/*
 * timer0_1s_delay_ctc_mode_prescaler1024.c
 * Description: created a 1 second delay using timer0 in CTC mode with prescaler value 1024.
 * Created: 19-11-2025 21:18:49
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#define LED PD5
/*
	TIMER0 CTC CALCULATION (NO PRESCALER)
	- Clock speed : 16000000  Hz
	- Prescaler : 1024
	- Timer frequency = 16000000 / 1024 = 15625
	- Time for 1 pulse : 1 / 15625  = 0.000064 ~ 64 microseconds.
	- Selecting match value (OCR0A = 199) ~ 200 ticks
	- Time for 1 Overflow = 156 x 0.000064 = 0.009984 ~ 9.984 ms
	- Overflow required for 1 second = 1 / 009984  = 100.160 ~ 100 overflows
	
*/

/*PORTD PIN CONFIGURATION*/
void init_gpio_config(void)
{
	/* configuring PORTD PIN 5 as output for LED */
	DDRD |= (1 << DDD5); 
	PORTD &= ~(1 << LED); //turning off at the time of start.
}

/*TIMER0 CONFIGURATION*/
void init_timer0_config(void)
{
	/*loading minimum value to the counter.*/
	TCNT0 = 0;      
	/*loading the value to be compared in the OCR0A register*/
	OCR0A = 155;
	/* configuring timer0 in CTC mode -> WGM00 : 0 , WGM001 : 1 */
	TCCR0A &= ~(1<< WGM00);
	TCCR0A |= (1 << WGM01);
	/*configuring prescaler value as 1024 -> CS02: 0, CS01: 0 CS00: 1 */
	TCCR0B &= (1 << CS00);
	TCCR0B |= ((1 << CS02) | (1 << CS00));
}

/*timer0  1 sec delay in CTC mode*/
void delay_1s(void)
{
	/*running loops for 100 times ~ 100 overflows*/
	for(uint8_t i = 0; i < 100; i++)
	{
		/* waiting for flag OCF0 to set*/
		while(!(TIFR0 & (1 << OCF0A))); //wait until OCF0A flag is set.
		TIFR0 |= (1 << OCF0A); //clearing flag.
	}
	
}

int main(void)
{
	init_gpio_config(void);
	init_timer0_config(void);
	
    while (1) 
    {
		PORTD ^= (1 << LED); // toggling the led in every 1 second
		delay_1s(); // dealy function call
    }
}



