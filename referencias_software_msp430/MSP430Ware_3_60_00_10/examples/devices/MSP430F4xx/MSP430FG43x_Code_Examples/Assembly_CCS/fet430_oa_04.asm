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
;   MSP-FET430P430 Demo - OA0, Inverting PGA Mode
;
;   Description: Configure OA0 for Inverting PGA mode. In this mode, the
;   "+" terminal must be supplied with an offset, since the OA is a
;   single-supply opamp, and the input must be positive. If an offset is
;   not supplied, the opamp will try to drive its output negative, which
;   cannot be done. In this example, the offset is provided by DAC0 and
;   is 1.5V. The "-" terminal is connected to the R ladder tap and the
;   OAFBRx bits select the gain. The input signal should be AC coupled.
;   ACLK = n/a, MCLK = SMCLK = default DCO
;
;                    MSP430FG439
;                 -------------------
;             /|\|                XIN|-
;              | |                   |
;              --|RST            XOUT|-
;                |                   |
;     "-" --||-->|P6.0/OA0I0         |
;                |                   |
;                |          P6.1/OA0O|-->  OA0 Output
;                |                   |     Gain is -7
;
;   M. Mitchell / M. Mitchell
;   Texas Instruments Inc.
;   May 2005
;   Built with Code Composer Essentials Version: 1.0
;******************************************************************************
 .cdecls C,LIST,  "msp430.h"

;------------------------------------------------------------------------------
            .text                  ; Program Start
;------------------------------------------------------------------------------
RESET       mov.w   #0A00h,SP               ; Initialize stack pointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
                                            ;
REFOn       mov.w   #REFON+REF2_5V,&ADC12CTL0
                                            ; 2.5V reference for DAC12
DAC12_0     mov.w   #DAC12IR+DAC12AMP_2+DAC12ENC,&DAC12_0CTL
                                            ; 1x input range, enable DAC120,
                                            ; low speed/current
            mov.w   #099Ah,&DAC12_0DAT      ; Set DAC120 to output 1.5V
                                            ;
SetupOA     mov.b   #OAP_2+OAPM_1+OAADC1,&OA0CTL0
                                            ; "+" connected to DAC120,
                                            ; slow slew rate,
                                            ; output connected to A1
            mov.b   #OAFC_6+OAFBR_6+OARRIP,&OA0CTL1
                                            ; Inverting PGA, gain = 7
                                            ; No r-to-r input
                                            ;						
Mainloop    bis.w   #LPM3,SR                ; Enter LPM3
            nop                             ; Required only for debug
                                            ;
;------------------------------------------------------------------------------
;           Interrupt Vectors
;------------------------------------------------------------------------------
            .sect   ".reset"                ; RESET Vector
            .short  RESET                   ;
            .end
