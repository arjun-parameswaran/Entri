/*
 * dc_motor_speed_contorl_using_potentiometer.c
 * Description: DC Motor speed control using potentiometer.
 * Created: 02-01-2026 10:53:48
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

#define GREEN_LED PB4
#define RED_LED PB5

#define SWITCH PD2 

volatile uint8_t motor_enable = 0;

ISR(INT0_vect)
{
	motor_enable = !(motor_enable);
}
void interrupt_init()
{
	/*Enabling Interrupt for falling edge*/
	EICRA |=  (1 << ISC01); 
	EICRA &= ~(1 << ISC00);  
	/*Enabling INT0 interrupt*/
	EIMSK |= (1 << INT0);    // Enable INT0	
}

void gpio_init()
{
	/*ON/OFF switch configuration*/
	DDRD &= ~((1 << DDD2));
	PORTD |= (1 << SWITCH); //Enabling Internal Pull-Up.
	/*ON/OFF LED configuration*/
	DDRB |= ((1 << DDB5) | (1 << DDB4));
}

/*timer1 configuration*/
void fast_pwm_config()
{
	/*configuring port for output*/
	DDRB |= (1 << DDB1);
	/*configuring in fast PWM mode*/
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM13) | (1 << WGM12);
	/*setting prescaler value to 1 */
	TCCR1B |= (1 << CS10);                                                                          
	/*configuring in non - inverting mode*/
	TCCR1A |= (1 << COM1A1); 
	/*configuring the TOP value for 10khz frequency*/
	ICR1 = 1599;
	/*configuring initial duty cycle 0*/
	OCR1A = 0;
}
void adc_config()
{
	/*configuring the reference voltage (for simulinkIDE)*/
	ADMUX |= (1 << REFS0);
	ADMUX |= (1 << REFS1);

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
	/*function calls for configuring GPIO, PWM, ADC and Interrupt*/
	gpio_init();
	fast_pwm_config();
	adc_config();
	interrupt_init();
	
	sei(); //Enabling Global Interrupt.
	
    uint16_t adc_value;
	
    while (1) 
    {
		if(motor_enable)
		{
			/*setting the LED indication*/
			PORTB &= ~(1 << RED_LED);        // LED OFF
			PORTB |= (1 << GREEN_LED);       // LED ON
			/*controlling speed according to the pot value*/
			adc_value = read_adc(0);
			
			OCR1A = (uint32_t) (adc_value * 1.564);
			
		}
		else
		{
				/*setting the LED indication*/
				PORTB &= ~(1 << GREEN_LED);  // LED OFF
				PORTB |= (1 << RED_LED);     // LED ON
				/*Turning OFF the Motor*/ 
				OCR1A = 0;                   //Motor OFF 
		}
		
    }
}

