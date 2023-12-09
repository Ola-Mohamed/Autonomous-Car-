/*
 * Servo.c
 *
 *  Created on: Nov 6, 2023
 *      Author: mosta
 */


#include "Servo.h"


void Servo_Init (void)
{
	PWM_Freq_HZ(50);
}


void Servo_Move (sint16 angle) // angle*10 ----- To get high res //
							   // angle range : -90 to 90 //
{
	sint16 r_angle=0;
	sint16 duty=0;

	if (angle>=-90 && angle<=90)
	{
		r_angle=90+angle;
		duty=50+((r_angle*50)/180); // step = 3.6°
		PWM_Duty(duty);
	}
	else
	{
		// Do Nothing
	}
}
