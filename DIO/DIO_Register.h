/*
 * DIO_Register.h
 *
 *  Created on: Nov 17, 2023
 *      Author: pc
 */

#ifndef DIO_DIO_REGISTER_H_
#define DIO_DIO_REGISTER_H_

/* Define DIO register addresses for PORT, DDR, and PIN for each port */

#define DIO_PORTA (*((volatile unsigned char*)0x3B))  // PORTA register address
#define DIO_DDRA  (*((volatile unsigned char*)0x3A))   // DDRA register address
#define DIO_PINA  (*((volatile unsigned char*)0x39))    // PINA register address

#define DIO_PORTB (*((volatile unsigned char*)0x38))    // PORTB register address
#define DIO_DDRB  (*((volatile unsigned char*)0x37))    // DDRB register address
#define DIO_PINB  (*((volatile unsigned char*)0x36))    // PINB register address

#define DIO_PORTC (*((volatile unsigned char*)0x35))    // PORTC register address
#define DIO_DDRC  (*((volatile unsigned char*)0x34))    // DDRC register address
#define DIO_PINC  (*((volatile unsigned char*)0x33))    // PINC register address

#define DIO_PORTD (*((volatile unsigned char*)0x32))    // PORTD register address
#define DIO_DDRD  (*((volatile unsigned char*)0x31))    // DDRD register address
#define DIO_PIND  (*((volatile unsigned char*)0x30))    // PIND register address

#define DIO_PORTE (*((volatile unsigned char*)0x23))    // PORTE register address
#define DIO_DDRE  (*((volatile unsigned char*)0x22))    // DDRE register address
#define DIO_PINE  (*((volatile unsigned char*)0x21))    // PINE register address

#define DIO_PORTF (*((volatile unsigned char*)0x62))    // PORTF register address
#define DIO_DDRF  (*((volatile unsigned char*)0x61))    // DDRF register address
#define DIO_PINF  (*((volatile unsigned char*)0x20))    // PINF register address

#define DIO_PORTG (*((volatile unsigned char*)0x65))    // PORTG register address
#define DIO_DDRG  (*((volatile unsigned char*)0x64))    // DDRG register address
#define DIO_PING  (*((volatile unsigned char*)0x63))    // PING register address

#endif /* DIO_DIO_REGISTER_H_ */
