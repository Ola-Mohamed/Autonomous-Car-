/*
 * Timer0_Config.h
 *
 *  Created on: Nov 20, 2023
 *      Author: pc
 */

#ifndef TIMER0_TIMER0_CONFIG_H_
#define TIMER0_TIMER0_CONFIG_H_

#include "../DIO/DIO_Interface.h"

// Define the selected mode for Timer/Counter0


#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

/* TIMSK Register */
#define TOIE0	0
#define OCIE0	1

/* TIFR Register */
#define TOV0	0
#define OCF0	1

/* ASSR Register */
#define TCR0UB 0
#define OCR0UB 1
#define TCN0UB 2
#define AS0    3

/* SFIOR Register */
#define TSM  7
#define PSR0 1



/* SFIOR Register */
#define PSR0 1
#define TSM  7


#define TIMER0_PWM_PIN 4
#define TIMER0_PWM_PORT DIO_DDRB




#endif /* TIMER0_TIMER0_CONFIG_H_ */
