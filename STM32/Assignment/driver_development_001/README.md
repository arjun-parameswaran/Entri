# STM32F401 GPIO Button and LED Control

## Description
This project demonstrates basic GPIO input and output on the STM32F401
microcontroller using a custom GPIO driver.

- On-board push button controls the on-board LED
- Two external LEDs blink alternately using a non-blocking delay

## Hardware Used
- STM32F401 (NUCLEO-F401RE)
- Push button (PC13)
- Onboard LED (PA5)
- External LED 1 (PA6)
- External LED 2 (PA7)
- Resistors for LEDs

## Pin Configuration

- PA5  - Onboard LED (toggle on button press) 
- PA6  - External LED 1 
- PA7  - External LED 2 
- PC13 - Push button input (pull-up enabled) 

## Working
1. GPIO pins are initialized using a custom GPIO driver.
2. The button on PC13 is read continuously - used state change method inorder to detect the switch press
   - avoid using delys bloking delay to prevent the Debounce.
4. When the button is pressed (falling edge detected), the onboard LED (PA5) toggles.
5. A software counter creates a non-blocking delay.
6. Based on a flag, PA6 and PA7 turn ON alternately.

## Key Points
- Button is active-low
- Edge detection avoids multiple toggles
- Delay is non-blocking (no blocking delay loops)

## Notes
- Button debouncing is not implemented
- Delay timing depends on system clock
- Timers can be used for accurate delays

## Author
STM32 GPIO practice project
