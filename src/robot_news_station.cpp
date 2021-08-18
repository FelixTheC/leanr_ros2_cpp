#include "my_cpp_pkg/robot_news_station.hpp"


RobotNewsStationNode::RobotNewsStationNode(): Node("robot_news_station"), robot_name("R2D2")
{
    publisher_ = create_publisher<example_interfaces::msg::String>("robot_news", 10);
    timer_ = create_wall_timer(std::chrono::milliseconds(500), 
                                std::bind(&RobotNewsStationNode::publishNews, this)
                                );
    RCLCPP_INFO(get_logger(), "Robot News Station has been started.");
}

void 
RobotNewsStationNode::publishNews()
{
    auto msg = example_interfaces::msg::String();
    msg.data = "Hi this is " + robot_name + " from the Robot News Station";

    publisher_->publish(msg);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<RobotNewsStationNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}