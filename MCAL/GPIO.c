/********************************************************************
Engineer        : Omar Elsobkey
Version         : 2.1
Date            : 10/7/2021
********************************************************************/

#include "GPIO.h"
#include "memoryMap.h"
#include "macros.h"

void set_pin_direction(u8 port, u8 pinNumber){
	switch(port){
		case porta: SET_BIT(DDRA, pinNumber); break;
		case portb: SET_BIT(DDRB, pinNumber); break;
		case portc: SET_BIT(DDRC, pinNumber); break;
		case portd: SET_BIT(DDRD, pinNumber); break;
	}
}
void set_port_direction(u8 port){
	switch(port){
		case porta: DDRA = 0xff; break;
		case portb: DDRB = 0xff; break;
		case portc: DDRC = 0xff; break;
		case portd: DDRD = 0xff; break;
	}
}

void clr_pin_direction(u8 port, u8 pinNumber){
	switch(port){
		case porta: CLR_BIT(DDRA, pinNumber); break;
		case portb: CLR_BIT(DDRB, pinNumber); break;
		case portc: CLR_BIT(DDRC, pinNumber); break;
		case portd: CLR_BIT(DDRD, pinNumber); break;
	}
}
void clr_port_direction(u8 port){
	switch(port){
		case porta: DDRA = 0; break;
		case portb: DDRB = 0; break;
		case portc: DDRC = 0; break;
		case portd: DDRD = 0; break;
	}
}

void write_port_direction(u8 port, u8 direction){
	switch(port){
		case porta: DDRA = direction; break;
		case portb: DDRB = direction; break;
		case portc: DDRC = direction; break;
		case portd: DDRD = direction; break;
	}
}

void set_pin_value(u8 port, u8 pinNumber){
	switch(port){
		case porta: SET_BIT(PORTA, pinNumber); break;
		case portb: SET_BIT(PORTB, pinNumber); break;
		case portc: SET_BIT(PORTC, pinNumber); break;
		case portd: SET_BIT(PORTD, pinNumber); break;
	}
}
void set_port_value(u8 port){
	switch(port){
		case porta: PORTA = 0xff; break;
		case portb: PORTB = 0xff; break;
		case portc: PORTC = 0xff; break;
		case portd: PORTD = 0xff; break;
	}
}

void clr_pin_value(u8 port, u8 pinNumber){
	switch(port){
		case porta: CLR_BIT(PORTA, pinNumber); break;
		case portb: CLR_BIT(PORTB, pinNumber); break;
		case portc: CLR_BIT(PORTC, pinNumber); break;
		case portd: CLR_BIT(PORTD, pinNumber); break;
	}
}
void clr_port_value(u8 port){
	switch(port){
		case porta: PORTA = 0; break;
		case portb: PORTB = 0; break;
		case portc: PORTC = 0; break;
		case portd: PORTD = 0; break;
	}
}

void write_port_value(u8 port, u8 value){
	switch(port){
		case porta: PORTA = value; break;
		case portb: PORTB = value; break;
		case portc: PORTC = value; break;
		case portd: PORTD = value; break;
	}
}

void tog_pin(u8 port, u8 pinNumber){
	switch(port){
		case porta: TOG_BIT(PORTA, pinNumber); break;
		case portb: TOG_BIT(PORTB, pinNumber); break;
		case portc: TOG_BIT(PORTC, pinNumber); break;
		case portd: TOG_BIT(PORTD, pinNumber); break;
	}
}
void tog_port(u8 port){
	switch(port){
		case porta: PORTA = ~PORTA; break;
		case portb: PORTB = ~PORTB; break;
		case portc: PORTC = ~PORTC; break;
		case portd: PORTD = ~PORTD; break;
	}
}

u8 get_pin_value(u8 port, u8 pinNumber){
	switch(port){
		case porta: return GET_BIT(PINA, pinNumber);
		case portb: return GET_BIT(PINB, pinNumber);
		case portc: return GET_BIT(PINC, pinNumber);
		case portd: return GET_BIT(PIND, pinNumber);
	}
	return 0;
}
u8 get_port_value(u8 port){
	switch(port){
		case porta: return PINA;
		case portb: return PINB;
		case portc: return PINC;
		case portd: return PIND;
	}
	return 0;
}
