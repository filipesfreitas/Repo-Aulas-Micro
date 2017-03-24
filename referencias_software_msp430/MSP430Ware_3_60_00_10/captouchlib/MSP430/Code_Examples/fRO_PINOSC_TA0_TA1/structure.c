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
 *  fRO_PINOSC_TA0_TA1 implementation using a single proximity element and LED.
 *
 *          Schematic Description:
 *
 *                         MSP430F2553
 *                      +---------------+
 *                      |               |
 *          LED0--------|P1.0           |
 *                      |               |
 *          eProx-------|P2.2           |
 *
 *  The threshold and maxResponse values must be updated for electrode design,
 *  system clock settings, and selection of gate time (source and accumulation
 *  cycles).
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
/* fRO_PINOSC_TA0_TA1 on P2.2. One proximity sensor */
/* 
 * The element defines the input of the port sel registers 1 and 2, the bit 
 * definition, the maximum response, and the threshold. The threshold and 
 * maxResponse values are based upon the gate time, defined in the keypad 
 * sensor definition.  In this example the gate time is 10ms.
 */
const struct Element eProx = 
{
    .inputPxselRegister = (uint8_t *)&P2SEL,
    .inputPxsel2Register = (uint8_t *)&P2SEL2,
    .inputBits = BIT2,
    /* maxResponse is not Used in this application */
    .maxResponse = 0,
    .threshold = 100
}; 
/*
 *  The sensor defines the grouping of elements, the method to measure change in
 *  capacitance, and the measurement time of each element.
 */
const struct Sensor proximity =
{ 
    /* Gate source is INCLK by default */
    .halDefinition = fRO_PINOSC_TA0_TA1,
    .numElements = 1,
    .baseOffset = 0,
    .arrayPtr[0] = &eProx,
    /* Measurement Source is SMCLK */
    .measGateSource = TIMER_SMCLK,
    /* Gate Source divided by 1 */
    .sourceScale = TIMER_SOURCE_DIV_0,
    .accumulationCycles = 11000
};
