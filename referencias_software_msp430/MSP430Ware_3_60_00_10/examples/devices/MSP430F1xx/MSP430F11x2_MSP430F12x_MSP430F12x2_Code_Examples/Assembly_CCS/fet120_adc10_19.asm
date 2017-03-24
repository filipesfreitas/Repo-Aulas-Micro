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
;   MSP-FET430P120 Demo - ADC10, DTC Sample A0 64x, AVcc, HF XTAL
;
;   Description: For non-low power applications HF XTAL can source ACLK and be
;   used also for CPU MCLK, as in this example. DTC always uses MCLK for data
;   transfer. Though not required, ADC10 can also clock from HF XTAL as in this
;   example using ACLK.
;   MCLK = ACLK = ADC10CLK = HF XTAL in this example.
;   DTC Used to sample A0 64 times with reference to AVcc. Software writes to
;   ADC10SC to trigger sample burst. In Mainloop MSP430 waits in LPM0 to save
;   power until ADC10 conversion burst complete, ADC10_ISR(DTC) will force
;   exit from any LPMx in Mainloop on reti. In this example ACLK times sample
;   period (16x) and conversion (13x). DTC transfers conversion code to RAM
;   200h - 280h. P1.0 .set at start of conversion burst, reset on completion.
;   //* MSP430F1232 or MSP430F1132 Device Required *//
;   //* HF XTAL NOT INSTALLED ON FET *//
;
;                MSP430F1232
;             -----------------
;         /|\|              XIN|-
;          | |                 | HF XTAL (455k - 8Mhz)
;          --|RST          XOUT|-
;            |                 |
;        >---|A0           P1.0|-->LED
;
;   M. Buccini / M. Raju
;   Texas Instruments Inc.
;   May 2005
;   Built with Code Composer Essentials Version: 1.0
;******************************************************************************
 .cdecls C,LIST,  "msp430.h"
;------------------------------------------------------------------------------
            .text                           ; Program Start
;------------------------------------------------------------------------------
RESET       mov.w   #0300h,SP               ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupBC     bis.b   #XTS,&BCSCTL1           ; LFXT1 = HF XTAL
SetupOsc    bic.b   #OFIFG,&IFG1            ; Clear OSC fault flag
            mov.w   #0FFh,R15               ; R15 = Delay
SetupOsc1   dec.w   R15                     ; Additional delay to ensure start
            jnz     SetupOsc1               ;
            bit.b   #OFIFG,&IFG1            ; OSC fault flag set?
            jnz     SetupOsc                ; OSC Fault, clear flag again
            bis.b   #SELM_3,&BCSCTL2        ; MCLK = LFXT1
SetupADC10  mov.w   #ADC10SSEL_1+CONSEQ_2,&ADC10CTL1 ;
            mov.w   #ADC10SHT_2+MSC+ADC10ON+ADC10IE,&ADC10CTL0 ;
            bis.b   #01h,&ADC10AE           ; P2.0 ADC option select
            mov.b   #040h,&ADC10DTC1        ; 64 conversions
SetupP1     bis.b   #001h,&P1DIR            ; P1.0 output
                                            ;
Mainloop    bis.b   #001h,&P1OUT            ; P1.0 = 1
            bic.w   #ENC,&ADC10CTL0         ;
busy_test   bit     #BUSY,&ADC10CTL1        ; ADC10 core inactive?
            jnz     busy_test               ;
            mov.w   #0200h,&ADC10SA         ; Data buffer start
            bis.w   #ENC+ADC10SC,&ADC10CTL0 ; Start sampling
            bis.w   #CPUOFF+GIE,SR          ; LPM0, ADC12 ISR will force exit
            bic.b   #001h,&P1OUT            ; P1.0 = 0
            jmp     Mainloop                ; Again
                                            ;
;------------------------------------------------------------------------------
ADC10_ISR;
;------------------------------------------------------------------------------
            mov.w   #GIE,0(SP)              ; Exit any LPMx on reti
            reti                            ;		
                                            ;
;------------------------------------------------------------------------------
;           Interrupt Vectors
;------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET                   ;
            .sect   ".int05"                ; ADC10 Vector
            .short  ADC10_ISR               ;
            .end
