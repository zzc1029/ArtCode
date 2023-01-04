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
OBJCOPY_TARGET += \
YB-CZGJ-AK-221201.s19 \

OBJDUMP_LIST += \
YB-CZGJ-AK-221201.lst \


LD_SRCS =G:/workspace32/YB-CZGJ-AK-221201/system/KF32A152MQV.ld

EXECUTABLES	= YB-CZGJ-AK-221201.elf
# 所有目标
all: YB-CZGJ-AK-221201.elf secondary-outputs

# 工具调用
YB-CZGJ-AK-221201.elf: $(OBJS) $(USER_RELS) $(LD_SRCS)
	@echo 'Building target: $@'
#	@echo 'Invoking: C Linker Release'
	@kf32-ld $(OBJS) $(USER_RELS) $(LIBS) -L"C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/ccr1_issue_v0/lib" -L"G:\workspace32\YB-CZGJ-AK-221201" -lIQmath-R1 -lSeriesDIServices -lmath -lio -lstring -lstdlib -lctype -lcrtv1 -T"G:/workspace32/YB-CZGJ-AK-221201/system/KF32A152MQV.ld" --kf32-arch=kf32r --kf32-nodisassemble --kf32-z --with-checksum-fill=0xFF --gc-sections -o  "YB-CZGJ-AK-221201.elf" -Map "YB-CZGJ-AK-221201.map"
	@echo 'Finished building target: $@'
#	@echo ' '
	$(MAKE) --no-print-directory post-build

YB-CZGJ-AK-221201.s19: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjCopy'
	@kf32-objcopy -O srec "YB-CZGJ-AK-221201.elf"   "YB-CZGJ-AK-221201.s19"
	@echo 'Finished building: $@'
#	@echo ' '

YB-CZGJ-AK-221201.lst: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjDump'
	@kf32-objdump -S -l --section=.text --section=.data --section=.bss --kf32-arch=kf32r "YB-CZGJ-AK-221201.elf"   > "YB-CZGJ-AK-221201.lst"
	@echo 'Finished building: $@'
#	@echo ' '

# 其他目标
clean:
	-$(RM)  $(OBJS) $(EXECUTABLES) $(C_DEPS) YB-CZGJ-AK-221201.elf '$(basename $(OBJDUMP_LIST)).lst' '$(basename $(OBJCOPY_TARGET)).hex'   '$(basename $(OBJCOPY_TARGET)).bin'  '$(basename $(OBJCOPY_TARGET)).s19' '$(basename $(OBJCOPY_TARGET)).map'
#	-@echo ' '

post-build:
	-../pack/pack.sh YB-CZGJ-AK-221201  G:/workspace32/YB-CZGJ-AK-221201
	-@echo ' '

secondary-outputs: YB-CZGJ-AK-221201.lst YB-CZGJ-AK-221201.s19

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
