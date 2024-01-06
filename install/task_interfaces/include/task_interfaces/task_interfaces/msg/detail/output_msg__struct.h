// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from task_interfaces:msg/OutputMsg.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__STRUCT_H_
#define TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/OutputMsg in the package task_interfaces.
typedef struct task_interfaces__msg__OutputMsg
{
  double x;
  double vx;
  double y;
  double vy;
  double z;
  double vz;
  /// 角度
  double theta;
  /// 角速度
  double vtheta;
  /// 半径偏置量
  double r_offset;
  /// 高度偏置量
  double z_offset;
  /// 时间戳
  double timestamp;
} task_interfaces__msg__OutputMsg;

// Struct for a sequence of task_interfaces__msg__OutputMsg.
typedef struct task_interfaces__msg__OutputMsg__Sequence
{
  task_interfaces__msg__OutputMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} task_interfaces__msg__OutputMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__STRUCT_H_
