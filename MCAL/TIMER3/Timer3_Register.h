/*
 * Timer3_Register.h
 *
 *  Created on: Nov 29, 2023
 *      Author: dell
 */

#ifndef MCAL_TIMER3_TIMER3_REGISTER_H_
#define MCAL_TIMER3_TIMER3_REGISTER_H_

#define ICR3     (*(volatile unsigned short*)0x80)
#define OCR3A    (*(volatile unsigned short*)0x86)
#define OCR3B    (*(volatile unsigned short*)0x84)
#define TCNT3    (*(volatile unsigned short*)0x88)
#define ICR3L     (*(volatile unsigned char*)0x80)
#define ICR3H     (*(volatile unsigned char*)0x81)
#define OCR3BL    (*(volatile unsigned char*)0x84)
#define OCR3BH    (*(volatile unsigned char*)0x85)
#define OCR3AL    (*(volatile unsigned char*)0x86)
#define OCR3AH    (*(volatile unsigned char*)0x87)
#define TCNT3L    (*(volatile unsigned char*)0x88)
#define TCNT3H    (*(volatile unsigned char*)0x89)
#define TCCR3B    (*(volatile unsigned char*)0x8A)
#define TCCR3A   (*(volatile unsigned char*)0x8B)
#define TCCR3C 	  (*(volatile unsigned char*)0x8C)
#define OCR3CH   (*(volatile unsigned char*)0x83)
#define OCR3CL   (*(volatile unsigned char*)0x82)

#define SFIOR     (*(volatile unsigned char*)0x40)
#define OSCCAL    (*(volatile unsigned char*)0x6F)
#define ETIMSK     (*(volatile unsigned char*)0x7D)
#define  ETIFR	  (*(volatile unsigned char*)0x7C)


/* ETIMSK */
#define TICIE3  5
#define OCIE3A  4
#define OCIE3B  3
#define TOIE3   2
#define OCIE3C   1
#define OCIE1C   0
/* TCCR3A */
#define COM3A1  7
#define COM3A0  6
#define COM3B1  5
#define COM3B0  4
#define COM3C1  3
#define COM3C0  2
#define WGM31   1
#define WGM30   0
/* TCCR3B */
#define ICNC3   7
#define ICES3   6
#define WGM33   4
#define WGM32   3
#define CS32    2
#define CS31    1
#define CS30    0

/* TCCR3C */
#define FOC3A 7
#define FOC3B 6
#define FOC3C 5



/* ETIFR Register */
#define ICF3   5
#define OCF3A  4
#define OCF3B  3
#define TOV3   2
#define OCF3C  1
#define OCF1C  0





/* Timer/Counter3 Capture Event */
#define TIMER3_ICU_vect		__vector_25
/* Timer/Counter3 Compare Match A */
#define TIMER3_OCA_vect		__vector_27
/* Timer/Counter3 Compare Match B */
#define TIMER3_OCB_vect		__vector_28
/* Timer/Counter3 Compare Match C */
#define TIMER3_OCC_vect		__vector_29
/* Timer/Counter3 Overflow */
#define TIMER3_OVF_vect		__vector_30


#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)



#endif /* MCAL_TIMER3_TIMER3_REGISTER_H_ */
