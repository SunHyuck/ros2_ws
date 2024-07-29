cmake_minimum_required(VERSION 3.8)
project(cpp_parsing)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(custom_interfaces REQUIRED)
find_package(Qt5 COMPONENTS SerialPort REQUIRED)

add_executable(reader src/nmea_reader.cpp)
ament_target_dependencies(reader rclcpp std_msgs)

add_executable(parser src/utm_parser.cpp)
ament_target_dependencies(parser rclcpp std_msgs custom_interfaces)

target_link_libraries(reader
  Qt5::SerialPort
)

install(TARGETS
  reader
  parser
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()