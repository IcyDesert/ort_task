// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from task_interfaces:msg/InputMsg.idl
// generated code does not contain a copyright notice
#include "task_interfaces/msg/detail/input_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
task_interfaces__msg__InputMsg__init(task_interfaces__msg__InputMsg * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // yaw
  // timestamp
  return true;
}

void
task_interfaces__msg__InputMsg__fini(task_interfaces__msg__InputMsg * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // yaw
  // timestamp
}

bool
task_interfaces__msg__InputMsg__are_equal(const task_interfaces__msg__InputMsg * lhs, const task_interfaces__msg__InputMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  return true;
}

bool
task_interfaces__msg__InputMsg__copy(
  const task_interfaces__msg__InputMsg * input,
  task_interfaces__msg__InputMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // yaw
  output->yaw = input->yaw;
  // timestamp
  output->timestamp = input->timestamp;
  return true;
}

task_interfaces__msg__InputMsg *
task_interfaces__msg__InputMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__msg__InputMsg * msg = (task_interfaces__msg__InputMsg *)allocator.allocate(sizeof(task_interfaces__msg__InputMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(task_interfaces__msg__InputMsg));
  bool success = task_interfaces__msg__InputMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
task_interfaces__msg__InputMsg__destroy(task_interfaces__msg__InputMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    task_interfaces__msg__InputMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
task_interfaces__msg__InputMsg__Sequence__init(task_interfaces__msg__InputMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__msg__InputMsg * data = NULL;

  if (size) {
    data = (task_interfaces__msg__InputMsg *)allocator.zero_allocate(size, sizeof(task_interfaces__msg__InputMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = task_interfaces__msg__InputMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        task_interfaces__msg__InputMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
task_interfaces__msg__InputMsg__Sequence__fini(task_interfaces__msg__InputMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      task_interfaces__msg__InputMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

task_interfaces__msg__InputMsg__Sequence *
task_interfaces__msg__InputMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__msg__InputMsg__Sequence * array = (task_interfaces__msg__InputMsg__Sequence *)allocator.allocate(sizeof(task_interfaces__msg__InputMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = task_interfaces__msg__InputMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
task_interfaces__msg__InputMsg__Sequence__destroy(task_interfaces__msg__InputMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    task_interfaces__msg__InputMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
task_interfaces__msg__InputMsg__Sequence__are_equal(const task_interfaces__msg__InputMsg__Sequence * lhs, const task_interfaces__msg__InputMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!task_interfaces__msg__InputMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
task_interfaces__msg__InputMsg__Sequence__copy(
  const task_interfaces__msg__InputMsg__Sequence * input,
  task_interfaces__msg__InputMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(task_interfaces__msg__InputMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    task_interfaces__msg__InputMsg * data =
      (task_interfaces__msg__InputMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!task_interfaces__msg__InputMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          task_interfaces__msg__InputMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!task_interfaces__msg__InputMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
