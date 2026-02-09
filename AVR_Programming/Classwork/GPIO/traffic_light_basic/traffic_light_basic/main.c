/*
 * traffic_light_basic.c
 * Description: A simple traffic light simulator.
 * Created: 18-11-2025 23:01:11
 * Author : ARJUN
 */
#define F_CPU 16000000UL /*CPU frequency*/
#include <avr/io.h>
#include <util/delay.h>  /*for _delay_ms()*/

void redLight()
{
	PORTD |= (1 << PD3);
	_delay_ms(5000);
	PORTD &= ~(1<< PD3);
	return;
}
void yellowLight()
{
	PORTD |= (1 << PD2);
	_delay_ms(2000);
	PORTD &= ~(1<< PD2);
	return;
}
void greenLight()
{
	PORTD |= (1 << PD1);
	_delay_ms(5000);
	PORTD &= ~(1 << PD1);
	return;
}

int main(void)
{
	/*configuring PORTD as output*/
	DDRD |= (1 << DDD1) | (1 << DDD2) | (1 << DDD3);
	
	while (1)
	{
		greenLight();
		yellowLight();
		redLight();
		
	}
	return 0;
}
