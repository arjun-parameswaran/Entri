/*
 * led_brightness_control_using_potentiometer.c
 * Description: LED brightness is controlled using Potentiometer
 * Created: 02-01-2026 14:10:25
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void fast_pwm_config()
{
	/*configuring port for output*/
	DDRD |= (1 << DDD6);
	/*configuring in fast pwm mode*/
	TCCR0A |= ((1 << WGM01) | (1 << WGM00));
	/*setting prescaler value to 8)*/
	TCCR0B |= (1 << CS01);
	/*configuring in non - inverting mode*/
	TCCR0A |= (1 << COM0A1);
	/*making the value/speed 0 at the time of starting*/
	OCR0A = 0;
	
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
	fast_pwm_config();
	adc_config();
	uint16_t _curr_adc_value, prev_adc_value;
	while (1)
	{
		adc_value = read_adc(0);
		if(adc_value != prev_adc_value)
		{
			OCR0A = (adc_value >> 2); //dividing by 4 for mapping.
			prev_adc_value = curr_adc_value;
		}
		
	}
}

