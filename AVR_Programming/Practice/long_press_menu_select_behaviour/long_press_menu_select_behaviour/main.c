/*
 * long_press_menu_select_behaviour.c
 *
 * Created: 13-12-2025 21:53:31
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SWITCH PB7
#define LED_LONG PC5
#define LONG_LIMIT 200
#define IS_SWITCH_PRESSED (!(PINB & (1 << SWITCH)))

void blink_led()
{
	PORTC ^= (1 << LED_LONG);
	_delay_ms(200);
}

int main()
{
	DDRB &= ~(1 << DDB7);
	PORTB |= (1 << SWITCH);
	/*configuring PORTC PIN LED1 and LED2*/
	DDRC |= (1 << DDC5);
	PORTC &= ~(1 << LED_LONG);
	
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
					//once_happend = 0 - resetting here
					if(press_duration > LONG_LIMIT)
					{
						break;
					}
				}
				if(press_duration > LONG_LIMIT)
				{
					for(uint8_t i = 0; i < 6; i++)
						blink_led();
					/*can be replaced with a flag uint8_t once_happend = 0/1*/	
					while(IS_SWITCH_PRESSED);
				}
				else
				{
					//PORTC ^= (1 << LED_SHORT);
				}
			}
		}
		
		
	}
}

