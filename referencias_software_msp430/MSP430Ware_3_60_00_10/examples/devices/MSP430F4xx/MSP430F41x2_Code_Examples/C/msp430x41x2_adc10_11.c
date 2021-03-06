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
//  MSP430F41x2 Demo - ADC10, Sample A0, 1.5V, TA1 Trig, Set P5.1 if > 0.5V
//
//  Description: A0 is sampled 16/second (ACLK/2048) with reference to 1.5V.
//  Timer_A is run in upmode and TA1 is used to automatically trigger
//  ADC10 conversion, TA0 defines the period. Internal oscillator times sample
//  (16x) and conversion (13x). Inside ADC10_ISR if A0 > 0.5Vcc, P5.1 is set,
//  else reset. Normal mode is LPM3.
//  //* An external watch crystal on XIN XOUT is required for ACLK *//
//
//               MSP430F21x2
//            -----------------
//        /|\|              XIN|-
//         | |                 | 32kHz
//         --|RST          XOUT|-
//           |                 |
//       >---|P7.4/A0     P5.1 |--> LED
//
//  P. Thanigai
//  Texas Instruments Inc.
//  January 2009
//  Built with CCE Version: 3.1 and IAR Embedded Workbench Version: 4.11
//******************************************************************************
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  ADC10CTL1 = SHS_1 + CONSEQ_2;             // TA1 trigger sample start
  ADC10CTL0 = SREF_1 + ADC10SHT_2 + REFON + ADC10ON + ADC10IE;
  TACCR0 = 30;                              // Delay to allow Ref to settle
  TACCTL0 |= CCIE;                          // Compare-mode interrupt
  TACTL = TASSEL_2 + MC_1;                  // TACLK = SMCLK, Up mode
  __bis_SR_register(CPUOFF + GIE);          // LPM0, TA0_ISR will force exit
  TACCTL0 &= ~CCIE;                         // Disable timer Interrupt
  ADC10CTL0 |= ENC;                         // ADC10 Enable
  ADC10AE0 |= 0x01;                         // P7.4 ADC10 option select
  P5DIR |= 0x02;                            // Set P5.1 output
  TACCR0 = 2048-1;                          // PWM Period
  TACCTL1 = OUTMOD_3;                       // TACCR1 set/reset
  TACCR1 = 2047;                            // TACCR1 PWM Duty Cycle
  TACTL = TASSEL_1 + MC_1;                  // ACLK, up mode

  __bis_SR_register(LPM3_bits + GIE);       // Enter LPM3 w/ interrupts
}

// ADC10 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC10_VECTOR))) ADC10_ISR (void)
#else
#error Compiler not supported!
#endif
{
  if (ADC10MEM < 0x155)                     // ADC10MEM = A0 > 0.5V?
    P5OUT &= ~0x02;                         // Clear P5.1 LED off
  else
    P5OUT |= 0x02;                          // Set P5.1 LED on
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TA0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) TA0_ISR (void)
#else
#error Compiler not supported!
#endif
{
  TACTL = 0;                                // Clear Timer_A control registers
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
