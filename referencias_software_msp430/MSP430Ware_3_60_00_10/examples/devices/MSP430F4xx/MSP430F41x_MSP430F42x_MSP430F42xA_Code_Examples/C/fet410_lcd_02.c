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
//*****************************************************************************
//  MSP-FET430P410 Demo - LCD, Display Numbers on a Static LCD
//
//  Description: This program displays a 3.5 digit number on a static LCD,
//  then waits in low power mode 3. The leading digit must be '1', nothing
//  else will display.  To use the program enter a 3.5 digit BCD
//  (characters 0-9) number in the program for the variable "value".
//  Download the program and run it.
//  ACLK = LFXT1 = 32768 Hz, MCLK = SMCLK = DCO = 32 x ACLK = 1048576 Hz
//  //* An external watch crystal is required on XIN/XOUT for ACLK *//	
//
//
//                                 Connections MSP430 -> LCD
//                                 -------------------------
//
//                                T.I.               Varitronix
//                           MSP430x41x MCU     3.5 digit, static LCD
//                                                 # VI-302-DP-S
//                           ---------------       --------------
//                          |          COM0 |-----|1,40 COM      |
//                          |          SEG0 |-----|21            |
//                          |          SEG1 |-----|20            |
//                          |          SEG2 |-----|19            |
//                          |          SEG3 |-----|18            |
//                          |          SEG4 |-----|17            |
//                          |          SEG5 |-----|22            |
//                          |          SEG6 |-----|23            |
//                          |          SEG7 |-----|38 (low batt) |
//                          |          SEG8 |-----|25            |
//                          |          SEG9 |-----|24            |
//                          |          SEG10|-----|15            |
//                          |          SEG11|-----|14            |
//                          |          SEG12|-----|13            |
//                          |          SEG13|-----|26            |
//                          |          SEG14|-----|27            |
//                          |          SEG15|-----|28 (L)  COLON |
//                          |          SEG16|-----|30            |
//                          |          SEG17|-----|29            |
//                          |          SEG18|-----|11            |
//                          |          SEG19|-----|10            |
//                       ---|R03       SEG20|-----|9             |
//                      |   |          SEG21|-----|31            |
//                      |   |          SEG22|-----|32            |
//                     \|/  |          SEG23|-----|3 (B-C) =     |
//                     GND  |               |     | .5 digit ="1"|
//                           ---------------       --------------
//
//                 NOTE: Pin R03 on the MSP430 must be connected to GND
//
//  G. Morton / H. Grewal
//  Texas Instruments Inc.
//  Feb 2005
//  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.21A
//*****************************************************************************
#include <msp430.h>

/* Variable Declarations */
unsigned int value = 0x1789;                // Number to display,
                                            // range = 0 - 1999 = max display
                                            // NOTE: DO NOT use leading zeros

unsigned int h;
unsigned int index;
unsigned int dig_pntr;
char* LCD = LCDMEM;


/* LCD Mapping Array */
const char digit[40] =
{
  0x11, 0x11,  // '0'    LCD segments a+b & c+d = lower two bytes
  0x11, 0x00,  // '0'    LCD segments e+f & g+h = upper two bytes
  0x10, 0x01,  // '1'
  0x00, 0x00,  // '1'
  0x11, 0x10,  // '2'
  0x01, 0x01,  // '2'
  0x11, 0x11,  // '3'
  0x00, 0x01,  // '3'
  0x10, 0x01,  // '4'
  0x10, 0x01,  // '4'
  0x01, 0x11,  // '5'
  0x10, 0x01,  // '5'
  0x01, 0x11,  // '6'
  0x11, 0x01,  // '6'
  0x11, 0x01,  // '7'
  0x00, 0x00,  // '7'
  0x11, 0x11,  // '8'
  0x11, 0x01,  // '8'
  0x11, 0x11,  // '9'
  0x10, 0x01,  // '9'
};


int main(void)
{
  volatile unsigned int i;                  // Use volatile to prevent removal
                                            // by compiler optimization

  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  FLL_CTL0 |= XCAP14PF;                     // Configure load caps
  for (i = 0; i < 10000; i++);              // Delay for 32 kHz crystal to
                                            // stabilize

  // Initialize LCD
  LCDCTL = LCDP1+LCDP0+LCDSTATIC+LCDON;     // Static LCD, segments S0-S23
  BTCTL  = BTFRFQ1+BTFRFQ0;                 // Set freqLCD = ACLK/256

  // Initialize port pins
  P1DIR = 0xFF;                             // Set port to outputs
  P2DIR = 0xFF;                             // Set port to outputs
  P3DIR = 0xFF;                             // Set port to outputs
  P4DIR = 0xFF;                             // Set port to outputs
  P5DIR = 0xFF;                             // Set port to outputs
  P6DIR = 0xFF;                             // Set port to outputs

  // Clear LCD memory to clear display
  for (index = 0; index < 12; index++)
  {
    LCD[index] = 0;
  }

  // Display lower 3 digits
  for (h = 0; h < 3; h++)
  {
    dig_pntr = (value & 0xF) << 2;          // Set pointer to start of
                                            // digit in table

    for (index = 0; index < 4; index++)     // Load 4 bytes of digit
    {
      LCD[index] = digit[dig_pntr++];       // Byte of digit to byte of
                                            // LCD memory and increment to
                                            // next byte of digit
    }

    value >>= 4;                            // Shifts value right to display
                                            // next character

    LCD += 4;                               // Increment by 4 for next
                                            // character location
  }

  if (value == 1)                           // Test if leading 1 needs to
  {                                         // be displayed
    LCDM12 |= 0x10;                         // Set bit to display leading 1
  }

  LPM3;                                     // Enter low power mode 3
}

