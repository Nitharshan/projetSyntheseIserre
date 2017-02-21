################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/StringUtility.c \
../Sources/Xbee_Driver.c \
../Sources/app.c \
../Sources/console.c \
../Sources/fifo_buffer.c \
../Sources/iSerre-SN.c \
../Sources/main.c \
../Sources/sensor.c 

OBJS += \
./Sources/Events.o \
./Sources/StringUtility.o \
./Sources/Xbee_Driver.o \
./Sources/app.o \
./Sources/console.o \
./Sources/fifo_buffer.o \
./Sources/iSerre-SN.o \
./Sources/main.o \
./Sources/sensor.o 

C_DEPS += \
./Sources/Events.d \
./Sources/StringUtility.d \
./Sources/Xbee_Driver.d \
./Sources/app.d \
./Sources/console.d \
./Sources/fifo_buffer.d \
./Sources/iSerre-SN.d \
./Sources/main.d \
./Sources/sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL26Z128VLH4" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/hal/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/hal/src/sim/MKL26Z4" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/system/src/clock/MKL26Z4" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/system/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/osa/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/CMSIS/Include" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/devices" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/devices/MKL26Z4/include" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/utilities/src" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/utilities/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/cheik/workspace.kds/Temp/Generated_Code/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/cheik/workspace.kds/Temp/Sources" -I"C:/Users/cheik/workspace.kds/Temp/Generated_Code" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


