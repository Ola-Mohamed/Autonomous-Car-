/*
 * Timer2_interface.h
 *
 *  Created on: 5 Dec 2023
 *      Author: 20128
 */

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_



//#include "Timer2_Register.h"
#include "Timer2_Types.h"
#include"commons_macros.h"
#include <avr/interrupt.h>




/***********************************************************
 *
 *                  Defines
 *
 **********************************************************/



// Define constants for timer modes
#define OVER_FLOW_MODE 0   // Overflow mode for Timer/Counter0
#define CTC_MODE 1         // Clear Timer on Compare Match (CTC) mode for Timer/Counter0
#define FAST_PWM_MODE 2     // Fast PWM mode for Timer/Counter0
#define PCP_PWM_MODE 3      // Phase Correct PWM mode for Timer/Counter0


/***********************************************************
 *
 *                   Functions Prototypes
 *
 **********************************************************/

// Declare the function prototype for Timer0 initialization
// Takes prescaler, compare value, and duty cycle as parameters
Timer2_E_ErrorType MCAL_Timer2_Init(E_Prescaler prescaler);



#endif /* TIMER2_INTERFACE_H_ */
