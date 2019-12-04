// Headers in this package
#include <perception_pipeline/object_classes_server_component.h>
// Headers in RCLCPP
#include <rclcpp/rclcpp.hpp>

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::NodeOptions options;
    //auto component = std::make_shared<pcl_apps::EuclideanClusteringComponent>(options);
    //rclcpp::spin(component);
    rclcpp::shutdown();
    return 0;
}