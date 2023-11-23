
#include "Time0_Interface.h"


#define TIMER0_MODE FAST_PWM_MODE

/***************************************************************
 *
 *                         Functions Definitions
 *
 **************************************************************/

/* For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 *  (Tick Time = (prescaler / freq.) ms
 * so put initial timer counter = 0  0 --> 255 (256ms per overflow)
 * so we need timer to overflow 2 times to get a 0.5 second
 *
 * Time0 Interrupt ISR(TIMER0_OVF_vect)
 *
 */

/*TIMER0 CTC MODE
 * Description:
 * Put our desired Compare value to match, It fires an interrupt when this value is matched by timer0
 * For clock=1Mhz and prescale every count will take 1ms
 * (Tick Time = (prescaler / freq.) ms
 * so we just need 250 counts to get 250ms every compare match.
 * put initial timer counter=0 and output compare register 0 --> 255 (250ms per compare match)
 * so we need timer to make 2 compare matches to get a 0.5 second
 *
 * Time0 Comapet match mode  ISR(TIMER0_COMP_vect)
 */

/*TIMER0 FAST PWM
 *  Description:
 * Put our desired Duty Cycle to generate a PWM Signal On Pin PB3
 * F_PWM=(F_CPU)/(256*N) = (16^6)/(256*1024) = 61
 * Duty Cycle can be changed be update the value in The Compare Register
 */

/*TIMER0 PCP PWM
 * Description:
 * The PWM resolution for the phase correct PWM mode is fixed to eight bits. In phase correct
 * Put our desired Duty Cycle to generate a PWM Signal On Pin PB3
 * F_PWM=(F_CPU)/(256*N) = (16^6)/(256*1024) = 61
 * Duty Cycle can be changed be update the value in The Compare Register
 */

Timer0_E_ErrorType MCAL_Timer0_Init(E_Prescaler prescaler,u8CompareValue CompareValue,u8DutyCyle Duty_Cycle)
{
	Timer0_E_ErrorType error;
	if(TIMER0_STATUS_ERROR == TIMER0_E_NOT_OK)
	{
		error = TIMER0_E_NOT_OK;
	}
	else
	{
#if (TIMER0_MODE == OVER_FLOW_MODE)
		TCNT0 = 0; //To start counting from 0
		/* Configure the timer control register
		 * . Non PWM mode FOC0=1
		 * . Normal Mode WGM01=0 & WGM00=0
		 * . Normal Mode COM00=0 & COM01=0
		 * . prescaler 1024 CS00=1  CS02=1
		 * . prescaler 256  CS02=1
		 * . prescaler 64   CS00=1  CS0=1
		 * . prsecaler 8    CS00=1
		 */
		SET_BIT(TCCR0,FOC0);

		switch (prescaler)
		{
		case Prescaler_8:
			SET_BIT(TCCR0,CS00);
			break;
		case Prescaler_64:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			break;
		case Prescaler_256:
			SET_BIT(TCCR0,CS02);
			break;
		case Prescaler_1024:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS02);
			break;
		default:
			break;
		}
		//Enable Time0 Iterrupt
		SET_BIT(TIMSK,TOIE0);
#endif

#if (TIMER0_MODE == CTC_MODE)
		TCNT0 = 0;    // Set Timer initial value to 0
		OCR0  = CompareValue; // Set Compare Value

		/* Configure timer0 control register
		 * . Non PWM mode FOC0=1
		 * . CTC Mode WGM01=1 & WGM00=0
		 * . CLear OC0 on compare match
		 * . prescaler 1024 CS00=1  CS02=1
		 * . prescaler 256  CS02=1
		 * . prescaler 64   CS00=1  CS0=1
		 * . prsecaler 8    CS00=1
		 */
		SET_BIT(TCCR0,FOC0);
		SET_BIT(TCCR0,WGM01);
		//SET_BIT(TCCR0,COM01);

		switch (prescaler)
		{
		case Prescaler_8:
			SET_BIT(TCCR0,CS00);
			break;
		case Prescaler_64:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			break;
		case Prescaler_256:
			SET_BIT(TCCR0,CS02);
			break;
		case Prescaler_1024:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS02);
			break;
		default:
			break;

		}
		SET_BIT(TIMSK,OCIE0);
#endif

#if (TIMER0_MODE == FAST_PWM_MODE)
		TCNT0 = 0;
		OCR0 = Duty_Cycle;
		SET_BIT(TIMER0_PWM_PORT,TIMER0_PWM_PIN);

		/* Configure timer control register
		 * 1. Phase Correct PWM mode FOC0=0
		 * 2. Phase Correct Mode WGM00=1
		 * 3. Clear OC0 when match occurs COM01=1
		 * . prescaler 1024 CS00=1  CS02=1
		 * . prescaler 256  CS02=1
		 * . prescaler 64   CS00=1  CS0=1
		 * . prsecaler 8    CS00=1
		 */

		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,COM01);
		switch (prescaler)
		{
		case 0:
			SET_BIT(TCCR0,CS00);

			break;

		case 1:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			break;
		case 2:
			SET_BIT(TCCR0,CS02);
			break;
		case 3:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS02);

			break;
		default:

			break;
		}
#endif

#if (TIMER0_MODE == PCP_PWM_MODE)
		TCNT0 = 0;
		OCR0 = Duty_Cycle;
		SET_BIT(TIMER0_PWM_PORT,TIMER0_PWM_PIN);

		/* Configure timer control register
		 * 1. Phase Correct PWM mode FOC0=0
		 * 2. Phase Correct Mode WGM00=1
		 * 3. Clear OC0 when match occurs COM01=1
		 * . prescaler 1024 CS00=1  CS02=1
		 * . prescaler 256  CS02=1
		 * . prescaler 64   CS00=1  CS0=1
		 * . prsecaler 8    CS00=1
		 */

		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,COM01);
		switch (prescaler)
		{
		case Prescaler_8:
			SET_BIT(TCCR0,CS00);
			break;
		case Prescaler_64:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			break;
		case Prescaler_256:
			SET_BIT(TCCR0,CS02);
			break;
		case Prescaler_1024:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS02);
			break;
		default:
			break;
		}
#endif
		return error;
	}
}
