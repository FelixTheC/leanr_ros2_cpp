#include "hw_status_publisher.hpp"


HwStatusPublisherNode::HwStatusPublisherNode(): Node("hw_status_publisher")
{
    publisher_ = create_publisher<hardware_status>("hardware_status", 10);
    timer_ = create_wall_timer(
        std::chrono::seconds(1),
        std::bind(&HwStatusPublisherNode::publishHardwareStatus, this)
    );
    RCLCPP_INFO(get_logger(), "HwStatusPublisherNode has been started.");
}

void 
HwStatusPublisherNode::publishHardwareStatus()
{
    auto msg = hardware_status();
    msg.temperature = 42;
    msg.are_motors_ready = false;
    msg.debug_message = "Motors are too hot";
    publisher_->publish(msg);
}


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<HwStatusPublisherNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}