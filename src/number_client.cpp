#include "number_client.hpp"


NumberClientNode::NumberClientNode(): Node("number_client")
{
    subscriber_ = create_subscription<InterfaceInt64>(
        "number_count", 
        10,
        std::bind(
            &NumberClientNode::callbackNumberCount, 
            this, _1));

    client_ = create_client<ISrv::SetBool>("reset_counter");
    RCLCPP_INFO(get_logger(), "NumberClientNode has been started.");
}

void 
NumberClientNode::callbackNumberCount(InterfaceInt64::SharedPtr number)
{
    number_ = number->data;
    RCLCPP_INFO(get_logger(), "Number is %d", number_);

    if (number_ > 50)
    {
        std::thread thread(
            std::bind(&NumberClientNode::callbackClient, this, true)
        );

        if(thread.joinable())
            thread.detach();

    }
}

void 
NumberClientNode::callbackClient(const bool &reset)
{
    while(!client_->wait_for_service(std::chrono::seconds(1)))
        RCLCPP_WARN(get_logger(), "Waiting for server to be up...");

    auto request_ = std::make_shared<ISrv::SetBool_Request>();

    request_->data = reset;

    auto future = client_->async_send_request(request_);
    
    if(future.valid())
    {
        RCLCPP_INFO(get_logger(), "Status: valid async request");
        try
        {
            auto response = future.get();
            RCLCPP_INFO(get_logger(), "Response message: " + response->message);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else 
    {
        RCLCPP_INFO(get_logger(), "Status: invalid async request");
    }
}


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<NumberClientNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}