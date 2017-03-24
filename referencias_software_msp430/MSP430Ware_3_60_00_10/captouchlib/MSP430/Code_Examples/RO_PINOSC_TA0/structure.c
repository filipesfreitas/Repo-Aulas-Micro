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
//                         MSP430G2452
//                      +---------------+
//                      |
//             C--------|P1.0
//             C--------|P1.1
//             C--------|P1.2
//             C--------|P1.3
//             C--------|P1.4
//             C--------|P1.5
//                      |
//           C----------|P2.0
//           C----------|P2.1
//           C----------|P2.2
//           C----------|P2.3
//           C----------|P2.4
//           C----------|P2.5
//                      |
//           C----------|P2.6
//           C----------|P2.7
//
//******************************************************************************

#include "structure.h"

//PinOsc P1.0
const struct Element element0 = {

              .inputPxselRegister = (uint8_t *)&P1SEL,  
              .inputPxsel2Register = (uint8_t *)&P1SEL2,  
              .inputBits = BIT0,
              .maxResponse = 121+655, 
              .threshold = 121 

};     

const struct Element element1 = {

              .inputPxselRegister = (uint8_t *)&P1SEL,  
              .inputPxsel2Register = (uint8_t *)&P1SEL2,  
              .inputBits = BIT1,
              .maxResponse = 121+655, 
              .threshold = 121 

};  
    
const struct Element element2 = {

              .inputPxselRegister = (uint8_t *)&P1SEL,  
              .inputPxsel2Register = (uint8_t *)&P1SEL2,  
              .inputBits = BIT2,
              .maxResponse = 121+655, 
              .threshold = 121 

};  
    
const struct Element element3 = {

              .inputPxselRegister = (uint8_t *)&P1SEL,  
              .inputPxsel2Register = (uint8_t *)&P1SEL2,  
              .inputBits = BIT3,
              .maxResponse = 121+655, 
              .threshold = 121 

};      

const struct Element element4 = {

              .inputPxselRegister = (uint8_t *)&P1SEL,  
              .inputPxsel2Register = (uint8_t *)&P1SEL2,  
              .inputBits = BIT4,
              .maxResponse = 121+655, 
              .threshold = 121 

};  
    
const struct Element element5 = {

              .inputPxselRegister = (uint8_t *)&P1SEL,  
              .inputPxsel2Register = (uint8_t *)&P1SEL2,  
              .inputBits = BIT5,
              .maxResponse = 121+655, 
              .threshold = 121 

};  
//PinOsc P2.0
const struct Element element6 = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT0,
              .maxResponse = 121+655, 
              .threshold = 121 

};     
const struct Element element7 = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT1,
              .maxResponse = 121+655, 
              .threshold = 121 

};  
const struct Element element8 = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT2,
              .maxResponse = 121+655, 
              .threshold = 121 

};  
const struct Element element9 = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT3,
              .maxResponse = 121+655, 
              .threshold = 121 

};      
const struct Element elementA = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT4,
              .maxResponse = 121+655, 
              .threshold = 121 

};  
const struct Element elementB = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT5,
              .maxResponse = 121+655, 
              .threshold = 121 

};  
const struct Element elementC = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT6,
              .maxResponse = 121+655, 
              .threshold = 121 

};      
const struct Element elementD = {

              .inputPxselRegister = (uint8_t *)&P2SEL,  
              .inputPxsel2Register = (uint8_t *)&P2SEL2,  
              .inputBits = BIT7,
              .maxResponse = 121+655, 
              .threshold = 121 

};      


//*** Sensor     *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

const struct Sensor keypad =
               { 
                  .halDefinition = fRO_PINOSC_TA0_SW,
                  .numElements = 14,
                  .baseOffset = 0,
                  // Pointers to elements
                  .arrayPtr[0] = &element0,  
				  .arrayPtr[1] = &element1,  
                  .arrayPtr[2] = &element2,  
                  .arrayPtr[3] = &element3,  
                  .arrayPtr[4] = &element4,  
                  .arrayPtr[5] = &element5,  
                  .arrayPtr[6] = &element6,  
                  .arrayPtr[7] = &element7,  
                  .arrayPtr[8] = &element8,  
                  .arrayPtr[9] = &element9,  
                  .arrayPtr[10] = &elementA,  
                  .arrayPtr[11] = &elementB,  
                  .arrayPtr[12] = &elementC,  
				  .arrayPtr[13] = &elementD,  

                  // Timer Information
                  .accumulationCycles= 100   //number of ACLK cycles              
               };
