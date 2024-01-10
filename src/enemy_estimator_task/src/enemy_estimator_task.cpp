#include "../include/enemy_estimator_task/enemy_estimator_task.hpp"
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "Eigen/Dense"
#include "../../../install/task_interfaces/include/task_interfaces/task_interfaces/msg/input_msg.hpp"
#include "../../../install/task_interfaces/include/task_interfaces/task_interfaces/msg/output_msg.hpp"
#include "ultra_parameters.hpp"

// 零矩阵或零向量，用于置零
const Vector9d vec9d_zero = Vector9d::Zero();
const Matrix9d mtx9d_zero = Matrix9d::Zero();
const Vector4d vec4d_zero = Vector4d::Zero();

/**
 * @brief EFK类的初始化
 * @param delta_t 测量时间间隔
 */
EFK::EFK(double delta_t)
    // 噪声与R超参数从“参数hpp文件”里读取，其他矩阵置零
    : status_previous(vec9d_zero),
      status_prior(vec9d_zero),
      status_amend(vec9d_zero),
      status_msr(vec4d_zero),
      Q_previous(mtx9d_zero),
      Q_prior(mtx9d_zero),
      Q_amend(mtx9d_zero),
      MTX_status_shift_prior(mtx9d_zero),
      MTX_msr(Eigen::Matrix<double, 4, 9>::Zero()),
      K_gain(Eigen::Matrix<double, 9, 4>::Zero()),
      Q_noise(ultra_param::Q_noise),
      ultra_args_of_K_gain(ultra_param::R_),
      e_msr(ultra_param::e_msr),
      Node("EFK filter node") {
    //---------------以下为节点通信相关处理--------------
    // 所在的话题名称为filter
    filter_subscriber_ = this->create_subscription<task_interfaces::msg::InputMsg>(
            "filter", 10, std::bind(&EFK::subscriber_callback, this, std::placeholders::_1
        )); // 订阅者
    filter_publisher_ = this->create_publisher<task_interfaces::msg::OutputMsg>("filter", 10); // 发布者
    timer_ = this->create_wall_timer(std::chrono::milliseconds(100), 
                                     std::bind(&EFK::timer_callback, this)); // 计时器
    //--------------以下为矩阵初始化-------------
    // 状态变换矩阵
    MTX_status_shift_prior.diagonal() << 1, 1, 1, 1, 1, 1, 1, 1, 1;
    for (int i = 0; i <= 6; i += 2) {
        MTX_status_shift_prior(i, i + 1) = delta_t;
    }
    // 测量矩阵
    MTX_msr.diagonal() << 1, 1, 1, 1;
    update_MTX_msr(status_previous[6]);
    // 白噪声方差、测量误差矩阵，随便写
    Q_previous.diagonal() << 1, 1, 1, 1, 1, 1, 1, 1, 1;

    RCLCPP_INFO(this->get_logger(), "观测、滤波程序就位，准备接受观测数据.");
}
/**
 * @brief 定时器回调函数，间隔100ms发布一次数据
*/
void EFK::timer_callback() {
    task_interfaces::msg::OutputMsg message;
    message.x = status_prior[0];
    message.vx = status_prior[1];
    message.y = status_prior[2];
    message.vy = status_prior[3];
    message.z = status_prior[4];
    message.vz = status_prior[5];
    message.theta = status_prior[6];
    message.vtheta = status_prior[7];
    message.r_offset = this->r_offset;
    message.z_offset = this->z_offset;
    message.timestamp = this->get_timestamp();
    filter_publisher_->publish(message);
    RCLCPP_INFO(this->get_logger(), "已发布修正状态.");
    return;
}
/**
 * @brief 订阅者收到信息的回调函数，执行卡尔曼滤波过程
 * @param msg 实际上是InputMsg类型指针，包含测量数据
*/
void EFK::subscriber_callback(const task_interfaces::msg::InputMsg::SharedPtr &msg) {
    status_msr << msg->x, msg->y, msg->z, msg->yaw;
    this->filter_unit();
    RCLCPP_INFO(this->get_logger(), "收到观测数据，已完成滤波计算.");
    return;
}
/**
 * @brief 测量矩阵更新，只因测量矩阵里带有theta，会随状态而变化
 * @param theta 上一状态时的最优角度
 */
inline void EFK::update_MTX_msr(const double &theta) {
    MTX_msr(0, 8) = cos(theta);
    MTX_msr(1, 8) = sin(theta);
    return;
}
/**
 * @brief 测量，并以z和r的5%为允许误差范围，判断是否发生旋转突变；如果是旋转引起突变还需要切换状态，重新开始测量
 */
void EFK::measure() {
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
void EFK::prior() {
    status_prior = MTX_status_shift_prior * status_previous;
    Q_prior = MTX_status_shift_prior * Q_previous * MTX_status_shift_prior.transpose() + Q_noise;
    return;
}
/**
 * @brief 卡尔曼滤波——修正值计算
 */
void EFK::amend() {
    K_gain = Q_prior * MTX_msr.transpose()
             * (MTX_msr * Q_prior * MTX_msr.transpose() + ultra_args_of_K_gain).inverse();
    status_amend = status_prior + K_gain * (status_msr - MTX_msr * status_prior);
    Q_amend = (Matrix9d::Identity() - K_gain * MTX_msr) * Q_prior;
    return;
}
/**
 * @brief 重置状态，只因旋转引起；这里直接使用测量值作为新一次的状态值
 */
void EFK::rotate_status_toggle() {
    r_offset = status_msr[2] - status_previous[4]; // 半径偏置量
    z_offset = status_msr[3] - status_previous[6]; // 高度偏置量
    status_previous[4] = status_msr[2];  // z坐标
    status_previous[8] = status_msr[3];  // r
    status_previous[6] = 0;              // theta归零，监测一个新装甲板
    update_MTX_msr(status_previous[6]);  // 当theta变化时，相应地测量矩阵也随之变化
    return;
}
/**
 * @brief 滤波的最小操作单元，由测量、先验、修正组成；测量放最前，是确保旋转时能够切换状态，不会引起较大误差
 */
void EFK::filter_unit() {
    measure();
    prior();
    amend();
    return;
}
/**
 * @brief 利用chrono功能计算时间戳
*/
double EFK::get_timestamp() {
    return std::chrono::duration_cast<std::chrono::duration<double>>(
        std::chrono::steady_clock::now().time_since_epoch()
    ).count();
}
EFK::~EFK() {}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<EFK>(0.1);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
