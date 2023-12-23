/*
 * EX_interrupt_types.h
 *
 *  Created on: Dec 10, 2023
 *      Author: mosta
 */

#ifndef MCAL_EX_INTERRUPT_EX_INTERRUPT_TYPES_H_
#define MCAL_EX_INTERRUPT_EX_INTERRUPT_TYPES_H_

typedef enum
{
	EX_INT0=0,
	EX_INT1,
	EX_INT2,
	EX_INT3,
	EX_INT4,
	EX_INT5,
	EX_INT6,
	EX_INT7
} EX_Interrupt_Type;

typedef enum
{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
} EX_Interrupt_TriggerEdge_Type;

#endif /* MCAL_EX_INTERRUPT_EX_INTERRUPT_TYPES_H_ */
