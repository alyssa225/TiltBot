// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from turtle_brick_interfaces:msg/Tilt.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "turtle_brick_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "turtle_brick_interfaces/msg/detail/tilt__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace turtle_brick_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
cdr_serialize(
  const turtle_brick_interfaces::msg::Tilt & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  turtle_brick_interfaces::msg::Tilt & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
get_serialized_size(
  const turtle_brick_interfaces::msg::Tilt & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
max_serialized_size_Tilt(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace turtle_brick_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtle_brick_interfaces, msg, Tilt)();

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
