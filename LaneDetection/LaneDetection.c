/*
 * main.c
 *
 *  Created on: 21 Nov 2023
 *      Author: 20128
 */



#include "LaneDetection.h"


void LaneDetection_init()
{
	// Two IR initialization

	HAL_IR_Init(IR1_PORT, IR1_SENSOR_PIN);
	HAL_IR_Init(IR2_PORT, IR2_SENSOR_PIN);


	// DC motor initialization
	Motor1_INIT();
	Motor2_INIT();

	// For Test
	HAL_LED_INIT(LED1_PORT, LED1_PIN);
	HAL_LED_INIT(LED2_PORT, LED2_PIN);
	HAL_LED_INIT(LED3_PORT, LED3_PIN);
}

void LaneDetection(){

	unsigned char IR1_Read =0, IR2_Read=0;


	while(1){
		IR1_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
		IR2_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);

		if((IR1_Read == DETECTED) && (IR2_Read == DETECTED)){
			//Go Straight --> you are in your lane

			Move_Forward(SPEED_FORWARD);

			HAL_LED_ON(LED1_PORT, LED1_PIN);
			HAL_LED_OFF(LED2_PORT, LED2_PIN);
			HAL_LED_OFF(LED3_PORT, LED3_PIN);

		}
		else if ((IR1_Read == DETECTED) && (IR2_Read == NOT_DETECTED))
		{
			//Turn left
			Move_Left(SPEED_CHANGE);
			Move_Forward(SPEED_CHANGE);

			HAL_LED_ON(LED2_PORT, LED2_PIN);
			HAL_LED_OFF(LED1_PORT, LED1_PIN);
			HAL_LED_OFF(LED3_PORT, LED3_PIN);
		}
		else if ((IR1_Read == NOT_DETECTED) && (IR2_Read == DETECTED))
		{
			//Turn right
			Move_Right(SPEED_CHANGE);
			Move_Forward(SPEED_CHANGE);

			HAL_LED_ON(LED3_PORT, LED3_PIN);
			HAL_LED_OFF(LED1_PORT, LED1_PIN);
			HAL_LED_OFF(LED2_PORT, LED2_PIN);
		}
		else
		{

			Move_Forward(SPEED_FORWARD);

			HAL_LED_ON(LED1_PORT, LED1_PIN);
			HAL_LED_OFF(LED2_PORT, LED2_PIN);
			HAL_LED_OFF(LED3_PORT, LED3_PIN);
		}
	}

}
