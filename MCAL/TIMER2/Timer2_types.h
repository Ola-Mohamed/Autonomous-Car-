/*
 * Timer2_types.h
 *
 *  Created on: 5 Dec 2023
 *      Author: 20128
 */

#ifndef TIMER2_TYPES_H_
#define TIMER2_TYPES_H_


// Define a custom data type for Timer2 error types
typedef unsigned char Timer2_E_ErrorType;


// Define an enumeration for Timer2 prescaler options
typedef enum
{
	Prescaler_8,     // Prescaler value of 8
	Prescaler_64,    // Prescaler value of 64
	Prescaler_256,   // Prescaler value of 256
	Prescaler_1024   // Prescaler value of 1024
} E_Prescaler;

// Define error codes for Timer0 functions
#define TIMER2_E_OK       0      // Timer2 operation successful
#define TIMER2_E_NOT_OK   1  // Timer2 operation not successful

// End of code

#define TIMER2_STATUS_ERROR TIMER2_E_OK


#endif /* TIMER2_TYPES_H_ */
