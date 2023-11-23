/*
 * ADC_TYPES.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef MCAL_ADC_ADC_TYPES_H_
#define MCAL_ADC_ADC_TYPES_H_


typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned long u32;
typedef signed long s32;

typedef unsigned long long u64;
typedef signed long long s64;

typedef float f32;

typedef enum{
	FALSE_0= 0,
	TRUE_1= 1
}bool_t;

typedef enum{
	E_NOT_OKAY,
	E_OKAY

}E_ERROR_TYPE;

typedef enum{
	ADC_AREF,
	ADC_VCC,
	ADC_V256

}ADC_Vref_Type;



typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128

}ADC_Scaler_Type;

typedef enum{
	CH0=0,
	CH1,
	CH2,
	CH3,
	CH4,
	CH5,
	CH6,
	CH7
}ADC_Channel_Type;

#define ADC_STATUS_ERROR E_OKAY

#endif /* MCAL_ADC_ADC_TYPES_H_ */
