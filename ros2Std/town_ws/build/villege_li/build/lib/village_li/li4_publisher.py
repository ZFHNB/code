# 导入库文件
import rclpy #ros client library python
from rclpy.node import Node
# 1.导入消息类型
from std_msgs.msg import String

# 编写一个话题发布者一流程：

# 1.导入消息类型

# 2.声明并创建发布者

# 3.编写发布逻辑发布数据

class WriterNode(Node):
    def __init__(self, name):
        super().__init__(name)
        self.get_logger().info("大家好，我是作家%s" % name)

    # 2.声明并创建发布者
        self.pub_novel = self.create_publisher(String, "sexy_girl", 10)

        self.count = 0 #计数器
        self.timer_period = 5 #定时间隔，单位s
        self.timer = self.create_timer(self.timer_period, self.timer_callback) #创建并启动定时器
    def timer_callback(self):
        msg = String()
        msg.data = "第%d回：潋滟湖 %d 次偶遇胡艳娘" % (self.count,self.count)
        self.pub_novel.publish(msg) #发布者发布消息
        self.get_logger().info('李四:我发布了一个章节，内容是："%s"' % msg.data)
        self.count += 1
def main(args=None):

    # 初始化客户端库
    rclpy.init(args=args)
    # 新建节点对象
    li4_node = WriterNode("li4")
    # spin循环节点
    rclpy.spin(li4_node)
    # 关闭客户端库
    rclpy.shutdown()