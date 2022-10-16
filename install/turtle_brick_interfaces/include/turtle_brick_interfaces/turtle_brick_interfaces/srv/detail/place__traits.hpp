// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_brick_interfaces:srv/Place.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__PLACE__TRAITS_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__PLACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_brick_interfaces/srv/detail/place__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_brick_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Place_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Place_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Place_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_brick_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_brick_interfaces::srv::Place_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::srv::Place_Request & msg)
{
  return turtle_brick_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::srv::Place_Request>()
{
  return "turtle_brick_interfaces::srv::Place_Request";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::Place_Request>()
{
  return "turtle_brick_interfaces/srv/Place_Request";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::Place_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::Place_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::srv::Place_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace turtle_brick_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Place_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Place_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Place_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_brick_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_brick_interfaces::srv::Place_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::srv::Place_Response & msg)
{
  return turtle_brick_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::srv::Place_Response>()
{
  return "turtle_brick_interfaces::srv::Place_Response";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::Place_Response>()
{
  return "turtle_brick_interfaces/srv/Place_Response";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::Place_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::Place_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::srv::Place_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turtle_brick_interfaces::srv::Place>()
{
  return "turtle_brick_interfaces::srv::Place";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::Place>()
{
  return "turtle_brick_interfaces/srv/Place";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::Place>
  : std::integral_constant<
    bool,
    has_fixed_size<turtle_brick_interfaces::srv::Place_Request>::value &&
    has_fixed_size<turtle_brick_interfaces::srv::Place_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::Place>
  : std::integral_constant<
    bool,
    has_bounded_size<turtle_brick_interfaces::srv::Place_Request>::value &&
    has_bounded_size<turtle_brick_interfaces::srv::Place_Response>::value
  >
{
};

template<>
struct is_service<turtle_brick_interfaces::srv::Place>
  : std::true_type
{
};

template<>
struct is_service_request<turtle_brick_interfaces::srv::Place_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtle_brick_interfaces::srv::Place_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__PLACE__TRAITS_HPP_
