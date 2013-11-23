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

                TA0CTL &= ~MC1|MC0;                        // stop timer A0
                TA1CTL &= ~MC1|MC0;

                TA0CTL |= TACLR;                        // clear timer A0
                TA1CTL |= TACLR;

                TA0CTL |= TASSEL1;                        // configure for SMCLK
                TA1CTL |= TASSEL1;

                TA1CCR0 = 100;
                TA0CCR0 = 100;

                TA0CCR1 = 55;
                TA1CCR1 = 60;
                TA1CCR2 = 65;

                TA0CCTL1 |= OUTMOD_7;                // set to RESET/SET mode
                TA1CCTL1 |= OUTMOD_7;

                TA0CTL |= MC0;                                // set to count up
                TA1CTL |= MC0;
}


void moveRobot(unsigned char direction){
        switch (direction){

        case STOP:
        		P1DIR |= BIT2;	//I reset the bits each time because backwards requires a different bit set configuration
        	    P1SEL |= BIT2;
        	    P2DIR |= BIT1|BIT4;
        	    P2SEL |= BIT1|BIT4;

        	    TA1CCR1 = 0;	//no duty cycle>>no movement
                TA0CCR1 = 0;
                TA1CCR2 = 0;
                break;

        case FORWARD:
        		P1DIR |= BIT2;
        	    P1SEL |= BIT2;
        	    P2DIR |= BIT1|BIT4;
        	    P2SEL |= BIT1|BIT4;

                TA0CCR1 = 60;
                TA1CCR1 = 55;
                TA1CCR2 = 0;
                break;

        case BACKWARD:
        	    P2DIR &= ~BIT4;
        	    P2SEL &= ~BIT4;

        	    TA1CCR1 = 0;
                TA0CCR1 = 0;
                TA1CCR2 = 65;
                break;

        case BIGRIGHT:
        		P1DIR |= BIT2;
        	    P1SEL |= BIT2;
        	    P2DIR |= BIT1|BIT4;
        	    P2SEL |= BIT1|BIT4;

                TA1CCR1 = 55;
                TA0CCR1 = 0;
                TA1CCR2 = 0;
                _delay_cycles(400000);
                TA0CCR1 = 60;
                break;

        case SMALLRIGHT:
        		P1DIR |= BIT2;
        	    P1SEL |= BIT2;
        	    P2DIR |= BIT1|BIT4;
        	    P2SEL |= BIT1|BIT4;

                TA1CCR1 = 55;
                TA0CCR1 = 0;
                TA1CCR2 = 0;
                _delay_cycles(200000);
                TA0CCR1 = 60;
                break;

        case BIGLEFT:
        		P1DIR |= BIT2;
        	    P1SEL |= BIT2;
        	    P2DIR |= BIT1|BIT4;
        	    P2SEL |= BIT1|BIT4;

                TA0CCR1 = 60;
                TA1CCR1 = 0;
                TA1CCR2 = 0;
                _delay_cycles(400000);
                TA1CCR1 = 55;
                break;

        case SMALLLEFT:
        		P1DIR |= BIT2;
        	    P1SEL |= BIT2;
        	    P2DIR |= BIT1|BIT4;
        	    P2SEL |= BIT1|BIT4;

                TA0CCR1 = 60;
                TA1CCR1 = 0;
                TA1CCR2 = 0;
                _delay_cycles(200000);
                TA1CCR1 = 55;
                break;
        }
}



