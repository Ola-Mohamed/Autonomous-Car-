/*
 * LCD_Prog.c
 *
 *  Created on: 26 Oct 2023
 *      Author: Ayaya
 */


#include "LCD_Interface.h"

#include "../../common_macros.h"
/* Function to initialize the LCD */
E_ErrorType HAL_LCD_init()
{
	E_ErrorType u8LocalReturn = E_NOT_OK;
	/* Initialize control pins as output */
	S_Dio LCD_RS_interface= {LCD_RS_PORT , LCD_RS_PIN , OUTPUT};

	u8LocalReturn = MCAL_Dio_Init(&LCD_RS_interface);
	S_Dio LCD_E_interface= {LCD_E_PORT , LCD_E_PIN , OUTPUT};

	u8LocalReturn = MCAL_Dio_Init(&LCD_E_interface);
	/* If RW is configurable */
	#if (LCD_RW_PORT != none)
		S_Dio LCD_RW_interface= {LCD_RW_PORT , LCD_RW_PIN , OUTPUT};
		u8LocalReturn = MCAL_Dio_Init(&LCD_RW_interface);
	#else
		//Do nothing
	#endif
	/* Initialize data pins as output */
	#if (LCD_DATA_BITS_MODE == 8)
		/* 8 bits mode */
		S_Dio LCD_DATA_interface= {LCD_DATA_PORT, (LCD_D0_PIN | LCD_D1_PIN | LCD_D2_PIN |LCD_D3_PIN |LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN |LCD_D7_PIN), OUTPUT};
		u8LocalReturn = MCAL_Dio_Init(&LCD_DATA_interface);
		_delay_ms(35);
		HAL_LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
		_delay_ms(40);
	#elif (LCD_DATA_BITS_MODE == 4)
		/* 4 bits mode */
		#ifdef LOWER_PORT_PINS
			/* Using upper data pins */
			S_Dio LCD_DATA_interface = {LCD_DATA_PORT, (LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN |LCD_D7_PIN), OUTPUT};
			u8LocalReturn = MCAL_Dio_Init(&LCD_DATA_interface);
		#else
			/* Using lower data pins */
			S_Dio LCD_DATA_interface = {LCD_DATA_PORT, (LCD_D0_PIN | LCD_D1_PIN | LCD_D2_PIN |LCD_D3_PIN), OUTPUT};
			u8LocalReturn = MCAL_Dio_Init(&LCD_DATA_interface);
		#endif
		_delay_ms(35);
		HAL_LCD_sendCommand(FOUR_BITS_DATA_MODE);
		HAL_LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE);
		_delay_ms(40);
	#endif

	HAL_LCD_sendCommand(CURSOR_ON);
	_delay_ms(40);
	HAL_LCD_sendCommand(CLEAR_COMMAND);
	_delay_ms(2);
	HAL_LCD_sendCommand(SHIFT_CURSOR_RIGHT);

	return u8LocalReturn;
}

/* Function to send command to LCD */
E_ErrorType HAL_LCD_sendCommand(LCD_commandType command)
{
	E_ErrorType u8LocalReturn = E_NOT_OK;
	S_Dio LCD_RS_interface = {LCD_RS_PORT , LCD_RS_PIN , PIN_LOW};
	u8LocalReturn = MCAL_Dio_WritePin(&LCD_RS_interface, PIN_LOW);
	_delay_ms(1);
	/* If RW is configurable */
	#if (LCD_RW_PORT != none)
		S_Dio LCD_RW_interface = {LCD_Rw_PORT , LCD_Rw_PIN , PIN_LOW};
		u8LocalReturn = MCAL_Dio_WritePin(&LCD_RW_interface, PIN_LOW);
	#else
		//Do nothing
	#endif

	S_Dio LCD_E_interface = {LCD_E_PORT , LCD_E_PIN , PIN_LOW};
	_delay_ms(1);

	#if (LCD_DATA_BITS_MODE ==8)
		S_Dio LCD_DATA_interface= {LCD_DATA_PORT, (LCD_D0_PIN | LCD_D1_PIN | LCD_D2_PIN |LCD_D3_PIN |LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN |LCD_D7_PIN), OUTPUT};
		u8LocalReturn = MCAL_Dio_WritePin(&LCD_DATA_interface, command);
		u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_HIGH);
		_delay_ms(1);
		u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_LOW);
		_delay_ms(1);
	#elif (LCD_DATA_BITS_MODE == 4)
	#ifdef LOWER_PORT_PINS
		S_Dio LCD_DATA_interface = {LCD_DATA_PORT, (LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN |LCD_D7_PIN), OUTPUT};
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D4_PIN, GET_BIT(command, 4));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D5_PIN, GET_BIT(command, 5));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D6_PIN, GET_BIT(command, 6));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D7_PIN, GET_BIT(command, 7));
		_delay_ms(1);
	#else
		S_Dio LCD_DATA_interface = {LCD_DATA_PORT, (LCD_D0_PIN | LCD_D1_PIN | LCD_D2_PIN |LCD_D3_PIN), OUTPUT};
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D0_PIN, GET_BIT(command, 4));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D1_PIN, GET_BIT(command, 5));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D2_PIN, GET_BIT(command, 6));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D3_PIN, GET_BIT(command, 7));
	#endif
	u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_HIGH);
	_delay_ms(1);
	u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_LOW);
	_delay_ms(1);
	#ifdef LOWER_PORT_PINS
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D4_PIN, GET_BIT(command, 0));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D5_PIN, GET_BIT(command, 1));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D6_PIN, GET_BIT(command, 2));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D7_PIN, GET_BIT(command, 3));
		_delay_ms(1);
	#else
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D0_PIN, GET_BIT(command, 0));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D1_PIN, GET_BIT(command, 1));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D2_PIN, GET_BIT(command, 2));
		MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D3_PIN, GET_BIT(command, 3));
	#endif
	u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_HIGH);
	_delay_ms(1);
	u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_LOW);
	_delay_ms(1);
	#endif

	return u8LocalReturn;
}

/* Function to display a character on the LCD */
E_ErrorType HAL_LCD_sendCharacter(LCD_dataType data)
{
	E_ErrorType u8LocalReturn = E_NOT_OK;
	S_Dio LCD_RS_interface = {LCD_RS_PORT , LCD_RS_PIN , PIN_LOW};
	u8LocalReturn = MCAL_Dio_WritePin(&LCD_RS_interface, PIN_HIGH);
	/* If RW is configurable */
	#if (LCD_RW_PORT != none)
		S_Dio LCD_RW_interface = {LCD_Rw_PORT , LCD_Rw_PIN , PIN_LOW};
		u8LocalReturn = MCAL_Dio_WritePin(&LCD_RW_interface, PIN_LOW);
	#else
		//Do nothing
	#endif

		S_Dio LCD_E_interface = {LCD_E_PORT , LCD_E_PIN , PIN_LOW};
		_delay_ms(1);

		#if (LCD_DATA_BITS_MODE ==8)
			S_Dio LCD_DATA_interface= {LCD_DATA_PORT, (LCD_D0_PIN | LCD_D1_PIN | LCD_D2_PIN |LCD_D3_PIN |LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN |LCD_D7_PIN), OUTPUT};
			u8LocalReturn = MCAL_Dio_WritePort(&LCD_DATA_interface, command);
			u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_LOW);
			_delay_ms(1);
			u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_LOW);
			_delay_ms(1);
		#elif (LCD_DATA_BITS_MODE == 4)
		#ifdef LOWER_PORT_PINS
			S_Dio LCD_DATA_interface = {LCD_DATA_PORT, (LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN |LCD_D7_PIN), OUTPUT};
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D4_PIN, GET_BIT(data, 4));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D5_PIN, GET_BIT(data, 5));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D6_PIN, GET_BIT(data, 6));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D7_PIN, GET_BIT(data, 7));
			_delay_ms(1);
		#else
			S_Dio LCD_DATA_interface = {LCD_DATA_PORT, (LCD_D0_PIN | LCD_D1_PIN | LCD_D2_PIN |LCD_D3_PIN), OUTPUT};
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D0_PIN, GET_BIT(data, 4));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D1_PIN, GET_BIT(data, 5));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D2_PIN, GET_BIT(data, 6));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D3_PIN, GET_BIT(data, 7));
		#endif
		u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_HIGH);
		_delay_ms(1);
		u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_LOW);
		_delay_ms(1);
		#ifdef LOWER_PORT_PINS
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D4_PIN, GET_BIT(data, 0));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D5_PIN, GET_BIT(data, 1));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D6_PIN, GET_BIT(data, 2));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D7_PIN, GET_BIT(data, 3));
			_delay_ms(1);
		#else
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D0_PIN, GET_BIT(data, 0));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D1_PIN, GET_BIT(data, 1));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D2_PIN, GET_BIT(data, 2));
			MCAL_Dio_WriteSinglePin(&LCD_DATA_interface, LCD_D3_PIN, GET_BIT(data, 3));
		#endif
		u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_HIGH);
		_delay_ms(1);
		u8LocalReturn = MCAL_Dio_WritePin(&LCD_E_interface, PIN_LOW);
		_delay_ms(1);
		#endif

	return u8LocalReturn;
}

/* Function to display a string on the LCD */
E_ErrorType HAL_LCD_sendString(LCD_string str)
{
	E_ErrorType u8LocalReturn = E_NOT_OK;
	unsigned char i;
	for(i =0 ; str[i] != 0; i++)
	{
		u8LocalReturn = HAL_LCD_sendCharacter(str[i]);
	}
	return u8LocalReturn;
}

/* Function to clear the LCD screen */
E_ErrorType HAL_LCD_clearScreen()
{
	E_ErrorType u8LocalReturn = E_NOT_OK;
	u8LocalReturn = HAL_LCD_sendCommand(CLEAR_COMMAND);
	_delay_ms(10);
	u8LocalReturn = HAL_LCD_sendCommand(SHIFT_CURSOR_RIGHT);
	return u8LocalReturn;
}

/* Function to display a string on a certain row and column on the LCD screen */
E_ErrorType HAL_LCD_displaystringRowColumn(LCD_string str, LCD_row row, LCD_column col)
{
	E_ErrorType u8LocalReturn = E_NOT_OK;
	u8LocalReturn = HAL_LCD_goToRowColumn(row, col);
	u8LocalReturn = HAL_LCD_sendString(str);
	return u8LocalReturn;
}

/* Function to move the cursor to a certain row and column on the LCD screen */
E_ErrorType HAL_LCD_goToRowColumn(LCD_row row, LCD_column col)
{
	E_ErrorType u8LocalReturn = E_NOT_OK;
	unsigned char Address = 0;
	/* calculate the required address */
	switch(row)
	{
		case 0:
			Address = col;
			u8LocalReturn = E_OK;
			break;
		case 1:
			Address = col + row1col1;
			u8LocalReturn = E_OK;
			break;
		case 2:
			Address = col + row2col1;
			u8LocalReturn = E_OK;
			break;
		case 3:
			Address = col + row3col1;
			u8LocalReturn = E_OK;
			break;
		default :
			u8LocalReturn = E_NOT_OK;
			break;
	}
	u8LocalReturn = HAL_LCD_sendCommand(SET_CURSOR_LOCATION | Address);
	return u8LocalReturn;
}

/* Function to convert an integer to string */
E_ErrorType HAL_LCD_integerToString(LCD_integer num)
{
	E_ErrorType u8LocalReturn = E_NOT_OK;
	signed char str[16];
	unsigned char i, rem, len=0;
	LCD_integer n = num;
	if(n ==0)
	{
		len = 1;
	}
	else
	{
		while(n != 0)
		{
			len++;
			n /= 10;
		}
	}
	if(len >= 15)
	{
		u8LocalReturn = E_NOT_OK;
		return u8LocalReturn;
	}
	for(i=0 ; i<len ; i++)
	{
		rem = num % 10;
		num = num /10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	u8LocalReturn = HAL_LCD_sendString(str);
	return u8LocalReturn;
}

/* Function to display an integer on a certain row and column on the LCD screen */
E_ErrorType HAL_LCD_displayIntegerRowColumn(LCD_integer num, LCD_row row, LCD_column col)
{
	E_ErrorType u8LocalReturn = E_NOT_OK;
	u8LocalReturn = HAL_LCD_goToRowColumn(row, col);
	u8LocalReturn = HAL_LCD_integerToString(num);
	return u8LocalReturn;
}
