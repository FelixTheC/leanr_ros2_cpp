#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
#include "example_interfaces/srv/set_bool.hpp"
#include <math.h>

#pragma once

#ifndef NUMBER_CLIENT_HPP
#define NUMBER_CLIENT_HPP

namespace ISrv = example_interfaces::srv;

using rclcpp::Client;
using rclcpp::Subscription;
using InterfaceInt64 = example_interfaces::msg::Int64;
using std::placeholders::_1;

class NumberClientNode : public rclcpp::Node
{

private:
    int number_;
    Subscription<InterfaceInt64>::SharedPtr subscriber_;
    Client<ISrv::SetBool>::SharedPtr client_;

public:
    NumberClientNode();
    void callbackNumberCount(InterfaceInt64::SharedPtr number);
    void callbackClient(const bool &reset);
    void callAddTwoIntsService(const int &a, const int &b);
};

#endif