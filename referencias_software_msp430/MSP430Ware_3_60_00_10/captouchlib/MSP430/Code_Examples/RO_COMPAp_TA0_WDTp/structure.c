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
//
// MSP40F2011
// 4 elements configured as a 64 point slider.
//
//******************************************************************************

#include "structure.h"

// P1.2, CA2
const struct Element element0 = {
              .inputBits =  P2CA2,  // CA2
              .maxResponse = 250,
              .threshold = 80
};
//P1.3, CA3
const struct Element element1 = {
              .inputBits = P2CA1+P2CA2, // CA3
              .maxResponse = 300,
              .threshold = 60
};
//P1.4, CA4
const struct Element element2 = {
              .inputBits = P2CA3,    //CA4
              .maxResponse = 280,
              .threshold = 80
};
//P1.5, CA5
const struct Element element3 = {
              .inputBits = P2CA1+P2CA3, //CA5
              .maxResponse = 250,
              .threshold = 60
};

//*** Sensor         *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

const struct Sensor slider = 
{ 
                  .halDefinition = RO_COMPAp_TA0_WDTp,
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
                  // CAOUT is P1.7
                  // TACLK is P1.0
                  .caoutDirRegister = (unsigned char *)&P1DIR,  // PxDIR
                  .caoutSelRegister = (unsigned char *)&P1SEL,  // PxSEL
                  .txclkDirRegister = (unsigned char *)&P1DIR,  // PxDIR
                  .txclkSelRegister = (unsigned char *)&P1SEL,  // SxSEL
                  .caoutBits = BIT7, // BITy
                  .txclkBits = BIT0,
                  .refPxoutRegister = (unsigned char *)&P1OUT,
                  .refPxdirRegister = (unsigned char *)&P1DIR,
                  .refBits = BIT6,           // BIT6
                  .refCactl2Bits = P2CA4,   // CACTL2-> P2CA4 , CA1
                  .capdBits = (BIT1+BIT2+BIT3+BIT4+BIT5),
                  
                  // Timer Information
                  .measGateSource= GATE_WDT_SMCLK,     //  0->SMCLK, 1-> ACLK
                  //.accumulationCycles= WDTp_GATE_32768                     // 32768
                  //.accumulationCycles= WDTp_GATE_8192                     // 8192
                  .accumulationCycles = WDTp_GATE_512              // 512
                  //.accumulationCycles= WDTp_GATE_64                     // 64                  
};
