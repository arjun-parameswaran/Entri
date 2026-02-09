/*
 * toggle_switch.c
 *
 * Created: 13-12-2025 01:03:45
 * Author : ARJUN
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define SWITCH PB7
#define  LED PB5
#define SWITCH_PRESS (!(PINB & (1 << SWITCH)))



int main(void)
{
	DDRB &= ~(1 << DDB7);
	DDRB |= (1 << DDB5);
	PORTB |= (1 << SWITCH);
	PORTB &= ~(1 << LED);
    while (1) 
    {
		if(SWITCH_PRESS)
		{
			_delay_ms(20);
			if(SWITCH_PRESS)
			{
				PORTB ^= (1 << LED);
				while(SWITCH_PRESS);
			}
		}
    }
}

