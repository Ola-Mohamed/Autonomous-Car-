
#include "IR_Interface.h"

// Initialize the IR sensor
void HAL_IR_Init() {
    // Set the IR sensor pin as an input
    CLEAR_BIT(IR_PORT, IR_SENSOR_PIN);
    // Enable the internal pull-up resistor for the sensor pin
    SET_BIT(IR_PORT, IR_SENSOR_PIN);
}

// Read the IR sensor's state (1 if object detected, 0 if not)
unsigned char HAL_IR_Read()
{
    return (((IR_PIN ) & (1<<IR_SENSOR_PIN)) ? NOT_DETECTED : DETECTED);
}
