/*
 * UltraSonic.c
 *
 *  Created on: Dec 10, 2023
 *      Author: mosta
 */

#include "UltraSonic.h"

static volatile uint16 T1_ECHO, T2_ECHO, Distance_ECHO, Flag_ECHO = 0;
static volatile uint16 T1_EX_INT4, T2_EX_INT4, Distance_EX_INT4, Flag_EX_INT4 =
		0;
static volatile uint16 T1_EX_INT5, T2_EX_INT5, Distance_EX_INT5, Flag_EX_INT5 =
		0;
static volatile uint16 T1_EX_INT6, T2_EX_INT6, Distance_EX_INT6, Flag_EX_INT6 =
		0;

S_Dio ECHO = { PORTD_ID, PIN7_ID, INPUT };
S_Dio Ultrasonic_Trigger0 = { UltraSonic_Trig_FRONT_Port,
		UltraSonic_Trig_FRONT_Pin, OUTPUT };
S_Dio Ultrasonic_Trigger1 = { UltraSonic_Trig_BACK_Port,
		UltraSonic_Trig_BACK_Pin, OUTPUT };
S_Dio Ultrasonic_Trigger2 = { UltraSonic_Trig_RIGHT_Port,
		UltraSonic_Trig_RIGHT_Pin, OUTPUT };
S_Dio Ultrasonic_Trigger3 = { UltraSonic_Trig_LEFT_Port,
		UltraSonic_Trig_LEFT_Pin, OUTPUT };

static void ICU_ISR(void);
static void EX_INT4_ISR(void);
static void EX_INT5_ISR(void);
static void EX_INT6_ISR(void);

void UltraSonic_Init(void) {
	MCAL_Dio_SetPinDirection(&ECHO);
	MCAL_Dio_SetPinDirection(&Ultrasonic_Trigger0);
	MCAL_Dio_SetPinDirection(&Ultrasonic_Trigger1);
	MCAL_Dio_SetPinDirection(&Ultrasonic_Trigger2);
	MCAL_Dio_SetPinDirection(&Ultrasonic_Trigger3);
	EX_Interrupt_Init(EX_INT4);
	EX_Interrupt_Init(EX_INT5);
	EX_Interrupt_Init(EX_INT6);
	EX_Interrupt_TriggerEdge(EX_INT4, ANY_LOGIC_CHANGE);
	EX_Interrupt_TriggerEdge(EX_INT5, ANY_LOGIC_CHANGE);
	EX_Interrupt_TriggerEdge(EX_INT6, ANY_LOGIC_CHANGE);
	Timer3_ICU_SetCallBack(ICU_ISR);
	EX_Interrupt_SetCallBack(EX_INT4, EX_INT4_ISR);
	EX_Interrupt_SetCallBack(EX_INT5, EX_INT5_ISR);
	EX_Interrupt_SetCallBack(EX_INT6, EX_INT6_ISR);
}

void UltraSonic_begin(void) {
	TCNT3=0;
	Timer3_InputCaptureEdge(RISING3);
	MCAL_Dio_WriteSinglePin(&Ultrasonic_Trigger0, Ultrasonic_Trigger0.pin_num,
			LOGIC_HIGH);
	MCAL_Dio_WriteSinglePin(&Ultrasonic_Trigger1, Ultrasonic_Trigger1.pin_num,
			LOGIC_HIGH);
	MCAL_Dio_WriteSinglePin(&Ultrasonic_Trigger2, Ultrasonic_Trigger2.pin_num,
			LOGIC_HIGH);
	MCAL_Dio_WriteSinglePin(&Ultrasonic_Trigger3, Ultrasonic_Trigger3.pin_num,
			LOGIC_HIGH);
	_delay_us(10);
	MCAL_Dio_WriteSinglePin(&Ultrasonic_Trigger0, Ultrasonic_Trigger0.pin_num,
			LOGIC_LOW);
	MCAL_Dio_WriteSinglePin(&Ultrasonic_Trigger1, Ultrasonic_Trigger1.pin_num,
			LOGIC_LOW);
	MCAL_Dio_WriteSinglePin(&Ultrasonic_Trigger2, Ultrasonic_Trigger2.pin_num,
			LOGIC_LOW);
	MCAL_Dio_WriteSinglePin(&Ultrasonic_Trigger3, Ultrasonic_Trigger3.pin_num,
			LOGIC_LOW);
	Timer3_ICU_InterruptEnable();
	EX_Interrupt_Enable(EX_INT4);
	EX_Interrupt_Enable(EX_INT5);
	EX_Interrupt_Enable(EX_INT6);
}

static void ICU_ISR(void) {
	if (Flag_ECHO == 0) {
		T1_ECHO = ICR3;
		Timer3_InputCaptureEdge(FALLING3);
		Flag_ECHO = 1;
	} else if (Flag_ECHO == 1) {
		T2_ECHO = ICR3;
		Timer3_ICU_InterruptDisable();
		Distance_ECHO = ((T2_ECHO - T1_ECHO)+58) /116;
		Flag_ECHO = 0;
	}
}

static void EX_INT4_ISR(void) {
	if (Flag_EX_INT4 == 0) {
		T1_EX_INT4 = TCNT3;
		Flag_EX_INT4 = 1;
	} else if (Flag_EX_INT4 == 1) {
		T2_EX_INT4 = TCNT3;
		EX_Interrupt_Disable(EX_INT4);
		Distance_EX_INT4 = ((T2_EX_INT4 - T1_EX_INT4)+58) /116;
		Flag_EX_INT4 = 0;
	}
}

static void EX_INT5_ISR(void) {
	if (Flag_EX_INT5 == 0) {
		T1_EX_INT5 = TCNT3;
		Flag_EX_INT5 = 1;
	} else if (Flag_EX_INT5 == 1) {
		T2_EX_INT5 = TCNT3;
		EX_Interrupt_Disable(EX_INT5);
		Distance_EX_INT5 = ((T2_EX_INT5 - T1_EX_INT5)+58) / 116;
		Flag_EX_INT5 = 0;
	}
}

static void EX_INT6_ISR(void) {
	if (Flag_EX_INT6 == 0) {
		T1_EX_INT6 = TCNT3;
		Flag_EX_INT6 = 1;
	} else if (Flag_EX_INT6 == 1) {
		T2_EX_INT6 = TCNT3;
		EX_Interrupt_Disable(EX_INT6);
		Distance_EX_INT6 = ((T2_EX_INT6 - T1_EX_INT6)+58) / 116;
		Flag_EX_INT6 = 0;
	}
}

uint16 UltraSonic_ECHO_Distance (void)
{
	return Distance_ECHO;
}

uint16 UltraSonic_EX_INT4_Distance (void)
{
	return Distance_EX_INT4;
}

uint16 UltraSonic_EX_INT5_Distance (void)
{
	return Distance_EX_INT5;
}

uint16 UltraSonic_EX_INT6_Distance (void)
{
	return Distance_EX_INT6;
}
