; --COPYRIGHT--,BSD_EX
;  Copyright (c) 2013, Texas Instruments Incorporated
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
;  MSP430i20xx Demo - eUSCI_A0, SPI 4-Wire Master Incremented Data
;
;  Description: SPI master talks to SPI slave using 4-wire mode. Incrementing
;  data is sent by the master starting at 0x01. Received data is expected to
;  be same as the previous transmission TXData = RXData-1.
;
;  ACLK = 32kHz, MCLK = SMCLK = Calibrated DCO = 16.384MHz
;  * Ensure low_level_init.asm is included when building/running this example *
;
;  Note: Ensure slave is powered up before master to prevent delays due to
;  slave init
;
;           MSP430i20xx
;         ----------------
;     /|\|                |
;      | |                |
;      --|RST         P1.0|--> Slave Select  (UCA0STE)
;        |            P1.3|--> Data Out      (UCA0SIMO)
;        |            P1.2|<-- Data In       (UCA0SOMI)
;        |            P1.1|--> Serial Clock  (UCA0CLK)
;
;   T. Witt
;   Texas Instruments Inc.
;   October 2013
;   Built with Code Composer Studio v5.5
;******************************************************************************
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
RXData      .set    R7
TXData      .set    R8
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack                  ; Make stack linker segment known

            .text                           ; Assemble to Flash memory
            .retain                         ; Ensure current section gets linked
            .retainrefs

            .ref    init                    ; Reference external function

RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
Cal         call    #init                   ; Calibrate peripherals
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop WDT
            bis.b   #BIT0|BIT1|BIT2|BIT3,&P1SEL0 ; eUSCI_A0 Pin Function
            bic.b   #BIT0|BIT1|BIT2|BIT3,&P1SEL1
            mov.w   #UCSWRST,&UCA0CTLW0     ; eUSCI in reset
            bis.w   #UCMST|UCSYNC|UCCKPL|UCMSB|UCMODE_1|UCSTEM,&UCA0CTLW0
            ; 4-pin, 8-bit SPI master, Clock polarity high, MSB
            bis.w   #UCSSEL_1,&UCA0CTLW0    ; ACLK
            mov.b   #0x02,&UCA0BR0
            clr.b   &UCA0BR1
            bic.w   #UCSWRST,&UCA0CTLW0     ; Initialize eUSCI
            bis.w   #UCRXIE,&UCA0IE         ; Enable RX interrupt
            mov.b   #0x01,TXData

Mainloop    bis.w   #UCTXIE,&UCA0IE         ; Enable TX interrupt
            bis.w   #LPM0|GIE,SR            ; Enter LPM0 with interrupts
            mov.w   #32000,R15              ; Delay loop
Delay       dec.w   R15
            jnz     Delay
            inc.b   TXData
            jmp     Mainloop                ; Again
                                            ;
;-------------------------------------------------------------------------------
USCI_A0_ISR    ; eUSCI_A0 ISR
;-------------------------------------------------------------------------------
            add.w   &UCA0IV,PC              ; Add interrupt offset
            reti                            ; No interrupt
            jmp     RXIFG_                  ; RXIFG
            jmp     TXIFG_                  ; TXIFG
RXIFG_      mov.b   &UCA0RXBUF,RXData       ; Save RX'ed Data
            bic.w   #UCRXIFG,&UCA0IFG       ; Clear IFG
            bic.w   #LPM0,0(SP)             ; Wake up from LPM0
            reti
TXIFG_      mov.b   TXData,&UCA0TXBUF       ; Transmit character
            bic.w   #UCTXIE,&UCA0IE         ; Disable TX interrupt
            reti

;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            .sect   ".int09"                ; eUSCI_A0 Vector
            .short  USCI_A0_ISR
            .end
