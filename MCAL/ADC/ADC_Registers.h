/*
 * ADC_Registers.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef MCAL_ADC_ADC_REGISTERS_H_
#define MCAL_ADC_ADC_REGISTERS_H_


#define ACSR    (*(volatile unsigned char *)0x7A)



#define ADMUX   (*(volatile unsigned char *)0x7C)
#define ADCSRA  (*(volatile unsigned char *)0x7A)
#define ADCSRB  (*(volatile unsigned char *)0x7B)
#define ADCH    (*(volatile unsigned char *)0x79)
#define ADCL    (*(volatile unsigned char *)0x78)



#define ADC     (*(volatile unsigned short *)0x24)


/*****************************************************/

//ADMUX
#define REFS1 7
#define REFS0 6
#define ADLAR 5


//ADCSRA
#define ADEN  7
#define ADSC  6
#define ADFR 5
#define ADIF  4
#define ADIE  3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0


#endif /* MCAL_ADC_ADC_REGISTERS_H_ */
