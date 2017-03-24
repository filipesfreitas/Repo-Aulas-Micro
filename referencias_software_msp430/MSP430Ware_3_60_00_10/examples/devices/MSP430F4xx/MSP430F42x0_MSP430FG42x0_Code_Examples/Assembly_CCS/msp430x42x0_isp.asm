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
;*****************************************************************************
;   MSP430x42x0 Demo - Flash In-System Program Memory
;
;   Description: This program demonstrates in-system programming of FLASH
;   memory. Two variable bytes @ 01080h/01081h in SegmentA are modified.
;   The subroutine Update_SegA saves the variables on the stack,
;   incrementing 01080h and decrementing 01081h. SegmentA is first erased and
;   then re-Flashed with the modified variables on the stack. Flash timing
;   generator must meet datasheet specifications. This program assumes a
;   watch crystal is used, the FLL is active, and MCLK = 1048576Hz. Test by
;   setting a breakpoint at the line indicated below and running program.
;   Upon reaching breakpoint, observe Flash memory locations 01080h/01081h
;   in a memory window.
;   ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
;   //* An external watch crystal between XIN & XOUT is required for ACLK *//	
;
;   IMPORTANT - set breakpoint to avoid stressing Flash
;
;                 MSP430F4270
;             -----------------
;         /|\|              XIN|-
;          | |                 | 32kHz
;          --|RST          XOUT|-
;            |                 |
;
;  JL Bile
;  Texas Instruments Inc.
;  June 2008
;  Built Code Composer Essentials: v3 FET
;*******************************************************************************
 .cdecls C,LIST, "msp430.h"
;------------------------------------------------------------------------------
			.text							; Program Start
;------------------------------------------------------------------------------
RESET       mov.w   #300h,SP                ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupFLL    bis.b   #XCAP14PF,&FLL_CTL0     ; Configure load caps
                                            ;				          							
Mainloop    call    #Update_SegA            ;
Delay       push.w  #0FFFFh                 ; Delay loop to minimize number of
D1          dec.w   0(SP)                   ; Flash erase/write cycles in case
            jnz     D1                      ; breakpoint is not set.
            incd.w  SP                      ;
            jmp     Mainloop                ; SET BREAKPOINT HERE
                                            ;
;------------------------------------------------------------------------------
Update_SegA; Increment byte 01080h, decrement byte 01081h in Flash SegA
;------------------------------------------------------------------------------
Timing      mov.w   #FWKEY+FSSEL0+FN1,&FCTL2  ; *Timing generator = MCLK/3
            push.b  &01081h                 ; Save contents of 01081h to stack
            push.b  &01080h                 ; Save contents of 01080h to stack
            inc.b   0(SP)                   ; Increment value on stack
            dec.b   2(SP)                   ; Decrement value on stack
                                            ;
Erase_SegA  mov.w   #FWKEY,&FCTL3           ; Lock = 0
            mov.w   #FWKEY+ERASE,&FCTL1     ; Erase bit = 1
            mov.w   #0,&01080h              ; Dummy write to SegA to erase
                                            ;
Write_SegA  mov.w   #FWKEY+WRT,&FCTL1       ; Write bit = 1
            pop.b   &01080h                 ; Write to Flash 01080h
            pop.b   &01081h                 ; Write to Flash 01081h
            mov.w   #FWKEY+LOCK,&FCTL3      ; Lock = 1
            ret                             ;
                                            ;
;-----------------------------------------------------------------------------
;           Interrupt Vectors
;-----------------------------------------------------------------------------
            .sect    ".reset"                  ; RESET Vector
            .short   RESET                   ;
            .end
