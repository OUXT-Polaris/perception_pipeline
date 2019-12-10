// Headers in this package
#include <perception_pipeline/object_classes_server_component.h>

namespace perception_pipeline
{
    ObjectClassesServerComponent::ObjectClassesServerComponent(const rclcpp::NodeOptions & options)
    : Node("object_classes_server", options)
    {
        declare_parameter("xml_path","");
        if(!has_parameter("xml_path"))
        {
            RCLCPP_ERROR(get_logger(),"param xml_path does not set.");
            return;
        }
        std::string xml_path = get_parameter("xml_path").get_value<std::string>();
        std::ifstream ifs(xml_path);
        std::string xml_string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
        using namespace boost::property_tree;
        ptree pt;
        std::stringstream ss;
        ss << xml_string;
        try
        {
            read_xml(ss, pt);
            BOOST_FOREACH (const ptree::value_type& child, pt.get_child("classes"))
            {
                if(child.first == "class")
                {
                    perception_msgs::msg::ObjectClass object_class;
                    boost::optional<int> id = child.second.get_optional<int>("<xmlattr>.id");
                    boost::optional<std::string> name = child.second.get_optional<std::string>("<xmlattr>.name");
                    if(id && name)
                    {
                        object_class.id = id.get();
                        object_class.class_name = name.get();
                        object_classes_.classes.push_back(object_class);
                    }
                    else
                    {
                        return;
                    }
                }
            }
        }
        catch(...)
        {
            return;
        }
        object_classes_pub_ = create_publisher<perception_msgs::msg::ObjectClasses>("object_classes", rclcpp::QoS(10).transient_local());
        object_classes_pub_->publish(object_classes_);
    }
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(perception_pipeline::ObjectClassesServerComponent)