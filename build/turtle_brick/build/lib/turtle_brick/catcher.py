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
import rclpy
from rclpy.node import Node
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped, Pose, PoseStamped
from turtle_brick_interfaces.srv import Place, Drop
import math 
from .quaternion import angle_axis_to_quaternion
from enum import Enum, auto

class State(Enum):
    """ Current state of the brick.
    """
    WAITING = auto(),
    CATCH = auto(),
    FLOOR = auto()

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
    #     #variables
    #     self.rplatform = 0.35
    #     self.landing = 0.0
    #     self.platformx = 0.0
    #     self.platformy = 0.0
    #     self.timefall = 0.0
    #     self.timerobo = 0.0
    #     self.time = 0.0
    #     self.time2 = 0.0
    #     self.client = False
    #     #state
    #     self.state = State.WAITING
    #     #subscritions
    #     self.robot_sub = self.create_subscription(Pose,'/robot',self.robot_callback,10)
    #     #publisher
    #     self.brick_land_pub= self.create_publisher(Pose,'/land',10)
    #     self.goal_pub= self.create_publisher(PoseStamped,'/goal_pose',10)
    #     self.tilt_pub= self.create_publisher(Tilt,'/tilt',10)
    #     #pose and posestamp and tilt
    #     self.brick_pose = Pose()
    #     self.goal_pos = PoseStamped()
    #     self.tilt = Tilt()

    #     self.tmr = self.create_timer(0.004, self.timer_callback)
    #     # clients
    #     self.place_cli = self.create_client(Place,"place")
    #     self.drop_cli = self.create_client(Drop,"drop")

    
    # def robot_callback(self,msg):
    #     self.get_logger().info('message recieved: "%s" "%s" "%s"' % (msg.position.x, msg.position.y))
    #     self.landing = self.height
    #     self.platformx = msg.position.x
    #     self.platformy = msg.position.y

    # #place callback grabs x,y,z placement 
    #     #calc time takes robot to move to x,y position from current position in max velocity speed (0.22)
    #     #calc time it takes for brick to fall from placed height to platform height
    #     #if time robot < time fall --> CATCH --> pose pose to tutle robot is published to pose for arena 
    #     #if time robot > time fall --> FAIL --> publish to pose arena 0 for height and x y of place 
    # #drop callback 
    #     # if state = fail --> marker for 3 sec
    #     # if state = catch --> publish to goal pose
    # def timer_callback(self):
    #     if self.state == State.WAITING:
    #         self.client = False
    #         self.time =  0.0
    #         self.time2 = 0.0
    #         self.brick = Place.Request()
    #         #calc time it takes for brick to fall from placed height to platform height
    #         self.timefall = math.sqrt((2*(self.height-self.brick.z)/-self.g))
    #         #calc time takes robot to move to x,y position from current position in max velocity speed (3.0 m/s)
    #         self.timerobo = math.sqrt((self.brick.x-self.platformx+0.35)**2+(self.brick.y-self.platformy)**2)/self.vmax
    #         if self.timerobo<=self.timefall:
    #             self.state = State.CATCH
    #         elif self.timerobo>self.timefall:
    #             self.state = State.FLOOR
    #     if self.state == State.CATCH:
    #         if self.drop_client.wait_for_service(timeout_sec=0.004) or self.client:
    #             self.client = True
    #             self.time += 0.004
    #             self.brick_pose.position.x = self.platformx
    #             self.brick_pose.position.y = self.platformy
    #             self.brick_pose.position.z = self.height
    #             self.goal_pos.pose.position.x = self.brick.x
    #             self.goal_pos.pose.position.y = self.brick.y
    #             if self.time >= self.timefall+1.0:
    #                 self.brick.x = 0.0
    #                 self.brick.y = 0.0
    #                 if abs(self.goal_pos.pose.position.x)<= 0.05 and abs(self.goal_pos.pose.position.y)<= 0.05:
    #                     self.time2 += 0.004
    #                     #tilt.angle = 1.0
    #                     self.goal_pub.publish(self.goal_pos)
    #                     if self.time2 >= 2.0:
    #                         #wait 2 sec 
    #                         #tilt.angle = 0.0 
    #                         self.goal_pub.publish(self.goal_pos)
    #                         self.state=State.WAITING
    #     if self.state == State.FLOOR:
    #         self.brick_pose.position.x = self.brick.x
    #         self.brick_pose.position.y = self.brick.y
    #         self.brick_pose.position.z = 0.0
    #         #code for marker that says unreachable for 3 sec


    #     self.brick_land_pub.publish(self.brick_pose) 
    #     self.goal_pub.publish(self.goal_pos)


def catcher_entry(args=None):
    rclpy.init(args=args)
    node = Catcher()
    rclpy.spin(node)
    rclpy.shutdown()