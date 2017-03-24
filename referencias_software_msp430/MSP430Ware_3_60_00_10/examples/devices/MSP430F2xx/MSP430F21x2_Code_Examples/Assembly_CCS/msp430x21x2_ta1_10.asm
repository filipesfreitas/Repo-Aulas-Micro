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
;******************************************************************************
;  MSP430F21x2 Demo - Timer1_A, Toggle P3.6/TA0_1, Up Mode, DCO SMCLK
;
;  Description: Toggle P3.6 using hardware TA0_1 output. Timer1_A is configured
;  for up mode with TA1CCR0 defining period. In this
;  example, TA1CCR0 is loaded with 500-1 and TA0_1 will toggle P3.6 at TA1CLK/500.
;  Thus the output frequency on P3.6 will be TA1CLK/1000. No CPU or software
;  resources required.
;  As coded with TA1CLK = SMCLK, P3.6 output frequency is ~1200000/1000.
;  SMCLK = MCLK = TA1CLK = default DCO ~1.2MHz
;
;            MSP430F21x2
;         -----------------
;     /|\|              XIN|-
;      | |                 |
;      --|RST          XOUT|-
;        |                 |
;        |       P3.6/TA0_1|--> SMCLK/1000
;
;  JL Bile
;  Texas Instruments Inc.
;  May 2008
;  Built with Code Composer Essentials: v3 FET
;*******************************************************************************
 .cdecls C,LIST, "msp430.h"
;-------------------------------------------------------------------------------
 			.text							; Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #025Fh,SP         		; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP3     bis.b   #040h,&P3DIR            ; P1.1 output
            bis.b   #040h,&P3SEL            ; P1.1 option slect
SetupC0     mov.w   #OUTMOD_4,&TA1CCTL0     ; TA1CCR0 toggle, upmode
            mov.w   #500-1,&TA1CCR0         ;
SetupTA     mov.w   #TASSEL_2+MC_1,&TA1CTL  ; SMCLK, clear TAR
                                            ;
Mainloop    bis.w   #CPUOFF,SR              ; CPU off
            nop                             ; Required only for debugger
                                            ;
;-------------------------------------------------------------------------------
;			Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect	".reset"				; MSP430 RESET Vector
            .short	RESET                   ;
            .end