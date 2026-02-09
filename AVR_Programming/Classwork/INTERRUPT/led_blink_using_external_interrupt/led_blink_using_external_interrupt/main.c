/*
 * led_blink_using_external_interrupt.c
 * Description: Led blinking using External Interrupt.
 * Created: 06-12-2025 20:20:43
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*pin definitions*/
#define LED1 PB4
#define LED2 PB5

ISR(INT0_vect)
{
	PORTB |= (1 << LED2);
	_delay_ms(10000);
	
}
void  gpio_init()
{
	DDRD &= ~(1 << DDD2);	//configuring as Output for external interrupt
	DDRB |= ((1 << DDB4) | (1 << DDB5)); //configuring as Input
}

void external_interrupt_config()
{
	/*External Interrupt configuration*/
	EICRA |= ((1 << ISC00) | (1 << ISC01)); //Rising Edge INTC0
	EIMSK |= (1 << INT0); //Enabling INT0	
}

int main(void)
{
	gpio_init();
	external_interrupt_config();
    sei(); //Enabling global interrupts
    while (1) 
    {
		PORTB &= (1 << LED1);
		PORTB ^= (1 << LED2);
		_delay_ms(1000); 
		
    }
}

