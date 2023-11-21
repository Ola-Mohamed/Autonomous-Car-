/*
 * DIO_Interface.h
 *
 *  Created on: Nov 17, 2023
 *      Author: pc
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_

/* Include necessary header files */

#include "DIO_Register.h"        // Include DIO register addresses
#include "DIO_Types.h"           // Include DIO data types
#include "DIO_Private.h"         // Include DIO private functions
#include "DIO_Config.h"          // Include DIO configuration
#include "../Common_Files/common_macros.h"  // Include common macros

/****************************************Functions Prototypes******************************/

/* Function prototypes for DIO module initialization and configuration */

DIO_E_ErrorType MCAL_Dio_Init(S_Dio *Dio_Config);

/* Functions prototypes for setting port and pin directions */

DIO_E_ErrorType MCAL_Dio_SetPortDirection(S_Dio *Dio_ConfigPort);
DIO_E_ErrorType MCAL_Dio_SetPinDirection(S_Dio *Dio_ConfigPin);

/* Functions prototypes for reading port and pins */

DIO_E_ErrorType MCAL_Dio_ReadPort(S_Dio *Dio_ReadPort, u8PortValue *Port_Value);
DIO_E_ErrorType MCAL_Dio_ReadPins(S_Dio *Dio_ReadPin, u8PinValue *Pin_Value);

/* Function prototype for reading a single pin */

DIO_E_ErrorType MCAL_Dio_ReadSinglePin(S_Dio *Dio_ReadPin, E_DioPin Pin_Num, u8PinValue *Pin_Value);

/* Functions prototypes for writing to port and pins */

DIO_E_ErrorType MCAL_Dio_WritePort(S_Dio *Dio_WritePort, u8PortValue Port_Value);
DIO_E_ErrorType MCAL_Dio_WritePin(S_Dio *Dio_WritePin, u8PinValue Pin_value);

/* Function prototype for writing to a single pin */

DIO_E_ErrorType MCAL_Dio_WriteSinglePin(S_Dio *Dio_WritePin, E_DioPin Pin_Num, u8PinValue Pin_value);

/* Function prototype for toggling a single pin */

DIO_E_ErrorType MCAL_Dio_TogglePin(S_Dio *Dio_TogglePin, E_DioPin Pin_Num);

#endif /* DIO_DIO_INTERFACE_H_ */
