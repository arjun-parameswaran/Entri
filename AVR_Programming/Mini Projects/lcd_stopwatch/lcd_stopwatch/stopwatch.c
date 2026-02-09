/*
 * stopwatch.c
 *
 * Created: 30-01-2026 17:33:32
 *  Author: ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>
#include "main.h"

/*function to disokay the stopwatch in MM:SS:MS formant*/
void stopwatch_display()
{

	lcd_set_cursor(0, 4);
	lcd_print("MM:SS:MS");
	lcd_set_cursor(1, 4);
	lcd_print_time(min);
	/*blink logic for semicolon for every 500 ms -when stopwatch is running*/
	if(blink_flag)
	{
		lcd_set_cursor(1, 6);			
		lcd_print(":");
		lcd_set_cursor(1, 9);				
		lcd_print(":");
		
	}
	else
	{
		lcd_set_cursor(1, 6);
		lcd_print(" ");
		lcd_set_cursor(1, 9);
		lcd_print(" ");
	}
	lcd_set_cursor(1, 7);
	lcd_print_time(sec);
	lcd_set_cursor(1, 10);
	lcd_print_time(ms/10);
}