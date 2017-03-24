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
 * structure.c
 * 
 * RO_CSIO_TA2_WDTA_One_Button example
 * Touch the middle element to turn on/off the center button LED
 * RO method capactiance measurement using Cap sense IO, TimerA2, and WDT+
 *
 * Also provided RO_CSIO_TA2_TA3_One_Button and fRO_CSIO_TA2_TA3_One_Button 
 * examples. Users can define by themselves which measuring method is used. All 
 * the parameters like threshold are all configured based on specific
 * Launchpad and Boostpack, which may be modified according to user's own 
 * applications.
 *
 * Revised by Holly Gu on March 1st
 */

#include "structure.h"

// Middle Element (P1.5)
const struct Element middle_element = 
{
    .inputBits = CAPSIOPOSEL0 +CAPSIOPISEL2 + CAPSIOPISEL0,   // select 1.5
    /*
     * When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */
    .maxResponse = 900+655,
    .threshold = 900
};

// Up Element (P1.4)
const struct Element up_element = 
{
    .inputBits = CAPSIOPOSEL0 +CAPSIOPISEL2,   // select 1.4
    /*
     * When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */
    .maxResponse = 800+655,
    .threshold = 800
};

// Left Element (P3.5)
const struct Element left_element = 
{
    // select 3.5
    .inputBits = CAPSIOPOSEL1 + CAPSIOPOSEL0 + CAPSIOPISEL2 + CAPSIOPISEL0,   
    /*
     * When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */
    .maxResponse = 700+655,
    .threshold = 700
};

// Right Element (P1.3)
const struct Element right_element = 
{
    .inputBits = CAPSIOPOSEL0 +CAPSIOPISEL1 + CAPSIOPISEL0,   // select 1.3
    /*
     * When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */
    .maxResponse = 700+655,
    .threshold = 700
};

// Down Element (P3.6)
const struct Element down_element = 
{
    .inputBits = CAPSIOPOSEL1 + CAPSIOPOSEL0 + CAPSIOPISEL2 + CAPSIOPISEL1,
    /*
     * When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */
    .maxResponse = 900+655,
    .threshold = 900
};

//PinOsc Wheel
const struct Sensor wheel_buttons =
{
    /****** For RO_CSIO_TA2_WDTA **************/
    .halDefinition = RO_CSIO_TA2_WDTA,
    .inputCapsioctlRegister = (uint16_t *)&CAPSIO0CTL,
    .numElements = 5,
    .baseOffset = 0,
    // Pointer to elements
    .arrayPtr[0] = &up_element,  		// point to up element
    .arrayPtr[1] = &down_element,  		// point to down element
    .arrayPtr[2] = &left_element,  		// point to left element
    .arrayPtr[3] = &right_element,  		// point to right element
    .arrayPtr[4] = &middle_element,  		// point to middle element
    // Timer Information
    .measGateSource= GATE_WDTA_VLO,
    .accumulationCycles= WDTA_GATE_64           // 64 VLO cycles
};

