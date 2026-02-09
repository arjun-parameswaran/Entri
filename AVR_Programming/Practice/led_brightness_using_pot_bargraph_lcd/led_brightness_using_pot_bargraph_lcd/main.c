/*
 * led_brightness_using_pot_bargraph_lcd.c
 *
 * Created: 02-01-2026 21:57:35
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "lcd.h"

/*timer2 fast PWM configuration*/
void fast_pwm_config()
{
	/*configuring port for output*/
	DDRB |= (1 << DDB3);
	/*configuring in fast pwm mode*/
	TCCR2A |= ((1 << WGM21) | (1 << WGM20));
	TCCR2B &= ~(1 << WGM22);
	/*setting prescaler value to 32*/
	TCCR2B |= (1<< CS21) | (1 << CS20);
	/*configuring in non - inverting mode*/
	TCCR2A |= (1 << COM2A1);
	/*making the value/speed 0 at the time of starting*/
	OCR2A = 0;
	
}
void adc_config()
{
	/*configuring the reference voltage*/
	ADMUX |= (1 << REFS0);

	/*turning ON the ADC*/
	ADCSRA |= (1 << ADEN);
	/* Configure Prescaler to 128 */
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
}

uint16_t read_adc(uint8_t channel)
{
	/*retaining the first 4 bits and making the channel stay between 0 - 7*/
	ADMUX = (ADMUX & 0xF0) | (channel & 0x07);
	/*start conversion*/
	ADCSRA |= (1 << ADSC);

	/*waiting for conversion to finish (bit changes to 0*/
	while (ADCSRA & (1 << ADSC));

	/*Return the ADC value 10-bit result (0 to 1023)*/
	return ADC;
	
}

int main(void)
{
	lcd_init();
	fast_pwm_config();
	adc_config();
	uint16_t adc_value, percentage;
	while (1)
	{
		adc_value = read_adc(0);
		OCR2A = (adc_value >> 2); //dividing by 4 for mapping.
		percentage = ((adc_value/4) / 255 ) * 100;
		lcd_set_cursor(0,0);
		lcd_print("BRIGHT %:");
		lcd_set_cursor(0,10);
		lcd_print_uint16(percentage);
	}
}

