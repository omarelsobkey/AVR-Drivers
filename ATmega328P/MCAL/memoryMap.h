/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 10/7/2021
Microcontroller : ATmega328P
********************************************************************/

#ifndef MEMORY_MAP
#define MEMORY_MAP

// PORTB
#define PINB 	*((volatile unsigned char *)0x23)
#define DDRB 	*((volatile unsigned char *)0x24)
#define PORTB 	*((volatile unsigned char *)0x25)

// PORTC
#define PINC 	*((volatile unsigned char *)0x26)
#define DDRC 	*((volatile unsigned char *)0x27)
#define PORTC 	*((volatile unsigned char *)0x28)

// PORTD
#define PIND 	*((volatile unsigned char *)0x29)
#define DDRD 	*((volatile unsigned char *)0x2A)
#define PORTD 	*((volatile unsigned char *)0x2B)

// ADC
#define ADCL 	*((volatile unsigned char *)0x78)
#define ADCH 	*((volatile unsigned char *)0x79)
#define ADCSRA 	*((volatile unsigned char *)0x7A)
#define ADCSRB 	*((volatile unsigned char *)0x7B)
#define ADMUX 	*((volatile unsigned char *)0x7C)

// USART
#define UCSR0A 	*((volatile unsigned char *)0xC0)
#define MPCM0   0
#define U2X0    1
#define UPE0    2
#define DOR0    3
#define FE0     4
#define UDRE0   5
#define TXC0    6
#define RXC0    7

#define UCSR0B 	*((volatile unsigned char *)0xC1)
#define TXB80   0
#define RXB80   1
#define UCSZ02  2
#define TXEN0   3
#define RXEN0   4
#define UDRIE0  5
#define TXCIE0  6
#define RXCIE0  7

#define UCSR0C 	*((volatile unsigned char *)0xC2)
#define UCPOL0  0
#define UCSZ00  1
#define UCSZ01  2
#define USBS0   3
#define UPM00   4
#define UPM01   5
#define UMSEL00 6
#define UMSEL01 7

#define UBRR0L 	*((volatile unsigned char *)0xC4)
#define UBRR0H 	*((volatile unsigned char *)0xC5)
#define UDR0 	*((volatile unsigned char *)0xC6)

// Timers/Counter 0
#define TCCR0A 	*((volatile unsigned char *)0x44)
#define TCCR0B 	*((volatile unsigned char *)0x45)
#define OCR0A 	*((volatile unsigned char *)0x47)
#define OCR0B 	*((volatile unsigned char *)0x48)
#define TCNT0 	*((volatile unsigned char *)0x46)
#define TIMSK0 	*((volatile unsigned char *)0x6E)

// Timer/Counter 1
#define TCCR1A 	*((volatile unsigned char *)0x80)
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define WGM11 1
#define WGM10 0

#define TCCR1B 	*((volatile unsigned char *)0x81)
#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12 2 
#define CS11 1
#define CS10 0

#define TCCR1C 	*((volatile unsigned char *)0x82)
#define OCR1AL 	*((volatile unsigned char *)0x88)
#define OCR1AH 	*((volatile unsigned char *)0x89)
#define OCR1BL 	*((volatile unsigned char *)0x8A)
#define OCR1BH 	*((volatile unsigned char *)0x8B)
#define ICR1L 	*((volatile unsigned char *)0x86)
#define ICR1H 	*((volatile unsigned char *)0x87)
#define TCNT1L 	*((volatile unsigned char *)0x84)
#define TCNT1H 	*((volatile unsigned char *)0x85)
#define TIMSK1 	*((volatile unsigned char *)0x6F)

// Timer/Counter 2
#define TCCR2A 	*((volatile unsigned char *)0xB0)
#define TCCR2B 	*((volatile unsigned char *)0xB1)
#define OCR2A 	*((volatile unsigned char *)0xB3)
#define OCR2B 	*((volatile unsigned char *)0xB4)
#define TCNT2 	*((volatile unsigned char *)0xB2)
#define TIMSK2 	*((volatile unsigned char *)0x70)


#define TIFR0	*((volatile unsigned char *)0x35)
#define TIFR1	*((volatile unsigned char *)0x36)
#define TIFR2	*((volatile unsigned char *)0x37)
#define PCIFR	*((volatile unsigned char *)0x3B)
#define EIFR 	*((volatile unsigned char *)0x3C)
#define EIMSK 	*((volatile unsigned char *)0x3D)
#define GPIOR0 	*((volatile unsigned char *)0x3E)
#define EECR 	*((volatile unsigned char *)0x3F)
#define EEDR 	*((volatile unsigned char *)0x40)
#define EEARL 	*((volatile unsigned char *)0x41)
#define EEARH 	*((volatile unsigned char *)0x42)
#define GTCCR 	*((volatile unsigned char *)0x43)
#define GPIOR1 	*((volatile unsigned char *)0x4A)
#define GPIOR2 	*((volatile unsigned char *)0x4B)
#define SPCR0 	*((volatile unsigned char *)0x4C)
#define SPSR0 	*((volatile unsigned char *)0x4D)
#define SPDR0 	*((volatile unsigned char *)0x4E)
#define ACSR 	*((volatile unsigned char *)0x50)
#define DWDR 	*((volatile unsigned char *)0x51)
#define SMCR 	*((volatile unsigned char *)0x53)
#define MCUSR 	*((volatile unsigned char *)0x54)
#define MCUCR 	*((volatile unsigned char *)0x55)
#define SPMCSR 	*((volatile unsigned char *)0x57)
#define SPL 	*((volatile unsigned char *)0x5D)
#define SPH 	*((volatile unsigned char *)0x5E)
#define SREG 	*((volatile unsigned char *)0x5F)
#define WDTCSR 	*((volatile unsigned char *)0x60)
#define CLKPR 	*((volatile unsigned char *)0x61)
#define PRR 	*((volatile unsigned char *)0x64)
#define OSCCAL	*((volatile unsigned char *)0x66)
#define PCICR 	*((volatile unsigned char *)0x68)
#define EICRA 	*((volatile unsigned char *)0x69)
#define PCMSK0 	*((volatile unsigned char *)0x6B)
#define PCMSK1 	*((volatile unsigned char *)0x6C)
#define PCMSK2 	*((volatile unsigned char *)0x6D)
#define DIDR0 	*((volatile unsigned char *)0x7E)
#define DIDR1 	*((volatile unsigned char *)0x7F)
#define ASSR 	*((volatile unsigned char *)0xB6)
#define TWBR 	*((volatile unsigned char *)0xB8)
#define TWSR 	*((volatile unsigned char *)0xB9)
#define TWAR 	*((volatile unsigned char *)0xBA)
#define TWDR 	*((volatile unsigned char *)0xBB)
#define TWCR 	*((volatile unsigned char *)0xBC)
#define TWAMR 	*((volatile unsigned char *)0xBD)

#endif