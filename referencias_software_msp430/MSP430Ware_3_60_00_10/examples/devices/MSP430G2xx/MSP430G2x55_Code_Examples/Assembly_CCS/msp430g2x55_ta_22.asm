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
;   MSP430G2x55 Demo - Timer_A, Ultra-Low Pwr Pulse Accumulator
;
;   Description: Timer_A is used as ultra-low power pulse counter. In this
;   example TAR is offset 100 counts, which are acculmulated on INCLK P2.1,
;   with the system in LPM4 - all internal clocks off. After 100 counts, TAR
;   will overflow requesting an interrupt, and waking the system. Timer_A is
;   then reconfigured with SMCLK as clock source in up mode - TACCR1 will then
;   toggle P1.0 every 50000 SMCLK cycles. SMCLK is then configured to operate
;   at default DCO value.
;
;                MSP430G2x55
;             -----------------
;         /|\|              XIN|-
;          | |                 |
;          --|RST          XOUT|-
;            |                 |
;        --->|P2.1/TAINCLK P1.0|-->LED
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
RESET       mov.w   #025Fh,SP                 ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP1     mov.b   #0FFh,&P1DIR            ; All P1.x outputs
            clr.b   &P1OUT                  ; All P1.x reset
SetupP2     mov.b   #0FDh,&P2DIR            ; All but P2.1 outputs
            mov.b   #002h,&P2SEL            ; P2.1 TAINCLK option select
            clr.b   &P2OUT                  ; All P2.x reset
SetupP3     mov.b   #0FFh,&P3DIR            ; All P3.x outputs
            clr.b   &P3OUT                  ; All P3.x reset
SetupTA     mov.w   #TASSEL1+TASSEL0+TACLR+TAIE,&TA0CTL  ; Ext. INCLK, interrupt
            mov.w   #0FFFFh-100,&TA0R        ; Offset until TAR overflow
            bis.w   #MC1,&TA0CTL             ; Start Timer_A continuous mode
            bis.w   #LPM4+GIE,SR            ; Enter LPM4 w/ interrupts
                                            ;
Mainloop    xor.b   #001h,&P1OUT            ; P1.0 = toggle
            bis.w   #CPUOFF,SR              ; CPU is not required
            jmp     Mainloop                ; Repeat
                                            ;
;-------------------------------------------------------------------------------
TAX_ISR;    Common ISR for TACCR1 and overflow
;-------------------------------------------------------------------------------
            add.w   &TA0IV,PC                ; Add Timer_A offset vector
            reti                            ;
            jmp     TACCR1_ISR              ; TA0CCR1
            reti                            ;
            reti                            ;
            reti                            ;
TA_over     mov.w   #TASSEL1+TACLR,&TA0CTL   ; SMCLK, clear TAR
SetupC1     mov.w   #CCIE,&TA0CCTL1          ; TA0CCR1 interrupt enabled
            mov.w   #50000,&TA0CCR1          ;
            bis.w   #MC1,&TA0CTL             ; Start Timer_A in continuous
            bic.w   #LPM4,0(SP)             ; Exit LPM4 on reti
            reti                            ; Return from overflow ISR
                                            ;
TACCR1_ISR  add.w   #50000,&TA0CCR1          ; Offset until next interrupt
            bic.w   #CPUOFF,0(SP)           ; CPU active on reti
            reti                            ; Return from TA0CCR1 ISR
                                            ;
;-------------------------------------------------------------------------------
;            Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect    ".reset"                ; MSP430 RESET Vector
            .short    RESET                   ;
            .sect    ".int08"                ; Timer_AX Vector
            .short    TAX_ISR                 ;
            .end
