/*
 * buzzer.c
 *
 * Created: 14-12-2025 13:13:49
 *  Author: ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define CRITICAL_ZONE 10
#define BUZZER PD5

void buzzer_init()
{
	DDRD |= (1 << DDD5)
	PORTD &= ~(1 << BUZZER) //keeping the buzzer off initiallu
	
}

void buzzer_alert(uint8_t distance)
{
	if(distance <= CRITICAL_ZONE)
	{
		PORTD |= (1 << BUZZER);
	}
	else
	{
		PORTD &= ~(1 << BUZZER);	
	}
	}
}
