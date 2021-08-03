/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 28/7/2021
********************************************************************/

#ifndef MOTOR
#define MOTOR

#include "../MCAL/STD_TYPES.h"

#define MOTOR1_Pin1   portb,pin0
#define MOTOR1_Pin2   portb,pin1
#define MOTOR2_Pin1   portb,pin2
#define MOTOR2_Pin2   portb,pin3

void motor_init(void);

void motor_move(u8 right_wheel, u8 left_wheel);

#endif