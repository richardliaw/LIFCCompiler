################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/code_gen.c \
../src/compiler.c \
../src/lexer.c \
../src/parser.c 

OBJS += \
./src/code_gen.o \
./src/compiler.o \
./src/lexer.o \
./src/parser.o 

C_DEPS += \
./src/code_gen.d \
./src/compiler.d \
./src/lexer.d \
./src/parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


