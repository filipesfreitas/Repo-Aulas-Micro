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
// fRO_PINOSC_TA0_SW example
//   fRO method capactiance measurement using the PinOsc and TimerA0
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
//           Charge and Discharge Cycle
//                            + 
//                        +    +
//                    +          +
//                 +                +
//               +                     +
//           Start Timer                  After n cycles Stop Timer
//
//        The TAR reister value is the number of SW loops (function of MCLK) 
//        within n charge and discharge cycles.  This value is directly 
//        proportional to the capacitance of the element measured. 'n' is 
//        defined by the variable accumulation_cycles.
//        This method does not require the use of the WDTp peripheral.
//        Higher resolutions can be achieved with higher clock speeds and 
//        larger accumulation cycles.  This method provides faster scan rates
//        at the expense of higher power consumption during the scans (higher 
//        clock frequencies).
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

struct Element * keypressed;
uint8_t sliderPosition;
uint8_t wheelPosition;

// Main Function
void main(void)
{ 
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  
  TI_CAPT_Init_Baseline(&wheel);
  TI_CAPT_Update_Baseline(&wheel,5);
  TI_CAPT_Init_Baseline(&slider);
  TI_CAPT_Update_Baseline(&slider,5);
  TI_CAPT_Init_Baseline(&buttons);
  TI_CAPT_Update_Baseline(&buttons,5);

  // Main loop starts here
  while (1)
  {
    keypressed = (struct Element *)TI_CAPT_Buttons(&buttons);
	if(keypressed)
	{
	    if(keypressed == (struct Element*)&elementC)
		{
		    __no_operation();
		}
	    if(keypressed == (struct Element*)&elementD)
		{
		    __no_operation();
		}
	}
	sliderPosition = TI_CAPT_Slider(&slider);
	if(sliderPosition != (uint8_t)ILLEGAL_SLIDER_WHEEL_POSITION)
	{
	    __no_operation();
	}
	wheelPosition = TI_CAPT_Wheel(&wheel);
	if(wheelPosition != (uint8_t)ILLEGAL_SLIDER_WHEEL_POSITION)
	{
	    __no_operation();
	}
	
  }
} // End Main

