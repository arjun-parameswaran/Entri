/*
 * ultrasonic_based_industrial_safety_alert_system.c
 *
 * Created: 14-12-2025 12:38:18
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define CRITICAL_ZONE 10
#define BUZZER PD5

int main(void)
{
	ultrasonic_pin_init();
	pwm_config();
	buzzer_init();

	while (1)
	{
		uint16_t distance = ultrasonic_read_distance();
		uint8_t duty = pwm_val(distance);
		buzzer_alert(distance);
		

		OCR0A = duty;
		_delay_ms(60);
	}
}