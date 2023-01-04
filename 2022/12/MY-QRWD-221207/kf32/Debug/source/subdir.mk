################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/MeterConfig.c \
../source/T123.c \
../source/bootloader.c \
../source/canreceive.c \
../source/display.c \
../source/displayhelper.c \
../source/eeprom.c \
../source/kf_it.c \
../source/main.c \
../source/switch.c \
../source/system.c 

OBJS += \
./source/MeterConfig.o \
./source/T123.o \
./source/bootloader.o \
./source/canreceive.o \
./source/display.o \
./source/displayhelper.o \
./source/eeprom.o \
./source/kf_it.o \
./source/main.o \
./source/switch.o \
./source/system.o 

C_DEPS += \
./source/MeterConfig.d \
./source/T123.d \
./source/bootloader.d \
./source/canreceive.d \
./source/display.d \
./source/displayhelper.d \
./source/eeprom.d \
./source/kf_it.d \
./source/main.d \
./source/switch.d \
./source/system.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
#	@echo 'Invoking: C Compiler Debug'
	@kf32-gcc  -MMD -I"D:\zzc\project\pro_2021\pro_12\FYGJ-AK-211230\code\ART_BOOT" -I"D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT" -I"D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/source" -I"D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/driver" -I"D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc" -I"D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys" -save-temps -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -c -funsigned-char -fsigned-bitfields -Wa,--kf32-arch=kf32r,-I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -ffunction-sections -fdata-sections -D"KF32A152MQV" -D"DEBUG" -Wno-packed-bitfield-compat -std=gnu99 -gstabs+ -O0 $< -o "$@"
	@echo 'Finished building: $<'

