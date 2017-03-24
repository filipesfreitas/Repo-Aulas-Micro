------------Capacitive Touch Library and Getting Started Guide------------------
July 2014
Texas Instruments, Inc.
--------------------------------------------------------------------------------

CONTENTS
         
I. Library
II. Code_Examples
III. Documentation
IV. Example_Projects

I. Library
-----------------------------------
The following files are found in the Library directory:

    CTS_HAL.c
    CTS_HAL.h
    CTS_Layer.c
    CTS_Layer.h

           
II. Code_Examples
-----------------------------------  
The following example directories incude a main application file and configuration
files structure.c/.h. These files are used with the files found in the source 
directory. The element definition found in the configuration file structure.c uses a 
designated initializer list. This allows members to be initialized in any order and 
also enhances the readability of the element being initialized.  This feature 
requires the GCC language extension found in Code Composer Studio (CCS).  
C99 is the default dialect found in IAR and therefore the default settings can be 
used.

	fRO_COMPAp_SW_TA0
	fRO_COMPAp_TA0_SW 
	fRO_COMPB_TA1_TA0
	fRO_CSIO_TA0_SW
	fRO_CSIO_TA0_TA1
	fRO_CSIO_TA2_TA3
	fRO_PINOSC_TA0_SW
	fRO_PINOSC_TA0_TA1
	fRO_PINOSC_TA1_TA0
	fRO_PINOSC_TA1_TB0
	RC_PAIR_TA0
	RO_COMPAp_TA0_WDTp
	RO_COMPB_TA1_TA0
	RO_COMPB_TA1_WDTA
	RO_COMPB_TB0_WDTA
	RO_CSIO_TA0_RTC
	RO_CSIO_TA0_TA1
	RO_CSIO_TA0_WDTA
	RO_CSIO_TA2_TA3
	RO_CSIO_TA2_WDTA
	RO_PINOSC_TA0
	RO_PINOSC_TA0_TA1
	RO_PINOSC_TA0_WDTp
	RO_PINOSC_TA1_WDTp
	RO_PINOSC_TA1_TB0


III. Documentation
-----------------------------------
Doxygen for the files found in the Library directory.

IV. Example_Projects
-----------------------------------
Eight projects for both IAR and CCS.  The C source code is found in the Source sub-directory.  Both the CCS and IAR projects link to the Library directory.

