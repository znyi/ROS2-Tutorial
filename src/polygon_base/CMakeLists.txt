cmake_minimum_required(VERSION 3.5)
project(polygon_base)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(pluginlib REQUIRED)

add_executable(area_node src/area_node.cpp)
target_include_directories(area_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  area_node
  "pluginlib"
)

# make the header ros2_ws/src/polygon_base/include/polygon_base/regular_polygon.hpp" available to other classes, add after ament_target_dependencies
install(
  DIRECTORY include/
  DESTINATION include
)

install(TARGETS area_node
  DESTINATION lib/${PROJECT_NAME})

# add this before ament_package
ament_export_include_directories(
  include
)

ament_package()
