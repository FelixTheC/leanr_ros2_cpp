//
// Created by felix on 08.08.21.
//
#include "rclcpp/rclcpp.hpp"


class MyNode : public rclcpp::Node
{
public:
    MyNode(): Node("cpp_test"), counter(0)
    {
        RCLCPP_INFO(get_logger(), "Hello Cpp Node");

        timer = create_wall_timer(std::chrono::seconds(1),
                                  std::bind(&MyNode::timerConsumer, this));
    }

private:
    int counter;
    rclcpp::TimerBase::SharedPtr timer;

    void timerConsumer()
    {
        ++counter;
        RCLCPP_INFO(get_logger(), "Hello %d", counter);
    }

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<MyNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
