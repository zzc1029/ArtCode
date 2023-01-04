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
all: App.hex

# 工具调用
App.hex: $(OBJS) $(USER_RELS)
	@echo 'Building target: $@'
#	@echo 'Invoking: C Linker Debug'
	@kf32-ld $(OBJS) $(USER_RELS) $(LIBS) -L"C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/ccr1_issue_v0/lib" -L"H:\workspace32\App" -lIQmath-R1 -lSeriesDIServices -lmath -lio -lstring -lstdlib -lctype -lcrtv1 -T"H:/workspace32/App/system/KF32A152MQV.ld" --kf32-autoihex --kf32-arch=kf32r --gc-sections -o  "App.elf" -Map "App.map"
	@echo 'Finished building target: $@'
#	@echo ' '
	$(MAKE) --no-print-directory post-build

# 其他目标
clean:
	-$(RM) $(OBJS)$(EXECUTABLES)$(C_DEPS) App.hex
#	-@echo ' '

post-build:
	-rm  -r  "H:/workspace32/App/bin" & mkdir "H:/workspace32/App/bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
