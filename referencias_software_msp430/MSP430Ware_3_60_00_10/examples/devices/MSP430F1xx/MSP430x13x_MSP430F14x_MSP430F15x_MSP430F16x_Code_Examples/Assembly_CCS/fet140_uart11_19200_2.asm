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
;   MSP-FET430P140 Demo - USART1, UART 19200 Echo ISR, XT2 HF XTAL SMCLK
;
;   Description: This program will echo a received character, RX interrupt
;   service used. XT2 oscillator used in this example.
;   ACLK = MCLK = SMCLK = UCLK1 = XT2 = 8MHz
;   Baud rate divider with 8Mhz XTAL @19200 = 8MHz/19200 = 416.66 ~417
;   //* An external 8MHz XTAL on X2IN X2OUT is required for ACLK *//	
;
;                MSP430F149
;             -----------------
;         /|\|             X2IN|-
;          | |                 | 8MHz
;          --|RST         X2OUT|-
;            |                 |
;            |             P3.6|------------>
;            |                 | 19200 - 8N1
;            |             P3.7|<------------
;
;   M. Buccini / G. Morton
;   Texas Instruments Inc.
;   May 2005
;   Built with Code Composer Essentials Version: 1.0
;******************************************************************************
 .cdecls C,LIST,  "msp430.h"
;------------------------------------------------------------------------------
            .text                           ; Progam Start
;------------------------------------------------------------------------------
RESET       mov.w   #0A00h,SP               ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP3     bis.b   #0C0h,&P3SEL            ; P3.6,7 = USART1 option select
SetupBC     bic.b   #XT2OFF,&BCSCTL1        ; XT2on
SetupOsc    bic.b   #OFIFG,&IFG1            ; Clear OSC fault flag
            mov.w   #0FFh,R15               ; R15 = Delay
SetupOsc1   dec.w   R15                     ; Additional delay to ensure start
            jnz     SetupOsc1               ;
            bit.b   #OFIFG,&IFG1            ; OSC fault flag set?
            jnz     SetupOsc                ; OSC Fault, clear flag again
            bis.b   #SELM_2+SELS,BCSCTL2    ; MCLK = SMCLK = XT2 (safe)
SetupUART1  bis.b   #UTXE1+URXE1,&ME2       ; Enable USART1 TXD/RXD
            bis.b   #CHAR,&UCTL1            ; 8-bit characters
            mov.b   #SSEL1,&UTCTL1          ; UCLK = SMCLK
            mov.b   #0A0h,&UBR01            ; 8Mhz/19200 ~ 417
            mov.b   #001h,&UBR11            ;
            mov.b   #000h,&UMCTL1           ; no modulation
            bic.b   #SWRST,&UCTL1           ; **Initialize USART state machine**
            bis.b   #URXIE1,&IE2            ; Enable USART1 RX interrupt
                                            ;
Mainloop    bis.b   #CPUOFF+GIE,SR          ; Enter LPM0, interrupts enabled
            nop                             ; Needed only for debugger
                                            ;
;------------------------------------------------------------------------------
USART1RX_ISR;  Echo back RXed character, confirm TX buffer is ready first
;------------------------------------------------------------------------------
TX2         bit.b   #UTXIFG1,&IFG2          ; USART1 TX buffer ready?
            jz      TX2                     ; Jump is TX buffer not ready
            mov.b   &RXBUF1,&TXBUF1         ; TX -> RXed character
            reti                            ;
                                            ;
;------------------------------------------------------------------------------
;           Interrupt Vectors
;------------------------------------------------------------------------------
            .sect   ".reset"                ;
            .short  RESET                   ; POR, ext. Reset, Watchdog
            .sect   ".int03"                ;
            .short  USART1RX_ISR            ; USART1 Receive
            .end
