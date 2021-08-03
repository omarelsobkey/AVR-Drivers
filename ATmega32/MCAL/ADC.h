/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 13/7/2021
Microcontroller : ATmega32
Crystal         : 8Mhz
********************************************************************/

#ifndef ADC
#define ADC

#include "STD_TYPES.h"

// ADMUX pins
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0

// ADCSRA pins
#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

// PORTA pins
#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

// ADC pins
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

// Conversion result
#define ADC_Value (ADCL | (ADCH << 8))

void adc_init(void);
u16 adc_get_pin_value(u8 channel);

#endif