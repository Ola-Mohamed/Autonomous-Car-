/*
 * Uart_register.h
 *
 *  Created on: Nov 1, 2023
 *      Author: dell
 */

#ifndef MCAL_UART_UART_REGISTER_H_
#define MCAL_UART_UART_REGISTER_H_

/************************************************************************/
/* Uart register                                                                     */
/************************************************************************/

 /* USART I/O Data Register */
#define UDR *((volatile unsigned char *)0x2C)
/* USART Control and Status RegisterA */
#define UCSRA *((volatile unsigned char *)0x2B)
/* USART Control and Status RegisterB */
#define UCSRB *((volatile unsigned char *)0x2A)
/* USART Control and Status RegisterC */
#define UCSRC *((volatile unsigned char*)0x40)
/* UART Baud Rate Registers */
#define UBRRL *((volatile unsigned char*)0x29)
/* UART Baud Rate Registers */
#define UBRRH *((volatile unsigned char*)0x40)

/***** USART Control and Status RegisterA bits*****/

/*  Multi-processor Communication Mode */
#define MPCM   0
/* Double the USART Transmission Speed*/
#define U2X    1
/* Parity Error */
#define PE     2
/* Data OverRun */
#define DOR    3
/* Frame Error*/
#define FE     4
/* USART Data Register Empty */
#define UDRE   5
/* USART Transmit Complete */
#define TXC    6
/* USART Receive Complete */
#define RXC    7

/**** USART Control and Status RegisterB bits***/

/* Transmit Data Bit 8 */
#define TXB8    0
/* Receive Data Bit 8 */
#define RXB8    1
/*Character Size */
#define UCSZ2   2
/* Transmitter Enable */
#define TXEN    3
/* Receiver Enable */
#define RXEN    4
/*  USART Data Register Empty Interrupt Enable */
#define UDRIE   5
/* TX Complete Interrupt Enable */
#define TXCIE   6
/* RX Complete Interrupt Enable */
#define RXCIE   7

/**** USART Control and Status RegisterC bits*****/

/* Clock Polarity*/
#define UCPOL    0
/* Character Size */
#define UCSZ0    1
/* Character Size */
#define UCSZ1    2
/* Stop Bit Select*/
#define USBS     3
/* UPM0: Parity Mode */
#define UPM0     4
/* UPM1: Parity Mode */
#define UPM1     5
/* USART Mode Select */
#define UMSEL    6
/* Register Select */
#define URSEL    7






#endif /* MCAL_UART_UART_REGISTER_H_ */
