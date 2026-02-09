/*
 * phase_correct_pwm_non-inverting_timer0.c
 *
 * Created: 29-11-2025 21:10:24
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


void init_phase_correct_pwm_config()
{
	/*configuring PORTD PIN5 for PWM*/
	DDRD |= (1 << DDD6);
	
	/*configuring phase correct PWM (mode 1)*/
	TCCR0A &= ~(1 << WGM01);
	TCCR0A |= (1 << WGM00);
	
	/*configuring for non inverting PWM*/
	TCCR0A &= ~(1 << COM0A0);
	TCCR0A |= (1 << COM0A1);
	
	/*configuring prescaler value : 8*/
	TCCR0B &= ~((1 << CS02 | 1 << CS00));
	TCCR0B |= (1 << CS01);
	/*setting the duty cycle in OCR0A (PD5)*/
	OCR0A = 128; //the led will light at 50% brightness
}
	

int main(void)
{
	init_phase_correct_pwm_config(); //function call for PWM configuration/
	
    while (1) 
    {
		
    }
}

