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
;   MSP430x24x Demo - USCI_A0, Ultra-Low Pwr UART 9600 RX/TX, 32kHz ACLK
;
;   Description: This program demonstrates a full-duplex 9600-baud UART using
;   USCI_A0 and a 32kHz crystal.  The program will wait in LPM3, and receive
;   a string1 into RAM starting at 200h, and echo back the complete string.
;   ACLK = BRCLK = LFXT1 = 32768, MCLK = SMCLK = DCO ~1.045MHz
;   Baud rate divider with 32768Hz XTAL @9600 = 32768Hz/9600 = 3.41
;   //* An external watch crystal is required on XIN XOUT for ACLK *//
;
;                MSP430F249
;             -----------------
;         /|\|              XIN|-
;          | |                 | 32kHz
;          --|RST          XOUT|-
;            |                 |
;            |     P3.4/UCA0TXD|------------>
;            |                 | 9600 - 8N1
;            |     P3.5/UCA0RXD|<------------
;
;
;  JL Bile
;  Texas Instruments Inc.
;  May 2008
;  Built Code Composer Essentials: v3 FET
;*******************************************************************************
 .cdecls C,LIST, "msp430.h"

;   CPU registers used
PointerTX   .equ    R4
PointerRX   .equ    R5
String1     .equ     0200h

;-------------------------------------------------------------------------------
            .text   ;Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #0500h,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP1     mov.b   #0FFh,&P1DIR            ; All P1.x outputs
            clr.b   &P1OUT                  ; All P1.x reset
SetupP2     mov.b   #0FFh,&P2DIR            ; All P2.x outputs
            clr.b   &P2OUT                  ; All P2.x reset
SetupP3     bis.b   #030h,&P3SEL            ; P3.4,5 = USCI_A0 TXD/RXD
            mov.b   #0FFh,&P3DIR            ; All P3.x outputs
            clr.b   &P3OUT                  ; All P3.x reset
SetupP4     mov.b   #0FFh,&P4DIR            ; All P4.x outputs
            clr.b   &P4OUT                  ; All P4.x reset
SetupUSCI0  bis.b   #UCSSEL_1,&UCA0CTL1     ; CLK = ACLK
            mov.b   #03h,&UCA0BR0           ; 32kHz/9600 = 3.41
            mov.b   #00h,&UCA0BR1           ;
            mov.b   #UCBRS1+UCBRS0,&UCA0MCTL; Modulation UCBRSx = 3
            bic.b   #UCSWRST,&UCA0CTL1      ; **Initialize USCI state machine**
            bis.b   #UCA0RXIE,&IE2          ; Enable USCI_A0 RX interrupt
            clr.w   PointerRX               ;
                                            ;
Mainloop    bis.w   #LPM3+GIE,SR            ; Enter LPM3 w/ int until Byte RXed
            nop                             ; Required only for debugger
                                            ;
;-------------------------------------------------------------------------------
USCI0TX_ISR;
;-------------------------------------------------------------------------------
            mov.b   @PointerTX+,&UCA0TXBUF  ; TX next character
            cmp.w   #String1+8,PointerTX    ; TX over?
            jeq     Done                    ;
            reti                            ;
Done        bic.b   #UCA0TXIE,&IE2          ; Disable USCI_A0 TX interrupt
            reti                            ;
                                            ;
;-------------------------------------------------------------------------------
USCI0RX_ISR;
;-------------------------------------------------------------------------------
            mov.b   &UCA0RXBUF,String1(PointerRX) ; Store RX data
            inc.w   PointerRX               ;
            cmp.b   #8,PointerRX            ;
            jne     UART_Done               ;
            bis.b   #UCA0RXIE+UCA0TXIE,&IE2 ; Enable USCI_A0 TX interrupt
            clr.w   PointerRX               ;
            mov.w   #String1,PointerTX      ;
            mov.b   @PointerTX+,&UCA0TXBUF  ;
UART_Done   reti                            ;
;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".int23"
            .short  USCI0RX_ISR
            .sect   ".int22"
            .short  USCI0TX_ISR
            .sect   ".reset"
            .short  RESET
            .end
            
