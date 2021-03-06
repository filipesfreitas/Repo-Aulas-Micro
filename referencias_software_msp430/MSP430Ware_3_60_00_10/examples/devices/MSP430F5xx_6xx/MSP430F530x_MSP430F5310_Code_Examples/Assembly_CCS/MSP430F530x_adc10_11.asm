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
;  MSP430F530x Demo - ADC10, Sample A0, 1.5V Ref, TA0.1 Trig, Set P1.0 if
;                     A0>0.5V
;
;  Description: A0 is sampled 16/second (2048AxCLK) with reference to 1.5V.
;  Timer_A is run in upmode and TA0.1 is used to automatically trigger
;  ADC10 conversion. Internal oscillator times sample (16x) and conversion
;  (13x).Inside ADC10_ISR if A0 > 0.5V, P1.0 is set, else reset. Normal mode
;  is LPM3.
;  //* An external watch crystal on XIN XOUT is required for ACLK *//
;
;               MSP430F530x
;            -----------------
;        /|\|              XIN|-
;         | |                 | 32kHz
;         --|RST          XOUT|-
;           |                 |
;    Vin -->|P6.0/A0      P1.0|--> LED
;           |             P1.2|--> TA0.1 (ADC trigger signal)
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

SetupP1     bis.b   #BIT0,&P1DIR            ; Set P1.0 to output direction
            bic.b   #BIT0,&P1OUT            ; Clear P1.0
            bis.b   #BIT2,&P1DIR            ; P1.2/TA0.1 output
            bis.b   #BIT2,&P1SEL            ; TA0.1 function select

; Configure XT1
            bis.b   #BIT4 | BIT5,&P5SEL     ; Port select XT1
            bic.w   #XT1OFF,&UCSCTL6        ; XT1 On
            bis.w   #XCAP_3,&UCSCTL6        ; Internal load cap
            mov.w   #0,&UCSCTL3             ; FLL Reference Clock = XT1

; Loop until XT1,XT2 & DCO stabilizes - In this case loop until XT1 and DCo
do_loop     bic.w   #XT2OFFG | XT1LFOFFG | DCOFFG,&UCSCTL7 ;Clear XT2,XT1,
                                                           ;DCO fault flags
            bic.w   #OFIFG,&SFRIFG1         ; Clear fault flags
            and.w   #OFIFG,&SFRIFG1         ; Test oscillator fault flag
            jnz     do_loop                 ; Again
            bic.w   #XT1DRIVE_3,&UCSCTL6    ; Xtal is now stable, reduce drive
                                            ; strength
            bis.w   #SELA_0,&UCSCTL4        ; ACLK = LFTX1 (by default)

; Configure ADC10
SetupADC10  bis.w   #ADC10ON | ADC10MSC,&ADC10CTL0 ; ADC10ON
            bis.w   #ADC10SHS_1 | ADC10CONSEQ_2,&ADC10CTL1
                                            ; rpt single ch, TA0.1 trig sample
            bis.w   #ADC10RES,&ADC10CTL2    ; 10-bit conversion results
            bis.w   #ADC10INCH_0 | ADC10SREF_1,&ADC10MCTL0 ; A0 ADC input select
                                                           ; Vref=1.5V

; By default, REFMSTR=1 => REFCTL is used to configure the internal reference
while_loop  bit.w   #REFGENBUSY,&REFCTL0    ; If ref generator busy, WAIT
            jnz     while_loop              ;
            bis.w   #REFVSEL_0 | REFON,&REFCTL0 ; Internal Reference ON
                                                ; Vref=1.5V

; Configure TA0 to provide delay for reference settling ~75us
            mov.w   #80,&TA0CCR0            ; Delay to allow Ref to settle
            bis.w   #CCIE,&TA0CCTL0         ; Compare-mode interrupt.
            mov.w   #MC_1 | TASSEL_2,&TA0CTL; up mode, TACLK=SMCLK
            nop
            bis.w   #LPM0 | GIE,SR          ; Enter LPM0, TA0_ISR will force
            nop                             ; exit
            bic.w   #CCIE,&TA0CCTL0         ; Disable timer interrupt

            bis.w   #ADC10ENC,&ADC10CTL0    ; ADC10 Enable
            bis.w   #ADC10IE0,&ADC10IE      ; Enable ADC conv complete interrupt

; ADC conversion trigger signal - TimerA0.1 (32ms ON-period)
            mov.w   #1024-1,&TA0CCR0        ; PWM Period
            mov.w   #512-1,&TA0CCR1         ; TA0.1 PWM
            mov.w   #OUTMOD_4,&TA0CCTL1     ; TA0CCR1 toggle
            mov.w   #TASSEL_1 | MC_1| TACLR,&TA0CTL ; ACLK, up mode
            nop
            bis.w   #LPM3 | GIE,SR          ; Enter LPM3 w/ interrupts
            nop
;-------------------------------------------------------------------------------
TA0_ISR
;-------------------------------------------------------------------------------
            clr.w   &TA0CTL                 ; Clear Timer_A control registers
            bic.w   #LPM0,0(SP)             ; Exit LPM0, interrupts enabled
            reti                            ;
;-------------------------------------------------------------------------------
ADC10_ISR
;-------------------------------------------------------------------------------
            add.w   &ADC10IV,PC             ; Add offset to PC
            reti                            ; Vector 0:  No interrupt
            reti                            ; Vector 2:  ADC overflow
            reti                            ; Vector 4:  ADC timing overflow
            reti                            ; Vector 6:  ADC10HI
            reti                            ; Vector 8:  ADC10LO
            reti                            ; Vector 10: ADC10IN
            jmp     ADC10IFG0_HND           ; Vector 12: ADC10IFG3

ADC10IFG0_HND
            cmp.w   #0x155,&ADC10MEM0       ; ADC10MEM0 = A10 > 0.5V
            jnc     less_than
grtr_or_eql bis.b   #BIT0,&P1OUT            ; yes -> P1.0 = 1
            jmp     exit_isr
less_than   bic.b   #BIT0,&P1OUT            ; no -> P1.0 = 0
exit_isr    reti
;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ADC10_VECTOR            ; ADC10 Vector
            .short  ADC10_ISR
            .sect   TIMER0_A0_VECTOR        ; Timer_A0 Vector
            .short  TA0_ISR
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET                   ;
            .end
