/*
 * UltraSonic_Cfg.h
 *
 * Created: 8/7/2023 4:54:48 AM
 *  Author: mosta
 */


#ifndef ULTRASONIC_CFG_H_
#define ULTRASONIC_CFG_H_

#define UltraSonic_PORT_EC	PORTD_ID

#define UltraSonic_ECHO		PIN4_ID

#define  UltraSonic_PORT_tr PORTA_ID

#define UltraSonic_Trig_FRONT	PIN0_ID
#define UltraSonic_Trig_BACK	PIN1_ID
#define UltraSonic_Trig_RIGHT	PIN2_ID
#define UltraSonic_Trig_LEFT	PIN3_ID


typedef enum
{
	UltraSonic_FRONT,
	 UltraSonic_BACK,
	 UltraSonic_RIGHT,
	 UltraSonic_LEFT,

} ULTRA_NUM;


#endif /* ULTRASONIC_CFG_H_ */
