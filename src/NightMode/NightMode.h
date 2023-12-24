/*
 * NightMode.h
 *
 *  Created on: 22 Nov 2023
 *      Author: Ola
 */

#include "../DIO/DIO_interface.h"
#include "../ADC/ADC_interface.h"
#include "../LDR/LDR_Interface.h"
#include "../LED/LED_Interface.h"
#include "../DC_MOTOR/DC_Interface.h"
#include "../TIMER0/Time0_Interface.h"


/************************************************Defines*****************************************/

#define NightMode_E_OK 0

#define NightMode_E_NOT_OK 1

#define LDR_Value 30

#define Speed_limit 20

#define Regular_Speed  80


/*******************************************Global Varaibles****************************************/

// Define the LDR pin percentage variable
char LDR_Percentage; 

E_LDR_ErrorType result;

typedef unsigned char NightMode_Error_Type = NightMode_E_NOT_OK;

/***********************************************Prototypes*********************************************************/
void Night_Mode_init();

NightMode_Error_Type Night_Mode_Task();