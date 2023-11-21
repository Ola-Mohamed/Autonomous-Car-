/*
 * DC_Program.c
 *
 *  Created on: Nov 20, 2023
 *      Author: EVA
 */


#include "DC_Interface.h"
#include "../DIO/DIO_Interface.h"
#include "../TIMER0/Time0_Interface.h"
#include "../LCD/lcd.h"


S_Dio DC_Motor1;
S_Dio DC_Motor2;
DC_E_ErrorType Error_DC1= DC_E_OK;
DC_E_ErrorType Error_DC2= DC_E_OK;
u8DC_speed Motor_Speed;


DC_E_ErrorType Motor1_INIT(void)
{

	DC_Motor1.port_num = DC_Port;
	DC_Motor1.pin_num = (DC1_TERMINAL1 | DC1_TERMINAL2);
	DC_Motor1.Direction = OUTPUT;
	Error_DC1 =MCAL_Dio_Init(&DC_Motor1);
	return Error_DC1;
}

DC_E_ErrorType Motor2_INIT(void)
{

	DC_Motor2.port_num = DC_Port;
	DC_Motor2.pin_num = (DC2_TERMINAL1 | DC2_TERMINAL2);
	DC_Motor2.Direction = OUTPUT;
	MCAL_Dio_Init(&DC_Motor2);
	Error_DC2 =MCAL_Dio_Init(&DC_Motor1);
	return Error_DC1;


}

DC_E_ErrorType Move_Forward(u8DC_speed speed)
{


	if(speed > MAX_SPEED)
	{
		Error_DC1 = DC_E_NOT_OK;
	}
	else
	{
		Motor_Speed = (speed * MAX_TICK) / MAX_SPEED;
		MCAL_Timer0_Init(Prescaler_1024,0,Motor_Speed);
		MCAL_Dio_WriteSinglePin(&DC_Motor1,DC1_TERMINAL1,LOGIC_HIGH);
		MCAL_Dio_WriteSinglePin(&DC_Motor1,DC1_TERMINAL2,LOGIC_LOW);
	}




	return Error_DC1;
}

DC_E_ErrorType Move_Backword(u8DC_speed speed)
{

	if(speed > MAX_SPEED)
	{
		Error_DC1 = DC_E_NOT_OK;
	}
	else
	{
		Motor_Speed = (speed * MAX_TICK) / MAX_SPEED;
		MCAL_Timer0_Init(Prescaler_1024,0,Motor_Speed);
		MCAL_Dio_WriteSinglePin(&DC_Motor1,DC1_TERMINAL1,LOGIC_LOW);
		MCAL_Dio_WriteSinglePin(&DC_Motor1,DC1_TERMINAL2,LOGIC_HIGH);
	}




	return Error_DC1;
}

DC_E_ErrorType Move_Right(u8DC_speed speed)
{

	if(speed > MAX_SPEED)
	{
		Error_DC2 = DC_E_NOT_OK;
	}
	else
	{
		Motor_Speed = (speed * MAX_TICK) / MAX_SPEED;
		MCAL_Timer0_Init(Prescaler_1024,0,Motor_Speed);

		Error_DC2=MCAL_Dio_WriteSinglePin(&DC_Motor2,DC2_TERMINAL1,1);
		if(Error_DC2==DC_E_OK)
		{
			MCAL_Dio_WriteSinglePin(&DC_Motor2,DC2_TERMINAL2,0);
		}
		else
		{
			Error_DC2=DC_E_NOT_OK;
		}
	}



	return Error_DC2;


}


DC_E_ErrorType Move_Left(u8DC_speed speed)
{

	if(speed > MAX_SPEED)
	{
		Error_DC2 = DC_E_NOT_OK;
	}
	else
	{
		Motor_Speed = (speed * MAX_TICK) / MAX_SPEED;
		MCAL_Timer0_Init(Prescaler_1024,0,Motor_Speed);

		Error_DC2=MCAL_Dio_WriteSinglePin(&DC_Motor2,DC2_TERMINAL1,0);
		if(Error_DC2==DC_E_OK)
		{
			MCAL_Dio_WriteSinglePin(&DC_Motor2,DC2_TERMINAL2,1);
		}
		else
		{
			Error_DC2=DC_E_NOT_OK;
		}

	}


	return Error_DC2;
}


DC_E_ErrorType Motor2_Stop(void)
{
	if(Error_DC2==MCAL_Dio_WriteSinglePin(&DC_Motor2,DC2_TERMINAL2,0))
	{
		MCAL_Dio_WriteSinglePin(&DC_Motor2,DC2_TERMINAL1,0);
	}
	else
	{
		Error_DC2=DC_E_NOT_OK;
	}
	return Error_DC2;

}

DC_E_ErrorType Motor1_Stop(void)
{
	if(Error_DC2==MCAL_Dio_WriteSinglePin(&DC_Motor1,DC1_TERMINAL2,0))
	{
		MCAL_Dio_WriteSinglePin(&DC_Motor1,DC1_TERMINAL1,0);
	}
	else
	{
		Error_DC1=DC_E_NOT_OK;
	}
	return Error_DC1;
}



