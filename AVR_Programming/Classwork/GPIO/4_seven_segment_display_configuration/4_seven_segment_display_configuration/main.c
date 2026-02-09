#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/* Common Cathode segment patterns (a b c d e f g dp) */
const uint8_t seg_cc[10] =
{
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111  // 9
};
int value = 153, count = 0;
void digit_off(void)
{
	/* Disable all digits (set HIGH) */
	PORTD |= (1 << PD0) | (1 << PD1) | (1 << PD2) | (1 << PD3);
}

void digit_on(uint8_t digit)
{
	PORTD &= ~(1 << digit);   // Enable selected digit (LOW)
}

int main(void)
{
	/* Segment pins as output */
	DDRB = 0xFF;

	/* Digit control pins as output */
	DDRD |= (1 << PD0) | (1 << PD1) | (1 << PD2) | (1 << PD3);

	digit_off();   // All digits OFF initially

	while (1)
	{
		PORTB = seg_cc[(value/1000) % 10];
		digit_on(PD0);
		_delay_ms(3);
		digit_off();

		PORTB = seg_cc[(value / 100) % 10];
		digit_on(PD1);
		_delay_ms(3);
		digit_off();

		PORTB = seg_cc[(value/10) % 10];
		digit_on(PD2);
		_delay_ms(3);
		digit_off();

		PORTB = seg_cc[value % 10];
		digit_on(PD3);
		_delay_ms(3);
		digit_off();
		if(count++ == 100)
		{
			value++;
			count = 0;
		}
	}
}
