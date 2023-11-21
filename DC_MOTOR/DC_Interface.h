/*
 * DC_Interface.h
 *
 *  Created on: Nov 20, 2023
 *      Author: EVA
 */

#ifndef DC_MOTOR_DC_INTERFACE_H_
#define DC_MOTOR_DC_INTERFACE_H_



#include "../Common_Files/common_macros.h"

#include"DC_Types.h"
#include "DC_Config.h"

DC_E_ErrorType Motor1_INIT(void);
DC_E_ErrorType Motor2_INIT(void);
DC_E_ErrorType Move_Forward(u8DC_speed speed);
DC_E_ErrorType Move_Backword(u8DC_speed speed);
DC_E_ErrorType Move_Right(u8DC_speed speed);
DC_E_ErrorType Move_Left(u8DC_speed speed);
DC_E_ErrorType Motor1_Stop(void);
DC_E_ErrorType Motor2_Stop(void);

u8DC_speed Speed;

#endif /* DC_MOTOR_DC_INTERFACE_H_ */
