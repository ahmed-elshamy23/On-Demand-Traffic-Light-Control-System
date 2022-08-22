#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

// This function interacts with registers to initialize timer
// Steps:
// 1- #if directive to determine mode (normal - CTC - ...etc)
// 2- modify TCCR0 register to initialize timer0 according to the chosen mode
errorState TIMER0_voidInit();

// This function sets the prescaler of the timer according to the configuration to start it
// Steps:
// 1- #if directive to determine prescaler
// 2- modify TCCR0 register with the chosen prescaler to start the timer
errorState TIMER0_voidStart();

// This function sets 0 to the prescaler to stop the timer
errorState TIMER0_voidStop();

// This function make a delay using timer0
// Steps:
// 1- #if directive to calculate tick time
// 2- calculate overflow time
// 3- compare the required delay time with overflow time
// 4- if the delay time is bigger, calculate number of overflows and the preload value of the counter
// 5- if the delay time is smaller, calculate the preload value only
// 6- apply the preload value to the timer through TIMER0_voidSetTimerValue
// 7- In both cases, wait in an empty loop until the overflow flag is set
// 8- clear the overflow flag
// 9- repeat step 7, 8 until the required delay time is passed
errorState TIMER0_voidDelay(f32 delayTime);

// This functions sets the preload of the timer
// modify TCNT0 register to choose the preload of the timer to start counting from this value
errorState TIMER0_voidSetTimerValue(u8 value);

#endif