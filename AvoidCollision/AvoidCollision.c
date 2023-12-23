/*
 * AvoidCollision.c
 *
 *  Created on: Nov 24, 2023
 *      Author: dell
 */
#include "Avoid.h"




void AvoidCollision(void)
{

	/* Distance is the global variable and extern  */
	extern uint16 distance;
	/* Angle is the global variable and extern */
	extern  sint16 angle;


	/* Delay is used befor ultrasonic begin */

	/* Select the ultrasonic that will be used */

	/* Select the transistor to active ultrasonic */

	/* UltraSonic begin */
	UltraSonic_begin();
	/* Delay is used until the wave of the sound return */
	_delay_ms(50);
	/* Calculate the ultrasonic distance */
	distance=UltraSonic_ECHO_Distance();
	/* Display on LCD d1 = */
	HAL_LCD_displaystringRowColumn("d1=",1,0);
	/* Dispaly on the LCD the value of the distance */
	HAL_LCD_displayIntegerRowColumn(distance,1,3);
	/* Check if the distance of the ultrasonic is less than and equal 90 and greater than 70 and angle equal 0 */
	if((distance <=90) && (distance > 70) && (angle==0) )
	{
		Move_Forward(40);
	}
	/* Check if the distance of the ultrasonic is less than and equal 70 and greater than 50 and angle equal 0 */
	else if((distance <=70) && (distance >50)&& (angle==0) )
	{
		Move_Forward(40);
	}
	/* Check if the distance of the ultrasonic is less than and equal 50 and greater than 30 and angle equal 0 */
	else if((distance <=50) && (distance >30) && (angle==0) )
	{
		Move_Forward(40);
	}
	/* Check if the distance of the ultrasonic is less than and equal 30 and greater than 10 and angle equal 0 */
	else if((distance <=30) && (distance >10)&& (angle==0) )
	{
		Move_Forward(40);
	}
	/* Check if the distance of the ultrasonic is less than and equal 10 and angle equal 0 */
	else if(( distance<=10) && (angle == 0) )
	{
		/* Motor1 will stop */
		Motor1_Stop();
		/* Motor2 will stop */
		Motor2_Stop();
		/* Servo angle is 90 */
		Servo_Move(90);
		/* angle is 90 */
		angle =90;
		/* Display on the LCD distance<10 and angle =0 */
		HAL_LCD_displaystringRowColumn("                    ",2,0);
		HAL_LCD_displaystringRowColumn("distance<10 and ang=0",2,0);

	}
		/* Check if the distance of the ultrasonic is  greater than and equal 20 and angle equal 90 */
		else if((distance>=20) && (angle == 90))
		{
			/* Call function move system 1 */
			Move_System1();
			/* Display on the LCD servo right continue */
			HAL_LCD_displaystringRowColumn("                      ",2,0);
			HAL_LCD_displaystringRowColumn("Servo right continue",2,0);
		}
		/* Check if the distance of the Ultrasonic is less than and 20 and angle equal 90 */
		else if((distance<20) &&  (angle == 90))
		{
			/* Servo angle is -90 */
			Servo_Move(-90);
			/* Angle is -90 */
			angle=-90;
			/* Motors will be stop */
			Motor1_Stop();
			Motor2_Stop();
			/* Display on the LCD servo right stop */
			HAL_LCD_displaystringRowColumn("                    ",2,0);
			HAL_LCD_displaystringRowColumn("Servo right stop",2,0);
		}
		/* Check if the distance of the Ultrasonic is less than and 20 and angle equal - 90 */
		else if((distance>=20) &&  (angle == -90))
		{
			/* Call function move system 1 */
			Move_System2();
			/* Display on the LCD servo left continue */
			HAL_LCD_displaystringRowColumn("                     ",3,0);
			HAL_LCD_displaystringRowColumn("Servo Left Continue",3,0);
		}
	/* if any conditions is not done the else will be done */
		else
		{
			Motor1_Stop();
			Motor2_Stop();
			HAL_LCD_displaystringRowColumn("                     ",3,0);
			HAL_LCD_displaystringRowColumn("Motors stop",3,0);
		}


}
