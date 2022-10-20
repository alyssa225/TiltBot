import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.substitutions import FindPackageShare
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

"""
launches turtlesim and turtle_robot node along with all the nodes in
show_turtle launch file. Also connects yaml file to turtle_robot
"""


def generate_launch_description():
    showlaunch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('turtle_brick'),
                'show_turtle.launch.py'
            ])
        ])
    )
    config = os.path.join(
      get_package_share_directory('turtle_brick'),
      'config',
      'turtle.yaml'
      )

    return LaunchDescription([
        showlaunch,
        Node(
            package='turtlesim',
            namespace='turtlesim1',
            executable='turtlesim_node',
            parameters=[{'holonomic': "True"}]
        ),
        Node(
            package='turtle_brick',
            namespace='turtle_robot',
            executable='turtle_robot',
            remappings=[('/cmd_vel', '/turtlesim1/turtle1/cmd_vel'), ],
            parameters=[config]
        )
    ])
