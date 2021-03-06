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
;   MSP-FET430P430 Demo - LCD, Display "0123456" on SBLCDA4 LCD
;
;   Description: Displays "0123456" on SBLCDA4 LCD as used on 430 Day Watch
;   demo board.
;   ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
;   //* An external watch crystal between XIN & XOUT is required for ACLK *//	
;
;               MSP430FG439
;            -----------------
;        /|\|              XIN|-
;         | |                 | 32kHz
;         --|RST          XOUT|-
;           |                 |      SBLCDA4
;           |                 |      (As used on 430 Day Watch Demo board)
;         +-|R33          S0  |     -----------------
;        1m |              -  |--> | + 7 6 5 4 3 2 1 |
;         +-|R23          S21 |     -----------------
;        1m |             COM0|-----||||
;         +-|R13          COM1|------|||
;        1m |             COM2|-------||
;         +-|R03          COM3|--------|
;         | |                 |
;        Vss
;
;   L. Westlund / M. Mitchell
;   Texas Instruments Inc.
;   May 2005
;   Built with Code Composer Essentials Version: 1.0
;******************************************************************************
 .cdecls C,LIST,  "msp430.h"
;------------------------------------------------------------------------------
            .text                  ; Program Start
;------------------------------------------------------------------------------
RESET       mov.w   #0A00h,SP               ; Initialize stack pointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop Watchdog Timer
SetupFLL    bis.b   #XCAP14PF,&FLL_CTL0     ; Configure load caps

SetupLCD    mov.b   #LCDON+LCDSG0_3+LCD4MUX,&LCDCTL; 4mux LCD, segs0-23=outputs
SetupBT     mov.b   #BT_fLCD_DIV128,&BTCTL  ; Set LCD frame freq = ACLK/128
SetupIO     mov.b   #0xFC,&P5SEL            ; Common and Rxx all selected
                                            ; For P5.0 P5.1 P4.6 P4.7 setting
                                            ; SEL bits selects Analog for FG
Mainloop    clr.w   R5                      ; Clear pointer
Disp        mov.b   LCD_Tab(R5),LCDMEM(R5)  ;
            inc.w   R5                      ;
            cmp.w   #07,R5                  ;
            jne     Disp                    ;
            jmp     Mainloop                ; Again

                                            ; As used on 430 Day Watch board
LCD_Tab     .byte   0F5h                    ; displays "0"
            .byte   060h                    ; displays "1"
            .byte   0B6h                    ; displays "2"
            .byte   0F2h                    ; displays "3"
            .byte   063h                    ; displays "4"
            .byte   0D3h                    ; displays "5"
            .byte   0D7h                    ; displays "6"
            .byte   070h                    ; displays "7"
            .byte   0F7h                    ; displays "8"
            .byte   0F3h                    ; displays "9"
;-----------------------------------------------------------------------------
;           Interrupt Vectors
;-----------------------------------------------------------------------------
            .sect   ".reset"                ; RESET Vector
            .short  RESET                   ;
            .end
