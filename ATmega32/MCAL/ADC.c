/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 13/7/2021
Microcontroller : ATmega32
Crystal         : 8Mhz
********************************************************************/

#include "ADC.h"

void adc_init(void){
    // ADC Enable
    SET_BIT(ADCSRA, ADEN);

    // Start conversion
    SET_BIT(ADCSRA, ADSC);
    
    // Single conversion mode (not auto triggered)
    CLR_BIT(ADCSRA, ADATE);
    
    // Clear ADC flag
    SET_BIT(ADCSRA, ADIF);
    
    // Pooling (not using interrupt)
    CLR_BIT(ADCSRA, ADIE);

    // Prescalar Configuration as 128 (the largest prescalar)
    SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS0);

    // choose channel 0 as input
    CLR_BIT(ADMUX, MUX0);
    CLR_BIT(ADMUX, MUX1);
    CLR_BIT(ADMUX, MUX2);
    CLR_BIT(ADMUX, MUX3);
    CLR_BIT(ADMUX, MUX4);

    // ADC data right adjustment
    CLR_BIT(ADMUX, ADLAR);

    // choose AVCC as refrence voltage
    SET_BIT(ADMUX, REFS0);
    CLR_BIT(ADMUX, REFS1);
}

u16 adc_get_pin_value(u8 channel){
    // return to channel 0
    CLR_BIT(ADMUX, MUX0);
    CLR_BIT(ADMUX, MUX1);
    CLR_BIT(ADMUX, MUX2);
    CLR_BIT(ADMUX, MUX3);
    CLR_BIT(ADMUX, MUX4);

    // choose which pin will input the ADC
	ADMUX |= channel;
	
	// Start conversion
    SET_BIT(ADCSRA, ADSC);

    // stay here while conversion still on going
	while(GET_BIT(ADCSRA, ADSC)); 
    
    // return the converted value (0:1023)
	return ADC_Value; 
}