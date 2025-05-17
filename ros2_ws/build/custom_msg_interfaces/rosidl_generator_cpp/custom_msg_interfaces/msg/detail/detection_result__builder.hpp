// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/msg/detection_result.hpp"


#ifndef CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__BUILDER_HPP_
#define CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msg_interfaces/msg/detail/detection_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msg_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectionResult_data
{
public:
  explicit Init_DetectionResult_data(::custom_msg_interfaces::msg::DetectionResult & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::msg::DetectionResult data(::custom_msg_interfaces::msg::DetectionResult::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::msg::DetectionResult msg_;
};

class Init_DetectionResult_header
{
public:
  Init_DetectionResult_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionResult_data header(::custom_msg_interfaces::msg::DetectionResult::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DetectionResult_data(msg_);
  }

private:
  ::custom_msg_interfaces::msg::DetectionResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::msg::DetectionResult>()
{
  return custom_msg_interfaces::msg::builder::Init_DetectionResult_header();
}

}  // namespace custom_msg_interfaces

#endif  // CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__BUILDER_HPP_
