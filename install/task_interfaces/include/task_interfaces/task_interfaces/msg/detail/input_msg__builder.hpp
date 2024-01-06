// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from task_interfaces:msg/InputMsg.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__BUILDER_HPP_
#define TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "task_interfaces/msg/detail/input_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace task_interfaces
{

namespace msg
{

namespace builder
{

class Init_InputMsg_timestamp
{
public:
  explicit Init_InputMsg_timestamp(::task_interfaces::msg::InputMsg & msg)
  : msg_(msg)
  {}
  ::task_interfaces::msg::InputMsg timestamp(::task_interfaces::msg::InputMsg::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::task_interfaces::msg::InputMsg msg_;
};

class Init_InputMsg_yaw
{
public:
  explicit Init_InputMsg_yaw(::task_interfaces::msg::InputMsg & msg)
  : msg_(msg)
  {}
  Init_InputMsg_timestamp yaw(::task_interfaces::msg::InputMsg::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_InputMsg_timestamp(msg_);
  }

private:
  ::task_interfaces::msg::InputMsg msg_;
};

class Init_InputMsg_z
{
public:
  explicit Init_InputMsg_z(::task_interfaces::msg::InputMsg & msg)
  : msg_(msg)
  {}
  Init_InputMsg_yaw z(::task_interfaces::msg::InputMsg::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_InputMsg_yaw(msg_);
  }

private:
  ::task_interfaces::msg::InputMsg msg_;
};

class Init_InputMsg_y
{
public:
  explicit Init_InputMsg_y(::task_interfaces::msg::InputMsg & msg)
  : msg_(msg)
  {}
  Init_InputMsg_z y(::task_interfaces::msg::InputMsg::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_InputMsg_z(msg_);
  }

private:
  ::task_interfaces::msg::InputMsg msg_;
};

class Init_InputMsg_x
{
public:
  Init_InputMsg_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InputMsg_y x(::task_interfaces::msg::InputMsg::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_InputMsg_y(msg_);
  }

private:
  ::task_interfaces::msg::InputMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::task_interfaces::msg::InputMsg>()
{
  return task_interfaces::msg::builder::Init_InputMsg_x();
}

}  // namespace task_interfaces

#endif  // TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__BUILDER_HPP_
