#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXIT_interface.h"
#include "EXIT_private.h"

void (*callBackINT0)(void) = NULL;
void (*callBackINT1)(void) = NULL;
void (*callBackINT2)(void) = NULL;

errorState EXIT_voidInit(u8 peripheral, u8 mode)
{
	switch (peripheral)
	{
	case INT0:
		SET_BIT(GICR, INT0_BIT);
		switch (mode)
		{
		case LOW_LEVEL:
			CLR_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
		case ANY_CHANGE:
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
		default:
			return ERROR_OCCURED;
		}
		break;
	case INT1:
		SET_BIT(GICR, INT1_BIT);
		switch (mode)
		{
		case LOW_LEVEL:
			CLR_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
			break;
		case ANY_CHANGE:
			SET_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
		default:
			return ERROR_OCCURED;
		}
		break;
	case INT2:
		SET_BIT(GICR, INT2_BIT);
		switch (mode)
		{
		case FALLING_EDGE:
			CLR_BIT(MCUCSR, ISC2);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCSR, ISC2);
		default:
			return ERROR_OCCURED;
		}
	default:
		return ERROR_OCCURED;
	}
	return OK;
}

errorState EXIT_voidSetCallbackINT0(void (*ptr)())
{
	callBackINT0 = ptr;
	return OK;
}

errorState EXIT_voidSetCallbackINT1(void (*ptr)())
{
	callBackINT1 = ptr;
	return OK;
}

errorState EXIT_voidSetCallbackINT2(void (*ptr)())
{
	callBackINT2 = ptr;
	return OK;
}

void INT0_VECT(void)
{
	if (callBackINT0 != NULL)
	{
		callBackINT0();
	}
}

void INT1_VECT(void)
{
	if (callBackINT1 != NULL)
	{
		callBackINT1();
	}
}

void INT2_VECT(void)
{
	if (callBackINT2 != NULL)
	{
		callBackINT2();
	}
}