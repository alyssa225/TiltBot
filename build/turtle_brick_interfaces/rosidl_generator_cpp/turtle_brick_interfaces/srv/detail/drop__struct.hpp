// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_brick_interfaces:srv/Drop.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__STRUCT_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtle_brick_interfaces__srv__Drop_Request __attribute__((deprecated))
#else
# define DEPRECATED__turtle_brick_interfaces__srv__Drop_Request __declspec(deprecated)
#endif

namespace turtle_brick_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Drop_Request_
{
  using Type = Drop_Request_<ContainerAllocator>;

  explicit Drop_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->g = 0.0f;
    }
  }

  explicit Drop_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->g = 0.0f;
    }
  }

  // field types and members
  using _g_type =
    float;
  _g_type g;

  // setters for named parameter idiom
  Type & set__g(
    const float & _arg)
  {
    this->g = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_brick_interfaces__srv__Drop_Request
    std::shared_ptr<turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_brick_interfaces__srv__Drop_Request
    std::shared_ptr<turtle_brick_interfaces::srv::Drop_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Drop_Request_ & other) const
  {
    if (this->g != other.g) {
      return false;
    }
    return true;
  }
  bool operator!=(const Drop_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Drop_Request_

// alias to use template instance with default allocator
using Drop_Request =
  turtle_brick_interfaces::srv::Drop_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_brick_interfaces


#ifndef _WIN32
# define DEPRECATED__turtle_brick_interfaces__srv__Drop_Response __attribute__((deprecated))
#else
# define DEPRECATED__turtle_brick_interfaces__srv__Drop_Response __declspec(deprecated)
#endif

namespace turtle_brick_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Drop_Response_
{
  using Type = Drop_Response_<ContainerAllocator>;

  explicit Drop_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg = "";
    }
  }

  explicit Drop_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg = "";
    }
  }

  // field types and members
  using _msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_type msg;

  // setters for named parameter idiom
  Type & set__msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_brick_interfaces__srv__Drop_Response
    std::shared_ptr<turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_brick_interfaces__srv__Drop_Response
    std::shared_ptr<turtle_brick_interfaces::srv::Drop_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Drop_Response_ & other) const
  {
    if (this->msg != other.msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const Drop_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Drop_Response_

// alias to use template instance with default allocator
using Drop_Response =
  turtle_brick_interfaces::srv::Drop_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace turtle_brick_interfaces
{

namespace srv
{

struct Drop
{
  using Request = turtle_brick_interfaces::srv::Drop_Request;
  using Response = turtle_brick_interfaces::srv::Drop_Response;
};

}  // namespace srv

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__DROP__STRUCT_HPP_
