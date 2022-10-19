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
from .quaternion import angle_axis_to_quaternion

#states
#WAIT
#FAIL
#CATCH
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
        #client to place topic and place callback
        #client to drop topic and drop callback
        #publish to goal_pose
        self.tmr = self.create_timer(1, self.timer_callback)
    
    #place callback grabs x,y,z placement 
        #calc time takes robot to move to x,y position from current position in max velocity speed (0.22)
        #calc time it takes for brick to fall from placed height to platform height
        #if time robot < time fall --> CATCH
        #if time robot > time fall --> FAIL
    #drop callback 
        # if state = fail --> marker for 3 sec
        # if state = catch 
    def timer_callback(self):
        
        # update the movement
        self.dx -= 1
        if self.dx == 0:
            self.dx = 10


def catcher_entry(args=None):
    rclpy.init(args=args)
    node = Catcher()
    rclpy.spin(node)
    rclpy.shutdown()