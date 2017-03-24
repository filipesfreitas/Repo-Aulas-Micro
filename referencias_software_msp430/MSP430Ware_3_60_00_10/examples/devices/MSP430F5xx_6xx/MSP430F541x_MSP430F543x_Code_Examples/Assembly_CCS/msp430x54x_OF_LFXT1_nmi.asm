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
;  MSP430F54x Demo - LFXT1 Oscillator Fault Detection
;
;  Description: System runs normally in LPM3 with basic timer clocked by
;  32kHz ACLK with a 1 second interrupt. P1.0 is normally toggled every
;  1 second inside basic timer interrupt. If an LFXT1 oscillator fault occurs,
;  NMI is requested forcing exit from LPM3. P1.0 is toggled rapidly by
;  software as long as LFXT1 oscillator fault is present. Assuumed only
;  LFXT1 as NMI source - code does not check for other NMI sources.
;  ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
;  ;* An external watch crystal between XIN & XOUT is required for ACLK *;	
;
;
;           MSP430F5438
;         -----------------
;    /|\ |              XIN|-
;     |  |                 | 32kHz
;     ---|RST          XOUT|-
;        |                 |
;        |             P1.0|-->LED
;
;   M. Morales
;   Texas Instruments Inc.
;   September 2008
;   Built with Code Composer Essentials v3.x
;******************************************************************************

    .cdecls C,LIST,"msp430.h"

count    .equ    R4 

;-------------------------------------------------------------------------------
            .global _main 
            .text                           ; Assemble to Flash memory
;-------------------------------------------------------------------------------
_main
RESET       mov.w   #0x5C00,SP              ; Initialize stackpointer
            mov.w   #WDTPW + WDTHOLD,&WDTCTL; Stop WDT    
            ; Set up XT1
            bis.b   #0x03,&P7SEL            ; Analog function for XT1 Pins
            bic.w   #XT1OFF,&UCSCTL6        ; XT1 On
            bic.w   #XCAP_3,&UCSCTL6        ; Internal load cap

            bis.b   #BIT0,&P1DIR            ; P1.0 output

            mov.w   #RTCTEV_3,&RTCCTL01     ; 32-bit overflow RTC time event
            mov.w   #RT0PSDIV_7,&RTCPS0CTL  ; Set RTPS0 to /256
            mov.w   #RT1IP_6 + RT1PSIE + RT1SSEL_3,&RTCPS1CTL
                                            ; Set RT1IP to /4, enable
                                            ; RT1PS interrupt and select
                                            ; RTOPS output as clock

            mov.w   #OFIE,&SFRIE1           ; Enable osc fault interrupt

            bis.w   #LPM3 + GIE,SR          ; Enter LPM3, enable interrupts
            nop                             ; For debugger
            
;-------------------------------------------------------------------------------
RTC_ISR     ; RTC isr 
;-------------------------------------------------------------------------------
             xor.b    #0x01,&P1OUT          ; Toggle P1.0
             bic.w    #RTCTEVIFG,&RTCCTL01  
             bic.w    #RT1PSIFG,&RTCPS1CTL  
             reti 

;-------------------------------------------------------------------------------
UNMI_ISR    ; UNMI isr - wait until oscillators stabilize before continuing operation
;------------------------------------------------------------------------------- 
do_while    bic.w     #XT1LFOFFG + DCOFFG,&UCSCTL7   
                                            ; Clear XT1 & DCO fault flags
            bic.w     #OFIFG,&SFRIFG1       ; Clear OSC Fault flag
            mov.w     #0xFFFF,count       
osc_delay   dec.w     count                 ; Time for flag to set
            jne       osc_delay             
            xor.b     #BIT0,&P1OUT          ; Toggle P1.0 using exclusive-OR
            bit.w     #OFIFG,&SFRIFG1              
            jc        do_while            
            reti

;-------------------------------------------------------------------------------
                  ; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".int41"    
            .short  RTC_ISR
            .sect   ".int61"    
            .short  UNMI_ISR
            .sect   ".reset"                ; POR, ext. Reset
            .short  RESET
            .end
