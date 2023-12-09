/*
 * ADAPTIVE_CONTROL.c
 *
 *  Created on: Nov 21, 2023
 *      Author: EVA
 */

#include"ADAPTIVE_CONTROL.h"


u8flag Enable_Flag;
Adaptive_Error_Type Error=Adaptive_E_NOT_OK;
void Adaptive_Enable(void)
{
	Enable_Flag=Enabled;
}


Adaptive_Error_Type Adaptive_Set_Speed(void)
{
	if(Forward_Flag==1)
	{
		Error=Move_Forward(MAX_Speed);
	}
	else if(Backward_Flag==1)
	{
		Error=Move_Backword(MAX_Speed);
	}
	else if(Right_Flag==1)
	{
		Error=Move_Right(MAX_SPEED);
	}
	else if(Left_Flag==1)
	{
		Error=Move_Left(MAX_SPEED);
	}

		return Error;
}


void Adaptive_Disable(void)
{
	Enable_Flag=Disabled;
}
