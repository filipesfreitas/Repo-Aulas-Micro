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
;   MSP430F41x2 Demo - USCI_A0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK
;
;   Description: Echo a received character, RX ISR used. Normal mode is LPM3,
;   USCI_A0 RX interrupt triggers TX Echo.
;   ACLK = BRCLK = LFXT1 = 32768, MCLK = SMCLK = DCO~1048k
;   Baud rate divider with 32768hz XTAL @2400 = 32768Hz/2400 = 13
;   //* An external watch crystal is required on XIN XOUT for ACLK *//	
;
;
;                MSP430F41x2
;             -----------------
;         /|\|              XIN|-
;          | |                 | 32kHz
;          --|RST          XOUT|-
;            |                 |
;            |     P6.5/UCA0RXD|------------>
;            |                 | 2400 - 8N1
;            |     P6.6/UCA0TXD|<------------
;
;  P. Thanigai
;  Texas Instruments Inc.
;  January 2009
;  Built with CCE Version: 3.1
;******************************************************************************
 .cdecls C,LIST, "msp430.h" 
 
            .global _main
;------------------------------------------------------------------------------
            .text                           ; Program Start
;------------------------------------------------------------------------------
_main
RESET       mov.w   #0400h,SP               ; Initialize stack pointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupFLL    bis.b   #XCAP11PF,&FLL_CTL0     ; Configure load caps

OFIFGcheck  bic.b   #OFIFG,&IFG1            ; Clear OFIFG
            mov.w   #047FFh,R15             ; Wait for OFIFG to set again if
OFIFGwait   dec.w   R15                     ; not stable yet
            jnz     OFIFGwait
            bit.b   #OFIFG,&IFG1            ; Has it set again?
            jnz     OFIFGcheck              ; If so, wait some more

SetupP6     bis.b   #BIT5+BIT6,&P6SEL       ; P6.5,6 USCI option select
SetupUART   bis.b   #UCSSEL_1,&UCA0CTL1     ; CLK = ACLK
            mov.b   #13,&UCA0BR0            ; 32k/2400 - 13
            mov.b   #00h,&UCA0BR1           ;
            mov.b   #0Ch,&UCA0MCTL          ; Modulation
            bic.b   #UCSWRST,&UCA0CTL1      ; **Initialize USCI state machine**
            bis.b   #UCA0RXIE,&IE2          ; Enable USCI_A0 RX interrupt
                                            ;
Mainloop    bis.b   #LPM3+GIE,SR            ; Enter LPM3, interrupts enabled
            nop                             ; Required for debugger
                                            ;
;------------------------------------------------------------------------------
USCIA0RX_ISR;  Echo back RXed character, confirm TX buffer is ready first
;------------------------------------------------------------------------------
TX0         bit.b   #UCA0TXIFG,&IFG2        ; USCI_A0 TX buffer ready?
            jz      TX0                     ; Jump if TX buffer not ready
            mov.b   &UCA0RXBUF,&UCA0TXBUF   ; TX -> RXed character
            reti                            ;
                                            ;
;------------------------------------------------------------------------------
;			Interrupt Vectors
;------------------------------------------------------------------------------
            .sect    ".int09"       		;
            .short   USCIA0RX_ISR           ; USCI receive
            .sect    ".reset"            	; POR, ext. Reset, Watchdog
            .short   RESET                  ;
            .end
