CLS
@echo off
rem This is a small helper script that programs a prebuilt binary for a device using MSP430Flasher
rem
rem Eric Chen, MSP430 Applications, Texas Instruments, Inc.
rem Last modified: 09/23/2014
:input
@echo MSP-EXP430FR4133-LaunchPad Firmware Programmer

set device=MSP430FR4133
set firmware=IR_Emitter.txt

@echo Programing %firmware% into %device% ......
..\MSP430Flasher\MSP430Flasher.exe -n %device% -w %firmware% -v -g -z [VCC]

pause