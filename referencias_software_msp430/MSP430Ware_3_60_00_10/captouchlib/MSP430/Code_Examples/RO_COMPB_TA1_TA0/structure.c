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
 *  RO_COMPB_TA1_TA0 example with the MSP430F5529 Experimenters Board
 *
 *  Schematic
 *   PAD5-+-----------------------------R--+--<P1.6/TA1CLK/CBOUT
 *        |                                |
 *        | PAD4-+----------------------R--+
 *        |      |                         |
 *        |      | PAD3-+---------------R--+
 *        |      |      |                  |
 *        |      |      | PAD2-+--------R--+
 *        |      |      |      |           |
 *        |      |      |      | PAD1-+-R--+
 *        |      |      |      |      |
 *        |      |      |      |      +------->CB0
 *        |      |      |      +-------------->CB1
 *        |      |      +--------------------->CB2
 *        |      +---------------------------->CB3
 *        +----------------------------------->CB4
 *
 *  In this example the five pads on the experimenter's board are grouped
 *  together in the sensor keypad.
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
 * The element defines the input of the comparator mux, the maximum response, 
 * and the threshold. The threshold and maxResponse values are based upon the gate time, defined
 * in the keypad sensor definition.  In this example the gate time is 1.5ms.
 */
const struct Element PAD1 = 
{   //CB0
    .inputBits = CBIMSEL_0,
    .maxResponse = 250,
    .threshold = 125
};
const struct Element PAD2 = 
{   //CB1
    .inputBits = CBIMSEL_1,
    .maxResponse = 390,
    .threshold = 195
};
const struct Element PAD3 = 
{   //CB2
    .inputBits = CBIMSEL_2,
    .maxResponse = 340,
    .threshold = 170
};
const struct Element PAD4 = 
{   //CB3
    .inputBits = CBIMSEL_3,
    .maxResponse = 500,
    .threshold = 230
};
const struct Element PAD5 = 
{   //CB4
    .inputBits = CBIMSEL_4,
    .maxResponse = 400,
    .threshold = 200
};
/*
 *  The sensor defines the grouping of elements, the method to measure change in
 *  capacitance, and the measurement time of each element.
 */
const struct Sensor keypad =
{
    .halDefinition = RO_COMPB_TA1_TA0,
    .numElements = 5,
    .baseOffset = 0,
    .cbpdBits = 0x001F, //CB0,CB1,CB2,CB3,CB4
    .arrayPtr[0] = &PAD1,
    .arrayPtr[1] = &PAD2,
    .arrayPtr[2] = &PAD3,
    .arrayPtr[3] = &PAD4,
    .arrayPtr[4] = &PAD5,
    .cboutTAxDirRegister = (uint8_t *)&P1DIR,  // PxDIR
    .cboutTAxSelRegister = (uint8_t *)&P1SEL,  // PxSEL
    .cboutTAxBits = BIT6, // P1.6
    // Timer Information
    .measGateSource = TIMER_ACLK,      //  ACLK
    .sourceScale = TIMER_SOURCE_DIV_0, // ACLK/1
    /*  50 ACLK/1 cycles or 50*1/32Khz = 1.5ms  */
    .accumulationCycles = 50
};

