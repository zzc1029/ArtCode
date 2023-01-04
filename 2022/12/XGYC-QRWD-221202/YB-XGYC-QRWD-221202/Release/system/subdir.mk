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
	@kf32-gcc  -MMD -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system" -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc" -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver" -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source" -I"H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys" -save-temps -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -c -funsigned-char -fsigned-bitfields -Wa,--kf32-arch=kf32r,-I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -ffunction-sections -fdata-sections -D"KF32A152MQV" -Wno-packed-bitfield-compat -std=gnu99 -gstabs+ -O2 $< -o "$@"
	@echo 'Finished building: $<'

