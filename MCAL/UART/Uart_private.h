/*
 * Uart_private.h
 *
 *  Created on: Nov 1, 2023
 *      Author: dell
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

/* Rx complete interrupt */
#define UART_RXC_VECT   __vector_13
/* USART Data Register Empty */
#define UART_UDRE_vect        __vector_14

/* USART, Tx Complete */
#define UART_TXC_vect         __vector_15

/* Enable global interrupts */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* Disable global interrupts */
#define cei() __asm__ __volatile__ ("cei" ::: "memory")

/* Macro defines the ISR */
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


#endif /* MCAL_UART_UART_PRIVATE_H_ */
