// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msg_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_path.hpp"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_PATH__TRAITS_HPP_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msg_interfaces/srv/detail/compute_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose_start'
// Member 'pose_end'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace custom_msg_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputePath_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose_start
  {
    out << "pose_start: ";
    to_flow_style_yaml(msg.pose_start, out);
    out << ", ";
  }

  // member: pose_end
  {
    out << "pose_end: ";
    to_flow_style_yaml(msg.pose_end, out);
    out << ", ";
  }

  // member: num_interpolations
  {
    out << "num_interpolations: ";
    rosidl_generator_traits::value_to_yaml(msg.num_interpolations, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputePath_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_start:\n";
    to_block_style_yaml(msg.pose_start, out, indentation + 2);
  }

  // member: pose_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_end:\n";
    to_block_style_yaml(msg.pose_end, out, indentation + 2);
  }

  // member: num_interpolations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_interpolations: ";
    rosidl_generator_traits::value_to_yaml(msg.num_interpolations, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputePath_Request & msg, bool use_flow_style = false)
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
  const custom_msg_interfaces::srv::ComputePath_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::srv::ComputePath_Request & msg)
{
  return custom_msg_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputePath_Request>()
{
  return "custom_msg_interfaces::srv::ComputePath_Request";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputePath_Request>()
{
  return "custom_msg_interfaces/srv/ComputePath_Request";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputePath_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputePath_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<custom_msg_interfaces::srv::ComputePath_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'poses'
// already included above
// #include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace custom_msg_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputePath_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: poses
  {
    if (msg.poses.size() == 0) {
      out << "poses: []";
    } else {
      out << "poses: [";
      size_t pending_items = msg.poses.size();
      for (auto item : msg.poses) {
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
  const ComputePath_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: poses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.poses.size() == 0) {
      out << "poses: []\n";
    } else {
      out << "poses:\n";
      for (auto item : msg.poses) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputePath_Response & msg, bool use_flow_style = false)
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
  const custom_msg_interfaces::srv::ComputePath_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::srv::ComputePath_Response & msg)
{
  return custom_msg_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputePath_Response>()
{
  return "custom_msg_interfaces::srv::ComputePath_Response";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputePath_Response>()
{
  return "custom_msg_interfaces/srv/ComputePath_Response";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputePath_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputePath_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msg_interfaces::srv::ComputePath_Response>
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
  const ComputePath_Event & msg,
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
  const ComputePath_Event & msg,
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

inline std::string to_yaml(const ComputePath_Event & msg, bool use_flow_style = false)
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
  const custom_msg_interfaces::srv::ComputePath_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg_interfaces::srv::ComputePath_Event & msg)
{
  return custom_msg_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputePath_Event>()
{
  return "custom_msg_interfaces::srv::ComputePath_Event";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputePath_Event>()
{
  return "custom_msg_interfaces/srv/ComputePath_Event";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputePath_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputePath_Event>
  : std::integral_constant<bool, has_bounded_size<custom_msg_interfaces::srv::ComputePath_Request>::value && has_bounded_size<custom_msg_interfaces::srv::ComputePath_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<custom_msg_interfaces::srv::ComputePath_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msg_interfaces::srv::ComputePath>()
{
  return "custom_msg_interfaces::srv::ComputePath";
}

template<>
inline const char * name<custom_msg_interfaces::srv::ComputePath>()
{
  return "custom_msg_interfaces/srv/ComputePath";
}

template<>
struct has_fixed_size<custom_msg_interfaces::srv::ComputePath>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_msg_interfaces::srv::ComputePath_Request>::value &&
    has_fixed_size<custom_msg_interfaces::srv::ComputePath_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_msg_interfaces::srv::ComputePath>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_msg_interfaces::srv::ComputePath_Request>::value &&
    has_bounded_size<custom_msg_interfaces::srv::ComputePath_Response>::value
  >
{
};

template<>
struct is_service<custom_msg_interfaces::srv::ComputePath>
  : std::true_type
{
};

template<>
struct is_service_request<custom_msg_interfaces::srv::ComputePath_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_msg_interfaces::srv::ComputePath_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_PATH__TRAITS_HPP_
