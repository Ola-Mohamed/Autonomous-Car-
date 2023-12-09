
#include "Timer1_Interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/*************************Pointer to functions to be assigned to ISR*********************************/

static void (*Timer1_OVF_Fptr) (void)=NULL_PTR;
static void (*Timer1_OCA_Fptr) (void)=NULL_PTR;
static void (*Timer1_OCB_Fptr) (void)=NULL_PTR;
static void (*Timer1_ICU_Fptr) (void)=NULL_PTR;
/******************************************************************************************/

// Function to initialize Timer1 with specified mode and scaler
Timer1_E_Error_Type Timer1_Init(Timer1Mode_type mode, Timer1Scaler_type scaler)
{
    // Local variable to store the return status of the function
    Timer1_E_Error_Type localreturn = TIMER1_E_OK;

    // Switch case based on the selected Timer1 mode
    switch (mode)
    {
        // Configure Timer1 in Normal mode
        case TIMER1_NORMAL_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            CLEAR_BIT(TCCR1B, WGM12);
            CLEAR_BIT(TCCR1B, WGM13);
            break;

        // Configure Timer1 in CTC mode with ICR as the top value
        case TIMER1_CTC_ICR_TOP_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;

        // Configure Timer1 in CTC mode with OCRA as the top value
        case TIMER1_CTC_OCRA_TOP_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            CLEAR_BIT(TCCR1B, WGM13);
            break;

        // Configure Timer1 in Fast PWM mode with ICR as the top value
        case TIMER1_FASTPWM_ICR_TOP_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;

        // Configure Timer1 in Fast PWM mode with FF as the top value
        case TIMER1_FASTPWM_FF_TOP_MODE:
            SET_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            CLEAR_BIT(TCCR1B, WGM13);
            break;

        // Configure Timer1 in Fast PWM mode with OCRA as the top value
        case TIMER1_FASTPWM_OCRA_TOP_MODE:
            SET_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;
    }

    // Clear the first 3 bits of TCCR1B and set them according to the scaler value
    TCCR1B &= 0XF8;
    TCCR1B |= scaler;

    // Return the local variable indicating the success of the function
    return localreturn;
}

// Function to configure Timer1 OCRA mode
Timer1_E_Error_Type Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
    // Local variable to store the return status of the function
    Timer1_E_Error_Type localreturn = TIMER1_E_OK;

    // Switch case based on the selected OCRA mode
    switch (oc1a_mode)
    {
        // Disconnect OC1A (Clear on Compare Match)
        case OCRA_DISCONNECTED:
            CLEAR_BIT(TCCR1A, COM1A0);
            CLEAR_BIT(TCCR1A, COM1A1);
            break;

        // Toggle OC1A on Compare Match
        case OCRA_TOGGLE:
            SET_BIT(TCCR1A, COM1A0);
            CLEAR_BIT(TCCR1A, COM1A1);
            break;

        // Non-inverting mode for OC1A (Set on Compare Match)
        case OCRA_NON_INVERTING:
            CLEAR_BIT(TCCR1A, COM1A0);
            SET_BIT(TCCR1A, COM1A1);
            break;

        // Inverting mode for OC1A (Clear on Compare Match)
        case OCRA_INVERTING:
            SET_BIT(TCCR1A, COM1A0);
            SET_BIT(TCCR1A, COM1A1);
            break;
    }

    // Return the local variable indicating the success of the function
    return localreturn;
}

// Function to configure Timer1 OCRB mode
Timer1_E_Error_Type Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
    // Local variable to store the return status of the function
    Timer1_E_Error_Type localreturn = TIMER1_E_OK;

    // Switch case based on the selected OCRB mode
    switch (oc1b_mode)
    {
        // Disconnect OC1B (Clear on Compare Match)
        case OCRB_DISCONNECTED:
            CLEAR_BIT(TCCR1A, COM1B0);
            CLEAR_BIT(TCCR1A, COM1B1);
            break;

        // Toggle OC1B on Compare Match
        case OCRB_TOGGLE:
            SET_BIT(TCCR1A, COM1B0);
            CLEAR_BIT(TCCR1A, COM1B1);
            break;

        // Non-inverting mode for OC1B (Set on Compare Match)
        case OCRB_NON_INVERTING:
            CLEAR_BIT(TCCR1A, COM1B0);
            SET_BIT(TCCR1A, COM1B1);
            break;

        // Inverting mode for OC1B (Clear on Compare Match)
        case OCRB_INVERTING:
            SET_BIT(TCCR1A, COM1B0);
            SET_BIT(TCCR1A, COM1B1);
            break;
    }

    // Return the local variable indicating the success of the function
    return localreturn;
}

// Function to configure Timer1 Input Capture Edge
Timer1_E_Error_Type Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
    // Local variable to store the return status of the function
    Timer1_E_Error_Type localreturn = TIMER1_E_OK;

    // Check the specified edge type and set or clear the corresponding bit
    if (edge == RISING)
        SET_BIT(TCCR1B, ICES1);
    else if (edge == FALLING)
        CLEAR_BIT(TCCR1B, ICES1);

    // Return the local variable indicating the success of the function
    return localreturn;
}


// Enable Timer1 Input Capture Unit (ICU) interrupt
void Timer1_ICU_InterruptEnable(void)
{
    SET_BIT(TIMSK, TICIE1);
}

// Disable Timer1 Input Capture Unit (ICU) interrupt
void Timer1_ICU_InterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TICIE1);
}

// Enable Timer1 Overflow (OVF) interrupt
void Timer1_OVF_InterruptEnable(void)
{
    SET_BIT(TIMSK, TOIE1);
}

// Disable Timer1 Overflow (OVF) interrupt
void Timer1_OVF_InterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TOIE1);
}

// Enable Timer1 Output Compare A (OCA) interrupt
void Timer1_OCA_InterruptEnable(void)
{
    SET_BIT(TIMSK, OCIE1A);
}

// Disable Timer1 Output Compare A (OCA) interrupt
void Timer1_OCA_InterruptDisable(void)
{
    CLEAR_BIT(TIMSK, OCIE1A);
}

// Enable Timer1 Output Compare B (OCB) interrupt
void Timer1_OCB_InterruptEnable(void)
{
    SET_BIT(TIMSK, OCIE1B);
}

// Disable Timer1 Output Compare B (OCB) interrupt
void Timer1_OCB_InterruptDisable(void)
{
    CLEAR_BIT(TIMSK, OCIE1B);
}


/*********************************Timer 1 Call Back functions*****************************************/

// Set callback function for Timer1 Overflow (OVF) interrupt
Timer1_E_Error_Type Timer1_OVF_SetCallBack(void (*LocalFptr)(void))
{
    Timer1_E_Error_Type localreturn = TIMER1_E_NOT_OK;

    // Check if the callback function is NULL
    if (LocalFptr == NULL_PTR)
    {
        localreturn = TIMER1_E_NULL_PTR;
    }
    else
    {
        // Set the Timer1 OVF callback function
        Timer1_OVF_Fptr = LocalFptr;
        localreturn = TIMER1_E_OK;
    }

    return localreturn;
}

// Set callback function for Timer1 Output Compare A (OCA) interrupt
Timer1_E_Error_Type Timer1_OCA_SetCallBack(void (*LocalFptr)(void))
{
    Timer1_E_Error_Type localreturn = TIMER1_E_NOT_OK;

    // Check if the callback function is NULL
    if (LocalFptr == NULL_PTR)
    {
        localreturn = TIMER1_E_NULL_PTR;
    }
    else
    {
        // Set the Timer1 OCA callback function
        Timer1_OCA_Fptr = LocalFptr;
        localreturn = TIMER1_E_OK;
    }

    return localreturn;
}

// Set callback function for Timer1 Output Compare B (OCB) interrupt
Timer1_E_Error_Type Timer1_OCB_SetCallBack(void (*LocalFptr)(void))
{
    Timer1_E_Error_Type localreturn = TIMER1_E_NOT_OK;

    // Check if the callback function is NULL
    if (LocalFptr == NULL_PTR)
    {
        localreturn = TIMER1_E_NULL_PTR;
    }
    else
    {
        // Set the Timer1 OCB callback function
        Timer1_OCB_Fptr = LocalFptr;
        localreturn = TIMER1_E_OK;
    }

    return localreturn;
}

// Set callback function for Timer1 Input Capture Unit (ICU) interrupt
Timer1_E_Error_Type Timer1_ICU_SetCallBack(void (*LocalFptr)(void))
{
    Timer1_E_Error_Type localreturn = TIMER1_E_NOT_OK;

    // Check if the callback function is NULL
    if (LocalFptr == NULL_PTR)
    {
        localreturn = TIMER1_E_NULL_PTR;
    }
    else
    {
        // Set the Timer1 ICU callback function
        Timer1_ICU_Fptr = LocalFptr;
        localreturn = TIMER1_E_OK;
    }

    return localreturn;
}

// Timer1 Overflow (OVF) ISR
ISR(TIMER1_OVF_vect)
{
    // Check if the Timer1 OVF callback function is not NULL
    if (Timer1_OVF_Fptr != NULL_PTR)
    {
        // Call the Timer1 OVF callback function
        Timer1_OVF_Fptr();
    }
}

// Timer1 Output Compare A (OCA) ISR
ISR(TIMER1_OCA_vect)
{
    // Check if the Timer1 OCA callback function is not NULL
    if (Timer1_OCA_Fptr != NULL_PTR)
    {
        // Call the Timer1 OCA callback function
        Timer1_OCA_Fptr();
    }
}

// Timer1 Output Compare B (OCB) ISR
ISR(TIMER1_OCB_vect)
{
    // Check if the Timer1 OCB callback function is not NULL
    if (Timer1_OCB_Fptr != NULL_PTR)
    {
        // Call the Timer1 OCB callback function
        Timer1_OCB_Fptr();
    }
}

// Timer1 Input Capture Unit (ICU) ISR
ISR(TIMER1_ICU_vect)
{
    // Check if the Timer1 ICU callback function is not NULL
    if (Timer1_ICU_Fptr != NULL_PTR)
    {
        // Call the Timer1 ICU callback function
        Timer1_ICU_Fptr();
    }
}





