// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from turtle_brick_interfaces:srv/Drop.idl
// generated code does not contain a copyright notice
#include "turtle_brick_interfaces/srv/detail/drop__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "turtle_brick_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "turtle_brick_interfaces/srv/detail/drop__struct.h"
#include "turtle_brick_interfaces/srv/detail/drop__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Drop_Request__ros_msg_type = turtle_brick_interfaces__srv__Drop_Request;

static bool _Drop_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Drop_Request__ros_msg_type * ros_message = static_cast<const _Drop_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: g
  {
    cdr << ros_message->g;
  }

  return true;
}

static bool _Drop_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Drop_Request__ros_msg_type * ros_message = static_cast<_Drop_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: g
  {
    cdr >> ros_message->g;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
size_t get_serialized_size_turtle_brick_interfaces__srv__Drop_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Drop_Request__ros_msg_type * ros_message = static_cast<const _Drop_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name g
  {
    size_t item_size = sizeof(ros_message->g);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Drop_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_turtle_brick_interfaces__srv__Drop_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
size_t max_serialized_size_turtle_brick_interfaces__srv__Drop_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: g
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Drop_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_turtle_brick_interfaces__srv__Drop_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Drop_Request = {
  "turtle_brick_interfaces::srv",
  "Drop_Request",
  _Drop_Request__cdr_serialize,
  _Drop_Request__cdr_deserialize,
  _Drop_Request__get_serialized_size,
  _Drop_Request__max_serialized_size
};

static rosidl_message_type_support_t _Drop_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Drop_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, srv, Drop_Request)() {
  return &_Drop_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "turtle_brick_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/drop__struct.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/drop__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Drop_Response__ros_msg_type = turtle_brick_interfaces__srv__Drop_Response;

static bool _Drop_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Drop_Response__ros_msg_type * ros_message = static_cast<const _Drop_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: g
  {
    cdr << ros_message->g;
  }

  return true;
}

static bool _Drop_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Drop_Response__ros_msg_type * ros_message = static_cast<_Drop_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: g
  {
    cdr >> ros_message->g;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
size_t get_serialized_size_turtle_brick_interfaces__srv__Drop_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Drop_Response__ros_msg_type * ros_message = static_cast<const _Drop_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name g
  {
    size_t item_size = sizeof(ros_message->g);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Drop_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_turtle_brick_interfaces__srv__Drop_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
size_t max_serialized_size_turtle_brick_interfaces__srv__Drop_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: g
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Drop_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_turtle_brick_interfaces__srv__Drop_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Drop_Response = {
  "turtle_brick_interfaces::srv",
  "Drop_Response",
  _Drop_Response__cdr_serialize,
  _Drop_Response__cdr_deserialize,
  _Drop_Response__get_serialized_size,
  _Drop_Response__max_serialized_size
};

static rosidl_message_type_support_t _Drop_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Drop_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, srv, Drop_Response)() {
  return &_Drop_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "turtle_brick_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "turtle_brick_interfaces/srv/drop.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Drop__callbacks = {
  "turtle_brick_interfaces::srv",
  "Drop",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, srv, Drop_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, srv, Drop_Response)(),
};

static rosidl_service_type_support_t Drop__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Drop__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, srv, Drop)() {
  return &Drop__handle;
}

#if defined(__cplusplus)
}
#endif
