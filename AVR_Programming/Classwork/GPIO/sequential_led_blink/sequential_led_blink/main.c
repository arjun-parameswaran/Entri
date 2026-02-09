/*
 * sequential_led_blink.c
 * Description: Sequential LED blinking on PD2, PD3, and PD4 using function-based GPIO control with blocking delays.
 * Created: 15-11-2025 22:57:49
 * Author : ARJUN
 */
 #define F_CPU 16000000UL /*CPU frequency*/
 #include <avr/io.h>
 #include <util/delay.h>

 void led1()
 {
	 PORTD |= (1 << PD2);
	 _delay_ms(2000);
	 PORTD &= ~(1 << PD2);
	 return;
 }

 void led2()
 {
	  PORTD |= (1 << PD3);
	  _delay_ms(2000);
	  PORTD &= ~(1 << PD3);
	  return; 
 }

 void led3()
 {
	  PORTD |= (1 << PD4);
	  _delay_ms(2000);
	  PORTD &= ~(1 << PD4);
	  return;
 
 }

 int main(void)
 {
	 /*configuring PD2, PD3 and PD4 as output */
	 DDRD |= (1 << DDD2) | (1 << DDD3) | (1 << DDD4);
	 while (1)
	 {
		 led1();
		 led2();
		 led3();
	 }
	 return 0;
 }

 

