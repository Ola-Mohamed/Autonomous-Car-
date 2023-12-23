/*
 * UltraSonic.h
 *
 *  Created on: Dec 10, 2023
 *      Author: mosta
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../../std_types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer3/Timer3_Interface.h"
#include "../../MCAL/EX_Interrupt/EX_Interrupt_Interface.h"
#include <util/delay.h>
#include "UltraSonic_Cfg.h"


void UltraSonic_Init(void);
void UltraSonic_begin(void);

uint16 UltraSonic_ECHO_Distance (void);
uint16 UltraSonic_EX_INT4_Distance (void);
uint16 UltraSonic_EX_INT5_Distance (void);
uint16 UltraSonic_EX_INT6_Distance (void);

#endif /* ULTRASONIC_H_ */
