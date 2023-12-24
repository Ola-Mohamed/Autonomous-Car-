/*
 * main.c
 *
 *  Created on: 18 Nov 2023
 *      Author: Ayaya
 */

// Header files for FreeRTOS and hardware abstraction layer (HAL)
#include "FreeRTOS/src/FreeRTOS.h"
#include "FreeRTOS/src/semphr.h"
#include "FreeRTOS/src/queue.h"
#include "FreeRTOS/src/event_groups.h"
#include "FreeRTOS/src/task.h"
#include "HAL/IR/IR_Interface.h"
#include "HAL/DC_MOTOR/DC_Interface.h"
#include "HAL/UltraSonic/UltraSonic.h"
#include "MCAL/Timer2_interface.h"

// Tasks prototype
void LaneDetection(void * pv);
void AvoidCollision(void * pv);
void Ultrasonic(void * pv);
void AutoParking(void * pv);
void AdaptiveCC(void * pv);
void systemInit(void);

//	Create task handler
TaskHandle_t LaneDetectHandler = NULL;
TaskHandle_t AvoidHandler = NULL;
TaskHandle_t UltrasonicHandler = NULL;
TaskHandle_t AutoParkHandler = NULL;
TaskHandle_t AdaptiveHandler = NULL;


// Event group handle
EventGroupHandle_t Event_group = NULL;

// Define bits in the event group
#define AutoPark_bit	(1<<0)
#define Avoid_bit		(1<<1)

#define Enabled  1
#define Disabled	0
#define Adaptive_E_OK 0
#define Adaptive_E_NOT_OK 1

//Global variables
// Motor_Speed
unsigned char MOTOR_SPEED = 40;
typedef unsigned char Adaptive_Error_Type;
typedef unsigned char u8flag;
extern u8FuncFlag Left_Flag;
extern u8FuncFlag Right_Flag;
extern u8FuncFlag Backward_Flag;
extern u8FuncFlag Forward_Flag;

unsigned short ULTRA_1 =0;
unsigned short ULTRA_2 =0;
unsigned short ULTRA_3 =0;

unsigned char Parking_Available=0;
unsigned char ULTRASONIC_FLAG ;
unsigned char AUTO_DISTANCE = 20;
unsigned char SPECIFIC_TIME = 2000;


// Main function
int main() {
	// Create tasks with specific priorities and assign task handlers
	xTaskCreate(LaneDetection, NULL, 120, NULL, 3, &LaneDetectHandler);
	xTaskCreate(AvoidCollision, NULL, 120, NULL, 5, &AvoidHandler);
	xTaskCreate(Ultrasonic, NULL, 120, NULL, 6, &UltrasonicHandler);
	xTaskCreate(AutoParking, NULL, 120, NULL, 4, &AutoParkHandler);
	xTaskCreate(AdaptiveCC, NULL, 120, NULL, 2, &AdaptiveHandler);

	// Create event group
	Event_group = xEventGroupCreate();

	systemInit(); // Initialize the system

	vTaskStartScheduler(); // Start FreeRTOS scheduler

	while(1) {
		// Infinite loop to maintain the program running
	}

	return 0;
}

void systemInit(void)
{
	// Two IR initialization

	HAL_IR_Init(IR1_PORT, IR1_SENSOR_PIN);
	HAL_IR_Init(IR2_PORT, IR2_SENSOR_PIN);


	// DC motor initialization
	Motor1_INIT();
	Motor2_INIT();

	UltraSonic_Init();
}

// Lane Detection task using IR
void LaneDetection(void * pv)
{
	unsigned char IR1_Read =0, IR2_Read=0;
	while(1)
	{
		IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
		IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);

		if((IR1_Read == DETECTED) && (IR2_Read == DETECTED)){

			while((IR1_Read == DETECTED) && (IR2_Read == DETECTED))
			{
				IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
				IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);
				//Go Straight --> you are in your lane
				Motor2_Stop();
				Move_Forward(MOTOR_SPEED);
			}
		}
		else if ((IR1_Read == DETECTED) && (IR2_Read == NOT_DETECTED))
		{
			while((IR1_Read == DETECTED) && (IR2_Read == NOT_DETECTED))
			{
				IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
				IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);
				//Turn left
				Move_Left(MOTOR_SPEED);
				Move_Forward(MOTOR_SPEED);
			}
		}
		else if ((IR1_Read == NOT_DETECTED) && (IR2_Read == DETECTED))
		{
			while((IR1_Read == NOT_DETECTED) )
			{
				IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
				IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);
				//Turn right
				Move_Right(MOTOR_SPEED);
				Move_Forward(MOTOR_SPEED);
			}
		}
		else
		{
			while((IR1_Read == NOT_DETECTED) && (IR2_Read == NOT_DETECTED))
			{
				IR2_Read = HAL_IR_Read(IR1_PIN, IR1_SENSOR_PIN);
				IR1_Read = HAL_IR_Read(IR2_PIN, IR2_SENSOR_PIN);
				//Stay forward
				Motor2_Stop();
				Move_Forward(MOTOR_SPEED);
			}

		}
		// Delay for task execution frequency
		vTaskDelay(80);
	}
}

// Collision avoiding task using Ultrasonic
void AvoidCollision(void * pv)
{
	EventBits_t egBits3 = 0;
	while(1)
	{
		egBits3 =   xEventGroupWaitBits(Event_group,
				Avoid_bit,
				0,//  1 ->clear event enable    0-> clear events disable
				1, // 0->ORing between events if one event happen actions turn on   1-> Anding all Events must be happened
				portMAX_DELAY);

		if((egBits3&(Avoid_bit))== (Avoid_bit))
		{
			/* Motor1 will stop */
			Motor1_Stop();
			/* Motor2 will stop */
			Motor2_Stop();
			if(ULTRA_1 > 10)
			{
				xEventGroupClearBits(Event_group,Avoid_bit);
			}

		}
		// Delay for task execution frequency
		vTaskDelay(100);
	}
}



// Ultrasonic task to get ultrasonics readings
void Ultrasonic(void * pv)
{
	//EventBits_t egBits2 = 0;

	while(1)
	{
		// ---> get the 3 ultra reads
		UltraSonic_begin();
		ULTRA_1 = UltraSonic_ECHO_Distance();
		ULTRA_2 = UltraSonic_EX_INT4_Distance();
		ULTRA_3 = UltraSonic_EX_INT5_Distance();
		if(ULTRA_1 <= 10){
			xEventGroupSetBits(Event_group,Avoid_bit);
		}

		// Delay for task execution frequency
		vTaskDelay(60);
	}
}

// Auto Parking task using Ultrasonic
void AutoParking(void * pv)
{
	EventBits_t egBits = 0;
	while(1)
	{
		// Wait for specific events in the event group to trigger auto parking
		egBits =   xEventGroupWaitBits(Event_group,
				AutoPark_bit,
				0,//  1 ->clear event enable    0-> clear events disable
				1, // 0->ORing between events if one event happen actions turn on   1-> Anding all Events must be happened
				portMAX_DELAY);

		if((egBits&(AutoPark_bit))== (AutoPark_bit))
		{
			// Suspend other tasks except ultrasonic task
			vTaskSuspend(LaneDetectHandler);
			vTaskSuspend(AvoidHandler);
			vTaskSuspend(AdaptiveHandler);

			// Auto Parking code
			MOTOR_SPEED = 40;
			Move_Forward(MOTOR_SPEED);
			// --> Read ultra Right
			if(ULTRA_2 >= AUTO_DISTANCE && Parking_Available == 0 ){

				TCNT2=0;
				while(TCNT2< SPECIFIC_TIME && ULTRA_2 >= AUTO_DISTANCE)
				{
					// --> Read ultra Right

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
				// --> Read ultra Right
				while(ULTRA_2 > 10 || ULTRA_3 > 10 )
				{
					// --> Read ultra Back
					// --> Read ultra Right
					Move_Right(MOTOR_SPEED);
					Move_Backword(MOTOR_SPEED);
				}

				Motor1_Stop();
				Motor2_Stop();

				// can be edit
				// --> Read ultra Back
				// --> Read ultra Right
				while(ULTRA_2 > 10 || ULTRA_3 > 10 )
				{
					// --> Read ultra Back
					// --> Read ultra Right
					Move_Left(MOTOR_SPEED);
					Move_Backword(MOTOR_SPEED);
				}
				Motor1_Stop();
				Motor2_Stop();
				Parking_Available = 2;
			}
			else if(Parking_Available == 2)
			{
				// Done parking
				// --> Resume other tasks
				vTaskResume(LaneDetectHandler);
				vTaskResume(AvoidHandler);
				vTaskResume(AdaptiveHandler);
				// --> Clear AutoParking event
				xEventGroupClearBits(Event_group,AutoPark_bit);
			}
		}
	}
	// Delay for task execution frequency
	vTaskDelay(100);
}


// Adaptive cruise control task
void AdaptiveCC(void * pv)
{
	u8flag Enable_Flag;
	Adaptive_Error_Type Error=Adaptive_E_NOT_OK;
	Enable_Flag=Enabled;
	while(1)
	{
		if(Enable_Flag==Enabled)
		{
			if(Forward_Flag==1)
			{
				Error=Move_Forward(MOTOR_SPEED);
			}
			else if(Backward_Flag==1)
			{
				Error=Move_Backword(MOTOR_SPEED);
			}
			else if(Right_Flag==1)
			{
				Error=Move_Right(MOTOR_SPEED);
			}
			else if(Left_Flag==1)
			{
				Error=Move_Left(MOTOR_SPEED);
			}
		}
		else
		{
			//Do nothing
		}

		// Delay for task execution frequency
		vTaskDelay(70);
	}
}

