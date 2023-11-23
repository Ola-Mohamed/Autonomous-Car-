/*
 * Timer0_Types.h
 *
 *  Created on: Nov 20, 2023
 *      Author: pc
 */

#ifndef TIMER0_TIMER0_TYPES_H_
#define TIMER0_TIMER0_TYPES_H_


// Define a custom data type for Timer0 error types
typedef unsigned char Timer0_E_ErrorType;

// Define a custom data type for 8-bit compare values
typedef unsigned char u8CompareValue;

// Define a custom data type for 8-bit duty cycle values
typedef unsigned char u8DutyCyle;

// Define an enumeration for Timer0 prescaler options
typedef enum
{
	Prescaler_8,     // Prescaler value of 8
	Prescaler_64,    // Prescaler value of 64
	Prescaler_256,   // Prescaler value of 256
	Prescaler_1024   // Prescaler value of 1024
} E_Prescaler;

// Define error codes for Timer0 functions
#define TIMER0_E_OK 0      // Timer0 operation successful
#define TIMER0_E_NOT_OK 1  // Timer0 operation not successful

// End of code

#define TIMER0_STATUS_ERROR TIMER0_E_OK


#endif /* TIMER0_TIMER0_TYPES_H_ */
