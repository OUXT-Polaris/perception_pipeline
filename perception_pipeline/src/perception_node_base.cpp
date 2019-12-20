// Headers in this package
#include <perception_pipeline/percaption_node_base.h>

namespace perception_pipeline
{
    PerceptionNodeBase::PerceptionNodeBase(const rclcpp::NodeOptions & options)
    : Node("perception_pipeline_base", options)
    {
        object_classes_ = boost::none;
        declare_parameter("object_classes_topic",get_name() + std::string("/object_classes"));
        get_parameter("object_classes_topic",object_classes_topic_);
        auto object_classes_callback =
        [this](const typename perception_msgs::msg::ObjectClasses::SharedPtr msg) -> void
        {
            object_classes_mutex_.lock();
            object_classes_ = *msg;
            object_classes_mutex_.unlock();
        };
        sub_object_classes_ = create_subscription<perception_msgs::msg::ObjectClasses>(object_classes_topic_, 10, object_classes_callback);
    }
}