################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/Adc.c \
../driver/Bcan.c \
../driver/Dcan.c \
../driver/EElogic.c \
../driver/Pcan1.c \
../driver/Pcan2.c \
../driver/Pcan3.c \
../driver/Rtc.c \
../driver/T123AI.c \
../driver/ZD24C0x.c \
../driver/canfifo.c \
../driver/canreceive.c \
../driver/eeprom.c \
../driver/emios.c \
../driver/flash.c \
../driver/gpio.c \
../driver/iic.c \
../driver/key.c \
../driver/keyfif.c \
../driver/led.c \
../driver/output.c \
../driver/sch.c \
../driver/switch.c \
../driver/timer.c \
../driver/watchdog.c 

OBJS += \
./driver/Adc.o \
./driver/Bcan.o \
./driver/Dcan.o \
./driver/EElogic.o \
./driver/Pcan1.o \
./driver/Pcan2.o \
./driver/Pcan3.o \
./driver/Rtc.o \
./driver/T123AI.o \
./driver/ZD24C0x.o \
./driver/canfifo.o \
./driver/canreceive.o \
./driver/eeprom.o \
./driver/emios.o \
./driver/flash.o \
./driver/gpio.o \
./driver/iic.o \
./driver/key.o \
./driver/keyfif.o \
./driver/led.o \
./driver/output.o \
./driver/sch.o \
./driver/switch.o \
./driver/timer.o \
./driver/watchdog.o 

C_DEPS += \
./driver/Adc.d \
./driver/Bcan.d \
./driver/Dcan.d \
./driver/EElogic.d \
./driver/Pcan1.d \
./driver/Pcan2.d \
./driver/Pcan3.d \
./driver/Rtc.d \
./driver/T123AI.d \
./driver/ZD24C0x.d \
./driver/canfifo.d \
./driver/canreceive.d \
./driver/eeprom.d \
./driver/emios.d \
./driver/flash.d \
./driver/gpio.d \
./driver/iic.d \
./driver/key.d \
./driver/keyfif.d \
./driver/led.d \
./driver/output.d \
./driver/sch.d \
./driver/switch.d \
./driver/timer.d \
./driver/watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
driver/%.o: ../driver/%.c
	@echo 'Building file: $<'
#	@echo 'Invoking: C Compiler Release'
	@kf32-gcc  -MMD -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system" -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc" -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver" -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source" -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys" -save-temps -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -c -funsigned-char -fsigned-bitfields -Wa,--kf32-arch=kf32r,-I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -ffunction-sections -fdata-sections -D"KF32A152MQV" -Wno-packed-bitfield-compat -std=gnu99 -gstabs+ -O2 $< -o "$@"
	@echo 'Finished building: $<'

