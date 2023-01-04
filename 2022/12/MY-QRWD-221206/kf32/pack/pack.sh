#!/bin/sh
# $1 = project Name
# $2 = project path
kf32-objcopy -O srec "$1.elf"  "$1.s19"

"$2/pack/bincopy.exe" "$1.s19" -Motorola -exclude 0x0000 0x8000 -o "$2/bin/$1.yb" -Motorola
"$2/pack/bincopy.exe" "$1.s19" -Motorola -exclude 0x0000 0x8000 -o "$1_3.hex" -Intel
"$2/pack/bincopy.exe" "$2/pack/KF32_Bootloader.hex" -Intel "$1_3.hex" -Intel -o "$2/bin/$1_ALL.hex" -Intel
"$2/pack/bincopy.exe" "$2/bin/$1_ALL.hex" -Intel -crop 0x00000 0x80000 -o "$1.hex" -Intel
cp -f "$2/pack/KF32_Bootloader.hex" "$2/bin/"
