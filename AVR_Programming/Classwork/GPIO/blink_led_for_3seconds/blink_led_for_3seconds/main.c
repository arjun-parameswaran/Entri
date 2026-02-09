/*
 * blink_led_for_3seconds.c
 * Description: program to blink LED for 3 sec on PORTD PIN5.
 * Created: 15-11-2025 19:26:31
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL     /* CPU frequency */
#include <avr/io.h>
#include <util/delay.h>      /* Required for _delay_ms() */


int main(void)
{
	DDRD |= 1 << 5; /*setting PD5 as output*/
	while (1)
	{
		PORTD  |= 1 << 5;      //Turn PD5 HIGH - LED ON
		_delay_ms(3000);       // 3000 ms delay

		PORTD = 0b00000000;    // Turn PD5 LOW _LED OFF
		_delay_ms(1000);       // 3000 ms delay	
	}
	return 0;
}
