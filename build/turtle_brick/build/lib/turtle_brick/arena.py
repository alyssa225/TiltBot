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
  
    def __init__(self):
        super().__init__('arena')
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
        self.drop = self.create_service(Drop,"drop",self.drop_callback)

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
        self.brick_marker.scale.x = 0.25
        self.brick_marker.scale.y = 0.1
        self.brick_marker.scale.z = 0.1
        self.brick_marker.color.a = 1.0
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

        #publishing wall markers
        self.marker_pub.publish(self.back_wall_marker)
        self.marker_pub.publish(self.left_wall_marker)
        self.marker_pub.publish(self.right_wall_marker)
        self.marker_pub.publish(self.front_wall_marker)
        

        #initializing brick variables
        self.brickx = 0.0
        self.bricky = 0.0
        self.brickz = 0.0 
        self.gravity = 0.0
        self.seconds = 0.0
        # # Create a timer to do the rest of the transforms
        self.tmr = self.create_timer(0.004, self.timer_callback)

    def place_callback(self, request,response):
        self.brickx = request.x
        self.bricky = request.y
        self.brickz = request.z
        self.brick_marker.color.a = 0.60
        self.world_brick.transform.translation.x = self.brickx
        self.world_brick.transform.translation.y = self.bricky 
        self.world_brick.transform.translation.z = self.brickz
        response.x = self.brickx
        response.y = self.bricky 
        response.z = self.brickz 

    def drop_callback(self, request,response):
        self.brick_state = BState.DROPPING
        self.gravity = request.g
        response.g = self.gravity

    def timer_callback(self):
        #creating the brick marker
        self.brick_marker.pose.position.x = self.brickx
        self.brick_marker.pose.position.y = self.bricky
        self.brick_marker.pose.position.z = self.brickz
        self.marker_pub.publish(self.brick_marker)
        
        
        
        #updating brick frame 
        if self.brick_state == BState.PLACED:
            self.world_brick.transform.translation.z = self.brickz
        elif self.brick_state == BState.DROPPING:
            self.world_brick.transform.translation.z = self.brickz
            self.seconds = self.seconds +0.004
            self.brickz = self.brickz-0.5*self.gravity*self.seconds^2
            if self.brickz <= 0: #change the 0 to height of platform 
                self.brickz = 0.0 
                self.brick_state = BState.SITTING
        # elif self.brick_state == BState.SITTING:
            #self.world_brick.transform.translation.x = platform.x
            #self.world_brick.transform.translation.y = platform.y
        # # don't forget to put a timestamp
        time = self.get_clock().now().to_msg()
        # base_link.header.stamp = time
        self.world_brick.header.stamp = time
        # #world_base_tf.header.stamp = time
        # #base_up.header.stamp = time
        
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

