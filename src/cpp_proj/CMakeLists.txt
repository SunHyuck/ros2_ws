cmake_minimum_required(VERSION 3.8)
project(cpp_proj)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Manually specify PROJ library paths
set(PROJ_INCLUDE_DIRS /usr/include)
set(PROJ_LIBRARIES /usr/lib/x86_64-linux-gnu/libproj.so)

include_directories(include)
include_directories(/usr/include)  # Add PROJ headers path
include_directories(${PROJ_INCLUDE_DIRS})
link_directories(${PROJ_LIBRARY_DIRS})

add_executable(transpose src/proj_coordinate.cpp)
ament_target_dependencies(transpose rclcpp std_msgs)

# Link against the PROJ library
target_link_libraries(transpose ${PROJ_LIBRARIES})

install(TARGETS
  transpose
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
