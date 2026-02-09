/*
 * lcd_stopwatch.c
 *
 * Created: 30-01-2026 14:37:44
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>

#include "main.h"

/*variables*/
volatile uint16_t press_timer;
volatile uint16_t ms;
volatile uint8_t sec;
volatile uint8_t min;
/*flag variables*/
volatile uint8_t stopwatch_enable_flag = 0;
volatile uint8_t blink_flag  = 1;
volatile uint8_t switch_flag = 0; 
volatile uint8_t longpress_flag = 0;
int main(void)
{
	gpio_init();
	timer1_init();
	lcd_init();
	sei();

    while (1) 
    {
		stopwatch_display();
		uint8_t curr_state = (SWITCH_PRESSED);
		if (curr_state == 1)
		{
			press_timer++;
			if(press_timer >= LONG_PRESS_TIME && !longpress_flag)
			{
				cli();
				stopwatch_enable_flag = DISABLE;
				min = sec = ms = RESET;		
				longpress_flag = ENABLE;	
				blink_flag = ENABLE;	
				stopwatch_display();
				sei();
			}
		}
		else
		{
			if(press_timer > SHORT_PRESS_TIME && !longpress_flag)
			{
				stopwatch_enable_flag ^= 1;
				blink_flag = ENABLE;
			}
			press_timer = RESET;
			longpress_flag = DISABLE;
			
		}
		
		
    }
}

