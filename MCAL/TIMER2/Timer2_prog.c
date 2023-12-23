/*
 * Timer2_prog.c
 *
 *  Created on: 5 Dec 2023
 *      Author: 20128
 */


#include"Timer2_Interface.h"


#define TIMER2_MODE OVER_FLOW_MODE

Timer2_E_ErrorType MCAL_Timer2_Init(E_Prescaler prescaler)
{
	Timer2_E_ErrorType error = TIMER2_E_OK ;
	if(TIMER2_STATUS_ERROR == TIMER2_E_NOT_OK)
	{
		error = TIMER2_E_NOT_OK;
	}
	else
	{
#if (TIMER2_MODE == OVER_FLOW_MODE)
		TCNT2 = 6; //To start counting

		SET_BIT(TCCR2,FOC2);

		switch (prescaler)
		{
		case Prescaler_8:
			SET_BIT(TCCR2,CS20);
			break;
		case Prescaler_64:
			SET_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS21);
			break;
		case Prescaler_256:
			SET_BIT(TCCR2,CS22);
			break;
		case Prescaler_1024:
			SET_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS22);
			break;
		default:
			break;
		}
		//Enable Time0 Iterrupt
		SET_BIT(TIMSK,TOIE2);
#endif
	}


    return error;

}
