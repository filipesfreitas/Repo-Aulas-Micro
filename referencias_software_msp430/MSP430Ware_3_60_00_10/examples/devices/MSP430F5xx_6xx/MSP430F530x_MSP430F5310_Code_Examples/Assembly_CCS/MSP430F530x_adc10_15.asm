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
;  MSP430F550x Demo - ADC10, DMA Sample A11 32x to Flash, Int Ref, DCO
;
;  Description: Sample A11 (AVCC/2) 32x, Int reference, and transfer
;  code via DMA to Flash. Software writes to ADC10SC to trigger sample burst.
;  Each ADC10 sample & convert = (32+13)*2/SMCLK = 90/SMCLK = 75us
;  Enough time is provided between ADC10 conversions for each word moved by
;  the DMA to Flash to program. DMA transfers ADC10 code to Flash 1800h-183Fh.
;  In the Mainloop, the MSP430 waits in LPM0 during conversion and programming,
;  DMA_ISR will force exit from LPM0 in Mainloop.
;
;               MSP430F550x
;            -----------------
;        /|\|              XIN|-
;         | |                 |
;         --|RST          XOUT|-
;           |                 |
;           |A11              |
;
;  K. Chen
;  Texas Instruments Inc.
;  March 2012
;  Built with CCS Version: 5.2
;*******************************************************************************

 .cdecls C,LIST, "msp430.h"

            .global _main
            .global __STACK_END
            .sect   .stack                  ; Make stack linker segment known
;-------------------------------------------------------------------------------
            .text                           ; Assemble to Flash memory
            .retain                         ; Ensure current section gets linked
            .retainrefs
;-------------------------------------------------------------------------------
_main
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop WDT

; Configure ADC10
SetupADC10  mov.w   #ADC10SHT_3 | ADC10MSC | ADC10ON,&ADC10CTL0
                                            ; 32ADCclks, ADC on
            mov.w   #ADC10SHP|ADC10CONSEQ_2|ADC10SSEL_3|ADC10DIV_1,&ADC10CTL1
                                            ; SMCLK/2, Sampling timer, 
                                            ; rpt single ch            
            mov.w   #ADC10RES,&ADC10CTL2    ; 10-bit conversion results
            mov.w   #ADC10INCH_11 | ADC10SREF_1,&ADC10MCTL0 ; Vref|, A11
            
; Configure internal reference
while_loop  and.w   #REFGENBUSY,&REFCTL0    ; If ref generator busy, WAIT       
            jnz     while_loop              ; 
            bis.w   #REFVSEL_0 | REFON,&REFCTL0
                                            ; Internal Reference ON; Vref=1.5V            
; Delay (~75us) for Ref to settle
            mov.w   #75,R4                  ; Initialize loop counter R4=75
delay_loop  dec.w   R4                      ; Decrement loop counter
            jnz     delay_loop              ; Loop if loop counter > 0
            
; Configure DMA (ADC10IFG trigger)
            mov.w   #DMA0TSEL_24,&DMACTL0   ; ADC10IFG trigger
            movx.a  #ADC10MEM0,&DMA0SA      ; Source single address
            movx.a  #0x1800,&DMA0DA         ; Destination array address
            mov.w   #0x20,&DMA0SZ           ; 32 conversions
            mov.w   #DMADT_4 | DMADSTINCR_3 | DMAEN | DMAIE,&DMA0CTL
                                            ; enable int after 32 conversions
            
while_loop1 mov.w   #FWKEY,&FCTL3           ; Lock = 0
            mov.w   #FWKEY | ERASE,&FCTL1   ; Erase bit = 1
            clr.w   &0x1800                 ; Dummy write to erase Flash seg
while_loop2 bit.w   #ADC10BUSY,&ADC10CTL1   ; Wait if ADC10 core is active
            jc      while_loop2             ;
            mov.w   #FWKEY | WRT,&FCTL1     ; Write bit = 1
            bis.w   #ADC10ENC | ADC10SC,&ADC10CTL0
                                            ; Start sampling
            nop
            bis.w   #LPM0|GIE,SR            ; LPM0, ADC10_ISR will force exit
            nop
            mov.w   #FWKEY | LOCK,&FCTL3    ; Lock = 1
            nop                             ; << SET BREAKPOINT HERE
            mov.w   #0x681,R15              ; Delay between conversions
delay       add.w   #0xFFFF,R15             ;
            jc      delay                   ; 
            jmp     while_loop1             ; 
            nop                             ; 
                                                            
;-------------------------------------------------------------------------------
DMA_ISR;
;-------------------------------------------------------------------------------
            add.w   &DMAIV,PC               ; Add offset to PC
            reti                            ; Vector 0:  No interrupt
            jmp     DMA0_HND                ; Vector 2:  DMA0IFG
            reti                            ; Vector 4:  DMA1IFG
            reti                            ; Vector 6:  DMA2IFG
            reti                            ; Vector 8:  Reserved
            reti                            ; Vector 10: Reserved               
            reti                            ; Vector 12: Reserved
            reti                            ; Vector 14: Reserved
            reti                            ; Vector 16: Reserved
                        
DMA0_HND
; 32 conversions complete             
            bic.w   #ADC10ENC,&ADC10CTL0    ; Clear interrupt flag 
            bic.w   #LPM0,0(SP)             ; exit LPM
            reti
            
;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   DMA_VECTOR              ; DMA Vector
            .short  DMA_ISR                 ;
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET                   ;
            .end
