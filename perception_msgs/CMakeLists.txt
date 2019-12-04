cmake_minimum_required(VERSION 3.5)
project(perception_msgs)

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
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(unique_identifier_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)

set(msg_files
  "msg/Score.msg"
  "msg/SourceInfo.msg"
  "msg/BoundingBox3D.msg"
  "msg/ObjectClasses.msg"
  "msg/ObjectShape2D.msg"
  "msg/ObjectShape3D.msg"
  "msg/ObjectPose3D.msg"
  "msg/DetectedObject2D.msg"
  "msg/DetectedObject2DArray.msg"
  "msg/DetectedObject3D.msg"
  "msg/DetectedObject3DArray.msg"
  "msg/TrackedObject2D.msg"
  "msg/TrackedObject2DArray.msg"
  "msg/TrackedObject3D.msg"
  "msg/TrackedObject3DArray.msg"
)
rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  DEPENDENCIES builtin_interfaces std_msgs sensor_msgs geometry_msgs unique_identifier_msgs
)
ament_export_dependencies(rosidl_default_runtime)

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

ament_export_dependencies(rosidl_default_runtime)
ament_export_include_directories(include)
ament_package()
