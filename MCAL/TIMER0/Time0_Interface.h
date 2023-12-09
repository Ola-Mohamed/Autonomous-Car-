/*
 * Time0_Interface.h
 *
 *  Created on: Nov 20, 2023
 *      Author: pc
 */

#ifndef TIMER0_TIME0_INTERFACE_H_
#define TIMER0_TIME0_INTERFACE_H_




#include "Timer0_Config.h"
#include "Timer0_Registers.h"
#include "Timer0_Private.h"
#include "Timer0_Types.h"




// Define constants for timer modes
#define OVER_FLOW_MODE 0   // Overflow mode for Timer/Counter0
#define CTC_MODE 1         // Clear Timer on Compare Match (CTC) mode for Timer/Counter0
#define FAST_PWM_MODE 2     // Fast PWM mode for Timer/Counter0
#define PCP_PWM_MODE 3      // Phase Correct PWM mode for Timer/Counter0


static S_Dio S_Timer = {PORTB_ID,PIN4_ID,OUTPUT};

/***********************************************************
 *
 *                   Functions Prototypes
 *
 **********************************************************/

// Declare the function prototype for Timer0 initialization
// Takes prescaler, compare value, and duty cycle as parameters
Timer0_E_ErrorType MCAL_Timer0_Init(E_Prescaler prescaler, u8CompareValue CompareValue, u8DutyCyle Duty_Cycle);
Timer0_E_ErrorType MCAL_Timer0_SetSpeed(u8DutyCyle DutyCycle);
// End of code


#endif /* TIMER0_TIME0_INTERFACE_H_ */
