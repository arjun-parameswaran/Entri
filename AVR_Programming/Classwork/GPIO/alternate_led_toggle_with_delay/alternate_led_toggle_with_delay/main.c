/*
 * alternate_led_toggle_with_delay.c
 * 
 * Created: 15-11-2025 23:04:53
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL     /* CPU frequency */
#include <avr/io.h>
#include <util/delay.h>      /* Required for _delay_ms() */
#define LED1 PD2
#define LED2 PD3

int main(void)
{
	DDRD |= ((1 << DDD2) | (1 << DDD3)); /*configuring PD2  and PD3 as output*/
	
	while (1)
	{
		/*pin1 ON and Pin2 OFF*/
		PORTD |= (1 << LED1);
		PORTD &= ~(1 << LED2);
		_delay_ms(5000);
		
		/*pin1 and pin2 OFF*/
		PORTD &= ~(1 << LED1);
		PORTD &= ~(1 << LED2);
		_delay_ms(3000);
		
		/*pin1 OFF and pin2 ON*/
		PORTD &= ~(1 << LED1);
		PORTD  |= (1 << LED2);
	
		_delay_ms(5000);
		
		/*pin1 and pin2 OFF*/
		PORTD &= ~(1 << LED1);
		PORTD &= ~(1 << LED2);
		_delay_ms(3000);
		
	}
	
	return 0;
}

