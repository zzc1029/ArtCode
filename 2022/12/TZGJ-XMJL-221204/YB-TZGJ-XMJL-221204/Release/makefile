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
OBJDUMP_LIST += \
YB-TZGJ-XMJL-221204.lst \

OBJCOPY_TARGET += \
YB-TZGJ-XMJL-221204.s19 \


LD_SRCS =D:/ARTStanHome/Desktop/TZGJ-XMJL-221204/YB-TZGJ-XMJL-221204/system/KF32A152MQV.ld

EXECUTABLES	= YB-TZGJ-XMJL-221204.elf
# 所有目标
all: YB-TZGJ-XMJL-221204.elf secondary-outputs

# 工具调用
YB-TZGJ-XMJL-221204.elf: $(OBJS) $(USER_RELS) $(LD_SRCS)
	@echo 'Building target: $@'
#	@echo 'Invoking: C Linker Release'
	@kf32-ld $(OBJS) $(USER_RELS) $(LIBS) -L"C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/ccr1_issue_v0/lib" -L"D:\ARTStanHome\Desktop\TZGJ-XMJL-221204\YB-TZGJ-XMJL-221204" -lIQmath-R1 -lSeriesDIServices -lmath -lio -lstring -lstdlib -lctype -lcrtv1 -T"D:/ARTStanHome/Desktop/TZGJ-XMJL-221204/YB-TZGJ-XMJL-221204/system/KF32A152MQV.ld" --kf32-arch=kf32r --kf32-nodisassemble --kf32-z --gc-sections -o  "YB-TZGJ-XMJL-221204.elf" -Map "YB-TZGJ-XMJL-221204.map"
	@echo 'Finished building target: $@'
#	@echo ' '
	$(MAKE) --no-print-directory post-build

YB-TZGJ-XMJL-221204.lst: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjDump'
	@kf32-objdump -S -l --section=.text --section=.data --section=.bss --kf32-arch=kf32r "YB-TZGJ-XMJL-221204.elf"   > "YB-TZGJ-XMJL-221204.lst"
	@echo 'Finished building: $@'
#	@echo ' '

YB-TZGJ-XMJL-221204.s19: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjCopy'
	@kf32-objcopy -O srec "YB-TZGJ-XMJL-221204.elf"   "YB-TZGJ-XMJL-221204.s19"
	@echo 'Finished building: $@'
#	@echo ' '

# 其他目标
clean:
	-$(RM)  $(OBJS) $(EXECUTABLES) $(C_DEPS) YB-TZGJ-XMJL-221204.elf
#	-@echo ' '

post-build:
	-../pack/pack.sh YB-TZGJ-XMJL-221204  D:/ARTStanHome/Desktop/TZGJ-XMJL-221204/YB-TZGJ-XMJL-221204
	-@echo ' '

secondary-outputs:

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
