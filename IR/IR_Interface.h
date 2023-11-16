/*
 * IR_Interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef HAL_IR_IR_INTERFACE_H_
#define HAL_IR_IR_INTERFACE_H_

#include "IR_Config.h"
#include "IR_Private.h"
#include "IR_Registers.h"
#include "IR_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"



void HAL_IR_Init();

unsigned char HAL_IR_Read();


#endif /* HAL_IR_IR_INTERFACE_H_ */
