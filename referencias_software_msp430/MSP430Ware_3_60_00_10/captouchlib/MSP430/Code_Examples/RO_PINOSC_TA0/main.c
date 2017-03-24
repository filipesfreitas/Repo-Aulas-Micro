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
// RO_PINOSC_TA0 example
// RO method capactiance measurement using PinOsc IO and TimerA0
//
//          Schematic Description: 
//
//                         MSP430G2452
//                      +---------------+
//                      |
//             C--------|P1.0
//             C--------|P1.1
//             C--------|P1.2
//             C--------|P1.3
//             C--------|P1.4
//             C--------|P1.5
//                      |
//           C----------|P2.0
//           C----------|P2.1
//           C----------|P2.2
//           C----------|P2.3
//           C----------|P2.4
//           C----------|P2.5
//                      |
//           C----------|P2.6
//           C----------|P2.7
//
//        The measurement window is accumulation_cycles/ACLK. The ACLK is
//        used to generate a capture event via the internal connection CCIOB. 
//        The counts within the TA0R that have accumulated during the 
//        measurement window represents the capacitance of the element.
//        This peripheral configuration frees up the WDTp peripheral for other
//        uses, but requires an active polling of the CCI0B capture event.  The
//        polling can be replaced with an ISR to improve power consumption.
//
//******************************************************************************
/*
 *  The element and sensor definitions found in the configuration file 
 *  structure.c use designated initializer lists. This allows members to be 
 *  initialized in any order and also enhances the readability of the element
 *  being initialized.  
 *  This feature requires the GCC language extension found in Code Composer 
 *  Studio (CCS).  C99 is the default dialect found in IAR and therefore the 
 *  default settings can be used.
*/
#include "CTS_Layer.h"

#define NUM_SEN	14

uint16_t dCnt[NUM_SEN];
struct Element* keypressed;

const struct Element* address_list[NUM_SEN] = 
{
	&element0,
	&element1,
	&element2,
	&element3,
	&element4,
	&element5,
	&element6,
	&element7,
	&element8,
	&element9,
	&elementA,
	&elementB,
    &elementC,
	&elementD

};						

// Main Function
void main(void)
{ 
  uint8_t i;
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  
  BCSCTL3 |= LFXT1S_2;                  // LFXT1 = VLO

  TI_CAPT_Init_Baseline(&keypad);
  TI_CAPT_Update_Baseline(&keypad,5);

  // Main loop starts here
  while (1)
  {
    keypressed = (struct Element *)TI_CAPT_Buttons(&keypad);
	if(keypressed)
	{
	  for(i=0; i<NUM_SEN; i++)
      {
      	if (keypressed == address_list[i])
		{
		    __no_operation();
		}
      }  
	}
  }
} // End Main

