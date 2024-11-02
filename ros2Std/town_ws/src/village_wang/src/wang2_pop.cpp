// 编写ROS2节点的一般步骤
// 1.导入库文件
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    // 2.初始化客户端库
    rclcpp::init(argc, argv);
    // 3.新建节点对象
    auto node = std::make_shared<rclcpp::Node>("wang2");
    RCLCPP_INFO(node->get_logger(), "大家好，我是单身狗wang2.");
    // 4.spin循环节点
    rclcpp::spin(node);
    // 5.关闭客户端库
    rclcpp::shutdown();
}

