#include "LDR_Interface.h"

S_Dio S_LDR={LDR_PORT , LDR_PIN , INPUT};

E_ErrorType HAL_LDR_Init(void)
{
	E_ErrorType u8LocalReturn = E_NOT_OK;

	if (DIO_STATUS_ERROR == E_NOT_OK)
	{
		// Do Nothing
	}
	else
	{
		u8LocalReturn = MCAL_Dio_SetPinDirection(&S_LDR);
	}

	return u8LocalReturn;
}

E_ErrorType HAL_LDR_Read(char *LDR_Percentage)
{
	E_ErrorType u8LocalReturn = E_OK;

	int adc=MCAL_ADC_READ(LDR_Channel);
	int LDR_Read;

	LDR_Read=((1024-adc)*(long)100)/1024;

	*LDR_Percentage=LDR_Read;

	return u8LocalReturn;
}
