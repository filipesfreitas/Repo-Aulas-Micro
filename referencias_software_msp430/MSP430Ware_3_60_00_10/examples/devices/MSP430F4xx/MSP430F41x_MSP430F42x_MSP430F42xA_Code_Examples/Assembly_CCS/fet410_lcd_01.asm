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
;   MSP-FET430P410 Demo - LCD, Display "6543210" on STK/EVK LCD
;
;   Description: Display "6543210" on MSP-EVK430S320 LCD.
;   ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
;   ;* An external watch crystal between XIN & XOUT is required for ACLK *//	
;
;                                 Connections MSP430 -> LCD
;                                 -------------------------
;
;                                              T.I. MSP-EVK430S320
;                             MSP430F449       6.5 digit 4 mux LCD
;                                                    #T218010
;                       /|\ ---------------       --------------
;                        | |          COM3 |-----|2    COM4     |
;                        --|RST       COM2 |-----|1    COM3     |
;                          |          COM1 |-----|3    COM2     |
;                          |          COM0 |-----|4,20 COM1     |
;                         -|XIN       SEG0 |-----|19            |
;                     32kHz|          SEG1 |-----|18            |
;                         -|XOUT      SEG2 |-----|17            |
;                          |          SEG3 |-----|16            |
;                          |          SEG4 |-----|15            |
;                          |          SEG5 |-----|14            |
;                          |          SEG6 |-----|13            |
;                          |          SEG7 |-----|12            |
;                        +-|R33       SEG8 |-----|11            |
;                       1M |          SEG9 |-----|10            |
;                        +-|R23       SEG10|-----|9             |
;                       1M |          SEG11|-----|8             |
;                        +-|R13       SEG12|-----|7             |
;                       1M |          SEG13|-----|6             |
;                        +-|R03       SEG14|-----|5 (bits C,E,H |
;                        | |               |     |   of digit 7)|
;                       Vss ---------------       --------------
;
;   M. Buccini / S. Karthikeyan
;   Texas Instruments Inc.
;   May 2005
;   Built with Code Composer Essentials Version 1.0
;******************************************************************************
 .cdecls C,LIST,  "msp430.h"
;------------------------------------------------------------------------------
            .text                           ; Program Start
;------------------------------------------------------------------------------
RESET       mov.w   #300h,SP                ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop Watchdog Timer
SetupFLL    bis.b   #XCAP14PF,&FLL_CTL0     ; Configure load caps
SetupLCD    mov.b   #LCDON+LCD4MUX+LCDP2,&LCDCTL    ; STK LCD 4Mux, S0-S17
SetupBT     mov.b   #BTFRFQ1,&BTCTL         ; STK LCD freq.
SetupIO     mov.b   #0FCh,&P5SEL            ; Common and Rxx all selected
                                            ;
Mainloop    clr.w   R5                      ; Clear pointer
Disp        mov.b   LCD_Tab(R5),LCDMEM(R5)  ;
            inc.w   R5                      ;
            cmp.w   #07,R5                  ;
            jne     Disp                    ;
            jmp     Mainloop                ; Again
                                            ;
LCD_Tab     .byte   0B7h                    ; displays "0"
            .byte   012h                    ; displays "1"
            .byte   08Fh                    ; displays "2"
            .byte   01Fh                    ; displays "3"
            .byte   03Ah                    ; displays "4"
            .byte   03Dh                    ; displays "5"
            .byte   0BDh                    ; displays "6"
            .byte   013h                    ; displays "7"
            .byte   0BFh                    ; displays "8"
            .byte   03Fh                    ; displays "9"
                                            ;										
;-----------------------------------------------------------------------------
;           Interrupt Vectors
;-----------------------------------------------------------------------------
            .sect     ".reset"                  ; RESET Vector
            .short  RESET                   ;
            .end
