#include "add_two_ints_server.hpp"

using std::placeholders::_1;
using std::placeholders::_2;


AddTwoIntsServerNode::AddTwoIntsServerNode(): Node("add_two_ints_server")
{
    server_ = create_service<ISrv::AddTwoInts>(
        "add_two_ints",
        std::bind(&AddTwoIntsServerNode::callbackAddTwoInt, this, _1, _2));
    RCLCPP_INFO(get_logger(), "AddTwoIntsServerNode has been started.");
}

void 
AddTwoIntsServerNode::callbackAddTwoInt(
    const ISrv::AddTwoInts::Request::SharedPtr request, 
    const ISrv::AddTwoInts::Response::SharedPtr response)
{
    response->sum = request->a + request->b;
    RCLCPP_INFO(get_logger(), "%d + %d = %d", request->a, request->b, response->sum);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<AddTwoIntsServerNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}