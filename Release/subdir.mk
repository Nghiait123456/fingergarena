################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
../fingerDone.ino 

CPP_SRCS += \
../.ino.cpp 

LINK_OBJ += \
./.ino.cpp.o 

INO_DEPS += \
./fingerDone.ino.d 

CPP_DEPS += \
./.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
.ino.cpp.o: ../.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/user/software/develop/eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"/home/user/software/develop/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"/home/user/software/develop/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/variants/mega" -I"/home/user/software/develop/eclipse/arduinoPlugin/libraries/Adafruit_Fingerprint_Sensor_Library/1.1.1" -I"/home/user/software/develop/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial" -I"/home/user/software/develop/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/ClearID" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/AddNewId" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/ListIdUse" -I"/home/user/workspace/eclipse1/FingerGaneral/global value" -I"/home/user/workspace/eclipse1/FingerGaneral/fingerprint_data" -I"/home/user/workspace/eclipse1/FingerGaneral/readAndCompareFinger" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/changeIdFinger" -I"/home/user/workspace/eclipse1/FingerGaneral/gpsDataPark" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/delayNooLoop" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

fingerDone.o: ../fingerDone.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/user/software/develop/eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"/home/user/software/develop/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"/home/user/software/develop/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/variants/mega" -I"/home/user/software/develop/eclipse/arduinoPlugin/libraries/Adafruit_Fingerprint_Sensor_Library/1.1.1" -I"/home/user/software/develop/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial" -I"/home/user/software/develop/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/ClearID" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/AddNewId" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/ListIdUse" -I"/home/user/workspace/eclipse1/FingerGaneral/global value" -I"/home/user/workspace/eclipse1/FingerGaneral/fingerprint_data" -I"/home/user/workspace/eclipse1/FingerGaneral/readAndCompareFinger" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/changeIdFinger" -I"/home/user/workspace/eclipse1/FingerGaneral/gpsDataPark" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs" -I"/home/user/workspace/eclipse1/TestFuncionWithIOTLibs/delayNooLoop" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


