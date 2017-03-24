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
 *
 *  Summary
 *     MSP430G2559 target board, custom adapter, and Capacitive Touch Booster Pack
 *
 *  Details
 *     Capacitive Touch Booster Pack: 4 element wheel, middle button, and 
 *     proximity sensor.  MSP430 harware configuration is RO_PINOSC_TA1_WDTp.
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

//PinOsc Volume down P2.2
const struct Element volume_down = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT2,
              // measured for a 1Mhz SMCLK
              .maxResponse = 400+655,	// used for RO_PINOSC_TA1_xxx
              .threshold = 400
};      

//PinOsc forward right P2.3
const struct Element right = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT3,
              // 1Mhz SMCLK
              .maxResponse = 427+655,	// used for RO_PINOSC_TA1_xxx
              .threshold = 427
};

//PinOsc Volume up, P2.4
const struct Element volume_up = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT4,
              // 1Mhz SMCLK
              .maxResponse = 385+655,	// used for RO_PINOSC_TA1_xxx
              .threshold = 385
};      

//PinOsc reverse left P2.1
const struct Element left = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT1,
              // 1Mhz SMCLK
              .maxResponse = 427+655,	// used for RO_PINOSC_TA1_xxx
              .threshold = 427
};      

//PinOsc Wheel: middle button P2.5
const struct Element middle_element = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT5,
              // When using an abstracted function to measure the element
              // the 100*(maxResponse - threshold) < 0xFFFF
              // ie maxResponse - threshold < 655
              .maxResponse = 427+655,	// used for RO_PINOSC_TA1_xxx
              .threshold = 427
}; 

//PinOsc proximity: P2.0
const struct Element proximity_element = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT0,
              .maxResponse = 270,
              .threshold = 200
};      

//*** CAP TOUCH HANDLER *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

const struct Sensor wheel =
               { 
                  .halDefinition = RO_PINOSC_TA1_WDTp,
                  .numElements = 4,
                  .points = 64,
                  .sensorThreshold = 75,
                  .baseOffset = 0,
                  // Pointer to elements
                  .arrayPtr[0] = &volume_up,  // point to first element
                  .arrayPtr[1] = &right,  
                  .arrayPtr[2] = &volume_down,  
                  .arrayPtr[3] = &left,  
                  // Timer Information
                  .measGateSource= GATE_WDT_SMCLK,     //  0->SMCLK, 1-> ACLK
//                  .accumulationCycles= WDTp_GATE_32768             //32768
                  .accumulationCycles= WDTp_GATE_8192               // 8192
                  //.accumulationCycles= WDTp_GATE_512             //512
                  //.accumulationCycles= WDTp_GATE_64             //64                                                
               };

const struct Sensor middle_button =
               { 
                  .halDefinition = RO_PINOSC_TA1_WDTp,
                  .numElements = 1,
                  .baseOffset = 4,
                  // Pointer to elements
                  .arrayPtr[0] = &middle_element,  // point to first element
                  // Timer Information
                  .measGateSource= GATE_WDT_SMCLK,     //  0->SMCLK, 1-> ACLK
//                  .accumulationCycles= WDTp_GATE_32768             //32768
                  .accumulationCycles= WDTp_GATE_8192               // 8192
                  //.accumulationCycles= WDTp_GATE_512             //512
                  //.accumulationCycles= WDTp_GATE_64             //64                  
               };

const struct Sensor proximity_sensor =
               { 
                  .halDefinition = RO_PINOSC_TA1_WDTp,
                  .numElements = 1,
                  .baseOffset = 5,
                  // Pointer to elements
                  .arrayPtr[0] = &proximity_element,  // point to first element
                  // Timer Information
                  .measGateSource= GATE_WDT_SMCLK,     //  0->SMCLK, 1-> ACLK
//                  .accumulationCycles= WDTp_GATE_32768             //32768
                  .accumulationCycles= WDTp_GATE_8192               // 8192
                  //.accumulationCycles= WDTp_GATE_512             //512
                  //.accumulationCycles= WDTp_GATE_64             //64                  
               };



