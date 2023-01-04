################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/Adc.c \
../driver/Bcan.c \
../driver/Dcan.c \
../driver/EElogic.c \
../driver/Emios.c \
../driver/Pcan.c \
../driver/Rtc.c \
../driver/Usart.c \
../driver/ZD24C0x.c \
../driver/can.c \
../driver/canfifo.c \
../driver/flash.c \
../driver/gpio.c \
../driver/iic.c \
../driver/key.c \
../driver/keyfif.c \
../driver/led.c \
../driver/motor.c \
../driver/output.c \
../driver/pwm.c \
../driver/sch.c \
../driver/timer.c \
../driver/watchdog.c 

OBJS += \
./driver/Adc.o \
./driver/Bcan.o \
./driver/Dcan.o \
./driver/EElogic.o \
./driver/Emios.o \
./driver/Pcan.o \
./driver/Rtc.o \
./driver/Usart.o \
./driver/ZD24C0x.o \
./driver/can.o \
./driver/canfifo.o \
./driver/flash.o \
./driver/gpio.o \
./driver/iic.o \
./driver/key.o \
./driver/keyfif.o \
./driver/led.o \
./driver/motor.o \
./driver/output.o \
./driver/pwm.o \
./driver/sch.o \
./driver/timer.o \
./driver/watchdog.o 

C_DEPS += \
./driver/Adc.d \
./driver/Bcan.d \
./driver/Dcan.d \
./driver/EElogic.d \
./driver/Emios.d \
./driver/Pcan.d \
./driver/Rtc.d \
./driver/Usart.d \
./driver/ZD24C0x.d \
./driver/can.d \
./driver/canfifo.d \
./driver/flash.d \
./driver/gpio.d \
./driver/iic.d \
./driver/key.d \
./driver/keyfif.d \
./driver/led.d \
./driver/motor.d \
./driver/output.d \
./driver/pwm.d \
./driver/sch.d \
./driver/timer.d \
./driver/watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
driver/%.o: ../driver/%.c
	@echo 'Building file: $<'
#	@echo 'Invoking: C Compiler Release'
	@kf32-gcc  -MMD -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system" -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc" -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/driver" -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/source" -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys" -save-temps -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -c -funsigned-char -fsigned-bitfields -Wa,--kf32-arch=kf32r,-I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -ffunction-sections -fdata-sections -D"KF32A152MQV" -Wno-packed-bitfield-compat -std=gnu99 -gstabs+ -O2 $< -o "$@"
	@echo 'Finished building: $<'

