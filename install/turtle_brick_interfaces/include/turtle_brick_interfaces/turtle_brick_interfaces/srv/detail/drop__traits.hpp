// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_brick_interfaces:srv/Drop.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__TRAITS_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_brick_interfaces/srv/detail/drop__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_brick_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Drop_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: g
  {
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Drop_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Drop_Request & msg, bool use_flow_style = false)
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
  const turtle_brick_interfaces::srv::Drop_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::srv::Drop_Request & msg)
{
  return turtle_brick_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::srv::Drop_Request>()
{
  return "turtle_brick_interfaces::srv::Drop_Request";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::Drop_Request>()
{
  return "turtle_brick_interfaces/srv/Drop_Request";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::Drop_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::Drop_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::srv::Drop_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace turtle_brick_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Drop_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: g
  {
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Drop_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Drop_Response & msg, bool use_flow_style = false)
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
  const turtle_brick_interfaces::srv::Drop_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::srv::Drop_Response & msg)
{
  return turtle_brick_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::srv::Drop_Response>()
{
  return "turtle_brick_interfaces::srv::Drop_Response";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::Drop_Response>()
{
  return "turtle_brick_interfaces/srv/Drop_Response";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::Drop_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::Drop_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::srv::Drop_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turtle_brick_interfaces::srv::Drop>()
{
  return "turtle_brick_interfaces::srv::Drop";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::Drop>()
{
  return "turtle_brick_interfaces/srv/Drop";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::Drop>
  : std::integral_constant<
    bool,
    has_fixed_size<turtle_brick_interfaces::srv::Drop_Request>::value &&
    has_fixed_size<turtle_brick_interfaces::srv::Drop_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::Drop>
  : std::integral_constant<
    bool,
    has_bounded_size<turtle_brick_interfaces::srv::Drop_Request>::value &&
    has_bounded_size<turtle_brick_interfaces::srv::Drop_Response>::value
  >
{
};

template<>
struct is_service<turtle_brick_interfaces::srv::Drop>
  : std::true_type
{
};

template<>
struct is_service_request<turtle_brick_interfaces::srv::Drop_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtle_brick_interfaces::srv::Drop_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__TRAITS_HPP_
