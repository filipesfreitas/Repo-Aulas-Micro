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
/*   Description: Output an Analog Signal using the APOOL DAC. A write to the    */
/*   APINT register while REFON, ODSEL, DBEN, and ODEN are set to one corresponds*/
/*   to an analog voltage with range 1..256mV driven on Aout.                    */
/*                                                                               */
/****************************A_POOL DAC ******************************************/
/*                                                                               */
/*                                                                               */
/*              +----L092---+                                                    */
/*              |*1      14 |                                                    */
/*              | 2      13 |                                                    */
/*              | 3      12 |                                                    */
/*              | 4      11 |                                                    */
/*              | 5      10 |                                                    */
/*              | 6       9 |                                                    */
/*              | 7       8 |  -> AOUT- Analog Output Provided ~256mV            */
/*              +-----------+                                                    */
/*  D.Dang/D.Archbold/D.Szmulewicz                                               */
/*  Texas Instruments Inc.                                                       */
/*  Built with IAR Version 5.10.4                                                */
/*********************************************************************************/
#include <msp430.h>                               // 

int main(void)
{
   
   WDTCTL = WDTPW + WDTHOLD;                           // Stop WDT 
   
  //Setup of the A-POOL module for DAC output
    
    APCNF = DBON+CONVON+APREFON;                      // Configure A-POOL elements
    APCTL |= ODEN+OSEL;                               // A-POOL Comparator/Saturation Based Stop Enable and Running 
    
    while(1)
   
     {                                                // APINT - A-POOL integer Conversion Register
      APINT =0xFF;                                    // Output a Value of ~256mV on Aout, Change this Value for different
     }                                                // voltages. High Accuracy is reached when Aout > 20mV.
                                                      // Try the following values - 0x00 = 1mV ; 0x7F = 128mV; 0xFF = 256mV
   
}


