
#include "ADC_interface.h"

E_ERROR_TYPE MCAL_ADC_INIT(){
	
	E_ERROR_TYPE u8LocalError = E_OKAY;
	
	if(ADC_STATUS_ERROR!=E_OKAY){

	}
	else{
		S_Dio ADC_interface = {ADC_PORT, ADC_USED_CHANNELS, INPUT};
		// Set all used ADC channels as inputs
		MCAL_Dio_Init(&ADC_interface);
		ADMUX=0;
		
		switch(vref){
		case ADC_AREF:
			CLEAR_BIT(ADMUX, REFS1);
			CLEAR_BIT(ADMUX, REFS0);
			break;
			
		case ADC_VCC:
			CLEAR_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
			break;
			
		case ADC_V256:
			SET_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
			break;
		}

	 // Clear ADCSRA and set ADC clock prescaler
        ADCSRA &= 0xF8;
        scaler &= 0x07;
        ADCSRA |= scaler;
        
        // Enable ADC
        SET_BIT(ADCSRA, ADEN);
        
        // Clear ADLAR to select right adjust result
        CLEAR_BIT(ADMUX, ADLAR);
	}
	return u8LocalError;
}

u16 MCAL_ADC_READ(ADC_Channel_Type channel){

	ADMUX&=0XE0;
	ADMUX|=channel;
	SET_BIT(ADCSRA,ADSC);
	while(GET_BIT(ADCSRA,ADSC));

	return ADC;
}
