################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/startup.c \
../system/system_init.c \
../system/vector.c 

OBJS += \
./system/startup.o \
./system/system_init.o \
./system/vector.o 

C_DEPS += \
./system/startup.d \
./system/system_init.d \
./system/vector.d 


# Each subdirectory must supply rules for building sources it contributes
system/%.o: ../system/%.c
	@echo 'Building file: $<'
#	@echo 'Invoking: C Compiler Release'
	@mkdir -p "_static_code_analysis"
	@kf32-gcc  -MMD -I"G:/workspace32/YB-GZST-QRWD-221203/system" -I"G:/workspace32/YB-GZST-QRWD-221203/system/inc" -I"G:/workspace32/YB-GZST-QRWD-221203/driver" -I"G:/workspace32/YB-GZST-QRWD-221203/source" -I"G:/workspace32/YB-GZST-QRWD-221203" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include/Sys" -save-temps -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -c -funsigned-char -fsigned-bitfields -Wa,--kf32-arch=kf32r,-I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include" -ffunction-sections -fdata-sections -D"KF32A152MQV" -D"__RELEASE__" -Wno-packed-bitfield-compat -std=gnu99 -gstabs+ -O2 $< -o "$@"
	@echo 'Finished building: $<'

