/*
 * EX_Interrupt_Interface.h
 *
 *  Created on: Dec 10, 2023
 *      Author: mosta
 */

#ifndef MCAL_EX_INTERRUPT_EX_INTERRUPT_INTERFACE_H_
#define MCAL_EX_INTERRUPT_EX_INTERRUPT_INTERFACE_H_

#include "../../common_macros.h"
#include "../../std_types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "EX_interrupt_register.h"
#include "EX_interrupt_types.h"


void EX_Interrupt_Init(EX_Interrupt_Type EX_INT);
void EX_Interrupt_Enable(EX_Interrupt_Type EX_INT);
void EX_Interrupt_Disable(EX_Interrupt_Type EX_INT);
void EX_Interrupt_TriggerEdge(EX_Interrupt_Type EX_INT, EX_Interrupt_TriggerEdge_Type Edge);
void EX_Interrupt_SetCallBack(EX_Interrupt_Type EX_INT, void (*LocalPtr)(void) );

#endif /* MCAL_EX_INTERRUPT_EX_INTERRUPT_INTERFACE_H_ */
