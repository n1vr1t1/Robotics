// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg_interfaces:srv/ComputeIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_ik.hpp"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_IK__BUILDER_HPP_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_IK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msg_interfaces/srv/detail/compute_ik__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeIK_Request_target_pose
{
public:
  explicit Init_ComputeIK_Request_target_pose(::custom_msg_interfaces::srv::ComputeIK_Request & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputeIK_Request target_pose(::custom_msg_interfaces::srv::ComputeIK_Request::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeIK_Request msg_;
};

class Init_ComputeIK_Request_header
{
public:
  Init_ComputeIK_Request_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeIK_Request_target_pose header(::custom_msg_interfaces::srv::ComputeIK_Request::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ComputeIK_Request_target_pose(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeIK_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputeIK_Request>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputeIK_Request_header();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeIK_Response_status_message
{
public:
  explicit Init_ComputeIK_Response_status_message(::custom_msg_interfaces::srv::ComputeIK_Response & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputeIK_Response status_message(::custom_msg_interfaces::srv::ComputeIK_Response::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeIK_Response msg_;
};

class Init_ComputeIK_Response_joint_angles_matrix
{
public:
  Init_ComputeIK_Response_joint_angles_matrix()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeIK_Response_status_message joint_angles_matrix(::custom_msg_interfaces::srv::ComputeIK_Response::_joint_angles_matrix_type arg)
  {
    msg_.joint_angles_matrix = std::move(arg);
    return Init_ComputeIK_Response_status_message(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeIK_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputeIK_Response>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputeIK_Response_joint_angles_matrix();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeIK_Event_response
{
public:
  explicit Init_ComputeIK_Event_response(::custom_msg_interfaces::srv::ComputeIK_Event & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputeIK_Event response(::custom_msg_interfaces::srv::ComputeIK_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeIK_Event msg_;
};

class Init_ComputeIK_Event_request
{
public:
  explicit Init_ComputeIK_Event_request(::custom_msg_interfaces::srv::ComputeIK_Event & msg)
  : msg_(msg)
  {}
  Init_ComputeIK_Event_response request(::custom_msg_interfaces::srv::ComputeIK_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComputeIK_Event_response(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeIK_Event msg_;
};

class Init_ComputeIK_Event_info
{
public:
  Init_ComputeIK_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeIK_Event_request info(::custom_msg_interfaces::srv::ComputeIK_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComputeIK_Event_request(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeIK_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputeIK_Event>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputeIK_Event_info();
}

}  // namespace custom_msg_interfaces

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_IK__BUILDER_HPP_
