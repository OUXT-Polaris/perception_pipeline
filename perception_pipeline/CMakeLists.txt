cmake_minimum_required(VERSION 3.5)
project(perception_pipeline)

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

include_directories(
  include
)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(perception_msgs REQUIRED)

add_library(object_classes_server_component SHARED src/object_classes_server_component.cpp)
target_compile_definitions(object_classes_server_component PRIVATE "PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_BUILDING_DLL")
ament_target_dependencies(object_classes_server_component rclcpp rclcpp_components perception_msgs)
rclcpp_components_register_nodes(object_classes_server_component "perception_pipeline::ObjectClassesServerComponent")

add_executable(object_classes_server_node src/object_classes_server_node.cpp)
target_link_libraries(object_classes_server_node object_classes_server_component)
ament_target_dependencies(object_classes_server_node rclcpp rclcpp_components perception_msgs)

# install executables/libs
install(TARGETS
  object_classes_server_node
  DESTINATION lib/pcl_apps
)

install(TARGETS
  object_classes_server_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
