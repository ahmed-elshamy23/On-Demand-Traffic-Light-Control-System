#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

// This function interact with DDR registers to set the pin direction
// Steps:
// 1- switch case to determine which DDR register is to be modified
// 2- switch case to determine the direction of data (set or clear bit in DDR register)
// 3- Modify DDR register according to the above steps
errorState DIO_voidSetPinDirection(u8 portNumber, u8 pinNumber, u8 direction);

// This function interact with PORT registers to set the pin value
// Steps:
// 1- switch case to determine which PORT register is to be modified
// 2- switch case to determine the pin value (set or clear bit in PORT register)
// 3- Modify PORT register according to the above steps
errorState DIO_voidSetPinValue(u8 portNumber, u8 pinNumber, u8 value);

// This function interact with PIN registers to get the pin input value
// Steps:
// 1- switch case to determine which PORT register is to be read
// 2- get the desired bit value
// 3- return the value
u8 DIO_u8GetPinValue(u8 portNumber, u8 pinNumber);

#endif