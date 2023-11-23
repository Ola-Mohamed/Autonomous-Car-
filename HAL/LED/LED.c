/*
 * LED.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Marii
 */

#include "LED_Interface.h"
#include "LED_Types.h"
#include "LED_cfg.h"

E_ErrorType_ HAL_LED_INIT(E_DioPort ledPORT, E_DioPin LEDPin){
	S_Dio P2 = {ledPORT, LEDPin, OUTPUT};
	E_ErrorType_ u8LocalReturn = E_NOT_OK__ ;
	u8LocalReturn = MCAL_Dio_Init(&P2);
	return u8LocalReturn;
}

E_ErrorType_ HAL_LED_ON(E_DioPort ledPORT, E_DioPin LEDPin){
	S_Dio P2 = {ledPORT, LEDPin, PIN_LOW};
	E_ErrorType_ u8LocalReturn = E_NOT_OK__;
	u8LocalReturn = MCAL_Dio_WritePin(&P2, PIN_HIGH);
	return u8LocalReturn;

}

E_ErrorType_ HAL_LED_OFF(E_DioPort ledPORT, E_DioPin LEDPin){
	S_Dio P2 = {ledPORT, LEDPin, PIN_LOW};
	E_ErrorType_ u8LocalReturn = E_NOT_OK__;
	u8LocalReturn = MCAL_Dio_WritePin(&P2, PIN_LOW);
	return u8LocalReturn;

}

E_ErrorType_ HAL_LED_TOGGLE(E_DioPort ledPORT, E_DioPin LEDPin){
	S_Dio P2 = {ledPORT, LEDPin, PIN_LOW};
	E_ErrorType_ u8LocalReturn = E_NOT_OK__;
	u8LocalReturn = MCAL_Dio_WritePin(&P2, PIN_HIGH);
	_delay_ms(time);
	u8LocalReturn = MCAL_Dio_WritePin(&P2, PIN_LOW);
	_delay_ms(time);
	return u8LocalReturn;

}




