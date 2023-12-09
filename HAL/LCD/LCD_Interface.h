/*
 * LCD_Interface.h
 *
 *  Created on: 26 Oct 2023
 *      Author: Ayaya
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#include "LCD_Registers.h"
#include "LCD_Types.h"
#include <util/delay.h>

/* Function set */
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
/* Display on/off control */
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
/* Display clear */
#define CLEAR_COMMAND 0x01
/* Entry mode set */
#define SHIFT_CURSOR_RIGHT 0x06
/* Set cursor location at position 0 */
#define SET_CURSOR_LOCATION 0x80

#define SHIFT_LEFT_LCD 0x18
#define SHIFT_RIGHT_LCD 0x1c

#define row1col1	0x40
#define row2col1	0x14
#define row3col1	0x54


/* Function to initialize the LCD */
E_ErrorType HAL_LCD_init();

/* Function to send command to LCD */
E_ErrorType HAL_LCD_sendCommand(LCD_commandType command);

/* Function to display a character on the LCD */
E_ErrorType HAL_LCD_sendCharacter(LCD_dataType data);

/* Function to display a string on the LCD */
E_ErrorType HAL_LCD_sendString(LCD_string str);

/* Function to clear the LCD screen */
E_ErrorType HAL_LCD_clearScreen();

/* Function to display a string on a certain row and column on the LCD screen */
E_ErrorType HAL_LCD_displaystringRowColumn(LCD_string str, LCD_row row, LCD_column col);

/* Function to move the cursor to a certain row and column on the LCD screen */
E_ErrorType HAL_LCD_goToRowColumn(LCD_row row, LCD_column col);

/* Function to convert an integer to string */
E_ErrorType HAL_LCD_integerToString(LCD_integer num);

/* Function to display an integer on a certain row and column on the LCD screen */
E_ErrorType HAL_LCD_displayIntegerRowColumn(LCD_integer num, LCD_row row, LCD_column col);


#endif /* LCD_INTERFACE_H_ */
