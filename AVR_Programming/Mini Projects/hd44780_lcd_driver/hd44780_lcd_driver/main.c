/*
 * hd44780_lcd_driver.c
 *
 * Created: 27-01-2026 18:16:58
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "hd44780.h"
void gpio_init()
{
	DDRD &= ~(1 << DDD2);
	PORTD |= (1 <<PD2);
	DDRC |= (1 << DDC2);
	//PORTC |= (1 << PC2);
}
int main(void)
{
	
	lcd_init();
	gpio_init();
	lcd_set_cursor(0,1);
	lcd_print("It's Working!!");
	


	uint16_t i = 0;	
    while (1) 
    {	
		if(!(PIND & (1 << PD2)))
		{
			PORTC ^= (1 << PC2);
		}
		lcd_set_cursor(1,1);
		lcd_print("It's Working!!");
				
    }
}

