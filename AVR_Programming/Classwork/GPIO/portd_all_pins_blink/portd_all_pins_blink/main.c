/*
 * portd_all_pins_blink.c
 * Problem: Turn ON all pins of PORTD at the same time for 3 seconds, then turn them OFF for 3 seconds.
 * Created: 16-11-2025 01:16:01
 * Author : ARJUN
 */
 #define F_CPU 16000000UL /*cpu frequency 16khz*/
 #include <avr/io.h>
 #include <util/delay.h>      /* Required for _delay_ms() */


 int main(void)
 {
	DDRD |= ((1 << DDD0) | (1 << DDD1) |(1 << DDD2) |(1 << DDD3) |(1 << DDD4) |(1 << DDD5) |(1 << DDD6) |(1 << DDD7)); /*setting all PORTD as output*/
 
 while (1)
 {
	PORTD |= ((1 << PD0) | (1 << PD1) |(1 << PD2) |(1 << PD3) |(1 << PD4) |(1 << PD5) |(1 << PD6) |(1 << PD7)); /*turning all pins HIGH*/
	_delay_ms(3000);
	PORTD &= ~((1 << PD0) | (1 << PD1) |(1 << PD2) |(1 << PD3) |(1 << PD4) |(1 << PD5) |(1 << PD6) |(1 << PD7)); /*turning all pins HIGH*/ /*turning all pins LOW*/
	_delay_ms(3000);
 }
 return 0;
 }



