/*
 * led_blink_with_bitwise_register_configuration.c
 
 * Description: LED blinking using bitwise register manipulation with blocking delay.
 * Created: 15-11-2025 20:30:50
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL     /* CPU frequency */
#include <avr/io.h>
#include <util/delay.h>      /* Required for _delay_ms() */


int main(void)
{
	DDRD |= (1 << DDD2); /*setting PD2 as output*/
	
	while (1)
	{
		PORTD  |= (1 << PD2);    //Turn PD2 HIGH
		_delay_ms(3000);         // 3000 ms delay

		PORTD &= ~(1 << PD2);    // Turn PD2 LOW
		_delay_ms(3000);         // 3000 ms delay	
	}
	return 0;
}
