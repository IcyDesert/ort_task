// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from task_interfaces:msg/OutputMsg.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__TRAITS_HPP_
#define TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "task_interfaces/msg/detail/output_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace task_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const OutputMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: vx
  {
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: vy
  {
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: vz
  {
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << ", ";
  }

  // member: vtheta
  {
    out << "vtheta: ";
    rosidl_generator_traits::value_to_yaml(msg.vtheta, out);
    out << ", ";
  }

  // member: r_offset
  {
    out << "r_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.r_offset, out);
    out << ", ";
  }

  // member: z_offset
  {
    out << "z_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.z_offset, out);
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
  const OutputMsg & msg,
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

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
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

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
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

  // member: vz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: vtheta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vtheta: ";
    rosidl_generator_traits::value_to_yaml(msg.vtheta, out);
    out << "\n";
  }

  // member: r_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.r_offset, out);
    out << "\n";
  }

  // member: z_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.z_offset, out);
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

inline std::string to_yaml(const OutputMsg & msg, bool use_flow_style = false)
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
  const task_interfaces::msg::OutputMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  task_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use task_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const task_interfaces::msg::OutputMsg & msg)
{
  return task_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<task_interfaces::msg::OutputMsg>()
{
  return "task_interfaces::msg::OutputMsg";
}

template<>
inline const char * name<task_interfaces::msg::OutputMsg>()
{
  return "task_interfaces/msg/OutputMsg";
}

template<>
struct has_fixed_size<task_interfaces::msg::OutputMsg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<task_interfaces::msg::OutputMsg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<task_interfaces::msg::OutputMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__TRAITS_HPP_
