/*
 * led_toggle_with_xor_operator.c
 * Description: LED toggling on PD2 using XOR with a 3-second blocking delay.
 * Created: 15-11-2025 20:51:40
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL     /* CPU frequency */
#include <avr/io.h>
#include <util/delay.h>      /* Required for _delay_ms() */


int main(void)
{
	DDRD |= (1 << DDD2); /*configuring PD2 as output*/
	
	while (1)
	{
		/*Blinking using XOR - Toggling Method*/
		
		PORTD  ^= (1 << PD2);    //Turn PD2 HIGH and LOW alternatively
		_delay_ms(3000);         // 3000 ms delay
	}
	return 0;
}

