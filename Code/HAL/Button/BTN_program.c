#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"
#include "BTN_interface.h"

errorState BTN_voidInit(u8 portNumber, u8 pinNumber)
{
	u8 state1, state2;
	state1 = DIO_voidSetPinDirection(portNumber, pinNumber, INPUT);
	state2 = DIO_voidSetPinValue(portNumber, pinNumber, HIGH);
	if (state1 == OK && state2 == OK)
		return OK;
	else
		return ERROR_OCCURED;
}

u8 BTN_u8ButtonIsPressed(u8 portNumber, u8 pinNumber)
{
	if (DIO_u8GetPinValue(portNumber, pinNumber) == LOW)
		return 0x01;
	return 0;
}