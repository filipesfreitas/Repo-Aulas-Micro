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
//******************************************************************************
//  MSP-FET430P140 Demo - DMA0, Repeated Block To P1OUT, TACCR2, DCO
//
//  Description: DMA0 is used to transfer a string byte-by-byte as a repeating
//  block to P1OUT. Timer_A operates Continuously clocked at ~800Hz with CCR2IFG
//  triggering DMA0. The effect is P1.0/1.1 toggling at different frequencies.
//  ACLK = n/a, MCLK = SMCLK =  TACLK = default DCO ~ 800k
//  //* MSP430F169 Device Required *//
//
//               MSP430F169
//            -----------------
//        /|\|              XIN|-
//         | |                 |
//         --|RST          XOUT|-
//           |                 |
//           |             P1.0|--> LED
//           |             P1.1|-->
//
//  M. Buccini
//  Texas Instruments Inc.
//  Feb 2005
//  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.21A
//******************************************************************************

#include <msp430.h>

	

const unsigned char testconst[] = { 0x00, 0x03, 0x02, 0x03, 0x00, 0x01 };

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog
  P1DIR |= 0x03;                            // P1.0/1.1 output
  DMACTL0 = DMA0TSEL_1;                     // CCR2IFG trigger
  DMA0SA = (unsigned int)testconst;         // Source block address
  DMA0DA = (unsigned int) &P1OUT;						// Dest single address
  DMA0SZ = sizeof testconst;                // Block size
  DMA0CTL = DMADT_4 + DMASRCINCR_3 + DMASBDB + DMAEN; // Rpt, inc src, enable
  TACTL = TASSEL_2 + MC_2;                  // SMCLK, cont-mode

  __bis_SR_register(LPM0_bits);             // Enter LPM0
}

