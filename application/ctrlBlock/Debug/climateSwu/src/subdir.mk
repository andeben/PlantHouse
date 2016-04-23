################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../climateSwu/src/ClimateFacade.cpp 

OBJS += \
./climateSwu/src/ClimateFacade.o 

CPP_DEPS += \
./climateSwu/src/ClimateFacade.d 


# Each subdirectory must supply rules for building sources it contributes
climateSwu/src/%.o: ../climateSwu/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


