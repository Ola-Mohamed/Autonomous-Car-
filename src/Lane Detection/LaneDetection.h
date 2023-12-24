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

#define SPEED_FORWARD  40
#define SPEED_CHANGE1  40
#define SPEED_CHANGE   40

//int Right_Flag=0;
//int Left_Flag=0;

void LaneDetection();
void LaneDetection_init();

#endif /* LANEDETECTION_H_ */
