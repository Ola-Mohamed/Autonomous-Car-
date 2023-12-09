/*
 * Timer1_Register.h
 *
 *  Created on: Nov 17, 2023
 *      Author: pc
 */

#ifndef TIMER1_TIMER1_REGISTER_H_
#define TIMER1_TIMER1_REGISTER_H_

#define ICR1     (*(volatile unsigned short*)0x46)
#define OCR1B    (*(volatile unsigned char*)0x48)
#define OCR1A    (*(volatile unsigned char*)0x4A)
#define ICR1L     (*(volatile unsigned char*)0x46)
#define ICR1H     (*(volatile unsigned char*)0x47)
#define OCR1BL    (*(volatile unsigned char*)0x48)
#define OCR1BH    (*(volatile unsigned char*)0x49)
#define OCR1AL    (*(volatile unsigned char*)0x4A)
#define OCR1AH    (*(volatile unsigned char*)0x4B)
#define TCNT1L    (*(volatile unsigned char*)0x4C)
#define TCNT1H    (*(volatile unsigned char*)0x4D)
#define TCCR1B    (*(volatile unsigned char*)0x4E)
#define TCCR1A    (*(volatile unsigned char*)0x4F)
#define TCCR1C 	  (*(volatile unsigned char*)0x7A)
#define OCR1CH   (*(volatile unsigned char*)0x79)
#define OCR1CL   (*(volatile unsigned char*)0x78)

#define SFIOR     (*(volatile unsigned char*)0x40)
#define OSCCAL    (*(volatile unsigned char*)0x6F)
#define TIMSK     (*(volatile unsigned char*)0x57)
#define ETIMSK    (*(volatile unsigned char*)0x7D)
#define TIFR	  (*(volatile unsigned char*)0x56)
#define ETIFR	  (*(volatile unsigned char*)0x7C)

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0
/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define COM1C1  3
#define COM1C0  2
#define WGM11   1
#define WGM10   0
/* TCCR1B */
#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/* TCCR1C */
#define FOC1A 7
#define FOC1B 6
#define FOC1C 5

/*ETIMSK Register
 * 	Extended Timer/Counter Interrupt Mask Register*/
#define TICIE3 5
#define OCIE3A 4
#define OCIE3B 3
#define TOIE3  2
#define OCIE3C 1
#define OCIE1C 0


/* TIFR Register */
#define ICF1  5
#define OCF1A 4
#define OCF1B 3
#define TOV1  2

/* ETIFR Register */
#define OCF1C  0



/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect		__vector_11
/* Timer/Counter1 Compare Match A */
#define TIMER1_OCA_vect		__vector_13
/* Timer/Counter1 Compare Match B */
#define TIMER1_OCB_vect		__vector_14
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_15


#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)


#endif /* TIMER1_TIMER1_REGISTER_H_ */
