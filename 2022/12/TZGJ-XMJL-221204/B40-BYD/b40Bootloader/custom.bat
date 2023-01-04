:: $L..\PackScript\RunAfterBulid.bat $K @L $L #L H20G20Bootloader
:: %1 == $K keil安装主目录 
:: %2 == #L keil编译输出文件名，包含目录和扩展名 
:: %3 == $L keil编译输出文件目录 
:: $L..\PackScript\RunAfterBulid.bat $K @L $L #L I30Bootloader
@echo off

%1ARM\ARMCC\bin\fromelf.exe --m32 --output  %3\S19\  %2

IF EXIST ..\b40\PackScript ( 
	copy /Y  %3\S19\MAIN_ROM  ..\b40\PackScript\B40Bootloader
	copy /Y  %3\S19\KEYWORD_ROM  ..\b40\PackScript\B40BootloaderKey
)

copy /Y  %3\S19\MAIN_ROM  .\bin\B40Bootloader
copy /Y  %3\S19\KEYWORD_ROM  .\bin\B40BootloaderKey
	
	