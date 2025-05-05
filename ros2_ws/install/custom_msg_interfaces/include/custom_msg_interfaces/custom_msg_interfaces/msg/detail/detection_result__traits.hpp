// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msg_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/msg/detection_result.hpp"


#ifndef CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__TRAITS_HPP_
#define CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msg_interfaces/msg/detail/detection_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace custom_msg_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectionResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionResult & msg, bool use_flow_style = false)
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

}  // namespace custom_msg_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_msg_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msg_interfaces::msg::DetectionResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::msg::DetectionResult & msg)
{
  return custom_msg_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::msg::DetectionResult>()
{
  return "custom_msg_interfaces::msg::DetectionResult";
}

template<>
inline const char * name<custom_msg_interfaces::msg::DetectionResult>()
{
  return "custom_msg_interfaces/msg/DetectionResult";
}

template<>
struct has_fixed_size<custom_msg_interfaces::msg::DetectionResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msg_interfaces::msg::DetectionResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msg_interfaces::msg::DetectionResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__TRAITS_HPP_
