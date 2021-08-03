/********************************************************************
Engineer        : OmarElsobkey
Version         : 1.0
Date            : 6/2/2021
********************************************************************/

#ifndef KEYPAD
#define KEYPAD

#include "STD_TYPES.h"

#define KPD_Port    portc
#define R1          pin0
#define R2          pin1
#define R3          pin2
#define R4          pin3
#define C1          pin4
#define C2          pin5
#define C3          pin6
#define C4          pin7

#define KPD_Keys    {{'7', '8', '9', '/'}, \
                     {'4', '5', '6', '*'}, \
                     {'1', '2', '3', '-'}, \
                     {' ', '0', '=', '+'}}

void kpd_init(void);
u8 kpd_get_char(void);

#endif