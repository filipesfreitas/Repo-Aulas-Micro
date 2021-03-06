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
;  MSP430F530x Demo - ADC10, DMA Sample A1 32x, 2.5V Ref, TB0 Trig, DCO
;
;  Description; A1 is sampled 32x burst 16 times per second (ACLK/256) with
;  Vref = internal 2.5V. Activity is interrupt driven. Timer_A in upmode uses
;  TB0.0 toggle to drive ADC10 conversion. ADC conversions are automatically 
;  triggered by TB0 rising edge every 2048 ACLK cycles. ADC10_ISR will exit 
;  from LPM3 mode and return CPU active. Internal ADC10OSC times sample (16x)
;  and conversion (13x). DMA transfers conv results to ADC_Result variable. 
;  //* An external watch crystal on XIN XOUT is required for ACLK *//
;
;               MSP430F530x
;            -----------------
;        /|\|              XIN|-
;         | |                 | 32kHz
;         --|RST          XOUT|-
;           |                 |
;       >---|P6.1/A1          | 
;           |            P4.0 |--> TB0.0 (ADC trigger signal)
;
;  K. Chen
;  Texas Instruments Inc.
;  March 2012
;  Built with CCS Version: 5.2
;*******************************************************************************

 .cdecls C,LIST, "msp430.h"

ADC_Result  .equ  0x1c00

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

; Configure ADC10 - pulse sample mode; TB0 trigger; rpt single channel
SetupADC10  mov.w   #ADC10SHT_2 | ADC10ON,&ADC10CTL0 ; 16ADCclks, ADC on
            mov.w   #ADC10SHP | ADC10SHS_2 | ADC10CONSEQ_2,&ADC10CTL1
                                            ; sampling timer, TimerB0.0 trigger 
                                            ; rpt single channel       
            mov.w   #ADC10RES,&ADC10CTL2    ; 10-bits resolution
            mov.w   #ADC10SREF_1 | ADC10INCH_1,&ADC10MCTL0 ; Vref+, A1

; Configure internal reference
while_loop  and.w   #REFGENBUSY,&REFCTL0    ; If ref generator busy, WAIT       
            jnz     while_loop              ; 
            bis.w   #REFVSEL_2 | REFON,&REFCTL0
                                            ; Internal Reference ON; Vref=2.5V

; Delay (~75us) for Ref to settle
            mov.w   #75,R4                  ; Initialize loop counter R4=75
delay_loop  dec.w   R4                      ; Decrement loop counter
            jnz     delay_loop              ; Loop if loop counter > 0
            
; Configure DMA (ADC10IFG trigger)
            mov.w   #DMA0TSEL_24,&DMACTL0   ; ADC10IFG trigger
            movx.a  #ADC10MEM0,&DMA0SA      ; Source single address
            movx.a  #ADC_Result,&DMA0DA     ; Destination array address
            mov.w   #32,&DMA0SZ             ; 32 conversions
            mov.w   #DMADT_4 | DMADSTINCR_3 | DMAEN | DMAIE,&DMA0CTL
                                            ; Rpt, inc dest, byte access,
                                            ; enable interrupt after 32 
                                            ; conversions 

; Configure Timer Trigger TB0.0
            mov.w   #256-1,&TB0CCR0         ; TB0.0 Period
            mov.w   #OUTMOD_4,&TB0CCTL0     ; TBCCR0 toggle (ON period = ~7.8ms
; Configure P4.0 as TB0.0 output
            calla   #Port_Mapping           ;
            bis.b   #BIT0,&P4SEL            ; Port map option select
            bis.b   #BIT0,&P4DIR            ; P4.0/TB0.0 output direction
            mov.w   #TBSSEL_1 | MC_1 | TBCLR,&TB0CTL ; ACLK, up mode

while_loop1 
while_loop2 bit.w   #ADC10BUSY,&ADC10CTL1   ; Wait if ADC10 core is active
            jnz     while_loop2             ;             
            bis.w   #ADC10ENC,&ADC10CTL0    ; Sampling and conversion ready                                            
            nop
            bis.w   #LPM0|GIE,SR            ; LPM0, DMA0_ISR will force exit
            nop
            mov.w   #0x681,R15              ; Delay between sequence convs
delay       add.w   #0xFFFF,R15             ;
            jc      delay                   ; 
            nop                             ; BREAKPOINT; check ADC_Result 
            jmp     while_loop1             ;

;-------------------------------------------------------------------------------
Port_Mapping
;-------------------------------------------------------------------------------
            dint                            ; Disable Interrupts before altering 
                                            ; Port Mapping registers
            nop                             ;
            mov.w   #0x2D52,&PMAPKEYID      ; Enable Write-access to modify port 
                                            ; mapping registers
            mov.b   #PM_TB0CCR0A,&P4MAP0    ; TDB0.0 PWM Output
            clr.w   &PMAPKEYID              ; Disable Write-Access to modify 
                                            ; port mapping registers
            reta            
;-------------------------------------------------------------------------------
DMA_ISR;
;-------------------------------------------------------------------------------
            add.w   &DMAIV,PC               ; Add offset to PC
            reti                            ; Vector 0:  No interrupt
            jmp     DMA0_HND                ; Vector 2:  DMA0IFG
            reti                            ; Vector 4:  DMA1IFG
            reti                            ; Vector 6:  DMA2IFG
            reti                            ; Vector 8:  Reserved
            reti                            ; Vector 10: Reserved               
            reti                            ; Vector 12: Reserved
            reti                            ; Vector 14: Reserved
            reti                            ; Vector 16: Reserved
                        
DMA0_HND
; 32 conversions complete            
            bic.w   #LPM0,0(SP)             ; exit LPM
            reti
            
;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   DMA_VECTOR              ; DMA Vector
            .short  DMA_ISR                 ;
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET                   ;
            .end
