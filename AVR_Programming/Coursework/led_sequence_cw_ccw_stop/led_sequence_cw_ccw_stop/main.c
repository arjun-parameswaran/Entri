/*
 * led_sequence_cw_ccw_stop.c.c
 
 * Problem : Define 3 functions for the 3 conditions explained in the previous question (Function names  cw(),ccw() stp()).
				Call the functions in the min so that we get the LED blink as per the previous question (dual_alternate_led_blink).
 * Created: 15-11-2025 22:45:08
 * Author : ARJUN
 */

 #define F_CPU 16000000UL     /* CPU frequency */
 #include <avr/io.h>
 #include <util/delay.h>      /* Required for _delay_ms() */

/*both pin3 & pin2 are LOW*/
 void stp()
 {
	PORTD &= ~(1 << PD3); //LED1 OFF
	PORTD &= ~(1 << PD2); // LED2 OFF
	_delay_ms(3000);
	return;
 }
 /*Pin3 HIGH and pin2 LOW*/
 void cw()
 {
	PORTD  |= (1 << PD3); //LED1 ON
	PORTD &= ~(1 << PD2); //LED2 OFF
	_delay_ms(5000);
	return;
 }
 /*pin3 LOW and Pin2 HIGH*/
 void ccw()
 {
	PORTD &= ~(1 << PD3); //LED1 OFF
	PORTD |= (1 << PD2); //LED2 ON
	_delay_ms(5000);
	return;
 }

 int main(void)
 {
 DDRD |= (1 << DDD2) | (1 << DDD3); /*configuring PD2  and PD3 as output*/
 
 while (1)
 {
 /*function to turn LED1 ON and LED2 OFF*/
 ccw();
 /*function to turn LED1 and LED2 OFF*/
 stp();
 /*function to turn LED2 ON and LED1 OFF*/
 cw();
 /*function to turn OFF LED1 and LED2 OFF*/
 stp();
 }
 
 return 0;
 }


