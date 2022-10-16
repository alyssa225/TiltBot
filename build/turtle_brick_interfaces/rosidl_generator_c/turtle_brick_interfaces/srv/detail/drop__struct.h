// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_brick_interfaces:srv/Drop.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__STRUCT_H_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Drop in the package turtle_brick_interfaces.
typedef struct turtle_brick_interfaces__srv__Drop_Request
{
  float g;
} turtle_brick_interfaces__srv__Drop_Request;

// Struct for a sequence of turtle_brick_interfaces__srv__Drop_Request.
typedef struct turtle_brick_interfaces__srv__Drop_Request__Sequence
{
  turtle_brick_interfaces__srv__Drop_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_brick_interfaces__srv__Drop_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Drop in the package turtle_brick_interfaces.
typedef struct turtle_brick_interfaces__srv__Drop_Response
{
  double g;
} turtle_brick_interfaces__srv__Drop_Response;

// Struct for a sequence of turtle_brick_interfaces__srv__Drop_Response.
typedef struct turtle_brick_interfaces__srv__Drop_Response__Sequence
{
  turtle_brick_interfaces__srv__Drop_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_brick_interfaces__srv__Drop_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__STRUCT_H_
