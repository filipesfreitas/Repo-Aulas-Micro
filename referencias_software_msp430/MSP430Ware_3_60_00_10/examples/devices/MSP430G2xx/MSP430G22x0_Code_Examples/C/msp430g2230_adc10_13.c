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
//  MSP430G2230 Demo - ADC10, DTC Sample A5 32x, AVcc, TA0 Trig, DCO
//
//  Description; A5 is sampled in 32x burst using DTC 16 times per second
//  (ACLK/2048) with reference to AVcc. Activity is interrupt driven.
//  Timer_A in upmode uses TA0 toggle to drive ADC10 conversion. Sample burst
//  is automatically triggered by TA0 rising edge every 2048 ACLK cycles.
//  ADC10_ISR will exit from LPM3 mode and return CPU active. Internal ADC10OSC
//  times sample (16x) and conversion (13x). DTC transfers conversion code to
//  RAM 200h - 240h. In the Mainloop P1.2 is toggled. Normal Mode is LPM3.
//  //* An external watch crystal on XIN XOUT is required for ACLK *//
//
//               MSP430G2230
//            -----------------
//        /|\|              XIN|-
//         | |                 | 32kHz
//         --|RST          XOUT|-
//           |                 |
//       >---|P1.5/A5     P1.2 |--> LED
//
//  B. Nisarga
//  Texas Instruments, Inc
//  December 2011
//  Built with CCE Version: 5.1 and IAR Embedded Workbench Version: 5.4
//******************************************************************************

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
  
  /* Initialization Code */
  P1REN = 0x1B;                             // Terminate unavailable Port1 pins (P1.0/1/3/4) properly
                                            // Config as Input with pull-down enabled
  BCSCTL3 |= LFXT1S_2;                      // Select VLO as low freq clock     
  /* End Initialization Code */
  
  ADC10CTL1 = INCH_5 | SHS_2 | CONSEQ_2;    // TA0 trigger
  ADC10CTL0 = ADC10SHT_2 | MSC | ADC10ON | ADC10IE;
  ADC10DTC1 = 0x20;                         // 32 conversions
  P1DIR |= BIT2;                            // Set P1.2 output
  ADC10AE0 |= BIT5;                         // P1.5 ADC10 option select
  TA0CCR0 = 1024-1;                         // PWM Period
  TA0CCTL0 = OUTMOD_4;                      // TA0CCR0 toggle
  TA0CTL = TASSEL_1 | MC_1;                 // ACLK, up mode

  for (;;)
  {
    ADC10CTL0 &= ~ENC;
    while (ADC10CTL1 & BUSY);               // Wait if ADC10 core is active
    ADC10SA = 0x200;                        // Data buffer start
    ADC10CTL0 |= ENC;                       // Sampling and conversion ready
    __bis_SR_register(LPM3_bits + GIE);     // Enter LPM3, enable interrupts
    P1OUT ^= BIT2;                          // Toggle P1.2 using exclusive-OR
  }
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
  __bic_SR_register_on_exit(LPM3_bits);     // Clear LPM3 bits from 0(SR)
}
