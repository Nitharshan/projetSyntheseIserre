################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/system/src/clock/MKL26Z4/fsl_clock_MKL26Z4.c 

OBJS += \
./SDK/platform/system/src/clock/MKL26Z4/fsl_clock_MKL26Z4.o 

C_DEPS += \
./SDK/platform/system/src/clock/MKL26Z4/fsl_clock_MKL26Z4.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/system/src/clock/MKL26Z4/%.o: ../SDK/platform/system/src/clock/MKL26Z4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL26Z128VLH4" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/hal/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/hal/src/sim/MKL26Z4" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/system/src/clock/MKL26Z4" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/system/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/osa/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/CMSIS/Include" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/devices" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/devices/MKL26Z4/include" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/utilities/src" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/utilities/inc" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/cheik/workspace.kds/Temp/Generated_Code/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/cheik/workspace.kds/Temp/Sources" -I"C:/Users/cheik/workspace.kds/Temp/Generated_Code" -I"C:/Users/cheik/workspace.kds/Temp/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


