/*
 * DIO_Prog.c
 *
 *  Created on: Nov 17, 2023
 *      Author: pc
 */





#include "DIO_interface.h"
#include "DIO_Types.h"
#include "../LCD/lcd.h"

DIO_E_ErrorType MCAL_Dio_Init(S_Dio *Dio_Config)
{
    // Declare local variables
    DIO_E_ErrorType error = DIO_E_OK;
    u8RegisterValue Mask1, Mask2;
   // LCD_displayString("PIN:");
    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_Config->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {
        // Calculate masks based on pin_num and Direction
        Mask2 = ((Dio_Config->pin_num) & (Dio_Config->Direction));

        // Switch based on the port_num

        switch (Dio_Config->port_num)
        {

        case PORTA_ID:
            // Calculate Mask1 for PORTA
            Mask1 = ((DIO_DDRA) & (~(Dio_Config->pin_num)));
            // Set the port direction for PORTA
            DIO_DDRA = Mask1 | Mask2;
            break;
        case PORTB_ID:
            // Calculate Mask1 for PORTB
            Mask1 = ((DIO_DDRB) & (~(Dio_Config->pin_num)));
            // Set the port direction for PORTB
            DIO_DDRB = Mask1 | Mask2;
            break;
        case PORTC_ID:
            // Calculate Mask1 for PORTC
            Mask1 = ((DIO_DDRC) & (~(Dio_Config->pin_num)));
            // Set the port direction for PORTC
            DIO_DDRC = Mask1 | Mask2;
            break;
        case PORTD_ID:
            // Calculate Mask1 for PORTD
            Mask1 = ((DIO_DDRD) & (~(Dio_Config->pin_num)));
            // Set the port direction for PORTD
            DIO_DDRD = Mask1 | Mask2;
            break;
        case PORTE_ID:
            // Calculate Mask1 for PORTE
            Mask1 = ((DIO_DDRE) & (~(Dio_Config->pin_num)));
            // Set the port direction for PORTE
            DIO_DDRE = Mask1 | Mask2;
            break;
        case PORTF_ID:
            // Calculate Mask1 for PORTF
            Mask1 = ((DIO_DDRF) & (~(Dio_Config->pin_num)));
            // Set the port direction for PORTF
            DIO_DDRF = Mask1 | Mask2;
            break;
        case PORTG_ID:
            // Calculate Mask1 for PORTG
            Mask1 = ((DIO_DDRG) & (~(Dio_Config->pin_num)));
            // Set the port direction for PORTG
            DIO_DDRG = Mask1 | Mask2;
            break;
        }
    }

    // Return the error status
    return error;
}

DIO_E_ErrorType MCAL_Dio_SetPortDirection(S_Dio *Dio_ConfigPort)
{
    // Declare local variable for error status
    DIO_E_ErrorType error = DIO_E_OK;

    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_ConfigPort->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {
        // Switch based on the port_num
        switch (Dio_ConfigPort->port_num)
        {
        case PORTA_ID:
            // Set the port direction for PORTA
            DIO_DDRA = Dio_ConfigPort->Direction;
            break;
        case PORTB_ID:
            // Set the port direction for PORTB
            DIO_DDRB = Dio_ConfigPort->Direction;
            break;
        case PORTC_ID:
            // Set the port direction for PORTC
            DIO_DDRC = Dio_ConfigPort->Direction;
            break;
        case PORTD_ID:
            // Set the port direction for PORTD
            DIO_DDRD = Dio_ConfigPort->Direction;
            break;
        case PORTE_ID:
            // Set the port direction for PORTE
            DIO_DDRE = Dio_ConfigPort->Direction;
            break;
        case PORTF_ID:
            // Set the port direction for PORTF
            DIO_DDRF = Dio_ConfigPort->Direction;
            break;
        case PORTG_ID:
            // Set the port direction for PORTG
            DIO_DDRG = Dio_ConfigPort->Direction;
            break;
        }
    }

    // Return the error status
    return error;
}

DIO_E_ErrorType MCAL_Dio_SetPinDirection(S_Dio *Dio_ConfigPin)
{
    // Declare local variables for error status and masks
    DIO_E_ErrorType error = DIO_E_OK;
    u8RegisterValue Mask1, Mask2;

    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_ConfigPin->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {
        // Calculate masks based on pin_num and Direction
        Mask2 = ((Dio_ConfigPin->pin_num) & (Dio_ConfigPin->Direction));

        // Switch based on the port_num
        switch (Dio_ConfigPin->port_num)
        {
        case PORTA_ID:
            // Calculate Mask1 for PORTA
            Mask1 = ((DIO_DDRA) & (~(Dio_ConfigPin->pin_num)));
            // Set the pin direction for PORTA
            DIO_DDRA = Mask1 | Mask2;
            break;
        case PORTB_ID:
            // Calculate Mask1 for PORTB
            Mask1 = ((DIO_DDRB) & (~(Dio_ConfigPin->pin_num)));
            // Set the pin direction for PORTB
            DIO_DDRB = Mask1 | Mask2;
            break;
        case PORTC_ID:
            // Calculate Mask1 for PORTC
            Mask1 = ((DIO_DDRC) & (~(Dio_ConfigPin->pin_num)));
            // Set the pin direction for PORTC
            DIO_DDRC = Mask1 | Mask2;
            break;
        case PORTD_ID:
            // Calculate Mask1 for PORTD
            Mask1 = ((DIO_DDRD) & (~(Dio_ConfigPin->pin_num)));
            // Set the pin direction for PORTD
            DIO_DDRD = Mask1 | Mask2;
            break;
        case PORTE_ID:
            // Calculate Mask1 for PORTE
            Mask1 = ((DIO_DDRE) & (~(Dio_ConfigPin->pin_num)));
            // Set the pin direction for PORTE
            DIO_DDRE = Mask1 | Mask2;
            break;
        case PORTF_ID:
            // Calculate Mask1 for PORTF
            Mask1 = ((DIO_DDRF) & (~(Dio_ConfigPin->pin_num)));
            // Set the pin direction for PORTF
            DIO_DDRF = Mask1 | Mask2;
            break;
        case PORTG_ID:
            // Calculate Mask1 for PORTG
            Mask1 = ((DIO_DDRG) & (~(Dio_ConfigPin->pin_num)));
            // Set the pin direction for PORTG
            DIO_DDRG = Mask1 | Mask2;
            break;
        }
    }

    // Return the error status
    return error;
}

// Function to read the entire port
DIO_E_ErrorType MCAL_Dio_ReadPort(S_Dio *Dio_ReadPort, u8PortValue *Port_Value)
{
    // Declare local variable for error status
    DIO_E_ErrorType error = DIO_E_OK;

    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_ReadPort->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {
        // Switch based on the port_num
        switch (Dio_ReadPort->port_num)
        {
        case PORTA_ID:
            // Read the value of PORTA and store it in Port_Value
            *Port_Value = DIO_PINA;
            break;
        case PORTB_ID:
            // Read the value of PORTB and store it in Port_Value
            *Port_Value = DIO_PINB;
            break;
        case PORTC_ID:
            // Read the value of PORTC and store it in Port_Value
            *Port_Value = DIO_PINC;
            break;
        case PORTD_ID:
            // Read the value of PORTD and store it in Port_Value
            *Port_Value = DIO_PIND;
            break;
        case PORTE_ID:
            // Read the value of PORTE and store it in Port_Value
            *Port_Value = DIO_PINE;
            break;
        case PORTF_ID:
            // Read the value of PORTF and store it in Port_Value
            *Port_Value = DIO_PINF;
            break;
        case PORTG_ID:
            // Read the value of PORTG and store it in Port_Value
            *Port_Value = DIO_PING;
            break;
        }
    }

    // Return the error status
    return error;
}

// Function to read the value of a specific pin
DIO_E_ErrorType MCAL_Dio_ReadPin(S_Dio *Dio_ReadPin, u8PinValue *Pin_Value)
{
    // Declare local variable for error status
    DIO_E_ErrorType error = DIO_E_OK;

    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_ReadPin->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {
        // Switch based on the port_num
        switch (Dio_ReadPin->port_num)
        {
        case PORTA_ID:
            // Read the value of the specific pin in PORTA and store it in Pin_Value
            *Pin_Value = GET_BIT(DIO_PINA, Dio_ReadPin->pin_num);
            break;
        case PORTB_ID:
            // Read the value of the specific pin in PORTB and store it in Pin_Value
            *Pin_Value = GET_BIT(DIO_PINB, Dio_ReadPin->pin_num);
            break;
        case PORTC_ID:
            // Read the value of the specific pin in PORTC and store it in Pin_Value
            *Pin_Value = GET_BIT(DIO_PINC, Dio_ReadPin->pin_num);
            break;
        case PORTD_ID:
            // Read the value of the specific pin in PORTD and store it in Pin_Value
            *Pin_Value = GET_BIT(DIO_PIND, Dio_ReadPin->pin_num);
            break;
        case PORTE_ID:
            // Read the value of the specific pin in PORTE and store it in Pin_Value
            *Pin_Value = GET_BIT(DIO_PINE, Dio_ReadPin->pin_num);
            break;
        case PORTF_ID:
            // Read the value of the specific pin in PORTF and store it in Pin_Value
            *Pin_Value = GET_BIT(DIO_PINF, Dio_ReadPin->pin_num);
            break;
        case PORTG_ID:
            // Read the value of the specific pin in PORTG and store it in Pin_Value
            *Pin_Value = GET_BIT(DIO_PING, Dio_ReadPin->pin_num);
            break;
        }
    }

    // Return the error status
    return error;
}


// Function to write a value to the entire port
DIO_E_ErrorType MCAL_Dio_WritePort(S_Dio *Dio_WritePort, u8PortValue Port_Value)
{
    // Declare local variable for error status
    DIO_E_ErrorType error = DIO_E_OK;

    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_WritePort->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {
        // Switch based on the port_num
        switch (Dio_WritePort->port_num)
        {
        case PORTA_ID:
            // Write the value Port_Value to PORTA
            DIO_PORTA = Port_Value;
            break;
        case PORTB_ID:
            // Write the value Port_Value to PORTB
            DIO_PORTB = Port_Value;
            break;
        case PORTC_ID:
            // Write the value Port_Value to PORTC
            DIO_PORTC = Port_Value;
            break;
        case PORTD_ID:
            // Write the value Port_Value to PORTD
            DIO_PORTD = Port_Value;
            break;
        case PORTE_ID:
            // Write the value Port_Value to PORTE
            DIO_PORTE = Port_Value;
            break;
        case PORTF_ID:
            // Write the value Port_Value to PORTF
            DIO_PORTF = Port_Value;
            break;
        case PORTG_ID:
            // Write the value Port_Value to PORTG
            DIO_PORTG = Port_Value;
            break;
        }
    }

    // Return the error status
    return error;
}

// Function to write a value to a specific pin
DIO_E_ErrorType MCAL_Dio_WritePin(S_Dio *Dio_WritePin, u8PinValue Pin_value)
{
    // Declare local variable for error status
    DIO_E_ErrorType error = DIO_E_OK;
    // Declare local variables for masking
    u8RegisterValue Mask1, Mask2;

    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_WritePin->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {
        // Calculate masking values for the specific pin
        Mask2 = ((Dio_WritePin->pin_num) & (Pin_value));

        // Switch based on the port_num
        switch (Dio_WritePin->port_num)
        {
        case PORTA_ID:
            // Calculate Mask1, update PORTA with the modified value
            Mask1 = ((DIO_PORTA) & (~(Dio_WritePin->pin_num)));
            DIO_PORTA = Mask1 | Mask2;
            break;
        case PORTB_ID:
            // Calculate Mask1, update PORTB with the modified value
            Mask1 = ((DIO_PORTB) & (~(Dio_WritePin->pin_num)));
            DIO_PORTB = Mask1 | Mask2;
            break;
        case PORTC_ID:
            // Calculate Mask1, update PORTC with the modified value
            Mask1 = ((DIO_PORTC) & (~(Dio_WritePin->pin_num)));
            DIO_PORTC = Mask1 | Mask2;
            break;
        case PORTD_ID:
            // Calculate Mask1, update PORTD with the modified value
            Mask1 = ((DIO_PORTD) & (~(Dio_WritePin->pin_num)));
            DIO_PORTD = Mask1 | Mask2;
            break;
        case PORTE_ID:
            // Calculate Mask1, update PORTE with the modified value
            Mask1 = ((DIO_PORTE) & (~(Dio_WritePin->pin_num)));
            DIO_PORTE = Mask1 | Mask2;
            break;
        case PORTF_ID:
            // Calculate Mask1, update PORTF with the modified value
            Mask1 = ((DIO_PORTF) & (~(Dio_WritePin->pin_num)));
            DIO_PORTF = Mask1 | Mask2;
            break;
        case PORTG_ID:
            // Calculate Mask1, update PORTG with the modified value
            Mask1 = ((DIO_PORTG) & (~(Dio_WritePin->pin_num)));
            DIO_PORTG = Mask1 | Mask2;
            break;
        }
    }

    // Return the error status
    return error;
}

// Function to write a value to a single pin
DIO_E_ErrorType MCAL_Dio_WriteSinglePin(S_Dio *Dio_WritePin, E_DioPin Pin_Num, u8PinValue Pin_value)
{
    // Declare local variable for error status
    DIO_E_ErrorType error = DIO_E_OK;
    // Declare local variable for pin number
    u8PinNumber bitNumber;

    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_WritePin->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {

        // Loop through configured pins to find the bitNumber corresponding to Pin_Num
        for (int i = 0; i < DIO_CONFIGURED_PINS; i++)
        {
            if (Pin_Num & (1 << i))
            {
                // Assign the found bitNumber
                bitNumber = i;
                break;
            }
        }


        // Switch based on the port_num

        switch (Dio_WritePin->port_num)
        {


        case PORTA_ID:
            // Check Pin_value and set or clear the corresponding bit in DIO_PORTA
            if (Pin_value == 1)
            {
                SET_BIT(DIO_PORTA, bitNumber);

            }
            else
            {
                CLEAR_BIT(DIO_PORTA, bitNumber);
            }
            break;
        case PORTB_ID:
        	            // Check Pin_value and set or clear the corresponding bit in DIO_PORTB
            if (Pin_value == 1)
            {

                SET_BIT(DIO_PORTB, bitNumber);

            }
            else
            {
                CLEAR_BIT(DIO_PORTB, bitNumber);

            }
            break;
        case PORTC_ID:
            // Check Pin_value and set or clear the corresponding bit in DIO_PORTC
            if (Pin_value == 1)
            {
                SET_BIT(DIO_PORTC, bitNumber);
            }
            else
            {
                CLEAR_BIT(DIO_PORTC, bitNumber);
            }
            break;
        case PORTD_ID:
            // Check Pin_value and set or clear the corresponding bit in DIO_PORTD
            if (Pin_value == 1)
            {
                SET_BIT(DIO_PORTD, bitNumber);
            }
            else
            {
                CLEAR_BIT(DIO_PORTD, bitNumber);
            }
            break;
        case PORTE_ID:
            // Check Pin_value and set or clear the corresponding bit in DIO_PORTE
            if (Pin_value == 1)
            {
                SET_BIT(DIO_PORTE, bitNumber);
            }
            else
            {
                CLEAR_BIT(DIO_PORTE, bitNumber);
            }
            break;
        case PORTF_ID:
            // Check Pin_value and set or clear the corresponding bit in DIO_PORTF
            if (Pin_value == 1)
            {
                SET_BIT(DIO_PORTF, bitNumber);
            }
            else
            {
                CLEAR_BIT(DIO_PORTF, bitNumber);
            }
            break;
        case PORTG_ID:
            // Check Pin_value and set or clear the corresponding bit in DIO_PORTG
            if (Pin_value == 1)
            {
                SET_BIT(DIO_PORTG, bitNumber);
            }
            else
            {
                CLEAR_BIT(DIO_PORTG, bitNumber);
            }
            break;
        }

    }

    // Return the error status
    return error;
}

// Function to read the value of a single pin
DIO_E_ErrorType MCAL_Dio_ReadSinglePin(S_Dio *Dio_ReadPin, E_DioPin Pin_Num, u8PinValue *Pin_Value)
{
    // Declare local variable for error status
    DIO_E_ErrorType error = DIO_E_OK;
    // Declare local variable for pin number
    u8PinNumber bitNumber;

    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_ReadPin->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {
        // Loop through configured pins to find the bitNumber corresponding to Pin_Num
        for (int i = 0; i < DIO_CONFIGURED_PINS; i++)
        {
            if (Pin_Num & (1 << i))
            {
                // Assign the found bitNumber
                bitNumber = i;
                break;
            }
        }

        // Switch based on the port_num
        switch (Dio_ReadPin->port_num)
        {
        case PORTA_ID:
            // Read the value of the corresponding bit in DIO_PINA and assign it to Pin_Value
            *Pin_Value = GET_BIT(DIO_PINA, bitNumber);
            break;
        case PORTB_ID:
            // Read the value of the corresponding bit in DIO_PINB and assign it to Pin_Value
            *Pin_Value = GET_BIT(DIO_PINB, bitNumber);
            break;
        case PORTC_ID:
            // Read the value of the corresponding bit in DIO_PINC and assign it to Pin_Value
            *Pin_Value = GET_BIT(DIO_PINC, bitNumber);
            break;
        case PORTD_ID:
            // Read the value of the corresponding bit in DIO_PIND and assign it to Pin_Value
            *Pin_Value = GET_BIT(DIO_PIND, bitNumber);
            break;
        case PORTE_ID:
            // Read the value of the corresponding bit in DIO_PINE and assign it to Pin_Value
            *Pin_Value = GET_BIT(DIO_PINE, bitNumber);
            break;
        case PORTF_ID:
            // Read the value of the corresponding bit in DIO_PINF and assign it to Pin_Value
            *Pin_Value = GET_BIT(DIO_PINF, bitNumber);
            break;
        case PORTG_ID:
            // Read the value of the corresponding bit in DIO_PING and assign it to Pin_Value
            *Pin_Value = GET_BIT(DIO_PING, bitNumber);
            break;
        }
    }

    // Return the error status
    return error;
}


// Function to toggle the value of a single pin
DIO_E_ErrorType MCAL_Dio_TogglePin(S_Dio *Dio_TogglePin, E_DioPin Pin_Num)
{
    // Declare local variable for error status
    DIO_E_ErrorType error = DIO_E_OK;
    // Declare local variable for pin number
    u8PinNumber bitNumber;

    // Check if DIO_STATUS_ERROR is not equal to DIO_E_NOT_OK
    if (DIO_STATUS_ERROR == DIO_E_NOT_OK)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    // Check if port_num is greater than or equal to DIO_CONFIGURED_PORTS
    else if (Dio_TogglePin->port_num >= DIO_CONFIGURED_PORTS)
    {
        // Set error to DIO_E_NOT_OK
        error = DIO_E_NOT_OK;
    }
    else
    {
        // Loop through configured pins to find the bitNumber corresponding to Pin_Num
        for (int i = 0; i < DIO_CONFIGURED_PINS; i++)
        {
            if (Pin_Num & (1 << i))
            {
                // Assign the found bitNumber
                bitNumber = i;
                break;
            }
        }

        // Switch based on the port_num
        switch (Dio_TogglePin->port_num)
        {
        case PORTA_ID:
            // Toggle the corresponding bit in DIO_PORTA
            DIO_PORTA = DIO_PORTA ^ (1 << bitNumber);
            break;
        case PORTB_ID:
            // Toggle the corresponding bit in DIO_PORTB
            DIO_PORTB = DIO_PORTB ^ (1 << bitNumber);
            break;
        case PORTC_ID:
            // Toggle the corresponding bit in DIO_PORTC
            DIO_PORTC = DIO_PORTC ^ (1 << bitNumber);
            break;
        case PORTD_ID:
            // Toggle the corresponding bit in DIO_PORTD
            DIO_PORTD = DIO_PORTD ^ (1 << bitNumber);
            break;
        case PORTE_ID:
            // Toggle the corresponding bit in DIO_PORTE
            DIO_PORTE = DIO_PORTE ^ (1 << bitNumber);
            break;
        case PORTF_ID:
            // Toggle the corresponding bit in DIO_PORTF
            DIO_PORTF = DIO_PORTF ^ (1 << bitNumber);
            break;
        case PORTG_ID:
            // Toggle the corresponding bit in DIO_PORTG
            DIO_PORTG = DIO_PORTG ^ (1 << bitNumber);
            break;
        }
    }

    // Return the error status
    return error;
}
