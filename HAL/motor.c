/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 28/7/2021
********************************************************************/

#include "motor.h"
#include "../MCAL/GPIO.h"

void motor_init(void){
    set_pin_direction(MOTOR1_Pin1);
    set_pin_direction(MOTOR1_Pin2);
    set_pin_direction(MOTOR2_Pin1);
    set_pin_direction(MOTOR2_Pin2);
}

void motor_move(s16 right_wheel, s16 left_wheel){
    if(right_wheel >= 0){
        set_pin_direction(MOTOR1_Pin1);
        clr_pin_direction(MOTOR1_Pin2);
    } else if(right_wheel < 0){
        clr_pin_direction(MOTOR1_Pin1);
        set_pin_direction(MOTOR1_Pin2);
    }

    if(left_wheel >= 0){
        set_pin_direction(MOTOR2_Pin1);
        clr_pin_direction(MOTOR2_Pin2);
    } else if(left_wheel < 0){
        clr_pin_direction(MOTOR2_Pin1);
        set_pin_direction(MOTOR2_Pin2);
    }
}
