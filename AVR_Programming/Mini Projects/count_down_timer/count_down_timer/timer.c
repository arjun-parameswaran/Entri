/*
 * timer.c
 *
 * Created: 05-02-2026 11:22:22
 *  Author: ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "main.h"



void set_timer()
{
	lcd_set_cursor(0,2);
	lcd_print("SET TIMER");
	lcd_set_cursor(1,4);
	lcd_print_uint16(min);
	lcd_set_cursor(1,6);
	lcd_print(":");
	lcd_set_cursor(1,7);
	lcd_print_uint16(min);
	
}