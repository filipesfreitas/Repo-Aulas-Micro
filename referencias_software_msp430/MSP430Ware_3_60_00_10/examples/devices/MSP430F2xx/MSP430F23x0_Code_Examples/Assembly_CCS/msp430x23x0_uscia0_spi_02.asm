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
;   MSP430F23x0 Demo - USCI_A0, SPI Interface to HC165 Shift Register
;
;   Description: This program demonstrate a USCI_A0 in SPI mode interface to a
;   an 'HC165 shift register.  Read 8-bit Data from H-A into Data.
;   ACLK = n/a, MCLK = SMCLK = default DCO ~1.2MHz, BRCLK = SMCLK/2
;
;                          MSP430F23x0
;                       -----------------
;                   /|\|              XIN|-
;                    | |                 |
;          HC165     --|RST          XOUT|-
;        ----------    |                 |
;    8  |      /LD|<---|P3.6             |
;   -\->|A-H   CLK|<---|P3.0/UCA0CLK     |
;     |-|INH    QH|--->|P3.5/UCA0SOMI    |
;     |-|SER      |    |                 |
;     v
;
;
;  JL Bile
;  Texas Instruments Inc.
;  June 2008
;  Built Code Composer Essentials: v3 FET
;*******************************************************************************
 .cdecls C,LIST, "msp430.h"

Data        .equ     0200h
;-------------------------------------------------------------------------------
			.text							; Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #450h,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop watchdog timer
SetupP3     bis.b   #021h,&P3SEL            ; P3.0,5 USCI_A0 option select
            bis.b   #040h,&P3DIR            ; P3.6 output direction
SetupSPI    bis.b   #UCCKPH+UCMSB+UCMST+UCSYNC,&UCA0CTL0 ; 3-pin, 8-bit SPI mast
            bis.b   #UCSSEL_2,&UCA0CTL1     ; SMCLK
            bis.b   #02h,&UCA0BR0
            clr.b   &UCA0BR1                ;
            clr.b   &UCA0MCTL
            bic.b   #UCSWRST,&UCA0CTL1      ; **Initialize USCI state machine**
                                            ;
Mainloop    call    #RX_HC165               ; Load HC165 value into Rx buffer
            mov.b   &UCA0RXBUF,&Data        ; Move value into Data
            jmp     Mainloop                ; Repeat
                                            ;
;-------------------------------------------------------------------------------
RX_HC165
;-------------------------------------------------------------------------------
            bic.b   #040h,&P3OUT            ; Trigger low edge on HC165 /LD
            bis.b   #040h,&P3OUT            ; Return /LD to high
            bic.b   #UCA0RXIFG,&IFG2        ; Clear U1RXBUF flag
            mov.b   #00h,&UCA0TXBUF         ; Dummy write to start SPI
L1          bit.b   #UCA0RXIFG,&IFG2        ; RXBUF ready?
            jnc     L1                      ; 1 = ready
            ret                             ;
                                            ;
;-------------------------------------------------------------------------------
;			Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect	".reset"            ; POR, ext. Reset
            .short	RESET
            .end
