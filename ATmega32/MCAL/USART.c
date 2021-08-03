/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.1
Date            : 24/7/2021
Microcontroller : ATmega32
Crystal         : 8Mhz
********************************************************************/

#include "USART.h"
#include "macros.h"

void usart_init(u16 baud){
	u16 UBRR = (F_CPU / (16 * baud)) - 1;

	// Set baud rate
	UBRRH = (u8)(UBRR>>8);
	UBRRL = (u8)UBRR;

	// Enable receiver and transmitter
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);

	/* Set frame format */
	SET_BIT(UCSRC, URSEL);  // URSEL must be one while accessing UCSRC
	SET_BIT(UCSRC, UCSZ0);  // 8 bits
	SET_BIT(UCSRC, UCSZ1);
}

void usart_transmit_char(u8 data){
	// Wait for empty transmit buffer
	while (!GET_BIT(UCSRA, UDRE));
	
	// Put data into buffer, sends the data
	UDR = data;
}

void usart_transmit_9bit(u16 data){
	// Wait for empty transmit buffer
	while (!GET_BIT(UCSRA, UDRE));
	
	// write the 9th bit before sending data to buffer
	if (data & 0x100) SET_BIT(UCSRB, TXB8);
	else CLR_BIT(UCSRB, TXB8);

	// Put data into buffer, sends the data
	UDR = data;
}

void usart_transmit_string(u8* str){
	u8 i = 0;
	while(str[i] != '\0'){
		usart_transmit_char(str[i]);
		i++;
	}
}

u8 usart_available(void){
	return GET_BIT(UCSRA, RXC);
}

u8 usart_receive_char(void){
	// wait for data to be fully received
	while(!usart_available());

	// Get and return received data from buffer
	return UDR;
}

u16 usart_receive_9bit(void){
	u8 resh, resl;

	// wait for data to be fully received
	while(!usart_available());

	resh = UCSRB;   // Get 9th bit
	resl = UDR;     // Get data from buffer

	// If Frame Error, Data OverRun or Parity Error -> return -1
	if (GET_BIT(UCSRA, FE) || GET_BIT(UCSRA, DOR) || GET_BIT(UCSRA, PE)) return -1;

	resh = (resh >> 1) & 0x01; // Filter the 9th bit (move it to bit0 of resh)
	return ((resh << 8) | resl);
}

void usart_receive_string(u8* str){
	u8 i = 0;
	str[i] = usart_receive_char();
	while(str[i] != '#'){
		i++;
		str[i] = usart_receive_char();
	}
	str[i] = '\0';
}

// to remove any remaining data in the receiving buffer before closing it
void usart_flush(void){
	u8 dummy;
	while (GET_BIT(UCSRA, RXC)) dummy = UDR;
}