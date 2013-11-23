#include <msp430.h> 
#include "robot.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;        // Stop watchdog timer


            initializeMotor();		//set up pulse width modulation
            while(1){

            	    moveRobot(STOP);		//each movement calls a specific direction for a given time #cycles
            	    _delay_cycles(2000000);

                    moveRobot(BACKWARD);	//movements will loop until robot is turned off while(1)
                    _delay_cycles(2000000);

                    moveRobot(STOP);
                    _delay_cycles(2000000);

                    moveRobot(FORWARD);
                    _delay_cycles(2000000);

                    moveRobot(STOP);
                    _delay_cycles(2000000);

                    moveRobot(BIGRIGHT);
                    _delay_cycles(2000000);

                    moveRobot(STOP);
                    _delay_cycles(2000000);

                    moveRobot(BIGLEFT);
                    _delay_cycles(2000000);

                    moveRobot(STOP);
                    _delay_cycles(2000000);

                    moveRobot(SMALLRIGHT);
                    _delay_cycles(2000000);

                    moveRobot(STOP);
                    _delay_cycles(2000000);

                    moveRobot(SMALLLEFT);
                    _delay_cycles(2000000);

                    moveRobot(FORWARD);
                    _delay_cycles(2000000);
            }

}


