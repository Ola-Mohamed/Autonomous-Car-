/*
 * Timer3_Interface.h
 *
 *  Created on: Nov 29, 2023
 *      Author: dell
 */

#ifndef MCAL_TIMER3_TIMER3_INTERFACE_H_
#define MCAL_TIMER3_TIMER3_INTERFACE_H_

#include "../../common_macros.h"
#include "../../std_types.h"
#include "Timer3_Config.h"
#include "Timer3_Private.h"
#include "Timer3_Register.h"
#include "Timer3_Types.h"



// Initialize Timer3 with specified mode and scaler
Timer3_E_Error_Type Timer3_Init(Timer3Mode_type mode, Timer3Scaler_type scaler);

// Set the output compare (OC3A) mode for Timer3
Timer3_E_Error_Type Timer3_OCRA3Mode(OC3A_Mode_type oc3a_mode);

// Set the output compare (OC3B) mode for Timer3
Timer3_E_Error_Type Timer3_OCRB3Mode(OC3B_Mode_type oc3b_mode);

// Set the edge type for Input Capture Unit (ICU)
Timer3_E_Error_Type Timer3_InputCaptureEdge(ICU3_Edge_type edge);

// Enable and disable ICU interrupts
void Timer3_ICU_InterruptEnable(void);
void Timer3_ICU_InterruptDisable(void);

// Enable and disable Timer3 Overflow (OVF) interrupts
void Timer3_OVF_InterruptEnable(void);
void Timer3_OVF_InterruptDisable(void);

// Enable and disable Timer3 Output Compare A (OCA) interrupts
void Timer3_OCA_InterruptEnable(void);
void Timer3_OCA_InterruptDisable(void);

// Enable and disable Timer3 Output Compare B (OCB) interrupts
void Timer3_OCB_InterruptEnable(void);
void Timer3_OCB_InterruptDisable(void);

// Set callback functions for Timer3 overflow, OCA, OCB, and ICU interrupts
Timer3_E_Error_Type Timer3_OVF_SetCallBack(void (*LocalFptr)(void));
Timer3_E_Error_Type Timer3_OCA_SetCallBack(void (*LocalFptr)(void));
Timer3_E_Error_Type Timer3_OCB_SetCallBack(void (*LocalFptr)(void));
Timer3_E_Error_Type Timer3_ICU_SetCallBack(void (*LocalFptr)(void));
void PWM_Duty(uint16 duty);
void PWM_Freq_HZ(uint16 freq);

#endif /* MCAL_TIMER3_TIMER3_INTERFACE_H_ */
