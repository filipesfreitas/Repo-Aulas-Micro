/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2014, Texas Instruments Incorporated
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
//   MSP430FR231x Demo - LPM3.5, device enter LPM3.5 and toggles P1.0 with
//                       RTC interrupt handling every 1s
//
//
//   Description: Device enter LPM3.5 after configuring the RTC. The RTC wakes
//   the device up from LPM3.5 every second and toggles P1.0.
//   It also stores the state of P0OUT in the Backup RAM Registers.
//
//   ACLK = XT1 = 32kHz, MCLK = SMCLK = default DCODIV = ~1MHz.
//
//            MSP430FR2311
//         -----------------
//     /|\|                 |
//      | |                 |
//      | |        XIN(P2.7)|--
//      --|RST              |  ~32768Hz
//        |       XOUT(P2.6)|--
//        |                 |
//        |             P1.0|-->LED
//
//   Darren Lu
//   Texas Instruments Inc.
//   July 2015
//   Built with IAR Embedded Workbench v6.30 & Code Composer Studio v6.1 
//******************************************************************************
#include <msp430.h>

void initGpio(void);

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    initGpio();                             // Configure GPIO

    // Initialize XT1 32kHz crystal
    P2SEL1 |= BIT6 | BIT7;                  // P2.6~P2.7: crystal pins
    do
    {
        CSCTL7 &= ~(XT1OFFG | DCOFFG);      // Clear XT1 and DCO fault flag
        SFRIFG1 &= ~OFIFG;
    } while (SFRIFG1 & OFIFG);              // Test oscillator fault flag

    // First determine whether we are coming out of an LPMx.5 or a regular RESET.
    if (SYSRSTIV == SYSRSTIV_LPM5WU)        // When woken up from LPM3.5, reinit
    {
        // If MCU wakes up from LPM3.5, re-init and then return to LPM3.5 again.

        // Restore P1OUT value from backup RAM memory, keep P1OUT after LPMx.5 reset
        P1OUT = *(unsigned int *)BKMEM_BASE;

        __enable_interrupt();               // The RTC interrupt should trigger now...
    }
    else
    {
        // Device powered up from a cold start.
        // It configures the device and puts the device into LPM3.5

        // Configure backup memory
        *(unsigned int *)BKMEM_BASE = 0;

        // Configure RTC
        // Interrupt and reset happen every 1024/32768 * 32 = 1 sec.
        RTCMOD = 32-1;
        RTCCTL = RTCSS__XT1CLK | RTCSR |RTCPS__1024;
        RTCCTL |= RTCIE;

        // Store P1OUT value in backup memory register before enter LPM3.5
        *(unsigned int *)BKMEM_BASE = P1OUT;
    }

    // Enter LPM3.5 mode with interrupts enabled. Note that this operation does
    // not return. The LPM3.5 will exit through a RESET event, resulting in a
    // re-start of the code.
    PMMCTL0_H = PMMPW_H;                    // Open PMM Registers for write
    PMMCTL0_L |= PMMREGOFF;                 // and set PMMREGOFF
    __bis_SR_register(LPM3_bits | GIE);
    __no_operation();

    return 0;
}

void initGpio(void)
{
    P1DIR = 0xFF; P2DIR = 0xFF;
    P1REN = 0xFF; P2REN = 0xFF;
    P1OUT = 0x00; P2OUT = 0x00;

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = RTC_VECTOR
__interrupt void RTC_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(RTC_VECTOR))) RTC_ISR (void)
#else
#error Compiler not supported!
#endif
{
    switch(__even_in_range(RTCIV, RTCIV_RTCIF))
    {
        case RTCIV_NONE : break;            // No interrupt pending
        case RTCIV_RTCIF:                   // RTC Overflow
            // Toggle LED on P1.0
            P1OUT ^= BIT0;

            // Store P1OUT value in backup memory register
            *(unsigned int *)BKMEM_BASE = P1OUT;
            break;
        default:          break;
    }
}
