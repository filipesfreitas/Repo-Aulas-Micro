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
//******************************************************************************
//                             MSP430F2132
//                           +---------------+
//                           |
//                           +--<P3.7 
//                           |  
//                           R  
//                           |  
//                       +---+-->P2.3/CA0
//                       |   |  
//                       R   R                
//                       |   |  
//                      GND  +-->P1.0/TACLK
//                           |  
//c-+-------------------+-R--+--<P2.2/CAOUT  
//  |                        |
//  | c-+---------------+-R--+ 
//  |   |                    |
//  |   | c-+-----------+-R--+ 
//  |   |   |                |
//  |   |   | c-+-------+-R--+  
//  |   |   |   |            |
//  |   |   |   | c-+-----R--+  
//  |   |   |   |   |        |
//  |   |   |   |   | c-+-R--+                               
//  |   |   |   |   |   |
//  |   |   |   |   |   +------->P2.7/CA7
//  |   |   |   |   +----------->P2.6/CA6
//  |   |   |   +--------------->P2.5/CA5
//  |   |   +------------------->P2.1/CA3
//  |   +----------------------->P2.0/CA2
//  +--------------------------->P2.4/CA1
//
//******************************************************************************

#include "structure.h"

// P2.0, CA2
const struct Element element0 = {
              .inputBits =  P2CA2,  // CA2
              .maxResponse = 250,
              .threshold = 80
};
//P2.6, CA6
const struct Element element1 = {
              .inputBits = P2CA2+P2CA3, // CA6
              .maxResponse = 300,
              .threshold = 60
};
//P2.7, CA7
const struct Element element2 = {
              .inputBits = P2CA1+P2CA2+P2CA3,  //CA7
              .maxResponse = 280,
              .threshold = 80
};
//P2.5, CA5
const struct Element element3 = {
              .inputBits = P2CA1+P2CA3, //CA5
              .maxResponse = 250,
              .threshold = 60
};
//P2.4, CA1
const struct Element right = {
              .inputBits =  P2CA1,  // CA1
              .maxResponse = 250,
              .threshold = 60
};
//P2.1, CA3
const struct Element left = {
              .inputBits = P2CA1+P2CA2, // CA3
              .maxResponse = 250,
              .threshold = 60
};


//*** Sensor *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

const struct Sensor slider = 
{ 
                  .halDefinition = fRO_COMPAp_TA0_SW,
                  .numElements = 4,
                  .baseOffset = 0,
                  .points = 80,
				  .sensorThreshold = 75,
                  // Pointer to elements
                  .arrayPtr[0] = &element0,  // point to first element 
                  .arrayPtr[1] = &element1,    
                  .arrayPtr[2] = &element2,    
                  .arrayPtr[3] = &element3,    

                  // Reference Information
                  // CAOUT is P2.2
                  // TACLK is P1.0
                  .caoutDirRegister = (uint8_t *)&P2DIR,  // PxDIR
                  .caoutSelRegister = (uint8_t *)&P2SEL,  // PxSEL
                  .txclkDirRegister = (uint8_t *)&P1DIR,  // PxDIR
                  .txclkSelRegister = (uint8_t *)&P1SEL,  // SxSEL
                  .caoutBits = BIT2, // BITy
                  .txclkBits = BIT0,
                  .refPxoutRegister = (uint8_t *)&P3OUT,
                  .refPxdirRegister = (uint8_t *)&P3DIR,
                  .refBits = BIT7,           // BIT7
                  .refCactl2Bits = P2CA0,   // CACTL2-> P2CA0 , CA0
                  .capdBits = (BIT0+BIT3+BIT5+BIT6+BIT7), // P2.0,P2.3,P2.5,
				                                          // P2.6,P2.7
                  
                  // Timer Information
                  .accumulationCycles = 100    // number of relaxation
                                               // oscillator cycles that 
                                               // define measurement period											   
};

const struct Sensor menu = 
{ 
                  .halDefinition = fRO_COMPAp_TA0_SW,
                  .numElements = 2,
                  .baseOffset = 4,  // the first four elements in the baseline
				                    // tracking array are for the slider
                  // Pointer to elements
                  .arrayPtr[0] = &left,  // point to first element 
                  .arrayPtr[1] = &right,    

                  // Reference Information
                  // CAOUT is P2.2
                  // TACLK is P1.0
                  .caoutDirRegister = (uint8_t *)&P2DIR,  // PxDIR
                  .caoutSelRegister = (uint8_t *)&P2SEL,  // PxSEL
                  .txclkDirRegister = (uint8_t *)&P1DIR,  // PxDIR
                  .txclkSelRegister = (uint8_t *)&P1SEL,  // SxSEL
                  .caoutBits = BIT2, // BITy
                  .txclkBits = BIT0,
                  .refPxoutRegister = (uint8_t *)&P3OUT,
                  .refPxdirRegister = (uint8_t *)&P3DIR,
                  .refBits = BIT7,           // BIT7
                  .refCactl2Bits = P2CA0,   // CACTL2-> P2CA0 , CA0
                  .capdBits = (BIT0+BIT1+BIT4), // P2.0,P2.1,P2.4
                  
                  // Timer Information
                  .accumulationCycles = 100    // number of relaxation
                                               // oscillator cycles that 
                                               // define measurement period											   
};
