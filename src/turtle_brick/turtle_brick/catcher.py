"""
Create one static frame and two moving frames.

The tf tree produced from this node will look like

      world
       |
      base
      /  \
    left right

The left and right nodes will move in and out and rotate about the base z axis

"""
from cmath import sqrt
from time import sleep
import rclpy
from rclpy.node import Node
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped, Pose, PoseStamped, Vector3
from turtle_brick_interfaces.srv import Place, Drop
from turtle_brick_interfaces.msg import Tilt
from visualization_msgs.msg import Marker 
import math 
from std_msgs.msg import Bool
from .quaternion import angle_axis_to_quaternion
from enum import Enum, auto

class State(Enum):
    """ Current state of the brick.
    """
    WAITING = auto(),
    TILT = auto(),

class Catcher(Node):
    """
    Moves some frames around.

    Static Broadcasts:
       world -> base
    Broadcasts:
       base -> left and base -> right
    """

    def __init__(self):
        super().__init__('catcher')
        #params
        self.declare_parameters( 
            namespace='',
            parameters=[
                ('platform_height', 1.7),
                ('wheel_radius', 0.3),
                ('max_velocity',3.0),
                ('gravity',9.8)
            ]
        )
        self.height = self.get_parameter("platform_height").get_parameter_value().double_value
        self.rwheel = self.get_parameter("wheel_radius").get_parameter_value().double_value
        self.vmax = self.get_parameter("max_velocity").get_parameter_value().double_value
        self.g = self.get_parameter("gravity").get_parameter_value().double_value
        #variables
        self.platformx = 0.0
        self.platformy = 0.0
        #state
        self.state = State.WAITING
        #subscritions
        self.robot_sub = self.create_subscription(Pose,'/robot',self.robot_callback,10)
        self.drop_sub = self.create_subscription(Vector3,'/drop', self.drop_callback,10)
        self.catch_sub = self.create_subscription(Bool,'/catch', self.catch_callback,10)
        #publisher
        self.brick_land_pub= self.create_publisher(Pose,'/land',10)
        self.goal_pub= self.create_publisher(PoseStamped,'/goal_pose',10)
        self.tilt_pub= self.create_publisher(Tilt,'/tilt',10)
        self.marker_pub = self.create_publisher(Marker,'/marker',10)
        #pose and posestamp and tilt
        self.brick_pose = Pose()
    
        #the text marker
        self.text_marker = Marker()
        self.text_marker.header.frame_id = "world"
        self.text_marker.header.stamp = self.get_clock().now().to_msg()
        self.text_marker.ns = "brick"
        self.text_marker.id = 0
        self.text_marker.lifetime.sec = 3
        self.text_marker.type = Marker.TEXT_VIEW_FACING
        self.text_marker.action = Marker.ADD
        self.text_marker.scale.x = 2.0
        self.text_marker.scale.y = 4.0
        self.text_marker.scale.z = 1.0
        self.text_marker.color.a = 1.0
        self.text_marker.color.r = 1.0
        self.text_marker.color.g = 0.0
        self.text_marker.color.b = 0.0
        self.text_marker.pose.orientation.w = 1.0
        self.text_marker.pose.position.x = 0.0
        self.text_marker.pose.position.y = -5.55
        self.text_marker.pose.position.z = 5.0
        self.text_marker.text = 'UNREACHABLE'


    
    def robot_callback(self,msg):
        self.get_logger().info('robot position: "%s" "%s"' % (msg.position.x, msg.position.y))
        self.platformx = msg.position.x
        self.platformy = msg.position.y
        if self.state == State.TILT and abs(self.platformx) <= 0.05 and abs(self.platformy) <= 0.05:
            self.get_logger().info('tilting')
            tilt = Tilt()
            tilt.angle = 1.0
            self.tilt_pub.publish(tilt)
            self.state = State.WAITING
    
    def catch_callback(self,msg):
        self.get_logger().info('Caught: "%s"' % (msg.data))
        goal_pos = PoseStamped()
        sleep(1)
        goal_pos.pose.position.x = 0.0
        goal_pos.pose.position.y = 0.0
        self.goal_pub.publish(goal_pos)
        self.state = State.TILT


    def drop_callback(self,msg):
        self.get_logger().info('Drop position: "%s" "%s" "%s"' % (msg.x, msg.y, msg.z))
        self.brick_pose.position.x = msg.x
        self.brick_pose.position.y = msg.y
        self.brick_pose.position.z = msg.z
        if self.brick_pose.position.z >self.height:
            timefall = math.sqrt((2*(self.brick_pose.position.z-self.height)/self.g))
            #calc time takes robot to move to x,y position from current position in max velocity speed (3.0 m/s)
            timerobo = math.sqrt((abs(self.brick_pose.position.x-self.platformx)-0.35)**2+(abs(self.brick_pose.position.y-self.platformy)-0.35)**2)/self.vmax
            if timerobo<=timefall:
                goal_pos = PoseStamped()
                goal_pos.pose.position.x = self.brick_pose.position.x
                goal_pos.pose.position.y = self.brick_pose.position.y
                self.goal_pub.publish(goal_pos)
            else:
                self.marker_pub.publish(self.text_marker)

        
        
        


def catcher_entry(args=None):
    rclpy.init(args=args)
    node = Catcher()
    rclpy.spin(node)
    rclpy.shutdown()