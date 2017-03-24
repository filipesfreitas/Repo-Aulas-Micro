MSP-EXP430FR4133 Software Examples v1.04.00
Texas Instruments, Inc.


********************************************************************************
Welcome to the MSP-EXP430FR4133 LaunchPad!
********************************************************************************

In this package, you will find software examples and source codes that can help
you quickly get started on developing your own project.

The software example projects are located in the 'Source' folder:
 1. OutOfBox_MSP430FR4133                | The out of box demo source code
 2. TIDM-BOOST-IR-REMOTE_Software        | BOOST-IR software examples

In addition, prebuilt TI-TXT images are located in the 'Binary' folder. These
images are ready to be downloaded onto your LaunchPad using a free MSP430
programming interface, such as the included MSP430Flasher. Just run the
"Program <Example>.bat" to download the corresponding project to your LaunchPad!

You can also find various web links in the 'Documentation' folder pointing to
the Tool Page, Quick Start Guide, and User's Guide

For more resources, be sure to visit www.ti.com/tool/msp-exp430fr4133


********************************************************************************
Revision History
********************************************************************************
Ver 1.04.00 - June 22nd, 2015
- Added MacOSX + Linux support for MSP430Flasher

Ver 1.03.00 - March 24th, 2015
- Updated driverlib and USB stack in software examples

Ver 1.02.00 - December 8th, 2014
- Added BOOST-IR software examples
- Fixed incorrect file extension for layout file

Ver 1.01.00 - October 8th, 2014
- Updated BOM

Ver 1.00.00 - October 1st, 2014
- Initial Release


********************************************************************************
Project File Listing
********************************************************************************
|--Documentation                      : Folder containing links to more resources
|--Drivers                            : Folder containing driver files
   |--Emulation                       : Contains link to MSP430 FET USB driver
|--Firmware                           : Folder containing example firmwares
   |--Binary                          : Folder containing TI-TXT image files,
   |                                    MSP430Flasher, and GUI
   |--Source                          : Folder containing software examples
      |--OutOfBox_MSP430FR4133        : Out of box demo source code
      |--TIDM-BOOST-IR-REMOTE_Software: BOOST-IR software examples
         |--IR_Emitter_and_Receiver   : TX & RX example (needs 2 pair LP+BP)
         |--IR_Learning_Mode          : LP+BP learns different IR codes
|--Readme.txt                         : This file
