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
//  MSP-FET430P410 Demo - Timer_A, UART 115200 Echo, DCO SMCLK
//
//  Description: Use Timer_A CCR0 hardware output modes and SCCI data latch to
//  implement UART function @ 115k baud. Software does not directly read and
//  write to RX and TX pins, instead proper use of output modes and SCCI data
//  latch are demonstrated. Using these hardware features eliminates ISR
//  latency effects as hardware ensures that input and output bit latching and
//  timing are perfectly synchronised with Timer_A regardless of other
//  software activity. In the Mainloop the UART function readies the UART to
//  receive one character and waits in LPM0 with all activity interrupt driven.
//  After a character has been received, the UART receive function forces exit
//  from LPM0 in the Mainloop which echo's back the received character.
//  ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
//  //* An external watch crystal between XIN & XOUT is required for ACLK *//	
//
//                MSP430F413
//            -----------------
//        /|\|              XIN|-
//         | |                 | 32kHz
//         --|RST          XOUT|-
//           |                 |
//           |    P1.0/CCI0A/TX|----------->
//           |                 | 115200 8N1
//           |    P1.1/CCI0B/RX|<-----------
//
//  M. Buccini
//  Texas Instruments Inc.
//  Feb 2005
//  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.21A
//*****************************************************************************
#include <msp430.h>

#define RXD   0x02                          // RXD on P1.1
#define TXD   0x01                          // TXD on P1.0

//  Conditions for 115200 Baud SW UART, SMCLK = 8MHz

#define Bitime_5  0x024       // ~ 0.5 bit length + small adjustment
#define Bitime    0x045       // 8.6 us bit length ~ 115942 baud

unsigned int RXTXData;
unsigned char BitCnt;

void TX_Byte(void);
void RX_Ready(void);


int main (void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  FLL_CTL0 |= DCOPLUS + XCAP14PF;           // DCO+, Configure load caps
  SCFI0 |= FN_4;                            // x2 DCO frequency, 8MHz nominal
  SCFQCTL = 121;                            // (121+1) x 32768 x 2 = 7.99 MHz
  CCTL0 = OUT;                              // TXD Idle as Mark
  TACTL = TASSEL_2 + MC_2;                  // SMCLK, continuous mode

  P1SEL = TXD + RXD;                        // P1.0/1 TA0 for TXD/RXD function
  P1DIR = TXD;                              // TXD output on P1

  // Mainloop
  for (;;)
  {
    RX_Ready();                             // UART ready to RX one Byte
    __bis_SR_register(CPUOFF + GIE);        // Enter LPM0 Until character RXed
    TX_Byte();                              // TX Back RXed Byte Received
  }
}


// Function Transmits Character from RXTXData Buffer
void TX_Byte (void)
{
  BitCnt = 0xA;                             // Load Bit counter, 8data + ST/SP
  CCR0 = TAR;                               // Current state of TA counter
  CCR0 += Bitime;                           // Some time till first bit
  RXTXData |= 0x100;                        // Add mark stop bit to RXTXData
  RXTXData = RXTXData << 1;                 // Add space start bit
  CCTL0 = OUTMOD0 + CCIE;                   // TXD = mark = idle
  while ( CCTL0 & CCIE );                   // Wait for TX completion
}


// Function Readies UART to Receive Character into RXTXData Buffer
void RX_Ready (void)
{
  BitCnt = 0x8;                             // Load Bit counter
  CCTL0 = SCS + CCIS0 + OUTMOD0 + CM1 + CAP + CCIE;  // Sync, Neg Edge, Capture
}


// Timer A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
  CCR0 += Bitime;                           // Add Offset to CCR0

  // RX
  if (CCTL0 & CCIS0)                        // RX on CCI0B?
  {
    if( CCTL0 & CAP )                       // Capture mode = start bit edge
    {
      CCTL0 &= ~ CAP;                       // Capture to compare mode
      CCR0 += Bitime_5;
    }
    else
    {
      RXTXData = RXTXData >> 1;
      if (CCTL0 & SCCI)                     // Get bit waiting in receive latch
        RXTXData |= 0x80;
      BitCnt --;                            // All bits RXed?
      if ( BitCnt == 0)
//>>>>>>>>>> Decode of Received Byte Here <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      {
        CCTL0 &= ~ CCIE;                    // All bits RXed, disable interrupt
        __bic_SR_register_on_exit(CPUOFF);  // Clear LPM0 bits from 0(SR)
      }
//>>>>>>>>>> Decode of Received Byte Here <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    }
  }
  // TX
  else
  {
    if ( BitCnt == 0)
      CCTL0 &= ~ CCIE;                      // All bits TXed, disable interrupt
    else
    {
      CCTL0 |=  OUTMOD2;                    // TX Space
      if (RXTXData & 0x01)
        CCTL0 &= ~ OUTMOD2;                 // TX Mark
      RXTXData = RXTXData >> 1;
      BitCnt --;
    }
  }
}