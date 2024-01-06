// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from task_interfaces:msg/InputMsg.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__STRUCT_H_
#define TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/InputMsg in the package task_interfaces.
typedef struct task_interfaces__msg__InputMsg
{
  double x;
  double y;
  double z;
  double yaw;
  /// 时间戳
  double timestamp;
} task_interfaces__msg__InputMsg;

// Struct for a sequence of task_interfaces__msg__InputMsg.
typedef struct task_interfaces__msg__InputMsg__Sequence
{
  task_interfaces__msg__InputMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} task_interfaces__msg__InputMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__STRUCT_H_
