/*
 * robot.h
 *
 *  Created on: Nov 15, 2013
 *      Author: C15Christopher.Boula
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#define STOP                1
#define FORWARD             2
#define BACKWARD        	3
#define BIGRIGHT      		4
#define SMALLRIGHT          5
#define BIGLEFT             7
#define SMALLLEFT           8

void initializeMotor();

void moveRobot(unsigned char direction);

#endif /* ROBOT_H_ */
