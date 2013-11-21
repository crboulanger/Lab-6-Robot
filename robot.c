/*
 * robot.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Christopher.Boula
 */
#include "robot.h"
#include <msp430.h>

void initializeMotor(){
		P1DIR |= BIT2;
		P1SEL |= BIT2;
		P2DIR |= BIT1|BIT4;
		P2SEL |= BIT1|BIT4;

		TA0CTL &= ~MC1|MC0;			// stop timer A0
		TA1CTL &= ~MC1|MC0;

		TA0CTL |= TACLR;			// clear timer A0
		TA1CTL |= TACLR;

		TA0CTL |= TASSEL1;			// configure for SMCLK
		TA1CTL |= TASSEL1;

		TA1CCR0 = 100;
		TA0CCR0 = 100;

		TA0CCR1 = 75;
		TA1CCR1 = 75;
		TA1CCR2 = 0;

		TA0CCTL1 |= OUTMOD_7;		// set to RESET/SET mode
		TA1CCTL1 |= OUTMOD_7;

		TA0CTL |= MC0;				// set to count up
		TA1CTL |= MC0;
}


void moveRobot(unsigned char direction){
	switch (direction){

	case STOP:
		TA1CCR1 = 0;
		TA0CCR1 = 0;
		TA1CCR2 = 0;
		break;

	case FORWARD:
		TA0CCR1 = 75;
		TA1CCR1 = 75;
		TA1CCR2 = 0;
		break;

	case BACKWARD:
		TA1CCR1 = 0;
		TA0CCR1 = 0;
		TA1CCR2 = 45;
		break;

	case BIGRIGHT:
		TA1CCR1 = 75;
		TA0CCR1 = 0;
		TA1CCR2 = 0;
		_delay_cycles(400000);
		TA0CCR1 = 75;
		break;

	case SMALLRIGHT:
		TA1CCR1 = 75;
		TA0CCR1 = 0;
		TA1CCR2 = 0;
		_delay_cycles(200000);
		TA0CCR1 = 75;
		break;

	case BIGLEFT:
		TA0CCR1 = 75;
		TA1CCR1 = 0;
		TA1CCR2 = 0;
		_delay_cycles(400000);
		TA1CCR1 = 75;
		break;

	case SMALLLEFT:
		TA0CCR1 = 75;
		TA1CCR1 = 0;
		TA1CCR2 = 0;
		_delay_cycles(200000);
		TA1CCR1 = 75;
		break;
	}
}




