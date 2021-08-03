/********************************************************************
Engineer        : Omar Elsobkey
Version         : 2.1
Date            : 10/7/2021
********************************************************************/

#ifndef GPIO
#define GPIO

#include "STD_TYPES.h"

// the arrange of the ports
#define porta 0
#define portb 1
#define portc 2
#define portd 3

// the arrange of the pins
#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7

// the arrange of the PORTA pins
#define PA0 porta,pin0
#define PA1 porta,pin1
#define PA2 porta,pin2
#define PA3 porta,pin3
#define PA4 porta,pin4
#define PA5 porta,pin5
#define PA6 porta,pin6
#define PA7 porta,pin7

// the arrange of the PORTB pins
#define PB0 portb,pin0
#define PB1 portb,pin1
#define PB2 portb,pin2
#define PB3 portb,pin3
#define PB4 portb,pin4
#define PB5 portb,pin5
#define PB6 portb,pin6
#define PB7 portb,pin7

// the arrange of the PORTC pins
#define PC0 portc,pin0
#define PC1 portc,pin1
#define PC2 portc,pin2
#define PC3 portc,pin3
#define PC4 portc,pin4
#define PC5 portc,pin5
#define PC6 portc,pin6
#define PC7 portc,pin7

// the arrange of the PORTD pins
#define PD0 portd,pin0
#define PD1 portd,pin1
#define PD2 portd,pin2
#define PD3 portd,pin3
#define PD4 portd,pin4
#define PD5 portd,pin5
#define PD6 portd,pin6
#define PD7 portd,pin7

// the arrange 
#define OUTPUT 1
#define INPUT 0

void set_pin_direction(u8 port, u8 pinNumber);
void set_port_direction(u8 port);

void clr_pin_direction(u8 port, u8 pinNumber);
void clr_port_direction(u8 port);

void write_port_direction(u8 port, u8 direction);

void set_pin_value(u8 port, u8 pinNumber);
void set_port_value(u8 port);

void clr_pin_value(u8 port, u8 pinNumber);
void clr_port_value(u8 port);

void write_port_value(u8 port, u8 value);

void tog_pin(u8 port, u8 pinNumber);
void tog_port(u8 port);

u8 get_pin_value(u8 port, u8 pinNumber);
u8 get_port_value(u8 port);

#endif