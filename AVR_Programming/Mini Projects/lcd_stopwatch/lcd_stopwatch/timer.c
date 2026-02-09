/*
 * timer.c
 *
 * Created: 30-01-2026 17:33:21
 *  Author: ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>

#include "main.h"
#if 0
ISR(INT0_vect)
{
	PORTC |= (1 << PC1);
	stopwatch_enable_flag = DISABLE;
	//switch_flag = ENABLE;
	//press_count = 0;
	//blink_flag = 0;
}
ISR(INT1_vect)
{
	PORTC &= ~(1 << PC1);
	stopwatch_enable_flag = ENABLE;
}


#endif

ISR(TIMER1_COMPA_vect)
{
	/* Stopwatch logic, if flag is not set ~No increment function happens */
	if (!stopwatch_enable_flag)
	{
		return;
	}
	else
	{
		ms++;								//incrementing ms after each compare

		if (ms == 500)
		{
			blink_flag ^= 1;
		}
		/*updating values of min and sec based on ms and resetting them*/
		if (ms >= 1000)
		{
			ms = 0;							//resetting ms -> when it exceeds 1000
			sec++;							//when ms hit 1000, sec is updateed
			if (sec >= 60)
			{
				sec = 0;					//resetting sec ->when it is over 60
				min++;						//when sec it 60, min is updated
			}
		}
	}
	
	
}

/*Timer1 Configuration*/
void timer1_init(void)
{
	TCNT1  = 0;								//Loading 0
	TCCR1B |= (1 << WGM12);					//CTC mode configuration
	TCCR1B |= (1 << CS11) | (1 << CS10);	//Prescalar 64
	OCR1A = 249;							//1 ms 
	TIMSK1 |= (1 << OCIE1A);				//compare match interrupt enable
}

#if 0
/*External Interrupt configuration*/
void ext_interrupt_init()
{
	/*pin configuration INT0 and INT1*/
	DDRD &= ~(1 << DDD2 | 1 < DDD3);
	PORTD |= (1 << PD2) | (1 << PD3);
	/*configuring INT0 for falling edge*/
	EICRA &= ~(1 << ISC00);
	EICRA |= (1 << ISC01);
	/*configuring INT1for falling edge*/
	EICRA &= ~(1 << ISC10);
	EICRA |= (1 << ISC11);
	/*Enabling INT0*/
	EIMSK |= (1 << INT0 | 1 << INT1);
}

#endif
