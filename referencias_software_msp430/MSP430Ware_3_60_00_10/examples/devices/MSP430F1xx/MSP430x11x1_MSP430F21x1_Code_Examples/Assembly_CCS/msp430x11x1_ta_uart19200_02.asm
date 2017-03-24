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
;   MSP430x11x1 Demo - Timer_A, Ultra-Low Pwr UART 19200 Echo, 32kHz ACLK
;
;   Description: This program demonstrates a half-duplex 19200-baud UART using
;   Timer_A3 and a 32kHz crystal. The program will wait in LPM3, echoing back
;   a received character using 8N1 protocol.  The Set_DCO subroutine will
;   calibrate the DCOCLK to ~2MHz, which is used as the Timer_A clock.
;   ACLK = LFXT1/8 = 32768/8, MCLK = SMCLK = target DCO
;   ;* External watch crystal installed on XIN XOUT is required for ACLK *//	
;
;                MSP430F1121
;             -----------------
;         /|\|              XIN|-
;          | |                 | 32k
;          --|RST          XOUT|-
;            |                 |
;            |   CCI0A/TXD/P1.1|-------->
;            |                 | 19200 8N1
;            |   CCI0B/RXD/P2.2|<--------
;
;   CPU registers used
RXTXData .equ     R4
BitCnt   .equ     R5
;
;   Conditions for 19200 Baud HW/SW UART, SMCLK = DCOCLK ~ 2Mhz
Bitime_5    .equ    42                      ; 0.5 bit length
Bitime      .equ    104                     ; 52 us
Delta       .equ    488                     ; DCOCLK = (Delta)/(32768/8)

RXD         .set    004h                    ; RXD on P2.2
TXD         .set    002h                    ; TXD on P1.1
;
;   M. Buccini / Z. Albus
;   Texas Instruments Inc.
;   May 2005
;   Built with Code Composer Essentials Version: 1.0
;*******************************************************************************
 .cdecls C,LIST,  "msp430.h"
;-------------------------------------------------------------------------------
            .text                           ; Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #300h,SP                ; Initialize Stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupBC     bis.b   #DIVA_3,&BCSCTL1        ; ACLK=LFXT1CLK/8
Setup_TA    mov.w   #TASSEL_2+MC_2,&TACTL   ; SMCLK, ContMode
            call    #Set_DCO                ; Calibrate DCO
SetupC0     mov.w   #OUT,&CCTL0             ; TXD Idle as Mark
SetupP1_2   bis.b   #TXD,&P1SEL             ; P1.1/TA0 for TXD function
            bis.b   #TXD,&P1DIR             ; TXD output on P1
            bis.b   #RXD,&P2SEL             ; P2.2/TA0 as RXD input
                                            ;
Mainloop    call    #RX_Ready               ; UART ready to RX one Byte
            bis.w   #LPM3+GIE,SR            ; Enter LPM3 w/ int until Byte RXed
            call    #TX_Byte                ; TX Back RXed Byte Received
            jmp     Mainloop                ;
                                            ;
;-------------------------------------------------------------------------------
TX_Byte   ; Subroutine that Transmit One Byte from RXTXData Buffer.
;-------------------------------------------------------------------------------
            mov.w   &TAR,&CCR0              ; Current state of TA Counter
            add.w   #Bitime,&CCR0           ; Some time till first bit
            bis.w   #0100h, RXTXData        ; Add mark stop bit to RXTXData
            rla.w   RXTXData                ; Add space start bit
            mov.w   #10,BitCnt              ; Load Bit Counter, 8data + ST/SP
            mov.w   #OUTMOD0+CCIE,&CCTL0    ; TXD = mark = idle
TX_Wait     bit.w   #CCIE,&CCTL0            ; Wait for TX completion
            jnz     TX_Wait                 ;
            ret                             ;
                                            ;
;-------------------------------------------------------------------------------
RX_Ready  ; Subroutine that will Receive One Byte into RXTXData Buffer.
          ; !! Sync capture not possible as DCO=TACLK=SMCLK can be off !!
;-------------------------------------------------------------------------------
            mov.w   #8,BitCnt               ; Load Bit Counter, 8 data bits
SetupRX     mov.w   #CM1+CCIS0+OUTMOD0+CAP+CCIE,&CCTL0; Neg Edge,Cap
            ret                             ;
                                            ;
;-------------------------------------------------------------------------------
TA0_ISR  ;  CCR0/UART ISR:   RXTXData Buffer holds UART Data.
;-------------------------------------------------------------------------------
            add.w   #Bitime,&CCR0           ; Time to Next Bit
            bit.w   #CCIS0,&CCTL0           ; RX on ISCCIB?
            jnz     UART_RX                 ; Jump --> RX
UART_TX     cmp.w   #00h,BitCnt             ;
            jne     TX_Next                 ; Next bit?
            bic.w   #CCIE,&CCTL0            ; All Bits TX or RX, Disable Int.
            reti                            ;
TX_Next     bic.w   #OUTMOD2,&CCTL0         ; TX Mark
            rra.w   RXTXData                ; LSB is shifted to carry
            jc      TX_Test                 ; Jump --> bit = 1
TX_Space    bis.w   #OUTMOD2,&CCTL0         ; TX Space
TX_Test     dec.w   BitCnt                  ; All bits sent (or received)?
            reti                            ;
                                            ;
UART_RX     bit.w   #CAP,&CCTL0             ; Compare mode for start bit edge
            jz      RX_Bit                  ; Start bit edge?
RX_Edge     bic.w   #CAP,&CCTL0             ; Switch to Compare mode
            add.w   #Bitime_5,&CCR0         ; First databit 1.5 bits from edge
            mov.w   #CPUOFF+GIE,0(SP)       ; !!! DCO needs to remain on !!!
            reti                            ;
RX_Bit      bit.w   #SCCI,&CCTL0            ; Get bit waiting in receive latch
            rrc.b   RXTXData                ; Store received bit
RX_Test     dec.w   BitCnt                  ; All bits sent (or received)?
            jnz     RX_Next                 ; Next bit?
;>>>>>>>>>> Decode of Received Byte Here <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
RX_Comp     bic.w   #CCIE,&CCTL0            ; All Bits RXed, Disable Interrupt
            mov.w   #GIE,0(SP)              ; Decode Byte= Active in Mainloop
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
RX_Next     reti                            ;
                                            ;
;-------------------------------------------------------------------------------
Set_DCO;    Subroutine: Sets DCO to selected frequency based on Delta.
;           R14 and R15 are used, ACLK = 32768/8 Timer_A clocked by DCOCLK
;-------------------------------------------------------------------------------
            clr.w   R15                     ;							
Setup_CC2   mov.w   #CM_1+CCIS_1+CAP,&CCTL2 ; CAP, ACLK
Test_DCO    bit.w   #CCIFG,&CCTL2           ; Test capture flag
            jz      Test_DCO                ;
            bic.w   #CCIFG,&CCTL2           ; Clear capture flag
                                            ;
AdjDCO      mov.w   &CCR2,R14               ; R14 = captured SMCLK
            sub.w   R15,R14                 ; R14 = capture difference
            mov.w   &CCR2,R15               ; R15 = captured SMCLK
            cmp.w   #Delta,R14              ; Delta = SMCLK/(32768/8)
            jlo     IncDCO                  ;
            jeq     DoneDCO                 ;
DecDCO      dec.b   &DCOCTL                 ; Slow DCO with DCO and MOD
            jc      Test_DCO                ; Slower?
            cmp.b   #XT2OFF+DIVA_3,&BCSCTL1 ; Can RSEL.x be decremented?
            jz      DoneDCO                 ; jmp>DCO at slowest setting
            dec.b   &BCSCTL1                ; Decrement RSEL.x
            jmp     Test_DCO                ;
IncDCO      inc.b   &DCOCTL                 ; Speed DCO with DCO and MOD
            jnc     Test_DCO                ; Faster?
            cmp.b   #XT2OFF+DIVA_3+07h,&BCSCTL1; Can RSEL.x be increased?
            jz      DoneDCO                 ; jmp> DCO at fastest setting
            inc.b   &BCSCTL1                ; Increment RSEL.x
            jmp     Test_DCO                ;
DoneDCO     clr.w   &CCTL2                  ; Stop CCR2
            ret                             ; Return from subroutine
                                            ;
;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET                   ;
            .sect   ".int09"                ; Timer_A0 Vector
            .short  TA0_ISR                 ;
            .end

