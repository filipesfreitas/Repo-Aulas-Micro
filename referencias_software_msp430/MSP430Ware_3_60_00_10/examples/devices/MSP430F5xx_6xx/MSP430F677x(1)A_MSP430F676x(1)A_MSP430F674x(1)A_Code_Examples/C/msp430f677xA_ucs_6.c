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
//  MSP430F67791A Demo - UCS, XT1 sources ACLK. Toggles P5.3
//
//  Description: This program demonstrates using XT1 to source ACLK
//  ACLK = LFXT1 = 32,768Hz
//  //* An external watch crystal between XIN & XOUT is required for ACLK *//
//
//               MSP430F67791A
//             -----------------
//         /|\|              XIN|-
//          | |                 | 32kHz
//          --|RST          XOUT|-
//            |                 |
//            |             P1.2|--> ACLK = ~32kHz
//            |                 |
//            |             P5.3|-->LED
//
//   E. Chen
//   Texas Instruments Inc.
//   January 2014
//   Built with CCS Version: 5.5.0 and IAR Embedded Workbench Version: 5.52
//******************************************************************************
#include <msp430.h>

void main(void)
{
    WDTCTL = WDT_ADLY_1000;                 // WDT 1000ms, ACLK, interval timer
    SFRIE1 |= WDTIE;                        // Enable WDT interrupt

    // Setup P5.3 output, P1.2 ACLK
    P5DIR |= BIT3;                          // Set P5.3 to output direction
    P5OUT &= ~BIT3;                         // Clear P5.3
    P1DIR |= BIT2;                          // ACLK set out to pin
    P1SEL0 |= BIT2;                          // P1.2 for debugging purposes.

    // Setup LFXT1
    UCSCTL6 &= ~(XT1OFF);                   // XT1 On
    UCSCTL6 |= XCAP_3;                      // Internal load cap

    // Loop until XT1, XT2 & DCO stabilizes
//    do
//    {
//        UCSCTL7 &= ~(XT2OFFG | XT1LFOFFG | DCOFFG);
//        // Clear XT2,XT1,DCO fault flags
//        SFRIFG1 &= ~OFIFG;                  // Clear fault flags
//    } while (SFRIFG1 & OFIFG);              // Test oscillator fault flag
    UCSCTL6 &= ~(XT1DRIVE_3);               // XT1 stable, reduce drive strength

    __bis_SR_register(LPM3_bits | GIE);     // Enter LPM3 w/ interrupts
    __no_operation();                       // For debugger
}

// Watchdog Timer interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = WDT_VECTOR
__interrupt void watchdog_timer(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(WDT_VECTOR))) watchdog_timer (void)
#else
#error Compiler not supported!
#endif
{
    P5OUT ^= BIT3;                          // Toggle P5.3 using exclusive-OR
}
