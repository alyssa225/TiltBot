// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtle_brick_interfaces:srv/Place.idl
// generated code does not contain a copyright notice
#include "turtle_brick_interfaces/srv/detail/place__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
turtle_brick_interfaces__srv__Place_Request__init(turtle_brick_interfaces__srv__Place_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
turtle_brick_interfaces__srv__Place_Request__fini(turtle_brick_interfaces__srv__Place_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
}

bool
turtle_brick_interfaces__srv__Place_Request__are_equal(const turtle_brick_interfaces__srv__Place_Request * lhs, const turtle_brick_interfaces__srv__Place_Request * rhs)
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
  return true;
}

bool
turtle_brick_interfaces__srv__Place_Request__copy(
  const turtle_brick_interfaces__srv__Place_Request * input,
  turtle_brick_interfaces__srv__Place_Request * output)
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
  return true;
}

turtle_brick_interfaces__srv__Place_Request *
turtle_brick_interfaces__srv__Place_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__srv__Place_Request * msg = (turtle_brick_interfaces__srv__Place_Request *)allocator.allocate(sizeof(turtle_brick_interfaces__srv__Place_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_brick_interfaces__srv__Place_Request));
  bool success = turtle_brick_interfaces__srv__Place_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_brick_interfaces__srv__Place_Request__destroy(turtle_brick_interfaces__srv__Place_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_brick_interfaces__srv__Place_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_brick_interfaces__srv__Place_Request__Sequence__init(turtle_brick_interfaces__srv__Place_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__srv__Place_Request * data = NULL;

  if (size) {
    data = (turtle_brick_interfaces__srv__Place_Request *)allocator.zero_allocate(size, sizeof(turtle_brick_interfaces__srv__Place_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_brick_interfaces__srv__Place_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_brick_interfaces__srv__Place_Request__fini(&data[i - 1]);
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
turtle_brick_interfaces__srv__Place_Request__Sequence__fini(turtle_brick_interfaces__srv__Place_Request__Sequence * array)
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
      turtle_brick_interfaces__srv__Place_Request__fini(&array->data[i]);
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

turtle_brick_interfaces__srv__Place_Request__Sequence *
turtle_brick_interfaces__srv__Place_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__srv__Place_Request__Sequence * array = (turtle_brick_interfaces__srv__Place_Request__Sequence *)allocator.allocate(sizeof(turtle_brick_interfaces__srv__Place_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_brick_interfaces__srv__Place_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_brick_interfaces__srv__Place_Request__Sequence__destroy(turtle_brick_interfaces__srv__Place_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_brick_interfaces__srv__Place_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_brick_interfaces__srv__Place_Request__Sequence__are_equal(const turtle_brick_interfaces__srv__Place_Request__Sequence * lhs, const turtle_brick_interfaces__srv__Place_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_brick_interfaces__srv__Place_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_brick_interfaces__srv__Place_Request__Sequence__copy(
  const turtle_brick_interfaces__srv__Place_Request__Sequence * input,
  turtle_brick_interfaces__srv__Place_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_brick_interfaces__srv__Place_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_brick_interfaces__srv__Place_Request * data =
      (turtle_brick_interfaces__srv__Place_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_brick_interfaces__srv__Place_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_brick_interfaces__srv__Place_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_brick_interfaces__srv__Place_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
turtle_brick_interfaces__srv__Place_Response__init(turtle_brick_interfaces__srv__Place_Response * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
turtle_brick_interfaces__srv__Place_Response__fini(turtle_brick_interfaces__srv__Place_Response * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
}

bool
turtle_brick_interfaces__srv__Place_Response__are_equal(const turtle_brick_interfaces__srv__Place_Response * lhs, const turtle_brick_interfaces__srv__Place_Response * rhs)
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
  return true;
}

bool
turtle_brick_interfaces__srv__Place_Response__copy(
  const turtle_brick_interfaces__srv__Place_Response * input,
  turtle_brick_interfaces__srv__Place_Response * output)
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
  return true;
}

turtle_brick_interfaces__srv__Place_Response *
turtle_brick_interfaces__srv__Place_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__srv__Place_Response * msg = (turtle_brick_interfaces__srv__Place_Response *)allocator.allocate(sizeof(turtle_brick_interfaces__srv__Place_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_brick_interfaces__srv__Place_Response));
  bool success = turtle_brick_interfaces__srv__Place_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_brick_interfaces__srv__Place_Response__destroy(turtle_brick_interfaces__srv__Place_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_brick_interfaces__srv__Place_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_brick_interfaces__srv__Place_Response__Sequence__init(turtle_brick_interfaces__srv__Place_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__srv__Place_Response * data = NULL;

  if (size) {
    data = (turtle_brick_interfaces__srv__Place_Response *)allocator.zero_allocate(size, sizeof(turtle_brick_interfaces__srv__Place_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_brick_interfaces__srv__Place_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_brick_interfaces__srv__Place_Response__fini(&data[i - 1]);
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
turtle_brick_interfaces__srv__Place_Response__Sequence__fini(turtle_brick_interfaces__srv__Place_Response__Sequence * array)
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
      turtle_brick_interfaces__srv__Place_Response__fini(&array->data[i]);
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

turtle_brick_interfaces__srv__Place_Response__Sequence *
turtle_brick_interfaces__srv__Place_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__srv__Place_Response__Sequence * array = (turtle_brick_interfaces__srv__Place_Response__Sequence *)allocator.allocate(sizeof(turtle_brick_interfaces__srv__Place_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_brick_interfaces__srv__Place_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_brick_interfaces__srv__Place_Response__Sequence__destroy(turtle_brick_interfaces__srv__Place_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_brick_interfaces__srv__Place_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_brick_interfaces__srv__Place_Response__Sequence__are_equal(const turtle_brick_interfaces__srv__Place_Response__Sequence * lhs, const turtle_brick_interfaces__srv__Place_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_brick_interfaces__srv__Place_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_brick_interfaces__srv__Place_Response__Sequence__copy(
  const turtle_brick_interfaces__srv__Place_Response__Sequence * input,
  turtle_brick_interfaces__srv__Place_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_brick_interfaces__srv__Place_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_brick_interfaces__srv__Place_Response * data =
      (turtle_brick_interfaces__srv__Place_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_brick_interfaces__srv__Place_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_brick_interfaces__srv__Place_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_brick_interfaces__srv__Place_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
