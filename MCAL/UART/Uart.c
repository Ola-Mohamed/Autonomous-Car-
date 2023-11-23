/*
 * Uart.c

 *
 *  Created on: Nov 1, 2023
 *      Author: dell
 */


#include "Uart_interface.h"

/* UART initialization */
E_Errore_State_UART MCAL_UART_init(unsigned long int baudRate)
{
	E_Errore_State_UART error =OK;
	if(UART_STATUS_ERROR==NOT_OK)
	{
		error=NOT_OK;
	}
	else
	{


		unsigned long int BRValue = (F_CPU/(16UL*baudRate)) - 1;

		/* Set baud rate */
		UCSRC &= ~(1<<URSEL);
		UBRRH = (unsigned char)(BRValue>>8);
		UBRRL = (unsigned char)BRValue;

		/* Enable receiver and transmitter */
		UCSRB = (1<<RXEN)|(1<<TXEN);//|(1<<RXCIE);
		/* Set frame format: 8data, 2stop bit */
		UCSRC = (1<<URSEL)|(3<<UCSZ0);


	}

	return error;

}


/* UART sends character or number by synchronous  way */
E_Errore_State_UART MCAL_UART_send_sysch(unsigned char Data)
{
	E_Errore_State_UART error =OK;
	if(UART_STATUS_ERROR==NOT_OK)
	{
		error=NOT_OK;
	}
	else
	{
		/* Wait for empty transmit buffer */
		while ( !( UCSRA & (1<<UDRE)) );

		/* Put data into buffer, sends the data */
		UDR = Data;
	}
	return error;
}


/* Enable Transmit complete */
E_Errore_State_UART MCAL_UART_TXC_Enable()
{
	E_Errore_State_UART error =OK;
	if(UART_STATUS_ERROR==NOT_OK)
	{
		error=NOT_OK;
	}
	else{

		/* Enable Transmit complete  interrupt */
		UCSRB |=(1<<TXCIE);
		//enable global interrupt
		sei();
	}
	return error;
}

/* Enable USART data register empty */
E_Errore_State_UART  MCAL_UART_UDRE_Enable()
{
	E_Errore_State_UART error =OK;
	if(UART_STATUS_ERROR==NOT_OK)
	{
		error=NOT_OK;
	}
	else
	{


		/* Enable the interrupt UART data register empty */
		UCSRB |=(1<<UDRIE);
		/* Enable global interrupt */
		sei();

	}
	return error;


}

/* UART sends string  by synchronous  way */
E_Errore_State_UART MCAL_UART_send_str_sysch(char*Str)
{
	E_Errore_State_UART u8LocalReturn;
	E_Errore_State_UART error =OK;
	if(UART_STATUS_ERROR==NOT_OK)
	{
		error=NOT_OK;
	}
	else
	{
		for(char i=0;Str[i]!='\0';i++)
		{

			u8LocalReturn=MCAL_UART_send_sysch(Str[i]);

		}
	}
	return error;
}

/* UART receives data  by synchronous  way */
unsigned char MCAL_UART_receive_sysch()
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );

	/* Get and return received data from buffer */
	return UDR;
}


/* Enable USART receive complete  */
E_Errore_State_UART  MCAL_UART_RXC_Enable()
{
	E_Errore_State_UART error =OK;
	if(UART_STATUS_ERROR==NOT_OK)
	{
		error=NOT_OK;
	}
	else
	{

		//enable the interrupt complete interrupt
		UCSRB |=(1<<RXCIE);
		//enable global interrupt
		sei();

	}
	return error;
}


E_Errore_State_UART  MCAL_UART_setCAllBACK(void (*p2f)(void),MODES mode)
{
	E_Errore_State_UART error =OK;
	if(UART_STATUS_ERROR==NOT_OK)
	{
		error=NOT_OK;
	}
	else
	{
		switch (mode)
		{
		case Data_Register_Empty:
			if ((p2f) != NULL)
			{
				ptr2fun_Data_register_empty= p2f;
			}
			break;
		case Transmit_Complete:
			if( (p2f) != NULL)
			{
				ptr2fun_transmit_complete = p2f;
			}
			break;
		case receive_complete:
			if( (p2f) != NULL)
			{
				ptr2fun_receive_data = p2f;
			}
			break;
		default:
			break;

		}

	}
	return error;
}
void Uart_ReceiveByte_Unblock(char* pData)
{

	if(UCSRA & (1<<RXC)){
		(*pData) =  UDR;
		//result =  TRUE;
	}
	else{
		//result = FALSE;
	}
	//return result;
}

ISR(UART_RXC_VECT)
{
	if (ptr2fun_receive_data != NULL)
	{
		ptr2fun_receive_data();
	}
}


ISR(UART_TXC_vect)
{
	if (ptr2fun_transmit_complete  != NULL)
	{
		ptr2fun_transmit_complete();
	}
}

ISR(UART_UDRE_vect)
{
	if (ptr2fun_Data_register_empty != NULL)
	{
		ptr2fun_Data_register_empty();
	}
}


