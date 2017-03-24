---------------------------NFCLink User Experience------------------------------
Ver.: 1.00.00.03 Initial Release
October 2014
Erick Macias
Safety and Security (S2) NFC/RFID Applications
Texas Instruments, Inc.
--------------------------------------------------------------------------------

CONTENTS
         
I.   DESCRIPTION
II.  PROJECT & FILE CONFIGURATION
III. PROJECT IMPORT IN CCS
IV.  NFCLINK LIBRARY PORTING
V.   HISTORY

I. DESCRIPTION
-----------------------------------

This application has an NFC Host and an NFC Controller which communicate 
using the NFC Controller Interface(NCI). The controller runs on the MSp430F5529 
Experimenter's board + TRF7970A NFC transciever- supporting Reader/Writer, Peer 
to Peer, and Card Emulation. The host runs on a GUI for the Windows XP/7. There 
are two modules the MSP430F5529 can use to interface with a PC: UART and USB CDC.
For the UART project, an external UART-to-USB bridge is required(not included 
in the MSP430F5529 Experimenter's board). 


The two CCS projects RW_P2P_CE_1 and RW_P2P_CE_2 are initiated in an idle mode -
the transmitter is disabled, and the presence of an NFC device(i.e. reader) will
not trigger any response from the TRF7970A. The NFC Player running on the PC
is needed to enable/disable the various RFID/NFC modes - Reader/Writer, Peer 
to Peer, and Card Emulation. Each mode on the GUI has a tab designed to configure 
the mode's settings.

For the Reader/Writer mode four different tag types can be selected to be read
in a switching or individually format: 
1. Type 2 (MIFARE Ultralight, Ultralight C, Infineon my-d™ move, my-d™ move NFC)
2. Type 3 (Sony FeliCa Lite (RC-S965), FeliCa Lite-S (RC-S966))
3. Type 4A, Type 4B (ISO14443A/B)
4. Type V (ISO15693)

For the Peer to Peer mode the TRF7970A can be an initiator or a target supporting
two protocols to exchange NFC Data Exchange Format (NDEF):
1. NDEF Push Protocol (NPP)
2. Simple NDEF Exchange Protocol (SNEP)

For the Card Emulation mode the TRF7970A can emulate a ISO14443 Type A / B Tag. 
There are multiple configurations for the NDEF:
1. Empty Tag
2. Business Card (VCard)
3. URL (URI)
4. Text (short record) 
5. Smart Poster
6. Large Text (normal record)


II. PROJECT & FILE CONFIGURATION
-----------------------------------

PROJECT ROOT  - NFCLink_1.00.00.03 
|   README                  <This file>
+---[doc] – User Guide
|	User_Guide.pdf
+---[driverlib]				<UART, GPIO and Timer drivers>
+---[examples]
|   \---[[boards]
|       \---[msp430f5529_exp]		<MSP430F5529 Experimenters Board>
|            \---[allModes]		<Reader/Writer, Peer to Peer, and Card Emulation>
|	        \---[RW_P2P_CE_1]	<USB (CDC) interface to the host>
|	        \---[RW_P2P_CE_2]	<UART module interface to the host>
|       \---[msp430f5529_lp]		<MSP430F5529 Launchpad Board>		
|            \---[allModes]		<Reader/Writer, Peer to Peer, and Card Emulation>
|	         \---[RW_P2P_CE_1]	<USB (CDC) interface to the host>
|	         \---[RW_P2P_CE_2]	<UART module interface to the host>
+---[nfclinklib]		<NFC source + .lib files used on the CCS projects>
|   |---[allModesLib]
|	|   nfclinklib.lib
|   \---[Source]		<TRF7970A drivers, and NFC Controller Header Files>
+---[usblib430]			<USB drivers>
\---[utils] 			<NFC Player installer>  
            
Legend: [Directory]     
           |---filename 

           
III. PROJECT IMPORT IN CCS 
---------------------------
  1. Project Import in CCS  
       a. Open CCS.
       b. Select a new project workspace outside of the project folder*           
       c. Select Project-->Import Existing Project 
       d. Browse to the [PROJECT_ROOT]\CCS folder
       e. Select Finish 
       
       *Ideally, workspace should be in completely independent folder, not
       containing or contained by the project/package folder.
       
       !Note: For CCS, while project root is in the outer directory, the CCS 
       project files are located inside CCS. To enable the portability of
       the project, the file macros.ini is created to define the root. 
       Additionally, all project code files (*.c, *.h) are added as linked 
       resources with their relative path to the project root.
       
       
IV. NFCLINK LIBRARY PORTING
---------------------------
There are three layers that need to be modified when porting to other MSP430s:
1. Host Interface – there are three functions that must be modified to 
  interface with the host:
     a. Host_Interface::Init() – Initialization for the module and RX ISR. 	   
     b. Host_Interface::Write() – Function that transmits to the host. 
     c. The RX ISR for the host interface – Store incoming bytes into 
	Host_Interface::recbuf.  

2. MSP430 Hardware  –  there are five functions that must be modified: 
     a. HW_Config::Init() – Disables the WDT. Sets up the Frequency of the MCLK - 25MHz.
     b. HW_Config::MCU_Reset() – Reset the MSP430 by setting the BOR flag.
     c. HWTimer::Init() – Initialize Timer A using reference of ACLK (32.768kHz) 
	running continuously.
     d. HWTimer::ticks32() – Returns and stores the value of the timer’s counter 
	into timervalue.f[0]. Furthermore TICKS_PER_MSEC (inside MSP430_hardware.h)
	needs to be updated based on the CLK being used as reference. (i.e. For a
	2MHz Clock, TICKS_PER_MSEC = Ref. CLK / 1000 =  2 x 10^6 / 1000 = 2000)
     e. GPIO::Init() – Initializes the External Field LED (P1.1), External Field 
	debug pin (P4.1), Any Mode LED (P1.3), RW/Initiator Mode LED (1.0), P2P LED 
	(P8.1), CE (8.2), Serial TX debug pin(4.3) and Serial RX debug pin (4.2). 


3. TRF7970A Interface - there are five functions that must be modified:
     a. TRF797x_setup() – Initializes the interface to the TRF7970A (SPI / Parallel).
	Initializes the TRF7970 EN pin, then  sets up the IRQ pin with a rising edge 
	interrupt. Afterwards, it writes to the TRF7970 to ensure it has been initialized 
	properly. 
     b. RFSPI::init() – Initializes the SPI module as 3 pin SPI, 8 bit Master, MSB, Clock 
	Pol/ Phase = 0, SPI Clock ~ 4MHz using the SMCLK = 25MHz as reference. 
	The Slave Select will be manually set – ensure that SLAVESELECT _OUTPUT is using 
	the correct GPIO.
     c. TRF797x_IRQ_ISR() – Ensure that the interrupt service routine for the IRQ pin 
	(rising edge interrupt) is setup correctly. 
     d. RFSPI::waitBus() – Waits for the SPI module to be idle. 
     e. RFSPI::transfer() – Writes to the SPI TX register, and returns the value of the 
	SPI RX register. 

V. HISTORY 
-----------------------------------
Ver. 1.00.00.03
- Fixed following issues:
    1.The TRF7970A Software solution did not reply in 86 uS to the SEN_REQ sent by the 
      polling device, this time has was decreased to 92uS.
    2.The P2P target device now handles both 106kbps and 212kbps incoming polling 
      commands.
    3.The NFC controller was not replying to the SENSF_REQ within the correct timeslot.
      The controller now always replies in Slot 0.
    4.The NFC controller sends valid NFCID2 in the ATR_RES when target mode enabled.
    5.The P2P target now supports handling PSL_REQ (to 212kbps and 424kbps). 
    6.The P2P initiator chooses P2P when communicating with target devices that support 
      NFC-DEP and ISO-DEP when starting the P2P communication with NFC-A (106kbps). 
    7.The TRF7970A driver was improved to make the NFC-A P2P communication more robust.
- Added the following features:
    1.The GT was increased for NFC-B to 15mS. (To power up the RF430 Temperature TI design)
    2.Support Card Emulation NFC-F.
    3.Support multiple card emulation modes at the same time (NFC-A, NFC-B, and NFC-F).
    4.Allow for the NDEF message to be modified in card emulation mode.
    5.Added support for the MSP430F5529 Launchpad.
Ver. 1.00.00.02
- Modified the RFID::baudrate_air() function to switch the over the air baudrate correctly. 
Ver. 1.0.0.1
-Modified the file structure of the NCI folder.
Ver. 1.0.0.0
-Initial firmware Beta release supporting all NFC modes - Reader/Writer,Peer to 
Peer and Card Emulation. 