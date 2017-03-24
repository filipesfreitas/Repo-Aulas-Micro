; --COPYRIGHT--,BSD_EX
;  Copyright (c) 2014, Texas Instruments Incorporated
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
;   MSP430FR69xx Demo - Stay in active mode with MCLK = 8MHz
;
;   Description: Configure ACLK = VLO, MCLK = 8MHz.
;
;   ACLK = VLO, MCLK = SMCLK = 8MHz
;
;          MSP430FR6989
;         ---------------
;     /|\|               |
;      | |               |
;      --|RST            |
;        |               |
;        |               |
;        |               |
;
;   E. Chen
;   Texas Instruments Inc.
;   April 2014
;   Built with Code Composer Studio V6.0
;******************************************************************************
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
;-------------------------------------------------------------------------------
            .global _main
            .global __STACK_END
            .sect   .stack                  ; Make stack linker segment ?known?

            .text                           ; Assemble to Flash memory
            .retain                         ; Ensure current section gets linked
            .retainrefs

_main
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
ConfigGPIO  clr.b   &P1DIR
            clr.b   &P1OUT
            mov.b   #0xFF,&P1REN

            clr.b   &P2DIR
            clr.b   &P2OUT
            mov.b   #0xFF,&P2REN

            clr.b   &P3DIR
            clr.b   &P3OUT
            mov.b   #0xFF,&P3REN

            clr.b   &P4DIR
            clr.b   &P4OUT
            mov.b   #0xFF,&P4REN

            mov.w   #0xFFFF,&PJDIR
            clr.w   &PJOUT

UnlockGPIO  bic.w   #LOCKLPM5,&PM5CTL0      ; Disable the GPIO power-on default
                                            ; high-impedance mode to activate
                                            ; previously configured port settings

            mov.b   #CSKEY_H,&CSCTL0_H      ; Unlock CS registers
            mov.w   #DCOFSEL_6,&CSCTL1      ; Set DCO setting for 8MHz
            mov.w   #SELA__VLOCLK+SELS__DCOCLK+SELM__DCOCLK,&CSCTL2 ; set ACLK = VLO
            mov.w   #DIVA__1+DIVS__1+DIVM__1,&CSCTL3 ; MCLK = SMCLK = DCO = 8MHz
            clr.b   &CSCTL0_H               ; Lock CS registers

ACTIVE_TEST mov.w   #0x2000, R4
            mov.w   #0x4, 0(R4)
            mov.w   &0x2000, &0x2002
            add.w   @R4, 2(R4)
            swpb    @R4+
            mov.w   @R4, R5
IDD_AM_L1   ; run 8 times
            xor.w   @R4+, &0x2020
            dec.w   R5
            jnz     IDD_AM_L1
            xor.b   #0x01, &0x202
            jmp     ACTIVE_TEST
            nop                             ; for debug

;------------------------------------------------------------------------------
;           Interrupt Vectors
;------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET                   ;
            .end
