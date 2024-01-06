// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from task_interfaces:msg/InputMsg.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__TRAITS_HPP_
#define TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "task_interfaces/msg/detail/input_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace task_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const InputMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const InputMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const InputMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace task_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use task_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const task_interfaces::msg::InputMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  task_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use task_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const task_interfaces::msg::InputMsg & msg)
{
  return task_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<task_interfaces::msg::InputMsg>()
{
  return "task_interfaces::msg::InputMsg";
}

template<>
inline const char * name<task_interfaces::msg::InputMsg>()
{
  return "task_interfaces/msg/InputMsg";
}

template<>
struct has_fixed_size<task_interfaces::msg::InputMsg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<task_interfaces::msg::InputMsg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<task_interfaces::msg::InputMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__TRAITS_HPP_
