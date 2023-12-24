/*
 * AutoParking.h
 *
 *  Created on: 22 Nov 2023
 *      Author: 20128
 */

#ifndef AUTOPARKING_H_
#define AUTOPARKING_H_

#include "DC_Interface.h"

#define AutoParking_E_OK     0
#define AutoParking_E_NOT_OK 1

#define DC_SPEED_AUTOPARKING  10

#define DC_SPEED_AUTOPARKING_Right  10

#define DC_SPEED_AUTOPARKING_Left  10

#define AUTO_DISTANCE  50


void AutoParking_Init();

void AutoParking_Task();










#endif /* AUTOPARKING_H_ */
