/*
 * switch.c
 *
 * Created: 30-01-2026 17:56:55
 *  Author: ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>

#include "main.h"

void gpio_init()
{
	DDRC |= (1 << DDC2) | (1 << DDC3);				// LED indicator configuration
	DDRC &= ~(1 << DDC1);							//switch configuration for short press and long press
	PORTC |= (1  << SWITCH);						//Enabling Internal pull up
}