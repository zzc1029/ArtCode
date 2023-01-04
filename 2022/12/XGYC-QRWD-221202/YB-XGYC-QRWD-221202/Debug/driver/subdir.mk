################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/Bcan.c \
../driver/Dcan.c \
../driver/Pcan1.c \
../driver/Pcan2.c \
../driver/Pcan3.c \
../driver/Rtc.c \
../driver/canfifo.c \
../driver/canreceive.c \
../driver/gpio.c \
../driver/iic.c \
../driver/sch.c \
../driver/switch.c \
../driver/timer.c 

OBJS += \
./driver/Bcan.o \
./driver/Dcan.o \
./driver/Pcan1.o \
./driver/Pcan2.o \
./driver/Pcan3.o \
./driver/Rtc.o \
./driver/canfifo.o \
./driver/canreceive.o \
./driver/gpio.o \
./driver/iic.o \
./driver/sch.o \
./driver/switch.o \
./driver/timer.o 

C_DEPS += \
./driver/Bcan.d \
./driver/Dcan.d \
./driver/Pcan1.d \
./driver/Pcan2.d \
./driver/Pcan3.d \
./driver/Rtc.d \
./driver/canfifo.d \
./driver/canreceive.d \
./driver/gpio.d \
./driver/iic.d \
./driver/sch.d \
./driver/switch.d \
./driver/timer.d 


# Each subdirectory must supply rules for building sources it contributes
driver/%.o: ../driver/%.c
	@echo 'Building file: $<'
#	@echo 'Invoking: C Compiler Debug'
	@kf32-gcc  -MMD -I"H:\workspace32\App" -I"H:/workspace32/App" -I"H:/workspace32/App/source" -I"H:/workspace32/App/driver" -I"H:/workspace32/App/system/inc" -I"H:/workspace32/App/system" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys" -save-temps -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -c -funsigned-char -fsigned-bitfields -Wa,--kf32-arch=kf32r,-I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -ffunction-sections -fdata-sections -D"KF32A152MQV" -D"DEBUG" -Wno-packed-bitfield-compat -std=gnu99 -gstabs+ -O0 $< -o "$@"
	@echo 'Finished building: $<'

