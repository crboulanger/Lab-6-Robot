Lab-6-Robot
===========

This is my repository for my moving robot libraries

Welcome!

Navigate to the final robot motion library:
desktop/Engineering_3/382/Robot2

This repository is host to robot libraries which implement 8 directional commands:

- STOP
- FORWARD
- BACKWARD
- BIGRIGHT (>45 degrees)
- SMALLRIGHT (<45 degrees)
- BIGLEFT (>45 degrees)
- SMALLLEFT (>45 degrees)

All of these commands are defined in robot.h and implemented in robot.c.

To change the robot's path, follow the following template in main.c while loop:

- Choose a directional command
- Call it using "moveRobot('insert directional command')"
- Assign time length to execute "_delay_cycles('# of cycles')"
-- Remember frequency is about 1 MHz. 1,000,000 cyles is apprx. 1 second.
- Move on to next directional command
- Robot is designed to loop the programmed path.

The provided code is pre-programmed for a robot to demonstrate all of the commands.
The robot will go backward, forward, big right, big left, small right, small left, and forward again while stopping between each command.


