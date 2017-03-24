/* --COPYRIGHT--,BSD
 * Copyright (c) 2014, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/*
 *  main.c
 *  RO_COMPB_TB0_WDTA example with the MSP430F5529.
 *
 *     c-+------------------R--+--<PortMap/TB0CLK/CBOUT
 *       |                     |
 *       |  c-+-------------R--+
 *       |    |                |
 *       |    | c-+---------R--+
 *       |    |   |            |
 *       |    |   | c-+-----R--+
 *       |    |   |   |        |
 *       |    |   |   | c-+-R--+
 *       |    |   |   |   |
 *       |    |   |   |   +------->CB0
 *       |    |   |   +----------->CB1
 *       |    |   +--------------->CB2
 *       |    +------------------->CB3
 *       +------------------------>CB4
 *
 *  In order to access the TimerB0 clock input the port mapping value must be 
 *  set to 1 (see Table 9 of the MSP430F551x,MSP430F552x datasheet).  In this 
 *  example the TB0CLK/CBOUT function is ported to pin 4.7.
 *
 *  Some MSP430 devices allow the digital IO to be driven from a different 
 *  voltage rail (DVIO) than the voltage rail (VCC) that the Comp_B peripheral 
 *  uses.  If the comparator output, CBOUT, uses DVIO and DVIO is different 
 *  from VCC, then the input high and input low values set within the library 
 *  need to be updated.  These values are set in the Comp_B control register 2,
 *  CBCTL2, found in the CTS_HAL.c file.
 *
 *  The element and sensor definitions found in the configuration file 
 *  structure.c use designated initializer lists. This allows members to be 
 *  initialized in any order and also enhances the readability of the element
 *  being initialized.  
 *  This feature requires the GCC language extension found in Code Composer 
 *  Studio (CCS).  C99 is the default dialect found in IAR and therefore the 
 *  default settings can be used.
 */
#include "CTS_Layer.h"

#define NUM_KEYS	5
#define LED4		BIT5
#define LED5		BIT4
#define LED6		BIT3
#define LED7		BIT3
#define LED8		BIT1

uint16_t dCnt[NUM_KEYS];
struct Element* keypressed;

const struct Element* address_list[NUM_KEYS] =
{
	&element0,
	&element1,
	&element2,
	&element3,
	&element4
};						
/*
 *  Invert order of LEDs so that when pad1 is touched the LED with pad5 is
 *  illuminated.
 */
const uint8_t ledMask[NUM_KEYS] = {
		LED4,
		LED5,
		LED6,
		LED7,
		LED8
};
/*
 *  ======== main() ========
 */
uint16_t main(void)
{ 
    uint8_t i;
    WDTCTL = WDTPW + WDTHOLD;     // Stop watchdog timer
    /* Default DCO frequency, ACLK = REFO */
    UCSCTL4 |= SELA_2;
    /* Port Map P4.7 to TB0CLK/CBOUT */
    PMAPKEYID = 0x2D52;  // Unlock
    P4MAP7 = 1;          // Port Px.y map
    PMAPKEYID = 0xFFFF;  // Illegal write to lock
    /* Initialize IO */
	P1DIR = 0xFF;
	P2DIR = 0xFF;
	P3DIR = 0xFF;
	P4DIR = 0xFF;
	P5DIR = 0xFF;
	P6DIR = 0xFF;
	P7DIR = 0xFF;
	P8DIR = 0xFF;
	P1OUT = 0;
	P2OUT = 0;
    P3OUT = 0;
	P4OUT = 0;
	P5OUT = 0;
	P6OUT = 0;
	P7OUT = 0;
	P8OUT = 0;
	/*
	 *  establish baseline
	 */
	TI_CAPT_Init_Baseline(&keypad);
	TI_CAPT_Update_Baseline(&keypad,5);
	while (1)
	{
		P1OUT &= ~(LED4+LED5+LED6+LED7+LED8);
	    keypressed = (struct Element *)TI_CAPT_Buttons(&keypad);
	    TI_CAPT_Custom(&keypad,dCnt);
	    __no_operation();
	    if(keypressed)
	    {
		    for(i=0; i<NUM_KEYS; i++)
		    {
			    if (keypressed == address_list[i])
			    {
				    P1OUT |= ledMask[i];
			    }
		    }
	    }
	    __delay_cycles(10000);
	} // while loop
} // End Main
/*
 *  Initialize all unused interrupt vectors
 */
#pragma vector=RTC_VECTOR,PORT2_VECTOR,TIMER0_A0_VECTOR,                    \
  USCI_B1_VECTOR,USCI_A1_VECTOR,PORT1_VECTOR,TIMER1_A1_VECTOR,DMA_VECTOR,   \
  TIMER0_A1_VECTOR,TIMER1_A0_VECTOR,TIMER2_A0_VECTOR,TIMER2_A1_VECTOR,      \
  USCI_B0_VECTOR,USCI_A0_VECTOR,TIMER0_B1_VECTOR,TIMER0_B0_VECTOR,          \
  ADC12_VECTOR,COMP_B_VECTOR,UNMI_VECTOR,SYSNMI_VECTOR,USB_UBM_VECTOR
__interrupt void ISR_trap(void)
{
    /* The following will cause a software BOR */
 	PMMCTL0 = PMMPW | PMMSWBOR;
}

