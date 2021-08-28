#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"

#pragma once
#ifndef NUMBER_COUNTER_H
#define NUMBER_COUNTER_H

using rclcpp::Publisher;
using rclcpp::Service;
using rclcpp::Subscription;
using InterfaceInt64 = example_interfaces::msg::Int64;
using std::placeholders::_1;
using std::placeholders::_2;

namespace ISrv = example_interfaces::srv;

class NumberCounterNode : public rclcpp::Node
{
private:
    int counter_;
    Publisher<InterfaceInt64>::SharedPtr publisher_;
    Service<ISrv::SetBool>::SharedPtr server_;
    Subscription<InterfaceInt64>::SharedPtr subscriber_;
    
    void callbackNumberTopic(InterfaceInt64::SharedPtr number);
    void callbackSetBool(
        const ISrv::SetBool::Request::SharedPtr request,
        const ISrv::SetBool::Response::SharedPtr response
    );
    void publishCounter();

public:
    NumberCounterNode();

    void setCounter(int number);
    void addToCounter(int number);
    int getCounter();
};

#endif