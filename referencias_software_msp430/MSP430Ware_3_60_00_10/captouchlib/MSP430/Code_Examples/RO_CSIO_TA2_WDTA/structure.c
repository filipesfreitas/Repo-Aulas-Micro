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
 *  RO_CSIO_TA2_WDTA example 
 *
 *  Schematic Description:
 *
 *                         MSP430FR5969
 *                      +---------------+
 *                      |               |
 *          LED0--------|P4.2       P1.2|--------LED3
 *          LED1--------|P2.4       P3.0|--------LED4
 *          LED2--------|P2.2       P1.7|--------LED5
 *                      |               |
 *          key0--------|P3.4       P1.5|--------key3
 *          key1--------|P3.5       P1.4|--------key4
 *          key2--------|P3.6       P1.3|--------key5
 * 
 *  The threshold and maxResponse values must be updated for electrode design,
 *  system clock settings, and selection of gate time (source and accumulation
 *  cycles).  In this example the gate time is very short sine there is no 
 *  overlay material on the pcb.
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

// P3.4
const struct Element key0 =
{
    .inputBits = CAPSIOPOSEL0+CAPSIOPOSEL1+CAPSIOPISEL2,
    .maxResponse = 350,
    .threshold = 120
};
// P3.5
const struct Element key1 =
{
    .inputBits = CAPSIOPOSEL0+CAPSIOPOSEL1+CAPSIOPISEL0+CAPSIOPISEL2,
    .maxResponse = 380,
    .threshold = 210
};
// P3.6
const struct Element key2 =
{
    .inputBits = CAPSIOPOSEL0+CAPSIOPOSEL1+CAPSIOPISEL1+CAPSIOPISEL2,
    .maxResponse = 350,
    .threshold = 120
};
// P1.3
const struct Element key5 =
{
    .inputBits = CAPSIOPOSEL0+CAPSIOPISEL0+CAPSIOPISEL1,
    .maxResponse = 310,
    .threshold = 160
};
// P1.4
const struct Element key4 =
{
    .inputBits = CAPSIOPOSEL0+CAPSIOPISEL2,
    .maxResponse = 350,
    .threshold = 150   //
};
// P1.5
const struct Element key3 =
{
    .inputBits = CAPSIOPOSEL0+CAPSIOPISEL0+CAPSIOPISEL2,
    .maxResponse = 330,
    .threshold = 140
}; 

const struct Sensor keyPad =
{
    .halDefinition = RO_CSIO_TA2_WDTA,
    .inputCapsioctlRegister = (uint16_t *)&CAPSIO0CTL,
    .numElements = 6,
    .baseOffset = 0,
    // Pointer to elements
    .arrayPtr[0] = &key0,
    .arrayPtr[1] = &key1,
    .arrayPtr[2] = &key2,
    .arrayPtr[3] = &key3,
    .arrayPtr[4] = &key4,
    .arrayPtr[5] = &key5,
    .measGateSource = GATE_WDTA_SMCLK,
    .accumulationCycles = WDTA_GATE_64
};

