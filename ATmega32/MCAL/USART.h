/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.1
Date            : 24/7/2021
Microcontroller : ATmega32
Crystal         : 8Mhz
********************************************************************/

#ifndef USART
#define USART

#include "STD_TYPES.h"
#include "config.h"

enum UCSRA_PINS{MPCM, U2X, PE, DOR, FE, UDRE, TXC, RXC};
enum UCSRB_PINS{TXB8, RXB8, UCSZ2, TXEN, RXEN, UDRIE, TXCIE, RXCIE};
enum UCSRC_PINS{UCPOL, UCSZ0, UCSZ1, USBS, UPM0, UPM1, UMSEL, URSEL};

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

