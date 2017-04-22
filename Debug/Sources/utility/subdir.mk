################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/utility/conversion.cpp 

C_SRCS += \
../Sources/utility/Clock.c \
../Sources/utility/StringUtility.c 

OBJS += \
./Sources/utility/Clock.o \
./Sources/utility/StringUtility.o \
./Sources/utility/conversion.o 

C_DEPS += \
./Sources/utility/Clock.d \
./Sources/utility/StringUtility.d 

CPP_DEPS += \
./Sources/utility/conversion.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/utility/%.o: ../Sources/utility/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL26Z128VLH4" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/hal/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/hal/src/sim/MKL26Z4" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/system/src/clock/MKL26Z4" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/system/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/osa/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/CMSIS/Include" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/devices" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/devices/MKL26Z4/include" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/utilities/src" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/utilities/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/Generated_Code/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/Sources" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/Generated_Code" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/utility/%.o: ../Sources/utility/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL26Z128VLH4" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/hal/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/hal/src/sim/MKL26Z4" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/system/src/clock/MKL26Z4" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/system/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/osa/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/CMSIS/Include" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/devices" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/devices/MKL26Z4/include" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/utilities/src" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/utilities/inc" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/Generated_Code/SDK/platform/devices/MKL26Z4/startup" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/Sources" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/Generated_Code" -I"C:/Users/iSerre/Desktop/ProjetSynthese/iSerreTemperatureSensor/SDK/platform/drivers/inc" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


