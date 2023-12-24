/*
 * NightMode.c
 *
 *  Created on: 22 Nov 2023
 *      Author: Ola
 */

#include "NightMode.h"

/***********************************************Functions***********************************************/
void Night_Mode_init(){
	
	MCAL_ADC_INIT();
	HAL_LDR_Init();

	HAL_LED_INIT(PORTA_ID,PIN0_ID);
	HAL_LED_INIT(PORTA_ID,PIN1_ID);
	HAL_LED_INIT(PORTA_ID,PIN2_ID);

	Motor1_INIT();
	Motor2_INIT();
}
/**********************************************************************************************************/

NightMode_Error_Type Night_Mode_Task(){
	
	// Call the HAL_LDR_Read function to read the LDR percentage
		result = HAL_LDR_Read(&LDR_Percentage);

		if (result == LDR_E_OK){
			if(LDR_Percentage <= LDR_Value){


				Move_Forward(Speed_limit);

				HAL_LED_ON(PORTA_ID,PIN0_ID);
				HAL_LED_ON(PORTA_ID,PIN1_ID);
				HAL_LED_ON(PORTA_ID,PIN2_ID);
				//speed
              Error = NightMode_E_OK;

			}
			else{

				HAL_LED_OFF(PORTA_ID,PIN0_ID);
				HAL_LED_OFF(PORTA_ID,PIN1_ID);
				HAL_LED_OFF(PORTA_ID,PIN2_ID);

				Move_Forward(Regular_Speed)
			}
		}
		
		return  Error;
}