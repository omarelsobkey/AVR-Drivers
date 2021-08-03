/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 10/7/2021
Microcontroller : ATmega32
********************************************************************/

#ifndef MEMORY_MAP
#define MEMORY_MAP

#include "STD_TYPES.h"

// PORTA
#define DDRA 	*((volatile u8 *)0x3A)
#define PORTA 	*((volatile u8 *)0x3B)
#define PINA 	*((volatile u8 *)0x39) 

// PORTB
#define DDRB 	*((volatile u8 *)0x37)
#define PORTB 	*((volatile u8 *)0x38)
#define PINB 	*((volatile u8 *)0x36)

// PORTC
#define DDRC 	*((volatile u8 *)0x34)
#define PORTC 	*((volatile u8 *)0x35)
#define PINC 	*((volatile u8 *)0x33)

// PORTD
#define DDRD 	*((volatile u8 *)0x31)
#define PORTD 	*((volatile u8 *)0x32)
#define PIND 	*((volatile u8 *)0x30)

// ADC
#define ADMUX   *((volatile u8 *)0x27) 
#define ADCSRA  *((volatile u8 *)0x26) 
#define ADCH    *((volatile u8 *)0x25) 
#define ADCL    *((volatile u8 *)0x24) 

// USART
#define UCSRA   *((volatile u8 *)0x2B) 
#define UCSRB   *((volatile u8 *)0x2A) 
#define UCSRC   *((volatile u8 *)0x40)
#define UBRRH   *((volatile u8 *)0x40) 
#define UBRRL   *((volatile u8 *)0x29) 
#define UDR     *((volatile u8 *)0x2C) 

// Timer/Counter 0
#define TCCR0   *((volatile u8 *)0x53)
#define OCR0    *((volatile u8 *)0x5C)
#define TCNT0   *((volatile u8 *)0x52)

// Timer/Counter 1
#define TCCR1A  *((volatile u8 *)0x4F)
#define TCCR1B  *((volatile u8 *)0x4E) 
#define OCR1AH  *((volatile u8 *)0x4B) 
#define OCR1AL  *((volatile u8 *)0x4A) 
#define OCR1BH  *((volatile u8 *)0x49)
#define OCR1BL  *((volatile u8 *)0x48) 
#define ICR1H   *((volatile u8 *)0x47) 
#define ICR1L   *((volatile u8 *)0x46) 
#define TCNT1H  *((volatile u8 *)0x4D) 
#define TCNT1L  *((volatile u8 *)0x4C)

// Timer/Counter 2
#define TCCR2   *((volatile u8 *)0x45) 
#define OCR2    *((volatile u8 *)0x43) 
#define TCNT2   *((volatile u8 *)0x44) 

#define SREG    *((volatile u8 *)0x5F)
#define SPH     *((volatile u8 *)0x5E)
#define SPL     *((volatile u8 *)0x5D)
#define GICR    *((volatile u8 *)0x5B)
#define GIFR    *((volatile u8 *)0x5A)
#define TIMSK   *((volatile u8 *)0x59)
#define TIFR    *((volatile u8 *)0x58)
#define SPMCR   *((volatile u8 *)0x57)
#define TWCR    *((volatile u8 *)0x56)
#define MCUCR   *((volatile u8 *)0x55)
#define MCUCSR  *((volatile u8 *)0x54)
#define OSCCAL  *((volatile u8 *)0x51)
#define OCDR    *((volatile u8 *)0x51)
#define SFIOR   *((volatile u8 *)0x50) 
#define ASSR    *((volatile u8 *)0x42) 
#define WDTCR   *((volatile u8 *)0x41) 
#define EEARH   *((volatile u8 *)0x3F)
#define EEARL   *((volatile u8 *)0x3E) 
#define EEDR    *((volatile u8 *)0x3D) 
#define EECR    *((volatile u8 *)0x3C) 
#define SPDR    *((volatile u8 *)0x2F) 
#define SPSR    *((volatile u8 *)0x2E)
#define SPCR    *((volatile u8 *)0x2D) 
#define ACSR    *((volatile u8 *)0x28) 
#define TWDR    *((volatile u8 *)0x23) 
#define TWAR    *((volatile u8 *)0x22)

#endif