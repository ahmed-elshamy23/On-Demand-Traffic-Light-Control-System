#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GIE_interface.h"

errorState GIE_voidEnable()
{
	SET_BIT(SREG, GENERAL_INTERRUPT);
	return OK;
}

errorState GIE_voidDisable()
{
	CLR_BIT(SREG, GENERAL_INTERRUPT);
	return OK;
}