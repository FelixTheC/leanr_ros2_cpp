#include "add_two_ints_client.hpp"


AddTwoIntsClientNode::AddTwoIntsClientNode(): Node("add_two_ints_client")
{
    RCLCPP_INFO(get_logger(), "AddTwoIntsClientNode has been started.");
    for (int i=0; i<10; ++i)
    {
        threads.push_back(std::thread(
            std::bind(
                &AddTwoIntsClientNode::callAddTwoIntsService, this, i, std::pow(i, 2)
                )));
    }
}

void 
AddTwoIntsClientNode::callAddTwoIntsService(const int &a, const int &b)
{
    auto client_ = create_client<ISrv::AddTwoInts>("add_two_ints");

    while(!client_->wait_for_service(std::chrono::seconds(1)))
        RCLCPP_WARN(get_logger(), "Waiting for server to be up...");
    
    auto request_ = std::make_shared<ISrv::AddTwoInts_Request>();
    request_->a = a;
    request_->b = b;
    
    auto future = client_->async_send_request(request_);
    try
    {
        auto response = future.get();
        RCLCPP_INFO(get_logger(), 
                    "%d + %d = %d", request_->a, request_->b, response->sum);
    }
    catch(const std::exception& e)
    {
        RCLCPP_ERROR(get_logger(), "Service failed %s", e.what());
    }
}


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<AddTwoIntsClientNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}