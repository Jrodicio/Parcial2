################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../GetValues.c \
../LinkedList.c \
../Menu.c \
../Parser.c \
../Pilotos.c \
../Vuelos.c \
../main.c 

OBJS += \
./Controller.o \
./GetValues.o \
./LinkedList.o \
./Menu.o \
./Parser.o \
./Pilotos.o \
./Vuelos.o \
./main.o 

C_DEPS += \
./Controller.d \
./GetValues.d \
./LinkedList.d \
./Menu.d \
./Parser.d \
./Pilotos.d \
./Vuelos.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


