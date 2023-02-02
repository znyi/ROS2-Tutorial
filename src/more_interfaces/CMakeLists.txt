cmake_minimum_required(VERSION 3.5)
project(more_interfaces)

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


find_package(rosidl_default_generators REQUIRED)
# find_package(rosidl_tutorials_msgs REQUIRED)

# use set(srv_files ... ) for .srv files
set(msg_files
  "msg/AddressBook.msg"
  # add more if there are multiple interfaces
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  # ${srv_files}
  # DEPENDENCIES rosidl_tutorials_msgs
)

ament_export_dependencies(rosidl_default_runtime)

# 순서 주의해야 함, 위에서 만들어진 interface는 publish_address_book의 dependency이기 때문에, interface 먼저 만들어줘야 함

find_package(rclcpp REQUIRED)
add_executable(publish_address_book
  src/publish_address_book.cpp
)
ament_target_dependencies(publish_address_book
  "rclcpp"
)
install(TARGETS publish_address_book
  DESTINATION lib/${PROJECT_NAME})

#TO USE THE MESSAGES GENERATED IN THE SAME PACKAGE, IT FINDS THE RELEVANT GENERATED CPP CODE FROM AddressBook.msg AND ALLOWS THE TARGET TO LINK AGAINST IT
rosidl_target_interfaces(publish_address_book   
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

ament_package()
