################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/motor/motor_prog.c 

OBJS += \
./HAL/motor/motor_prog.o 

C_DEPS += \
./HAL/motor/motor_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/motor/%.o: ../HAL/motor/%.c HAL/motor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\HAL\ULTRA_SONIC" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\HAL\motor" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\APP" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\HAL\KeyPad" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\HAL\LCD" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\HAL\LED" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\HAL\LM35" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\HAL\PB" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\HAL\SSD" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\LIB" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\MCAL\ADC" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\MCAL\DIO" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\MCAL\EXTI" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\MCAL\GIE" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\MCAL\TIMER" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\MCAL\TIMER1" -I"C:\Users\AgAmIa\eclipse-workspace\final_project3\MCAL\WDT" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


