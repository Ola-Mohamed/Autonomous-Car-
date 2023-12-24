/*
 * RTOS_main.h
 *
 *  Created on: 24 Dec 2023
 *      Author: Ayaya
 */

#ifndef RTOS_MAIN_H_
#define RTOS_MAIN_H_


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


#endif /* RTOS_MAIN_H_ */
