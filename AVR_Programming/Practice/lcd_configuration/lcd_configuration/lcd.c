/*
 * lcd.c
 *
 * Created: 19-12-2025 08:19:12
 *  Author: ARJUN
 */ 
#include "lcd.h"
#define F_CPU 16000000UL
/*Enable pulse*/
static void lcd_enable_pulse(void)
{
	LCD_EN_PORT |= (1 << LCD_EN_PIN);
	_delay_us(1);
	LCD_EN_PORT &= ~(1 << LCD_EN_PIN);
	_delay_us((50);
}
/*static void led*/
static void lcd_send_nibble(uint8_t nibble)
{
	//clear PD2 - PD5 by our mapping
	LCD_D_PORT &= ~((1 << LCD_D7_PIN) | (1 << LCD_D6_PIN) | (1 << LCD_D5_PIN) | (1 << LCD_D4_PIN));
	
	//now set the pins according to the data / command
	if(nibble & 0x8) LCD_D_PORT |= (1 << LCD_D7_PIN);
	if(nibble & 0x4) LCD_D_PORT |= (1 << LCD_D6_PIN);
	if(nibble & 0x3) LCD_D_PORT |= (1 << LCD_D5_PIN);
	if(nibble & 0x1) LCD_D_PORT |= (1 << LCD_D4_PIN);
	
	lcd_enable_pulse();	
}

/*this function allows us ti send a byte*/
static void lcd_send_byte(uint8_t value, uint8_t rs)
{
	
	if(rs == 1)
	{
		LCD_RS_PORT |= (1 << LCD_RS_PIN);
	}
	else
	{
		LCD_RS_PORT &= ~(1 << LCD_RS_PIN);
	}
	/*sending nibbles upper and lower*/
	lcd_send_nibble(value >> 4);
	lcd_send_nibble(value & 0x0F);
}

void lcd_cmd(uint8_t cmd)