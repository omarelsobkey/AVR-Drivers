/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 10/7/2021
********************************************************************/

#ifndef SEVEN_SEGMENT
#define SEVEN_SEGMENT

#include "STD_TYPES.h"

void sevseg_init(u8 port);
void sevseg_write_number(u8 port, u8 num);

#endif