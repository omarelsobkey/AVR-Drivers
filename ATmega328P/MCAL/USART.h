/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 22/7/2021
Microcontroller : ATmega328P
Crystal			: 8Mhz
********************************************************************/

#ifndef USART
#define USART

#include "STD_TYPES.h"
#include "config.h"

#define UBRR ((F_CPU / 16 / baud) - 1)

void usart_init(u16 baud);

void usart_transmit_char(u8 data);
void usart_transmit_9bit(u16 data);
void usart_transmit_string(u8* str);
    
u8 usart_available(void);
u8 usart_receive_char(void);
u16 usart_receive_9bit(void);
void usart_receive_string(u8* str);

void usart_flush(void);

#endif

