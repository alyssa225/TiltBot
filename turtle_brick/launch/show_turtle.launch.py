from ament_index_python.packages import get_package_share_directory
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import Command, LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

"""
took bases from https://github.com/ros/urdf_tutorial/blob/ros2/launch/display.launch.py
launches the rviz, robot publisher, and choosen joint state publisher nodes and takes the
turtle_robot.urdf.xacro file from the urdf folder
LAUNCH ARGUMENTS:
    -use_jsp:
        default: '"gui"'
        arguments: ['"gui"', '"jsp"', '"none"']
            '"gui"': launches with joint_state_publisher_gui_node
            '"jsp"': launches with joint_state_publisher_node
            '"none"': does not use either joint state publisher
"""


def generate_launch_description():
    turtle_brick_path = 'src/turtle_brick'
    default_model_path = turtle_brick_path + '/urdf/turtle.urdf.xacro'
    default_rviz_config_path = turtle_brick_path + '/config/turtle_urdf.rviz'
    use_jsp = LaunchConfiguration('use_jsp')
    use_jsp_arg = DeclareLaunchArgument(name='use_jsp', default_value='"gui"',
                                        choices=['"gui"', '"jsp"', '"none"'],
                                        description='choose which jointstate publisher')
    model_arg = DeclareLaunchArgument(name='model', default_value=str(default_model_path),
                                      description='Absolute path to robot urdf file')
    rviz_arg = DeclareLaunchArgument(name='rvizconfig',
                                     default_value=str(default_rviz_config_path),
                                     description='Absolute path to rviz config file')

    robot_description = ParameterValue(Command(['xacro ', LaunchConfiguration('model')]),
                                       value_type=str)
    config = os.path.join(
      get_package_share_directory('turtle_brick'),
      'config',
      'turtle.yaml'
      )

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description, 'publish_frequency': 100.0}, config, ]
    )

    # Depending on gui parameter, either launch joint_state_publisher or joint_state_publisher_gui
    joint_state_publisher_node = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        condition=IfCondition(PythonExpression([use_jsp, "=='jsp'"]))
    )

    joint_state_publisher_gui_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        condition=IfCondition(PythonExpression([use_jsp, "=='gui'"]))
    )

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', LaunchConfiguration('rvizconfig')],
    )

    return LaunchDescription([
        use_jsp_arg,
        model_arg,
        rviz_arg,
        joint_state_publisher_node,
        joint_state_publisher_gui_node,
        robot_state_publisher_node,
        rviz_node
    ])
