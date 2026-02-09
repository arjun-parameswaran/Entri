/*
 * timer1_ctc_led_blink_5sec.c
 *
 * Created: 23-12-2025 14:57:38
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PB2);	
}


void gpio_config()
{
	DDRB |= (1 << DDB2);
	PORTB &= ~(1 << PB2);
}


void timer1_config()
{
	TCNT1 = 0;
	/*configuring the timer1 i CTC mode*/
	TCCR1B |= (1 << WGM12);
	/*configuring the prescaler value: 1024*/
	TCCR1B |= ((1 << CS12) | (1 << CS10));
	TCCR1B &= ~(1 << CS11);
	/*giving the compare value*/
	OCR1A = 7812; //value represents .5s
	/*Enabling timer1 compare interrupt*/
	TIMSK1 |= (1 << OCIE1A);
}
int main(void)
{
    timer1_config();
	gpio_config();
	sei();
    while (1) 
    {
    }
}

