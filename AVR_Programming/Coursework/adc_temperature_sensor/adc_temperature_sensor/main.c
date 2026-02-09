/*
 * adc_temperature_sensor.c
 * Description: Reading the temperature value LM35 sensor.
 * Created: 23-12-2025 21:04:31
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>

void adc_init(void)
{
	/*configuring ADC reference voltage as 5v*/
	ADMUX|=(1<<REFS0); 
	/*configuring the prescalar value as 128 and turning ON the ADC*/
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);	
}
uint16_t ADC_Read(uint8_t channel)
{
	/*limiting the channel value to 0 - 7*/
	channel &= 0x07;
	/*configuring channel value by retaining the first 4 bit and clearing the remaining the 4 bits*/
	ADMUX = (ADMUX & 0XF0)|channel;
	/*starting the conversion*/
	ADCSRA|=(1<<ADSC);
	/*waiting for the completion of ADC conversion*/
	while(ADCSRA & (1 << ADSC));
	/*returning the corresponding ADC value*/
	return (ADCL|(ADCH<<8));
}
int main(void)
{
	uint16_t adc_value;
	lcd_init();
	adc_init();
    /* Replace with your application code */
    while (1) 
    {
		/*reading ADC value from ADC0*/
		adc_value = adc_init(0);
		/*converting the adc value into corresponding temperature*/
		float temp = adc_value * 0.488; 
		lcd_clear(); // clearing display for new values to print
		
		lcd_set_cursor(0,0);
		lcd_print("Temperature:");
		
		lcd_set_cursor(1,0);
		lcd_print_float(temp);
		
		lcd_data(0xDF); //for printing degree symbol.
		lcd_print("C");
		
		/*for proper display*/
		_delay_ms(500);
		
    }
}


