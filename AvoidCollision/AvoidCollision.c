/*
 * AvoidCollision.c
 *
 *  Created on: Nov 24, 2023
 *      Author: dell
 */
#include "Avoid.h"
void AvoidCollision(void)
{
	uint16 distance=0 ;
	/* Ultrasonic begin */
	UltraSonic_begin ();
	/* calculate the distance */
	distance=UltraSonic_distance();
	/* Go in LCD to row 1 and column 10 */
	HAL_LCD_goToRowColumn(1,10);
	/* Display distance on LCD */
	HAL_LCD_integerToString(distance);
	//_delay_ms(500);
	/* Check distance if equal 5cm or less than 5cm */
	if(distance== 5 || distance <5)
	{
		/* Motor1 will stop */
		Motor1_Stop();
		/* Motor2 will stop */
		Motor2_Stop();
	}
	/* If distance is greater than 5 cm */
	else
	{
		/* Move motor 1 forward */
		Move_Forward(100);
		/* move motor 2 right */
		Move_Right(100);
	}
}
