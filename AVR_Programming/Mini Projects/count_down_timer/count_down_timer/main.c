/*
 * count_down_timer.c
 *
 * Created: 05-02-2026 11:07:22
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "main.h"

uint16_t sec = 0, min = 0;
uint8_t field;
int main(void)
{
    //gpio_init();
	lcd_init();
	//timer_interrupt_init();
	//ext_interrupt_init();
	sei();
	
    while (1) 
    {
		set_timer();
    }
}

