#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"
#include "LED_interface.h"

errorState LED_voidInit(u8 portNumber, u8 pinNumber)
{
	u8 state1, state2;
	state1 = DIO_voidSetPinDirection(portNumber, pinNumber, OUTPUT);
	state2 = DIO_voidSetPinValue(portNumber, pinNumber, LOW);
	if (state1 == OK && state2 == OK)
		return OK;
	else
		return ERROR_OCCURED;
}

errorState LED_voidOnOff(u8 portNumber, u8 pinNumber, u8 value)
{
	switch (value)
	{
	case ON:
		DIO_voidSetPinValue(portNumber, pinNumber, HIGH);
		break;
	case OFF:
		DIO_voidSetPinValue(portNumber, pinNumber, LOW);
	default:
		return ERROR_OCCURED;
	}
	return OK;
}