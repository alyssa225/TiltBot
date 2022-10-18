// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_brick_interfaces:srv/Place.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__PLACE__BUILDER_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__PLACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_brick_interfaces/srv/detail/place__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_Place_Request_z
{
public:
  explicit Init_Place_Request_z(::turtle_brick_interfaces::srv::Place_Request & msg)
  : msg_(msg)
  {}
  ::turtle_brick_interfaces::srv::Place_Request z(::turtle_brick_interfaces::srv::Place_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Request msg_;
};

class Init_Place_Request_y
{
public:
  explicit Init_Place_Request_y(::turtle_brick_interfaces::srv::Place_Request & msg)
  : msg_(msg)
  {}
  Init_Place_Request_z y(::turtle_brick_interfaces::srv::Place_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Place_Request_z(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Request msg_;
};

class Init_Place_Request_x
{
public:
  Init_Place_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Place_Request_y x(::turtle_brick_interfaces::srv::Place_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Place_Request_y(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::Place_Request>()
{
  return turtle_brick_interfaces::srv::builder::Init_Place_Request_x();
}

}  // namespace turtle_brick_interfaces


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_Place_Response_msg
{
public:
  Init_Place_Response_msg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_brick_interfaces::srv::Place_Response msg(::turtle_brick_interfaces::srv::Place_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::Place_Response>()
{
  return turtle_brick_interfaces::srv::builder::Init_Place_Response_msg();
}

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__PLACE__BUILDER_HPP_
