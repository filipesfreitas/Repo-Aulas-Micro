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
/*
 *  main.c
 *  In this RO_PINOSC_TA0_WDTp example, four elements are configured as 
 *  wheel.
 *
 *          Schematic Description: 
 * 
 *                         MSP430G2452
 *                      +---------------+
 *                      |
 *             C--------|P2.4
 *           C----------|P2.1
 *               C------|P2.3
 *             C--------|P2.2
 *                      |
 *
 *  The wheel is configured in strucutre.c to use the SMCLK to establish
 *  a consistent 8ms gate time.  This can be accomplished by using the 
 *  1Mhz calibration constants or the 8Mhz constants with the SMCLK 
 *  divider setting of /8 as in this example. 
 *
 *  The element and sensor definitions found in the configuration file 
 *  structure.c use designated initializer lists. This allows members to be 
 *  initialized in any order and also enhances the readability of the element
 *  being initialized.  
 *  This feature requires the GCC language extension found in Code Composer 
 *  Studio (CCS).  C99 is the default dialect found in IAR and therefore the 
 *  default settings can be used.
 */

#include "CTS_Layer.h"

uint16_t position;
// uint16_t dCnt[4];

// Main Function
uint16_t main(void)
{ 
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  BCSCTL1 = CALBC1_8MHZ;                // Set DCO to 1, 8, 12 or 16MHz
  DCOCTL = CALDCO_8MHZ;
  BCSCTL1 |= DIVA_0;                    // ACLK/(0:1,1:2,2:4,3:8)
  BCSCTL2 |= DIVS_3;                    // SMCLK/(0:1,1:2,2:4,3:8)
  BCSCTL3 |= LFXT1S_2;                  // LFXT1 = VLO

  // establish baseline
  TI_CAPT_Init_Baseline(&wheel);
  TI_CAPT_Update_Baseline(&wheel,5);

  // Main loop starts here
  while (1)
  {
    position = TI_CAPT_Wheel(&wheel);
	// TI_CAPT_Raw(&wheel,dCnt);
    // TI_CAPT_Custom(&wheel,dCnt);
    if(position != ILLEGAL_SLIDER_WHEEL_POSITION)   
    {
        __no_operation();
    }
    __delay_cycles(100); 

  }
} // End Main

#pragma vector= PORT2_VECTOR,PORT1_VECTOR,ADC10_VECTOR,NMI_VECTOR,          \
                TIMER0_A1_VECTOR,COMPARATORA_VECTOR,TIMER0_A0_VECTOR
__interrupt void ISR_trap(void)
{
  /* the following will cause an access violation and result in a PUC reset */
  WDTCTL = 0;
}

