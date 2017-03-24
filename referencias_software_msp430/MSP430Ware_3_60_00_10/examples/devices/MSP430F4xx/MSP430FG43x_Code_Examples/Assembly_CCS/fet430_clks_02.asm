; --COPYRIGHT--,BSD_EX
;  Copyright (c) 2012, Texas Instruments Incorporated
;  All rights reserved.
; 
;  Redistribution and use in source and binary forms, with or without
;  modification, are permitted provided that the following conditions
;  are met:
; 
;  *  Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
; 
;  *  Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the distribution.
; 
;  *  Neither the name of Texas Instruments Incorporated nor the names of
;     its contributors may be used to endorse or promote products derived
;     from this software without specific prior written permission.
; 
;  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
;  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
;  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
;  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
;  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
;  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
;  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
;  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
;  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; ******************************************************************************
;  
;                        MSP430 CODE EXAMPLE DISCLAIMER
; 
;  MSP430 code examples are self-contained low-level programs that typically
;  demonstrate a single peripheral function or device feature in a highly
;  concise manner. For this the code may rely on the device's power-on default
;  register values and settings such as the clock configuration and care must
;  be taken when combining code from several examples to avoid potential side
;  effects. Also see www.ti.com/grace for a GUI- and www.ti.com/msp430ware
;  for an API functional library-approach to peripheral configuration.
; 
; --/COPYRIGHT--
;*******************************************************************************
;   MSP-FET430P430 Demo - FLL+, Output 32kHz Xtal + HF Xtal + Internal DCO
;
;   Description: This program demonstrates using an external 32kHz crystal to
;   supply the internal ACLK, and using a high speed crystal or resonator to
;   supply SMCLK. The MLCK for the CPU is supplied by the DCO. The 32kHz
;   crystal connects between pins XIN and XOUT. The high frequency crystal
;   or resonator connects bwteen pins XT2IN and XT2OUT. The DCO clock is
;   generated internally and calibrated from the 32kHz crystal. ACLK is
;   brought out on P1.5, SMCLK is brought out on P1.4, and MCLK on pin P1.1.
;   ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
;   ;* An external watch crystal between XIN & XOUT is required for ACLK *//	
;
;   NOTE: External matching capacitors must be added for the high speed
;         crystal or resonator as required.
;   ;* External XTALs required and not installed on FET *//	
;
;                MSP430FG439
;             -----------------
;        /|\ |              XIN|-
;         |  |                 | 32kHz crystal
;         ---|RST          XOUT|-
;            |                 |
;            |            XT2IN|-
;            |                 | XTAL (455k - 8Mhz) (add caps as needed)
;            |           XT2OUT|-
;            |                 |
;            |        P1.1/MCLK|--> MCLK = 1048576 Hz
;            |       P1.4/SMCLK|--> SMCLK = HF XTAL
;            |        P1.5/ACLK|--> ACLK = 32kHz
;
;   M. Buccini / M. Mitchell
;   Texas Instruments Inc.
;   May 2005
;   Built with Code Composer Essentials Version: 1.0
;******************************************************************************
 .cdecls C,LIST,  "msp430.h"
;-------------------------------------------------------------------------------
            .text                  ; Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #0A00h,SP               ; Initialize stack pointer
SetupWDT    mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupFLL2   bis.b   #XCAP18PF,&FLL_CTL0     ; .set load capacitance for 32k xtal
SetupHF     bic.b   #XT2OFF,&FLL_CTL1       ; Clear bit = high freq xtal on
ClearFlag   bic.b   #OFIFG,&IFG1            ; Clear osc fault flag
            mov     #0F000h,R15             ; Move delay time to register 15
HF_Wait     dec     R15                     ; Delay for xtal to start, FLL lock
            jnz     HF_Wait		            ; Loop if delay not finished
            bit.b   #OFIFG,&IFG1            ; Test osc fault flag
            jnz     ClearFlag               ; If not loop again
SwitchHF    bis.b   #SELS,&FLL_CTL1         ; Is reset so switch SMCLK = HF xtal
                                            ;
SetupPorts  bis.b   #032h,&P1DIR            ; P1.1, P1.4 & P1.5 to outputs
            bis.b   #032h,&P1SEL            ; P1.1, P1.4 & P1.5 functions
                                            ; Set to output
                                            ; MCLK, SMCLK & ACLK
Mainloop    jmp     Mainloop                ; Loop with CPU running
                                            ;
;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; RESET Vector
            .short  RESET                   ;
            .end