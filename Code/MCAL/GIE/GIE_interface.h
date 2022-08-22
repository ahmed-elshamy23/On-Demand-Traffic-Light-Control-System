#ifndef GIE_INTERFACE_H
#define GIE_INTERFACE_H

#define SREG *((volatile u8 *)(0x5F))
#define GENERAL_INTERRUPT 7

// These functions interact with the status register to enable or disable the global interrupt
errorState GIE_voidEnable();
errorState GIE_voidDisable();

#endif