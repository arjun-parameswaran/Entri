/*
 * adc_voltage_display.c
 * Description: to display the voltage present at the ADC pin 0.
 * Created: 24-12-2025 19:33:47
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "lcd.h"


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
void adc_config()
{
	/*configuring the reference voltage*/
	ADMUX |= (1 << REFS0);
	ADMUX |= (1 << REFS1);

	/* Configure Prescaler to 128 */
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
}

int main(void)
{
	lcd_init();
	
	lcd_set_cursor(0,0);
	lcd_print("adc value :");
	
	lcd_set_cursor(1, 0);
	lcd_print("voltage :");
	adc_config();
	
	uint16_t adc_value;
	float voltage;
	
    while (1) 
    {
		adc_value = read_adc(1); //channel 0 - 7
		voltage = (adc_value * 5.0) / 1023.0; //voltage calculation
		lcd_set_cursor(0,11);
		lcd_print("      ");// clear before printing new value
		
		lcd_set_cursor(0, 11);
		lcd_print_uint16(adc_value); //printing adc value
		
		lcd_set_cursor(1,10);
		lcd_print("      ");// clear before printing new value
		
		lcd_set_cursor(1, 10);
		lcd_print_float(voltage); // printing voltage value
		_delay_ms(500); // for smooth operation 

		
    }
}

