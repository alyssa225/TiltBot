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
from rclpy.qos import QoSProfile
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

def turtle_odom():#, child_id, x,y,z,):
    
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
        #params
        # self.max_vel = self.get_parameter('max_velocity').get_parameter_value.float_value
        #initializing publishers
        qos_profile = QoSProfile(depth=10)
        self.joint_publisher_ = self.create_publisher(JointState,'joint_states',qos_profile)
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

        world_odom_tf.transform.translation.x = 0.0
        world_odom_tf.transform.translation.y = 0.0
        self.static_broadcaster.sendTransform(world_odom_tf)

	
        # The header contains the timing information and frame id
        self.currentx = 3.0 # used to control frame movement
        self.currenty = 0.0
        self.currentomega = 0.0
        # create the broadcaster
        self.broadcaster = TransformBroadcaster(self, qos=qos_profile)
        self.odom_base_link = TransformStamped()
        self.odom_base_link.header.frame_id = "odom"
        self.odom_base_link.child_frame_id = "base_link"
        self.odom_base_link.transform.translation.z = 0.6+0.15+0.25

        #joint state publisher
        self.joint_state = JointState()
        self.joint_state.header.frame_id = 'odom'
        self.wheel_ang = 1.0
        self.direction_ang = 2.0
        self.tilt_ang = -1.0
        # Create a timer to do the rest of the transforms
        self.tmr = self.create_timer(0.01, self.timer_callback)
    
    def pose_callback(self,msg):
        self.get_logger().info('message recieved: %f %f %f' % (msg.pose.position.x,msg.pose.position.y,msg.pose.orientation.z) )


    def tilt_callback(self,msg):
        self.get_logger().info('message recieved: "%s %s"' % (msg.alpha, type(msg.alpha )))


    def timer_callback(self):
        time = self.get_clock().now().to_msg()

        self.joint_state.header.stamp = self.get_clock().now().to_msg()
        self.joint_state.name = ['stem_wheel','base_stem','link_platform1']
        self.joint_state.position = [self.wheel_ang, self.direction_ang, self.tilt_ang]
        self.wheel_ang = 0.5
        self.direction_ang = -0.6
        self.tilt_ang = -0.30
        self.odom_base_link.transform.translation.x = -float(self.currentx) 
        
        self.odom_base_link.header.stamp = time
        #  inputing values for the the publisher
        # odometry = turtle_odom()
        # twist = turtle_twist(self.dx,self.dy,self.omega)

        #publisher and broadcaster
               
        # self.odom_pub.publish(odometry)  
        # self.vel_pub.publish(twist)  

        #broadcasting 
        self.joint_publisher_.publish(self.joint_state) 
        self.broadcaster.sendTransform(self.odom_base_link)
        self.currentx -= 0.01
        if self.currentx <= 0:
            self.currentx = 10
        # self.tilt_ang-=0.01
        # if self.tilt_ang <= 0:
        #     self.tilt_ang = 2

        
        

def main(args=None):
    rclpy.init(args=args)
    turtleRobot= Turtle_robot()
    rclpy.spin(turtleRobot)
    rclpy.shutdown 


