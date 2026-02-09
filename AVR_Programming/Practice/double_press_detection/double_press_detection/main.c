/*
 * double_press_detection.c
 *
 * Created: 13-12-2025 01:49:25
 * Author : ARJUN
 */ 

#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#define SWITCH PB7
#define  LED PB5
#define IS_SWITCH_PRESSED (!(PINB & (1 << SWITCH)))

int main(void)

{
	/*configuring ports and pins*/
	DDRB &= ~(1 << DDB7); //Input configuration
	PORTB |= (1 << SWITCH); //setting as high for pull up
	DDRB |= (1 << DDB5); //output
	PORTB &= ~(1 << LED);//low at starting

	while (1)

	{

		if(IS_SWITCH_PRESSED)
		{
			_delay_ms(20);
			if(IS_SWITCH_PRESSED) //checking for first press
			{
				while(IS_SWITCH_PRESSED);
				uint8_t double_press_detected = 0;
				
				for(uint8_t i = 0; i < 40; i++)
				{
					_delay_ms(10);
					if(IS_SWITCH_PRESSED)
					{
						double_press_detected = 1;
						while(IS_SWITCH_PRESSED);
						break;
					}
				}
				/*checking if switch is pressed*/
				if(double_press_detected)
				{
					PORTB ^= (1 << LED); //toggle the LED
				}
			}
		}
	}
}


