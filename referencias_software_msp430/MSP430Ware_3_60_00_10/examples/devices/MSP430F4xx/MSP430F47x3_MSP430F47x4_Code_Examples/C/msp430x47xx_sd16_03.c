/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************
 * 
 *                       MSP430 CODE EXAMPLE DISCLAIMER
 *
 * MSP430 code examples are self-contained low-level programs that typically
 * demonstrate a single peripheral function or device feature in a highly
 * concise manner. For this the code may rely on the device's power-on default
 * register values and settings such as the clock configuration and care must
 * be taken when combining code from several examples to avoid potential side
 * effects. Also see www.ti.com/grace for a GUI- and www.ti.com/msp430ware
 * for an API functional library-approach to peripheral configuration.
 *
 * --/COPYRIGHT--*/
//*****************************************************************************
//  MSP430x47xx Demo - SD16, Continuous Conversion on a Single Channel
//
//  Description: This program uses the SD16 module to perform continuous
//  conversions on a single channel. A SD16 interrupt occurs whenever a
//  conversion has completed. Test by applying a voltage to channel 2
//  (A2.0+, A2.0-) and setting a breakpoint at the line indicated below.
//  Run program until it reaches the breakpoint, then use the debugger's
//  watch window to view the conversion results. Conversion results are
//  stored in the array, "results".
//  ACLK = LFXT1 = 32768 Hz, MCLK = SMCLK = DCO = 32 x ACLK = 1048576 Hz
//  //* An external watch crystal on XIN XOUT is required for ACLK     *//	
//  //* For Minimum Vcc required for SD16 module - see datasheet        *//
//  //* 100nF cap btw Vref and AVss is recommended when using 1.2V ref *//
//
//                MSP430x47xx
//             -----------------
//         /|\|              XIN|-
//          | |                 | 32kHz
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
//  P. Thanigai / K.Venkat
//  Texas Instruments Inc.
//  November 2007
//  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.42A
//*****************************************************************************
#include <msp430.h>
#define   Num_of_Results   8

/* Arrays to store SD16 conversion results */
/* NOTE: arrays need to be global to       */
/*       prevent removal by compiler       */
unsigned int results[Num_of_Results];

int main(void)
{
  volatile unsigned int i;                  // Use volatile to prevent removal
                                            // by compiler optimization

  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  FLL_CTL0 |= XCAP11PF;                     // Configure load caps
  for (i = 0; i < 10000; i++);              // Delay for 32 kHz crystal to
                                            // stabilize

  SD16CTL = SD16REFON+SD16SSEL0;            // 1.2V ref, SMCLK
  SD16INCTL2 |= SD16INTDLY0;                // Interrupt on 3rd sample
  SD16CCTL2 |= SD16IE ;                     // Enable interrupt
  for (i = 0; i < 0x3600; i++);             // Delay for 1.2V ref startup
  
  SD16CCTL2 |= SD16SC;                      // Set bit to start conversion
  __bis_SR_register(LPM0_bits + GIE);          // Enter LPM0 w/ interrupts

}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=SD16A_VECTOR
__interrupt void SD16AISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(SD16A_VECTOR))) SD16AISR (void)
#else
#error Compiler not supported!
#endif
{
  static unsigned int index = 0;

  switch (SD16IV)
  {
    case 2:                                   // SD16MEM Overflow
      break;
    case 4:                                   // SD16MEM0 IFG
      break;
    case 6:                                   // SD16MEM1 IFG
      break;
    case 8:                                   // SD16MEM2 IFG
      results[index] = SD16MEM2;              // Save CH2 results (clears IFG)
      if (++index == Num_of_Results)
      {
        index = 0;                            // SET BREAKPOINT HERE
      }
      break;
  }
}


