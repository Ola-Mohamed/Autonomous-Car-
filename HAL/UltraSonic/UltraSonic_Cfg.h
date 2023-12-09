/*
 * UltraSonic_Cfg.h
 *
 * Created: 8/7/2023 4:54:48 AM
 *  Author: mosta
 */


#ifndef ULTRASONIC_CFG_H_
#define ULTRASONIC_CFG_H_

#define UltraSonic_PORT_EC	PORTE_ID

#define UltraSonic_ECHO		PIN7_ID

#define  UltraSonic_PORT_tr PORTD_ID

#define UltraSonic_Trig_FRONT	PIN0_ID
#define UltraSonic_Trig_RIGHT	PIN1_ID
#define UltraSonic_Trig_LEFT	PIN2_ID



typedef enum
{
	UltraSonic_FRONT,
	 UltraSonic_RIGHT,
	 UltraSonic_LEFT

} ULTRA_NUM;


typedef enum
{
	Transistor_Front,
	Transistor_Right,
	Transistor_Left

}Select_Transistor;


#endif /* ULTRASONIC_CFG_H_ */
