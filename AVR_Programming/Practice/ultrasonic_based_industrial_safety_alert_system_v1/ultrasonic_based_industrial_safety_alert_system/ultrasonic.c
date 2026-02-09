/*
 * ultrasonic.c
 *
 * Created: 14-12-2025 12:46:55
 *  Author: ARJUN
 */ 
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


void pwm_config();
void ultrasonic_pin_init(void);
uint16_t ultrasonic_read_distance();
uint8_t pwm_val(uint16_t distance);




#endif /* ULTRASONIC_H_ */