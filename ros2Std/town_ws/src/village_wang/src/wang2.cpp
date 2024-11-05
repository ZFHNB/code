// 编写ROS2节点的一般步骤
// 1.导入库文件
#include "rclcpp/rclcpp.hpp"
/* 1.导入消息类型 */
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32.hpp"

using std::placeholders::_1;

class SingleDogNode : public rclcpp::Node
{
private:
    /* 3.声明订阅对象 */
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_novel;
    /* 2.创建回调函数 */
    void novel_callback(const std_msgs::msg::String::SharedPtr novels)
    {
        /* 4.编写回调处理逻辑 */
        RCLCPP_INFO(this->get_logger(), "朕已阅%s。", novels->data.c_str());
    }
public:
    SingleDogNode(std::string name);
};

SingleDogNode::SingleDogNode(std::string name) : Node(name)//使用初始化列表初始化对象成员
{
    RCLCPP_INFO(this->get_logger(), "大家好，我是单身狗%s.", name.c_str());

    /* 3.实例化订阅对象 */
    sub_novel = this->create_subscription<std_msgs::msg::String>("sexy_girl", 10, std::bind(&SingleDogNode::novel_callback, this, _1));
}

int main(int argc, char **argv)
{
    // 2.初始化客户端库
    rclcpp::init(argc, argv);
    // 3.新建节点对象
    auto node = std::make_shared<SingleDogNode>("wang2");
    
    // 4.spin循环节点
    rclcpp::spin(node);
    // 5.关闭客户端库
    rclcpp::shutdown();
}

