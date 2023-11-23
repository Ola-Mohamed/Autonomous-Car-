/*
 * DIO_Types.h
 *
 *  Created on: Nov 17, 2023
 *      Author: pc
 */

#ifndef DIO_DIO_TYPES_H_
#define DIO_DIO_TYPES_H_

/* Data types used in the DIO module */

typedef unsigned char u8PinNumber;         // Type for pin number
typedef unsigned char u8PortID;            // Type for port ID
typedef unsigned char u8PinID;             // Type for pin ID
typedef unsigned char u8Direction;         // Type for pin direction
typedef unsigned char u8PortValue;         // Type for port value
typedef unsigned char u8PinValue;          // Type for pin value
typedef unsigned char DIO_E_ErrorType;     // Type for DIO error
typedef unsigned char u8RegisterValue;     // Type for register value

typedef unsigned char boolean;              // Type for boolean

/* Boolean Values */

#define DIO_E_OK       0                   // DIO operation successful
#define DIO_E_NOT_OK   1                   // DIO operation not successful

#define PORT_HIGH    0xFF                   // Value for setting a port to high
#define PORT_LOW     0x00                   // Value for setting a port to low

#define PIN_LOW  0x00                        // Value for setting a pin to low
#define PIN_HIGH 0xFF                        // Value for setting a pin to high

#define LOGIC_HIGH 1                         // Logical high value
#define LOGIC_LOW  0                         // Logical low value

#define OUTPUT 0xFF                          // Output direction value
#define INPUT 0x00                           // Input direction value

#define DIO_INITIALIZED 1                    // DIO module initialized
#define DIO_NOTINITIALIZED 0                 // DIO module not initialized

#define DIO_STATUS_ERROR DIO_E_OK            // DIO status error

#define DIO_CONFIGURED_PORTS    7            // Number of configured ports
#define DIO_CONFIGURED_PINS     8            // Number of configured pins

#define NULL_PTR    ((void*)0)              // Null pointer

/* Enumeration for DIO port IDs */
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5
#define PORTG 6

#define PIN0 0x01
#define PIN1 0x02
#define PIN2 0x04
#define PIN3 0x08
#define PIN4 0x10
#define PIN5 0x20
#define PIN6 0x40
#define PIN7 0x80

typedef enum
{
	PORTA_ID=0,
	PORTB_ID,
	PORTC_ID,
	PORTD_ID,
	PORTE_ID,
	PORTF_ID,
	PORTG_ID
} E_DioPort;

/* Enumeration for DIO pin IDs */

typedef enum
{
	PIN0_ID = 0x01,
	PIN1_ID = 0x02,
	PIN2_ID = 0x04,
	PIN3_ID = 0x08,
	PIN4_ID = 0x10,
	PIN5_ID = 0x20,
	PIN6_ID = 0x40,
	PIN7_ID = 0x80,
} E_DioPin;

/* Structure for DIO configuration */

typedef struct
{
    E_DioPort port_num;
    E_DioPin  pin_num;
    u8Direction Direction;
} S_Dio;

#endif /* DIO_DIO_TYPES_H_ */
