:: $L..\PackScript\RunAfterBulid.bat $K @L $L #L H20G20Bootloader
:: %1 == $K keil��װ��Ŀ¼ 
:: %2 == #L keil��������ļ���������Ŀ¼����չ�� 
:: %3 == $L keil��������ļ�Ŀ¼ 
:: $L..\PackScript\RunAfterBulid.bat $K @L $L #L I30Bootloader
@echo off

%1ARM\ARMCC\bin\fromelf.exe --m32 --output  %3\S19\  %2

IF EXIST ..\b40\PackScript ( 
	copy /Y  %3\S19\MAIN_ROM  ..\b40\PackScript\B40Bootloader
	copy /Y  %3\S19\KEYWORD_ROM  ..\b40\PackScript\B40BootloaderKey
)

copy /Y  %3\S19\MAIN_ROM  .\bin\B40Bootloader
copy /Y  %3\S19\KEYWORD_ROM  .\bin\B40BootloaderKey
	
	