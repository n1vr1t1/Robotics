// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_path.hpp"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_PATH__BUILDER_HPP_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msg_interfaces/srv/detail/compute_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputePath_Request_num_interpolations
{
public:
  explicit Init_ComputePath_Request_num_interpolations(::custom_msg_interfaces::srv::ComputePath_Request & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputePath_Request num_interpolations(::custom_msg_interfaces::srv::ComputePath_Request::_num_interpolations_type arg)
  {
    msg_.num_interpolations = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputePath_Request msg_;
};

class Init_ComputePath_Request_pose_end
{
public:
  explicit Init_ComputePath_Request_pose_end(::custom_msg_interfaces::srv::ComputePath_Request & msg)
  : msg_(msg)
  {}
  Init_ComputePath_Request_num_interpolations pose_end(::custom_msg_interfaces::srv::ComputePath_Request::_pose_end_type arg)
  {
    msg_.pose_end = std::move(arg);
    return Init_ComputePath_Request_num_interpolations(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputePath_Request msg_;
};

class Init_ComputePath_Request_pose_start
{
public:
  Init_ComputePath_Request_pose_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputePath_Request_pose_end pose_start(::custom_msg_interfaces::srv::ComputePath_Request::_pose_start_type arg)
  {
    msg_.pose_start = std::move(arg);
    return Init_ComputePath_Request_pose_end(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputePath_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputePath_Request>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputePath_Request_pose_start();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputePath_Response_poses
{
public:
  Init_ComputePath_Response_poses()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msg_interfaces::srv::ComputePath_Response poses(::custom_msg_interfaces::srv::ComputePath_Response::_poses_type arg)
  {
    msg_.poses = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputePath_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputePath_Response>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputePath_Response_poses();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputePath_Event_response
{
public:
  explicit Init_ComputePath_Event_response(::custom_msg_interfaces::srv::ComputePath_Event & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputePath_Event response(::custom_msg_interfaces::srv::ComputePath_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputePath_Event msg_;
};

class Init_ComputePath_Event_request
{
public:
  explicit Init_ComputePath_Event_request(::custom_msg_interfaces::srv::ComputePath_Event & msg)
  : msg_(msg)
  {}
  Init_ComputePath_Event_response request(::custom_msg_interfaces::srv::ComputePath_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComputePath_Event_response(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputePath_Event msg_;
};

class Init_ComputePath_Event_info
{
public:
  Init_ComputePath_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputePath_Event_request info(::custom_msg_interfaces::srv::ComputePath_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComputePath_Event_request(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputePath_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputePath_Event>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputePath_Event_info();
}

}  // namespace custom_msg_interfaces

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_PATH__BUILDER_HPP_
