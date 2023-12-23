/*
 * Timer3_Types.h
 *
 *  Created on: Nov 29, 2023
 *      Author: dell
 */

#ifndef MCAL_TIMER3_TIMER3_TYPES_H_
#define MCAL_TIMER3_TIMER3_TYPES_H_

// Define a NULL pointer
#define NULL3_PTR      ((void*)0)

// Define error types for Timer3 functions
typedef enum {
	TIMER3_E_OK=0,         // Timer3 operation successful
	TIMER3_E_NOT_OK,       // Timer3 operation not successful
	TIMER3_E_NULL_PTR      // Timer3 null pointer error
} Timer3_E_Error_Type;

// Define scaler types for Timer3
typedef enum {
	TIMER3_STOP=0,              // Timer3 stopped
	TIMER3_SCALER_1,            // Timer3 prescaler 1
	TIMER3_SCALER_8,            // Timer3 prescaler 8
	TIMER3_SCALER_64,           // Timer3 prescaler 64
	TIMER3_SCALER_256,          // Timer3 prescaler 256
	TIMER3_SCALER_1024,         // Timer3 prescaler 1024
	EXTERNAL03_FALLING,          // External trigger falling edge
	EXTERNAL03_RISING            // External trigger rising edge
} Timer3Scaler_type;

// Define mode types for Timer1
typedef enum {
	TIMER3_NORMAL_MODE=0,               // Timer3 normal mode
	TIMER3_CTC_ICR_TOP_MODE,            // Timer3 CTC mode with ICR as TOP
	TIMER3_CTC_OCRA_TOP_MODE,           // Timer3 CTC mode with OCR1A as TOP
	TIMER3_FASTPWM_ICR_TOP_MODE,        // Timer3 Fast PWM mode with ICR as TOP
	TIMER3_FASTPWM_OCRA_TOP_MODE,       // Timer3 Fast PWM mode with OCR1A as TOP
	TIMER3_FASTPWM_FF_TOP_MODE          // Timer3 Fast PWM mode with 0xFF as TOP
} Timer3Mode_type;

// Define output compare (OC3A) modes for Timer3
typedef enum {
	OCRA3_DISCONNECTED=0,      // OC3A disconnected
	OCRA3_TOGGLE,              // OC3A toggle mode
	OCRA3_NON_INVERTING,       // OC3A non-inverting mode
	OCRA3_INVERTING            // OC3A inverting mode
} OC3A_Mode_type;

// Define output compare (OC3B) modes for Timer3
typedef enum {
	OCRB3_DISCONNECTED=0,      // OC3B disconnected
	OCRB3_TOGGLE,              // OC3B toggle mode
	OCRB3_NON_INVERTING,       // OC3B non-inverting mode
	OCRB3_INVERTING            // OC3B inverting mode
} OC3B_Mode_type;

// Define edge types for Input Capture Unit (ICU)
typedef enum {
	RISING3,   // Rising edge
	FALLING3   // Falling edge
} ICU3_Edge_type;


#endif /* MCAL_TIMER3_TIMER3_TYPES_H_ */
