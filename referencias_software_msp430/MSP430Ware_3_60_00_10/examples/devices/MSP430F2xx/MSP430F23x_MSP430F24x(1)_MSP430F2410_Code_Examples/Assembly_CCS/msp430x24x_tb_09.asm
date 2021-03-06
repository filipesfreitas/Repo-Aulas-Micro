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
;  MSP430F249 Demo - Timer_B, PWM TB1-6, Up/Down Mode, DCO SMCLK
;
;  Description: This program generates two PWM outputs on P4.1-6 using
;  Timer_B configured for up/down mode. The value in CCR0, 128, defines the
;  PWM period/2 and values in CCR1-6 the PWM duty cycles. Using ~1.1MHz SMCLK
;  as TBCLK, the timer period is ~ 250us. Normal operating mode: LPM0.
;  SMCLK = MCLK = TBCLK = default DCO ~1.045MHz.
;
;               MSP430F249
;            -----------------
;        /|\|              XIN|-
;         | |                 |  32KHz
;         --|RST          XOUT|-
;           |                 |
;           |         P4.1/TB1|--> CCR1 - 75% PWM
;           |         P4.2/TB2|--> CCR2 - 25% PWM
;           |         P4.3/TB3|--> CCR3 - 12.5% PWM
;           |         P4.4/TB4|--> CCR4 - 6.25% PWM
;           |         P4.5/TB5|--> CCR5 - 3.125% PWM
;           |         P4.6/TB6|--> CCR6 - 1.5625% PWM
;
;  JL Bile
;  Texas Instruments Inc.
;  May 2008
;  Built Code Composer Essentials: v3 FET
;*******************************************************************************
 .cdecls C,LIST, "msp430.h"
;-------------------------------------------------------------------------------
			.text	;Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #0500h,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP4     mov.b   #07Eh, &P4DIR           ; P4.1 - P4.6 output
            mov.b   #07Eh, &P4SEL           ; P4.1 - P4.6 TBx options
SetupTA     mov.w   #128,&TBCCR0            ;PWM period
            mov.w   #OUTMOD_6, &TBCCTL1     ; CCR1 toggle/set
            mov.w   #032, &TBCCR1           ; CCR1 PWM duty cycle
            mov.w   #OUTMOD_6, &TBCCTL2     
            mov.w   #096h, &TBCCR2          
            mov.w   #OUTMOD_6, &TBCCTL3     
            mov.w   #0112, &TBCCR3          
            mov.w   #OUTMOD_6, &TBCCTL4      
            mov.w   #0120, &TBCCR4          
            mov.w   #OUTMOD_6, &TBCCTL5      
            mov.w   #0124, &TBCCR5           
            mov.w   #OUTMOD_6, &TBCCTL6      
            mov.w   #0126, &TBCCR6
            
            mov.w   #TBSSEL_2 + MC_3, &TBCTL  ;SMCLK, up-down mode
                                            						
Mainloop    bis.w   #CPUOFF,SR            ; CPU off, interrupts enabled
            nop                             ; Required for debugger
                                                                        
;-------------------------------------------------------------------------------
;			Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect	".reset"            ;  MSP430 RESET Vector
            .short  RESET                    ;
            .end
