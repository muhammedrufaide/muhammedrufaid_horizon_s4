#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32

class DistanceSubscriber(Node):

    def __init__(self):
        super().__init__('distance_subscriber')
        self.subscription = self.create_subscription(
            Int32,
            'distance',
            self.callback,
            10
        )

    def callback(self, msg):
        self.get_logger().info(f'Received distance: {msg.data}')

def main(args=None):
    rclpy.init(args=args)
    node = DistanceSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()