/*
 * LaneDetection.h
 *
 *  Created on: 23 Nov 2023
 *      Author: Ayaya
 */

#ifndef LANEDETECTION_H_
#define LANEDETECTION_H_

#include "HAL/IR/IR_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "HAL/DC_MOTOR/DC_Interface.h"

#define SPEED_FORWARD  80
#define SPEED_CHANGE   30

void LaneDetection();
void LaneDetection_init();

#endif /* LANEDETECTION_H_ */
