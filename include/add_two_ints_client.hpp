#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
#include <vector>
#include <math.h>

#pragma once

#ifndef ADD_TWO_INTS_CLIENT_HPP
#define ADD_TWO_INTS_CLIENT_HPP

namespace ISrv = example_interfaces::srv;

class AddTwoIntsClientNode : public rclcpp::Node
{
private:
    std::vector<std::thread> threads;

public:
    AddTwoIntsClientNode();
    ~AddTwoIntsClientNode() = default;
    void callAddTwoIntsService(const int &a, const int &b);
};

#endif