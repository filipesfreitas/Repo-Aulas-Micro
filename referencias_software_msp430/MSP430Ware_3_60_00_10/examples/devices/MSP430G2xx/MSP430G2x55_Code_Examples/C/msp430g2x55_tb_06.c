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
//   MSP430G2x55 Demo - Timer_B, Toggle P1.0, TBCCR1 Cont. Mode ISR, DCO SMCLK
//
//   Description: Toggle P1.0 using software and TB_1 ISR. Toggles every
//   50000 SMCLK cycles. SMCLK provides clock source for TBCLK.
//   During the TB_1 ISR, P1.0 is toggled and 50000 clock cycles are added to
//   TBCCR1. TB_1 ISR is triggered every 50000 cycles. CPU is normally off and
//   used only during TB_ISR. Proper use of the TBIV interrupt vector generator
//   is demonstrated.
//   ACLK = n/a, MCLK = SMCLK = TBCLK = default DCO ~1.2MHz
//
//                MSP430G2x55
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//   Lixin Chen
//   Texas Instruments Inc.
//   March 2013
//   Built with CCS Version: 5.3.0 and IAR Embedded Workbench Version: 5.51
//******************************************************************************
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // P1.0 output
  TBCCTL1 = CCIE;                           // TBCCR1 interrupt enabled
  TBCCR1 = 50000;
  TBCTL = TBSSEL_2 | MC_2;                  // SMCLK, contmode

  __bis_SR_register(CPUOFF | GIE);          // CPU off, interrupts enabled
}

// Timer_B3 Interrupt Vector (TBIV) handler
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMERB1_VECTOR
__interrupt void Timer_B(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMERB1_VECTOR))) Timer_B (void)
#else
#error Compiler not supported!
#endif
{
  switch (TBIV)        // Efficient switch-implementation
  {
    case  2:                                // TBCCR1
      TBCCR1 += 50000;                      // Offset until next interrupt
      P1OUT ^= 0x01;                        // Toggle P1.0
      break;
    case  4: break;                         // TBCCR2 not used
    case 14: break;                         // Overflow not used
  }
}
