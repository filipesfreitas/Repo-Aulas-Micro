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
;  MSP-FET430P140 Demo - I2C, Slave Reads/Writes to MSP430 Master
;
;  Description: This example shows the repeated start condition  It talks to
;  the MSP430F169.  It first does two writes, then sends repeated start and
;  does a read, then sets STP.
;  Access ready Interrupt occurs when 2 bytes are sent by master, and then
;  master is switched to Reciever. Another ARDY Interrupt occurs when data
;  is read from I2CDRB and then a stop condition is issued.
;  The received data is in R6 and is checked for validity. If the received
;  data is incorrect, the CPU is trapped and P1.0 LED will stay on.
;
;  This is the Slave code.
;  The Master code is called fet140_i2c_11.s43
;
;  ACLK = n/a, MCLK = SMCLK = I2CCLOCK = DCO ~ 800kHz
;  //* MSP430F15x, MSP430F16x Device Required *//
;
;                                 /|\  /|\
;                  MSP430F169     10k  10k     MSP430F169
;                    slave         |    |        master
;              -----------------|  |    |  -----------------
;             |             P3.1|<-|---+->|P3.1             |
;             |                 |  |      |             P1.0|-->LED
;             |                 |  |      |                 |
;             |             P3.3|<-+----->|P3.3             |
;             |                 |         |                 |
;
;
;   H. Grewal / L. Westlund
;   Texas Instruments Inc.
;   Nov 2005
;   Built with Code Composer Essentials Version: 1.0
;******************************************************************************
 .cdecls C,LIST,  "msp430.h"

;------------------------------------------------------------------------------
            .text                           ; Progam Start
;------------------------------------------------------------------------------
RESET       mov.w   #0A00h,SP               ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
            bis.b   #0Ah,&P3SEL             ; Select I2C pins
            bis.b   #01h,&P1DIR             ; P1.0 output
            bic.b   #01h,&P1OUT             ; Clear P1.0

I2C_init    bis.b   #I2C+SYNC,&U0CTL        ; Recommended init procedure
            bic.b   #I2CEN,&U0CTL           ; Recommended init procedure
            bis.b   #I2CSSEL1,&I2CTCTL      ; SMCLK
            mov.w   #0048h,&I2COA           ; Own Address is 048h
            bis.b   #TXRDYIE+RXRDYIE,&I2CIE ; Enable TXRDYIFG,RXRDYIFG interrupt
            bis.b   #I2CEN,&U0CTL           ; Enable I2C

            clr.w   R5                      ; Use R5 to hold TX data
            clr.w   R6                      ; Use R6 to hold RX data
            clr.w   R7                      ; use R7 to check received data
Mainloop    bis.b   #LPM0+GIE,SR            ; Enter LPM0, enable interrupts
            bic.b   #TXRDYIE+RXRDYIE,&I2CIE ; Disable TXRDYIFG,RXRDYIFG interrupt
            bis.b   #01h,&P1OUT             ; Set P1.0
            jmp     $                       ; Trap CPU

;------------------------------------------------------------------------------
I2C_ISR;    Common ISR for I2C Module
;------------------------------------------------------------------------------
            add.w  &I2CIV,PC               ; Add I2C offset vector
            reti                            ; No Interrupt
            reti                            ; Arbitration lost
            reti                            ; No Acknowledge
            reti                            ; Own Address
            reti                            ; Register Access Ready
            jmp     RXRDY_ISR               ; Receive Ready
            jmp     TXRDY_ISR               ; Transmit Ready
            reti                            ; General Call
            reti                            ; Start Condition

RXRDY_ISR   mov.b   &I2CDRB,R6              ; RX data in R5
            cmp.w   R6,R7                   ; Test received data
            jne     Trap                    ; Trap CPU if wrong
            inc.b   R7                      ; Increment correct RX value
            jmp     returnint
Trap        bic.w   #LPM0,0(SP)             ; Clear LPM0
returnint   reti

TXRDY_ISR   mov.b   R5,&I2CDRB              ; Load I2CDRB
            inc.b   R5                      ; Increment data
            reti

;------------------------------------------------------------------------------
;           Interrupt Vectors
;------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET vector
            .short  RESET                   ;
            .sect   ".int08"                ; I2C interrupt vector
            .short  I2C_ISR
            .end
