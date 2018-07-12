################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include readAndCompareFinger/subdir.mk
-include libraries/SoftwareSerial/src/subdir.mk
-include libraries/Adafruit_Fingerprint_Sensor_Library/subdir.mk
-include libraries/subdir.mk
-include gpsDataPark/subdir.mk
-include global\ value/subdir.mk
-include fingerprint_data/subdir.mk
-include core/core/subdir.mk
-include changeIdFinger/subdir.mk
-include ListIdUse/subdir.mk
-include ClearID/subdir.mk
-include AddNewId/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/Release/arduino.ar \

ELF += \
TestFuncionWithIOTLibs.elf \

HEX += \
TestFuncionWithIOTLibs.hex \


# All Target
all: TestFuncionWithIOTLibs

# Tool invocations
TestFuncionWithIOTLibs: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/user/software/develop/eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-size" -A "/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/Release/TestFuncionWithIOTLibs.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/user/software/develop/eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs    /home/user/workspace/eclipse1/TestFuncionWithIOTLibs/Release/arduino.ar $(AR_OBJ)    /home/user/workspace/NoPCShare/IotTeam/IoTHeartLibs/Arduino/avr/sbash.o
	@echo 'Finished building: $@'
	@echo ' '

TestFuncionWithIOTLibs.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/user/software/develop/eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p -o "/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/Release/TestFuncionWithIOTLibs.elf"  -Wl,-Map=output.map  $(LINK_OBJ) $(AR)   /home/user/workspace/eclipse1/TestFuncionWithIOTLibs/Release/arduino.ar  "-L/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

TestFuncionWithIOTLibs.hex: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
