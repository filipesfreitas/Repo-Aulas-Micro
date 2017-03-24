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
 *  RO method capactiance measurement using CompA+, TimerA0, and WDT+
 *        Schematic Description of CompA+ forming relaxation oscillator and
 *        coupling (connection) between the relaxation oscillator and TimerA0.
 *        <- Output
 *        -> Input
 *        R  Resistor (typically 100Kohms)
 *
 *                             MSP430F2011
 *                          +---------------+
 *                          |           
 *                       +--<P1.6 
 *                       |  
 *                       R  
 *                       |  
 *                   +---+-->P1.1/CA1
 *                   |   |  
 *                   R   R                
 *                   |   |  
 *                  GND  +-->P1.0/TACLK
 *                       |  
 *    c-+-----------+-R--+--<P1.7/CAOUT  
 *      |                |
 *      | c-+-------+-R--+  
 *      |   |            |
 *      |   | c-+-----R--+  
 *      |   |   |        |
 *      |   |   | c-+-R--+                               
 *      |   |   |   |
 *      |   |   |   +------->P1.5/CA5
 *      |   |   +----------->P1.4/CA4
 *      |   +--------------->P1.3/CA3
 *      +------------------->P1.2/CA2
 *
 *  The WDT+ interval represents the measurement window.  The number of 
 *  counts within the TA0R that have accumulated during the measurement
 *  window represents the capacitance of the element.  Using the WDT is
 *  a low power implementation, either LPM3 (when WDT+ is sourced from 
 *  ACLK) or LPM0 (when WDT+ sourced from SMCLK).
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

unsigned int position;
//unsigned int dCnt[4];

// Main Function
void main(void)
{ 
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer

  // establish baseline
  TI_CAPT_Init_Baseline(&slider);
  TI_CAPT_Update_Baseline(&slider,5);

  // Main loop starts here
  while (1)
  {
    position = TI_CAPT_Slider(&slider);
    //TI_CAPT_Custom(&slider,dCnt);
    if(position != ILLEGAL_SLIDER_WHEEL_POSITION)   
    {
        __no_operation();
    }
    __delay_cycles(100); 

  }
} // End Main

