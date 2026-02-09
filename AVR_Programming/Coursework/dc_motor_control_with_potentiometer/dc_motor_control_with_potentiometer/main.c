/*
 * dc_motor_control_with_potentiometer.c
 * Description: DC Motor speed control using Phase Correct PWM.
 
 * Created: 01-01-2026 10:14:59
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include

void fast_pwm_config()
{
	/*configuring PWM output pin*/
	DDRB |= (1 << DDB1);
	/*configuring Timer0 in fast PWM mode*/
	TCCR1A |= (1 << WGM11);
	TCCR1A &= ~(1 << WGM10);
	TCCR1B |= ((1 << WGM13) | (1 << WGM12));
	
	/*choosing the prescalar value to 8*/
	TCCR1B |= (1 << CS11);
	TCCR1B &= ~((1 << CS12) | (1 << CS10));

	/*configuring the PWM in Non-inverting mode*/
	TCCR1A |= (1 << COM0A1);
	TCCR1A &= ~(1 << COM0A0);

	/*set the frequency*/
	ICR1 = 1999;
	
	
	
	
}
void adc_init()
{
	
}

int main(void)
{
    
    while (1) 
    {
    }
}

