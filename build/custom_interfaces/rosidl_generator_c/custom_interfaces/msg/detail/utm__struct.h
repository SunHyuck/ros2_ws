// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Utm.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__UTM__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__UTM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'raw_data'
// Member 'message_id'
// Member 'lat_dir'
// Member 'lon_dir'
// Member 'alt_unit'
// Member 'sep_unit'
// Member 'check_sum'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Utm in the package custom_interfaces.
typedef struct custom_interfaces__msg__Utm
{
  rosidl_runtime_c__String raw_data;
  rosidl_runtime_c__String message_id;
  double utc;
  double lat;
  rosidl_runtime_c__String lat_dir;
  double lon;
  rosidl_runtime_c__String lon_dir;
  int16_t quality;
  int16_t num_satelite;
  double hdop;
  double alt;
  rosidl_runtime_c__String alt_unit;
  double sep;
  rosidl_runtime_c__String sep_unit;
  double diff_age;
  int16_t diff_station;
  rosidl_runtime_c__String check_sum;
  int32_t easting;
  int32_t northing;
} custom_interfaces__msg__Utm;

// Struct for a sequence of custom_interfaces__msg__Utm.
typedef struct custom_interfaces__msg__Utm__Sequence
{
  custom_interfaces__msg__Utm * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Utm__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__UTM__STRUCT_H_
