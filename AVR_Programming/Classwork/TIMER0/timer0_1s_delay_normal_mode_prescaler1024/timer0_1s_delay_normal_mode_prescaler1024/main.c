/*
 * timer0_1s_delay_normal_mode_prescalar_1024.c
 * Description: 1 second delay using timer0 in normal mode with prescaler value 1024.
 * Created: 19-12-2025 17:15:18
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	TCNT0 = 0; //loading the initial starting value.

	/*configuring the normal mode*/
	TCCR0A &= ~((1 << WGM01) | (1 << WGM00));
	
	/* setting pre-scaling value to 1024 */
	TCCR0B &= ~(1 << CS01);
	TCCR0B |= ((1 << CS02) | (1 << CS00));
	/*creating a loop which runs 61 times overflow ~ 1 second delay*/
	for(uint8_t i = 0; i < 61; i++)
	{
		/* checking for TOV0 flag set or not */
		while(!(TIFR0 & (1 << TOV0))); //waiting until the flag is set.
		TIFR0 |= (1 << TOV0);          //writing 1 to reset the flag
	}
	
}

int main(void)
{
	/*configuring PORTD PIN 5 for LED*/
	DDRD |= (1 << DDD5);
	PORTD &= ~(1 << PD5); //turning the led off during the start
	
	while (1)
	{
		PORTD ^= (1 << PD5);
		delay_1s();
	}
}

