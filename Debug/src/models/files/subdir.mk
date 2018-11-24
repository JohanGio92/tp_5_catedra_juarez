################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/models/files/FlightRecord.cpp 

OBJS += \
./src/models/files/FlightRecord.o 

CPP_DEPS += \
./src/models/files/FlightRecord.d 


# Each subdirectory must supply rules for building sources it contributes
src/models/files/%.o: ../src/models/files/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


