/*
* ServiceAvoid.c

 *
 *  Created on: Dec 11, 2023
 *      Author: dell
 */


#include "ServiceAvoid.h"



void Move_System1()
{
	Move_Right(40);
	//_delay_ms(100);
	Move_Forward(40);
	_delay_ms(100);
	Move_Left(40);
	Move_Forward(40);
}

void Move_System2()
{
	Move_Left(70);
	//_delay_ms(100);
	Move_Forward(50);
	_delay_ms(100);
	Move_Right(70);
	Move_Forward(50);
}
