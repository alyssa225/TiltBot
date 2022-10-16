from setuptools import find_packages
from setuptools import setup

setup(
    name='turtle_brick_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('turtle_brick_interfaces', 'turtle_brick_interfaces.*')),
)
