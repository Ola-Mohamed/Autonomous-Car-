/*
 * DC_Types.h
 *
 *  Created on: Nov 20, 2023
 *      Author: EVA
 */

#ifndef DC_MOTOR_DC_TYPES_H_
#define DC_MOTOR_DC_TYPES_H_

typedef unsigned char u8DC_speed;
typedef unsigned char DC_E_ErrorType;

#define DC_E_OK       0                   // DIO operation successful
#define DC_E_NOT_OK   1                   // DIO operation not successful

#define MAX_SPEED 100
#define MAX_TICK  255

#endif /* DC_MOTOR_DC_TYPES_H_ */
