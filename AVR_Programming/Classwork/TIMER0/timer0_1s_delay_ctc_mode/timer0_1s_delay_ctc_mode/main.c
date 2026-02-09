/*
 * timer0_1s_delay_ctc_mode.c
 * Description: Created a 1 second delay using timer0 in CTC mode with no prescaler.
 * Created: 19-11-2025 20:11:37
 * Author : ARJUN
 */ 
/*
  Timer0  CTC mode configuration steps
  - Load OCR0A - load with value to be compared.
  - configure in CTC mode (WGM01 : 1, WGM00 : 0).
  - select pre-scaling (1(no pre-scaling), 8 , 64, 256, 1024).
  - find the count for 1 second delay and create the loop.
  - check if the flag OCF0A is set or not.
  - when the flag is rest reset the flag.
  - continue the loop until the condition is satisfied.
 
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#define LED PD5
/*
	TIMER0 CTC CALCULATION (NO PRESCALER)
	- Clock speed : 16000000  Hz
	- Prescaler : 1
	- Time for 1 pulse : 1/ 16000000 = 0.0625 microseconds.
	- Selecting match value (OCR0A = 199) ~ 200 ticks
	- Time for 1 Overflow = 200 x 0.0625 = 12.5 ms 
	- Overflow required for 1 second = 1 / 12.5 ms = 80,0000 overflows
	
*/

/*timer0  1 sec delay in CTC mode*/
void delay_1s(void)
{
	/*loading the value to be compared in the OCR0A register*/
	OCR0A = 199;
	/* configuring timer0 in CTC mode ->*/
	TCCR0A &= ~(1<< WGM00);
	TCCR0A |= (1 << WGM01);
	/*configuring prescaler value as 1 -> CS02: 0, CS01: 0 CS00: 1 */
	TCCR0B &= ~((1 << CS02) | (1 << CS01));
	TCCR0B |= (1 << CS00);
	/**/
	for(uint32_t i = 0; i < 80000; i++)
	{
		/* waiting for flag OCF0 to set*/
		while(!(TIFR0 & (1 << OCF0A))); //checking flag for CTC mode.
		TIFR0 |= (1 << OCF0A); //clearing flag for CTC mode.
	}
	
}

int main(void)
{
	/* configuring PORTD PIN 5 as output for LED */
	DDRD |= (1 << DDD5);
	PORTD &= ~(1 << LED);
	
    while (1) 
    {
		PORTD ^= (1 << LED);
		delay_1s();
    }
}

