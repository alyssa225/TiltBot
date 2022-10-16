// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from turtle_brick_interfaces:srv/Drop.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "turtle_brick_interfaces/srv/detail/drop__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace turtle_brick_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Drop_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Drop_Request_type_support_ids_t;

static const _Drop_Request_type_support_ids_t _Drop_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Drop_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Drop_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Drop_Request_type_support_symbol_names_t _Drop_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtle_brick_interfaces, srv, Drop_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, turtle_brick_interfaces, srv, Drop_Request)),
  }
};

typedef struct _Drop_Request_type_support_data_t
{
  void * data[2];
} _Drop_Request_type_support_data_t;

static _Drop_Request_type_support_data_t _Drop_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Drop_Request_message_typesupport_map = {
  2,
  "turtle_brick_interfaces",
  &_Drop_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Drop_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Drop_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Drop_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Drop_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<turtle_brick_interfaces::srv::Drop_Request>()
{
  return &::turtle_brick_interfaces::srv::rosidl_typesupport_cpp::Drop_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, turtle_brick_interfaces, srv, Drop_Request)() {
  return get_message_type_support_handle<turtle_brick_interfaces::srv::Drop_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/drop__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace turtle_brick_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Drop_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Drop_Response_type_support_ids_t;

static const _Drop_Response_type_support_ids_t _Drop_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Drop_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Drop_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Drop_Response_type_support_symbol_names_t _Drop_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtle_brick_interfaces, srv, Drop_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, turtle_brick_interfaces, srv, Drop_Response)),
  }
};

typedef struct _Drop_Response_type_support_data_t
{
  void * data[2];
} _Drop_Response_type_support_data_t;

static _Drop_Response_type_support_data_t _Drop_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Drop_Response_message_typesupport_map = {
  2,
  "turtle_brick_interfaces",
  &_Drop_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Drop_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Drop_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Drop_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Drop_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<turtle_brick_interfaces::srv::Drop_Response>()
{
  return &::turtle_brick_interfaces::srv::rosidl_typesupport_cpp::Drop_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, turtle_brick_interfaces, srv, Drop_Response)() {
  return get_message_type_support_handle<turtle_brick_interfaces::srv::Drop_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/drop__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace turtle_brick_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Drop_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Drop_type_support_ids_t;

static const _Drop_type_support_ids_t _Drop_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Drop_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Drop_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Drop_type_support_symbol_names_t _Drop_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtle_brick_interfaces, srv, Drop)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, turtle_brick_interfaces, srv, Drop)),
  }
};

typedef struct _Drop_type_support_data_t
{
  void * data[2];
} _Drop_type_support_data_t;

static _Drop_type_support_data_t _Drop_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Drop_service_typesupport_map = {
  2,
  "turtle_brick_interfaces",
  &_Drop_service_typesupport_ids.typesupport_identifier[0],
  &_Drop_service_typesupport_symbol_names.symbol_name[0],
  &_Drop_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Drop_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Drop_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<turtle_brick_interfaces::srv::Drop>()
{
  return &::turtle_brick_interfaces::srv::rosidl_typesupport_cpp::Drop_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
