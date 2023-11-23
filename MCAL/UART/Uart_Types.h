/*
 * Uart_Types.h
 *
 *  Created on: Nov 1, 2023
 *      Author: dell
 */

#ifndef MCAL_UART_UART_TYPES_H_
#define MCAL_UART_UART_TYPES_H_

#define OK       0
#define NOT_OK   1
#define NULL ((void *)0)
#define UART_STATUS_ERROR OK
#define F_CPU 16000000UL


/* pointer to function*/
static void (*ptr2fun_Data_register_empty)(void) = NULL;
static void (*ptr2fun_transmit_complete)(void) = NULL;
static void (*ptr2fun_receive_data)(void) = NULL;

typedef unsigned char E_Errore_State_UART;


typedef enum
{
	 Data_Register_Empty,
	 Transmit_Complete,
	receive_complete
}MODES;

#endif /* MCAL_UART_UART_TYPES_H_ */
