/*
 * tactile_switch_test.c
 *
 * Created: 30-01-2026 20:55:30
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRD &= ~(1 << DDD2);
	PORTD |= (1 << PD2);
	DDRD |= (1 << PD3);
	uint8_t prev_state = 0;
    while (1) 
    {	
		#if 0
		if (!(PIND & (1 << PIND2)))
		{
			PORTD |= (1 << PD3);
		}
		else
		{
			PORTD &= ~(1 << PD3);
		}
		#endif
		
		#if 1
		uint8_t curr_state = (!(PIND & (1 << PIND2)))? 1 : 0;
		if (prev_state == 0 && curr_state == 1)
		{
			PORTD ^= (1 << PD3);
		}
		prev_state = curr_state;
		#endif
		 
    }
}

