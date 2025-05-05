// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msg_interfaces:srv/ComputeIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_ik.hpp"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_IK__TRAITS_HPP_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_IK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msg_interfaces/srv/detail/compute_ik__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace custom_msg_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeIK_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: target_pose
  {
    out << "target_pose: ";
    to_flow_style_yaml(msg.target_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeIK_Request & msg,
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

  // member: target_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_pose:\n";
    to_block_style_yaml(msg.target_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeIK_Request & msg, bool use_flow_style = false)
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

}  // namespace custom_msg_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_msg_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msg_interfaces::srv::ComputeIK_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::srv::ComputeIK_Request & msg)
{
  return custom_msg_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputeIK_Request>()
{
  return "custom_msg_interfaces::srv::ComputeIK_Request";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputeIK_Request>()
{
  return "custom_msg_interfaces/srv/ComputeIK_Request";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputeIK_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputeIK_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<custom_msg_interfaces::srv::ComputeIK_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'joint_angles_matrix'
#include "std_msgs/msg/detail/float64_multi_array__traits.hpp"

namespace custom_msg_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeIK_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint_angles_matrix
  {
    out << "joint_angles_matrix: ";
    to_flow_style_yaml(msg.joint_angles_matrix, out);
    out << ", ";
  }

  // member: status_message
  {
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeIK_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint_angles_matrix
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_angles_matrix:\n";
    to_block_style_yaml(msg.joint_angles_matrix, out, indentation + 2);
  }

  // member: status_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeIK_Response & msg, bool use_flow_style = false)
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

}  // namespace custom_msg_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_msg_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msg_interfaces::srv::ComputeIK_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::srv::ComputeIK_Response & msg)
{
  return custom_msg_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputeIK_Response>()
{
  return "custom_msg_interfaces::srv::ComputeIK_Response";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputeIK_Response>()
{
  return "custom_msg_interfaces/srv/ComputeIK_Response";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputeIK_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputeIK_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msg_interfaces::srv::ComputeIK_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace custom_msg_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeIK_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
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
  const ComputeIK_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeIK_Event & msg, bool use_flow_style = false)
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

}  // namespace custom_msg_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_msg_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msg_interfaces::srv::ComputeIK_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::srv::ComputeIK_Event & msg)
{
  return custom_msg_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputeIK_Event>()
{
  return "custom_msg_interfaces::srv::ComputeIK_Event";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputeIK_Event>()
{
  return "custom_msg_interfaces/srv/ComputeIK_Event";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputeIK_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputeIK_Event>
  : std::integral_constant<bool, has_bounded_size<custom_msg_interfaces::srv::ComputeIK_Request>::value && has_bounded_size<custom_msg_interfaces::srv::ComputeIK_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<custom_msg_interfaces::srv::ComputeIK_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputeIK>()
{
  return "custom_msg_interfaces::srv::ComputeIK";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputeIK>()
{
  return "custom_msg_interfaces/srv/ComputeIK";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputeIK>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_msg_interfaces::srv::ComputeIK_Request>::value &&
    has_fixed_size<custom_msg_interfaces::srv::ComputeIK_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputeIK>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_msg_interfaces::srv::ComputeIK_Request>::value &&
    has_bounded_size<custom_msg_interfaces::srv::ComputeIK_Response>::value
  >
{
};

template<>
struct is_service<custom_msg_interfaces::srv::ComputeIK>
  : std::true_type
{
};

template<>
struct is_service_request<custom_msg_interfaces::srv::ComputeIK_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_msg_interfaces::srv::ComputeIK_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_IK__TRAITS_HPP_
