# 导入库文件
import rclpy #ros client library python
from rclpy.node import Node

def main(args=None):

    # 初始化客户端库
    rclpy.init(args=args)
    # 新建节点
    li4_node = Node("li4")
    li4_node.get_logger().info("我是李四")
    # spin循环节点
    rclpy.spin(li4_node)
    # 关闭客户端库
    rclpy.shutdown()