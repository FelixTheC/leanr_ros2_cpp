#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

#pragma once

#ifndef NUMBER_PUBLISHER_H
#define NUMBER_PUBLISHER_H

using rclcpp::TimerBase;
using rclcpp::Publisher;

class NumberPublisherNode : public rclcpp::Node
{
public:
    NumberPublisherNode();

private:
    int number = 2;
    TimerBase::SharedPtr timer_;
    Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;

    void publishNumber();

};

#endif