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
;  MSP430F530x Demo - Timer1_A3, Toggle P1.7/TA1.0, Up Mode, 32kHz ACLK
;
;  Description: Toggle P1.7 using hardware TA1.0 output. Timer1_A is configured
;  for up mode with CCR0 defining period, TA1.0 also output on P1.7. In this
;  example, CCR0 is loaded with 10-1 and TA1.0 will toggle P1.7 at TACLK/10.
;  Thus the output frequency on P1.7 will be the TACLK/20. No CPU or software
;  resources required. Normal operating mode is LPM3.
;  As coded with TACLK = ACLK, P1.7 output frequency = 32768/20 = 1.6384kHz.
;  ACLK = TACLK = 32kHz, MCLK = default DCO ~1.045MHz
;
;                MSP430F530x
;            -------------------
;        /|\|                   |
;         | |                   |
;         --|RST                |
;           |                   |
;           |         P1.7/TA1.0|--> ACLK/20
;
;  K. Chen
;  Texas Instruments Inc.
;  March 2012
;  Built with CCS Version: 5.2
;*******************************************************************************

 .cdecls C,LIST, "msp430.h"

            .global _main
            .global __STACK_END
            .sect   .stack                  ; Make stack linker segment known
;-------------------------------------------------------------------------------
            .text                           ; Assemble to Flash memory
            .retain                         ; Ensure current section gets linked
            .retainrefs
;-------------------------------------------------------------------------------
_main
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop WDT

SetupP1     bis.b   #BIT7,&P1DIR            ; P1.7 output
            bis.b   #BIT7,&P1SEL            ; P1.7 option select

; Configure XT1
            bis.b   #BIT4 | BIT5,&P5SEL     ; Port select XT1
            bic.w   #XT1OFF,&UCSCTL6        ; XT1 On
            bis.w   #XCAP_3,&UCSCTL6        ; Internal load cap
            mov.w   #0,&UCSCTL3             ; FLL Reference Clock = XT1

; Loop until XT1,XT2 & DCO stabilizes - In this case loop until XT1 and DCo
do_loop     bic.w   #XT2OFFG | XT1LFOFFG | DCOFFG,&UCSCTL7
                                            ; Clear XT2,XT1, DCO fault flags
            bic.w   #OFIFG,&SFRIFG1         ; Clear fault flags
            bit.w   #OFIFG,&SFRIFG1         ; Test oscillator fault flag
            jnz     do_loop                 ; Again
            bic.w   #XT1DRIVE_3,&UCSCTL6    ; Xtal is now stable, reduce drive
                                            ; strength
            bis.w   #SELA_0,&UCSCTL4        ; ACLK = LFTX1 (by default)

SetupC0     mov.w   #OUTMOD_4,&TA1CCTL0     ; CCR0 toggle mode
            mov.w   #10-1,&TA1CCR0          ;
SetupTA     mov.w   #TASSEL_1 | MC_1 | TACLR,&TA1CTL ; ACLK, upmode, clear TAR
                                            ;
Mainloop    bis.w   #LPM3,SR                ; Enter LPM3
            nop                             ; Required only for debugger
                                            ;
;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET                   ;
            .end