/*
 * Servo.c
 *
 *  Created on: Nov 6, 2023
 *      Author: mosta
 */

#include "Servo.h"

S_Dio S_Servo = { PORTE_ID, PIN4_ID, OUTPUT };

void Servo_Init(void) {
	Timer3_Init(TIMER3_FASTPWM_OCRA_TOP_MODE,TIMER3_SCALER_8);
	MCAL_Dio_SetPinDirection(&S_Servo);
	Timer3_OCRB3Mode(OCRB3_NON_INVERTING);
	PWM_Freq_HZ(50);
}

void Servo_Move(sint16 angle) // angle*10 ----- To get high res //
// angle range : -90 to 90 //
{
	sint16 r_angle = 0;
	sint16 duty = 0;

	if (angle >= -90 && angle <= 90) {
		r_angle = 90 + angle;
		duty = 50 + ((r_angle * 50) / 180); // step = 3.6°
		PWM_Duty(duty);
	} else {
		// Do Nothing
	}
}
