#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

#pragma once

#ifndef ADD_TWO_INTS_SERVER_HPP
#define ADD_TWO_INTS_SERVER_HPP

namespace ISrv = example_interfaces::srv;

class AddTwoIntsServerNode : public rclcpp::Node
{
private:
    
    rclcpp::Service<ISrv::AddTwoInts>::SharedPtr server_;
    void 
    callbackAddTwoInt(
        const ISrv::AddTwoInts::Request::SharedPtr request, 
        const ISrv::AddTwoInts::Response::SharedPtr response
        );

public:
    AddTwoIntsServerNode();

};

#endif