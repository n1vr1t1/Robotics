// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg_interfaces:srv/ComputeTrajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_trajectory.hpp"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_TRAJECTORY__BUILDER_HPP_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msg_interfaces/srv/detail/compute_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeTrajectory_Request_array
{
public:
  Init_ComputeTrajectory_Request_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msg_interfaces::srv::ComputeTrajectory_Request array(::custom_msg_interfaces::srv::ComputeTrajectory_Request::_array_type arg)
  {
    msg_.array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeTrajectory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputeTrajectory_Request>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputeTrajectory_Request_array();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeTrajectory_Response_status_message
{
public:
  explicit Init_ComputeTrajectory_Response_status_message(::custom_msg_interfaces::srv::ComputeTrajectory_Response & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputeTrajectory_Response status_message(::custom_msg_interfaces::srv::ComputeTrajectory_Response::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeTrajectory_Response msg_;
};

class Init_ComputeTrajectory_Response_trajectory
{
public:
  Init_ComputeTrajectory_Response_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeTrajectory_Response_status_message trajectory(::custom_msg_interfaces::srv::ComputeTrajectory_Response::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_ComputeTrajectory_Response_status_message(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeTrajectory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputeTrajectory_Response>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputeTrajectory_Response_trajectory();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeTrajectory_Event_response
{
public:
  explicit Init_ComputeTrajectory_Event_response(::custom_msg_interfaces::srv::ComputeTrajectory_Event & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::ComputeTrajectory_Event response(::custom_msg_interfaces::srv::ComputeTrajectory_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeTrajectory_Event msg_;
};

class Init_ComputeTrajectory_Event_request
{
public:
  explicit Init_ComputeTrajectory_Event_request(::custom_msg_interfaces::srv::ComputeTrajectory_Event & msg)
  : msg_(msg)
  {}
  Init_ComputeTrajectory_Event_response request(::custom_msg_interfaces::srv::ComputeTrajectory_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComputeTrajectory_Event_response(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeTrajectory_Event msg_;
};

class Init_ComputeTrajectory_Event_info
{
public:
  Init_ComputeTrajectory_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeTrajectory_Event_request info(::custom_msg_interfaces::srv::ComputeTrajectory_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComputeTrajectory_Event_request(msg_);
  }

private:
  ::custom_msg_interfaces::srv::ComputeTrajectory_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::ComputeTrajectory_Event>()
{
  return custom_msg_interfaces::srv::builder::Init_ComputeTrajectory_Event_info();
}

}  // namespace custom_msg_interfaces

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_TRAJECTORY__BUILDER_HPP_
