/*
 * ADC_interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "ADC_CFG.h"
#include "ADC_Private.h"
#include "ADC_Registers.h"
#include "ADC_TYPES.h"
#include "../DIO/DIO_interface.h"

E_ERROR_TYPE MCAL_ADC_INIT();

u16 MCAL_ADC_READ(ADC_Channel_Type channel);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
