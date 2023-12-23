/*
 * EX_Interrupt_register.h
 *
 *  Created on: Dec 10, 2023
 *      Author: mosta
 */

#ifndef MCAL_EX_INTERRUPT_EX_INTERRUPT_REGISTER_H_
#define MCAL_EX_INTERRUPT_EX_INTERRUPT_REGISTER_H_



#define EIMSK   (*(volatile unsigned char*)0x59)
#define INT0 0
#define INT1 1
#define INT2 2
#define INT3 3
#define INT4 4
#define INT5 5
#define INT6 6
#define INT7 7


#define EICRA     (*(volatile unsigned char*)0x6A)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC20 4
#define ISC21 5
#define ISC30 6
#define ISC31 7

#define EICRB    (*(volatile unsigned char*)0x5A)
#define ISC40 0
#define ISC41 1
#define ISC50 2
#define ISC51 3
#define ISC60 4
#define ISC61 5
#define ISC70 6
#define ISC71 7

#define EIFR   (*(volatile unsigned char*)0x58)
#define INTF0 0
#define INTF1 1
#define INTF2 2
#define INTF3 3
#define INTF4 4
#define INTF5 5
#define INTF6 6
#define INTF7 7


/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/* External Interrupt Request 3 */
#define INT3_vect			__vector_4
/* External Interrupt Request 4 */
#define INT4_vect			__vector_5
/* External Interrupt Request 5 */
#define INT5_vect			__vector_6
/* External Interrupt Request 6 */
#define INT6_vect			__vector_7
/* External Interrupt Request 7 */
#define INT7_vect			__vector_8

#  define BAD_vect        __vector_default

/*interrupt functions*/

# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)
# define ret()  __asm__ __volatile__ ("ret" ::)

#  define ISR_NOBLOCK    __attribute__((interrupt))
#  define ISR_NAKED      __attribute__((naked))


#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

#endif /* MCAL_EX_INTERRUPT_EX_INTERRUPT_REGISTER_H_ */
