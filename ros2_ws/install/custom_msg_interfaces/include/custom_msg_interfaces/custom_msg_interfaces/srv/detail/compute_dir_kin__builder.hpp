// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg_interfaces:srv/ComputeDirKin.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_dir_kin.hpp"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_DIR_KIN__BUILDER_HPP_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_DIR_KIN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msg_interfaces/srv/detail/compute_dir_kin__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeDirKin_Request_frame_id
{
public:
  explicit Init_ComputeDirKin_Request_frame_id(::custom_msg_interfaces::srv::ComputeDirKin_Request & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputeDirKin_Request frame_id(::custom_msg_interfaces::srv::ComputeDirKin_Request::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeDirKin_Request msg_;
};

class Init_ComputeDirKin_Request_joints
{
public:
  explicit Init_ComputeDirKin_Request_joints(::custom_msg_interfaces::srv::ComputeDirKin_Request & msg)
  : msg_(msg)
  {}
  Init_ComputeDirKin_Request_frame_id joints(::custom_msg_interfaces::srv::ComputeDirKin_Request::_joints_type arg)
  {
    msg_.joints = std::move(arg);
    return Init_ComputeDirKin_Request_frame_id(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeDirKin_Request msg_;
};

class Init_ComputeDirKin_Request_header
{
public:
  Init_ComputeDirKin_Request_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeDirKin_Request_joints header(::custom_msg_interfaces::srv::ComputeDirKin_Request::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ComputeDirKin_Request_joints(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeDirKin_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputeDirKin_Request>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputeDirKin_Request_header();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeDirKin_Response_frame_id
{
public:
  explicit Init_ComputeDirKin_Response_frame_id(::custom_msg_interfaces::srv::ComputeDirKin_Response & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputeDirKin_Response frame_id(::custom_msg_interfaces::srv::ComputeDirKin_Response::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeDirKin_Response msg_;
};

class Init_ComputeDirKin_Response_status_message
{
public:
  explicit Init_ComputeDirKin_Response_status_message(::custom_msg_interfaces::srv::ComputeDirKin_Response & msg)
  : msg_(msg)
  {}
  Init_ComputeDirKin_Response_frame_id status_message(::custom_msg_interfaces::srv::ComputeDirKin_Response::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return Init_ComputeDirKin_Response_frame_id(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeDirKin_Response msg_;
};

class Init_ComputeDirKin_Response_final_pose
{
public:
  Init_ComputeDirKin_Response_final_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeDirKin_Response_status_message final_pose(::custom_msg_interfaces::srv::ComputeDirKin_Response::_final_pose_type arg)
  {
    msg_.final_pose = std::move(arg);
    return Init_ComputeDirKin_Response_status_message(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeDirKin_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputeDirKin_Response>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputeDirKin_Response_final_pose();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeDirKin_Event_response
{
public:
  explicit Init_ComputeDirKin_Event_response(::custom_msg_interfaces::srv::ComputeDirKin_Event & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputeDirKin_Event response(::custom_msg_interfaces::srv::ComputeDirKin_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeDirKin_Event msg_;
};

class Init_ComputeDirKin_Event_request
{
public:
  explicit Init_ComputeDirKin_Event_request(::custom_msg_interfaces::srv::ComputeDirKin_Event & msg)
  : msg_(msg)
  {}
  Init_ComputeDirKin_Event_response request(::custom_msg_interfaces::srv::ComputeDirKin_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComputeDirKin_Event_response(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeDirKin_Event msg_;
};

class Init_ComputeDirKin_Event_info
{
public:
  Init_ComputeDirKin_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeDirKin_Event_request info(::custom_msg_interfaces::srv::ComputeDirKin_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComputeDirKin_Event_request(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeDirKin_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputeDirKin_Event>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputeDirKin_Event_info();
}

}  // namespace custom_msg_interfaces

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_DIR_KIN__BUILDER_HPP_
