// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtle_brick_interfaces:msg/Tilt.idl
// generated code does not contain a copyright notice
#include "turtle_brick_interfaces/msg/detail/tilt__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
turtle_brick_interfaces__msg__Tilt__init(turtle_brick_interfaces__msg__Tilt * msg)
{
  if (!msg) {
    return false;
  }
  // alpha
  return true;
}

void
turtle_brick_interfaces__msg__Tilt__fini(turtle_brick_interfaces__msg__Tilt * msg)
{
  if (!msg) {
    return;
  }
  // alpha
}

bool
turtle_brick_interfaces__msg__Tilt__are_equal(const turtle_brick_interfaces__msg__Tilt * lhs, const turtle_brick_interfaces__msg__Tilt * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // alpha
  if (lhs->alpha != rhs->alpha) {
    return false;
  }
  return true;
}

bool
turtle_brick_interfaces__msg__Tilt__copy(
  const turtle_brick_interfaces__msg__Tilt * input,
  turtle_brick_interfaces__msg__Tilt * output)
{
  if (!input || !output) {
    return false;
  }
  // alpha
  output->alpha = input->alpha;
  return true;
}

turtle_brick_interfaces__msg__Tilt *
turtle_brick_interfaces__msg__Tilt__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__msg__Tilt * msg = (turtle_brick_interfaces__msg__Tilt *)allocator.allocate(sizeof(turtle_brick_interfaces__msg__Tilt), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_brick_interfaces__msg__Tilt));
  bool success = turtle_brick_interfaces__msg__Tilt__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_brick_interfaces__msg__Tilt__destroy(turtle_brick_interfaces__msg__Tilt * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_brick_interfaces__msg__Tilt__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_brick_interfaces__msg__Tilt__Sequence__init(turtle_brick_interfaces__msg__Tilt__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__msg__Tilt * data = NULL;

  if (size) {
    data = (turtle_brick_interfaces__msg__Tilt *)allocator.zero_allocate(size, sizeof(turtle_brick_interfaces__msg__Tilt), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_brick_interfaces__msg__Tilt__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_brick_interfaces__msg__Tilt__fini(&data[i - 1]);
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
turtle_brick_interfaces__msg__Tilt__Sequence__fini(turtle_brick_interfaces__msg__Tilt__Sequence * array)
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
      turtle_brick_interfaces__msg__Tilt__fini(&array->data[i]);
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

turtle_brick_interfaces__msg__Tilt__Sequence *
turtle_brick_interfaces__msg__Tilt__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__msg__Tilt__Sequence * array = (turtle_brick_interfaces__msg__Tilt__Sequence *)allocator.allocate(sizeof(turtle_brick_interfaces__msg__Tilt__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_brick_interfaces__msg__Tilt__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_brick_interfaces__msg__Tilt__Sequence__destroy(turtle_brick_interfaces__msg__Tilt__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_brick_interfaces__msg__Tilt__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_brick_interfaces__msg__Tilt__Sequence__are_equal(const turtle_brick_interfaces__msg__Tilt__Sequence * lhs, const turtle_brick_interfaces__msg__Tilt__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_brick_interfaces__msg__Tilt__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_brick_interfaces__msg__Tilt__Sequence__copy(
  const turtle_brick_interfaces__msg__Tilt__Sequence * input,
  turtle_brick_interfaces__msg__Tilt__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_brick_interfaces__msg__Tilt);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_brick_interfaces__msg__Tilt * data =
      (turtle_brick_interfaces__msg__Tilt *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_brick_interfaces__msg__Tilt__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_brick_interfaces__msg__Tilt__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_brick_interfaces__msg__Tilt__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
