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
;   MSP430F21x2 Demo - ADC10, Sample A0, 1.5V Ref, Set P1.0 if A0 > 0.2V
;
;   Description: A single sample is made on A0 with reference to internal
;   1.5V Vref. Software sets ADC10SC to start sample and conversion - ADC10SC
;   automatically cleared at EOC. ADC10 internal oscillator times sample (16x)
;   and conversion. In Mainloop MSP430 waits in LPM0 to save power until ADC10
;   conversion complete, ADC10_ISR will force exit from LPM0 in Mainloop on
;   reti. If A0 > 0.2V, P1.0 set, else reset.
;
;                MSP430F21x2
;             -----------------
;         /|\|              XIN|-
;          | |                 |
;          --|RST          XOUT|-
;            |                 |
;        >---|P2.0/A0      P1.0|--> LED
;
;  JL Bile
;  Texas Instruments Inc.
;  May 2008
;  Built with Code Composer Essentials: v3 FET
;*******************************************************************************
 .cdecls C,LIST, "msp430.h"
;-------------------------------------------------------------------------------
            .text                            ;Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #025Fh,SP               ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupADC10  mov.w   #SREF_1+ADC10SHT_2+REFON+ADC10ON+ADC10IE,&ADC10CTL0;
            mov.w   #30,&TA0CCR0            ; Delay to allow Ref to settle
            bis.w   #CCIE,&TA0CCTL0         ; Compare-mode interrupt.
            mov.w   #TACLR+MC_1+TASSEL_2,&TA0CTL; up mode, SMCLK
            bis.w   #LPM0+GIE,SR            ; Enter LPM0, enable interrupts
            bic.w   #CCIE,&TA0CCTL0         ; Disable timer interrupt
            bis.b   #01h,&ADC10AE0          ; P2.0 ADC10 option select
SetupP1     bis.b   #001h,&P1DIR            ; P1.0 output

Mainloop    bis.w   #ENC+ADC10SC,&ADC10CTL0 ; Start sampling/conversion
            bis.w   #CPUOFF+GIE,SR          ; LPM0, ADC12 ISR will force exit
            bic.b   #01h,&P1OUT             ; P1.0 = 0
            cmp.w   #088h,&ADC10MEM         ; ADC10MEM = A0 > 0.2V?
            jlo     Mainloop                ; Again
            bis.b   #01h,&P1OUT             ; P1.0 = 1
            jmp     Mainloop                ; Again

;-------------------------------------------------------------------------------
TA0_ISR;    ISR for TA0CCR0
;-------------------------------------------------------------------------------
            clr.w   &TA0CTL                 ; Clear Timer_A control registers
            bic.w   #LPM0,0(SP)             ; Exit LPM0, interrupts enabled
            reti                            ;
;-------------------------------------------------------------------------------
ADC10_ISR;  Exit LPM0 on reti
;-------------------------------------------------------------------------------
            bic.w   #LPM0,0(SP)             ; Exit LPM0, interrupts enabled
            reti                            ;
;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".int05"                ; ADC10 Vector
            .short  ADC10_ISR
            .sect   ".int09"                ; Timer_A0 Vector 
            .short  TA0_ISR
            .sect   ".reset"                ; POR, ext. Reset
            .short  RESET
            .end
