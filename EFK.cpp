#include <cmath>
#include <iostream>
#include "Eigen/Dense"

typedef Eigen::Matrix<double, 9, 1> Vector9d; // 9维向量
typedef Eigen::Matrix<double, 9, 9> Matrix9d; // 9阶方阵
using Eigen::Vector4d; // 4维向量

// 零矩阵或零向量，用于置零
const Vector9d vec_zero = Vector9d::Zero();
const Matrix9d mtx_zero = Matrix9d::Zero();

class EFK {
    // EFK类型，用于完成卡尔曼滤波
    // 使用时，先测量以确定是否需要进行旋转导致的状态切换，然后依次进行先验、校正，见filter_unit
   private:
    // 格式统一：status为状态向量；Q为协方差矩阵
    // 前一最优状态 previous
    Vector9d status_previous;
    Matrix9d Q_previous;
    // 先验值 prior
    Vector9d status_prior;
    Matrix9d Q_prior;
    Matrix9d MTX_status_shift_prior;  // 状态方程中的变换矩阵，由前一最优状态得到先验值
    // 测量值 msr
    Vector4d status_msr;                  // 测量得到的状态量
    Eigen::Matrix<double, 4, 9> MTX_msr;  // 测量矩阵
    // 后验值/修正值 amend
    Vector9d status_amend;
    Matrix9d Q_amend;
    Eigen::Matrix<double, 9, 4> K_gain;    // 卡尔曼增益矩阵
    Eigen::Matrix4d ultra_args_of_K_gain;  // 卡尔曼增益矩阵中的R，超参数
    // 误差相关
    Matrix9d Q_noise;  // 协方差噪声
    Vector4d e_msr;    // 测量误差
    // 函数
    void update_MTX_msr(double theta);
    void measure(void);
    void prior(void);
    void amend(void);
    void rotate_status_toggle(void);

   public:
    EFK(double delta_t);
    void filter_unit(void);
    ~EFK();
};

EFK::EFK(double delta_t)
    // 初始化，所有矩阵先置零
    : status_previous(vec_zero),
      status_prior(vec_zero),
      status_amend(vec_zero),
      status_msr(vec_zero),
      Q_previous(mtx_zero),
      Q_prior(mtx_zero),
      Q_amend(mtx_zero),
      Q_noise(mtx_zero),
      MTX_status_shift_prior(mtx_zero),
      MTX_msr(Eigen::Matrix<double, 4, 9>::Zero()),
      K_gain(Eigen::Matrix<double, 9, 4>::Zero()),
      ultra_args_of_K_gain(Eigen::Matrix4d::Zero()),
      e_msr(Vector4d::Zero()) {
    
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
    // 噪声矩阵，随便写
    Q_noise.diagonal() << 1, 1, 1, 1, 1, 1, 1, 1, 1;
    e_msr = Vector4d::Constant(0.05);
    // 超参数，随便写
    ultra_args_of_K_gain.diagonal() << 1, 1, 1, 1;
}
inline void EFK::update_MTX_msr(double theta) {
    // 参数：theta，上一状态时的最优角度
    // 测量矩阵更新，只因测量矩阵里带有theta，会随状态而变化
    MTX_msr(0, 8) = cos(theta);
    MTX_msr(1, 8) = sin(theta);
    return;
}
void EFK::measure(void) {
    // 测量，并判断是否发生旋转突变
    update_MTX_msr(status_previous[6]);
    status_msr = MTX_msr * status_previous;
    // 判断的对象是z与r，设置的切换标准是10%
    if (abs(status_msr[2] - status_previous[4]) >= 0.1 * status_previous[4] || abs(status_msr[3] - status_previous[6]) >= 0.1 * status_previous[6]) {
        rotate_status_toggle();
    }
    return;
}
void EFK::prior(void) {
    // 先验值计算
    status_prior = MTX_status_shift_prior * status_previous;
    Q_prior = MTX_status_shift_prior * Q_previous * MTX_status_shift_prior.transpose() + Q_noise;
    return;
}
void EFK::amend(void) {
    // 修正值计算
    K_gain = Q_prior * MTX_msr.transpose() * (MTX_msr * Q_prior * MTX_msr.transpose() + ultra_args_of_K_gain).inverse();

    status_amend = status_prior + K_gain * (status_msr - MTX_msr * status_prior);
    Q_amend = (Matrix9d::Identity() - K_gain * MTX_msr) * Q_prior;
    return;
}
void EFK::rotate_status_toggle(void) {
    // 旋转导致状态突变，切换状态
    status_previous[4] = status_msr[2];  // z坐标
    status_previous[8] = status_msr[3];  // r
    status_previous[6] = 0;              // theta归零，监测一个新装甲板
    update_MTX_msr(status_previous[6]);
    return;
}
void EFK::filter_unit(void) {
    // 滤波的最小操作单元，由以下三个操作组成
    measure();
    prior();
    amend();
}
EFK::~EFK() {}
