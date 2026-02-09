/*
 * switch_pullup_configuration.c
 * Description: configuration of switch with pull-up configuration.
 * Created: 15-11-2025 22:15:49
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/*pin definitions */
#define PULLUP_SWITCH PD5
#define IS_SWITCH_PRESSED (!(PIND & (1 << PULLUP_SWITCH)))
#define LED PB2


void gpio_configuration()
{
	/*configuration of PORTD as PIN5 as input and PORTB PIN2 as output for lED */
	DDRD &= ~(1 << DDD5);
	PORTD |= (1 << PULLUP_SWITCH); //Enabling internal pull-up.
	
	DDRB |= (1 << DDB2);
	PORTB &= ~(1 << LED); //turning the LED at the time of start/
	

}

int main(void)
{
    gpio_configuration();
	
    while (1) 
    {
		/*checking for switch press*/
		if(IS_SWITCH_PRESSED)
		{
			_delay_ms(20);
			if(IS_SWITCH_PRESSED)
			{
				PORTB |= (1 << LED);
			}
		}
		else
		{
			PORTB &= ~(1 << LED);
		}
			
    }
}

