// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msg_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice
#include "custom_msg_interfaces/msg/detail/detection_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
custom_msg_interfaces__msg__DetectionResult__init(custom_msg_interfaces__msg__DetectionResult * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    custom_msg_interfaces__msg__DetectionResult__fini(msg);
    return false;
  }
  // data
  if (!rosidl_runtime_c__float__Sequence__init(&msg->data, 0)) {
    custom_msg_interfaces__msg__DetectionResult__fini(msg);
    return false;
  }
  return true;
}

void
custom_msg_interfaces__msg__DetectionResult__fini(custom_msg_interfaces__msg__DetectionResult * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // data
  rosidl_runtime_c__float__Sequence__fini(&msg->data);
}

bool
custom_msg_interfaces__msg__DetectionResult__are_equal(const custom_msg_interfaces__msg__DetectionResult * lhs, const custom_msg_interfaces__msg__DetectionResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
custom_msg_interfaces__msg__DetectionResult__copy(
  const custom_msg_interfaces__msg__DetectionResult * input,
  custom_msg_interfaces__msg__DetectionResult * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

custom_msg_interfaces__msg__DetectionResult *
custom_msg_interfaces__msg__DetectionResult__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__msg__DetectionResult * msg = (custom_msg_interfaces__msg__DetectionResult *)allocator.allocate(sizeof(custom_msg_interfaces__msg__DetectionResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msg_interfaces__msg__DetectionResult));
  bool success = custom_msg_interfaces__msg__DetectionResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msg_interfaces__msg__DetectionResult__destroy(custom_msg_interfaces__msg__DetectionResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msg_interfaces__msg__DetectionResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msg_interfaces__msg__DetectionResult__Sequence__init(custom_msg_interfaces__msg__DetectionResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__msg__DetectionResult * data = NULL;

  if (size) {
    data = (custom_msg_interfaces__msg__DetectionResult *)allocator.zero_allocate(size, sizeof(custom_msg_interfaces__msg__DetectionResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msg_interfaces__msg__DetectionResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msg_interfaces__msg__DetectionResult__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msg_interfaces__msg__DetectionResult__Sequence__fini(custom_msg_interfaces__msg__DetectionResult__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msg_interfaces__msg__DetectionResult__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msg_interfaces__msg__DetectionResult__Sequence *
custom_msg_interfaces__msg__DetectionResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__msg__DetectionResult__Sequence * array = (custom_msg_interfaces__msg__DetectionResult__Sequence *)allocator.allocate(sizeof(custom_msg_interfaces__msg__DetectionResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msg_interfaces__msg__DetectionResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msg_interfaces__msg__DetectionResult__Sequence__destroy(custom_msg_interfaces__msg__DetectionResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msg_interfaces__msg__DetectionResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msg_interfaces__msg__DetectionResult__Sequence__are_equal(const custom_msg_interfaces__msg__DetectionResult__Sequence * lhs, const custom_msg_interfaces__msg__DetectionResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msg_interfaces__msg__DetectionResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msg_interfaces__msg__DetectionResult__Sequence__copy(
  const custom_msg_interfaces__msg__DetectionResult__Sequence * input,
  custom_msg_interfaces__msg__DetectionResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msg_interfaces__msg__DetectionResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msg_interfaces__msg__DetectionResult * data =
      (custom_msg_interfaces__msg__DetectionResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msg_interfaces__msg__DetectionResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msg_interfaces__msg__DetectionResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msg_interfaces__msg__DetectionResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
