/*
 * dc_motor_speed_control__pwm_30pct_speed.c
 *
 * Created: 22-12-2025 14:19:04
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


void phase_correct_pwm_config()
{
	
	DDRD |= (1 << DDD6); //configuring PORTD PIN6 as PWM output.
	
	/*configuring in phase correct PWM mode*/
	TCCR0A &= ~(1 << WGM01);
	TCCR0A |= (1 << WGM00);
	/*configuring non-inverting mode*/
	TCCR0A &= ~(1 << COM0A0);
	TCCR0A |= (1 << COM0A1);
	/*choosing prescalar as 8*/
	TCCR0B &= ~(1 << CS02);
	TCCR0B |= ((1 << CS00) | (1 << CS01));
	/*setting the speed - 30% of motor speed*/
	OCR0A = 77;
}
int main(void)
{
	
	phase_correct_pwm_config();
	
    while (1) 
    {
		
    }
}

