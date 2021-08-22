#include "rclcpp/rclcpp.hpp"
#include "smartphone.hpp"


SmartphoneNode::SmartphoneNode(): Node("smartphone")
{
    subscriber_ = create_subscription<example_interfaces::msg::String>("robot_news", 
                                                                        10, 
                                                                        std::bind(
                                                                            &SmartphoneNode::callbackRobotNews, 
                                                                            this,
                                                                            std::placeholders::_1
                                                                            )
                                                                      );
    RCLCPP_INFO(get_logger(), "Smartphone has been started.");
}

void 
SmartphoneNode::callbackRobotNews(const example_interfaces::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(get_logger(), "%s", msg->data.c_str());
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<SmartphoneNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}