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
;   MSP430FG479 Demo - Timer_B, Toggle P4.6, CCR0 Up Mode ISR, DCO SMCLK
;
;   Description: This program toggles P4.6 using software and TB_0 ISR.
;   Timer_B is configured for up mode, thus the the timer overflows when
;   TBR counts to CCR0. In this example, CCR0 is loaded with 20000.
;   SMCLK provides clock source for TBCLK.
;   ACLK = n/a, MCLK = SMCLK = TBCLK = default DCO
;
;                MSP430FG479
;             -----------------
;         /|\|              XIN|-
;          | |                 |
;          --|RST          XOUT|-
;            |                 |
;            |             P4.6|-->LED
;
;   P.Thanigai
;   Texas Instruments Inc.
;   September 2008
;   Built with Code Composer Essentials Version: 3.0
;******************************************************************************
 .cdecls C,LIST, "msp430.h" 
;------------------------------------------------------------------------------
            .text                           ; Program Start
;------------------------------------------------------------------------------
RESET       mov.w   #0A00h,SP               ; Initialize stack pointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP4     bis.b   #040h,&P4DIR            ; P4.6 output
SetupC0     mov.w   #CCIE,&TBCCTL0          ; TBCCR0 interrupt enabled
            mov.w   #20000,&TBCCR0          ;
SetupTB     mov.w   #TBSSEL_2+MC_1,&TBCTL   ; SMCLK, up mode
                                            ;						
Mainloop    bis.w   #CPUOFF+GIE,SR          ; CPU off, interrupts enabled
            nop                             ; Required only for debugger
                                            ;
;------------------------------------------------------------------------------
TB0_ISR;    Toggle P4.6
;------------------------------------------------------------------------------
            xor.b   #040h,&P4OUT            ; Toggle P4.6
            reti                            ;		
                                            ;
;------------------------------------------------------------------------------
;           Interrupt Vectors
;------------------------------------------------------------------------------
            .sect    ".reset"            	; RESET Vector
            .short   RESET                  ;
            .sect    ".int13"          ; Timer_A0 Vector
            .short   TB0_ISR                 ;
            .end
