

#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_



#define DIO_PORTA (*((volatile unsigned char *)0x3B))
#define DIO_DDRA (*((volatile unsigned char *)0x3A))
#define DIO_PINA (*((volatile unsigned char*)0x39))

#define DIO_PORTB (*((volatile unsigned char*)0x38))
#define DIO_DDRB  (*((volatile unsigned char*)0x37))
#define DIO_PINB  (*((volatile unsigned char*)0x36))

#define DIO_PORTC (*((volatile unsigned char*)0x35))
#define DIO_DDRC  (*((volatile unsigned char*)0x34))
#define DIO_PINC  (*((volatile unsigned char*)0x33))

#define DIO_PORTD (*((volatile unsigned char*)0x32))
#define DIO_DDRD  (*((volatile unsigned char*)0x31))
#define DIO_PIND  (*((volatile unsigned char*)0x30))



#define DIO_PORTE (*((volatile unsigned char*)0x2E))
#define DIO_DDRE  (*((volatile unsigned char*)0x2D))
#define DIO_PINE  (*((volatile unsigned char*)0x2C))

#define DIO_PORTF (*((volatile unsigned char*)0x2B))
#define DIO_DDRF  (*((volatile unsigned char*)0x2A))
#define DIO_PINF  (*((volatile unsigned char*)0x29))

#define DIO_PORTG (*((volatile unsigned char*)0x28))
#define DIO_DDRG  (*((volatile unsigned char*)0x27))
#define DIO_PING  (*((volatile unsigned char*)0x26))


#endif /* DIO_REGISTERS_H_ */
