import os
from glob import glob
from setuptools import setup, find_packages

package_name = 'turtle_brick'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml', 'launch/show_turtle.launch.py', 'config/turtle_urdf.rviz', 'launch/run_turtle.launch.py', 'launch/turtle_arena.launch.py']),
        (os.path.join('share', package_name), glob('urdf/*')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml'))
    ],
    install_requires=['setuptools', 'urdf','rviz'],
    zip_safe=True,
    maintainer='alyssa',
    maintainer_email='alyssachen2022@u.northwestern.edu',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest','ament_lint_auto'],
    entry_points={
        'console_scripts': [
            'turtle_robot = turtle_brick.turtle_robot:main',
            'arena = turtle_brick.arena:arena_entry',
            'catcher = turtle_brick.catcher:catcher_entry'
        ],
    },
)
