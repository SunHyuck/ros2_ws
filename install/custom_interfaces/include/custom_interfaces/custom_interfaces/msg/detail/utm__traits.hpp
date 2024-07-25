// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/Utm.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__UTM__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__UTM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/utm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Utm & msg,
  std::ostream & out)
{
  out << "{";
  // member: raw_data
  {
    out << "raw_data: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_data, out);
    out << ", ";
  }

  // member: message_id
  {
    out << "message_id: ";
    rosidl_generator_traits::value_to_yaml(msg.message_id, out);
    out << ", ";
  }

  // member: utc
  {
    out << "utc: ";
    rosidl_generator_traits::value_to_yaml(msg.utc, out);
    out << ", ";
  }

  // member: lat
  {
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << ", ";
  }

  // member: lat_dir
  {
    out << "lat_dir: ";
    rosidl_generator_traits::value_to_yaml(msg.lat_dir, out);
    out << ", ";
  }

  // member: lon
  {
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << ", ";
  }

  // member: lon_dir
  {
    out << "lon_dir: ";
    rosidl_generator_traits::value_to_yaml(msg.lon_dir, out);
    out << ", ";
  }

  // member: quality
  {
    out << "quality: ";
    rosidl_generator_traits::value_to_yaml(msg.quality, out);
    out << ", ";
  }

  // member: num_satelite
  {
    out << "num_satelite: ";
    rosidl_generator_traits::value_to_yaml(msg.num_satelite, out);
    out << ", ";
  }

  // member: hdop
  {
    out << "hdop: ";
    rosidl_generator_traits::value_to_yaml(msg.hdop, out);
    out << ", ";
  }

  // member: alt
  {
    out << "alt: ";
    rosidl_generator_traits::value_to_yaml(msg.alt, out);
    out << ", ";
  }

  // member: alt_unit
  {
    out << "alt_unit: ";
    rosidl_generator_traits::value_to_yaml(msg.alt_unit, out);
    out << ", ";
  }

  // member: sep
  {
    out << "sep: ";
    rosidl_generator_traits::value_to_yaml(msg.sep, out);
    out << ", ";
  }

  // member: sep_unit
  {
    out << "sep_unit: ";
    rosidl_generator_traits::value_to_yaml(msg.sep_unit, out);
    out << ", ";
  }

  // member: diff_age
  {
    out << "diff_age: ";
    rosidl_generator_traits::value_to_yaml(msg.diff_age, out);
    out << ", ";
  }

  // member: diff_station
  {
    out << "diff_station: ";
    rosidl_generator_traits::value_to_yaml(msg.diff_station, out);
    out << ", ";
  }

  // member: check_sum
  {
    out << "check_sum: ";
    rosidl_generator_traits::value_to_yaml(msg.check_sum, out);
    out << ", ";
  }

  // member: easting
  {
    out << "easting: ";
    rosidl_generator_traits::value_to_yaml(msg.easting, out);
    out << ", ";
  }

  // member: northing
  {
    out << "northing: ";
    rosidl_generator_traits::value_to_yaml(msg.northing, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Utm & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: raw_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_data: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_data, out);
    out << "\n";
  }

  // member: message_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message_id: ";
    rosidl_generator_traits::value_to_yaml(msg.message_id, out);
    out << "\n";
  }

  // member: utc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc: ";
    rosidl_generator_traits::value_to_yaml(msg.utc, out);
    out << "\n";
  }

  // member: lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << "\n";
  }

  // member: lat_dir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lat_dir: ";
    rosidl_generator_traits::value_to_yaml(msg.lat_dir, out);
    out << "\n";
  }

  // member: lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << "\n";
  }

  // member: lon_dir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lon_dir: ";
    rosidl_generator_traits::value_to_yaml(msg.lon_dir, out);
    out << "\n";
  }

  // member: quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quality: ";
    rosidl_generator_traits::value_to_yaml(msg.quality, out);
    out << "\n";
  }

  // member: num_satelite
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_satelite: ";
    rosidl_generator_traits::value_to_yaml(msg.num_satelite, out);
    out << "\n";
  }

  // member: hdop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hdop: ";
    rosidl_generator_traits::value_to_yaml(msg.hdop, out);
    out << "\n";
  }

  // member: alt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alt: ";
    rosidl_generator_traits::value_to_yaml(msg.alt, out);
    out << "\n";
  }

  // member: alt_unit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alt_unit: ";
    rosidl_generator_traits::value_to_yaml(msg.alt_unit, out);
    out << "\n";
  }

  // member: sep
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sep: ";
    rosidl_generator_traits::value_to_yaml(msg.sep, out);
    out << "\n";
  }

  // member: sep_unit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sep_unit: ";
    rosidl_generator_traits::value_to_yaml(msg.sep_unit, out);
    out << "\n";
  }

  // member: diff_age
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "diff_age: ";
    rosidl_generator_traits::value_to_yaml(msg.diff_age, out);
    out << "\n";
  }

  // member: diff_station
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "diff_station: ";
    rosidl_generator_traits::value_to_yaml(msg.diff_station, out);
    out << "\n";
  }

  // member: check_sum
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "check_sum: ";
    rosidl_generator_traits::value_to_yaml(msg.check_sum, out);
    out << "\n";
  }

  // member: easting
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "easting: ";
    rosidl_generator_traits::value_to_yaml(msg.easting, out);
    out << "\n";
  }

  // member: northing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "northing: ";
    rosidl_generator_traits::value_to_yaml(msg.northing, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Utm & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::Utm & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::Utm & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::Utm>()
{
  return "custom_interfaces::msg::Utm";
}

template<>
inline const char * name<custom_interfaces::msg::Utm>()
{
  return "custom_interfaces/msg/Utm";
}

template<>
struct has_fixed_size<custom_interfaces::msg::Utm>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::Utm>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::Utm>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__UTM__TRAITS_HPP_
