/*
 * LED_Interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Marii
 */

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_

#include "LED_Registers.h"
#include "LED_cfg.h"
#include "LED_private.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "LED_Types.h"



E_ErrorType_ HAL_LED_INIT(E_DioPort ledPORT, E_DioPin LEDPin);
E_ErrorType_ HAL_LED_ON(E_DioPort port, E_DioPin pin);
E_ErrorType_ HAL_LED_OFF(E_DioPort ledPORT, E_DioPin LEDPin);
E_ErrorType_ HAL_LED_TOGGLE(E_DioPort ledPORT, E_DioPin LEDPin);
#endif /* LED_LED_INTERFACE_H_ */
