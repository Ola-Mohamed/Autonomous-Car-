/*
 * EX_Interrupt.c
 *
 *  Created on: Dec 10, 2023
 *      Author: mosta
 */

#include "EX_Interrupt_Interface.h"

/****************************Pointer to functions to be assigned to ISR*********************************/

static void (*INT0_Fptr)(void) = NULL_PTR;
static void (*INT1_Fptr)(void) = NULL_PTR;
static void (*INT2_Fptr)(void) = NULL_PTR;
static void (*INT3_Fptr)(void) = NULL_PTR;
static void (*INT4_Fptr)(void) = NULL_PTR;
static void (*INT5_Fptr)(void) = NULL_PTR;
static void (*INT6_Fptr)(void) = NULL_PTR;
static void (*INT7_Fptr)(void) = NULL_PTR;

/************************************Init struct and function***********************************/

S_Dio EX_Interrupt_PIN = { 0, 0, INPUT };

void EX_Interrupt_Init(EX_Interrupt_Type EX_INT) {
	switch (EX_INT) {
	case EX_INT0:
		EX_Interrupt_PIN.port_num = PORTD_ID;
		EX_Interrupt_PIN.pin_num = PIN0_ID;
		MCAL_Dio_SetPinDirection(&EX_Interrupt_PIN);
		break;
	case EX_INT1:
		EX_Interrupt_PIN.port_num = PORTD_ID;
		EX_Interrupt_PIN.pin_num = PIN1_ID;
		MCAL_Dio_SetPinDirection(&EX_Interrupt_PIN);
		break;
	case EX_INT2:
		EX_Interrupt_PIN.port_num = PORTD_ID;
		EX_Interrupt_PIN.pin_num = PIN2_ID;
		MCAL_Dio_SetPinDirection(&EX_Interrupt_PIN);
		break;
	case EX_INT3:
		EX_Interrupt_PIN.port_num = PORTD_ID;
		EX_Interrupt_PIN.pin_num = PIN3_ID;
		MCAL_Dio_SetPinDirection(&EX_Interrupt_PIN);
		break;
	case EX_INT4:
		EX_Interrupt_PIN.port_num = PORTE_ID;
		EX_Interrupt_PIN.pin_num = PIN4_ID;
		MCAL_Dio_SetPinDirection(&EX_Interrupt_PIN);
		break;
	case EX_INT5:
		EX_Interrupt_PIN.port_num = PORTE_ID;
		EX_Interrupt_PIN.pin_num = PIN5_ID;
		MCAL_Dio_SetPinDirection(&EX_Interrupt_PIN);
		break;
	case EX_INT6:
		EX_Interrupt_PIN.port_num = PORTE_ID;
		EX_Interrupt_PIN.pin_num = PIN6_ID;
		MCAL_Dio_SetPinDirection(&EX_Interrupt_PIN);
		break;
	case EX_INT7:
		EX_Interrupt_PIN.port_num = PORTE_ID;
		EX_Interrupt_PIN.pin_num = PIN7_ID;
		MCAL_Dio_SetPinDirection(&EX_Interrupt_PIN);
		break;
	}
}

/************************************Enable/Disable functions***********************************/

void EX_Interrupt_Enable(EX_Interrupt_Type EX_INT) {
	switch (EX_INT) {
	case EX_INT0:
		SET_BIT(EIMSK, INT0);
		break;
	case EX_INT1:
		SET_BIT(EIMSK, INT1);
		break;
	case EX_INT2:
		SET_BIT(EIMSK, INT2);
		break;
	case EX_INT3:
		SET_BIT(EIMSK, INT3);
		break;
	case EX_INT4:
		SET_BIT(EIMSK, INT4);
		break;
	case EX_INT5:
		SET_BIT(EIMSK, INT5);
		break;
	case EX_INT6:
		SET_BIT(EIMSK, INT6);
		break;
	case EX_INT7:
		SET_BIT(EIMSK, INT7);
		break;
	}
}

void EX_Interrupt_Disable(EX_Interrupt_Type EX_INT) {
	switch (EX_INT) {
	case EX_INT0:
		CLEAR_BIT(EIMSK, INT0);
		break;
	case EX_INT1:
		CLEAR_BIT(EIMSK, INT1);
		break;
	case EX_INT2:
		CLEAR_BIT(EIMSK, INT2);
		break;
	case EX_INT3:
		CLEAR_BIT(EIMSK, INT3);
		break;
	case EX_INT4:
		CLEAR_BIT(EIMSK, INT4);
		break;
	case EX_INT5:
		CLEAR_BIT(EIMSK, INT5);
		break;
	case EX_INT6:
		CLEAR_BIT(EIMSK, INT6);
		break;
	case EX_INT7:
		CLEAR_BIT(EIMSK, INT7);
		break;
	}
}

/************************************Control function*****************************/

void EX_Interrupt_TriggerEdge(EX_Interrupt_Type EX_INT,
		EX_Interrupt_TriggerEdge_Type Edge) {
	switch (EX_INT) {
	case EX_INT0:
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(EICRA, ISC00);
			CLEAR_BIT(EICRA, ISC01);
			break;
		case ANY_LOGIC_CHANGE:
			break;
		case FALLING_EDGE:
			CLEAR_BIT(EICRA, ISC00);
			SET_BIT(EICRA, ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(EICRA, ISC00);
			SET_BIT(EICRA, ISC01);
			break;
		}
		break;
	case EX_INT1:
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(EICRA, ISC10);
			CLEAR_BIT(EICRA, ISC11);
			break;
		case ANY_LOGIC_CHANGE:
			break;
		case FALLING_EDGE:
			CLEAR_BIT(EICRA, ISC10);
			SET_BIT(EICRA, ISC11);
			break;
		case RISING_EDGE:
			SET_BIT(EICRA, ISC10);
			SET_BIT(EICRA, ISC11);
			break;
		}
		break;
	case EX_INT2:
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(EICRA, ISC20);
			CLEAR_BIT(EICRA, ISC21);
			break;
		case ANY_LOGIC_CHANGE:
			break;
		case FALLING_EDGE:
			CLEAR_BIT(EICRA, ISC20);
			SET_BIT(EICRA, ISC21);
			break;
		case RISING_EDGE:
			SET_BIT(EICRA, ISC20);
			SET_BIT(EICRA, ISC21);
			break;
		}
		break;
	case EX_INT3:
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(EICRA, ISC30);
			CLEAR_BIT(EICRA, ISC31);
			break;
		case ANY_LOGIC_CHANGE:
			break;
		case FALLING_EDGE:
			CLEAR_BIT(EICRA, ISC30);
			SET_BIT(EICRA, ISC31);
			break;
		case RISING_EDGE:
			SET_BIT(EICRA, ISC30);
			SET_BIT(EICRA, ISC31);
			break;
		}
		break;
	case EX_INT4:
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(EICRB, ISC40);
			CLEAR_BIT(EICRB, ISC41);
			break;
		case ANY_LOGIC_CHANGE:
			SET_BIT(EICRB, ISC40);
			CLEAR_BIT(EICRB, ISC41);
			break;
		case FALLING_EDGE:
			CLEAR_BIT(EICRB, ISC40);
			SET_BIT(EICRB, ISC41);
			break;
		case RISING_EDGE:
			SET_BIT(EICRB, ISC40);
			SET_BIT(EICRB, ISC41);
			break;
		}
		break;
	case EX_INT5:
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(EICRB, ISC50);
			CLEAR_BIT(EICRB, ISC51);
			break;
		case ANY_LOGIC_CHANGE:
			SET_BIT(EICRB, ISC50);
			CLEAR_BIT(EICRB, ISC51);
			break;
		case FALLING_EDGE:
			CLEAR_BIT(EICRB, ISC50);
			SET_BIT(EICRB, ISC51);
			break;
		case RISING_EDGE:
			SET_BIT(EICRB, ISC50);
			SET_BIT(EICRB, ISC51);
			break;
		}
		break;
	case EX_INT6:
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(EICRB, ISC60);
			CLEAR_BIT(EICRB, ISC61);
			break;
		case ANY_LOGIC_CHANGE:
			SET_BIT(EICRB, ISC60);
			CLEAR_BIT(EICRB, ISC61);
			break;
		case FALLING_EDGE:
			CLEAR_BIT(EICRB, ISC60);
			SET_BIT(EICRB, ISC61);
			break;
		case RISING_EDGE:
			SET_BIT(EICRB, ISC60);
			SET_BIT(EICRB, ISC61);
			break;
		}
		break;
	case EX_INT7:
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(EICRB, ISC70);
			CLEAR_BIT(EICRB, ISC71);
			break;
		case ANY_LOGIC_CHANGE:
			SET_BIT(EICRB, ISC70);
			CLEAR_BIT(EICRB, ISC71);
			break;
		case FALLING_EDGE:
			CLEAR_BIT(EICRB, ISC70);
			SET_BIT(EICRB, ISC71);
			break;
		case RISING_EDGE:
			SET_BIT(EICRB, ISC70);
			SET_BIT(EICRB, ISC71);
			break;
		}
		break;
	}
}

/************************************Call back functions*********************************************/

void EX_Interrupt_SetCallBack(EX_Interrupt_Type EX_INT, void (*LocalPtr)(void)) {
	switch (EX_INT) {
	case EX_INT0:
		INT0_Fptr = LocalPtr;
		break;
	case EX_INT1:
		INT1_Fptr = LocalPtr;
		break;
	case EX_INT2:
		INT2_Fptr = LocalPtr;
		break;
	case EX_INT3:
		INT3_Fptr = LocalPtr;
		break;
	case EX_INT4:
		INT4_Fptr = LocalPtr;
		break;
	case EX_INT5:
		INT5_Fptr = LocalPtr;
		break;
	case EX_INT6:
		INT6_Fptr = LocalPtr;
		break;
	case EX_INT7:
		INT7_Fptr = LocalPtr;
		break;
	}
}

/*******************************ISR********************************/

ISR(INT0_vect)
{
	if (INT0_Fptr!=NULL_PTR)
	{
		INT0_Fptr();
	}
}
ISR(INT1_vect)
{
	if (INT1_Fptr!=NULL_PTR)
	{
		INT1_Fptr();
	}
}
ISR(INT2_vect)
{
	if (INT2_Fptr!=NULL_PTR)
	{
		INT2_Fptr();
	}
}
ISR(INT3_vect)
{
	if (INT3_Fptr!=NULL_PTR)
	{
		INT3_Fptr();
	}
}
ISR(INT4_vect)
{
	if (INT4_Fptr!=NULL_PTR)
	{
		INT4_Fptr();
	}
}
ISR(INT5_vect)
{
	if (INT5_Fptr!=NULL_PTR)
	{
		INT5_Fptr();
	}
}
ISR(INT6_vect)
{
	if (INT6_Fptr!=NULL_PTR)
	{
		INT6_Fptr();
	}
}
ISR(INT7_vect)
{
	if (INT7_Fptr!=NULL_PTR)
	{
		INT7_Fptr();
	}
}
