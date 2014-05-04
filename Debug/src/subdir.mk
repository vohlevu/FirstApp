################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FirstApp.cpp 

OBJS += \
./src/FirstApp.o 

CPP_DEPS += \
./src/FirstApp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"/cygdrive/c/cygwin/lib/gcc/i686-pc-cygwin/4.8.2/include" -I"/cygdrive/c/cygwin/lib/gcc/i686-pc-cygwin/4.8.2/include-fixed" -I"/cygdrive/c/cygwin/lib/gcc/i686-pc-cygwin/4.8.2/include/c++" -I"/cygdrive/c/cygwin/lib/gcc/i686-pc-cygwin/4.8.2/include/c++/i686-pc-cygwin" -I"/cygdrive/c/working-lib/curl-7.36.0/include" -I"/cygdrive/c/cygwin/lib/gcc/i686-pc-cygwin/4.8.2/include/c++/backward" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


