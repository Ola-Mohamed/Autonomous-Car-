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

}

void LaneDetection(){

	unsigned char IR1_Read =0, IR2_Read=0;

	while(1){
		IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
		IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);

		if((IR1_Read == DETECTED) && (IR2_Read == DETECTED)){
			while((IR1_Read == DETECTED) && (IR2_Read == DETECTED))
			{
				IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
				IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);
				//Go Straight --> you are in your lane
				Motor2_Stop();
				Move_Forward(SPEED_FORWARD);
			}
		}
		else if ((IR1_Read == DETECTED) && (IR2_Read == NOT_DETECTED))
		{
			while((IR1_Read == DETECTED) && (IR2_Read == NOT_DETECTED))
			{
				IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
				IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);
				//Turn left
				Move_Left(SPEED_CHANGE);
				Move_Forward(SPEED_CHANGE1);
			}
		}
		else if ((IR1_Read == NOT_DETECTED) && (IR2_Read == DETECTED))
		{
			while((IR1_Read == NOT_DETECTED) )
			{
				IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
				IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);
				//Turn right
				Move_Right(SPEED_CHANGE);
				Move_Forward(SPEED_CHANGE1);
			}
		}
		else
		{
			while((IR1_Read == NOT_DETECTED) && (IR2_Read == NOT_DETECTED))
			{
				IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
				IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);
				//Stay forward
				Motor2_Stop();
				Move_Forward(SPEED_FORWARD);
			}

		}
	}

}
