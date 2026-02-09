/*
 * ADC_configuration.c
 *
 * Created: 20-12-2025 22:47:14
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

uint16_t read_adc_value()
{
	 ADCSRA |= (1 << ADSC); //enabling convention
	 while(ADCSRA & (1 << ADSC)); //wating until the concersion compleates. ADSC bit changes to 0.
	 
	 return ADC;
	
}
void adc_config()
{
	/*voltage reference selection */
	ADMUX &= ~(1 << REFS1);
	ADMUX |= (1 << REFS0);
	
	/*channel channel pin selection */
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
	
	/*configuring prescaler value : 64*/
	 ADCSRA |= ((1 << ADPS2) | (1 << ADPS1));
	 
	 /*enabling*/
	 ADCSRA |= (1 << ADEN); //turning ON the conversion
	 
	 //ADCSRA |= (1 << ADSC); //starting conversion
	 //while(ADCSRA & (1 << ADSC)); //waiting until the conversion completes. ADSC bit changes to 0.

}

void main(void)
{
	DDRD |= (1 << DDD5);
	PORTD &=  ~(1 << PD5);
	adc_config();
	uint16_t adc_value = read_adc_value();
    while (1) 
    {
		//uint16_t adc_value = read_adc_value();
		if(adc_value >= 900)
		{
			PORTD |= (1 << PD5);// turns on the led.
		}
	}
}

