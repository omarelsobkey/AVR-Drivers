/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 11/7/2021
********************************************************************/

#include "LCD.h"
#include "macros.h"
#include <util/delay.h>

void lcd_init(void){
    set_port_direction(LCD_DataPort);           // set port pins as output
	set_pin_direction(RS);                      // set reset pin as output
	set_pin_direction(RW);                      // set read/write pin as output    
	set_pin_direction(E);                       // set enable pin as output

    _delay_ms(100);                             // Power-up delay

    clr_pin_value(RS, 0);                       // select the Instruction Register (RS low)
    clr_pin_value(E, 0);                        // make sure E is initially low

    lcd_send_instruction(LCD_FunctionReset);    // first part of reset sequence
    _delay_ms(10);                              // 4.1 mS delay (min)

    lcd_send_instruction(LCD_FunctionReset);    // second part of reset sequence
    _delay_us(200);                             // 100uS delay (min)

    lcd_send_instruction(LCD_FunctionReset);    // third part of reset sequence
    _delay_us(200);                             // this delay is omitted in the data sheet

    lcd_send_instruction(LCD_FunctionSet);      // set data lines
    _delay_us(80);                              // operation time

    lcd_send_instruction(LCD_DisplayOff);       // display off
    _delay_us(80);                              // operation time

    lcd_send_instruction(LCD_Clear);            // clear any display
    _delay_ms(4);                               // operation time

    lcd_send_instruction(LCD_EntryMode);        // cursor shifting
    _delay_us(80);                              // operation time

    lcd_send_instruction(LCD_DisplayOn);        // re open display
    _delay_us(80);                              // operation time
}

void lcd_send_data(u8 data){
    write_port_value(LCD_DataPort, data);        // write data

    set_pin_value(E); // enable = high
    _delay_ms(1);
    clr_pin_value(E); // enable = low
    _delay_ms(1);
}

void lcd_send_instruction(u8 instructions){
    // send instructions to lcd
    // RS must be low, E must be low
    clr_pin_value(RS);
    clr_pin_value(E);

    lcd_send_data(instructions);
}

void lcd_send_char(u8 character){
    // send char to lcd
    // RS must be high, E must be low
    set_pin_value(RS);            
    clr_pin_value(RW);               
    
    lcd_send_data(character);
}

void lcd_send_string(u8 *string){
    // send string to lcd by sending char by char
	while((*string)!='\0'){
		lcd_send_char(*string);
		string++;
	}
}

void lcd_set_cursor(u8 col, u8 row){
    // set the position of the cursor
    if(col < 16){
        switch(row){
            case 0: lcd_send_instruction(LCD_SetCursor + LCD_LineOne + col); break;
            case 1: lcd_send_instruction(LCD_SetCursor + LCD_LineTwo + col); break;
        }
    }
}

void lcd_set_cgram(){
    // send 0 [not '0'] using [send_char()] to get this special sympol
    lcd_send_instruction(0b01000000); 
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);

    // send 1 [not '1'] using [send_char()] to get this special sympol
    lcd_send_instruction(0b01001000); 
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    
     // send 2 [not '2'] using [send_char()] to get this special sympol
    lcd_send_instruction(0b01010000);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    
    // send 3 [not '3'] using [send_char()] to get this special sympol
    lcd_send_instruction(0b01011000); 
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    
    // send 4 [not '4'] using [send_char()] to get this special sympol
    lcd_send_instruction(0b01100000); 
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    
    // send 5 [not '5'] using [send_char()] to get this special sympol
    lcd_send_instruction(0b01101000); 
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);

    // send 6 [not '6'] using [send_char()] to get this special sympol
    lcd_send_instruction(0b01110000); 
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);

    // send 7 [not '7'] using [send_char()] to get this special sympol
    lcd_send_instruction(0b01111000); 
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
    lcd_send_char(0b00011111);
}