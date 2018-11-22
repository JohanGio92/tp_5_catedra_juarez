################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/models/Airport.cpp \
../src/models/FlightInformation.cpp 

OBJS += \
./src/models/Airport.o \
./src/models/FlightInformation.o 

CPP_DEPS += \
./src/models/Airport.d \
./src/models/FlightInformation.d 


# Each subdirectory must supply rules for building sources it contributes
src/models/%.o: ../src/models/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


