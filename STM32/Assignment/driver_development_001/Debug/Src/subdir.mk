################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio_toggle.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/toggle_led_state.c 

OBJS += \
./Src/gpio_toggle.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/toggle_led_state.o 

C_DEPS += \
./Src/gpio_toggle.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/toggle_led_state.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"D:/STM32/Workspace/F401_driver_development/driver_development_001/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/gpio_toggle.cyclo ./Src/gpio_toggle.d ./Src/gpio_toggle.o ./Src/gpio_toggle.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/toggle_led_state.cyclo ./Src/toggle_led_state.d ./Src/toggle_led_state.o ./Src/toggle_led_state.su

.PHONY: clean-Src

