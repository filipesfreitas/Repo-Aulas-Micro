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
;*****************************************************************************
;  Description: Toggle P1.0 using software and Timer0_A1 ISR. Toggles every
;  1000 SMCLK cycles. SMCLK provides clock source for TA0CLK.
;  During the Timer0_A1 ISR, P1.0 is toggled and 1000 clock cycles are added to
;  TA0CCR0. Timer0_A1 ISR is triggered every 1000 cycles. CPU is normally off and
;  used only during Timer0_A1 ISR. Proper use of the TA0IV interrupt vector generator
;  is demonstrated.
;***************************Timer_A0******************************************** 
;                                                                                
;                                                                                
;                                                                                
;                               +----L092---+                                    
;                               |*1      14 |                                    
;                               | 2      13 |                                    
;                               | 3      12 |                                    
;                               | 4      11 |                                    
;                               | 5      10 |                                    
;     P1.0 -Toggle Output  <-   | 6       9 |                                    
;     P1.1 SMCLK~ 1Mhz     <-   | 7       8 |                                    
;                               +-----------+                                    
;                                                                                
;  D.Dang;D.Archbold;D.Szmulewicz
;  Texas Instruments Inc.
;  Built with CCS version 4.2.0
;******************************************************************************

 .cdecls C,LIST,"msp430.h"
;-------------------------------------------------------------------------------
            .global main
            .text                           ; Assemble to memory
;-------------------------------------------------------------------------------
main        mov.w   #WDTPW + WDTHOLD,&WDTCTL ; Stop WDT  
 
            bis.b   #BIT0+BIT1,&P1DIR       ; P1.0 Output direction
            bis.b   #BIT1,&P1SEL0           ;              
            bis.b   #BIT1,&P1SEL1           ;    
    
;***********************
; Setup CCS            
; SMCLK = HFCLK       
;***********************
            mov.w   #CCSKEY,&CCSCTL0        ; Unlock CCS

check       mov.w   #0,&CCSCTL7             ; Clear HF & LF OSC fault flags
            mov.w   #0,&SFRIFG1             ; Clear OFIFG
            bit.w   #OFIFG,&SFRIFG1         ; Oscillator Flag(s)?
            jnz     check
    	    mov.w   #SELS_0,&CCSCTL4        ; Select HFCLK/DCO as the source for SMCLK   
    	    mov.w   #DIVS_0,&CCSCTL5        ; Set the Dividers for SMCLK to 1
    	    bis.b   #0xFF,&CCSCTL0_H        ;  Lock CCS
   
; Lock by writing to upper byte 
  
  
  	        mov.w   #CCIE,&TA0CCTL1         ; TA0CCR1 interrupt enabled
        	mov.w   #1000,&TA0CCR1 			; Set value for TA0CCR1
  	        mov.w   #TASSEL_2 + MC_2, &TA0CTL ; SMCLK, Contmode

            bis.w   #LPM0+GIE,SR            ; LPM0, enable interrupts
            nop                             ; Required only for debugger

;-------------------------------------------------------------------------------
TAX_ISR;    Common ISR
;-------------------------------------------------------------------------------
            add.w   &TA0IV,PC               ; Add Timer_A offset vector
            reti
            xor.b   #001h,&P1OUT            ;
            add.w   #1000,&TA0CCR1          ; 
            reti		                    ;
            reti                            ; TA0CCR2 not used
            reti                            ; Reserve
            reti                            ; Reserve
            reti                            ; Reserve
            reti                            ; Reserve
            reti                            ; Overflow not used

;-------------------------------------------------------------------------------
;			Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect	".int06"        		; Timer_AX Vector
            .short	TAX_ISR                 ;
            .end