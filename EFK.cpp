#include <cmath>
#include <iostream>
#include "Eigen/Dense"

typedef Eigen::Matrix<double, 9, 1> Vector9d;  // 9维向量
typedef Eigen::Matrix<double, 9, 9> Matrix9d;  // 9阶方阵
using Eigen::Vector4d;                         // 4维向量

// 零矩阵或零向量，用于置零
const Vector9d vec9d_zero = Vector9d::Zero();
const Matrix9d mtx9d_zero = Matrix9d::Zero();
const Vector4d vec4d_zero = Vector4d::Zero();

class EFK {
    // EFK类型，用于完成卡尔曼滤波
    // 使用时，先测量以确定是否需要进行旋转导致的状态切换，然后依次进行先验、校正，见filter_unit
   private:
    Vector9d status_previous;              // 前一最优状态
    Matrix9d Q_previous;                   // 前一最优协方差
    Vector9d status_prior;                 // 状态先验值
    Matrix9d Q_prior;                      // 协方差先验值
    Matrix9d MTX_status_shift_prior;       // 状态方程中的变换矩阵，由前一最优状态得到先验值
    Vector4d status_msr;                   // 测量得到的状态量
    Eigen::Matrix<double, 4, 9> MTX_msr;   // 测量矩阵
    Vector9d status_amend;                 // 状态修正值
    Matrix9d Q_amend;                      // 协方差修正值
    Eigen::Matrix<double, 9, 4> K_gain;    // 卡尔曼增益矩阵
    Eigen::Matrix4d ultra_args_of_K_gain;  // 卡尔曼增益矩阵中的R，超参数
    Matrix9d Q_noise;                      // 协方差噪声
    Vector4d e_msr;                        // 测量误差
    void update_MTX_msr(double theta);
    void measure(void);
    void prior(void);
    void amend(void);
    void rotate_status_toggle(void);

   public:
    EFK(double delta_t);
    void filter_unit(void);
    Vector9d broadcast(void);
    ~EFK();
};
/**
 * @brief EFK类的初始化
 * @param delta_t 测量时间间隔
 */
EFK::EFK(double delta_t)
    // 所有矩阵先置零
    : status_previous(vec9d_zero),
      status_prior(vec9d_zero),
      status_amend(vec9d_zero),
      status_msr(vec4d_zero),
      Q_previous(mtx9d_zero),
      Q_prior(mtx9d_zero),
      Q_amend(mtx9d_zero),
      Q_noise(mtx9d_zero),
      MTX_status_shift_prior(mtx9d_zero),
      MTX_msr(Eigen::Matrix<double, 4, 9>::Zero()),
      K_gain(Eigen::Matrix<double, 9, 4>::Zero()),
      ultra_args_of_K_gain(Eigen::Matrix4d::Zero()),
      e_msr(vec4d_zero) {
    // 协方差矩阵，随便写
    Q_previous.diagonal() << 1, 1, 1, 1, 1, 1, 1, 1, 1;
    // 状态变换矩阵
    MTX_status_shift_prior.diagonal() << 1, 1, 1, 1, 1, 1, 1, 1, 1;
    for (int i = 0; i <= 6; i += 2) {
        MTX_status_shift_prior(i, i + 1) = delta_t;
    }
    // 测量矩阵
    MTX_msr.diagonal() << 1, 1, 1, 1;
    update_MTX_msr(status_previous[6]);
    // 噪声、测量误差矩阵，随便写
    Q_noise.diagonal() << 1, 1, 1, 1, 1, 1, 1, 1, 1;
    e_msr = Vector4d::Constant(0.05);
    // 超参数，随便写
    ultra_args_of_K_gain.diagonal() << 1, 1, 1, 1;
}
/**
 * @brief 测量矩阵更新，只因测量矩阵里带有theta，会随状态而变化
 * @param theta 上一状态时的最优角度
 */
inline void EFK::update_MTX_msr(double theta) {
    MTX_msr(0, 8) = cos(theta);
    MTX_msr(1, 8) = sin(theta);
    return;
}
/**
 * @brief 测量，并以z和r的5%为允许误差范围，判断是否发生旋转突变；如果是旋转引起突变还需要切换状态，重新开始测量
 */
void EFK::measure(void) {
    update_MTX_msr(status_previous[6]);
    status_msr = MTX_msr * status_previous;
    // 判断的对象是z与r，设置的切换标准是5%
    if (abs(status_msr[2] - status_previous[4]) >= 0.05 * status_previous[4] ||
        abs(status_msr[3] - status_previous[6]) >= 0.05 * status_previous[6]) {
        rotate_status_toggle();
    }
    return;
}
/**
 * @brief 卡尔曼滤波——先验值计算
 */
void EFK::prior(void) {
    status_prior = MTX_status_shift_prior * status_previous;
    Q_prior = MTX_status_shift_prior * Q_previous * MTX_status_shift_prior.transpose() + Q_noise;
    return;
}
/**
 * @brief 卡尔曼滤波——修正值计算
 */
void EFK::amend(void) {
    K_gain = Q_prior * MTX_msr.transpose()
             * (MTX_msr * Q_prior * MTX_msr.transpose() + ultra_args_of_K_gain).inverse();
    status_amend = status_prior + K_gain * (status_msr - MTX_msr * status_prior);
    Q_amend = (Matrix9d::Identity() - K_gain * MTX_msr) * Q_prior;
    return;
}
/**
 * @brief 重置状态，只因旋转引起；这里直接使用测量值作为第一次的状态值
 */
void EFK::rotate_status_toggle(void) {
    status_previous[4] = status_msr[2];  // z坐标
    status_previous[8] = status_msr[3];  // r
    status_previous[6] = 0;              // theta归零，监测一个新装甲板
    update_MTX_msr(status_previous[6]);  // 当theta变化时，相应地测量矩阵也随之变化
    return;
}
/**
 * @brief 滤波的最小操作单元，由测量、先验、修正组成；测量放最前，是确保旋转时能够切换状态，不会引起较大误差
 */
void EFK::filter_unit(void) {
    measure();
    prior();
    amend();
}
/**
 * @brief 向外广播目标的修正状态
 */
Vector9d EFK::broadcast(void) { return status_amend; }
EFK::~EFK() {}

int main() { return 0; }