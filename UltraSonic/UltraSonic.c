/*#include "DIO_types.h"
#include "DIO_Interface.h"
#include "Timer1_interface.h"
#include "UltraSonic.h"
#include "UltraSonic_Cfg.h"
#include "Timer1_Register.h"
#include <util/delay.h>
*/
#include "../LCD/LCD_Interface.h"
#include "UltraSonic.h"
#include "UltraSonic_Cfg.h"

static u16_distance t1,t2,distance;
u8_ultra flag=0 ,ULTRA_STATE,ULTRA_POS;
static void ICU_F (void);
S_Dio ultrasonics[4]={
		{UltraSonic_PORT_tr , UltraSonic_Trig_FRONT , OUTPUT},
		{UltraSonic_PORT_tr , UltraSonic_Trig_BACK , OUTPUT},
		{UltraSonic_PORT_tr , UltraSonic_Trig_RIGHT , OUTPUT},
		{UltraSonic_PORT_tr , UltraSonic_Trig_LEFT , OUTPUT}
};


S_Dio S_ULTRA_E={UltraSonic_PORT_EC , UltraSonic_ECHO , INPUT};



ULTRA_E_ErrorType UltraSonic_Init (void)
{
	ULTRA_E_ErrorType error = ULTRA_E_OK;

	// Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
	if (ULTRA_STATUS_ERROR == ULTRA_E_NOT_OK)
	{
		// Set error to DIO_E_NOT_OK
		error = ULTRA_E_NOT_OK;
	}
	else{
		MCAL_Dio_SetPinDirection(&ultrasonics[0]);
		MCAL_Dio_SetPinDirection(&ultrasonics[1]);
		MCAL_Dio_SetPinDirection(&ultrasonics[2]);
		MCAL_Dio_SetPinDirection(&ultrasonics[3]);

		MCAL_Dio_SetPinDirection(&S_ULTRA_E);
		Timer1_ICU_SetCallBack(ICU_F);

	}
	// Return the error status
		    return error;
}
ULTRA_E_ErrorType UltraSonic_POSITION (u8_ultra ULTRA_STATE)
{

	ULTRA_E_ErrorType error = ULTRA_E_OK;

	if (ULTRA_STATUS_ERROR == ULTRA_E_NOT_OK)
	{
		error = ULTRA_E_NOT_OK;
	}
	else{
		switch(ULTRA_STATE)
		{
		case  UltraSonic_FRONT:
			ULTRA_POS=0;
			break;
		case UltraSonic_BACK:
			ULTRA_POS=1;
			break;
		case UltraSonic_RIGHT:
			ULTRA_POS=2;
			break;
		case UltraSonic_LEFT:
			ULTRA_POS=3;
			break;
		default:
			error = ULTRA_E_OK;


		}

	}
    return error;

}
ULTRA_E_ErrorType UltraSonic_begin (void)
{

		MCAL_Dio_WriteSinglePin( &(ultrasonics[ULTRA_POS]),ultrasonics[ULTRA_POS].pin_num,LOGIC_HIGH);
	ULTRA_E_ErrorType error = ULTRA_E_OK;

	// Check if ULTRA_STATUS_ERROR is not equal to ULTRA_E_NOT_OK
	if (ULTRA_STATUS_ERROR == ULTRA_E_NOT_OK)
	{
		// Set error to ULTRA_E_NOT_OK
		error = ULTRA_E_NOT_OK;
	}
	else{
		TCNT1L=0, TCNT1H=0;
		Timer1_InputCaptureEdge(RISING);
		MCAL_Dio_WriteSinglePin( &(ultrasonics[ULTRA_POS]),ultrasonics[ULTRA_POS].pin_num,LOGIC_HIGH);
		_delay_us(10);
		MCAL_Dio_WriteSinglePin( &(ultrasonics[ULTRA_POS]),ultrasonics[ULTRA_POS].pin_num,LOGIC_LOW);
		Timer1_ICU_InterruptEnable();
	}
	  // Return the error status
	    return error;
}

static void ICU_F (void)
{
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		Timer1_ICU_InterruptDisable();
		distance=(t2-t1)/58;
		flag=0;
	}
}

u16_distance UltraSonic_distance (void)
{
	return distance;
}

