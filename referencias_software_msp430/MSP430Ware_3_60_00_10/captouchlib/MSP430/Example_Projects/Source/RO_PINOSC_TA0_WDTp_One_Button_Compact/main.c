/* --COPYRIGHT--,BSD
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
 * --/COPYRIGHT--*/
//******************************************************************************
// RO_PINOSC_TA0_One_Button_Compact example
// Touch the middle element to turn on/off the center button LED
// Uses the low-level API function calls for reduced memory footprint.
// Note: Baseline tracking is implemented in the Application Layer
// RO method capactiance measurement using PinOsc IO, TimerA0, and WDT+
//
//          Schematic Description: 
// 
//                         MSP430G2452
//                      +---------------+
//                      |
//             C--------|P2.4
//           C----------|P2.1
//               C------|P2.3
//             C--------|P2.2
//                      |
//           C----------|P2.5
//                      |
//           C----------|P2.0
// 
//        The WDT+ interval represents the measurement window.  The number of 
//        counts within the TA0R that have accumulated during the measurement
//        window represents the capacitance of the element. This is lowest 
//        power option with either LPM3 (ACLK WDTp source) or LPM0 (SMCLK WDTp 
//        source).
//
//******************************************************************************
#include  "CTS_Layer.h"

// Define User Configuration values //
//----------------------------------//
#define DELAY 5000 		// Timer delay timeout count - 5000*0.1msec = 500 msec

// Sensor settings
#define KEY_lvl     150              // Defines the min count for a "key press"
                                     // Set to ~ half the max delta expected
// Global variables for sensing
unsigned int base_cnt;
unsigned int meas_cnt;
unsigned int delta_cnt;

char key_pressed, key_loc;
int cycles;

// Sleep Function
// Configures Timer A to run off ACLK, count in UP mode, places the CPU in LPM3 
// and enables the interrupt vector to jump to ISR upon timeout 
void sleep(unsigned int time)
{
    TA0CCR0 = time;
    TA0CTL = TASSEL_1+MC_1+TACLR;
    TA0CCTL0 &= ~CCIFG;
    TA0CCTL0 |= CCIE; 
    __bis_SR_register(LPM3_bits+GIE);
    __no_operation();
}

// Main Function
void main(void)
{ 
  volatile unsigned int i,j;

  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  BCSCTL1 = CALBC1_1MHZ;                // Set DCO to 1, 8, 12 or 16MHz
  DCOCTL = CALDCO_1MHZ;
  BCSCTL1 |= DIVA_0;                    // ACLK/(0:1,1:2,2:4,3:8)
  BCSCTL3 |= LFXT1S_2;                  // LFXT1 = VLO
  
  P1OUT = 0x00;							// Clear Port 1 bits
  P1DIR |= BIT0;						// Set P1.0 as output pin

  P2SEL &= ~(BIT6 + BIT7);	// Configure XIN (P2.6) and XOUT (P2.7) to GPIO
  P2OUT = 0x00;				// Drive all Port 2 pins low
  P2DIR = 0xFF;				// Configure all Port 2 pins outputs
  
  // Initialize Baseline measurement
  TI_CAPT_Raw(&middle_button,&base_cnt);
  
  // Main loop starts here
  while (1)
  {
  	  // Take raw delta measurement
      TI_CAPT_Raw(&middle_button,&meas_cnt);
      
      if(base_cnt < meas_cnt)
      // Handle baseline measurment for a base C decrease
      {                                 // beyond baseline, i.e. cap decreased
          base_cnt = (base_cnt+meas_cnt) >> 1; // Re-average baseline up quickly
          delta_cnt = 0;             // Zero out delta for position determination
      }
      else 
      {
          delta_cnt = base_cnt - meas_cnt;  // Calculate delta: c_change
      }

      if (delta_cnt > KEY_lvl)       // Determine if each key is pressed per a preset threshold
      {
        // turn on LED
        P1OUT |= BIT0;
      }
      else
      {
        // turn off LED
        base_cnt = base_cnt - 1;  // Adjust baseline down, should be slow to
        P1OUT &= ~BIT0;
      }
      
    // Put the MSP430 into LPM3 for a certain DELAY period
    sleep(DELAY);	      

  }
} // End Main

/******************************************************************************/
// Timer0_A0 Interrupt Service Routine: Disables the timer and exists LPM3  
/******************************************************************************/
#pragma vector=TIMER0_A0_VECTOR
__interrupt void ISR_Timer0_A0(void)
{
  TA0CTL &= ~(MC_1);
  TA0CCTL0 &= ~(CCIE);
  __bic_SR_register_on_exit(LPM3_bits+GIE);
}


#pragma vector=PORT2_VECTOR,             \
  PORT1_VECTOR,                          \
  TIMER0_A1_VECTOR,                      \
  USI_VECTOR,                            \
  NMI_VECTOR,COMPARATORA_VECTOR,         \
  ADC10_VECTOR
__interrupt void ISR_trap(void)
{
  // the following will cause an access violation which results in a PUC reset
  WDTCTL = 0;
}
