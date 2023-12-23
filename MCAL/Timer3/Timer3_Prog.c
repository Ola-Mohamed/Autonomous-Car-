/*
 * Timer3_Prog.c

 *
 *  Created on: Nov 29, 2023
 *      Author: dell
 */


#include "Timer3_Interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/*************************Pointer to functions to be assigned to ISR*********************************/

static void (*Timer3_OVF_Fptr) (void)=NULL3_PTR;
static void (*Timer3_OCA_Fptr) (void)=NULL3_PTR;
static void (*Timer3_OCB_Fptr) (void)=NULL3_PTR;
static void (*Timer3_ICU_Fptr) (void)=NULL3_PTR;
/******************************************************************************************/

// Function to initialize Timer3 with specified mode and scaler
Timer3_E_Error_Type Timer3_Init(Timer3Mode_type mode, Timer3Scaler_type scaler)
{
    // Local variable to store the return status of the function
    Timer3_E_Error_Type localreturn = TIMER3_E_OK;

    // Switch case based on the selected Timer3 mode
    switch (mode)
    {
        // Configure Timer3 in Normal mode
        case TIMER3_NORMAL_MODE:
            CLEAR_BIT(TCCR3A, WGM30);
            CLEAR_BIT(TCCR3A, WGM31);
            CLEAR_BIT(TCCR3B, WGM32);
            CLEAR_BIT(TCCR3B, WGM33);
            break;

        // Configure Timer3 in CTC mode with ICR as the top value
        case TIMER3_CTC_ICR_TOP_MODE:
            CLEAR_BIT(TCCR3A, WGM30);
            CLEAR_BIT(TCCR3A, WGM31);
            SET_BIT(TCCR3B, WGM32);
            SET_BIT(TCCR3B, WGM33);
            break;

        // Configure Timer3 in CTC mode with OCRA as the top value
        case TIMER3_CTC_OCRA_TOP_MODE:
            CLEAR_BIT(TCCR3A, WGM30);
            CLEAR_BIT(TCCR3A, WGM31);
            SET_BIT(TCCR3B, WGM32);
            CLEAR_BIT(TCCR3B, WGM33);
            break;

        // Configure Timer3 in Fast PWM mode with ICR as the top value
        case TIMER3_FASTPWM_ICR_TOP_MODE:
            CLEAR_BIT(TCCR3A, WGM30);
            SET_BIT(TCCR3A, WGM31);
            SET_BIT(TCCR3B, WGM32);
            SET_BIT(TCCR3B, WGM33);
            break;

        // Configure Timer3 in Fast PWM mode with FF as the top value
        case TIMER3_FASTPWM_FF_TOP_MODE:
            SET_BIT(TCCR3A, WGM30);
            CLEAR_BIT(TCCR3A, WGM31);
            SET_BIT(TCCR3B, WGM32);
            CLEAR_BIT(TCCR3B, WGM33);
            break;

        // Configure Timer3 in Fast PWM mode with OCRA as the top value
        case TIMER3_FASTPWM_OCRA_TOP_MODE:
            SET_BIT(TCCR3A, WGM30);
            SET_BIT(TCCR3A, WGM31);
            SET_BIT(TCCR3B, WGM32);
            SET_BIT(TCCR3B, WGM33);
            break;

    }

    // Clear the first 3 bits of TCCR3B and set them according to the scaler value
    TCCR3B &= 0XF8;
    TCCR3B |= scaler;

    // Return the local variable indicating the success of the function
    return localreturn;
}

// Function to configure Timer3 OCRA mode
Timer3_E_Error_Type Timer3_OCRA3Mode(OC3A_Mode_type oc3a_mode)
{
    // Local variable to store the return status of the function
    Timer3_E_Error_Type localreturn = TIMER3_E_OK;

    // Switch case based on the selected OCRA mode
    switch (oc3a_mode)
    {
        // Disconnect OC3A (Clear on Compare Match)
        case OCRA3_DISCONNECTED:
            CLEAR_BIT(TCCR3A, COM3A0);
            CLEAR_BIT(TCCR3A, COM3A1);
            break;

        // Toggle OC3A on Compare Match
        case OCRA3_TOGGLE:
            SET_BIT(TCCR3A, COM3A0);
            CLEAR_BIT(TCCR3A, COM3A1);
            break;

        // Non-inverting mode for OC3A (Set on Compare Match)
        case OCRA3_NON_INVERTING:
            CLEAR_BIT(TCCR3A, COM3A0);
            SET_BIT(TCCR3A, COM3A1);
            break;

        // Inverting mode for OC3A (Clear on Compare Match)
        case OCRA3_INVERTING:
            SET_BIT(TCCR3A, COM3A0);
            SET_BIT(TCCR3A, COM3A1);
            break;
    }

    // Return the local variable indicating the success of the function
    return localreturn;
}

// Function to configure Timer3 OCRB mode
Timer3_E_Error_Type Timer3_OCRB3Mode(OC3B_Mode_type oc3b_mode)
{
    // Local variable to store the return status of the function
    Timer3_E_Error_Type localreturn = TIMER3_E_OK;

    // Switch case based on the selected OCRB mode
    switch (oc3b_mode)
    {
        // Disconnect OC3B (Clear on Compare Match)
        case OCRB3_DISCONNECTED:
            CLEAR_BIT(TCCR3A, COM3B0);
            CLEAR_BIT(TCCR3A, COM3B1);
            break;

        // Toggle OC3B on Compare Match
        case OCRB3_TOGGLE:
            SET_BIT(TCCR3A, COM3B0);
            CLEAR_BIT(TCCR3A, COM3B1);
            break;

        // Non-inverting mode for OC3B (Set on Compare Match)
        case OCRB3_NON_INVERTING:
            CLEAR_BIT(TCCR3A, COM3B0);
            SET_BIT(TCCR3A, COM3B1);
            break;

        // Inverting mode for OC3B (Clear on Compare Match)
        case OCRB3_INVERTING:
            SET_BIT(TCCR3A, COM3B0);
            SET_BIT(TCCR3A, COM3B1);
            break;
    }

    // Return the local variable indicating the success of the function
    return localreturn;
}

// Function to configure Timer3 Input Capture Edge
Timer3_E_Error_Type Timer3_InputCaptureEdge(ICU3_Edge_type edge)
{
    // Local variable to store the return status of the function
    Timer3_E_Error_Type localreturn = TIMER3_E_OK;

    // Check the specified edge type and set or clear the corresponding bit
    if (edge == RISING3)
        SET_BIT(TCCR3B, ICES3);
    else if (edge == FALLING3)
        CLEAR_BIT(TCCR3B, ICES3);

    // Return the local variable indicating the success of the function
    return localreturn;
}


// Enable Timer3 Input Capture Unit (ICU) interrupt
void Timer3_ICU_InterruptEnable(void)
{
    SET_BIT(ETIMSK, TICIE3);
}

// Disable Timer3 Input Capture Unit (ICU) interrupt
void Timer3_ICU_InterruptDisable(void)
{
    CLEAR_BIT(ETIMSK, TICIE3);
}

// Enable Timer3 Overflow (OVF) interrupt
void Timer3_OVF_InterruptEnable(void)
{
    SET_BIT(ETIMSK, TOIE3);
}

// Disable Timer3 Overflow (OVF) interrupt
void Timer3_OVF_InterruptDisable(void)
{
    CLEAR_BIT(ETIMSK, TOIE3);
}

// Enable Timer3 Output Compare A (OCA) interrupt
void Timer3_OCA_InterruptEnable(void)
{
    SET_BIT(ETIMSK, OCIE3A);
}

// Disable Timer3 Output Compare A (OCA) interrupt
void Timer3_OCA_InterruptDisable(void)
{
    CLEAR_BIT(ETIMSK, OCIE3A);
}

// Enable Timer3 Output Compare B (OCB) interrupt
void Timer3_OCB_InterruptEnable(void)
{
    SET_BIT(ETIMSK, OCIE3B);
}

// Disable Timer3 Output Compare B (OCB) interrupt
void Timer3_OCB_InterruptDisable(void)
{
    CLEAR_BIT(ETIMSK, OCIE3B);
}


/*********************************Timer 3 Call Back functions*****************************************/

// Set callback function for Timer3 Overflow (OVF) interrupt
Timer3_E_Error_Type Timer3_OVF_SetCallBack(void (*LocalFptr)(void))
{
    Timer3_E_Error_Type localreturn = TIMER3_E_NOT_OK;

    // Check if the callback function is NULL
    if (LocalFptr == NULL3_PTR)
    {
        localreturn = TIMER3_E_NULL_PTR;
    }
    else
    {
        // Set the Timer1 OVF callback function
        Timer3_OVF_Fptr = LocalFptr;
        localreturn = TIMER3_E_OK;
    }

    return localreturn;
}

// Set callback function for Timer1 Output Compare A (OCA) interrupt
Timer3_E_Error_Type Timer3_OCA_SetCallBack(void (*LocalFptr)(void))
{
    Timer3_E_Error_Type localreturn = TIMER3_E_NOT_OK;

    // Check if the callback function is NULL
    if (LocalFptr == NULL3_PTR)
    {
        localreturn = TIMER3_E_NULL_PTR;
    }
    else
    {
        // Set the Timer3 OCA callback function
        Timer3_OCA_Fptr = LocalFptr;
        localreturn = TIMER3_E_OK;
    }

    return localreturn;
}

// Set callback function for Timer3 Output Compare B (OCB) interrupt
Timer3_E_Error_Type Timer3_OCB_SetCallBack(void (*LocalFptr)(void))
{
    Timer3_E_Error_Type localreturn = TIMER3_E_NOT_OK;

    // Check if the callback function is NULL
    if (LocalFptr == NULL3_PTR)
    {
        localreturn = TIMER3_E_NULL_PTR;
    }
    else
    {
        // Set the Timer3 OCB callback function
        Timer3_OCB_Fptr = LocalFptr;
        localreturn = TIMER3_E_OK;
    }

    return localreturn;
}

// Set callback function for Timer3 Input Capture Unit (ICU) interrupt
Timer3_E_Error_Type Timer3_ICU_SetCallBack(void (*LocalFptr)(void))
{
    Timer3_E_Error_Type localreturn = TIMER3_E_NOT_OK;

    // Check if the callback function is NULL
    if (LocalFptr == NULL3_PTR)
    {
        localreturn = TIMER3_E_NULL_PTR;
    }
    else
    {
        // Set the Timer1 ICU callback function
        Timer3_ICU_Fptr = LocalFptr;
        localreturn = TIMER3_E_OK;
    }

    return localreturn;
}

// Timer3 Overflow (OVF) ISR
ISR(TIMER3_OVF_vect)
{
    // Check if the Timer1 OVF callback function is not NULL
    if (Timer3_OVF_Fptr != NULL3_PTR)
    {
        // Call the Timer1 OVF callback function
        Timer3_OVF_Fptr();
    }
}

// Timer1 Output Compare A (OCA) ISR
ISR(TIMER3_OCA_vect)
{
    // Check if the Timer3 OCA callback function is not NULL
    if (Timer3_OCA_Fptr != NULL3_PTR)
    {
        // Call the Timer3 OCA callback function
        Timer3_OCA_Fptr();
    }
}

// Timer3 Output Compare B (OCB) ISR
ISR(TIMER3_OCB_vect)
{
    // Check if the Timer3 OCB callback function is not NULL
    if (Timer3_OCB_Fptr != NULL3_PTR)
    {
        // Call the Timer3 OCB callback function
        Timer3_OCB_Fptr();
    }
}

// Timer3 Input Capture Unit (ICU) ISR
ISR(TIMER3_ICU_vect)
{
    // Check if the Timer3 ICU callback function is not NULL
    if (Timer3_ICU_Fptr != NULL3_PTR)
    {
        // Call the Timer3 ICU callback function
        Timer3_ICU_Fptr();
    }
}


void PWM_Freq_HZ(uint16 freq)
{
	if (freq==0)
	{
		// Do Nothing
	}
	else
	{
		uint16 Ttotal=(uint32)2000000/freq;
		if (Ttotal>=1)
		{
			OCR3A=Ttotal-1;
		}
		else OCR3A=0;
	}
}


void PWM_Duty(uint16 duty) // duty*10 ----- To get high res //
{
	 if (duty<=1000)
	{
		uint16 Ton=((uint32)duty*(OCR3A+1))/1000;
		 //uint16 Ton=((uint32)duty*(OCR3A+1))/0.5;
		if (Ton>1)
		{
			OCR3B=Ton-1;
		}
		else
		OCR3B=0;
	}
}
