#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

#define ON 0
#define OFF 1

// This function uses DIO driver to initialize LED
// Steps:
// 1- uses DIO_voidSetPinDirection to assign the pin as output
// 2- uses DIO_voidSetPinValue to initialize the LED as low
errorState LED_voidInit(u8 portNumber, u8 pinNumber);

// This function uses DIO driver to turn the LED on or off
// Steps:
// 1- switch case to determine value (ON - OFF)
// 2- uses DIO_voidSetPinValue to output high or low to the LED
errorState LED_voidOnOff(u8 portNumber, u8 pinNumber, u8 value);

#endif