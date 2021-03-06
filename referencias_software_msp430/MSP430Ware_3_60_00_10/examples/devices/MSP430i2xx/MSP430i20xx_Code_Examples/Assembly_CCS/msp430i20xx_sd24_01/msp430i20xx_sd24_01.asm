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
;  MSP430i20xx Demo - SD24, Continuous Conversion on a Group of 3 Channels
;
;  Description: This program uses the SD24 module to perform continuous
;  conversions on a group of channels (0, 1 and 2). A SD24 interrupt occurs
;  whenever the conversions have completed.
;
;  Test by applying voltages to the 3 input channels and setting a breakpoint
;  at the indicated line. Run program until it reaches the breakpoint.
;  Results (upper 16 bits only) are stored in three arrays, one for each channel.
;  These arrays are stored in 0x200, 0x210, and 0x220 respectively and can be
;  viewed in the Memory Browser window within the debugger.
;
;  ACLK = 32kHz, MCLK = SMCLK = Calibrated DCO = 16.384MHz, SD_CLK = 1.024MHz
;  * Ensure low_level_init.asm is included when building/running this example *
;
;  Notes: For minimum Vcc required for SD24 module - see datasheet
;          100nF cap btw Vref and AVss is recommended when using 1.2V ref
;
;               MSP430i20xx
;             -----------------
;         /|\|                |
;          | |                |
;          --|RST             |
;            |                |
;   Vin1+ -->|A0.0+      VREF |---+
;   Vin1- -->|A0.0-           |   |
;   Vin2+ -->|A1.0+           |  -+- 100nF
;   Vin2- -->|A1.0-           |  -+-
;   Vin3+ -->|A2.0+           |   |
;   Vin3- -->|A2.0-      AVss |---+
;
;   T. Witt
;   Texas Instruments Inc.
;   October 2013
;   Built with Code Composer Studio v5.5
;******************************************************************************
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
Ch0results  .set 0x200                      ; Offset for Ch 0 results
Ch1results  .set 0x210                      ; Offset for Ch 1 results
Ch2results  .set 0x220                      ; Offset for Ch 2 results
Num_Results .set 8                          ; Number of Results
index       .set R7                         ; Index of results
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
            mov.w   #0,index                ; Set index to 0
            mov.w   #SD24REFS,&SD24CTL      ; Internal reference
            bis.w   #SD24GRP|SD24DF,&SD24CCTL0
            bis.w   #SD24GRP|SD24DF,&SD24CCTL1
            bis.w   #SD24IE|SD24DF,&SD24CCTL2
            mov.w   #0x428,R15              ; Delay for ref to settle
Delay       dec.w   R15                     ; ~200us total
            jne     Delay
            bis.w   #SD24SC,&SD24CCTL2      ; Start conversion

Mainloop    bis.w   #LPM0|GIE,SR            ; Enter LPM0 with interrupts
            jmp     Mainloop

;-------------------------------------------------------------------------------
SD24_ISR    ; ISR for SD24
;-------------------------------------------------------------------------------
            add     &SD24IV,PC              ; Determine interrupt source
            reti                            ; No interrupt
            reti                            ; SD24OVIFG
            reti                            ; SD24MEM0
            reti                            ; SD24MEM1
            jmp     SD24_Ch2                ; SD24MEM2
            reti                            ; SD24MEM3
SD24_Ch2    mov.w   index,R15               ; Conversion completed
            rla.w   R15
            mov.w   &SD24MEM0,Ch0results(R15) ; Save Ch0 Results
            mov.w   &SD24MEM1,Ch1results(R15) ; Save Ch1 Results
            mov.w   &SD24MEM2,Ch2results(R15) ; Save Ch2 Results
            inc.w   index                   ; Increment index
            cmp.w   #Num_Results,index      ; 8 Results Saved?
            jne     Exit_ISR                ; No, continue
            clr.w   index                   ; Yes, clear index
            nop                             ; SET BREAKPOINT HERE
Exit_ISR    reti

;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            .sect   ".int07"                ; SD24 ISR
            .short  SD24_ISR
            .end
