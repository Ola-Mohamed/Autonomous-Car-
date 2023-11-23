#ifndef TIMER1_TIMER1_INTERFACE_H_
#define TIMER1_TIMER1_INTERFACE_H_

#include "common_macros.h"
#include "Timer1_config.h"
#include "Timer1_Private.h"
#include "Timer1_register.h"
#include "Timer1_types.h"




E__Error__Type Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler);
E__Error__Type Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode);
E__Error__Type Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode);
E__Error__Type Timer1_InputCaptureEdge(ICU_Edge_type edge);

void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);

void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);

void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);

void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);

E__Error__Type Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
E__Error__Type Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
E__Error__Type Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
E__Error__Type Timer1_ICU_SetCallBack(void(*LocalFptr)(void));

#endif /* TIMER1_TIMER1_INTERFACE_H_ */
