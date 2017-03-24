CLS
@echo off
rem This is a small helper script that programs a prebuilt binary for a device using MSP430Flasher
rem
rem Eric Chen, MSP430 Applications, Texas Instruments, Inc.
rem Last modified: 02/28/2014
:input
@echo MSP-EXP430FR5969-LaunchPad Firmware Programmer

set device=MSP430FR5969
set firmware=430BOOST-SHARP96_GrlibExample_FR5969.txt

@echo Programing %firmware% into %device% ......
..\MSP430Flasher\MSP430Flasher.exe -n %device% -w %firmware% -v -g -z [VCC]

pause