################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/DbgCs1.c \
../Generated_Code/KSDK1.c \
../Generated_Code/WAIT1.c \
../Generated_Code/clockMan1.c \
../Generated_Code/hardware_init.c \
../Generated_Code/osa1.c \
../Generated_Code/pin_init.c \
../Generated_Code/uartCom1.c \
../Generated_Code/uart_xb.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/DbgCs1.o \
./Generated_Code/KSDK1.o \
./Generated_Code/WAIT1.o \
./Generated_Code/clockMan1.o \
./Generated_Code/hardware_init.o \
./Generated_Code/osa1.o \
./Generated_Code/pin_init.o \
./Generated_Code/uartCom1.o \
./Generated_Code/uart_xb.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/DbgCs1.d \
./Generated_Code/KSDK1.d \
./Generated_Code/WAIT1.d \
./Generated_Code/clockMan1.d \
./Generated_Code/hardware_init.d \
./Generated_Code/osa1.d \
./Generated_Code/pin_init.d \
./Generated_Code/uartCom1.d \
./Generated_Code/uart_xb.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL26Z128VLH4" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/hal/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/hal/src/sim/MKL26Z4" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/system/src/clock/MKL26Z4" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/system/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/osa/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/CMSIS/Include" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/devices" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/devices/MKL26Z4/include" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/utilities/src" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/utilities/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/cheik/workspace.kds/Temp/Generated_Code/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/cheik/workspace.kds/Temp/Sources" -I"C:/Users/cheik/workspace.kds/Temp/Generated_Code" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


