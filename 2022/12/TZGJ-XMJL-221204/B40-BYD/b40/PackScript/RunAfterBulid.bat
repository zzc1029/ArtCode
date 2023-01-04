:: $L..\PackScript\RunAfterBulid.bat $K @L $L #L H20G20Bootloader
:: %1 == $K keil安装主目录 
:: %2 == @L keil编译输出文件名，不包含目录和扩展名 
:: %3 == $L keil编译输出文件目录 
:: %4 == #L keil编译输出文件名，包含目录和扩展名 
:: %5 == H20G20Bootloader  目标板类型：I30Bootloader、H20G20Bootloader B40Bootloader
:: $L..\PackScript\RunAfterBulid.bat $K @L $L #L I30Bootloader
@echo off

%1ARM\ARMCC\bin\fromelf.exe --bin --output  %4.bin  %4
%1ARM\ARMCC\bin\fromelf.exe --m32 --output  %4.mot  %4

if "%5" == "I30Bootloader" (
	copy /Y %4.bin\MAIN_ROM  %3..\bin\%2_RemoteUpdate.bin
	copy /Y %4.mot\MAIN_ROM  %3..\bin\%2_CanUpdate.stm
	copy /Y /b %3..\PackScript\%5.s19 + %3..\bin\%2_CanUpdate.stm + %3..\PackScript\BootloaderPassword.s19  %3..\bin\%2_Factory.s19
	exit
) 

if "%5" == "H20G20Bootloader" (
	copy /Y %4.mot\MAIN_ROM  %3..\bin\%2_CanUpdate.stm
	copy /Y /b %3..\PackScript\%5.s19 + %3..\bin\%2_CanUpdate.stm + %3..\PackScript\BootloaderPassword.s19  %3..\bin\%2_Factory.s19
	exit
)

if "%5" == "B40Bootloader" (
	copy /Y %4.mot\MAIN_ROM  %3..\bin\%2_CanUpdate.stm.b40
	copy /Y /b %3..\PackScript\%5 + %3..\bin\%2_CanUpdate.stm.b40 + %3..\PackScript\B40BootloaderKey  %3..\bin\%2_Factory.s19
	exit
)