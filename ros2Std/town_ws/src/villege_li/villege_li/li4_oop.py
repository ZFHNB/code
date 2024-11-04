# 导入库文件
import rclpy #ros client library python
from rclpy.node import Node

class WriterNode(Node):
    def __init__(self, name):
        super().__init__(name)
        self.get_logger().info("大家好，我是作家%s" % name)

def main(args=None):

    # 初始化客户端库
    rclpy.init(args=args)
    # 新建节点对象
    li4_node = WriterNode("li4")
    # spin循环节点
    rclpy.spin(li4_node)
    # 关闭客户端库
    rclpy.shutdown()