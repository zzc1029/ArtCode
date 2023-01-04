################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/kf32a_basic_adc.c \
../system/src/kf32a_basic_aes.c \
../system/src/kf32a_basic_atim.c \
../system/src/kf32a_basic_bkp.c \
../system/src/kf32a_basic_btim.c \
../system/src/kf32a_basic_can.c \
../system/src/kf32a_basic_cfgl.c \
../system/src/kf32a_basic_cmp.c \
../system/src/kf32a_basic_crc.c \
../system/src/kf32a_basic_dac.c \
../system/src/kf32a_basic_dma.c \
../system/src/kf32a_basic_exic.c \
../system/src/kf32a_basic_flash.c \
../system/src/kf32a_basic_gpio.c \
../system/src/kf32a_basic_gptim.c \
../system/src/kf32a_basic_i2c.c \
../system/src/kf32a_basic_int.c \
../system/src/kf32a_basic_iwdt.c \
../system/src/kf32a_basic_lcd.c \
../system/src/kf32a_basic_led.c \
../system/src/kf32a_basic_op.c \
../system/src/kf32a_basic_osc.c \
../system/src/kf32a_basic_pclk.c \
../system/src/kf32a_basic_pm.c \
../system/src/kf32a_basic_qei.c \
../system/src/kf32a_basic_rst.c \
../system/src/kf32a_basic_rtc.c \
../system/src/kf32a_basic_spi.c \
../system/src/kf32a_basic_sysctl.c \
../system/src/kf32a_basic_systick.c \
../system/src/kf32a_basic_usart.c \
../system/src/kf32a_basic_usb.c \
../system/src/kf32a_basic_wwdt.c 

OBJS += \
./system/src/kf32a_basic_adc.o \
./system/src/kf32a_basic_aes.o \
./system/src/kf32a_basic_atim.o \
./system/src/kf32a_basic_bkp.o \
./system/src/kf32a_basic_btim.o \
./system/src/kf32a_basic_can.o \
./system/src/kf32a_basic_cfgl.o \
./system/src/kf32a_basic_cmp.o \
./system/src/kf32a_basic_crc.o \
./system/src/kf32a_basic_dac.o \
./system/src/kf32a_basic_dma.o \
./system/src/kf32a_basic_exic.o \
./system/src/kf32a_basic_flash.o \
./system/src/kf32a_basic_gpio.o \
./system/src/kf32a_basic_gptim.o \
./system/src/kf32a_basic_i2c.o \
./system/src/kf32a_basic_int.o \
./system/src/kf32a_basic_iwdt.o \
./system/src/kf32a_basic_lcd.o \
./system/src/kf32a_basic_led.o \
./system/src/kf32a_basic_op.o \
./system/src/kf32a_basic_osc.o \
./system/src/kf32a_basic_pclk.o \
./system/src/kf32a_basic_pm.o \
./system/src/kf32a_basic_qei.o \
./system/src/kf32a_basic_rst.o \
./system/src/kf32a_basic_rtc.o \
./system/src/kf32a_basic_spi.o \
./system/src/kf32a_basic_sysctl.o \
./system/src/kf32a_basic_systick.o \
./system/src/kf32a_basic_usart.o \
./system/src/kf32a_basic_usb.o \
./system/src/kf32a_basic_wwdt.o 

C_DEPS += \
./system/src/kf32a_basic_adc.d \
./system/src/kf32a_basic_aes.d \
./system/src/kf32a_basic_atim.d \
./system/src/kf32a_basic_bkp.d \
./system/src/kf32a_basic_btim.d \
./system/src/kf32a_basic_can.d \
./system/src/kf32a_basic_cfgl.d \
./system/src/kf32a_basic_cmp.d \
./system/src/kf32a_basic_crc.d \
./system/src/kf32a_basic_dac.d \
./system/src/kf32a_basic_dma.d \
./system/src/kf32a_basic_exic.d \
./system/src/kf32a_basic_flash.d \
./system/src/kf32a_basic_gpio.d \
./system/src/kf32a_basic_gptim.d \
./system/src/kf32a_basic_i2c.d \
./system/src/kf32a_basic_int.d \
./system/src/kf32a_basic_iwdt.d \
./system/src/kf32a_basic_lcd.d \
./system/src/kf32a_basic_led.d \
./system/src/kf32a_basic_op.d \
./system/src/kf32a_basic_osc.d \
./system/src/kf32a_basic_pclk.d \
./system/src/kf32a_basic_pm.d \
./system/src/kf32a_basic_qei.d \
./system/src/kf32a_basic_rst.d \
./system/src/kf32a_basic_rtc.d \
./system/src/kf32a_basic_spi.d \
./system/src/kf32a_basic_sysctl.d \
./system/src/kf32a_basic_systick.d \
./system/src/kf32a_basic_usart.d \
./system/src/kf32a_basic_usb.d \
./system/src/kf32a_basic_wwdt.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/%.o: ../system/src/%.c
	@echo 'Building file: $<'
#	@echo 'Invoking: C Compiler Release'
	@kf32-gcc  -MMD -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system" -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc" -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/driver" -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/source" -I"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys" -save-temps -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -c -funsigned-char -fsigned-bitfields -Wa,--kf32-arch=kf32r,-I"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include" -ffunction-sections -fdata-sections -D"KF32A152MQV" -Wno-packed-bitfield-compat -std=gnu99 -gstabs+ -O2 $< -o "$@"
	@echo 'Finished building: $<'

