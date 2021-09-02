#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

#pragma once

#ifndef HW_STATUS_PUBLISHER_HPP
#define HW_STATUS_PUBLISHER_HPP

using rclcpp::TimerBase;
using rclcpp::Publisher;
using hardware_status=my_robot_interfaces::msg::HardwareStatus;

class HwStatusPublisherNode : public rclcpp::Node
{

public:
    HwStatusPublisherNode();

private:
    TimerBase::SharedPtr timer_;
    Publisher<hardware_status>::SharedPtr publisher_;

    void publishHardwareStatus();
};

#endif