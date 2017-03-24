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
;  MSP430F673xA Demo - MPY32, 8x8 Signed Multiply Accumulate
;
;  Description: Hardware multiplier is used to multiply two numbers.
;  The calculation is automatically initiated after the second operand is
;  loaded.  A second multiply accumulate operation is performed after that.
;  Results are stored in RESLO and RESHI.  SUMEXT contains the extended sign of
;  result.
;
;  ACLK = 32.768kHz, MCLK = SMCLK = default DCO
;
;                MSP430F673xA
;             -----------------
;         /|\|                 |
;          | |                 |
;          --|RST              |
;            |                 |
;            |                 |
;
;  M. Swanson
;  Texas Instruments Inc.
;  December 2011
;  Built with CCS Version: 5.1.0
;*******************************************************************************
            .cdecls C,LIST,"msp430.h"

value1    .equ    R4 
value2    .equ    R5 

;-------------------------------------------------------------------------------
            .global _main 
            .text                           ; Assemble to Flash memory
;-------------------------------------------------------------------------------
_main
RESET       mov.w   #0x5C00,SP              ; Initialize stackpointer
            mov.w   #WDTPW + WDTHOLD,&WDTCTL; Stop WDT

            mov.w   #0x1234,&MPY            ; Load 1st operand - unsigned mult
            mov.w   #0x5678,&OP2            ; Load second operand

            mov.b   #0x12,value1            ; Load first operand - signed MAC
            mov.b   #0x96,value2            ; Load second operand

            mov.b   value1,&MACS_B          ; Signed multiplication
            mov.b   value2,&OP2_B           ; Byte access removes the need for
                                            ; ... sign extension
            bis.w   #LPM4,SR                ; Enter LPM4
            nop                             ; For debugger

;-------------------------------------------------------------------------------
                  ; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; POR, ext. Reset
            .short  RESET
            .end
