/*
 * switch_led_control.c
 * Description: Push Button Controlled LED using ATmega328P (Polling Method)
 * Created: 20-11-2025 20:21:25
 * Author : ARJUN
 */

 #define F_CPU 16000000UL     /* CPU frequency */
 #include <avr/io.h>
 #include <util/delay.h>      /* Required for _delay_ms() */


 void switchON()
 {
 /*PD2 should be low*/
 PORTB &= ~(1 << PB5);
 return;
 }
 void switchOFF()
 {
 
 return;
 }
 int main(void)
 {
 /*configuring PORTB Pin5 as output*/
 DDRB |= (1 << DDD5);
 /*configuring Pull down circuit on PORTD Pin5*/
 DDRD &= ~(1 << DDD2);
 while (1)
 {
 if(PIND & (1 << PD2))
 {
 switchON();
 }
 else
 {
 switchOFF();
 }
 return 0;
 }

