/*
 * main.h
 *
 * Created: 30-01-2026 17:30:13
 *  Author: ARJUN
 */ 


#ifndef MAIN_H_
#define MAIN_H_

/* Shared time variables */
extern volatile uint16_t press_timer;
extern volatile uint16_t ms;
extern volatile uint8_t sec;
extern volatile uint8_t min;

#define LONG_PRESS_TIME		1000
#define SHORT_PRESS_TIME	20

/* Shared flags */
extern volatile uint8_t stopwatch_enable_flag;
extern volatile uint8_t blink_flag;
extern volatile uint8_t switch_flag; 

/*GPIO - Macro*/
#define SWITCH_PORT			PORTC
#define SWITCH_PORT_DDR		DDRC
#define SWITCH				PC1
#define SWITCH_PRESSED		!(PINC & 1 << SWITCH)

#define LED_ON				PC2
#define LED_OFF				PC3
#define ENABLE				1
#define DISABLE				0
#define RESET				0

/*GPIO - Functions*/
void gpio_init(void);
void switch_press();

/*Interrupt functions*/
void timer1_init(void);


/*LCD*/

//RS PIN
#define LCD_RS_DDR		DDRB
#define LCD_RS_PORT		PORTB
#define LCD_RS_PIN		PB0

//EN PIN
#define LCD_EN_DDR		DDRB
#define LCD_EN_PORT		PORTB
#define LCD_EN_PIN		PB1

//DATA & COMMAND PINS (D4 - D7)
#define LCD_DATA_DDR	DDRD
#define LCD_DATA_PORT	PORTD
#define LCD_D7_PIN		PD7
#define LCD_D6_PIN		PD6
#define LCD_D5_PIN		PD5
#define LCD_D4_PIN		PD4
//definitions for
#define CLEAR_SCREEN	0x01
#define RETURN_HOME		0x02

//function definitions
void lcd_init(void);
static void lcd_send_nibble(uint8_t nibble);
void lcd_cmd(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_print(char *str);
voidlcd_print_uint16(uint16_t num);
void lcd_clear(void);
void lcd_home(void);


/*STOPWATCH*/
void stopwatch_display();


#endif /* MAIN_H_ */