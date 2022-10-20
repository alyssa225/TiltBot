"""
uupdate

"""
from tokenize import Double, String
import rclpy
from rclpy.node import Node
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from tf2_ros import TransformBroadcaster
from sensor_msgs.msg import JointState
from rclpy.qos import QoSProfile
from nav_msgs.msg import Odometry 
from geometry_msgs.msg import Twist, Vector3, TransformStamped, PoseStamped, Pose
from visualization_msgs.msg import Marker 
from turtle_brick_interfaces.msg import Tilt 
import math 
#from .quaternion import angle_axis_to_quaternion

class Turtle_robot(Node):
    """ update
    """
    def __init__(self):
        super().__init__('turtle_robot')
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

        # initializing publishers
        qos_profile = QoSProfile(depth=10)
        self.joint_publisher_ = self.create_publisher(JointState,'/joint_states',qos_profile)
        self.odom_pub = self.create_publisher(Odometry,'/odom',10)
        self.vel_pub = self.create_publisher(Twist,'/cmd_vel',10)
        self.robot_pub = self.create_publisher(Pose,'/robot',10)
        # initializing subscribers
        self.goal_sub = self.create_subscription(PoseStamped,'/goal_pose',self.pose_callback,10)
        self.tilt_sub = self.create_subscription(Tilt,'/tilt',self.tilt_callback,10)
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

        #positions 
        self.currentx = 0.0 
        self.currenty = 0.0
        self.currentomega = 0.0
        self.goalx = 0.0
        self.goaly = 0.0
        self.distx = 0.0
        self.disty = 0.0
        # velocity
        self.vx = 0.0
        self.vy = 0.0
        self.dx = 0.0
        self.dy = 0.0
        # create the broadcaster
        self.broadcaster = TransformBroadcaster(self, qos=qos_profile)
        self.odom_base_link = TransformStamped()
        self.odom_base_link.header.frame_id = "odom"
        self.odom_base_link.child_frame_id = "base_link"
        self.odom_base_link.transform.translation.z = 2*self.rwheel+0.15+0.25

        #joint state publisher
        self.joint_state = JointState()
        self.joint_state.header.frame_id = 'base_link'
        self.wheel_ang = 0.0
        self.direction_ang = 0.0
        self.tilt_ang = 0.0
        self.tilt_angf= 0.0

        # odommetry publisher
        self.odom = Odometry()
        self.odom.header.frame_id = "odom"
        self.odom.child_frame_id = "base_link"

        #cmd_vel publisher
        self.twist = Twist()

        #create pose publisher
        self.robo_pose = Pose()

        # Create a timer to do movements
        self.freq = 100.0
        self.period = 1/self.freq
        self.tmr = self.create_timer(self.period, self.timer_callback)
    
    def pose_callback(self,msg):
        self.get_logger().info('goal pose: %f %f %f' % (msg.pose.position.x,msg.pose.position.y,msg.pose.orientation.z) )
        self.goalx = msg.pose.position.x
        self.goaly = msg.pose.position.y
        dx = self.goalx - self.currentx
        dy = self.goaly - self.currenty
        d = math.sqrt(dx**2 + dy**2)
        self.vx = dx / d * self.vmax
        self.vy = dy / d * self.vmax
        self.get_logger().info('distx: "%f"' % dx)
        self.get_logger().info('disty: "%f"' % dy)
        self.dx = self.vx*self.period
        self.dy = self.vy*self.period

    def tilt_callback(self,msg):
        self.get_logger().info('tilt angle: "%s"' % (msg.angle))
        self.tilt_angf = msg.angle

    def timer_callback(self):
        time = self.get_clock().now().to_msg()
        
        #update odom
        self.odom.header.stamp = self.get_clock().now().to_msg()
        self.odom.pose.pose.position.x = self.currentx
        self.odom.pose.pose.position.y = self.currenty
        self.odom.twist.twist.linear.x = self.vx
        self.odom.twist.twist.linear.y = self.vy

        
        #updating joint states
        self.joint_state.header.stamp = self.get_clock().now().to_msg()
        self.joint_state.name = ['stem_wheel','base_stem','link_platform1']
        self.joint_state.position = [self.wheel_ang, self.direction_ang, self.tilt_ang]
        
        #update twist
        self.twist.linear.x = self.vx
        self.twist.linear.y = self.vy
        
        #update robot pose
        self.robo_pose.position.x=self.currentx
        self.robo_pose.position.y=self.currenty
        self.robo_pose.position.z=self.height
        self.robo_pose.orientation.w = self.tilt_ang

        #update transforms
        self.odom_base_link.transform.translation.x = self.currentx 
        self.odom_base_link.transform.translation.y = self.currenty 
        self.odom_base_link.header.stamp = time 

        #broadcasting and publishing
        self.joint_publisher_.publish(self.joint_state) 
        self.odom_pub.publish(self.odom)
        self.vel_pub.publish(self.twist)
        self.robot_pub.publish(self.robo_pose)
        self.broadcaster.sendTransform(self.odom_base_link)
        #moving the robot to goal pose
        self.currentx += self.dx
        self.currenty += self.dy
        if abs(self.currentx-self.goalx) <= 0.05:
            self.vx = 0.0
            self.dx = 0.0
        if abs(self.currenty-self.goaly)<= 0.05:
            self.vy = 0.0
            self.dy = 0.0
        
        #move the wheel and stem to face direction and roll
        #tilt if tilt is called
        if self.tilt_ang != 0.0 or self.tilt_angf != 0.0:
            if abs(self.tilt_ang-self.tilt_angf) >=0.01:       
                if self.tilt_angf-self.tilt_ang < 0.0:
                    self.tilt_ang-=0.005
                elif self.tilt_angf-self.tilt_ang >= 0.0:
                    self.tilt_ang+=0.005
            elif self.tilt_angf == 0.0:
                self.tilt_ang = 0.0
            else:
                self.tilt_angf = 0.0
        
        

def main(args=None):
    rclpy.init(args=args)
    turtleRobot= Turtle_robot()
    rclpy.spin(turtleRobot)
    rclpy.shutdown 


