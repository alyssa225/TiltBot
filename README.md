#ME495 Embedded Systems Homework 2
Author: Alyssa Chen

The package creates a turtle robot and arena in rviz that is connected to turtlesim. You can call a place service that will place a brick in the arena and any x, y, z location. When you call to drop the brick, the turtle robot will determine if it can catch the brick before it hits the ground. If it can, the robot will drive over on rviz and turtlesim and catch the brick. It will then return to the center and tilt the brick off it's platform. If it cannot catch the brick, the screen will tell you that it is "UNREACHABLE".

## Quickstart
1. Use `ros2 launch turtle_brick turtle_arena.launch.py use_jsp:='"none"'` to start the arena and turtle simulation
2. Use `ros2 service call drop std_srvs/srv/Empty` to drop a brick
3. Here is a video of the turtle when the brick is within catching range

[196850920-de1b0534-6ec8-48c1-9517-31d77fb2c711.webm](https://github.com/alyssa225/TiltBot/assets/81643108/baf6cb7f-33d4-4384-875c-374c2177ea6a)

5. Here is a video of the turtle when the brick cannot be caught

[196851138-7a033f9c-516c-414e-a1e4-d0c1c826d026.webm](https://github.com/alyssa225/TiltBot/assets/81643108/ad67e0c9-a4a7-4458-be41-c6bfe43f095c)

Worked With: ${Vaish}
