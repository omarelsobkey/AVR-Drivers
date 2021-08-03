/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 19/7/2021
********************************************************************/

// Fpwm = F_CLK / (2 * prescalar * (1 + TOP))
// Fpwm = 50 Hz

#ifndef SG90
#define SG90

#include "../MCAL/STD_TYPES.h"
#include "../MCAL/GPIO.h"
#include "../MCAL/config.h"

#define SERVO_Pin portb,pin2

#define OCR1A ((F_CPU / 256 / 50) - 1)

void servo_init(void);
void servo_set_angle(s8 angle);

#endif