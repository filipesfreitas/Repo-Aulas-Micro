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
//   MSP430F21x2 Demo - ADC10, DTC Sample A0 -> TA1, AVcc, DCO
//
//   Description: Use DTC to sample A0 with reference to AVcc and directly
//   transfer code to TACCR1. Timer_A has been configured for 10-bit PWM mode.
//   TACCR1 duty cycle is automatically proportional to ADC10 A0. WDT_ISR used
//   as a period wakeup timer approximately 27ms based on default ~1.2MHz
//   DCO/SMCLK clock source used in this example for the WDT clock source.
//   Timer_A also uses default DCO.
//
//                MSP430F21x2
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//        >---|P2.0/A0      P1.2|--> TACCR1 - 0-1024 PWM
//
//   A. Dannenberg
//   Texas Instruments Inc.
//   December 2007
//   Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.41A
//******************************************************************************
#include <msp430.h>

int main(void)
{
  WDTCTL = WDT_MDLY_32;                     // WDT ~27ms interval timer
  IE1 |= WDTIE;                             // Enable WDT interrupt
  ADC10CTL0 = ADC10SHT_2 + ADC10ON;
  ADC10AE0 |= 0x01;                         // P2.0 ADC option select
  ADC10DTC1 = 0x01;                         // 1 conversion
  P1DIR |= 0x04;                            // P1.2 = output
  P1SEL |= 0x04;                            // P1.2 = TA1 output
  TA0CCR0 = 1024 - 1;                        // PWM Period
  TA0CCTL1 = OUTMOD_7;                       // TACCR1 reset/set 
  TA0CCR1 = 512;                             // TACCR1 PWM Duty Cycle 
  TA0CTL = TASSEL_2 + MC_1;                  // SMCLK, upmode

  while(1)
  {
    __bis_SR_register(LPM0_bits + GIE);     // LPM0, WDT_ISR will force exit
    ADC10SA = (unsigned int)&TA0CCR1;        // Data transfer location
    ADC10CTL0 |= ENC + ADC10SC;             // Start sampling
  }
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = WDT_VECTOR
__interrupt void WDT_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(WDT_VECTOR))) WDT_ISR (void)
#else
#error Compiler not supported!
#endif
{
  __bic_SR_register_on_exit(LPM0_bits);     // Exit LPM0
}

