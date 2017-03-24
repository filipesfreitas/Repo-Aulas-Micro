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
//  MSP-FET430P140 Demo - DMA0, Rpt'd Blk, I2C Master Interface to DAC8571
//  Master = '169, Slave = DAC8571
//
//  Description: Using the DMA0 16-bit sine data is transmitted to the external
//  DAC. The DAC8571 is configured and sent continuous data without a stop or
//  repeated start condition. Data is handled in bytes by the I2C module and
//  the CPU is normally in LPM0.
//  ACLK = n/a, MCLK = SMCLK = I2CCLOCK = DCO ~ 750kHz
//  //* MSP430F169 Device Required *//
//
//                   MSP430F169                         DAC8571
//                 ---------------                   ------------
//                |            SDA|<--------------->|SDA         |
//                |     I2C    SCL|---------------->|SCL  I2C    |
//                |   MASTER      |                 |    SLAVE   |
//                |               |              GND|A0          |
//
//
//  DAC8571 I2C address = 0x4C (A0 = GND)
//
//  Z. Albus
//  Texas Instruments Inc.
//  Feb 2005
//  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.21A
//******************************************************************************

#include <msp430.h>


//------------------------------------------------------------------------------
// Flash - 16-bit Sine Lookup table with 16 steps (byte-wide format)
//------------------------------------------------------------------------------
const char Sin_tab[32] = {
       0xFF,
       0xFF,
       0xF6,
       0x40,
       0xDA,
       0x81,
       0xB0,
       0xFA,
       0x7F,
       0xFF,
       0x4F,
       0x03,
       0x25,
       0x7C,
       0x09,
       0xBD,
       0x00,
       0x00,
       0x09,
       0xBD,
       0x25,
       0x7C,
       0x4F,
       0x03,
       0x7F,
       0xFF,
       0xB0,
       0xFA,
       0xDA,
       0x81,
       0xF6,
       0x40
};

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog
  P3SEL |= 0x0A;                            // Assign I2C pins to module
  U0CTL |= TXDMAEN + I2C + SYNC;            // Enable DMA for TX, I2C mode
  U0CTL &= ~I2CEN;                          // Disable I2C
  I2CTCTL = I2CRM + I2CSSEL1;               // S/W controls data flow, SMCLK
  I2CSA = 0x4C;                             // Slave address
  U0CTL |= I2CEN;                           // Enable I2C
  DMACTL0 = DMA0TSEL_4;                     // I2CTXRDY trigger
  DMA0SA = (int) Sin_tab;                   // Source block address
  DMA0DA = (unsigned int)&I2CDRB;           // Destination single address
  DMA0SZ = 0x20;                            // Block size
  DMA0CTL = DMADT_4 + DMASRCINCR_3 + DMADSTBYTE + DMASRCBYTE + DMAEN;
                                            // Rpt, inc src, byte-byte
  U0CTL |= MST;                             // Master
  I2CTCTL |= I2CTRX + I2CSTT;               // Write, ST
  I2CDRB = 0x10;                            // Write DAC control

  __bis_SR_register(LPM0_bits);             // Enter LPM0
}