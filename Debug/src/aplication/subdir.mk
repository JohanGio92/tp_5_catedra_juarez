################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/aplication/Airline.cpp \
../src/aplication/CancelationCommand.cpp \
../src/aplication/Command.cpp \
../src/aplication/DisplayerCommand.cpp \
../src/aplication/ExitCommand.cpp \
../src/aplication/Menu.cpp \
../src/aplication/RegistrationCommand.cpp 

OBJS += \
./src/aplication/Airline.o \
./src/aplication/CancelationCommand.o \
./src/aplication/Command.o \
./src/aplication/DisplayerCommand.o \
./src/aplication/ExitCommand.o \
./src/aplication/Menu.o \
./src/aplication/RegistrationCommand.o 

CPP_DEPS += \
./src/aplication/Airline.d \
./src/aplication/CancelationCommand.d \
./src/aplication/Command.d \
./src/aplication/DisplayerCommand.d \
./src/aplication/ExitCommand.d \
./src/aplication/Menu.d \
./src/aplication/RegistrationCommand.d 


# Each subdirectory must supply rules for building sources it contributes
src/aplication/%.o: ../src/aplication/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


