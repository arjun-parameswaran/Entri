/*
 * simple_led_blink_test.c
 
 * Description: Program to turn on and off a led in every one second. (first program).
 * Created: 13-11-2025 21:18:31
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL     // CPU frequency
#include <avr/io.h>
#include <util/delay.h>      // Required for _delay_ms() and _delay_us()


int main(void)
{
	DDRD = 0b00000100; /*setting PD2 as output*/
	
	while (1)
	{
		PORTD = 0b00000100;   // Turn PD2 HIGH
		_delay_ms(1000);       // 1000 ms delay

		PORTD = 0b00000000;   // Turn PD2 LOW
		_delay_ms(1000);       // 1000 ms delay
		
	}
}


