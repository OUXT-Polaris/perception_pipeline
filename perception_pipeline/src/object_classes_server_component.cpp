// Headers in this package
#include <perception_pipeline/object_classes_server_component.h>

namespace perception_pipeline
{
    ObjectClassesServerComponent::ObjectClassesServerComponent(const rclcpp::NodeOptions & options)
    : Node("object_classes_server", options)
    {

    }
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(perception_pipeline::ObjectClassesServerComponent)