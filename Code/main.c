#include "Application/app.h"

#define F_CPU 8000000UL

int main()
{
	APP_init();
	while (1)
	{
		APP_start();
	}
}