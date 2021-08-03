/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 19/7/2021
********************************************************************/

#include "SG90.h"
#include "../MCAL/memoryMap.h"
#include "../MCAL/macros.h"

void servo_init(void){
    set_pin_direction(SERVO_Pin);
    
    // Fast PWM, TOP is OCR1A
    SET_BIT(TCCR1A, WGM11);
    SET_BIT(TCCR1A, WGM10);
    SET_BIT(TCCR1B, WGM13);
    SET_BIT(TCCR1B, WGM12);

    // SET on match with OCRA, CLR on bottom
    SET_BIT(TCCR1A, COM1B1);
    CLR_BIT(TCCR1A, COM1B0);

    // 256 prescalar
    SET_BIT(TCCR1B, CS12);
    CLR_BIT(TCCR1B, CS11);
    CLR_BIT(TCCR1B, CS10);

    // freq = 50Hz
    OCR1AH = (u8)(OCR1A >> 8);
    OCR1AL = (u8)OCR1A;
}

void servo_set_angle(s8 angle){
	u8 dif = angle + 90;
	u16 pwm = (u16)((0.173 * dif) + 31.2);
	
	OCR1BH = (u8)(pwm >> 8);
	OCR1BL = (u8)pwm;
}