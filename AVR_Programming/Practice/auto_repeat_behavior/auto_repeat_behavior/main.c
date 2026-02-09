/*
 * auto_repeat_behavior.c
 *
 * Created: 13-12-2025 23:01:43
 * Author : ARJUN
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define SWITCH PD2
#define LED PC5
#define IS_SWITCH_PRESSED (!(PIND & (1 << SWITCH)))

int main(void)
{
	DDRD &= ~(1 << DDD2);
	PORTD |= (1 << SWITCH);
	
	DDRC |= (1 << DDC5);
	PORTC &= ~(1 << LED);
   
    while (1) 
    {
		if(IS_SWITCH_PRESSED)
		{
			_delay_ms(20);
			if(IS_SWITCH_PRESSED)
			{
				PORTC ^= (1 << LED);
				
				for(uint8_t i = 0; i <  50; i++)
				{
					_delay_ms(10);
					if(!IS_SWITCH_PRESSED)
					{
						break;
					}
				}
				while(IS_SWITCH_PRESSED)
				{
					PORTC ^= (1 << LED);
					_delay_ms(200); 
				}
				
			}
		}
		
    }
}

