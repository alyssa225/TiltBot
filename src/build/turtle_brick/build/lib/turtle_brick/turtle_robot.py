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
from sensor_msgs.msg import JointState
from nav_msgs.msg import Odometry 
from geometry_msgs.msg import Twist, Vector3, TransformStamped, PoseStamped
from turtlesim.msg import Pose
from visualization_msgs.msg import Marker 
from turtle_brick_interfaces.msg import Tilt 
from math import pi
#from .quaternion import angle_axis_to_quaternion

def turtle_joint():
    ##### does this need an input?
    #returns the joint state of the robot
    return JointState

def turtle_odom():
    ##### does this need an input?
    ##and how to write the return
    #returns the joint state of the robot
    return Odometry
    
def turtle_twist(xdot, ydot, omega):
    """ Create a twist suitable for a turtle

    Args:
        xdot (float) : the forward velocity
        omega (float) : the angular velocity

    Returns:
        Twist - a 2D twist object corresponding to linear/angular velocity
    """
    return Twist(linear = Vector3(x = xdot, y = ydot, z = 0.0),
                angular = Vector3(x = 0.0, y = 0.0, z = omega))

class Turtle_robot(Node):
    """ Moves some frames around

    Static Broadcasts: world -> base
    Broadcasts base -> left and base -> right
    """
    def __init__(self):
        super().__init__('turtle_robot')
        #initializing publishers
        self.joint_publisher_ = self.create_publisher(JointState,'joint_states',10)
        self.odom_pub = self.create_publisher(Odometry,'odom',10)
        self.vel_pub = self.create_publisher(Twist,'/cmd_vel',10)
        # initializing subscribers
        self.goal_sub = self.create_subscription(PoseStamped,'/goal_pose',self.pose_callback,10)
        self.tilt_sub = self.create_subscription(Tilt,'tilt',self.tilt_callback,10)
        # self.pose_sub = self.create_subscription(Pose, 'pose', self.listener_callback,10)
        # Static broadcasters publish on /tf_static.        
        self.static_broadcaster = StaticTransformBroadcaster(self)
        self.broadcaster = TransformBroadcaster(self)
        world_odom_tf = TransformStamped()
        
        world_odom_tf.header.stamp = self.get_clock().now().to_msg()
        world_odom_tf.header.frame_id = "world"
        world_odom_tf.child_frame_id = "odom"

        world_odom_tf.transform.translation.x = 0.5
        world_odom_tf.transform.translation.y = 0.50
        self.static_broadcaster.sendTransform(world_odom_tf)

        # self.odom_base_link = TransformStamped()
        # self.odom_base_link.header.frame_id = "odom"
        # self.odom_base_link.child_frame_id = "base_link"
        
	
        # The header contains the timing information and frame id
        self.dx = 10.0 # used to control frame movement
        self.dy = 0.0
        self.omega = 0.0
        # create the broadcaster
        self.broadcaster = TransformBroadcaster(self)
        # Create a timer to do the rest of the transforms
        self.tmr = self.create_timer(0.01, self.timer_callback)
    
    def pose_callback(self,msg):
        self.get_logger().info('message recieved: %f' % (msg.pose.position.x) )

    def tilt_callback(self,msg):
        self.get_logger().info('message recieved: "%s %s"' % (msg.alpha, type(msg.alpha )))


    def timer_callback(self):
        # inputing values for the the publisher
        # joint_states = turtle_joint()
        # odometry = turtle_odom()
        # twist = turtle_twist(self.dx,self.dy,self.omega)

        #publisher and broadcaster
        # self.joint_publisher_.publish(joint_states)        
        # self.odom_pub.publish(odometry)  
        # self.vel_pub.publish(twist)  
        
        odom_base_link = TransformStamped()
        odom_base_link.header.frame_id = "odom"
        odom_base_link.child_frame_id = "base_link"
        odom_base_link.transform.translation.x = -float(self.dx)        

        # don't forget to put a timestamp
        time = self.get_clock().now().to_msg()
        # world_base_link.header.stamp = time
        odom_base_link.header.stamp = time

        #broadcasting 
        # self.broadcaster.sendTransform(brick)
        self.broadcaster.sendTransform(odom_base_link)
        # self.broadcaster.sendTransform(self.odom_base_link)
        #self.broadcaster.sendTransform(world_base_tf)
        #self.broadcaster.sendTransform(base_up)
        # update the movement
        # self.dx -= 1
        # if self.dx == 0:
        #     self.dx = 10


def main(args=None):
    rclpy.init(args=args)
    turtleRobot= Turtle_robot()
    rclpy.spin(turtleRobot)
    rclpy.shutdown 


