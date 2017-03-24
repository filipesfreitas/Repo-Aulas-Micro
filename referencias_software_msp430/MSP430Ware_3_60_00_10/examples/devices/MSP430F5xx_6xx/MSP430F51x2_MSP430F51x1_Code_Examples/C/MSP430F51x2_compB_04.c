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
// MSP430F51x2 Demo - COMPB Toggle from LPM4; CompB in ultra low power mode
// 		Vcompare is compared against the Vcc*1/2
//
// Description: Use CompB and shared reference to determine if input 'Vcompare'
//    is high/low.  When Vcompare exceeds 0.5*Vcc CBOUT goes high and when 
//    Vcompare is less than 0.5*Vcc then CBOUT goes low. 
//    Connect P3.3/CBOUT to P1.0 externally to see the LED toggle accordingly.
//                                                   
//                 MSP430F51x2
//             ------------------                        
//         /|\|                  |                       
//          | |                  |                       
//          --|RST      P1.1/CB1 |<--Vcompare            
//            |                  |                                         
//            |        P3.3/CBOUT|----> 'high'(Vcompare>Vcc*0.5); 'low'(Vcompare<Vcc*0.5)
//            |                  |  |
//            |            P1.0  |__| LED 'ON'(Vcompare>Vcc*0.5); 'OFF'(Vcompare<Vcc*0.5)
//            |                  | 
//
//  C.Sterzik/B.Nisarga
//  Texas Instruments Inc.
//  Dec 2009
//  Built with CCS v4 and IAR Embedded Workbench Version: 4.21
//******************************************************************************
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;     // Stop WDT
  P3DIR |= BIT3;                // P3.3 output direction
  P3SEL |= BIT3;                // Select CBOUT function on P3.3/CBOUT

// Setup ComparatorB                           
  CBCTL0 |= CBIPEN+CBIPSEL_1;   // Enable V+, input channel CB1              
  CBCTL1 |= CBMRVS;             // CMRVL selects the refV - VREF0
  CBCTL1 |= CBPWRMD_2;          // Ultra-Low Power mode         
  CBCTL2 |= CBRSEL;             // VREF is applied to -terminal 
  CBCTL2 |= CBRS_1+CBREF04;     // VCC applied to R-ladder; VREF0 is Vcc*1/2
  CBCTL3 |= BIT1;               // Input Buffer Disable @P1.1/CB1    
  CBCTL1 |= CBON;               // Turn On ComparatorB           

  __delay_cycles(75);           // delay for the reference to settle

  __bis_SR_register(LPM4_bits);             // Enter LPM4
  __no_operation();                         // For debug 
}
