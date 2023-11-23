/*
 * ADC_CFG.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

#include"ADC_TYPES.h"

static ADC_Vref_Type vref = ADC_VCC;
static ADC_Scaler_Type scaler = ADC_SCALER_64;

#define ADC_PORT PORTA_ID


//Put here all the ADC channel that you intend to use in your application
#define ADC_USED_CHANNELS PIN1_ID|PIN0_ID


#endif /* MCAL_ADC_ADC_CFG_H_ */
