/*
 * Timer0_Registers.h
 *
 *  Created on: Nov 20, 2023
 *      Author: pc
 */

#ifndef TIMER0_TIMER0_REGISTERS_H_
#define TIMER0_TIMER0_REGISTERS_H_


#define TCCR0	*((volatile unsigned char*)(0x53))
#define TCNT0	*((volatile unsigned char*)(0x52))
#define OCR0	*((volatile unsigned char*)(0x51))
#define TIMSK	*((volatile unsigned char*)(0x57))
#define TIFR	*((volatile unsigned char*)(0x56))
#define ASSR    *((volatile unsigned char*)(0x50))
#define SFIOR   *((volatile unsigned char*)(0x40))






#endif /* TIMER0_TIMER0_REGISTERS_H_ */
