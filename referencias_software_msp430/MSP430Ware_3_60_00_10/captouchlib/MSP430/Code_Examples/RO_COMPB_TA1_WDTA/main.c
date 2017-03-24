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
/*!
 *  RO_COMPB_TA1_WDTA example with 12 elements on the MSP430F5529.  
 * 
 *                                                         MSP430F5529
 *                                     +---------------+
 *                                     | 
 *   c-+-------------------------R--+--<P1.6/TA1CLK/CBOUT  
 *     |                            |
 *     | c-+---------------------R--+  
 *     |   |                        |
 *     |   |  c-+----------------R--+  
 *     |   |    |                   |
 *                     ...
 *     |   |    |                   |
 *     |   |    |    c-+---------R--+  
 *     |   |    |      |            |
 *     |   |    |      | c-+-----R--+  
 *     |   |    |      |   |        |
 *     |   |    |      |   | c-+-R--+                               
 *     |   |    |      |   |   |
 *     |   |    |      |   |   +------->CB0
 *     |   |    |      |   +----------->CB1
 *     |   |    |      +--------------->CB2
 *     |   |    |
 *                    ...
 *     |   |    |
 *     |   |    +---------------------->CB9
 *     |   +--------------------------->CB10
 *     +------------------------------->CB11
 *
 *  Some MSP430 devices allow the digital IO to be driven from a different 
 *  voltage rail (DVIO) than the voltage rail (VCC) that the Comp_B peripheral 
 *  uses.  If the comparator output, CBOUT, uses DVIO and DVIO is different 
 *  from VCC, then the input high and input low values set within the library 
 *  need to be updated.  These values are set in the Comp_B control register 2,
 *  CBCTL2, found in the CTS_HAL.c file.
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

#define NUM_SEN	12

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
	&elementB
};						

// Main Function
void main(void)
{ 
  uint8_t i;
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer

  // establish baseline
  TI_CAPT_Init_Baseline(&keypad);
  TI_CAPT_Update_Baseline(&keypad,5);

  // Main loop starts here
  while (1)
  {
      keypressed = (struct Element *)TI_CAPT_Buttons(&keypad);
      TI_CAPT_Custom(&keypad,dCnt);
      if(keypressed)
      {
          for(i=0; i<NUM_SEN; i++)
          {
      	      if (keypressed == address_list[i])
	      {
	          //dCnt[i];
                   __no_operation();
              }
           }  
      }
  }
} // End Main

