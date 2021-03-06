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
;   MSP-FET430P410 Demo - Timer_A, Output DTMF, Cont. Mode, DCO SMCLK
;
;   Description: This program outputs two tones on P1.2 and P2.0 using
;   Timer_A configured for continuous mode. The outputs toggle at 2x the
;   required frequency, thus producing a square wave the the target
;   frequencies. The index value (0, 2, 4, or 6) in R4 points to low a
;   frequency value stored in DTMF_TABlo, the index in R5 points to a high
;   frequency value stored in DTMF_TABhi.
;   ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
;   ;* An external watch crystal between XIN & XOUT is required for ACLK *//	
;
;                 MSP430F413
;             -----------------
;         /|\|              XIN|-
;          | |                 | 32kHz
;          --|RST          XOUT|-
;            |                 |
;            |         P1.2/TA1|--> DTMF_lo
;            |         P2.0/TA2|--> DTMF_hi
;
;   M. Buccini / S. Karthikeyan
;   Texas Instruments Inc.
;   May 2005
;   Built with Code Composer Essentials Version 1.0
;******************************************************************************
 .cdecls C,LIST,  "msp430.h"

DTMF_lo     .equ    0200h
DTMF_hi     .equ    0202h
MCLK        .equ    1048576

;------------------------------------------------------------------------------
            .text                  ; Program Start
;------------------------------------------------------------------------------
RESET       mov.w   #300h,SP                ; Initialize stackpointer
            call    #Init_Sys               ; Initialize System Peripherals
            clr.w   R4                      ;
            clr.w   R5                      ;
                                            ;
Mainloop    call    #Send_DTMF              ;
            jmp     $                       ;
                                            ;
;-----------------------------------------------------------------------------
Send_DTMF
;-----------------------------------------------------------------------------
            mov.w   DTMF_TABlo(R4),&DTMF_lo  ;
            mov.w   DTMF_TABhi(R5),&DTMF_hi  ;
SetupC1     mov.w   #OUTMOD2+CCIE,&CCTL1    ; CCR1 toggle, interrupt
SetupC2     mov.w   #OUTMOD2+CCIE,&CCTL2    ; CCR2 toggle, interrupt
            push.w  &TAR                    ; Delay until DTMF start
            add.w   #000FFh,0(SP)           ;
            mov.w   0(SP),&CCR1             ;
            pop.w   &CCR2                   ;
            ret                             ;
                                            ;
;-----------------------------------------------------------------------------
Init_Sys;   Initialize System Peripherals
;-----------------------------------------------------------------------------
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupFLL    bis.b   #XCAP14PF,&FLL_CTL0     ; Configure load caps
SetupTA     mov.w   #TASSEL1+MC1,&TACTL     ; SMCLK, continuous mode
SetupP1     bis.b   #004h,&P1DIR            ; P1.2 output
            bis.b   #004h,&P1SEL            ; P1.2 TA1 output
SetupP2     bis.b   #001h,&P2DIR            ; P2.0 output
            bis.b   #001h,&P2SEL            ; P2.0 TA2 output
            eint                            ;
            ret                             ; Return from subroutine
                                            ;
;-----------------------------------------------------------------------------
TAX_ISR;    Common ISR - CCR1-4 and overflow
;-----------------------------------------------------------------------------
            add.w   &TAIV,PC                ; Add offset to jump table
            reti                            ; Vector 0 - no interrupt
            jmp     TA1_ISR                 ; CCR1
            jmp     TA2_ISR                 ; CCR2
            reti                            ; Vector 6 - reserved
            reti                            ; Vector 8 - reserved
            reti                            ; TAIFG - no source
                                            ;
TA1_ISR     add.w   &DTMF_lo,&CCR1          ;
            reti                            ;
                                            ;
TA2_ISR     add.w   &DTMF_hi,&CCR2          ;
            reti                            ;
                                            ;
            .align 2                        ;
DTMF_TABlo  .short  ((MCLK/697)+1)/2        ; Generates 697 Hz
            .short  ((MCLK/770)+1)/2        ; Generates 770 Hz
            .short  ((MCLK/852)+1)/2        ; Generates 852 Hz
            .short  ((MCLK/941)+1)/2        ; Generates 941 Hz
DTMF_TABhi  .short  ((MCLK/1209)+1)/2       ; Generates 1209 Hz
            .short  ((MCLK/1336)+1)/2       ; Generates 1336 Hz
            .short  ((MCLK/1477)+1)/2       ; Generates 1477 Hz
            .short  ((MCLK/1633)+1)/2       ; Generates 1633 Hz
                                            ;
;-----------------------------------------------------------------------------
;           Interrupt Vectors
;-----------------------------------------------------------------------------
            .sect   ".reset"                ; RESET Vector
            .short  RESET                   ;
            .sect   ".int05"                ; Timer_AX Vector
            .short  TAX_ISR                 ;
            .end
