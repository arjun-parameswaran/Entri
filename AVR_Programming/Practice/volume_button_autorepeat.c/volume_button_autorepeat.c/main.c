/*
 * volume_button_autorepeat.c.c
 *
 * Created: 14-12-2025 10:34:12
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SWITCH PD2
#define IS_SWITCH_PRESSED !(PIND & (1 << SWITCH))
#define  MAX_LIMIT 6


void update_leds(uint8_t vol)
{
	PORTB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5));
	
	if(vol >= 1) PORTB |= (1 << PB0);
	if(vol >= 2) PORTB |= (1 << PB1);
	if(vol >= 3) PORTB |= (1 << PB2);
	if(vol >= 4) PORTB |= (1 << PB3);
	if(vol >= 5) PORTB |= (1 << PB4);
	if(vol >= 6) PORTB |= (1 << PB5);
	
	
}
void init_config()
{
	/*configuring the switch*/
	DDRD &= ~(1 << DDD2);
	PORTD |= (1 << SWITCH);
	/*configuring the LED's*/
	DDRB |= ((1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3)| (1 << DDB4)| (1 << DDB5));
    PORTB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5));
}

int main(void)
{
	uint8_t volume = 0;
    init_config();
    while (1) 
    {
		if(IS_SWITCH_PRESSED)
		{
			_delay_ms(20); //de-bounce
			if(IS_SWITCH_PRESSED)
			{
				if(volume < MAX_LIMIT)
					volume++;
				
				update_leds(volume);
								
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
					if(volume < MAX_LIMIT)
					{
						volume++;
						update_leds(volume);
					}
					_delay_ms(200);
				}
			}
			
		}
		
    }
}

