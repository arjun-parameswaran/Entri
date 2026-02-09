/*
 * pwm_timed_brightness_control.c
 * Description: An LED brightness controller that temporarily boosts brightness to 100% for 5 seconds when a button is pressed, 
				using Timer0 PWM and overflow interrupts.
 * Created: 20-12-2025 10:58:52
 * Author : ARJUN
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h> 


/*macro definitions*/
#define PWM_OUTPUT DDD6
#define DUTY_10 25
#define DUTY_100 255
#define SWITCH PD2
#define DELAY_5S 4883
#define IS_SWITCH_PRESSED !(PIND & (1 << SWITCH))

volatile uint16_t overflow_count = 0;
volatile uint8_t bright_mode_flag = 0;

void init_gpio_config()
{
	/*configuring PD2 as input for the switch*/
	DDRD &= ~(1 << DDD2);
	PORTD |= (1 << SWITCH); //enable internal pull up.
}

ISR(TIMER0_OVF_vect)
{
	if(bright_mode_flag) //checking if switch pressed or not
	{
		overflow_count++;		
	}
}

void init_fast_pwm_config_with_ovf_interrupt()
{
	/*Configuring PORTD PIN6 as PWM output*/
	DDRD |= (1 << PWM_OUTPUT);
	/*fast PWM configuration*/
	TCCR0A |= ((1 << WGM00) | (1 << WGM01));
	
	/*Configuring in non-inverting mode - 10*/
	TCCR0A |= (1 << COM0A1);
	TCCR0A &= ~(1 << COM0A0);
	
	/*Configuring prescalar 64*/
	TCCR0B &= ~(1 << CS02);
	TCCR0B |= ((1 << CS01) | (1 << CS00));
	
	/*Setting duty cycle in OCROA*/
	OCR0A = DUTY_10;
	
	/*Enabling Timer0 overflow interrupt*/
	TIMSK0 |= (1 << TOIE0);
	
}

int main(void)
{
	init_gpio_config();
	init_fast_pwm_config_with_ovf_interrupt();
	sei(); //global interrupt enable

	while (1)
	{
		static uint8_t prev_switch = 1;
		uint8_t curr_switch = IS_SWITCH_PRESSED;

		if(!bright_mode_flag && prev_switch == 0 && curr_switch == 1) //to avoid press while bright mode already active.
		{
			bright_mode_flag = 1;	// setting flag to start overflow count for 5 sec.
			OCR0A = DUTY_100;		//making LED brightness to 100%.
		}
		prev_switch = curr_switch;
		/*resetting counter and flag*/
		if(bright_mode_flag && overflow_count >= DELAY_5S)
		{
			bright_mode_flag = 0;	//resetting overflow counter.
			overflow_count = 0;		//resetting overflow counter.
			OCR0A = DUTY_10;		//resetting the LED brightness back to 10%
		}	

	}
}

