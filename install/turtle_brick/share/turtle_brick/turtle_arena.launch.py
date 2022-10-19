import os
from ament_index_python.packages import get_package_share_path, get_package_share_directory
from launch_ros.substitutions import FindPackageShare
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import Command, LaunchConfiguration, PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


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