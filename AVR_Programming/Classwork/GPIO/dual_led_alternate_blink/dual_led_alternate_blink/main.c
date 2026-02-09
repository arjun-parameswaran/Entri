/*
 * dual_led_alternate_blink.c
 
 * Description: Alternating LED control on PD2 and PD3 using bitwise GPIO configuration with blocking delays
 * Created: 15-11-2025 20:55:48
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL     /* CPU frequency */
#include <avr/io.h>
#include <util/delay.h>      /* Required for _delay_ms() */

int main(void)
{
	DDRD |= (1 << DDD2) | (1 << DDD3); /*configuring PD2  and PD3 as output*/
	
	while (1)
	{
		/*pin1 ON and Pin2 OFF*/
		PORTD |= (1 << PD2);
		PORTD &= ~(1 << PD3);
		_delay_ms(5000);
		
		/*pin1 and pin2 OFF*/
		PORTD &= ~(1 << PD3);
		PORTD &= ~(1 << PD2);
		_delay_ms(3000);
		
		/*pin1 OFF and pin2 ON*/
		PORTD  |= (1 << PD3);
		PORTD &= ~(1 << PD2);
		_delay_ms(5000);
		
		/*pin1 and pin2 OFF*/
		PORTD &= ~(1 << PD3);
		PORTD &= ~(1 << PD2);
		_delay_ms(3000);
		
	}
	
	return 0;
}

