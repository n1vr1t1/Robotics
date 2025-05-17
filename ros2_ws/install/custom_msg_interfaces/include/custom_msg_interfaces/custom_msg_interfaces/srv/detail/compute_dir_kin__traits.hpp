// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msg_interfaces:srv/ComputeDirKin.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_dir_kin.hpp"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_DIR_KIN__TRAITS_HPP_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_DIR_KIN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msg_interfaces/srv/detail/compute_dir_kin__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace custom_msg_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeDirKin_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: joints
  {
    if (msg.joints.size() == 0) {
      out << "joints: []";
    } else {
      out << "joints: [";
      size_t pending_items = msg.joints.size();
      for (auto item : msg.joints) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: frame_id
  {
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeDirKin_Request & msg,
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

  // member: joints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joints.size() == 0) {
      out << "joints: []\n";
    } else {
      out << "joints:\n";
      for (auto item : msg.joints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeDirKin_Request & msg, bool use_flow_style = false)
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
  const custom_msg_interfaces::srv::ComputeDirKin_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::srv::ComputeDirKin_Request & msg)
{
  return custom_msg_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputeDirKin_Request>()
{
  return "custom_msg_interfaces::srv::ComputeDirKin_Request";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputeDirKin_Request>()
{
  return "custom_msg_interfaces/srv/ComputeDirKin_Request";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputeDirKin_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputeDirKin_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msg_interfaces::srv::ComputeDirKin_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'final_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace custom_msg_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeDirKin_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: final_pose
  {
    out << "final_pose: ";
    to_flow_style_yaml(msg.final_pose, out);
    out << ", ";
  }

  // member: status_message
  {
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << ", ";
  }

  // member: frame_id
  {
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeDirKin_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: final_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "final_pose:\n";
    to_block_style_yaml(msg.final_pose, out, indentation + 2);
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

  // member: frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeDirKin_Response & msg, bool use_flow_style = false)
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
  const custom_msg_interfaces::srv::ComputeDirKin_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::srv::ComputeDirKin_Response & msg)
{
  return custom_msg_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputeDirKin_Response>()
{
  return "custom_msg_interfaces::srv::ComputeDirKin_Response";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputeDirKin_Response>()
{
  return "custom_msg_interfaces/srv/ComputeDirKin_Response";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputeDirKin_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputeDirKin_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msg_interfaces::srv::ComputeDirKin_Response>
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
  const ComputeDirKin_Event & msg,
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
  const ComputeDirKin_Event & msg,
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

inline std::string to_yaml(const ComputeDirKin_Event & msg, bool use_flow_style = false)
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
  const custom_msg_interfaces::srv::ComputeDirKin_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::srv::ComputeDirKin_Event & msg)
{
  return custom_msg_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputeDirKin_Event>()
{
  return "custom_msg_interfaces::srv::ComputeDirKin_Event";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputeDirKin_Event>()
{
  return "custom_msg_interfaces/srv/ComputeDirKin_Event";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputeDirKin_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputeDirKin_Event>
  : std::integral_constant<bool, has_bounded_size<custom_msg_interfaces::srv::ComputeDirKin_Request>::value && has_bounded_size<custom_msg_interfaces::srv::ComputeDirKin_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<custom_msg_interfaces::srv::ComputeDirKin_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputeDirKin>()
{
  return "custom_msg_interfaces::srv::ComputeDirKin";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputeDirKin>()
{
  return "custom_msg_interfaces/srv/ComputeDirKin";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputeDirKin>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_msg_interfaces::srv::ComputeDirKin_Request>::value &&
    has_fixed_size<custom_msg_interfaces::srv::ComputeDirKin_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputeDirKin>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_msg_interfaces::srv::ComputeDirKin_Request>::value &&
    has_bounded_size<custom_msg_interfaces::srv::ComputeDirKin_Response>::value
  >
{
};

template<>
struct is_service<custom_msg_interfaces::srv::ComputeDirKin>
  : std::true_type
{
};

template<>
struct is_service_request<custom_msg_interfaces::srv::ComputeDirKin_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_msg_interfaces::srv::ComputeDirKin_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_DIR_KIN__TRAITS_HPP_
