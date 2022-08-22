#include "../../LIB/BIT_MATH.h"
#include "WDT_interface.h"
#include "WDT_private.h"

errorState WDT_voidEnable()
{
	CLR_BIT(WDTCR, WDP0);
	CLR_BIT(WDTCR, WDP1);
	CLR_BIT(WDTCR, WDP2);
	SET_BIT(WDTCR, WDE);
	return OK;
}