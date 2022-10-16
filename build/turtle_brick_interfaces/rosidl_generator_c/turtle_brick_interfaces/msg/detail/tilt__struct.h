// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_brick_interfaces:msg/Tilt.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__STRUCT_H_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Tilt in the package turtle_brick_interfaces.
typedef struct turtle_brick_interfaces__msg__Tilt
{
  float alpha;
} turtle_brick_interfaces__msg__Tilt;

// Struct for a sequence of turtle_brick_interfaces__msg__Tilt.
typedef struct turtle_brick_interfaces__msg__Tilt__Sequence
{
  turtle_brick_interfaces__msg__Tilt * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_brick_interfaces__msg__Tilt__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__STRUCT_H_
