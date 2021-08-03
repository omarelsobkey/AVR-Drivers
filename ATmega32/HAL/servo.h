/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 19/7/2021
Microcontroller : ATmega32
Crystal         : 8Mhz
********************************************************************/

// Fpwm = F_CLK / (2 * prescalar * (1 + TOP))
// Fpwm = 50 Hz

#ifndef SERVO
#define SERVO

#include "../MCAL/STD_TYPES.h"
#include "../MCAL/config.h"

#define SERVO_Pin portd,pin4

// TCCR1A Pins
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A 3
#define FOC1B 2
#define WGM11 1
#define WGM10 0

// TCCR1B Pins
#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12 2 
#define CS11 1
#define CS10 0

void servo_init(void);
void servo_set_angle(u8 angle);

#endif