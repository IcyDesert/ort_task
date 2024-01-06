// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from task_interfaces:msg/OutputMsg.idl
// generated code does not contain a copyright notice
#include "task_interfaces/msg/detail/output_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
task_interfaces__msg__OutputMsg__init(task_interfaces__msg__OutputMsg * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // vx
  // y
  // vy
  // z
  // vz
  // theta
  // vtheta
  // r_offset
  // z_offset
  // timestamp
  return true;
}

void
task_interfaces__msg__OutputMsg__fini(task_interfaces__msg__OutputMsg * msg)
{
  if (!msg) {
    return;
  }
  // x
  // vx
  // y
  // vy
  // z
  // vz
  // theta
  // vtheta
  // r_offset
  // z_offset
  // timestamp
}

bool
task_interfaces__msg__OutputMsg__are_equal(const task_interfaces__msg__OutputMsg * lhs, const task_interfaces__msg__OutputMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // vz
  if (lhs->vz != rhs->vz) {
    return false;
  }
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  // vtheta
  if (lhs->vtheta != rhs->vtheta) {
    return false;
  }
  // r_offset
  if (lhs->r_offset != rhs->r_offset) {
    return false;
  }
  // z_offset
  if (lhs->z_offset != rhs->z_offset) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  return true;
}

bool
task_interfaces__msg__OutputMsg__copy(
  const task_interfaces__msg__OutputMsg * input,
  task_interfaces__msg__OutputMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // vx
  output->vx = input->vx;
  // y
  output->y = input->y;
  // vy
  output->vy = input->vy;
  // z
  output->z = input->z;
  // vz
  output->vz = input->vz;
  // theta
  output->theta = input->theta;
  // vtheta
  output->vtheta = input->vtheta;
  // r_offset
  output->r_offset = input->r_offset;
  // z_offset
  output->z_offset = input->z_offset;
  // timestamp
  output->timestamp = input->timestamp;
  return true;
}

task_interfaces__msg__OutputMsg *
task_interfaces__msg__OutputMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__msg__OutputMsg * msg = (task_interfaces__msg__OutputMsg *)allocator.allocate(sizeof(task_interfaces__msg__OutputMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(task_interfaces__msg__OutputMsg));
  bool success = task_interfaces__msg__OutputMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
task_interfaces__msg__OutputMsg__destroy(task_interfaces__msg__OutputMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    task_interfaces__msg__OutputMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
task_interfaces__msg__OutputMsg__Sequence__init(task_interfaces__msg__OutputMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__msg__OutputMsg * data = NULL;

  if (size) {
    data = (task_interfaces__msg__OutputMsg *)allocator.zero_allocate(size, sizeof(task_interfaces__msg__OutputMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = task_interfaces__msg__OutputMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        task_interfaces__msg__OutputMsg__fini(&data[i - 1]);
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
task_interfaces__msg__OutputMsg__Sequence__fini(task_interfaces__msg__OutputMsg__Sequence * array)
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
      task_interfaces__msg__OutputMsg__fini(&array->data[i]);
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

task_interfaces__msg__OutputMsg__Sequence *
task_interfaces__msg__OutputMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__msg__OutputMsg__Sequence * array = (task_interfaces__msg__OutputMsg__Sequence *)allocator.allocate(sizeof(task_interfaces__msg__OutputMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = task_interfaces__msg__OutputMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
task_interfaces__msg__OutputMsg__Sequence__destroy(task_interfaces__msg__OutputMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    task_interfaces__msg__OutputMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
task_interfaces__msg__OutputMsg__Sequence__are_equal(const task_interfaces__msg__OutputMsg__Sequence * lhs, const task_interfaces__msg__OutputMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!task_interfaces__msg__OutputMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
task_interfaces__msg__OutputMsg__Sequence__copy(
  const task_interfaces__msg__OutputMsg__Sequence * input,
  task_interfaces__msg__OutputMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(task_interfaces__msg__OutputMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    task_interfaces__msg__OutputMsg * data =
      (task_interfaces__msg__OutputMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!task_interfaces__msg__OutputMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          task_interfaces__msg__OutputMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!task_interfaces__msg__OutputMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
