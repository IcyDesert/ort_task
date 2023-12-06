#include "Eigen/Dense"
#include <iostream>
#include <cmath>

typedef Eigen::Matrix<double, 9, 1> Vector9d;
typedef Eigen::Matrix<double, 9, 9> Matrix9d;
using Eigen::Vector4d;

// TODO inline位置写哪里好呢？？？
// 用列表初始化,all the matrix must be inintialized to zero matrix
class EFK {
   private:
    // 格式统一：status为状态向量；Q为协方差矩阵
    // 前一最优状�? previous
    Vector9d status_previous;
    Matrix9d Q_previous;
    // 先验�? prior
    Vector9d status_prior;
    Matrix9d Q_prior;
    double delta_t;             // 采样间隔
    Matrix9d MTX_status_shift_prior;  // 状态方程中的变换矩阵，由前一最优状态得到先验�?
    // 测量�? msr
    Vector4d status_msr;                  // 测量得到的状态�?, 有优化空间，可以不要
    Eigen::Matrix<double, 4, 9> MTX_msr;  // 测量矩阵
    // 后验�?/修正�? amend
    Vector9d status_amend;
    Matrix9d Q_amend;
    Eigen::Matrix<double, 9, 4> K_gain;    // 卡尔曼增益矩�?
    Eigen::Matrix4d ultra_args_of_K_gain;  // 卡尔曼增益矩阵中的R，超参数
    // 误差相关
    Matrix9d Q_noise;  // 协方差噪�?
    Vector4d e_msr;    // 测量误差
    // 函数
    void update_MTX_msr(double theta);
    void measure(void);
    void prior(void);
    void amend(void);
    void rotate_toggle(void);

   public:
    EFK(double _delta_t);
    
    ~EFK();
};

EFK::EFK(double _delta_t) : delta_t(_delta_t) {
    status_previous = Vector9d::Zero();
    Q_previous.diagonal() << 1, 1, 1, 1, 1, 1, 1, 1, 1;

    MTX_status_shift_prior.diagonal() << 1, 1, 1, 1, 1, 1, 1, 1, 1;
    for (int i = 0;i <= 6; i+= 2) {
        MTX_status_shift_prior(i, i+1) = delta_t;
    }

    MTX_msr.diagonal() << 1, 1, 1, 1;
    update_MTX_msr(status_previous[6]);

    Q_noise.diagonal() << 1, 1, 1, 1, 1, 1, 1, 1, 1;
    e_msr = Vector4d::Constant(0.05);
}


inline void EFK::update_MTX_msr(double theta) {
    MTX_msr(0, 8) = cos(theta);
    MTX_msr(1, 8) = sin(theta);
    return;
}

void EFK::measure(void) {
    status_msr = MTX_msr * status_previous;
    if (status_msr[2] >= 1.1 * status_previous[4] || 
        status_msr[2] >= 1.1 * status_previous[6]) {
            rotate_toggle();
            }
    return;
}

void EFK::prior(void) {
    status_prior = MTX_status_shift_prior * status_previous;
    Q_prior = MTX_status_shift_prior * Q_previous * MTX_status_shift_prior.transpose() + Q_noise;
    return;
}

void EFK::amend(void) {
    K_gain = Q_prior * MTX_msr.transpose() * (MTX_msr * Q_prior * MTX_msr.transpose() + ultra_args_of_K_gain).inverse();
    status_amend = status_prior + K_gain * (status_msr - MTX_msr * status_prior);
    Q_amend = (Matrix9d::Identity() - K_gain * MTX_msr) * Q_prior;
    return;
}

void EFK::rotate_toggle(void) {

}
EFK::~EFK() {
}
