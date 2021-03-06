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
;   MSP430F23x0 Demo - Timer_A, Toggle P1.0-3, Cont. Mode ISR, HF XTAL ACLK
;
;   Description: Use Timer_A CCRx units and overflow to generate four
;   independent timing intervals. For demonstration, TACCR0, TACCR1 and TACCR2
;   output units are optionally selected with port pins P1.1, P1.2 and P1.3
;   in toggle mode. As such, these pins will toggle when respective TACCRx
;   registers match the TAR counter. Interrupts are also enabled with all
;   TACCRx units, software loads offset to next interval only - as long as the
;   interval offset is added to TACCRx, toggle rate is generated in hardware.
;   Timer_A overflow ISR is used to toggle P1.0 with software. Proper use
;   of the TAIV interrupt vector generator is demonstrated.
;   ACLK = MCLK = TACLK = LFXT1 = HF XTAL
;   //* Min Vcc required varies with MCLK frequency - refer to datasheet *//
;
;   As coded with TACLK= HF XTAL and assuming HF XTAL = 8MHz, toggle rates are:
;   P1.1 = TACCR0 = 8MHz/(2*200) = 20kHz
;   P1.2 = TACCR1 = 8MHz/(2*1000) = 4kHz
;   P1.3 = TACCR2 = 8MHz/(2*10000) = 400Hz
;   P1.0 = overflow = 8MHz/(2*65536) = 61Hz
;
;                MSP430F23x0
;             -----------------
;         /|\|              XIN|-
;          | |                 | HF XTAL (3  16MHz crystal or resonator)
;          --|RST          XOUT|-
;            |                 |
;            |         P1.1/TA0|--> TACCR0
;            |         P1.2/TA1|--> TACCR1
;            |         P1.3/TA2|--> TACCR2
;            |             P1.0|--> Overflow/software
;
;  JL Bile
;  Texas Instruments Inc.
;  June 2008
;  Built Code Composer Essentials: v3 FET
;*******************************************************************************
 .cdecls C,LIST, "msp430.h"
;-------------------------------------------------------------------------------
			.text	;Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #450h,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP1     bis.b   #00Eh,&P1SEL            ; P1.1 - P1.3 option select
            bis.b   #00Fh,&P1DIR            ; P1.0-3 outputs
SetupBC     bis.b   #XTS,&BCSCTL1           ; LFXT1 = HF XTAL
            mov.b   #LFXT1S1,&BCSCTL3       ; LFXT1S1 = 3-16Mhz
SetupOsc    bic.b   #OFIFG,&IFG1            ; Clear OSC fault flag
            mov.w   #0FFh,R15               ; R15 = Delay
SetupOsc1   dec.w   R15                     ; Additional delay to ensure start
            jnz     SetupOsc1               ;
            bit.b   #OFIFG,&IFG1            ; OSC fault flag set?
            jnz     SetupOsc                ; OSC Fault, clear flag again
            bis.b   #SELM_3,&BCSCTL2        ; MCLK = LFXT1
SetupC0     mov.w   #OUTMOD_4+CCIE,&TACCTL0 ; TACCR0 toggle, interrupt enabled
SetupC1     mov.w   #OUTMOD_4+CCIE,&TACCTL1 ; TACCR1 toggle, interrupt enabled
SetupC2     mov.w   #OUTMOD_4+CCIE,&TACCTL2 ; TACCR2 toggle, interrupt enabled
SetupTA     mov.w   #TASSEL_1+MC_2+TAIE,&TACTL   ; ACLK, contmode, interrupt
                                            ;
Mainloop    bis.w   #LPM3+GIE,SR            ; Enter LPM3, interrupts enabled
            nop                             ; Required for debugger
                                            ;
;-------------------------------------------------------------------------------
TA0_ISR;
;-------------------------------------------------------------------------------
            add.w   #200,&TACCR0            ; Offset until next interrupt
            reti                            ;
                                            ;
;-------------------------------------------------------------------------------
TAX_ISR;    Common ISR for TACCR1-2 and overflow
;-------------------------------------------------------------------------------
            add.w   &TAIV,PC                ; Add Timer_A offset vector
            reti                            ; No interrupt
            jmp     TACCR1_ISR              ; TACCR1
            jmp     TACCR2_ISR              ; TACCR2
            reti                            ; Reserved
            reti                            ; Reserved
TA_over     xor.b   #001h,&P1OUT            ; Toggle P1.0
            reti                            ; Return from overflow ISR
                                            ;
TACCR1_ISR  add.w   #1000,&TACCR1           ; Offset until next interrupt
            reti                            ; Return ISR
                                            ;
TACCR2_ISR  add.w   #10000,&TACCR2          ; Offset until next interrupt
            reti                            ; Return ISR
                                            ;
;-------------------------------------------------------------------------------
;			Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect	".reset"            ; MSP430 RESET Vector
            .short	RESET                   ;
            .sect	".int09"          ; Timer_A0 Vector
            .short   TA0_ISR                 ;
            .sect	".int08"          ; Timer_AX Vector
            .short  TAX_ISR                 ;
            .end            
