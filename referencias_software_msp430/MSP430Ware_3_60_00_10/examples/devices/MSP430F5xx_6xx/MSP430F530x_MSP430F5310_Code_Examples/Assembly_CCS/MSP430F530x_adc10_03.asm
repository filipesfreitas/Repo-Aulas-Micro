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
;  MSP430F530x Demo - ADC10, Sample A10 Temp, TA0.1 Trigger, Set P1.0 if Temp++
;                     ~2C
;
;  Description: Set ADC10 and the integrated temperature sensor to detect
;  temperature gradients. The temperature sensor output voltage is sampled
;  ~ every 62ms and then compared with the defined delta values using an ISR.
;  (ADC10OSC)/32 determines sample time which needs to be greater than
;  ~1us for temperature sensor.
;  ADC10 is operated in repeat-single channel mode with the sample and
;  convert trigger sourced from Timer_A CCR1. The ADC10IFG at the end
;  of each converstion will trigger an ISR.
;  ACLK = REFO, MCLK = SMCLK = default DCO ~1.2MHz, ADC10CLK = ADC10OSC
;
;                MSP430F530x
;             -----------------
;         /|\|              XIN|-
;          | |                 |
;          --|RST          XOUT|-
;            |                 |
;            |A10 (Temp)   P1.0|-->LED
;            |             P1.2|-->TA0.1 (ADC trigger signal)
;
;
;  K. Chen
;  Texas Instruments Inc.
;  March 2012
;  Built with CCS Version: 5.2
;*******************************************************************************

 .cdecls C,LIST, "msp430.h"

ADCDeltaOn  .equ      3                      ; ~ 2 Deg C delta for LED on

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

; Configure ADC10 - pulse Sample Mode, TimerA0.0 Trigger            
SetupADC10  mov.w   #ADC10SHT_3 | ADC10ON,&ADC10CTL0 ; S&H=32 ADC clks, ADC10 on
            mov.w   #ADC10SHP | ADC10SHS_1 | ADC10CONSEQ_2,&ADC10CTL1
                                            ; TA0.1 trig., rpt single ch   
            bis.w   #ADC10RES,&ADC10CTL2    ; 10-bit conversion results
            bis.w   #ADC10INCH_10 | ADC10SREF_1,&ADC10MCTL0 ; A10, internal
                                                            ; Vref+

; Configure internal reference
while_loop  and.w   #REFGENBUSY,&REFCTL0    ; If ref generator busy, WAIT       
            jnz     while_loop              ;
            bis.w   #REFVSEL_2|REFON,&REFCTL0 ; Select Internal ref = 2.5V.
                                              ; Internal reference on
            
; Configure TA0 to provide delay for reference settling ~75us            
            mov.w   #80,&TA0CCR0            ; Delay to allow Ref to settle
            bis.w   #CCIE,&TA0CCTL0         ; Compare-mode interrupt.
            mov.w   #MC_1 | TASSEL_2,&TA0CTL  ; up mode, TACLK=SMCLK
            nop
            bis.w   #LPM0 | GIE,SR          ; Enter LPM0, TA0_ISR will force
            nop                             ; exit
            bic.w   #CCIE,&TA0CCTL0         ; Disable timer interrupt

            bis.w   #ADC10IE0,&ADC10IE      ; Enable ADC conv complete interrupt 
            bis.w   #ADC10ENC,&ADC10CTL0    ;
            
; Configure TimerA0.0 as ADC conversion trigger ( period ~ 62 ms)
            mov.w   #1024-1,&TA0CCR0        ; PWM Period 
            mov.w   #512-1,&TA0CCR1         ; TA0.1 PWM
            bis.w   #OUTMOD_4,&TA0CCTL1     ; TA0CCR0 toggle
            bis.w   #TASSEL_1|MC_1|TACLR,&TA0CTL ; ACLK, up mode

SetupP1     bis.b   #BIT2,&P1DIR            ; P1.2/TA0.1 output
            bis.b   #BIT2,&P1SEL            ; Output TA0.1 ADC trigger signal 

ADC_Wait    and.w   #ADC10BUSY,&ADC10CTL1   ; First conversion?
            jnz     ADC_Wait                ; 
            mov.w   &ADC10MEM0,R4           ; Read out 1st ADC value   
            add.w   #ADCDeltaOn,R4          ;
            clr.b   &P1OUT                  ; Clear p1
            bis.b   #BIT0,&P1DIR            ; P1.0 as output
            nop
            bis.w   #LPM3|GIE,SR            ; Enter LPM3 w/ interrupt
            nop                             ; used for debugging
            
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
            cmp.w   R4,&ADC10MEM0           ; ADC10MEM0 = A10 > R4
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
