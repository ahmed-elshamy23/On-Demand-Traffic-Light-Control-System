#ifndef EXIT_INTERFACE_H
#define EXIT_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

// This function interacts with registers to initialize the external interrupt peripheral and its mode of operation
// Steps:
// 1- switch case to determine which interrupt peripheral is to be used
// 2- switch case on the mode of operation (rising edge, falling edge, ...etc)
// 3- modify GICR, MCUCR and MCUCSR registers according to the desired configuration
errorState EXIT_voidInit(u8 peripheral, u8 mode);

// These functions take a pointer to function and passes it to the ISR through a global pointer to function
errorState EXIT_voidSetCallbackINT0(void (*ptr)());
errorState EXIT_voidSetCallbackINT1(void (*ptr)());
errorState EXIT_voidSetCallbackINT2(void (*ptr)());

// These functions is the ISRs for external interrupts
void INT0_VECT(void) __attribute__((signal));
void INT1_VECT(void) __attribute__((signal));
void INT2_VECT(void) __attribute__((signal));

#endif