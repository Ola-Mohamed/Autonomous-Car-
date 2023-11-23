
#include "Timer1_Interface.h"

/*************************Pointer to functions to be assigned to ISR*********************************/

static void (*Timer1_OVF_Fptr) (void)=NULL_PTR;
static void (*Timer1_OCA_Fptr) (void)=NULL_PTR;
static void (*Timer1_OCB_Fptr) (void)=NULL_PTR;
static void (*Timer1_ICU_Fptr) (void)=NULL_PTR;
/******************************************************************************************/

E__Error__Type Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler)
{
	E__Error__Type localreturn=TIMER1_E_OK;
	switch (mode)
	{
	case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
	case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

	case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

	case TIMER1_FASTPWM_FF_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}

	TCCR1B&=0XF8;
	TCCR1B|=scaler;

	return localreturn;
}
E__Error__Type Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
	E__Error__Type localreturn=TIMER1_E_OK;
	switch (oc1a_mode)
	{
	case OCRA_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
	case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
	case OCRA_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
	return localreturn;
}
E__Error__Type Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
	E__Error__Type localreturn=TIMER1_E_OK;
	switch (oc1b_mode)
	{
	case OCRB_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
	case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
	case OCRB_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
	return localreturn;
}
E__Error__Type Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	E__Error__Type localreturn=TIMER1_E_OK;
	if(edge==RISING)
		SET_BIT(TCCR1B,ICES1);

	else if(edge==FALLING)
		CLEAR_BIT(TCCR1B,ICES1);

	return localreturn;
}


/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}

/*********************************Timer 1 Call Back functions*****************************************/

E__Error__Type Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	E__Error__Type localreturn=TIMER1_E_NOT_OK;

	if (LocalFptr==NULL_PTR)
	{
		localreturn=TIMER1_E_NULL_PTR;
	}
	else
	{
		Timer1_OVF_Fptr=LocalFptr;
		localreturn=TIMER1_E_OK;
	}
	return localreturn;
}
E__Error__Type Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	E__Error__Type localreturn=TIMER1_E_NOT_OK;

	if (LocalFptr==NULL_PTR)
	{
		localreturn=TIMER1_E_NULL_PTR;
	}
	else
	{
		Timer1_OCA_Fptr=LocalFptr;
		localreturn=TIMER1_E_OK;
	}
	return localreturn;
}
E__Error__Type Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	E__Error__Type localreturn=TIMER1_E_NOT_OK;

	if (LocalFptr==NULL_PTR)
	{
		localreturn=TIMER1_E_NULL_PTR;
	}
	else
	{
		Timer1_OCB_Fptr=LocalFptr;
		localreturn=TIMER1_E_OK;
	}
	return localreturn;
}
E__Error__Type Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	E__Error__Type localreturn=TIMER1_E_NOT_OK;

	if (LocalFptr==NULL_PTR)
	{
		localreturn=TIMER1_E_NULL_PTR;
	}
	else
	{
		Timer1_ICU_Fptr=LocalFptr;
		localreturn=TIMER1_E_OK;
	}
	return localreturn;
}

/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=NULL_PTR)
	{
		Timer1_OVF_Fptr();
	}
}
ISR(TIMER1_OCA_vect)
{
	if(Timer1_OCA_Fptr!=NULL_PTR)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_OCB_vect)
{
	if(Timer1_OCB_Fptr!=NULL_PTR)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_ICU_vect)
{
	if(Timer1_ICU_Fptr!=NULL_PTR)
	{
		Timer1_ICU_Fptr();
	}
}
