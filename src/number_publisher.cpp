#include "my_cpp_pkg/number_publisher.h"

using std::chrono::milliseconds;

NumberPublisherNode::NumberPublisherNode(): Node("number_publisher")
{
    publisher_ = create_publisher<example_interfaces::msg::Int64>("number", 10);
    timer_ = create_wall_timer(
                                milliseconds(500), // means 2Hz
                                std::bind(&NumberPublisherNode::publishNumber, this)
                               );
    RCLCPP_INFO(get_logger(), "Number publisher has been started.");
}

void 
NumberPublisherNode::publishNumber()
{
    auto msg = example_interfaces::msg::Int64();
    msg.data = number;
    publisher_->publish(msg);
}


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<NumberPublisherNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}