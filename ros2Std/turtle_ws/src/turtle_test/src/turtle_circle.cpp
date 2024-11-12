#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class TurtleCircle : public rclcpp::Node
{
private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub;

public:
    TurtleCircle(std::string name);
};

TurtleCircle::TurtleCircle(std::string name) : Node(name)
{
    RCLCPP_INFO(this->get_logger(), "我可以让小乌龟做圆周运动");

    // 创建一个Publisher，用于发布Twist消息到"cmd_vel"话题
    pub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

    // 创建一个定时器，用于定期发布消息
    this->create_timer(
        std::chrono::seconds(1),
        std::bind(&TurtleCircle::timerCallback, this, std::placeholders::_1));
}

// 定义定时器回调函数
void TurtleCircle::timerCallback(const rclcpp::TimerBase::SharedPtr timer)
{
    geometry_msgs::msg::Twist msg;
    msg.linear.x = 0.5; // 设置线速度
    msg.angular.z = 1.0; // 设置角速度

    // 发布消息
    pub->publish(msg);
}

int main(int argc, char **argv)
{
    // 1.初始化客户端库
    rclcpp::init(argc, argv);
    // 2.新建节点对象
    auto node = std::make_shared<TurtleCircle>("wang2");
    
    // 3.spin循环节点
    rclcpp::spin(node);
    // 4.关闭客户端库
    rclcpp::shutdown();
    return 0;
}