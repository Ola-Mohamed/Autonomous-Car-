/*
 * ADAPTIVE_CONTROL.h
 *
 *  Created on: Nov 21, 2023
 *      Author: EVA
 */

#ifndef ADAPTIVE_ADAPTIVE_CONTROL_H_
#define ADAPTIVE_ADAPTIVE_CONTROL_H_



#include "../DC_Motor/DC_Interface.h"
typedef unsigned char Adaptive_Error_Type;
typedef unsigned char u8flag;
#define Enabled  1
#define Disabled	0
#define MAX_Speed    20
#define Adaptive_E_OK 0
#define Adaptive_E_NOT_OK 1


extern u8FuncFlag Left_Flag;
extern u8FuncFlag Right_Flag;
extern u8FuncFlag Backward_Flag;
extern u8FuncFlag Forward_Flag;

void Adaptive_Enable(void);
Adaptive_Error_Type Adaptive_Set_Speed(void);
void Adaptive_Disable(void);

#endif /* ADAPTIVE_ADAPTIVE_CONTROL_H_ */
