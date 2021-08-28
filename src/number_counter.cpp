#include "number_counter.hpp"


NumberCounterNode::NumberCounterNode() : Node("number_counter"), counter_(0)
{
    publisher_ = create_publisher<InterfaceInt64>("number_count", 10);
    subscriber_ = create_subscription<InterfaceInt64>(
        "number",
        10, 
        std::bind(
            &NumberCounterNode::callbackNumberTopic, 
            this, 
            std::placeholders::_1
            )
        );
    server_ = create_service<ISrv::SetBool>("reset_counter", 
                             std::bind(&NumberCounterNode::callbackSetBool, 
                                this, _1, _2));
    RCLCPP_INFO(get_logger(), "Number counter has been started.");
}

void 
NumberCounterNode::callbackNumberTopic(InterfaceInt64::SharedPtr number)
{
    addToCounter(number->data);
    
    auto msg = InterfaceInt64();
    msg.data = getCounter();
    publisher_->publish(msg);
}

void 
NumberCounterNode::setCounter(int newNumber)
{
    counter_ = newNumber;
}

void 
NumberCounterNode::addToCounter(int newNumber)
{
    setCounter(counter_ + newNumber);
}

int 
NumberCounterNode::getCounter()
{
    return counter_;
}

void
NumberCounterNode::callbackSetBool(const ISrv::SetBool::Request::SharedPtr request, 
                                   const ISrv::SetBool::Response::SharedPtr response)
{
    std::string msg;

    if (request->data == true)
    {
        counter_ = 0;
        msg = "Counter has been reset.";
        response->success = true;
    }
    else
    {
        msg = std::string("Current Counter value: %d", counter_);
        response->success = false;
    }    
    
    response->message = msg;
}


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<NumberCounterNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}