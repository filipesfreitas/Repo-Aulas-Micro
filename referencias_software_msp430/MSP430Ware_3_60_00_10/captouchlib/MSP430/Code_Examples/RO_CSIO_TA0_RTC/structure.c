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
 * RO_CSIO_TA0_RTC_Five_Buttons example for Gradon
 * Touch the five elements to turn on/off the center button LED
 * RO method capactiance measurement using Cap sense IO, TimerA0, and RTC
 *
 * Users can define by themselves which measuring method is used
 * All the parameters like threshold are all configured based on specific 
 * Wolverine Launchpad and Boostpack, which may be modified according to user's 
 * own applications.
 *
 * Revised by Eric Fu on May 2nd
 */

#include "structure.h"

// Middle Element (P1.3)
const struct Element middle_element = 
{
    .inputBits = CAPSIOPOSEL0 + CAPSIOPISEL1 + CAPSIOPISEL0,  // select 1.4

    /* When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */

    .maxResponse = 100+655,
    .threshold = 100
};

const struct Element up_element =
{
    .inputBits = CAPSIOPOSEL0 + CAPSIOPISEL2,  // select 1.4

    /* When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */

    .maxResponse = 50+655,
    .threshold = 50
};

const struct Element right_element =
{
    .inputBits = CAPSIOPOSEL0 + CAPSIOPISEL2 + CAPSIOPISEL0,  // select 1.5

    /* When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */

    .maxResponse = 100+655,
    .threshold = 100
};

const struct Element down_element =
{
    .inputBits = CAPSIOPOSEL3 + CAPSIOPISEL1 + CAPSIOPISEL0,  // select 8.3

    /* When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */

    .maxResponse = 100+655,
    .threshold = 100
};

const struct Element left_element =
{
    .inputBits = CAPSIOPOSEL3 + CAPSIOPISEL1,  // select 8.2

    /* When using an abstracted function to measure the element
     * the 100*(maxResponse - threshold) < 0xFFFF
     * ie maxResponse - threshold < 655
     */

    .maxResponse = 100+655,
    .threshold = 100
};


// One Button Sensor
const struct Sensor one_button =
{ 

	/****** For RO_CSIO_TA0_RTC **************/
    .halDefinition = RO_CSIO_TA0_RTC,
	.inputCapsioctlRegister = (uint16_t *)&CAPSIO0CTL,
	.numElements = 5,
	.baseOffset = 0,
	// Pointer to elements
	.arrayPtr[0] = &middle_element,  		// point to middle element
	.arrayPtr[1] = &up_element,  		// point to up element
	.arrayPtr[2] = &right_element,  		// point to right element
	.arrayPtr[3] = &down_element,  		// point to down element
	.arrayPtr[4] = &left_element,  		// point to left element

	// Timer Information, which determine the Gate Time
	.measGateSource= GATE_RTC_SMCLK,     // Clock source for RTC
	.sourceScale = RTC_DIV_10,
	.accumulationCycles= 1024

};
