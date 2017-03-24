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
//  MSP430F51x2 Demo - ADC10, Window Comparator, 2.5V Timer trigger, DCO
//
//  Description; A1 is sampled in every 0.5s using the TA0.0 trigger in single 
//  ch/conversion mode. Window comparator is used to generate interrupts to
//  indicate when the input voltage goes above the High_Threshold or below the 
//  Low_Threshold or is inbetween the high and low thresholds. TimerD0 is used 
//  as an interval timer used to control the LED at P1.0 to toggle slow/fast 
//  or turn off according to the ADC10 Hi/Lo/IN interupts.
//  ADC10 is configured in pulse sample mode and is triggered by the TA0.0
//
//               MSP430F51x2
//            -----------------
//        /|\|              XIN|-
//         | |                 | 32kHz
//         --|RST          XOUT|-
//           |                 |
//       >---|P1.1/A1     P1.0 |--> LED 
//
//  F. Chen
//  Texas Instruments Inc.
//  Nov. 2012
//  Built with CCS v5.2.1 and IAR Embedded Workbench Version: 5.51.1
//******************************************************************************
#include <msp430.h>

#define High_Threshold 818
#define Low_Threshold 409

unsigned int SlowToggle_Period = 20000-1;
unsigned int FastToggle_Period = 1000-1;

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                  // Stop WDT
  
  PMAPPWD = 0x02D52;      // Enable Write-access to modify port mapping registers
  PMAPCTL = PMAPRECFG;    // Allow reconfiguration during runtime
  P1MAP1 |= PM_ANALOG;    // Modify all PxMAPy registers.  
  PMAPPWD = 0;            // Disable Write-Access to modify port mapping registers by writing incorrect key
  P1SEL|=BIT1;            // setting the port mapping register PxMAPy to PM_ANALOG together with PxSEL.y=1 when applying analog signals.
  
  // Configure ADC10; 
  ADC10CTL0 = ADC10SHT_2 + ADC10ON;         // ADC10ON
  ADC10CTL1 = ADC10SHP + ADC10SHS_1 + ADC10CONSEQ_2;  // rpt single ch; TA0 trig sample start
  ADC10CTL2 = ADC10RES;                     // 10-bit conversion results
  ADC10MCTL0 = ADC10INCH_1 + ADC10SREF_1;   // Vref+, A1
  ADC10HI = High_Threshold;                 // Window Comparator Hi-threshold 
  ADC10LO = Low_Threshold;                  // Window Comparator Lo-threshold
  
 // Configure internal reference
  while(REFCTL0 & REFGENBUSY);              // If ref generator busy, WAIT
  REFCTL0 |= REFVSEL_2+REFON;               // Select internal ref = 2.5V 
                                            // Internal Reference ON   
  __delay_cycles(75);                       // Delay (~75us) for Ref to settle

 
  P1DIR |= BIT0;                            // Set P1.0 output direction
  P1OUT &= ~BIT0;                           // Clear P1.0
  
  // Configure TD0 period-timer
  TD0CCTL0 = CCIE;                          // CCR0 interrupt enabled
  TD0CTL0 = TDSSEL_1 + TDCLR;               // ACLK, clear TAR
  
  // Configure ADC10 timer trigger TA0.0
  TA0CCR0 = 16384-1;                        // PWM Period
  TA0CCTL0 = OUTMOD_4;                      // TA0CCR0 toggle
  TA0CTL = TASSEL_1 + MC_1 + TACLR;         // ACLK, up mode
  
  ADC10IE |= ADC10HIIE + ADC10LOIE + ADC10INIE; // Interrupt enable   
  ADC10CTL0 |= ADC10ENC;                    // Enable conversion
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
  switch(__even_in_range(ADC10IV,12))
  {
    case  0: break;                         // No interrupt
    case  2: break;                         // conversion result overflow
    case  4: break;                         // conversion time overflow
    case  6:                                // ADC10HI
      ADC10IFG &= ~ADC10HIIFG;              // Clear interrupt flag
      TD0CTL0 &= ~MC_1;                     // Turn off Timer                      
      TD0CCR0 = FastToggle_Period;          // Set Timer Period for slow LED toggle
      TD0CTL0 |= MC_1;      
      break;                          

    case  8:                                // ADC10LO
      ADC10IFG &= ~ADC10LOIFG;              // Clear interrupt flag   
      TD0CTL0 &= ~MC_1;                     // Turn off Timer
      P1OUT &= ~BIT0;       
      break;                          
    
    case 10:                                // ADC10IN
      ADC10IFG &= ~ADC10INIFG;              // Clear interrupt flag
      TD0CTL0 &= ~MC_1;                     // Turn off Timer                      
      TD0CCR0 = SlowToggle_Period;          // Set Timer Period for slow LED toggle
      TD0CTL0 |= MC_1;        
      break;                          
    case 12: break;                          // ADC10IFG0                    
    default: break; 
  }   
}

// Timer1 A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_D0_VECTOR
__interrupt void TIMER0_D0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_D0_VECTOR))) TIMER0_D0_ISR (void)
#else
#error Compiler not supported!
#endif
{
  P1OUT ^= BIT0;                            // Toggle LED P1.0
}
