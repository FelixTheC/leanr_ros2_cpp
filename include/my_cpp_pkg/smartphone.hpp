#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"


#pragma once

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

class SmartphoneNode : public rclcpp::Node
{

public:
    SmartphoneNode();

private:
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;
    void 
    callbackRobotNews(const example_interfaces::msg::String::SharedPtr msg);

};

#endif
