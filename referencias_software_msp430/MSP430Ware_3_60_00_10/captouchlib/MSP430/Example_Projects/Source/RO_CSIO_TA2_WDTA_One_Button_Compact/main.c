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
// RO_CSIO_TA2_WDTA_One_Button_Compact example
// Touch the middle element to turn on/off the center button LED
// Uses the low-level API function calls for reduced memory footprint.
// Note: Baseline tracking is implemented in the Application Layer
// RO method capactiance measurement using CSIO, TimerA2, and WDTA
//
//       Schematic Description:
//
//                         MSP430FR5969
//                      +---------------+
//                      |
//             C--------|P1.4
//           C----------|P3.5
//               C------|P1.3
//             C--------|P3.6
//                      |
//           C----------|P1.5
//                      |
//           C----------|P3.4
//
//        The WDTA interval represents the measurement window.  The number of
//        counts within the TA0R that have accumulated during the measurement
//        window represents the capacitance of the element. This is lowest
//        power option with either LPM3 (ACLK WDTp source) or LPM0 (SMCLK WDTp
//        source).
//
// This is the preliminary code revised by Holly Gu
// 1st Mar, 2013


//******************************************************************************
#include  "CTS_Layer.h"
#include "msp430fr5969.h"

// Define User Configuration values //
//----------------------------------//
#define DELAY 2000 		// Timer delay timeout count - 5000*0.1msec = 500 msec

// Sensor settings
#define KEY_lvl     150             // Defines the min count for a "key press"
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

  WDTCTL = WDTPW + WDTHOLD;                // Stop watchdog timer
  //Clock Setting
  CSCTL0_H = 0xA5;                         //Unlock CS
  CSCTL1 = DCORSEL + DCOFSEL_5;            //Set DCO=20MHz,use this clk when fRO
  CSCTL2 = SELA__VLOCLK + SELS_3 + SELM_3; //set SMCLK = MCLK = DCO LFXT1 = VLO
  CSCTL0_H = 0;                            //Lock CS registers

  P4DIR |= BIT2; // Set the pin controlling the center LED P4.2  as output pin

  // Initialize Baseline measurement
  TI_CAPT_Raw(&middle_button,&base_cnt);
  
  // Main loop starts here
  while (1)
  {
  	  // Take raw delta measurement
      TI_CAPT_Raw(&middle_button,&meas_cnt);

#ifndef fRO_CSIO_TA2_TA3
      if(base_cnt < meas_cnt)
      // Handle baseline measurment for a base C decrease
      {                             // beyond baseline, i.e. cap decreased
          base_cnt = (base_cnt+meas_cnt) >> 1; // Re-average baseline up quickly
          delta_cnt = 0;            // Zero out delta for position determination
      }
      else
      {
          delta_cnt = base_cnt - meas_cnt;  // Calculate delta: c_change
      }
#endif

#ifdef fRO_CSIO_TA2_TA3
      if(base_cnt > meas_cnt)
      // Handle baseline measurment for a base C decrease
      {                             // beyond baseline, i.e. cap decreased
          base_cnt = (base_cnt+meas_cnt) >> 1; // Re-average baseline up quickly
          delta_cnt = 0;            // Zero out delta for position determination
      }
      else
      {
          delta_cnt = meas_cnt - base_cnt;  // Calculate delta: c_change
      }
#endif
      /* Determine if each key is pressed per a preset threshold */
      if (delta_cnt > KEY_lvl)
      {
        // turn on LED
        P4OUT |= BIT2;
      }
      else
      {
        // turn off LED
        base_cnt = base_cnt - 1;  // Adjust baseline down, should be slow to
        P4OUT &= ~BIT2;
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

#pragma vector=RTC_VECTOR,PORT2_VECTOR,TIMER3_A1_VECTOR,ADC12_VECTOR,        \
  USCI_A1_VECTOR,PORT1_VECTOR,TIMER1_A1_VECTOR,DMA_VECTOR,TIMER0_A1_VECTOR,  \
  USCI_B0_VECTOR,USCI_A0_VECTOR,TIMER0_B1_VECTOR,TIMER0_B0_VECTOR,           \
  UNMI_VECTOR,SYSNMI_VECTOR,AES256_VECTOR,PORT3_VECTOR,TIMER3_A0_VECTOR,     \
  PORT4_VECTOR,TIMER1_A0_VECTOR,TIMER2_A0_VECTOR,                            \
  TIMER2_A1_VECTOR /*  COMP_E_VECTOR */
__interrupt void ISR_trap(void)
{
    // the following will cause an access violation which results in a SW BOR
    PMMCTL0 = PMMPW | PMMSWBOR;
}
