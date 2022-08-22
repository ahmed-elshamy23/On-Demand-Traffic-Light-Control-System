#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"

errorState DIO_voidSetPinDirection(u8 portNumber, u8 pinNumber, u8 direction)
{
	switch (portNumber)
	{
	case PORTA:
		switch (direction)
		{
		case INPUT:
			CLR_BIT(DDRA_REG, pinNumber);
			break;
		case OUTPUT:
			SET_BIT(DDRA_REG, pinNumber);
		default:
			return ERROR_OCCURED;
		}
		break;
	case PORTB:
		switch (direction)
		{
		case INPUT:
			CLR_BIT(DDRB_REG, pinNumber);
			break;
		case OUTPUT:
			SET_BIT(DDRB_REG, pinNumber);
		default:
			return ERROR_OCCURED;
		}
		break;
	case PORTC:
		switch (direction)
		{
		case INPUT:
			CLR_BIT(DDRC_REG, pinNumber);
			break;
		case OUTPUT:
			SET_BIT(DDRC_REG, pinNumber);
		default:
			return ERROR_OCCURED;
		}
		break;
	case PORTD:
		switch (direction)
		{
		case INPUT:
			CLR_BIT(DDRD_REG, pinNumber);
			break;
		case OUTPUT:
			SET_BIT(DDRD_REG, pinNumber);
		default:
			return ERROR_OCCURED;
		}
	default:
		return ERROR_OCCURED;
	}
	return OK;
}

errorState DIO_voidSetPinValue(u8 portNumber, u8 pinNumber, u8 value)
{
	switch (portNumber)
	{
	case PORTA:
		switch (value)
		{
		case INPUT:
			CLR_BIT(PORTA_REG, pinNumber);
			break;
		case OUTPUT:
			SET_BIT(PORTA_REG, pinNumber);
		default:
			return ERROR_OCCURED;
		}
		break;
	case PORTB:
		switch (value)
		{
		case INPUT:
			CLR_BIT(PORTB_REG, pinNumber);
			break;
		case OUTPUT:
			SET_BIT(PORTB_REG, pinNumber);
		default:
			return ERROR_OCCURED;
		}
		break;
	case PORTC:
		switch (value)
		{
		case INPUT:
			CLR_BIT(PORTC_REG, pinNumber);
			break;
		case OUTPUT:
			SET_BIT(PORTC_REG, pinNumber);
		default:
			return ERROR_OCCURED;
		}
		break;
	case PORTD:
		switch (value)
		{
		case INPUT:
			CLR_BIT(PORTD_REG, pinNumber);
			break;
		case OUTPUT:
			SET_BIT(PORTD_REG, pinNumber);
		default:
			return ERROR_OCCURED;
		}
	}
	return OK;
}

u8 DIO_u8GetPinValue(u8 portNumber, u8 pinNumber)
{
	u8 value = 0;
	switch (portNumber)
	{
	case PORTA:
		value = GET_BIT(PINA_REG, pinNumber);
		break;
	case PORTB:
		value = GET_BIT(PINB_REG, pinNumber);
		break;
	case PORTC:
		value = GET_BIT(PINC_REG, pinNumber);
		break;
	case PORTD:
		value = GET_BIT(PIND_REG, pinNumber);
	}
	return value;
}