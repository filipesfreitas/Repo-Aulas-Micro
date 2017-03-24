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
;  MSP430G2230 Demo - ADC10, DTC Sample A5 32x, 1.5V, Repeat Single, DCO
;
;  Description: Use DTC to sample A5 32 times with reference to internal 1.5v.
;  Vref Software writes to ADC10SC to trigger sample burst. In Mainloop MSP430
;  waits in LPM0 to save power until ADC10 conversion complete, ADC10_ISR(DTC)
;  will force exit from any LPMx in Mainloop on return. ADC10 internal
;  oscillator times sample period (16x) and conversion (13x). DTC transfers
;  conversion code to RAM 200h - 23Fh. P1.2 set at start of conversion burst,
;  reset on completion.
;
;                MSP430G2230
;             -----------------
;         /|\|              XIN|-
;          | |                 |
;          --|RST          XOUT|-
;            |                 |
;        >---|P1.1/A5      P1.2|-->LED
;
;  B. Finch
;  Texas Instruments, Inc
;  May 2012
;  Built with CCS Version: 5.2.0.00069
;******************************************************************************

 .cdecls C,LIST,"msp430.h"

;-------------------------------------------------------------------------------
            .global _main
            .text                           ; Assemble to Flash memory
;-------------------------------------------------------------------------------
_main
RESET       mov.w   #0x280,SP               ; Initialize stackpointer
            mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
            mov.b   #0x1B,&P1REN            ; Terminate unavailable Port1 pins 
            bis.b   #LFXT1S_2,&BCSCTL3      ; Select VLO as low freqency clock

            mov.w   #CONSEQ_2+INCH_5,&ADC10CTL1 ; Repeat mode, input A5
            ; Set ref, sample every 16 ADC clocks, enable reference, ADC on
            mov.w   #SREF_1+ADC10SHT_2+MSC+REFON+ADC10ON+ADC10IE,&ADC10CTL0 
            eint
            mov.w   #30,&TACCR0             ; Delay to allow Ref to settle
            bis.w   #CCIE,&TACCTL0          ; Compare-mode interrupt enable
            mov.w   #TASSEL_2+MC_1,&TACTL; SMCLK, up mode, clear timer
            bis.w   #LPM0,SR                ; LPM0 (CPU off), ISR forces exit
            bic.w   #CCIE,&TACCTL0          ; Disable timer interrupt
            dint
            mov.b   #0x20,&ADC10DTC1        ; 32 conversions
            bis.b   #BIT5,&ADC10AE0         ; P1.5 ADC option select
            bis.b   #BIT2,&P1DIR            ; Set P1.2 to output direction

loop        bic.w   #ENC,&ADC10CTL0         ; clear ENC
busy_test   bit.w   #BUSY,&ADC10CTL1        ; ADC10 core inactive?
            jne     busy_test
            mov.w   #0x200,&ADC10SA         ; Set start address
            bis.b   #BIT2,&P1OUT            ; Set LED (on)
            bis.w   #ENC+ADC10SC,&ADC10CTL0 ; Sampling and conversion start
            bis.w   #LPM0+GIE,SR            ; LPM0 (CPU off), ISR forces exit
            bic.b   #BIT2,&P1OUT            ; Clear LED (off)
            jmp     loop

;-------------------------------------------------------------------------------
ADC10_ISR
;-------------------------------------------------------------------------------
            bic.w   #LPM0,0(SP)             ; Exit active CPU
            reti                            ; Vector 0:  No interrupt

;-------------------------------------------------------------------------------
TIMERA0_ISR
;-------------------------------------------------------------------------------
            clr.w   &TACTL                  ; Clear Timer_A control registers
            bic.w   #LPM0,0(SP)             ; Exit LPM0, interrupts enabled
            reti

;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; POR, ext. Reset
            .short  RESET
            .sect   ADC10_VECTOR            ; ADC10 isr vector
            .short  ADC10_ISR
            .sect   TIMERA0_VECTOR          ; Timer_A0 Vector
            .short  TIMERA0_ISR
            .end
