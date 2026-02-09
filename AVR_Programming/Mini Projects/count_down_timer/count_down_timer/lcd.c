/*
 * lcd.c
 *
 * Created: 05-02-2026 11:30:40
 *  Author: ARJUN
 */ 
/*LCD Initialization function*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "main.h"

void lcd_init()
{
	//Configure RS,EN and Data pins as Output
	LCD_RS_DDR |= (1 << LCD_RS_PIN);
	LCD_EN_DDR |= (1 << LCD_EN_PIN);
	LCD_DATA_DDR |= (1 << LCD_D4_PIN | 1 << LCD_D5_PIN | 1 << LCD_D6_PIN | 1 << LCD_D7_PIN);
	_delay_ms(20);							//Power-Up Wait
	
	LCD_RS_PORT &= ~(1 << LCD_RS_PIN);		//RS = 0
	LCD_EN_PORT &= ~(1 << LCD_EN_PIN);		//EN = 0
	
	lcd_send_nibble(0x03);
	_delay_us(5);
	lcd_send_nibble(0x03);
	_delay_us(150);
	lcd_send_nibble(0x03);
	_delay_us(150);
	lcd_send_nibble(0x02);
	_delay_us(150);
	
	/*commands start from here !*/
	lcd_cmd(0x28);							//Enable 4-Bit mode
	lcd_cmd(0x08);							//Display OFF
	lcd_cmd(0x01);							//Clear Display
	lcd_cmd(0x06);							//Entry Mode : Increment, No shift
	lcd_cmd(0x0C);							//Display ON, Cursor OFF, Blink OFF
}
/**/
static void lcd_send_nibble(uint8_t nibble)
{
	//Clearing Data Pins D4 - D7
	LCD_DATA_PORT &= ~((1 << LCD_D4_PIN) | (1 << LCD_D5_PIN) | (1 << LCD_D6_PIN) | (1 << LCD_D7_PIN));
	//sending data by 4 bits
	LCD_DATA_PORT = ((LCD_DATA_PORT & 0x0F) | (nibble << 4));
	lcd_enable_pulse();
}
/*LCD Enable*/
void lcd_enable_pulse(void)
{
	LCD_EN_PORT |= (1 << LCD_EN_PIN);		//EN Port High
	_delay_us(1);
	LCD_EN_PORT &= ~(1 << LCD_EN_PIN);		//EN Port Low
	_delay_us(50);
}
/**/
static void lcd_send_byte(uint8_t value, uint8_t rs)
{
	if(rs == 1)
	{
		LCD_RS_PORT |= (1 << LCD_RS_PIN);	//RS Port High ~ Data
	}
	else
	{
		LCD_RS_PORT &= ~(1 << LCD_RS_PIN);	//RS port Low ~ Command
	}
	lcd_send_nibble(value >> 4);			//Sending upper nibble
	lcd_send_nibble(value & 0x0F);			//Sending lower nibble
	
}
/*send command to LCD*/
void lcd_cmd(uint8_t cmd)
{
	lcd_send_byte(cmd, 0);
	/*Clear Screen and Return Home required longer delays in write-only mode*/
	if (cmd == CLEAR_SCREEN || cmd == RETURN_HOME)
	{
		_delay_ms(2);
	}
}
/*send data to LCD*/
void lcd_data(uint8_t data)
{
	lcd_send_byte(data, 1);
}
/*to set the cursor at desired position*/
void lcd_set_cursor(uint8_t row, uint8_t col)				// receives row and column value 2X16 LCD
{
	uint8_t addr = (row ? 0x40 : 0x00) + (col & 0x0F);		// this is a ternary operator.
	lcd_cmd(0x80 | addr);									// send (80 + addr) as a command.
}
/*to clear the LCD Screen*/
void lcd_clear()
{
	lcd_cmd(CLEAR_SCREEN);
}
/*to return to the LCD Home-screen*/
void lcd_home()
{
	lcd_cmd(RETURN_HOME);
}
/*function to print the data on the LCD screen*/
void lcd_print(char *str)
{
	while(*str)
	{
		lcd_data((uint8_t) *str++);
	}
}

void lcd_print_uint16(uint16_t num)
{
	char buffer[6];				//buffer to contain the number
	utoa(num, buffer, 10);		//converting into string
	lcd_print(buffer);			//printing as string
}