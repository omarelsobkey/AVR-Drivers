/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 22/7/2021
Microcontroller : ATmega328P
Crystal			: 8Mhz
********************************************************************/

#include "memoryMap.h"
#include "USART.h"
#include "macros.h"

void usart_init(u16 baud){
	// Set baud rate
	UBRR0H = (u8)(UBRR >> 8);
	UBRR0L = (u8)UBRR;

	// Enable receiver and transmitter
	SET_BIT(UCSR0B, RXEN0);
	SET_BIT(UCSR0B, TXEN0);

	// Asynchronous USART, 8bit, 1 stop bit 
	SET_BIT(UCSR0C, UCSZ00);
	SET_BIT(UCSR0C, UCSZ01);
}

void usart_transmit_char(u8 data){
	// Wait for empty transmit buffer
	while (!GET_BIT(UCSR0A, UDRE0));
	
	// Put data into buffer, sends the data
	UDR0 = data;
}

void usart_transmit_9bit(u16 data){
	// Wait for empty transmit buffer
	while (!GET_BIT(UCSR0A, UDRE0));
	
	// write the 9th bit before sending data to buffer
	if (data & 0x100) SET_BIT(UCSR0B, TXB80);
	else CLR_BIT(UCSR0B, TXB80);

	// Put data into buffer, sends the data
	UDR0 = data;
}

void usart_transmit_string(u8* str){
	u8 i = 0;
	while(str[i] != '\0'){
		usart_transmit_char(str[i]);
		i++;
	}
}

u8 usart_available(void){
	return GET_BIT(UCSR0A, RXC0);
}

u8 usart_receive_char(void){
	// wait for data to be fully received
	while(!usart_available());

	// Get and return received data from buffer
	return UDR0;
}

u16 usart_receive_9bit(void){
	u8 resh, resl;

	// wait for data to be fully received
	while(!usart_available());

	resh = UCSR0B;   // Get 9th bit
	resl = UDR0;     // Get data from buffer

	// If Frame Error, Data OverRun or Parity Error -> return -1
	if (GET_BIT(UCSR0A, FE0) || GET_BIT(UCSR0A, DOR0) || GET_BIT(UCSR0A, UPE0)) return -1;

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
	while (GET_BIT(UCSR0A, RXC0)) dummy = UDR0;
}