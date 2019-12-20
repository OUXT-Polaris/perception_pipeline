#ifndef PERCEPTION_PIPELINE_PERCEPTION_NODE_BASE_H_INCLUDED
#define PERCEPTION_PIPELINE_PERCEPTION_NODE_BASE_H_INCLUDED

// Headers in ROS2
#include <rclcpp/rclcpp.hpp>

// Headers in perception_pipeline
#include <perception_msgs/msg/object_classes.hpp>

// Headers in STL
#include <mutex>

// Headers in Boost
#include <boost/optional.hpp>

namespace perception_pipeline
{
    class PerceptionNodeBase : rclcpp::Node
    {
    public:
        explicit PerceptionNodeBase(const rclcpp::NodeOptions & options);
    private:
        std::shared_ptr<rclcpp::Subscription<perception_msgs::msg::ObjectClasses> > sub_object_classes_;
        std::string object_classes_topic_;
        std::mutex object_classes_mutex_;
        boost::optional<perception_msgs::msg::ObjectClasses> getObjectClasses()
        {
            object_classes_mutex_.lock();
            boost::optional<perception_msgs::msg::ObjectClasses> ret;
            object_classes_mutex_.unlock();
            return ret;
        }
        boost::optional<perception_msgs::msg::ObjectClasses> object_classes_;
    };
}

#endif  //PERCEPTION_PIPELINE_PERCEPTION_NODE_BASE_H_INCLUDED