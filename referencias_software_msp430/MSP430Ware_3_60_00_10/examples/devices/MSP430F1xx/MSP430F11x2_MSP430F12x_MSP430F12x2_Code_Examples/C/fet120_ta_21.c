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
//*******************************************************************************
//  MSP-FET430P120 Demo - Timer_A, PWM TA1-2, Up/Down Mode, HF XTAL ACLK
//
//  Description: This program generates two PWM outputs on P1.2,3 using
//  Timer_A configured for up/down mode.  The value in CCR0, 128, defines the
//  PWM period/2 and the values in CCR1 and CCR2 the PWM duty cycles. Using HF
//  XTAL ACLK as TACLK, the timer period is HF XTAL/256 with a 75% duty cycle
//  on P1.2 and 25% on P1.3.
//  ACLK = MCLK = TACLK = HF XTAL
//  //* HF XTAL REQUIRED AND NOT INSTALLED ON FET *//
//  //* Min Vcc required varies with MCLK frequency - refer to datasheet *//	
//
//               MSP430F123(2)
//            -----------------
//        /|\|              XIN|-
//         | |                 | HF XTAL (455k - 8MHz)
//         --|RST          XOUT|-
//           |                 |
//           |         P1.2/TA1|--> CCR1 - 75% PWM
//           |         P1.3/TA2|--> CCR2 - 25% PWM
//
//  M. Buccini
//  Texas Instruments Inc.
//  Feb 2005
//  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.21A
//******************************************************************************

#include <msp430.h>

int main(void)
{
  volatile unsigned int i;
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  BCSCTL1 |= XTS;                           // ACLK= LFXT1= HF XTAL

  do
  {
  IFG1 &= ~OFIFG;                           // Clear OSCFault flag
  for (i = 0xFF; i > 0; i--);               // Time for flag to set
  }
  while ((IFG1 & OFIFG));                   // OSCFault flag still set?

  BCSCTL2 |= SELM_3;                        // MCLK= LFXT1 (safe)
  P1DIR |= 0x0C;                            // P1.2 and P1.3 output
  P1SEL |= 0x0C;                            // P1.2 and P1.3 TA1/2 otions
  CCR0 = 128;                               // PWM Period/2
  CCTL1 = OUTMOD_6;  			    // CCR1 toggle/set
  CCR1 = 32;                                // CCR1 PWM duty cycle
  CCTL2 = OUTMOD_6;  			    // CCR2 toggle/set
  CCR2 = 96;                                // CCR2 PWM duty cycle
  TACTL = TASSEL_1 + MC_3;                  // ACLK, up-down mode

  __bis_SR_register(LPM0_bits);             // Enter LPM0
}

