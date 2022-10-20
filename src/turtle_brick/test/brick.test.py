# from ament_copyright.main import main
# import pytest
# import launch
# import launch_pytest
# import sys
# import launch_ros
# from pathlib import Path
# found this example here
# https://github.com/ros2/launch/blob/humble/launch_pytest/test/launch_pytest/examples/check_node_msgs.py

# def generate_test_description():
#     path_to_test = Path(__file__).parent

#     return launch.LaunchDescription([
#         launch_ros.actions.Node(
#             executable=sys.executable,
#             arguments=[str(path_to_test / 'executables' / 'talker.py')],
#             additional_env={'PYTHONUNBUFFERED': '1'},
#             name='demo_node_1',
#             output='screen',
#         ),
#     ])
