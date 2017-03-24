//*****************************************************************************
//  MSP430AFE25x Demo - SD24, Continuous Conversion on a Single Channel
//
//  Description: This program uses the SD24 module to perform continuous
//  conversions on a single channel. A SD24 interrupt occurs whenever a
//  conversion has completed. Test by applying a voltage to channel 2
//  (A2.0+, A2.0-) and setting a breakpoint at the line indicated below.
//  Run program until it reaches the breakpoint, then use the debugger's
//  watch window to view the conversion results. Conversion results are
//  stored in the array, "results".
//  ACLK = n/a, MCLK = SMCLK = DCO =  ~ 1.1MHz
//  //* For Minimum Vcc required for SD24 module - see datasheet        *//
//  //* 100nF cap btw Vref and AVss is recommended when using 1.2V ref *//
//
//                MSP430AFE25x
//             -----------------
//         /|\|              XIN|-
//          | |                 | 
//          --|RST          XOUT|-
//            |                 |
//    Vin+ -->|A2.0+            |
//    Vin- -->|A2.0-            |
//            |                 |
//            |            VREF |---+
//            |                 |   |
//            |                 |  -+- 100nF
//            |                 |  -+-
//            |                 |   |
//            |            AVss |---+
//            |                 |
//
//  K. Naveen
//  Texas Instruments, Inc
//  March 2011
//  Built with IAR Embedded Workbench Version: 5.20.1
//*****************************************************************************
#include <msp430.h>

#define   Num_of_Results   8

/* Arrays to store SD24 conversion results */
/* NOTE: arrays need to be global to       */
/*       prevent removal by compiler       */
unsigned int results[Num_of_Results];

void main(void)
{
  volatile unsigned int i;                  // Use volatile to prevent removal
                                            // by compiler optimization

  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  SD24CTL = SD24REFON + SD24SSEL0;          // 1.2V ref, SMCLK
  SD24INCTL2 |= SD24INTDLY0;                // Interrupt on 3rd sample
  SD24CCTL2 |= SD24IE ;                     // Enable interrupt
  for (i = 0; i < 0x3600; i++);             // Delay for 1.2V ref startup
  
  SD24CCTL2 |= SD24SC;                      // Set bit to start conversion
  __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupts

}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=SD24_VECTOR
__interrupt void SD24AISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(SD24_VECTOR))) SD24AISR (void)
#else
#error Compiler not supported!
#endif
{
  static unsigned int index = 0;

  switch (SD24IV)
  {
    case 2:                                   // SD24MEM Overflow
      break;
    case 4:                                   // SD24MEM0 IFG
      break;
    case 6:                                   // SD24MEM1 IFG
      break;
    case 8:                                   // SD24MEM2 IFG
      results[index] = SD24MEM2;              // Save CH2 results (clears IFG)
      if (++index == Num_of_Results)
      {
        index = 0;                            // SET BREAKPOINT HERE
      }
      break;
  }
}
