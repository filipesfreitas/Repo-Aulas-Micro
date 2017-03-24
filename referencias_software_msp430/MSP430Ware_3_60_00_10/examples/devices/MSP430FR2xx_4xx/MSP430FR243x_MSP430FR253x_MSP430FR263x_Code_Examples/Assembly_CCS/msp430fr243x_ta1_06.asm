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
;  MSP430FR24xx Demo - Timer0_A3, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK
;
;  Description: Toggle P1.0 using software and TA_0 ISR. Timer0_A is
;  configured for up mode, thus the timer overflows when TAR counts
;  to CCR0. In this example, CCR0 is loaded with 50000.
;  ACLK = n/a, MCLK = SMCLK = TACLK = default DCO ~1MHz
;
;
;           MSP430FR2433
;         ---------------
;     /|\|               |
;      | |               |
;      --|RST            |
;        |               |
;        |           P1.0|-->LED
;
;  
;  Ling Zhu
;  Texas Instruments Inc.
;  Nov 2015
;  Built with Code Composer Studio v6.0
;******************************************************************************
            .cdecls C,LIST,"msp430.h"           ; Include device header file
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack                      ; Make stack linker segment ?known?
    
            .global _main
            .text                               ; Assemble to Flash memory
            .retain                             ; Ensure current section gets linked
            .retainrefs
_main
    
RESET       mov.w   #__STACK_END,SP             ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL      ; Stop WDT
                
            bis.b   #BIT0,&P1DIR                ; Set P1.0 to output direction
            bis.b   #BIT0,&P1OUT    
            bic.w   #LOCKLPM5,&PM5CTL0          ; Unlock I/O pin

            mov.w   #CCIE,&TA1CCTL0             ; TACCR0 interrupt enabled
            mov.w   #50000,&TA1CCR0
            mov.w   #TASSEL_1|MC_1,&TA1CTL      ; ACLK, up mode

Mainloop    nop
            bis.w   #LPM3+GIE,SR                ; Enter LPM3 w/ interrupt
            nop                                 ; For debugger

;-------------------------------------------------------------------------------
TIMER1_A0_ISR;    ISR for TA1CCR0
;-------------------------------------------------------------------------------
            xor.b   #BIT0,&P1OUT                ; Toggle LED
            reti
            
;------------------------------------------------------------------------------
;           Interrupt Vectors
;------------------------------------------------------------------------------
            .sect   RESET_VECTOR                ; MSP430 RESET Vector
            .short  RESET                       
            .sect   TIMER1_A0_VECTOR            ; Timer_A0 Vector
            .short  TIMER1_A0_ISR                     
            .end