#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

#pragma once

#ifndef ROBOT_NEWS_STATION_H
#define ROBOT_NEWS_STATION_H

class RobotNewsStationNode : public rclcpp::Node
{
public:
    RobotNewsStationNode();

private:
    std::string robot_name;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    
    void publishNews();
};

#endif