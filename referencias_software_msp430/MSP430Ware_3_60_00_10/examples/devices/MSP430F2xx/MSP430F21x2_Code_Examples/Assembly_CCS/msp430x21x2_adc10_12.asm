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
;   MSP430F21x2 Demo - ADC10, Sample A7, 1.5V, TA1 Trig, Ultra-Low Pwr
;
;   Description: A7 is sampled 1024/second (32xACLK) with reference to 1.5V.
;   All activity is interrupt driven with proper usage of MSP430 low-power
;   modes, ADC10 and Vref demonstrated. Timer_A with both TA1/TA0 used in
;   upmode to drive ADC10 conversion (continuous mode can also be used).
;   Inside of TA0_ISR software will enable ADC10 and internal reference and
;   allow > 30us delay for Vref to stabilize prior to sample start. Sample
;   start is automatically triggered by TA1 every 32 ACLK cycles. ADC10_ISR
;   will disable ADC10 and Vref and compare ADC10 conversion code. Internal
;   oscillator times sample (16x) and conversion (13x). If A7 > 0.2Vcc,
;   P1.0 is set, else reset. Normal Mode is LPM3.
;   //* An external watch crystal on XIN XOUT is required for ACLK *//
;
;                     +-----(0.9766us)---------\\------------------>+
;     TA0_ISR        TA1      ADC10_ISR             TA0_ISR        TA1
;   -----+------------+------------+-----------\\------+------------+----->
;    Enable ADC    Trigger ADC  Disable ADC
;    and Vref                   Compare
;        +-( >30us--->+
;
;
;                MSP430F21x2
;             -----------------
;         /|\|              XIN|-
;          | |                 | 32kHz
;          --|RST          XOUT|-
;            |                 |
;        >---|P3.7/A7     P1.0 |--> LED
;
;  JL Bile
;  Texas Instruments Inc.
;  May 2008
;  Built with Code Composer Essentials: v3 FET
;*******************************************************************************
 .cdecls C,LIST, "msp430.h"
;-------------------------------------------------------------------------------
            .text                           ;Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #025Fh,SP               ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP1     mov.b   #0FFh,&P1DIR            ; All P1.x outputs
            clr.b   &P1OUT                  ; All P1.x reset
SetupP2     mov.b   #0FFh,&P2DIR            ; All P2.x outputs
            clr.b   &P2OUT                  ; All P2.x reset
SetupP3     mov.b   #0FFh,&P3DIR            ; All P3.x outputs
            clr.b   &P3OUT                  ; All P3.x reset
SetupADC10  mov.w   #INCH_7+SHS_1,&ADC10CTL1; P3.7, TA1 trigger sample start
            bis.b   #080h,&ADC10AE0         ; P3.7 ADC10 option select
SetupC0     mov.w   #CCIE,&TA0CCTL0         ; Enable interrupt
            mov.w   #32-1,&TA0CCR0          ; PWM Period
SetupC1     mov.w   #OUTMOD_3,&TA0CCTL1     ; TA0CCR1 set/reset
            mov.w   #2,&TA0CCR1             ; TA0CCR1 PWM Duty Cycle
SetupTA     mov.w   #TASSEL_1+MC_1,TA0CTL   ; ACLK, up mode
                                            ;
Mainloop    bis.w   #LPM3+GIE,SR            ; Enter LPM3
            nop                             ; Required only for debugger
                                            ;
;-------------------------------------------------------------------------------
ADC10_ISR;
;-------------------------------------------------------------------------------
            bic.w   #ENC,&ADC10CTL0         ; ADC10 disabled
            clr.w   &ADC10CTL0              ; ADC10, Vref disabled completely
            bic.b   #01h,&P1OUT             ; P1.0 = 0
            cmp.w   #088h,&ADC10MEM         ; ADC10MEM = A7 > 0.2V?
            jlo     ADC10_Exit              ; Again
            bis.b   #01h,&P1OUT             ; P1.0 = 1
ADC10_Exit  reti                            ;
                                            ;
;-------------------------------------------------------------------------------
TA0_ISR;    ISR for TA0CCR0
;-------------------------------------------------------------------------------
            mov.w   #SREF_1+ADC10SHT_2+REFON+ADC10ON+ADC10IE,&ADC10CTL0;
            bis.w   #ENC,&ADC10CTL0         ; ADC10 enable set
            reti                            ;
                                            ;
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
            
