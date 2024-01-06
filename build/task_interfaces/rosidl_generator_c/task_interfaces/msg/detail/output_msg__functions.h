// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from task_interfaces:msg/OutputMsg.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__FUNCTIONS_H_
#define TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "task_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "task_interfaces/msg/detail/output_msg__struct.h"

/// Initialize msg/OutputMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * task_interfaces__msg__OutputMsg
 * )) before or use
 * task_interfaces__msg__OutputMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__OutputMsg__init(task_interfaces__msg__OutputMsg * msg);

/// Finalize msg/OutputMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
void
task_interfaces__msg__OutputMsg__fini(task_interfaces__msg__OutputMsg * msg);

/// Create msg/OutputMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * task_interfaces__msg__OutputMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
task_interfaces__msg__OutputMsg *
task_interfaces__msg__OutputMsg__create();

/// Destroy msg/OutputMsg message.
/**
 * It calls
 * task_interfaces__msg__OutputMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
void
task_interfaces__msg__OutputMsg__destroy(task_interfaces__msg__OutputMsg * msg);

/// Check for msg/OutputMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__OutputMsg__are_equal(const task_interfaces__msg__OutputMsg * lhs, const task_interfaces__msg__OutputMsg * rhs);

/// Copy a msg/OutputMsg message.
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
task_interfaces__msg__OutputMsg__copy(
  const task_interfaces__msg__OutputMsg * input,
  task_interfaces__msg__OutputMsg * output);

/// Initialize array of msg/OutputMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * task_interfaces__msg__OutputMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__OutputMsg__Sequence__init(task_interfaces__msg__OutputMsg__Sequence * array, size_t size);

/// Finalize array of msg/OutputMsg messages.
/**
 * It calls
 * task_interfaces__msg__OutputMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
void
task_interfaces__msg__OutputMsg__Sequence__fini(task_interfaces__msg__OutputMsg__Sequence * array);

/// Create array of msg/OutputMsg messages.
/**
 * It allocates the memory for the array and calls
 * task_interfaces__msg__OutputMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
task_interfaces__msg__OutputMsg__Sequence *
task_interfaces__msg__OutputMsg__Sequence__create(size_t size);

/// Destroy array of msg/OutputMsg messages.
/**
 * It calls
 * task_interfaces__msg__OutputMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
void
task_interfaces__msg__OutputMsg__Sequence__destroy(task_interfaces__msg__OutputMsg__Sequence * array);

/// Check for msg/OutputMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_task_interfaces
bool
task_interfaces__msg__OutputMsg__Sequence__are_equal(const task_interfaces__msg__OutputMsg__Sequence * lhs, const task_interfaces__msg__OutputMsg__Sequence * rhs);

/// Copy an array of msg/OutputMsg messages.
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
task_interfaces__msg__OutputMsg__Sequence__copy(
  const task_interfaces__msg__OutputMsg__Sequence * input,
  task_interfaces__msg__OutputMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TASK_INTERFACES__MSG__DETAIL__OUTPUT_MSG__FUNCTIONS_H_
