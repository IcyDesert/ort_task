// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from task_interfaces:msg/InputMsg.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__FUNCTIONS_H_
#define TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "task_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "task_interfaces/msg/detail/input_msg__struct.h"

/// Initialize msg/InputMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * task_interfaces__msg__InputMsg
 * )) before or use
 * task_interfaces__msg__InputMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__InputMsg__init(task_interfaces__msg__InputMsg * msg);

/// Finalize msg/InputMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
void
task_interfaces__msg__InputMsg__fini(task_interfaces__msg__InputMsg * msg);

/// Create msg/InputMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * task_interfaces__msg__InputMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
task_interfaces__msg__InputMsg *
task_interfaces__msg__InputMsg__create();

/// Destroy msg/InputMsg message.
/**
 * It calls
 * task_interfaces__msg__InputMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
void
task_interfaces__msg__InputMsg__destroy(task_interfaces__msg__InputMsg * msg);

/// Check for msg/InputMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__InputMsg__are_equal(const task_interfaces__msg__InputMsg * lhs, const task_interfaces__msg__InputMsg * rhs);

/// Copy a msg/InputMsg message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__InputMsg__copy(
  const task_interfaces__msg__InputMsg * input,
  task_interfaces__msg__InputMsg * output);

/// Initialize array of msg/InputMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * task_interfaces__msg__InputMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__InputMsg__Sequence__init(task_interfaces__msg__InputMsg__Sequence * array, size_t size);

/// Finalize array of msg/InputMsg messages.
/**
 * It calls
 * task_interfaces__msg__InputMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
void
task_interfaces__msg__InputMsg__Sequence__fini(task_interfaces__msg__InputMsg__Sequence * array);

/// Create array of msg/InputMsg messages.
/**
 * It allocates the memory for the array and calls
 * task_interfaces__msg__InputMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
task_interfaces__msg__InputMsg__Sequence *
task_interfaces__msg__InputMsg__Sequence__create(size_t size);

/// Destroy array of msg/InputMsg messages.
/**
 * It calls
 * task_interfaces__msg__InputMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
void
task_interfaces__msg__InputMsg__Sequence__destroy(task_interfaces__msg__InputMsg__Sequence * array);

/// Check for msg/InputMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__InputMsg__Sequence__are_equal(const task_interfaces__msg__InputMsg__Sequence * lhs, const task_interfaces__msg__InputMsg__Sequence * rhs);

/// Copy an array of msg/InputMsg messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__InputMsg__Sequence__copy(
  const task_interfaces__msg__InputMsg__Sequence * input,
  task_interfaces__msg__InputMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TASK_INTERFACES__MSG__DETAIL__INPUT_MSG__FUNCTIONS_H_
