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
;  MSP430G2x55 Demo - Timer0_A3, Toggle P1.0-3, Cont. Mode ISR, 32kHz ACLK
;
;  Description: Use Timer0_A3 CCRx units and overflow to generate four
;  independent timing intervals. For demonstration, TA0CCR0, TA0CCR1 and TA0CCR2
;  output units are optionally selected with port pins P1.1, P1.2 and P1.3
;  in toggle mode. As such, these pins will toggle when respective TA0CCRx
;  registers match the TA0R counter. Interrupts are also enabled with all
;  TA0CCRx units, software loads offset to next interval only - as long as the
;  interval offset is added to TA0CCRx, toggle rate is generated in hardware.
;  Timer0_A1 overflow ISR is used to toggle P1.0 with software. Proper use
;  of the TA0IV interrupt vector generator is demonstrated.
;  ACLK = TACLK = 32kHz, MCLK = SMCLK = default DCO ~1.2MHz
;  ;* An external watch crystal on XIN XOUT is required for ACLK *;
;
;  As coded and with TA0CLK = 32768Hz, toggle rates are:
;  P1.1 = TA0CCR0 = 32768/(2*4) = 4096Hz
;  P1.2 = TA0CCR1 = 32768/(2*16) = 1024Hz
;  P1.3 = TA0CCR2 = 32768/(2*100) = 163.84Hz
;  P1.0 = overflow = 32768/(2*65536) = 0.25Hz
;
;              MSP430G2x55
;            -----------------
;        /|\|              XIN|-
;         | |                 | 32kHz
;         --|RST          XOUT|-
;           |                 |
;           |         P1.1/TA0|--> TA0CCR0
;           |         P1.2/TA1|--> TA0CCR1
;           |         P1.3/TA2|--> TA0CCR2
;           |             P1.0|--> Overflow/software
;
;  Xiaodong Li
;  Texas Instruments Inc.
;  March 2013
;  Built with Code Composer Studio v5.3
;*******************************************************************************
 .cdecls C,LIST, "msp430.h"
;-------------------------------------------------------------------------------
            .text                           ; Program reset
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section
            .retainrefs                     ; Additionally retain any sections
                                            ; that have references to current
                                            ; section
            .global RESET                   ; Define entry point
;-------------------------------------------------------------------------------
RESET       mov.w   #025Fh,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP1     bis.b   #00Eh,&P1SEL            ; P1.1 - P1.3 option select
            bis.b   #00Fh,&P1DIR            ; P1.0-3 outputs
SetupC0     mov.w   #OUTMOD_4 +CCIE,&TA0CCTL0 ; TA0CCR0 toggle, interrupt enabled
SetupC1     mov.w   #OUTMOD_4 +CCIE,&TA0CCTL1 ; TA0CCR1 toggle, interrupt enabled
SetupC2     mov.w   #OUTMOD_4 +CCIE,&TA0CCTL2 ; TA0CCR2 toggle, interrupt enabled
SetupTA     mov.w   #TASSEL_1+MC_2+TAIE,&TA0CTL   ; ACLK, contmode, interrupt
                                            ;
Mainloop    bis.w   #LPM3+GIE,SR            ; Enter LPM3, interrupts enabled
            nop                             ; Required for debug
                                            ;
;-------------------------------------------------------------------------------
TA0_ISR;
;-------------------------------------------------------------------------------
            add.w   #4,&TA0CCR0             ; Offset until next interrupt
            reti                            ;
                                            ;
;-------------------------------------------------------------------------------
TAX_ISR;    Common ISR for TA0CCR1-2 and overflow
;-------------------------------------------------------------------------------
            add.w   &TA0IV,PC                ; Add Timer_A offset vector
            reti                            ;
            jmp     TA0CCR1_ISR             ; TA0CCR1
            jmp     TA0CCR2_ISR             ; TA0CCR1
            reti                            ;
            reti                            ;
TA_over     xor.b   #001h,&P1OUT            ; Toggle P1.0
            reti                            ; Return from overflow ISR
                                            ;
TA0CCR1_ISR  add.w   #16,&TA0CCR1            ; Offset until next interrupt
            reti                            ; Return ISR
                                            ;
TA0CCR2_ISR  add.w   #100,&TA0CCR2           ; Offset until next interrupt
            reti                            ; Return ISR
                                            ;
;-------------------------------------------------------------------------------
;            Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect    ".reset"                ; MSP430 RESET Vector
            .short    RESET                   ;
            .sect    ".int09"                ; Timer_A0 Vector
            .short    TA0_ISR                 ;
            .sect    ".int08"                ; Timer_AX Vector
            .short    TAX_ISR                 ;
            .end                        
 
