#include <Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, 9, 1> Vector9d;
typedef Eigen::Matrix<double, 9, 9> Matrix9d;
using Eigen::Vector4d;

// TODO 把MTX_status_shift_prior 变成const，开始时即定义
class EFK {
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
    Vector4d status_msr;                  // 测量得到的状态值
    Eigen::Matrix<double, 4, 9> MTX_msr;  // 测量矩阵
    // 后验值/修正值 amend
    Vector9d status_amend;
    Matrix9d Q_amend;
    Eigen::Matrix<double, 9, 4> K_gain;    // 卡尔曼增益矩阵
    Eigen::Matrix4d ultra_args_of_K_gain;  // 卡尔曼增益矩阵中的R，超参数
    // 误差相关
    Matrix9d Q_noise;  // 协方差噪声
    Vector4d e_msr;    // 测量误差
   public:
    EFK();
    ~EFK();
};

EFK::EFK() {
}

EFK::~EFK() {
}
