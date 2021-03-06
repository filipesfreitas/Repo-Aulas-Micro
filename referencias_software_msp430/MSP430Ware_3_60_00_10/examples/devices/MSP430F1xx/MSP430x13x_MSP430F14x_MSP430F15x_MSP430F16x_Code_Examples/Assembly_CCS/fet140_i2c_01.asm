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
;   MSP-FET430P140 Demo - I2C, Master Intf. to TMP100, .set P1.0 if Temp > 28C
;
;   Description: I2C interface to TMP100 temperature sensor in 9-bit mode.
;   Timer_A CCR0 interrupt is used to wake up and read the two bytes of
;   the TMP100 temperature register. If the temperature is greater than 28C,
;   P1.0 is set, else reset. CPU is normally off and used only during TA_ISR.
;   ACLK = n/a, MCLK = SMCLK = TACLK = I2CCLOCK = default DCO ~800kHz
;   //* MSP430F169 Device Required *//
;
;
;          /|\           /|\ /|\
;           |   TMP100   10k 10k     MSP430F169
;           |   -------   |   |  -----------------
;           +--|Vcc SDA|<-|---+>|P3.1         P1.0|---> LED
;           |  |       |  |     |                 |
;           +--|A1,A0  |  |     |                 |
;              |       |  |     |                 |
;           ---|Vss SCL|<-+-----|P3.3             |
;          \|/  -------         |                 |
;
;   M. Buccini / L. Westlund
;   Texas Instruments Inc.
;   May 2005
;   Built with Code Composer Essentials Version: 1.0
;******************************************************************************
 .cdecls C,LIST,  "msp430.h"
;------------------------------------------------------------------------------
            .text                  ; Progam Start
;------------------------------------------------------------------------------
RESET       mov.w   #0A00h,SP               ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
            bis.b   #01h,&P1DIR             ;
SetupP3     bis.b   #0Ah,&P3SEL             ; Assign I2C pins to module
SetupI2C    bis.b   #SYNC+I2C,&U0CTL        ; Switch USART0 to I2C mode
            bic.b   #I2CEN, U0CTL           ; Recommended I2C init procedure
            mov.b   #I2CWORD+I2CSSEL1,&I2CTCTL ; SMCLK, word mode
            mov.b   #003h,&I2CSCLH          ; High period of SCL
            mov.b   #003h,&I2CSCLL          ; Low period of SCL
            mov.b   #002h,&I2CNDAT          ; transfer two bytes
            mov.w   #04Eh,&I2CSA            ; .set slave address
            bis.b   #I2CEN,&U0CTL           ; Enable I2C
            mov.w   #CCIE,&CCTL0            ; CCR0 interrupt enabled
            mov.w   #TASSEL_2+ MC_2,&TACTL  ; SMCLK, contmode
                                            ;
Mainloop    bis.w   #CPUOFF+GIE,SR          ; CPU off, interrupts enabled
            nop                             ; Required for debugger
                                            ;
;------------------------------------------------------------------------------
TA0_ISR;
;------------------------------------------------------------------------------
            mov.w   &I2CDRW,R4              ; R4 = Temp data
            swpb    R4                      ;
            cmp.w   #01E00h,R4              ;  > 28c?
            jlo     Low_Temp                ;
            bis.b   #01h,&P1OUT             ; P1.0 = 1
            jmp     Next_Temp               ;
Low_Temp    bic.b   #01h,&P1OUT             ; P1.0 = 0
Next_Temp   bis.b   #MST,&U0CTL             ; Master
            bis.b   #I2CSTT+I2CSTP,&I2CTCTL ; Read, ST, SP (clears MST)
            reti                            ;		
                                            ;
;------------------------------------------------------------------------------
;           Interrupt Vectors
;------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET                   ;
            .sect   ".int06"                ; Timer_A0 Vector
            .short  TA0_ISR                 ;
            .end
