#pragma once

#include "rclcpp/rclcpp.hpp"
#include "Eigen/Dense"
#include "task_interfaces/msg/input_msg.hpp"
#include "task_interfaces/msg/output_msg.hpp"


typedef Eigen::Matrix<double, 9, 1> Vector9d;  // 9维向量
typedef Eigen::Matrix<double, 9, 9> Matrix9d;  // 9阶方阵
using Eigen::Vector4d;                         // 4维向量
using std::string;                             // c++字符串

class EFK : public rclcpp::Node {
    // EFK类型，用于完成卡尔曼滤波且进行消息发布
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
    double r_offset;                       // 半径偏置量
    double z_offset;                       // 高度偏置量
    // 订阅者指针
    rclcpp::Subscription<task_interfaces::msg::InputMsg>::SharedPtr filter_subscriber_;
    // 发布者指针
    rclcpp::Publisher<task_interfaces::msg::OutputMsg>::SharedPtr filter_publisher_;
    // 计时器
    rclcpp::TimerBase::SharedPtr timer_;
    void subscriber_callback(const auto msg);
    void timer_callback();
    void update_MTX_msr(double theta);
    void measure();
    void prior();
    void amend();
    void rotate_status_toggle();
    double get_timestamp();
   public:
    EFK(double delta_t);
    void filter_unit();
    ~EFK();
};