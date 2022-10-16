// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_brick_interfaces:srv/Drop.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__BUILDER_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_brick_interfaces/srv/detail/drop__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_Drop_Request_g
{
public:
  Init_Drop_Request_g()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_brick_interfaces::srv::Drop_Request g(::turtle_brick_interfaces::srv::Drop_Request::_g_type arg)
  {
    msg_.g = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Drop_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::Drop_Request>()
{
  return turtle_brick_interfaces::srv::builder::Init_Drop_Request_g();
}

}  // namespace turtle_brick_interfaces


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_Drop_Response_g
{
public:
  Init_Drop_Response_g()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_brick_interfaces::srv::Drop_Response g(::turtle_brick_interfaces::srv::Drop_Response::_g_type arg)
  {
    msg_.g = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Drop_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::Drop_Response>()
{
  return turtle_brick_interfaces::srv::builder::Init_Drop_Response_g();
}

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__BUILDER_HPP_
