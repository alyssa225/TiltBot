// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_brick_interfaces:msg/Tilt.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__TRAITS_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_brick_interfaces/msg/detail/tilt__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_brick_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Tilt & msg,
  std::ostream & out)
{
  out << "{";
  // member: alpha
  {
    out << "alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.alpha, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tilt & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.alpha, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tilt & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtle_brick_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_brick_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_brick_interfaces::msg::Tilt & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::msg::Tilt & msg)
{
  return turtle_brick_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::msg::Tilt>()
{
  return "turtle_brick_interfaces::msg::Tilt";
}

template<>
inline const char * name<turtle_brick_interfaces::msg::Tilt>()
{
  return "turtle_brick_interfaces/msg/Tilt";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::msg::Tilt>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::msg::Tilt>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::msg::Tilt>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__TRAITS_HPP_
