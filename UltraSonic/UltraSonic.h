
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../../std_types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer1/Timer1_Interface.h"
#include <util/delay.h>
#include "UltraSonic_Cfg.h"
typedef unsigned char ULTRA_E_ErrorType;     // Type for DIO error
typedef unsigned short        u16_distance;         /*      -32768 .. +32767           */
typedef unsigned char        u8_ultra;
#define ULTRA_E_OK       0                   // ULTRA operation successful
#define ULTRA_E_NOT_OK   1                   // ULTRA operation not successful
#define ULTRA_STATUS_ERROR ULTRA_E_OK            // ULTRA status error

ULTRA_E_ErrorType UltraSonic_Init (void);
ULTRA_E_ErrorType UltraSonic_begin (void);
ULTRA_E_ErrorType UltraSonic_POSITION (u8_ultra ULTRA_STATE);

u16_distance UltraSonic_distance (void);



#endif /* ULTRASONIC_H_ */
