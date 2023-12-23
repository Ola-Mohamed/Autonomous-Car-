/*
 * Timer2_Register.h
 *
 *  Created on: 5 Dec 2023
 *      Author: 20128
 */

#ifndef TIMER2_REGISTER_H_
#define TIMER2_REGISTER_H_


#define TCCR2	*((volatile unsigned char*)(0x45))
#define TCNT2	*((volatile unsigned char*)(0x44))
#define OCR2	*((volatile unsigned char*)(0x43))
#define TIMSK	*((volatile unsigned char*)(0x57))
#define TIFR	*((volatile unsigned char*)(0x56))
#define ASSR    *((volatile unsigned char*)(0x50))
#define SFIOR   *((volatile unsigned char*)(0x40))





#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7

/* TIMSK Register */
#define TOIE2	0
#define OCIE2	1

/* TIFR Register */
#define TOV2	0
#define OCF2	1

/* ASSR Register */
#define TCR2UB 0
#define OCR2UB 1
#define TCN2UB 2
#define AS2    3

/* SFIOR Register */
#define TSM  7
#define PSR2 1



#endif /* TIMER2_REGISTER_H_ */
