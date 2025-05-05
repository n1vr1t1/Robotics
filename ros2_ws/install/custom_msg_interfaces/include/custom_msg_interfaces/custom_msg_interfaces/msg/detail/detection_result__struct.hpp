// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msg_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/msg/detection_result.hpp"


#ifndef CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_HPP_
#define CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msg_interfaces__msg__DetectionResult __attribute__((deprecated))
#else
# define DEPRECATED__custom_msg_interfaces__msg__DetectionResult __declspec(deprecated)
#endif

namespace custom_msg_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectionResult_
{
  using Type = DetectionResult_<ContainerAllocator>;

  explicit DetectionResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit DetectionResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _data_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msg_interfaces__msg__DetectionResult
    std::shared_ptr<custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msg_interfaces__msg__DetectionResult
    std::shared_ptr<custom_msg_interfaces::msg::DetectionResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionResult_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionResult_

// alias to use template instance with default allocator
using DetectionResult =
  custom_msg_interfaces::msg::DetectionResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msg_interfaces

#endif  // CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_HPP_
