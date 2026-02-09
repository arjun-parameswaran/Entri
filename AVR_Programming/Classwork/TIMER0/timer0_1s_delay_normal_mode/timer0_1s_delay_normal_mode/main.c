/*
 * timer0_1s_delay_normal_mode.c
 * Description: to create a delay of 1 second using Timer0 in Normal Mode.
 * Created: 19-12-2025 14:25:41
 * Author : ARJUN
 */ 
/*
  Timer0  configuration steps
  - Load TCNT0 - load with a minimum value.
  - configure in normal mode (WGM01 : 0, WGM00 : 0).
  - select pre-scaling (1(no pre-scaling), 8 , 64, 256, 1024).
  - find the count for 1 second delay and create the loop.
  - check if the flag TOV0 is set or not.
  - when the flag is rest reset the flag.
  - continue the loop until the condition is satisfied.
 
*/
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	TCNT0 = 0; //loading the initial starting value.

	/*configuring the normal mode*/
	TCCR0A |= ((1 << WGM01) | (1 << WGM00));
	
	/*setting pre-scaling value to 1 (no pre-scaling)*/
	TCCR0B &= ~((1 << CS02) | (1 << CS01));
	TCCR0B |= (1 << CS00);
	/*creating a loop which runs 62500 times overflow ~ 1 second delay*/
	for(uint16_t i = 0; i <= 62500; i++)
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

