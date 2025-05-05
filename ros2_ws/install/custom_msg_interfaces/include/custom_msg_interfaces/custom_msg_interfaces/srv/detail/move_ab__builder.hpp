// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg_interfaces:srv/MoveAB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/move_ab.hpp"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__MOVE_AB__BUILDER_HPP_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__MOVE_AB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msg_interfaces/srv/detail/move_ab__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveAB_Request_pose_end
{
public:
  explicit Init_MoveAB_Request_pose_end(::custom_msg_interfaces::srv::MoveAB_Request & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::MoveAB_Request pose_end(::custom_msg_interfaces::srv::MoveAB_Request::_pose_end_type arg)
  {
    msg_.pose_end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::MoveAB_Request msg_;
};

class Init_MoveAB_Request_pose_start
{
public:
  Init_MoveAB_Request_pose_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAB_Request_pose_end pose_start(::custom_msg_interfaces::srv::MoveAB_Request::_pose_start_type arg)
  {
    msg_.pose_start = std::move(arg);
    return Init_MoveAB_Request_pose_end(msg_);
  }

private:
  ::custom_msg_interfaces::srv::MoveAB_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::MoveAB_Request>()
{
  return custom_msg_interfaces::srv::builder::Init_MoveAB_Request_pose_start();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveAB_Response_message
{
public:
  explicit Init_MoveAB_Response_message(::custom_msg_interfaces::srv::MoveAB_Response & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::MoveAB_Response message(::custom_msg_interfaces::srv::MoveAB_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::MoveAB_Response msg_;
};

class Init_MoveAB_Response_success
{
public:
  Init_MoveAB_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAB_Response_message success(::custom_msg_interfaces::srv::MoveAB_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveAB_Response_message(msg_);
  }

private:
  ::custom_msg_interfaces::srv::MoveAB_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::MoveAB_Response>()
{
  return custom_msg_interfaces::srv::builder::Init_MoveAB_Response_success();
}

}  // namespace custom_msg_interfaces


namespace custom_msg_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveAB_Event_response
{
public:
  explicit Init_MoveAB_Event_response(::custom_msg_interfaces::srv::MoveAB_Event & msg)
  : msg_(msg)
  {}
  ::custom_msg_interfaces::srv::MoveAB_Event response(::custom_msg_interfaces::srv::MoveAB_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_interfaces::srv::MoveAB_Event msg_;
};

class Init_MoveAB_Event_request
{
public:
  explicit Init_MoveAB_Event_request(::custom_msg_interfaces::srv::MoveAB_Event & msg)
  : msg_(msg)
  {}
  Init_MoveAB_Event_response request(::custom_msg_interfaces::srv::MoveAB_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveAB_Event_response(msg_);
  }

private:
  ::custom_msg_interfaces::srv::MoveAB_Event msg_;
};

class Init_MoveAB_Event_info
{
public:
  Init_MoveAB_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAB_Event_request info(::custom_msg_interfaces::srv::MoveAB_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveAB_Event_request(msg_);
  }

private:
  ::custom_msg_interfaces::srv::MoveAB_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_interfaces::srv::MoveAB_Event>()
{
  return custom_msg_interfaces::srv::builder::Init_MoveAB_Event_info();
}

}  // namespace custom_msg_interfaces

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__MOVE_AB__BUILDER_HPP_
