/*
 * phase_correct_pwm_led_fading_timer0.c
 *
 * Created: 20-12-2025 00:47:14
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


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
	OCR0A = 0; //the led will light at 0% brightness
}


int main(void)
{
	init_phase_correct_pwm_config(); //function call for PWM configuration/
	
	while (1)
	{
		for(uint16_t duty = 255; duty >= 0; duty--)
		{
			OCR0A = duty;
			_delay_ms(50);
		}	
	}
}