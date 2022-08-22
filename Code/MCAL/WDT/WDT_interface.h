#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

// This function enables watchdog timer and configures it to reset MCU after 17ms
errorState WDT_voidEnable();

#endif