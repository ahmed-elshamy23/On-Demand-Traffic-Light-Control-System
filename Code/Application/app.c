#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_private.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/EXIT/EXIT_interface.h"
#include "../MCAL/EXIT/EXIT_private.h"
#include "../MCAL/TIMER0/TIMER0_config.h"
#include "../MCAL/TIMER0/TIMER0_private.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/WDT/WDT_interface.h"
#include "../HAL/Button/BTN_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "app.h"

void INT0_ISR()
{
	TIMER0_voidDelay(0.3);
	if (BTN_u8ButtonIsPressed(BUTTON_PORT, BUTTON_PIN))
	{
		__asm__ __volatile__("sei");
	}
	else
	{
		if (DIO_u8GetPinValue(CAR_PORT, CAR_LED_RED))
		{
			LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_GREEN, ON);
			LED_voidOnOff(CAR_PORT, CAR_LED_RED, ON);
			TIMER0_voidDelay(5);
		}
		else
		{
			LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_RED, ON);
			volatile u8 i = 1;
			for (; i <= 10; i++)
			{
				if (i % 2)
				{
					LED_voidOnOff(CAR_PORT, CAR_LED_YELLOW, ON);
					LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_YELLOW, ON);
				}
				else
				{
					LED_voidOnOff(CAR_PORT, CAR_LED_YELLOW, OFF);
					LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_YELLOW, OFF);
				}
				TIMER0_voidDelay(0.5);
			}
			LED_voidOnOff(CAR_PORT, CAR_LED_GREEN, OFF);
			LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_RED, OFF);
			LED_voidOnOff(CAR_PORT, CAR_LED_RED, ON);
			LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_GREEN, ON);
			TIMER0_voidDelay(5);
		}
		LED_voidOnOff(CAR_PORT, CAR_LED_RED, OFF);
		volatile u8 i = 1;
		for (; i <= 10; i++)
		{
			if (i % 2)
			{
				LED_voidOnOff(CAR_PORT, CAR_LED_YELLOW, ON);
				LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_YELLOW, ON);
			}
			else
			{
				LED_voidOnOff(CAR_PORT, CAR_LED_YELLOW, OFF);
				LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_YELLOW, OFF);
			}
			TIMER0_voidDelay(0.5);
		}
		LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_GREEN, OFF);
		LED_voidOnOff(PEDESTRIAN_PORT, PEDESTRIAN_LED_RED, ON);
		LED_voidOnOff(CAR_PORT, CAR_LED_GREEN, ON);
		TIMER0_voidDelay(5);
		__asm__ __volatile__("sei");
		WDT_voidEnable();
		while (1)
			;
	}
}

void APP_init()
{
	LED_voidInit(CAR_PORT, CAR_LED_GREEN);
	LED_voidInit(CAR_PORT, CAR_LED_YELLOW);
	LED_voidInit(CAR_PORT, CAR_LED_RED);

	LED_voidInit(PEDESTRIAN_PORT, PEDESTRIAN_LED_GREEN);
	LED_voidInit(PEDESTRIAN_PORT, PEDESTRIAN_LED_YELLOW);
	LED_voidInit(PEDESTRIAN_PORT, PEDESTRIAN_LED_RED);

	BTN_voidInit(BUTTON_PORT, BUTTON_PIN);

	GIE_voidEnable();
	EXIT_voidInit(INT0, FALLING_EDGE);
	EXIT_voidSetCallbackINT0(&INT0_ISR);

	TIMER0_voidInit();
}

void APP_start()
{
	LED_voidOnOff(CAR_PORT, CAR_LED_GREEN, ON);
	TIMER0_voidDelay(5);
	u8 i = 1;
	for (; i <= 10; i++)
	{
		if (i % 2)
			LED_voidOnOff(CAR_PORT, CAR_LED_YELLOW, ON);
		else
			LED_voidOnOff(CAR_PORT, CAR_LED_YELLOW, OFF);
		TIMER0_voidDelay(0.5);
	}
	LED_voidOnOff(CAR_PORT, CAR_LED_GREEN, OFF);
	LED_voidOnOff(CAR_PORT, CAR_LED_RED, ON);
	TIMER0_voidDelay(5);
	i = 1;
	for (; i <= 10; i++)
	{
		if (i % 2)
			LED_voidOnOff(CAR_PORT, CAR_LED_YELLOW, ON);
		else
			LED_voidOnOff(CAR_PORT, CAR_LED_YELLOW, OFF);
		TIMER0_voidDelay(0.5);
	}
	LED_voidOnOff(CAR_PORT, CAR_LED_RED, OFF);
}