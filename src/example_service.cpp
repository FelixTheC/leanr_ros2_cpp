#include "example_service.hpp"


ExampleServiceNode::ExampleServiceNode(): Node("example_service")
{
    RCLCPP_INFO(get_logger(), "ExampleServiceNode has been started.");
}




int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<ExampleServiceNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}