#ifndef LDR_LDR_INTERFACE_H_
#define LDR_LDR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "LDR_config.h"
#include "LDR_Private.h"
#include "LDR_register.h"
#include "LDR_Types.h"


E_ErrorType HAL_LDR_Read(char *LDR_Percentage);

E_ErrorType HAL_LDR_Init(void);

#endif /* LDR_LDR_INTERFACE_H_ */
