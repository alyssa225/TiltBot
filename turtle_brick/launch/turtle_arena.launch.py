import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.substitutions import FindPackageShare
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

"""
launches arena and catcher nodes along with all the nodes in
show_turtle launch file.
Also connects to yaml files to arena and catcher node
"""


def generate_launch_description():
    runlaunch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('turtle_brick'),
                'run_turtle.launch.py'
            ])
        ])
    )
    config = os.path.join(
      get_package_share_directory('turtle_brick'),
      'config',
      'turtle.yaml'
      )

    return LaunchDescription([
        runlaunch,
        Node(
            package='turtle_brick',
            namespace='arena',
            executable='arena',
            parameters=[config]
        ),
        Node(
            package='turtle_brick',
            namespace='catcher',
            executable='catcher',
            parameters=[config]
        )
    ])
