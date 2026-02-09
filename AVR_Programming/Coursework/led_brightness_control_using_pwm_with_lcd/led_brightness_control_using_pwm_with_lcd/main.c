/*
 * led_brightness_control_using_pwm_with_lcd.c
 *
 * Created: 28-12-2025 16:29:10
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED PB2

void gpio_init()
{
	/*configuring pins for LED*/
	DDRB |= (1 << DDB2);
	PORTB &= ~(1 << LED);
	/*configuring for switches*/
	
	
}

int main(void)
{
	gpio_init();
    while (1) 
    {
    }
}

