cmake_minimum_required(VERSION 3.5)
project(cpp_srvcli)

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
find_package(rclcpp REQUIRED)
find_package(tutorial_interfaces REQUIRED)

# server is the name of the executable, called using ros2 run. the thing after 'server' is source code
add_executable(server src/add_three_ints_server.cpp)
ament_target_dependencies(server rclcpp tutorial_interfaces)

# client
add_executable(client src/add_three_ints_client.cpp)
ament_target_dependencies(client rclcpp tutorial_interfaces)

# i think i should memorize the things beside the server 
install(TARGETS
  server
  client
  DESTINATION lib/${PROJECT_NAME})

ament_package()
