/*
 * timer0_1s_delay_normal_mode_prescaler64.c.c
 *
 * Created: 19-12-2025 15:23:03
 * Author : ARJUN
 */ 

/*
 * Timer0 Count Calculation (Normal Mode, Prescalar = 64)
 *
 * CPU Clock Frequency (F_CPU) = 16,000,000 Hz (16 MHz)
 *
 * Timer Clock Frequency:
 *   = F_CPU / Prescalar value
 *   = 16,000,000 / 64
 *   = 250,000 Hz
 *
 * Time Period of One Timer Tick:
 *   = 1 / 250,000
 *   = 0.000004 seconds
 *   = 4 µs
 *
 * Timer0 is an 8-bit timer:
 *   Counts from 0 to 255 ? 256 counts per overflow
 *
 * Time for One Overflow:
 *   = 256 × 4 µs
 *   = 1024 µs
 *   = 0.001024 seconds
 *
 * Number of Overflows Required for 1 Second:
 *   = 1 / 0.001024
 *   ? 976.56 overflows
 *
 * Therefore:
 *   977 overflows ? 1 second delay
 */


#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	TCNT0 = 0; //loading the initial starting value.

	/*configuring the normal mode*/
	TCCR0A |= ((1 << WGM01) | (1 << WGM00));
	
	/*setting pre-scaling value to 64*/
	TCCR0B &= ~(1 << CS02);
	TCCR0B |= ((1 << CS00) | (1 << CS01));
	/*creating a loop which runs 62500 times overflow ~ 1 second delay*/
	for(uint16_t i = 0; i <= 977; i++)
	{
		/*checking for TOV0 flag set or not*/
		while(!(TIFR0 & (1 << TOV0))); //waiting until the flag is set.
		TIFR0 |= (1 << TOV0); //writing 1 to reset the flag
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
