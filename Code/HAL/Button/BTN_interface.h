#ifndef BTN_INTERFACE_H
#define BTN_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

// This function uses DIO driver to initialize the button and activating the internal pull up resistor
// Steps:
// 1- uses DIO_voidSetPinDirection to assign the pin as input
// 2- uses DIO_voidSetPinValue to activate internal pull up resistor
errorState BTN_voidInit(u8 portNumber, u8 pinNumber);

// This function uses DIO driver to check if the button is pressed or not
// uses DIO_u8GetPinValue to check if the input is low or not
u8 BTN_u8ButtonIsPressed(u8 portNumber, u8 pinNumber);

#endif