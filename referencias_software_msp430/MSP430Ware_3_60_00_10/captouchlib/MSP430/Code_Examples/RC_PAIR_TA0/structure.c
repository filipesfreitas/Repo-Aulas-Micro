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
//  RC_PAIR_TA0 example
//
// 4 elements configured as a 64 point slider.  
//
// This file contains the structure names and the variable assingments.
//
//******************************************************************************


#include "structure.h"
//#pragma location="INFOB"

// P1.0 input, P1.1 reference 
const struct Element element0 = {
              .inputPxoutRegister = (uint8_t *)&P1OUT,    
              .inputPxinRegister = (uint8_t *)&P1IN,     
              .inputPxdirRegister = (uint8_t *)&P1DIR,
              .referencePxoutRegister= (uint8_t *)&P1OUT,
              .referencePxdirRegister = (uint8_t *)&P1DIR,     	     
              .referenceBits = BIT1,
              .inputBits =  BIT0,
              .maxResponse = 250,
              .threshold = 80
};
// P1.1 input, P1.0 reference 
const struct Element element1 = {
	      .inputPxoutRegister = (uint8_t *)&P1OUT,    
              .inputPxinRegister = (uint8_t *)&P1IN,     
              .inputPxdirRegister = (uint8_t *)&P1DIR,
              .referencePxoutRegister= (uint8_t *)&P1OUT,
              .referencePxdirRegister = (uint8_t *)&P1DIR,     	     
              .referenceBits = BIT0,
              .inputBits =  BIT1,
              .maxResponse = 250,
              .threshold = 80
};
// P1.2 input, P1.3 reference 
const struct Element element2 = {
              .inputPxoutRegister = (uint8_t *)&P1OUT,    
              .inputPxinRegister = (uint8_t *)&P1IN,     
              .inputPxdirRegister = (uint8_t *)&P1DIR,
              .referencePxoutRegister= (uint8_t *)&P1OUT,
              .referencePxdirRegister = (uint8_t *)&P1DIR,     	     
              .referenceBits = BIT3,
              .inputBits =  BIT2,
              .maxResponse = 250,
              .threshold = 80
};
// P1.3 input, P1.2 reference 
const struct Element element3 = {
              .inputPxoutRegister = (uint8_t *)&P1OUT,    
              .inputPxinRegister = (uint8_t *)&P1IN,     
              .inputPxdirRegister = (uint8_t *)&P1DIR,
              .referencePxoutRegister= (uint8_t *)&P1OUT,
              .referencePxdirRegister = (uint8_t *)&P1DIR,     	     
              .referenceBits = BIT2,
              .inputBits =  BIT3,
              .maxResponse = 250,
              .threshold = 80
};

//*** Sensor *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

const struct Sensor slider = 
{ 
                  .halDefinition = RC_PAIR_TA0,
                  .numElements = 4,
                  .baseOffset = 0,
                  .points = 80,
		  .sensorThreshold = 75,
                  // Pointer to elements
                  .arrayPtr[0] = &element0,  // point to first element 
                  .arrayPtr[1] = &element1,    
                  .arrayPtr[2] = &element2,    
                  .arrayPtr[3] = &element3,    
                  // Timer Information
		  //.measGateSource= TIMER_TxCLK,   // TxCLK
                  //.measGateSource= TIMER_ACLK,    // ACLK
                  .measGateSource= TIMER_SMCLK,     // SMCLK
		  .sourceScale = TIMER_SOURCE_DIV_0,
		  //.sourceScale = TIMER_SOURCE_DIV_1,				  
		  //.sourceScale = TIMER_SOURCE_DIV_2,
		  //.sourceScale = TIMER_SOURCE_DIV_3,
		  .accumulationCycles = 10
};
