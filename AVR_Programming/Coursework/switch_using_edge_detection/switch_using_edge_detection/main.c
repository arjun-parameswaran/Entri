/*
 * switch_using_edge_detection.c
 *
 * Created: 28-12-2025 21:50:06
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/*pin definitions*/
#define BUTTON PD2
#define LED_PRESS PB1
#define LED_RELEASE PB2

void gpio_init()
{
	DDRB |= (1 << LED_PRESS) | (1 << LED_RELEASE); // as output for led
	DDRD &= ~(1 << BUTTON); // as Input for Button
	PORTD |= (1 << BUTTON); // Enabling the Internal Pull-Up
	
}
int main(void)
{
	gpio_init();
	/*variables for storing the state*/
	uint8_t last_state = 1; //configuring as 1 since pull up.
	uint8_t current_state;

	while (1)
	{
		/*cheeking for any state change occurred*/
		(PIND & (1 << BUTTON))?(current_state = 1): (current_state = 0);
	
		/*comparing the current state vs the last state*/
		if (current_state != last_state)
		{
			_delay_ms(20); //De bounce
						
			/*conforming it is not noise*/
			if ((PIND & (1 << BUTTON)) ? 1 : 0 == current_state)
			{
				/*checking for Falling Edge*/
				if (last_state == 1 && current_state == 0)
				{
					/*High(1) -> Low(0) - Falling Edge (PRESSED)*/
					PORTB |= (1 << LED_PRESS); //Turn ON LED
					_delay_ms(200);
					PORTB &= ~(1 << LED_PRESS); // Turn OFF LED
				}
				/*checking for Rising Edge*/
				else if (last_state == 0 && current_state == 1)
				{
					/*Low(0) -> High(1) - Rising Edge (PRESSED)*/
					PORTB |= (1 << LED_RELEASE); //Turn ON LED
					_delay_ms(200);
					PORTB &= ~(1 << LED_RELEASE); //Turn OFF LED
				}

				/*updating the last state with the current state*/
				last_state = current_state;
			}
		}
	}
}