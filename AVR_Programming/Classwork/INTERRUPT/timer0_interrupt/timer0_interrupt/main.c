/*
 * timer0_interrupt.c
 *
 * Created: 04-12-2025 20:45:16
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#define SEC1 977
#define LED PB2

volatile uint16_t count = 0;

/*interrupt service routine*/
ISR(TIMER0_OVF_vect)
{
	if(count >= SEC1)
	{
		PORTB ^= (1 << LED); //toggling LED
		count = 0; //resetting count
	}
	else
	{
		count++; 
	}
}
void gpio_config()
{
	/*configuring PORTB PIN 2 as Output for LED*/
	DDRB |= (1 << DDB2);
	PORTB &= ~(1 << LED); //turning off during start.
}

void overflow_interrupt_config()
{
	TCNT0 = 0;
	/*configuring timer in normal mode*/
	TCCR0A &= ~((1 << WGM01) | (1 << WGM00));
	/*configuring prescaler 64*/
	TCCR0B |= ((1 << CS01) | (CS00));
	TCCR0B &= ~(1 << CS02);
	/*Enabling timer0 overflow interrupt*/
	TIMSK0 |= (1 << TOIE0);
	
}

int main(void)
{
	gpio_config();
	overflow_interrupt_config();
	sei(); //global interrupt enable
    
    while (1) 
    {
    }
}

