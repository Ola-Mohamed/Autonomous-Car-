/*
 * Avoid.h
 *
 *  Created on: Nov 24, 2023
 *      Author: dell
 */

#ifndef AVOID_H_
#define AVOID_H_

#include"HAL/UltraSonic/UltraSonic.h"
#include "HAL/DC_MOTOR/DC_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "ServiceAvoid/ServiceAvoid.h"


void AvoidCollision(void);

#endif /* AVOID_H_ */
