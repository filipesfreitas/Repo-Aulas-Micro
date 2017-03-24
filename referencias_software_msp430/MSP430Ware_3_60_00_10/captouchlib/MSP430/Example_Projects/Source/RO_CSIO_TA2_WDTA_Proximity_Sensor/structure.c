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
 * RO_CSIO_TA2_WDTA_One_Button_Proximity_Sensor example
 * Touch the middle element to turn on/off the center button LED
 * RO method capactiance measurement using Cap sense IO, TimerA2, and WDT+
 *
 * Also provided RO_CSIO_TA2_TA3_One_Button and fRO_CSIO_TA2_TA3_One_Button 
 * examples. Users can define by themselves which measuring method is used.
 * All the parameters like threshold are all configured based on specific 
 * Launchpad and Boostpack, which may be modified according to user's 
 * own applications.
 *
 * Revised by Holly Gu on March 1st
 */
#include "structure.h"

// Proximity Element (P3.4)
const struct Element proximity_element = {
    .inputBits = CAPSIOPOSEL0 + CAPSIOPOSEL1 + CAPSIOPISEL2,   // select 3.4

    // When using an abstracted function to measure the element
    // the 100*(maxResponse - threshold) < 0xFFFF
    // ie maxResponse - threshold < 655

    // RO_CSIO_TA2_WDTA  suggested threshold = 400;
    // RO_CSIO_TA2_TA3   suggested threshold = 750;
    // fRO_CSIO_TA2_TA3   suggested threshold = 500;

    .maxResponse = 400+655,
    .threshold = 400
};

//*** CAP TOUCH HANDLER *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

// One Button Sensor
const struct Sensor proximity_sensor =
{ 
    /****** For RO_CSIO_TA2_WDTA **************/
    .halDefinition = RO_CSIO_TA2_WDTA,	// RO_CSIO_TA2_WDTA
    .inputCapsioctlRegister = (uint16_t *)&CAPSIO0CTL,
    .numElements = 1,			// # of Elements
    .baseOffset = 0,			// First element index = 0
    // Pointer to elements
    .arrayPtr[0] = &proximity_element,  	// point to middle element
    // Timer Information
    .measGateSource= GATE_WDTA_VLO,         // Gate Clock Source
    .accumulationCycles= WDTA_GATE_64


    /****** For RO_CSIO_TA2_TA3 **************/
    /*.halDefinition = RO_CSIO_TA2_TA3,	// Sensing Method
    .numElements = 1,			// # of Elements
    .baseOffset = 0,			// First element index = 0
    // Pointer to elements
    .arrayPtr[0] = &proximity_element,  	// point to middle element

    // Timer Information, which determine the Gate Time
    .measGateSource= TIMER_SMCLK,     // Clock Source for the Gate Timer A3
    .sourceScale = TIMER_SOURCE_DIV_3,
    .accumulationCycles= 5000        //CCRx for Timer A3*/

    /****** For fRO_CSIO_TA2_TA3 **************/
    /*.halDefinition = fRO_CSIO_TA2_TA3,	// Sensing Method
    .numElements = 1,			// # of Elements
    .baseOffset = 0,			// First element index = 0
    // Pointer to elements
    .arrayPtr[0] = &proximity_element,  // point to middle element

    // Timer Information, which determine the Gate Time
    .measGateSource= TIMER_SMCLK,     // Clock source for Timer A3
    .sourceScale = TIMER_SOURCE_DIV_0,
    .accumulationCycles= 10000        
    //CCRx for Gate Timer A2, the clock source is by OSC*/

};
