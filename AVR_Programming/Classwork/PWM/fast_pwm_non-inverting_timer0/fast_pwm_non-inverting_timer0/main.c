/*
 * fast_pwm_non-inverting_timer0.c
 * Description: create a fast PWM to blibk a LED at 50% of its brightness.
 * Created: 20-12-2025 11:57:15
 * Author : ARJUN
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>



void init_fast_pwm_config()
{
	/*configuring PORTD PIN6 as PWM output*/
	DDRD |= (1 << DDD6); 
	/*fast PWM configuration*/
	TCCR0A |= ((1 << WGM00) | (1 << WGM01));
	
	/*configuring in non-inverting mode - 10*/
	TCCR0A |= (1 << COM0A1);
	TCCR0A &= ~(1 << COM0A0);	
	
	/*configuring prescalar 64*/
	TCCR0B &= ~(1 << CS02);
	TCCR0B |= ((1 << CS01) | (1 << CS00));
	
	/*setting duty cycle in OCROA*/
	OCR0A = 128;
		
}

int main(void)
{
	init_fast_pwm_config();

    while (1) 
    {
		
    }
}

