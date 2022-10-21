import unittest
from launch import LaunchDescription
from launch_ros.actions import Node
import launch_testing
import pytest
import rclpy
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import Twist


@pytest.mark.rostest
def test_cmdvel():
    turtle_robot_action = Node(package="turtle_brick",
                               executable="turtle_robot", )
    return (
        LaunchDescription([
            turtle_robot_action,
            launch_testing.actions.ReadyToTest()
            ]),
        {
            'turtle_robot': turtle_robot_action
        }
    )


class TestTurtleRobot(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        rclpy.init()

    @classmethod
    def tearDownClass(cls):
        rclpy.shutdown()

    def setUp(self):
        self.node = rclpy.create_node("test_node")

    def tearDown(self):
        self.node.destroy_node()

    def test_publisher(self, launch_service, in_out, proc_output):
        self.timestart = PoseStamped()
        self.time = PoseStamped()
        self.tilt_sub = self.create_subscription(Twist, '/cmd_vel', self.test_callback, 10)
        self.i = 0
        rclpy.spin(self.node)

    def test_callback(self, msg):
        if self.i == 0:
            self.timestart.header.stamp = self.get_clock().now().to_msg()
            self.timestart.pose.position.x = msg.position.x
            self.timestart.pose.position.y = msg.position.y
            self.timestart.pose.position.z = msg.position.z
            ti = (float(self.timestart.header.stamp.sec)
                  + float(self.timestart.header.stamp.nanosec) / 1000000000.0)
        self.get_logger().info('goal pose: %f %f %f'
                               % (msg.position.x, msg.position.y,
                                  msg.position.z))
        self.time.header.stamp = self.get_clock().now().to_msg()
        self.time.pose.position.x = msg.position.x
        self.time.pose.position.y = msg.position.y
        self.time.pose.position.z = msg.position.z
        tf = (float(self.time.header.stamp.sec)
              + float(self.time.header.stamp.nanosec) / 1000000000.0)
        self.i += 1
        if (tf - ti) >= 1:
            assert self.i == 100
            self.i = 0
