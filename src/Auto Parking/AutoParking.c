/*
 * AutoParking.c
 *
 *  Created on: 22 Nov 2023
 *      Author: 20128
 */


#include "AutoParking.h"


unsigned char Parking_Available=0;
unsigned char ULTRASONIC_FLAG ;
unsigned char TIME1 ,TIME2 , TIME ,SPECIFIC_TIME ;
unsigned char DISTANCE_RIGHT, DISTANCE_FARWARD , DISTANCE_BACKWARD;

//for test
void AutoParking_Init(){

	//Timer2_Init();
	UltraSonic_Init();
	Motor1_INIT();
	Motor2_INIT();

}

void AutoParking_Task(){


	While(1){

		UltraSonic_begin();

		Move_Forward(DC_SPEED_AUTOPARKING);

		
		// --> Read ultra Right
		DISTANCE_RIGHT = UltraSonic_EX_INT4_Distance();
		
		if(DISTANCE_RIGHT >= AUTO_DISTANCE && Parking_Available == 0 ){

			TCNT2=0;
			while(TCNT2< SPECIFIC_TIME && DISTANCE_RIGHT >= AUTO_DISTANCE)
			{
				// --> Read ultra Right
				DISTANCE_RIGHT = UltraSonic_EX_INT4_Distance();
			}
			if(TCNT2 >= SPECIFIC_TIME ){

				Parking_Available=1;
			}
			else{
				//DO NOTHING
			}
		}
		else if(Parking_Available ==1){
			// --> Read ultra Back
			DISTANCE_BACKWARD = UltraSonic_EX_INT5_Distance();
			// --> Read ultra Right
			DISTANCE_RIGHT = UltraSonic_EX_INT4_Distance();
			
			while(DISTANCE_RIGHT > 10 || DISTANCE_BACKWARD > 10 )
			{
				// --> Read ultra Back
				DISTANCE_BACKWARD = UltraSonic_EX_INT5_Distance();
				// --> Read ultra Right
				DISTANCE_RIGHT = UltraSonic_EX_INT4_Distance();
				Move_Right(DC_SPEED_AUTOPARKING_Right);
				Move_Backword(DC_SPEED_AUTOPARKING);
			}

			Motor1_Stop();
			Motor2_Stop();

			
			// --> Read ultra Back
			DISTANCE_BACKWARD = UltraSonic_EX_INT5_Distance();
			// --> Read ultra Right
			DISTANCE_RIGHT = UltraSonic_EX_INT4_Distance();
			while(DISTANCE_RIGHT > 10 || DISTANCE_BACKWARD > 10 )
			{
				// --> Read ultra Back
				DISTANCE_BACKWARD = UltraSonic_EX_INT5_Distance();
				// --> Read ultra Right
				DISTANCE_RIGHT = UltraSonic_EX_INT4_Distance();
				Move_Left(DC_SPEED_AUTOPARKING_Left);
				Move_Backword(DC_SPEED_AUTOPARKING);
			}
			Motor1_Stop();
			Motor2_Stop();
			Parking_Available = 2;
		}
		else if(Parking_Available == 2)
		{
			// Done parking
			Motor1_Stop();
			Motor2_Stop();
		}
	}
}
