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
from rclpy.node import Node
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
from math import pi
#from .quaternion import angle_axis_to_quaternion


class Arena(Node):
    """ Moves some frames around

    Static Broadcasts: world -> base
    Broadcasts base -> left and base -> right
    """
    def __init__(self):
        super().__init__('arena')
        # Static broadcasters publish on /tf_static. We will only need to publish this once
        self.static_broadcaster = StaticTransformBroadcaster(self)
        # world_odom_tf = TransformStamped()
        
        # world_odom_tf.header.stamp = self.get_clock().now().to_msg()
        # world_odom_tf.header.frame_id = "world"
        # world_odom_tf.child_frame_id = "odom"

        # # The base frame will be raised in the z direction by 1 meter
        # # and be aligned with world We are relying on the default values
        # # of the transform message (which defaults to no rotation)
        # world_odom_tf.transform.translation.x = 0.5
        # world_odom_tf.transform.translation.y = 0.50
        # self.static_broadcaster.sendTransform(world_odom_tf)
	
        # # Now create the transform, noted that it must have a parent frame and a timestamp
        # # The header contains the timing information and frame id
        # self.dx = 10  # used to control frame movement
        # # create the broadcaster
        # self.broadcaster = TransformBroadcaster(self)
        # # Create a timer to do the rest of the transforms
        # self.tmr = self.create_timer(1, self.timer_callback)

    def timer_callback(self):
        
        brick = TransformStamped()
        brick.header.frame_id = "world"
        brick.child_frame_id = "brick"
        
        
        # base_link = TransformStamped()
        # base_link.header.frame_id = "world"
        # base_link.child_frame_id = "base_link"
        
    	# # get a quaternion corresponding to a rotation by theta about an axis
        # #degrees = 36 * self.dx
        # #radians = degrees * pi / 180.0
        # #base_left.transform.rotation = angle_axis_to_quaternion(radians, [0, 0, 1.0])


        # # don't forget to put a timestamp
        time = self.get_clock().now().to_msg()
        # base_link.header.stamp = time
        brick.header.stamp = time
        # #world_base_tf.header.stamp = time
        # #base_up.header.stamp = time
        
        self.broadcaster.sendTransform(brick)
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

