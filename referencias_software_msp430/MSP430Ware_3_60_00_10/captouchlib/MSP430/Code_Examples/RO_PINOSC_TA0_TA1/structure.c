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
 *  RO_PINOSC_TA0_TA1 implementation using 6 buttons and 6 leds.
 *
 *          Schematic Description:
 *
 *                         MSP430F2553
 *                      +---------------+
 *                      |               |
 *          LED0--------|P1.0       P2.6|--------LED5
 *          LED1--------|P1.4       P2.7|--------LED4
 *          LED2--------|P1.5       P1.6|--------LED3
 *                      |               |
 *          key0--------|P1.0       P1.5|--------key5
 *          key1--------|P1.4       P1.4|--------key4
 *          key2--------|P3.6       P1.3|--------key3
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
/* RO_PINOSC_TA0_TA1 on P2.2. One proximity sensor. */
/* 
 * The element defines the input of the port sel registers 1 and 2, the bit 
 * definition, the maximum response, and the threshold. The threshold and 
 * maxResponse values are based upon the gate time, defined in the keypad 
 * sensor definition.  In this example the gate time is 11ms.
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
    .halDefinition = RO_PINOSC_TA0_TA1,
    .numElements = 1,
    .baseOffset = 0,
    .arrayPtr[0] = &eProx,
    /* Timer Information, Gate Source is SMCLK */
    .measGateSource = TIMER_SMCLK,
    /* Gate Source divided by 1 */
    .sourceScale = TIMER_SOURCE_DIV_0,
    .accumulationCycles = 11000  // Number of TimerA0 (RO) cycles
};

/* RO_PINOSC_TA0_TA1 on P2.0, 2.1, 2.2, 2.3, 2.4, 2.5. 6 button keypad. */
const struct Element key0 = 
{
    .inputPxselRegister = (uint8_t *)&P2SEL,
	.inputPxsel2Register = (uint8_t *)&P2SEL2,
	.inputBits = BIT0,
	.maxResponse = 300,
	.threshold = 100
};
// P2.1
const struct Element key1 = 
{
    .inputPxselRegister = (uint8_t *)&P2SEL,
    .inputPxsel2Register = (uint8_t *)&P2SEL2,
    .inputBits = BIT1,
    .maxResponse = 300,
    .threshold = 100
};
// P2.2
const struct Element key2 = 
{
    .inputPxselRegister = (uint8_t *)&P2SEL,
    .inputPxsel2Register = (uint8_t *)&P2SEL2,
    .inputBits = BIT2,
    .maxResponse = 300,
    .threshold = 100
};
// P2.3
const struct Element key3 = 
{
    .inputPxselRegister = (uint8_t *)&P2SEL,
    .inputPxsel2Register = (uint8_t *)&P2SEL2,
    .inputBits = BIT3,
    .maxResponse = 300,
    .threshold = 100
};
// P2.4
const struct Element key4 = 
{
    .inputPxselRegister = (uint8_t *)&P2SEL,
    .inputPxsel2Register = (uint8_t *)&P2SEL2,
    .inputBits = BIT4,
    .maxResponse = 300,
    .threshold = 100
};
// P2.5
const struct Element key5 = 
{
    .inputPxselRegister = (uint8_t *)&P2SEL,
    .inputPxsel2Register = (uint8_t *)&P2SEL2,
    .inputBits = BIT5,
    .maxResponse = 300,
    .threshold = 100
};
const struct Sensor keypad =
{
    .halDefinition = RO_PINOSC_TA0_TA1,
    .numElements = 6,
    .baseOffset = 1,
    // Pointer to elements
    .arrayPtr[0] = &key0,
    .arrayPtr[1] = &key1,
    .arrayPtr[2] = &key2,
    .arrayPtr[3] = &key3,
    .arrayPtr[4] = &key4,
    .arrayPtr[5] = &key5,
    /*
     * Timer Information
     * Measurement source is INCLK by HAL definition.
     * Gate Source is defined by measGateSource.
     */
    .measGateSource = TIMER_SMCLK,
    /* Gate Source divided by 1 */
    .sourceScale = TIMER_SOURCE_DIV_0,
    .accumulationCycles = 1000  // Number of TimerA1 cycles
};
