/*
 * LCD_Types.h
 *
 *  Created on: 26 Oct 2023
 *      Author: Ayaya
 */

#ifndef LCD_TYPES_H_
#define LCD_TYPES_H_

/* Types used in LCD driver */

/* Error type */
typedef enum
{
	E_OK,
	E_NOT_OK
}E_ErrorType;

typedef signed char LCD_commandType;
typedef signed char LCD_dataType;
typedef unsigned char LCD_row;
typedef unsigned char LCD_column;
typedef unsigned long int LCD_integer;
typedef const signed char* LCD_string;


#endif /* LCD_TYPES_H_ */
