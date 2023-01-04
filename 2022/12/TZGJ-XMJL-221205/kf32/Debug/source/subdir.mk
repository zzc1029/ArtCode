################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/bootloader.c \
../source/kf_it.c \
../source/main.c \
../source/system.c 

OBJS += \
./source/bootloader.o \
./source/kf_it.o \
./source/main.o \
./source/system.o 

C_DEPS += \
./source/bootloader.d \
./source/kf_it.d \
./source/main.d \
./source/system.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
#	@echo 'Invoking: C Compiler Debug'
	@kf32-gcc  -MMD -I"H:\workspace32\App" -I"H:/workspace32/App" -I"H:/workspace32/App/source" -I"H:/workspace32/App/driver" -I"H:/workspace32/App/system/inc" -I"H:/workspace32/App/system" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys" -save-temps -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -c -funsigned-char -fsigned-bitfields -Wa,--kf32-arch=kf32r,-I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -ffunction-sections -fdata-sections -D"KF32A152MQV" -D"DEBUG" -Wno-packed-bitfield-compat -std=gnu99 -gstabs+ -O0 $< -o "$@"
	@echo 'Finished building: $<'

