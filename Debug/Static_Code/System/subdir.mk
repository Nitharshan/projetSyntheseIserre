################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Static_Code/System/PE_low_level_init.c 

OBJS += \
./Static_Code/System/PE_low_level_init.o 

C_DEPS += \
./Static_Code/System/PE_low_level_init.d 


# Each subdirectory must supply rules for building sources it contributes
Static_Code/System/%.o: ../Static_Code/System/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL26Z128VLH4" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/hal/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/hal/src/sim/MKL26Z4" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/system/src/clock/MKL26Z4" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/system/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/osa/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/CMSIS/Include" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/devices" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/devices/MKL26Z4/include" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/utilities/src" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/utilities/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/Generated_Code/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/Sources" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/Generated_Code" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


