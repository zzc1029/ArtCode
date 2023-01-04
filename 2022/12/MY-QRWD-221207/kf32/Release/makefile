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
all: YB-MY-QRWD-221207.hex

# 工具调用
YB-MY-QRWD-221207.hex: $(OBJS) $(USER_RELS)
	@echo 'Building target: $@'
#	@echo 'Invoking: C Linker Release'
	@kf32-ld $(OBJS) $(USER_RELS) $(LIBS) -L"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/ccr1_issue_v0/lib" -L"D:\zzc\project\pro_2022\pro_12\MY-QRWD-221207\kf32" -lIQmath-R1 -lSeriesDIServices -lmath -lio -lstring -lstdlib -lctype -lcrtv1 -T"D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/KF32A152MQV.ld" --kf32-arch=kf32r --kf32-z --gc-sections -o  "YB-MY-QRWD-221207.elf" -Map "YB-MY-QRWD-221207.map"
	@echo 'Finished building target: $@'
#	@echo ' '
	$(MAKE) --no-print-directory post-build

# 其他目标
clean:
	-$(RM) $(OBJS)$(EXECUTABLES)$(C_DEPS) YB-MY-QRWD-221207.hex
#	-@echo ' '

post-build:
	-../pack/pack.sh YB-MY-QRWD-221207  D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
