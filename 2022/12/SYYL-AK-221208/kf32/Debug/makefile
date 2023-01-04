################################################################################
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := @rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/src/subdir.mk
-include system/subdir.mk
-include source/subdir.mk
-include driver/subdir.mk
-include subdir.mk
-include objects.mk

-include $(C_DEPS)

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# 所有目标
all: ART_BOOT.hex

# 工具调用
ART_BOOT.hex: $(OBJS) $(USER_RELS)
	@echo 'Building target: $@'
#	@echo 'Invoking: C Linker Debug'
	@kf32-ld $(OBJS) $(USER_RELS) $(LIBS) -L"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/ccr1_issue_v0/lib" -L"D:\zzc\project\pro_2021\pro_12\FYGJ-AK-211230\code\ART_BOOT" -lIQmath-R1 -lSeriesDIServices -lmath -lio -lstring -lstdlib -lctype -lcrtv1 -T"D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/KF32A152MQV.ld" --kf32-autoihex --kf32-arch=kf32r --gc-sections -o  "ART_BOOT.elf" -Map "ART_BOOT.map"
	@echo 'Finished building target: $@'
#	@echo ' '
	$(MAKE) --no-print-directory post-build

# 其他目标
clean:
	-$(RM) $(OBJS)$(EXECUTABLES)$(C_DEPS) ART_BOOT.hex
#	-@echo ' '

post-build:
	-rm  -r  "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/bin" & mkdir "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
