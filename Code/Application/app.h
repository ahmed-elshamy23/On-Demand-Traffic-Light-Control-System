#ifndef APP_H
#define APP_H

#define CAR_PORT PORTA
#define PEDESTRIAN_PORT PORTB
#define BUTTON_PORT PORTD

#define CAR_LED_GREEN 0
#define CAR_LED_YELLOW 1
#define CAR_LED_RED 2

#define PEDESTRIAN_LED_GREEN 0
#define PEDESTRIAN_LED_YELLOW 1
#define PEDESTRIAN_LED_RED 2

#define BUTTON_PIN 2

// This function initializes the application
// enable global interrupt and external interrupt and initialize timer0, LEDs and switch
void APP_init();

// This function executes the application
void APP_start();

#endif