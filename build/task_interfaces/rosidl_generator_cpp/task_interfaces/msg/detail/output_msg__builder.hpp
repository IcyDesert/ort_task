// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from task_interfaces:msg/OutputMsg.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__BUILDER_HPP_
#define TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "task_interfaces/msg/detail/output_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace task_interfaces
{

namespace msg
{

namespace builder
{

class Init_OutputMsg_timestamp
{
public:
  explicit Init_OutputMsg_timestamp(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  ::task_interfaces::msg::OutputMsg timestamp(::task_interfaces::msg::OutputMsg::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_z_offset
{
public:
  explicit Init_OutputMsg_z_offset(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  Init_OutputMsg_timestamp z_offset(::task_interfaces::msg::OutputMsg::_z_offset_type arg)
  {
    msg_.z_offset = std::move(arg);
    return Init_OutputMsg_timestamp(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_r_offset
{
public:
  explicit Init_OutputMsg_r_offset(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  Init_OutputMsg_z_offset r_offset(::task_interfaces::msg::OutputMsg::_r_offset_type arg)
  {
    msg_.r_offset = std::move(arg);
    return Init_OutputMsg_z_offset(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_vtheta
{
public:
  explicit Init_OutputMsg_vtheta(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  Init_OutputMsg_r_offset vtheta(::task_interfaces::msg::OutputMsg::_vtheta_type arg)
  {
    msg_.vtheta = std::move(arg);
    return Init_OutputMsg_r_offset(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_theta
{
public:
  explicit Init_OutputMsg_theta(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  Init_OutputMsg_vtheta theta(::task_interfaces::msg::OutputMsg::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_OutputMsg_vtheta(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_vz
{
public:
  explicit Init_OutputMsg_vz(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  Init_OutputMsg_theta vz(::task_interfaces::msg::OutputMsg::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_OutputMsg_theta(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_z
{
public:
  explicit Init_OutputMsg_z(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  Init_OutputMsg_vz z(::task_interfaces::msg::OutputMsg::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_OutputMsg_vz(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_vy
{
public:
  explicit Init_OutputMsg_vy(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  Init_OutputMsg_z vy(::task_interfaces::msg::OutputMsg::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_OutputMsg_z(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_y
{
public:
  explicit Init_OutputMsg_y(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  Init_OutputMsg_vy y(::task_interfaces::msg::OutputMsg::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_OutputMsg_vy(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_vx
{
public:
  explicit Init_OutputMsg_vx(::task_interfaces::msg::OutputMsg & msg)
  : msg_(msg)
  {}
  Init_OutputMsg_y vx(::task_interfaces::msg::OutputMsg::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_OutputMsg_y(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

class Init_OutputMsg_x
{
public:
  Init_OutputMsg_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OutputMsg_vx x(::task_interfaces::msg::OutputMsg::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_OutputMsg_vx(msg_);
  }

private:
  ::task_interfaces::msg::OutputMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::task_interfaces::msg::OutputMsg>()
{
  return task_interfaces::msg::builder::Init_OutputMsg_x();
}

}  // namespace task_interfaces

#endif  // TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__BUILDER_HPP_
