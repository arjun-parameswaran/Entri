/*
 * switch_pulldown_configuration.c
 * Description: Implementing a pull down switch and toggling LED on the switch press.
 * Created: 20-11-2025 21:01:28
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/*pin definitions*/
#define SWITCH PD5
#define IS_SWITCH_PRESSED (PIND & (1 << SWITCH))
#define LED PB2

void gpio_config()
{
	/*configuring PORTD PIN 5 as input*/
	DDRD &= ~(1 << DDD5);
	DDRB |= (1 << DDB2);
	PORTB &= ~(1 << LED);
}

int main(void)
{
	gpio_config();
	
	
    while (1) 
    {	/*checking for the switch press*/
		if(IS_SWITCH_PRESSED)
		{
			_delay_ms(50);
			if(IS_SWITCH_PRESSED)
			{
				PORTB ^= (1 << LED);	
			}
		}
    }
}

