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
import rclpy
# import rospy
from rclpy.node import Node
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
from std_srvs.srv import Empty
from math import pi
from turtle_brick_interfaces.srv import Place, Drop
from visualization_msgs.msg import Marker 
from builtin_interfaces.msg import Duration
from visualization_msgs.msg import MarkerArray
import math
from enum import Enum, auto
#from .quaternion import angle_axis_to_quaternion

# make states for the brick drop (PLACED, DROPPING, SITTING)
class BState(Enum):
    """ Current state of the brick.
    """
    PLACED = auto(),
    DROPPING = auto(),
    SITTING = auto()

class Arena(Node):
    """
    add what node does
    """
    def __init__(self):
        super().__init__('arena')
        #params
        self.declare_parameters( 
            namespace='',
            parameters=[
                ('platform_height', 0.0),
                ('wheel_radius', 0.0),
                ('max_velocity',0.0),
                ('gravity',0.0)
            ]
        )
        self.height = self.get_parameter("platform_height").get_parameter_value().double_value
        self.rwheel = self.get_parameter("wheel_radius").get_parameter_value().double_value
        self.vmax = self.get_parameter("max_velocity").get_parameter_value().double_value
        self.g = self.get_parameter("gravity").get_parameter_value().double_value
        #setting state of brick
        self.brick_state = BState.PLACED
        # set up brick to world transforms and broadcaster
        self.static_broadcaster = TransformBroadcaster(self)
        self.world_brick = TransformStamped()
        self.world_brick.header.frame_id = "world"
        self.world_brick.child_frame_id = "brick"
        # # create the broadcaster
        self.broadcaster = TransformBroadcaster(self)
        
        #initialize services
        self.place = self.create_service(Place,"place",self.place_callback)
        self.drop = self.create_service(Empty,"drop",self.drop_callback)

        # publisher = rclpy.Publisher(topic, MarkerArray,10)
        self.marker_pub = self.create_publisher(Marker,'marker',10)
        # self.left_wall_pub = self.create_publisher(Marker,'marker',10)
        # self.right_wall_pub = self.create_publisher(Marker,'marker',10)
        # self.front_wall_pub = self.create_publisher(Marker,'marker',10)
        # self.back_wall_pub = self.create_publisher(Marker,'marker',10)
        # brick_marker = Marker()

        count = 0
        # MARKERS_MAX = 100

        #creating brick marker
        self.brick_marker = Marker()
        self.brick_marker.header.frame_id = "world"
        self.brick_marker.header.stamp = self.get_clock().now().to_msg()
        self.brick_marker.ns = "brick"
        self.brick_marker.id = 0
        self.brick_marker.type = Marker.CUBE
        self.brick_marker.action = Marker.ADD
        self.brick_marker.scale.x = 0.3
        self.brick_marker.scale.y = 0.2
        self.brick_marker.scale.z = 0.2
        self.brick_marker.color.a = 0.0
        self.brick_marker.color.r = 0.6
        self.brick_marker.color.g = 0.3
        self.brick_marker.color.b = 0.3
        self.brick_marker.pose.orientation.w = 1.0

        #creating wall markers
        self.left_wall_marker = Marker()
        self.left_wall_marker.header.frame_id = "world"
        self.left_wall_marker.header.stamp = self.get_clock().now().to_msg()
        self.left_wall_marker.ns = "left_wall"
        self.left_wall_marker.id = 1
        # self.left_wall_marker.lifetime.sec = 0
        # self.left_wall_marker.lifetime.nanosec = 0
        self.left_wall_marker.lifetime = Duration()
        self.left_wall_marker.type = Marker.CUBE
        self.left_wall_marker.action = Marker.ADD
        self.left_wall_marker.scale.x = 0.1
        self.left_wall_marker.scale.y = 11.0
        self.left_wall_marker.scale.z = 2.0
        self.left_wall_marker.color.a = 1.0
        self.left_wall_marker.color.r = 0.3
        self.left_wall_marker.color.g = 0.3
        self.left_wall_marker.color.b = 1.0
        self.left_wall_marker.pose.orientation.w = 1.0
        self.left_wall_marker.pose.position.x = -5.55
        self.left_wall_marker.pose.position.y = 0.0
        self.left_wall_marker.pose.position.z = 1.0
        self.left_wall_marker.frame_locked = True

        self.right_wall_marker = Marker()
        self.right_wall_marker.header.frame_id = "world"
        self.right_wall_marker.header.stamp = self.get_clock().now().to_msg()
        self.right_wall_marker.ns = "right_wall"
        self.right_wall_marker.id = 2
        # self.right_wall_marker.lifetime.sec = 0
        # self.right_wall_marker.lifetime.nanosec = 0
        self.right_wall_marker.lifetime = Duration()
        self.right_wall_marker.type = Marker.CUBE
        self.right_wall_marker.action = Marker.ADD
        self.right_wall_marker.scale.x = 0.1
        self.right_wall_marker.scale.y = 11.0
        self.right_wall_marker.scale.z = 2.0
        self.right_wall_marker.color.a = 1.0
        self.right_wall_marker.color.r = 0.3
        self.right_wall_marker.color.g = 0.3
        self.right_wall_marker.color.b = 1.0
        self.right_wall_marker.pose.orientation.w = 1.0
        self.right_wall_marker.pose.position.x = 5.55
        self.right_wall_marker.pose.position.y = 0.0
        self.right_wall_marker.pose.position.z = 1.0
        self.right_wall_marker.frame_locked = True

        self.front_wall_marker = Marker()
        self.front_wall_marker.header.frame_id = "world"
        self.front_wall_marker.header.stamp = self.get_clock().now().to_msg()
        self.front_wall_marker.ns = "front_wall"
        self.front_wall_marker.id = 3
        # self.front_wall_marker.lifetime.sec = 0
        # self.front_wall_marker.lifetime.nanosec = 0
        self.front_wall_marker.lifetime = Duration()
        self.front_wall_marker.type = Marker.CUBE
        self.front_wall_marker.action = Marker.ADD
        self.front_wall_marker.scale.x = 11.0
        self.front_wall_marker.scale.y = 0.1
        self.front_wall_marker.scale.z = 2.0
        self.front_wall_marker.color.a = 1.0
        self.front_wall_marker.color.r = 0.3
        self.front_wall_marker.color.g = 0.3
        self.front_wall_marker.color.b = 1.0
        self.front_wall_marker.pose.orientation.w = 1.0
        self.front_wall_marker.pose.position.x = 0.0
        self.front_wall_marker.pose.position.y = 5.55
        self.front_wall_marker.pose.position.z = 1.0
        self.front_wall_marker.frame_locked = True

        self.back_wall_marker = Marker()
        self.back_wall_marker.header.frame_id = "world"
        self.back_wall_marker.header.stamp = self.get_clock().now().to_msg()
        self.back_wall_marker.ns = "back_wall"
        self.back_wall_marker.id = 4
        # self.back_wall_marker.lifetime.sec = 0
        # self.back_wall_marker.lifetime.nanosec = 0
        self.back_wall_marker.lifetime = Duration()
        self.back_wall_marker.type = Marker.CUBE
        self.back_wall_marker.action = Marker.ADD
        self.back_wall_marker.scale.x = 11.0
        self.back_wall_marker.scale.y = 0.1
        self.back_wall_marker.scale.z = 2.0
        self.back_wall_marker.color.a = 1.0
        self.back_wall_marker.color.r = 0.3
        self.back_wall_marker.color.g = 0.3
        self.back_wall_marker.color.b = 1.0
        self.back_wall_marker.pose.orientation.w = 1.0
        self.back_wall_marker.pose.position.x = 0.0
        self.back_wall_marker.pose.position.y = -5.55
        self.back_wall_marker.pose.position.z = 1.0
        self.back_wall_marker.frame_locked = True


        #initializing brick variables
        self.brickx = 0.0
        self.bricky = 0.0
        self.brickz = 0.0 
        self.gravity = 0.0
        self.seconds = 0.0
        # # Create a timer to do the actions
        self.freq = 250.0
        self.period = 1/self.freq
        self.tmr = self.create_timer(self.period, self.timer_callback)

    def place_callback(self, request,response):
        self.brickx = request.x
        self.bricky = request.y
        self.brickz = request.z
        self.brick_marker.pose.position.x = self.brickx
        self.brick_marker.pose.position.y = self.bricky
        self.brick_marker.pose.position.z = self.brickz 
        self.brick_marker.color.a = 0.60
        response.msg = 'placed'
        return response

    def drop_callback(self, request,response):
        self.brick_state = BState.DROPPING
        return response

    def timer_callback(self):
        #creating the brick marker
        self.marker_pub.publish(self.brick_marker)
        
        #publishing wall markers
        self.marker_pub.publish(self.left_wall_marker)
        self.marker_pub.publish(self.right_wall_marker)
        self.marker_pub.publish(self.front_wall_marker)
        self.marker_pub.publish(self.back_wall_marker)

        #update transform
        self.world_brick.transform.translation.x = self.brickx
        self.world_brick.transform.translation.y = self.bricky 
        

        #updating brick frame 
        if self.brick_state == BState.PLACED:
            self.world_brick.transform.translation.z = self.brickz
        elif self.brick_state == BState.DROPPING:
            self.world_brick.transform.translation.z = self.brickz
            self.seconds = self.seconds +0.004
            self.brickz = self.brickz-0.5*self.g*self.seconds**2 #has to grab gravity this from yaml
            if self.brickz <= 0.05: #change the 0 to height of platform or 
                self.brickz = 0.05 
                self.sec = 0.0
                self.brick_state = BState.SITTING
        # elif self.brick_state == BState.SITTING:
            #self.world_brick.transform.translation.x = platform.x
            #self.world_brick.transform.translation.y = platform.y
            #if tilt subscriber not = 0.0 

        time = self.get_clock().now().to_msg()
        self.world_brick.header.stamp = time

        
        self.broadcaster.sendTransform(self.world_brick)
        # self.broadcaster.sendTransform(base_link)
        # #self.broadcaster.sendTransform(world_base_tf)
        # #self.broadcaster.sendTransform(base_up)
        # # update the movement
        # self.dx -= 1


def arena_entry(args=None):
    rclpy.init(args=args)
    node= Arena()
    rclpy.spin(node)
    rclpy.shutdown 

