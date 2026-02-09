/*
 * long_press_detection.c
 *
 * Created: 13-12-2025 17:21:40
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SWITCH PB7
#define LED_LONG PC5
#define LED_SHORT PC2
#define MAX_LIMIT 150
#define LONG_LIMIT 100
#define IS_SWITCH_PRESSED (!(PINB & (1 << SWITCH)))


int main()
{
	DDRB &= ~(1 << DDB7);
	PORTB |= (1 << SWITCH);
	/*configuring PORTC PIN LED1 and LED2*/
	DDRC |= ((1 << DDC2) | (1 << DDC5));
	PORTC &= ~((1 << LED_LONG) | (1 << LED_SHORT));
	
	uint32_t press_duration = 0;
    while (1) 
    {
		if(IS_SWITCH_PRESSED)
		{
			_delay_ms(20);
			if(IS_SWITCH_PRESSED)
			{
				press_duration = 0; //reset the counter
				while(IS_SWITCH_PRESSED)
				{
					_delay_ms(10);
					press_duration++;
					if(press_duration > MAX_LIMIT)
					{
						break;
					}
				}
				if(press_duration > LONG_LIMIT)
				{
					PORTC ^= (1 << LED_LONG);
					while(IS_SWITCH_PRESSED);
				}
				else
				{
					PORTC ^= (1 << LED_SHORT);
				}
			}
		}
		
		
    }
}

