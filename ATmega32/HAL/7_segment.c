/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 10/7/2021
********************************************************************/
// a = pin7
// b = pin6
// c = pin5
// d = pin4
// e = pin3
// f = pin2
// g = pin1

#include "7_segment.h"

void sevseg_init(u8 port){
	set_port_direction(port);
}

void sevseg_write_number(u8 port, u8 num){
	unsigned char numbers[] = {	0b11111100,  // 0
								0b01100000,  // 1
								0b11011010,  // 2
								0b11110010,  // 3
								0b01100110,  // 4
								0b10110110,  // 5
								0b10111110,  // 6
								0b11100000,  // 7
								0b11111111,  // 8
								0b11110110}; // 9
	
	write_port_value(port, numbers[num]);
}