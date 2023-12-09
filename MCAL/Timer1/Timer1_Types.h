/*
 * Timer1_Types.h
 *
 *  Created on: Nov 17, 2023
 *      Author: pc
 */

#ifndef TIMER1_TIMER1_TYPES_H_
#define TIMER1_TIMER1_TYPES_H_


// Define a NULL pointer
#define NULL_PTR      ((void*)0)

// Define error types for Timer1 functions
typedef enum {
	TIMER1_E_OK=0,         // Timer1 operation successful
	TIMER1_E_NOT_OK,       // Timer1 operation not successful
	TIMER1_E_NULL_PTR      // Timer1 null pointer error
} Timer1_E_Error_Type;

// Define scaler types for Timer1
typedef enum {
	TIMER1_STOP=0,              // Timer1 stopped
	TIMER1_SCALER_1,            // Timer1 prescaler 1
	TIMER1_SCALER_8,            // Timer1 prescaler 8
	TIMER1_SCALER_64,           // Timer1 prescaler 64
	TIMER1_SCALER_256,          // Timer1 prescaler 256
	TIMER1_SCALER_1024,         // Timer1 prescaler 1024
	EXTERNAL0_FALLING,          // External trigger falling edge
	EXTERNAL0_RISING            // External trigger rising edge
} Timer1Scaler_type;

// Define mode types for Timer1
typedef enum {
	TIMER1_NORMAL_MODE=0,               // Timer1 normal mode
	TIMER1_CTC_ICR_TOP_MODE,            // Timer1 CTC mode with ICR as TOP
	TIMER1_CTC_OCRA_TOP_MODE,           // Timer1 CTC mode with OCR1A as TOP
	TIMER1_FASTPWM_ICR_TOP_MODE,        // Timer1 Fast PWM mode with ICR as TOP
	TIMER1_FASTPWM_OCRA_TOP_MODE,       // Timer1 Fast PWM mode with OCR1A as TOP
	TIMER1_FASTPWM_FF_TOP_MODE          // Timer1 Fast PWM mode with 0xFF as TOP
} Timer1Mode_type;

// Define output compare (OC1A) modes for Timer1
typedef enum {
	OCRA_DISCONNECTED=0,      // OC1A disconnected
	OCRA_TOGGLE,              // OC1A toggle mode
	OCRA_NON_INVERTING,       // OC1A non-inverting mode
	OCRA_INVERTING            // OC1A inverting mode
} OC1A_Mode_type;

// Define output compare (OC1B) modes for Timer1
typedef enum {
	OCRB_DISCONNECTED=0,      // OC1B disconnected
	OCRB_TOGGLE,              // OC1B toggle mode
	OCRB_NON_INVERTING,       // OC1B non-inverting mode
	OCRB_INVERTING            // OC1B inverting mode
} OC1B_Mode_type;

// Define edge types for Input Capture Unit (ICU)
typedef enum {
	RISING,   // Rising edge
	FALLING   // Falling edge
} ICU_Edge_type;


#endif /* TIMER1_TIMER1_TYPES_H_ */
