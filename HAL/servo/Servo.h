/*
 * Servo.h
 *
 *  Created on: Nov 6, 2023
 *      Author: mosta
 */

#ifndef SERVO_H_
#define SERVO_H_

#include"../../MCAL/Timer3/Timer3_Interface.h"



#define OPEN 90
#define CLOSE -90


void Servo_Init (void);
void Servo_Move (sint16 angle);

#endif /* SERVO_H_ */
