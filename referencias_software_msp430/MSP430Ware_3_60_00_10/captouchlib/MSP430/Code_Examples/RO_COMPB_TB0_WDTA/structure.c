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
 *  structure.c
 *  RO_COMPB_TB0_WDTA example with the MSP430F5529 Experimenters Board
 *
 *     c-+------------------R--+--<P4.7/TB0CLK/CBOUT
 *       |                     |
 *       |  c-+-------------R--+
 *       |    |                |
 *       |    | c-+---------R--+
 *       |    |   |            |
 *       |    |   | c-+-----R--+
 *       |    |   |   |        |
 *       |    |   |   | c-+-R--+
 *       |    |   |   |   |
 *       |    |   |   |   +------->CB0
 *       |    |   |   +----------->CB1
 *       |    |   +--------------->CB2
 *       |    +------------------->CB3
 *       +------------------------>CB4
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
#include "structure.h"
/*
 *  Elements 0 through 4 make up the keypad
 */
const struct Element element0 = {   //CB0
              .inputBits = CBIMSEL_0,
              .maxResponse = 250,
              .threshold = 125
};
const struct Element element1 = {   //CB1
              .inputBits = CBIMSEL_1,
              .maxResponse = 390,
              .threshold = 195
};
const struct Element element2 = {   //CB2
              .inputBits = CBIMSEL_2,
              .maxResponse = 340,
              .threshold = 170
};
const struct Element element3 = {   //CB3
              .inputBits = CBIMSEL_3,
              .maxResponse = 500,
              .threshold = 230
};
const struct Element element4 = {   //CB4
              .inputBits = CBIMSEL_4,
              .maxResponse = 400,
              .threshold = 200
};
/*
 *  The sensor structure defines the grouping of elements, the method to
 *  measure change in capacitance, and the measurement time of each element.
 */
const struct Sensor keypad =
{
	.halDefinition = RO_COMPB_TB0_WDTA,
	.numElements = 5,
	.baseOffset = 0,
	.cbpdBits = 0x001F, //CB0,CB1,CB2,CB3,CB4
	.arrayPtr[0] = &element0,  // point to first element
	.arrayPtr[1] = &element1,
	.arrayPtr[2] = &element2,
	.arrayPtr[3] = &element3,
	.arrayPtr[4] = &element4,
	.cboutTAxDirRegister = (uint8_t *)&P4DIR,  // PxDIR
	.cboutTAxSelRegister = (uint8_t *)&P4SEL,  // PxSEL
	.cboutTAxBits = BIT7, // P4.7
	// Timer Information
	.measGateSource = GATE_WDTA_ACLK,
	.accumulationCycles = WDTA_GATE_64
};

