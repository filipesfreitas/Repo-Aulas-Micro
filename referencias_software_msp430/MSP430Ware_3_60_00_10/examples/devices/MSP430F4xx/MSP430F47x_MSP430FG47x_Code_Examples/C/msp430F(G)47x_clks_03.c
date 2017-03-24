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
//  MSP430F(G)47x Demo - FLL+, Output 32kHz XTAL + HF XTAL + Internal DCO
//
//  Description: This program demonstrates using an external 32kHz crystal to
//  supply the internal ACLK, and using a high speed crystal or resonator to
//  supply SMCLK. The MLCK for the CPU is supplied by the DCO. The 32kHz
//  crystal connects to pins Xin and Xout. The high frequency crystal or
//  resonator connects to pins XT2in and XT2out. The DCO clock is generated
//  internally and calibrated by the FLL+ from the 32kHz crystal. The
//  resulting ACLK is brought out pin P1.5, SMCLK is brought out on P1.4,
//  and MCLK is brought out on pin P1.1.
//  ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
//  //* An external watch crystal between XIN & XOUT is required for ACLK *//
//  //* External matching capacitors must be added for the high *//
//  //* speed crystal or resonator as required.                 *//
//
//                MSP430F(G)47x
//             -----------------
//        /|\ |              XIN|-
//         |  |                 | 32kHz
//         ---|RST          XOUT|-
//            |                 |
//            |                 |
//            |            XT2IN|-
//            |                 | HF XTAL or Resonator (add capacitors)
//            |           XT2OUT|-
//            |                 |
//            |                 |
//            |        P1.5/ACLK|--> ACLK = 32768 Hz
//            |                 |
//            |       P1.4/SMCLK|--> SMCLK = High Freq XTAL or Resonator
//            |                 |
//            |        P1.1/MCLK|--> MCLK = 1048576 Hz (Default DCO)
//            |                 |
//            |                 |
//
//  M.Seamen/ P. Thanigai
//  Texas Instruments Inc.
//  September 2008
//  Built with IAR Embedded Workbench V4.11A and CCE V3.2
//*****************************************************************************
#include <msp430.h>

int main(void)
{
  volatile unsigned int i;                  // Use volatile to prevent removal
                                            // by compiler optimization

  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  FLL_CTL0 |= XCAP14PF;                     // Configure load caps
  for (i = 0; i < 10000; i++);              // Delay for 32 kHz crystal to
                                            // stabilize
  do
  {
    IFG1 &= ~OFIFG;                         // Clear osc fault flag
    for (i = 0; i < 1000; i++);             // Delay for osc to stabilize
  } while(IFG1 & OFIFG);                    // Check to see if osc flag is set

  FLL_CTL1 = SELS;                          // XT2 on, SMCLK = XT2CLK

  P1DIR = 0x32;                             // Set P1.5,4,1 as outputs
  P1SEL = 0x32;                             // Select P1.5,4,1 as clk option
  P1SEL2 |= 0x02;
  while(1);                                 // Loop in place
}