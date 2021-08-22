#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

#pragma once
#ifndef NUMBER_COUNTER_H
#define NUMBER_COUNTER_H

using rclcpp::Publisher;
using rclcpp::Subscription;
using InterfaceInt64 = example_interfaces::msg::Int64;

class NumberCounterNode : public rclcpp::Node
{
private:
    int counter_;
    Publisher<InterfaceInt64>::SharedPtr publisher_;
    Subscription<InterfaceInt64>::SharedPtr subscriber_;
    void callbackNumberTopic(InterfaceInt64::SharedPtr number);
    void publishCounter();

public:
    NumberCounterNode();

    void setCounter(int number);
    void addToCounter(int number);
    int getCounter();
};

#endif