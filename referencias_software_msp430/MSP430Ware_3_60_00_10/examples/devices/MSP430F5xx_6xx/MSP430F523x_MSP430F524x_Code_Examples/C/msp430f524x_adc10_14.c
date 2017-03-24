/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2013, Texas Instruments Incorporated
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
//  MSP430F524x Demo - ADC10, DMA Sample A1-0 32x, AVcc, Repeat Seq, DCO
//
//  Description: Use DMA to sample A1/A0 repeat sequence 32x(64 total samples)
//  with reference to AVcc.  Software sets ADC10SC to trigger sample burst.
//  In Mainloop MSP430 waits in LPM0 to save power until ADC10 conversion
//  complete, DMA_ISR will force exit from LPM0 in Mainloop.
//  ADC10 internal oscillator times sample period (16x) and conversion (13x).
//  DMA transfers conversion code to ADC_Result.  
//
//               MSP430F524x
//            -----------------
//        /|\|              XIN|-
//         | |                 |
//         --|RST          XOUT|-
//           |                 |
//       >---|P6.1/A1          |
//       >---|P6.0/A0          |
//
//
//   E. Chen
//   Texas Instruments Inc.
//   August 2013
//   Built with IAR Embedded Workbench v5.52 & Code Composer Studio v5.5
//******************************************************************************
#include "msp430.h"

unsigned int ADC_Result[64];                // ADC conversion result array

void main(void)
{
  unsigned int i;
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  
  // Configure ADC10; pulse sample mode, s/w trigger, rpt seq of channels
  ADC10CTL0 = ADC10SHT_2 + ADC10MSC + ADC10ON;  // 16ADCclks, ADC on
  ADC10CTL1 = ADC10SHP + ADC10CONSEQ_3;     // Sampling timer, rpt seq of ch
  ADC10CTL2 = ADC10RES;                     // 10-bit resolution
  ADC10MCTL0 = ADC10INCH_1;                 // AVCC ref, A0, A1(EOS)
  
  // Configure DMA0 (ADC10IFG trigger)
  DMACTL0 = DMA0TSEL_24;                    // ADC10IFG trigger
  __data16_write_addr((unsigned short) &DMA0SA,(unsigned long) &ADC10MEM0);
                                            // Source single address  
  DMA0SZ = 0x02;                            // 2x32 conversions 
  DMA0CTL = DMADT_4 + DMADSTINCR_3 + DMAEN + DMAIE; 
                                            // Rpt, inc dest, byte access, 
                                            // enable int after seq of convs
  while(1)
  {
    for(i=0;i<32;i++)
    {
        __data16_write_addr((unsigned short) &DMA0DA,(unsigned long) &ADC_Result[i*2]);
                                            // Update destination array address         
        while (ADC10CTL1 & ADC10BUSY);      // Wait if ADC10 core is active
        ADC10CTL0 |= ADC10ENC + ADC10SC;    // Sampling and conversion ready
        __bis_SR_register(CPUOFF + GIE);    // LPM0, ADC10_ISR will force exit
    }
    __delay_cycles(5000);               // Delay between sequence convs    
    __no_operation();                   // BREAKPOINT; check ADC_Result    
  }
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=DMA_VECTOR
__interrupt void DMA0_ISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(DMA_VECTOR))) DMA0_ISR (void)
#else
#error Compiler not supported!
#endif
{
  switch(__even_in_range(DMAIV,16))
  {
    case  0: break;                          // No interrupt
    case  2: 
      // sequence of conversions complete
      ADC10CTL0 &= ~ADC10ENC;                // Disable ADC conversion
      __bic_SR_register_on_exit(CPUOFF);     // exit LPM
      break;                                 // DMA0IFG
    case  4: break;                          // DMA1IFG
    case  6: break;                          // DMA2IFG
    case  8: break;                          // Reserved
    case 10: break;                          // Reserved
    case 12: break;                          // Reserved
    case 14: break;                          // Reserved
    case 16: break;                          // Reserved
    default: break; 
  }   
}
