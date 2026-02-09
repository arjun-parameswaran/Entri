/*
 * blink_led_three_times.c
 * Problem Statement: Make LED on PB0 blink 3 times (200 ms ON/OFF each), then stay OFF for 2 seconds.
 * Created: 16-11-2025 01:45:21
 * Author : ARJUN
 */

 #define F_CPU 16000000UL
 #include <avr/io.h>
 #include <util/delay.h>


void toggle_led()
{
	 PORTB ^= (1 << PB0);
	 _delay_ms(200);
}


 int main(void)
 {
	 DDRB |= (1 << DDB0); /*configuring PB0 as Output.*/
	 PORTB &= ~(1 << PB0);
	 
	 while (1)
	 {
		 for(int i = 0; i < 6; ++i)
		 {
			 toggle_led();
		 }
		 /*make sure the Pin1 is low*/
		 PORTB &= ~(1 << PB0);
		 _delay_ms(2000); //for the delay of 2 seconds
		 
	 }
	 return 0;
 }
