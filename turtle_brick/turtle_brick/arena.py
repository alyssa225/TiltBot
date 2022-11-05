import rclpy
# import rospy
from rclpy.node import Node
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped, Pose, Vector3
from std_srvs.srv import Empty
from turtle_brick_interfaces.srv import Place
from visualization_msgs.msg import Marker
from builtin_interfaces.msg import Duration
from std_msgs.msg import Bool
import math
from enum import Enum, auto


class BState(Enum):
    """
    Current state of the brick.

    Four states of brick.
        - PLACED: brick is placed
        - DROPPING: brick is dropping with accelleraction od gravity
        - PLATFORM: The platfom of turtle robot is below the brick
        - FLOOR: The turtle robot is not below the brick

    """

    PLACED = auto(),
    DROPPING = auto(),
    PLATFORM = auto(),
    FLOOR = auto()


class Arena(Node):
    """
    Creates the arena and places brick when called in command line.

    Will drop the robot when called in command line.
        -if robot is underneath the brick, the brick will land on the robot
        -if nothing is under brick, brick will land on ground

    SUBSCRIPTIONS:
        -robot_sub: continuous robot position
    PUBLISHERS:
        -marker_pub: publishes walls and brick
        -drop_pub: sends placement, drop coordinates
        -platform_pub: sends true if platform is under brick
    SERVICES:
        -Place: place brick at x, y, z location
        -Drop: Empty drops brick
    TRANSFORMS:
        -world_brick: connects brick to world

    """

    def __init__(self):
        super().__init__('arena')
        # params
        self.declare_parameters(
            namespace='',
            parameters=[
                ('platform_height', 1.7),
                ('wheel_radius', 0.3),
                ('max_velocity', 3.0),
                ('gravity', 9.8)
            ]
        )
        self.height = self.get_parameter("platform_height").get_parameter_value().double_value
        self.rwheel = self.get_parameter("wheel_radius").get_parameter_value().double_value
        self.vmax = self.get_parameter("max_velocity").get_parameter_value().double_value
        self.g = self.get_parameter("gravity").get_parameter_value().double_value
        # setting state of brick
        self.brick_state = BState.PLACED
        # variables
        self.platformz = 0.0
        self.platformx = 0.0
        self.platformy = 0.0
        self.tilt_ang = 0
        # set up subscribers
        self.robot_sub = self.create_subscription(Pose, '/robot', self.robot_callback, 10)
        # publisher
        self.marker_pub = self.create_publisher(Marker, '/marker', 10)
        self.drop_pub = self.create_publisher(Vector3, '/drop', 10)
        self.platform_pub = self.create_publisher(Bool, '/catch', 10)
        # set up brick to world transforms and broadcaster
        self.static_broadcaster = TransformBroadcaster(self)
        # create the broadcaster
        self.broadcaster = TransformBroadcaster(self)
        # initialize services
        self.place = self.create_service(Place, "/place", self.place_callback)
        self.drop = self.create_service(Empty, "/drop", self.drop_callback)
        # creating brick marker
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
        # creating left wall marker
        self.left_wall_marker = Marker()
        self.left_wall_marker.header.frame_id = "world"
        self.left_wall_marker.header.stamp = self.get_clock().now().to_msg()
        self.left_wall_marker.ns = "left_wall"
        self.left_wall_marker.id = 1
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
        # creating right wall marker
        self.right_wall_marker = Marker()
        self.right_wall_marker.header.frame_id = "world"
        self.right_wall_marker.header.stamp = self.get_clock().now().to_msg()
        self.right_wall_marker.ns = "right_wall"
        self.right_wall_marker.id = 2
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
        # creating front wall marker
        self.front_wall_marker = Marker()
        self.front_wall_marker.header.frame_id = "world"
        self.front_wall_marker.header.stamp = self.get_clock().now().to_msg()
        self.front_wall_marker.ns = "front_wall"
        self.front_wall_marker.id = 3
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
        # creating back wall marker
        self.back_wall_marker = Marker()
        self.back_wall_marker.header.frame_id = "world"
        self.back_wall_marker.header.stamp = self.get_clock().now().to_msg()
        self.back_wall_marker.ns = "back_wall"
        self.back_wall_marker.id = 4
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
        # initializing brick variables
        self.brickx = 0.0
        self.bricky = 0.0
        self.brickz = 0.0
        self.brickxplace = 0.0
        self.brickyplace = 0.0
        self.brickzplace = 0.0
        self.gravity = 0.0
        self.seconds = 0.0
        # Create a timer to do the actions
        self.freq = 250.0
        self.period = 1/self.freq
        self.tmr = self.create_timer(self.period, self.timer_callback)
        self.walls_published = False
        self.wall = self.create_timer(0.5, self.wall_callback)

    def place_callback(self, request, response):
        self.place_brick(request.x, request.y, request.z)
        response.msg = 'placed'
        return response

    def robot_callback(self, msg):
        # self.get_logger().info('robot position: "%s" "%s"' % (msg.position.x, msg.position.y))
        self.platformz = self.height
        self.platformx = msg.position.x
        self.platformy = msg.position.y
        tilt_ang = msg.orientation.w
        if self.brick_state == BState.PLATFORM:
            if tilt_ang >= 0.5:
                self.brick_state = BState.PLACED
                self.set_brick(self.brickxplace, self.brickyplace, self.brickzplace)
            else:
                self.set_brick(self.platformx, self.platformy, self.platformz)

    def drop_callback(self, request, response):
        drop = Vector3()
        drop.x = self.brickx
        drop.y = self.bricky
        drop.z = self.brickz
        self.drop_pub.publish(drop)
        self.seconds = 0.0
        self.brick_state = BState.DROPPING
        return response

    def wall_callback(self):
        # publishing wall markers
        self.marker_pub.publish(self.left_wall_marker)
        self.marker_pub.publish(self.right_wall_marker)
        self.marker_pub.publish(self.front_wall_marker)
        self.marker_pub.publish(self.back_wall_marker)

    def publish_brick(self):
        world_brick = TransformStamped()
        time = self.get_clock().now().to_msg()
        world_brick.header.stamp = time
        world_brick.header.frame_id = "world"
        world_brick.child_frame_id = "brick"
        world_brick.transform.translation.x = self.brickx
        world_brick.transform.translation.y = self.bricky
        world_brick.transform.translation.z = self.brickz
        self.brick_marker.pose.position.x = self.brickx
        self.brick_marker.pose.position.y = self.bricky
        self.brick_marker.pose.position.z = self.brickz + 0.1
        self.marker_pub.publish(self.brick_marker)
        self.broadcaster.sendTransform(world_brick)

    def set_brick(self, x, y, z):
        self.brickx = x
        self.bricky = y
        self.brickz = z
        self.publish_brick()

    def place_brick(self, x, y, z):
        self.brickxplace = x
        self.brickyplace = y
        self.brickzplace = z
        self.brick_state = BState.PLACED
        self.brick_marker.color.a = 1.0
        self.set_brick(x, y, z)

    def timer_callback(self):
        if self.brick_state == BState.DROPPING:
            self.seconds = self.seconds + 0.004
            self.brickz = self.brickz - 0.5 * self.g * self.seconds**2
            if self.brickz <= 0.0:
                self.brickz = 0.0
                self.brick_state = BState.FLOOR
            else:
                bd = math.sqrt((self.brickx-self.platformx)**2 + (self.bricky-self.platformy)**2)
                if bd <= 0.35 and self.brickz <= self.height:
                    msg = Bool()
                    msg.data = True
                    self.platform_pub.publish(msg)
                    self.brick_state = BState.PLATFORM

            self.publish_brick()


def arena_entry(args=None):
    rclpy.init(args=args)
    node = Arena()
    rclpy.spin(node)
    rclpy.shutdown
