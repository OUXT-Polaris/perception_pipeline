#ifndef PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_COMPONENT_H_INCLUDED
#define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_COMPONENT_H_INCLUDED

#if __cplusplus
extern "C" {
#endif

// The below macros are taken from https://gcc.gnu.org/wiki/Visibility and from
// demos/composition/include/composition/visibility_control.h at https://github.com/ros2/demos
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_EXPORT __attribute__ ((dllexport))
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_IMPORT __attribute__ ((dllimport))
  #else
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_EXPORT __declspec(dllexport)
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_IMPORT __declspec(dllimport)
  #endif
  #ifdef PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_BUILDING_DLL
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_PUBLIC PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_EXPORT
  #else
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_PUBLIC PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_IMPORT
  #endif
  #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_PUBLIC_TYPE PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_PUBLIC
  #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_LOCAL
#else
  #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_EXPORT __attribute__ ((visibility("default")))
  #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_IMPORT
  #if __GNUC__ >= 4
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_PUBLIC __attribute__ ((visibility("default")))
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_PUBLIC
    #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_LOCAL
  #endif
  #define PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_PUBLIC_TYPE
#endif

#if __cplusplus
} // extern "C"
#endif

//headers in ROS2
#include <rclcpp/rclcpp.hpp>

namespace perception_pipeline
{
    class ObjectClassesServerComponent: public rclcpp::Node
    {
    public:
        PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_PUBLIC
        explicit ObjectClassesServerComponent(const rclcpp::NodeOptions & options);
    };
}

#endif  //PERCEPTION_PIPELINE_OBJECT_CLASSES_SERVER_COMPONENT_H_INCLUDED