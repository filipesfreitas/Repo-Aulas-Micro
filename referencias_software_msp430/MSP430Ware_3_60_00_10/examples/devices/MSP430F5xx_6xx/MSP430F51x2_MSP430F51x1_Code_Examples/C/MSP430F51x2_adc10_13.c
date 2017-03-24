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
//  MSP430F51x2 Demo - ADC10, DMA Sample A1 32x, 2.5V Ref, TD0 Trig, DCO
//
//  Description; A1 is sampled 32x burst 16 times per second (ACLK/256) with
//  Vref = internal 2.5V. Activity is interrupt driven. Timer_A in upmode uses
//  TD0 toggle to drive ADC10 conversion. ADC conversions are automatically 
//  triggered by TD0 rising edge every 2048 ACLK cycles. ADC10_ISR will exit 
//  from LPM3 mode and return CPU active. Internal ADC10OSC times sample (16x)
//  and conversion (13x). DMA transfers conv results to ADC_Result variable. 
//  //* An external watch crystal on XIN XOUT is required for ACLK *//
//
//               MSP430F51x2
//            -----------------
//        /|\|              XIN|-
//         | |                 | 32kHz
//         --|RST          XOUT|-
//           |                 |
//       >---|P1.1/A1          | 
//           |            P1.6 |--> TD0.0 (ADC trigger signal)
//
//  F. Chen
//  Texas Instruments Inc.
//  Nov. 2012
//  Built with CCS v5.2.1 and IAR Embedded Workbench Version: 5.51.1
//******************************************************************************
#include <msp430.h>

unsigned int ADC_Result[32];

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  
  PMAPPWD = 0x02D52;      // Enable Write-access to modify port mapping registers
  PMAPCTL = PMAPRECFG;    // Allow reconfiguration during runtime
  P1MAP1 |= PM_ANALOG;    // Modify all PxMAPy registers. 
  PMAPPWD = 0;            // Disable Write-Access to modify port mapping registers by writing incorrect key
  P1SEL|=BIT1;            // setting the port mapping register PxMAPy to PM_ANALOG together with PxSEL.y=1 when applying analog signals.

  // Configure ADC10 - pulse sample mode; TD0 trigger; rpt single channel
  ADC10CTL0 = ADC10SHT_2 + ADC10ON;         // 16ADCclks, ADC10 on
  ADC10CTL1 = ADC10SHP + ADC10SHS_2 + ADC10CONSEQ_2; // sampling timer, TimerD0 
                                            // trigger, rpt single channel
  ADC10CTL2 = ADC10RES;                     // 10-bits resolution
  ADC10MCTL0 = ADC10SREF_1 + ADC10INCH_1;   // Vref+, A1

 // Configure internal reference
  while(REFCTL0 & REFGENBUSY);              // If ref generator busy, WAIT
  REFCTL0 |= REFVSEL_2+REFON;               // Select internal ref = 2.5V 
                                            // Internal Reference ON   
  __delay_cycles(75);                       // Delay (~75us) for Ref to settle
  
  // Configure DMA (ADC10IFG0 trigger)
  DMACTL0 = DMA0TSEL_24;                    // ADC10IFG trigger
  __data16_write_addr((unsigned short) &DMA0SA,(unsigned long) &ADC10MEM0);
                                            // Source single address  
  __data16_write_addr((unsigned short) &DMA0DA,(unsigned long) &ADC_Result[0]);
                                            // Destination array address  
  DMA0SZ = 32;                              // 32 conversions 
  DMA0CTL = DMADT_4 + DMADSTINCR_3 + DMAEN + DMAIE; // Rpt, inc dest, word access, 
                                            // enable interrupt after 32 conversions 
  // Configure Timer Trigger TD0.0
  TD0CCR0 = 256-1;                          // TD0.0 Period
  TD0CCTL0 = OUTMOD_4;                      // TDCCR0 toggle
  P1SEL |= BIT6;                            // TD0.0 option select
  P1DIR |= BIT6;                            // P1.6 output 
  TD0CTL0 = TDSSEL_1 + MC_1 + TDCLR;        // ACLK, up mode  
  
  while(1)
  {
    while (ADC10CTL1 & BUSY);               // Wait if ADC10 core is active
    ADC10CTL0 |= ADC10ENC;                  // Sampling and conversion ready
    __bis_SR_register(CPUOFF + GIE);        // Enter LPM3, enable interrupts
    
    __delay_cycles(5000);                   // Delay between conversions
    __no_operation();                       // BREAKPOINT to check ADC_Result    
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
    case  2:                                 // DMA0IFG
      // 32 conversions complete
      __bic_SR_register_on_exit(CPUOFF);     // exit LPM
      break;                                 
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
