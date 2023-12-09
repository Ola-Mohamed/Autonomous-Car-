/*
 * Timer1_Interface.h
 *
 *  Created on: Nov 17, 2023
 *      Author: pc
 */

#ifndef TIMER1_TIMER1_INTERFACE_H_
#define TIMER1_TIMER1_INTERFACE_H_


#include "../../common_macros.h"
#include "Timer1_Config.h"
#include "Timer1_Private.h"
#include "Timer1_Register.h"
#include "Timer1_Types.h"



// Initialize Timer1 with specified mode and scaler
Timer1_E_Error_Type Timer1_Init(Timer1Mode_type mode, Timer1Scaler_type scaler);

// Set the output compare (OC1A) mode for Timer1
Timer1_E_Error_Type Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode);

// Set the output compare (OC1B) mode for Timer1
Timer1_E_Error_Type Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode);

// Set the edge type for Input Capture Unit (ICU)
Timer1_E_Error_Type Timer1_InputCaptureEdge(ICU_Edge_type edge);

// Enable and disable ICU interrupts
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);

// Enable and disable Timer1 Overflow (OVF) interrupts
void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);

// Enable and disable Timer1 Output Compare A (OCA) interrupts
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);

// Enable and disable Timer1 Output Compare B (OCB) interrupts
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);

// Set callback functions for Timer1 overflow, OCA, OCB, and ICU interrupts
Timer1_E_Error_Type Timer1_OVF_SetCallBack(void (*LocalFptr)(void));
Timer1_E_Error_Type Timer1_OCA_SetCallBack(void (*LocalFptr)(void));
Timer1_E_Error_Type Timer1_OCB_SetCallBack(void (*LocalFptr)(void));
Timer1_E_Error_Type Timer1_ICU_SetCallBack(void (*LocalFptr)(void));



#endif /* TIMER1_TIMER1_INTERFACE_H_ */
