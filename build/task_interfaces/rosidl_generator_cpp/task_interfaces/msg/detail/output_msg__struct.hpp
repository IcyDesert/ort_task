// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from task_interfaces:msg/OutputMsg.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__STRUCT_HPP_
#define TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__task_interfaces__msg__OutputMsg __attribute__((deprecated))
#else
# define DEPRECATED__task_interfaces__msg__OutputMsg __declspec(deprecated)
#endif

namespace task_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OutputMsg_
{
  using Type = OutputMsg_<ContainerAllocator>;

  explicit OutputMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->vx = 0.0;
      this->y = 0.0;
      this->vy = 0.0;
      this->z = 0.0;
      this->vz = 0.0;
      this->theta = 0.0;
      this->vtheta = 0.0;
      this->r_offset = 0.0;
      this->z_offset = 0.0;
      this->timestamp = 0.0;
    }
  }

  explicit OutputMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->vx = 0.0;
      this->y = 0.0;
      this->vy = 0.0;
      this->z = 0.0;
      this->vz = 0.0;
      this->theta = 0.0;
      this->vtheta = 0.0;
      this->r_offset = 0.0;
      this->z_offset = 0.0;
      this->timestamp = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _vx_type =
    double;
  _vx_type vx;
  using _y_type =
    double;
  _y_type y;
  using _vy_type =
    double;
  _vy_type vy;
  using _z_type =
    double;
  _z_type z;
  using _vz_type =
    double;
  _vz_type vz;
  using _theta_type =
    double;
  _theta_type theta;
  using _vtheta_type =
    double;
  _vtheta_type vtheta;
  using _r_offset_type =
    double;
  _r_offset_type r_offset;
  using _z_offset_type =
    double;
  _z_offset_type z_offset;
  using _timestamp_type =
    double;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__vx(
    const double & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__vy(
    const double & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__vz(
    const double & _arg)
  {
    this->vz = _arg;
    return *this;
  }
  Type & set__theta(
    const double & _arg)
  {
    this->theta = _arg;
    return *this;
  }
  Type & set__vtheta(
    const double & _arg)
  {
    this->vtheta = _arg;
    return *this;
  }
  Type & set__r_offset(
    const double & _arg)
  {
    this->r_offset = _arg;
    return *this;
  }
  Type & set__z_offset(
    const double & _arg)
  {
    this->z_offset = _arg;
    return *this;
  }
  Type & set__timestamp(
    const double & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    task_interfaces::msg::OutputMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const task_interfaces::msg::OutputMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<task_interfaces::msg::OutputMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<task_interfaces::msg::OutputMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      task_interfaces::msg::OutputMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::msg::OutputMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      task_interfaces::msg::OutputMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::msg::OutputMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<task_interfaces::msg::OutputMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<task_interfaces::msg::OutputMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__task_interfaces__msg__OutputMsg
    std::shared_ptr<task_interfaces::msg::OutputMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__task_interfaces__msg__OutputMsg
    std::shared_ptr<task_interfaces::msg::OutputMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OutputMsg_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->vz != other.vz) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    if (this->vtheta != other.vtheta) {
      return false;
    }
    if (this->r_offset != other.r_offset) {
      return false;
    }
    if (this->z_offset != other.z_offset) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const OutputMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OutputMsg_

// alias to use template instance with default allocator
using OutputMsg =
  task_interfaces::msg::OutputMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace task_interfaces

#endif  // TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__STRUCT_HPP_
