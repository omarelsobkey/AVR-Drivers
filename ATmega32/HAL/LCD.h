/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.1
Date            : 11/7/2021
********************************************************************/

#ifndef LCD
#define LCD

#include "STD_TYPES.h"

#define LCD_DataPort        porta
#define RS                  portd,pin0
#define RW                  portd,pin1
#define E                   portd,pin2

#define LCD_LineOne         0x00        // start of line 1
#define LCD_LineTwo         0x40        // start of line 2
#define LCD_LineOne         0x80        // start of line 3
#define LCD_LineTwo         0xC0        // start of line 4

#define LCD_Clear           0b00000001  // replace all characters with ASCII 'space'
#define LCD_ReturnHome      0b00000010  // return cursor to first position on first line
#define LCD_FunctionReset   0b00110000  // reset the LCD
#define LCD_SetCursor       0b10000000  // set cursor position (set position + row address + column number)

// bit4 -> data lines (1 for 8/0 for 4), bit3 -> lines (1 for 2/0 for 1), bit2 -> font (1 for 5*11/0 for 5*8)
#define LCD_FunctionSet     0b00111000

// bit1 -> writing direction from (0 right/1 left), bit0 -> enable shift of entire display
#define LCD_EntryMode       0b00000110 

// bit2 -> display on/off, bit1 -> cursor on/off, bit0 -> cursor blink
#define LCD_DisplayOff      0b00001000
#define LCD_DisplayOn       0b00001110

// bit4 -> Display shift, bit3 -> direction (0 left/1 right)
#define LCD_DisplayShift    0b00010000


void lcd_init(void);

void lcd_send_data(u8 data);
void lcd_send_instruction(u8 instructions);
void lcd_send_char(u8 character);
void lcd_send_string(u8 *string);

void lcd_set_cursor(u8 col, u8 row);

void lcd_set_cgram();
#endif