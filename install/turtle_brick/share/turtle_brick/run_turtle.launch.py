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
            name='sim',
            parameters=[config]
        )
        
    ])