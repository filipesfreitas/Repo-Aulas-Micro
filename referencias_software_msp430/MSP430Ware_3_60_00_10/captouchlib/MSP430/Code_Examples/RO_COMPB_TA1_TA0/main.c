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
 *  RO_COMPB_TA1_TA0 example with the MSP430F5529 Experimenters Board
 *
 *  Schematic
 *   PAD5-+-----------------------------R--+--<P1.6/TA1CLK/CBOUT
 *        |                                |
 *        | PAD4-+----------------------R--+
 *        |      |                         |
 *        |      | PAD3-+---------------R--+
 *        |      |      |                  |
 *        |      |      | PAD2-+--------R--+
 *        |      |      |      |           |
 *        |      |      |      | PAD1-+-R--+
 *        |      |      |      |      |
 *        |      |      |      |      +------->CB0
 *        |      |      |      +-------------->CB1
 *        |      |      +--------------------->CB2
 *        |      +---------------------------->CB3
 *        +----------------------------------->CB4
 *
 *                          LED4--------R-----<P1.5
 *                          LED5--------R-----<P1.4
 *                          LED6--------R-----<P1.3
 *                          LED7--------R-----<P1.2
 *                          LED8--------R-----<P1.1
 *
 *  In this keypad application, when an electrode (PAD1-PAD5 on the PCB) is 
 *  touched the LED within the opposite electrode is turned on.  Touching PAD1
 *  illumines the LED within PAD5 and touching PAD5 illumines PAD1.  The 
 *  exception is the middle pad, PAD3. However it is difficult to see this LED
 *  while touching PAD3.
 *  The gate time for each element defined in sensor keypad is about 1.5ms. The 
 *  the time it takes to measure all five elements is approximately 7.5ms.
 *  The scan rate for the sensor keypad is approximately 24ms plus the 7.5ms it 
 *  takes to measure all five elements wihtin the sensor.
 *  1/(24ms + 7.5ms) ~ 32Hz
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
#define LED7		BIT2
#define LED8		BIT1

// uint16_t dCnt[NUM_KEYS];
struct Element* keypressed;

const struct Element* address_list[NUM_KEYS] =
{
	&PAD1,
	&PAD2,
	&PAD3,
	&PAD4,
	&PAD5
};						
/*
 * Invert order of LEDs so that when pad1 is touched the LED with pad5 is
 * illuminated.
 */
const uint8_t ledMask[NUM_KEYS] = 
{
    LED4,
    LED5,
    LED6,
    LED7,
    LED8
};
void sleep(uint16_t);
/*
 *  ======== main() ========
 */
uint16_t main(void)
{ 
    uint8_t i;
    WDTCTL = WDTPW + WDTHOLD;     /* Stop watchdog timer */
    /* Default DCO frequency, ACLK = REFO */
    UCSCTL4 |= SELA_2;
    /* Initialize IO */
	P1DIR = 0xFF;
	P2DIR = 0xFF;
	P8DIR = 0xFF;
	P1OUT = 0;
	P2OUT = 0;
	P8OUT = 0;
	/* establish baseline */
	TI_CAPT_Init_Baseline(&keypad);
	TI_CAPT_Update_Baseline(&keypad,5);
	while (1)
	{
		P1OUT &= ~(LED4+LED5+LED6+LED7+LED8);
	    keypressed = (struct Element *)TI_CAPT_Buttons(&keypad);
	    // TI_CAPT_Custom(&keypad,dCnt);
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
	    /* 
         * 24ms delay
         * This delay can be replaced with other application tasks. 
         */
        sleep(768);
	} /* End while loop */
} /* End Main */

/*
 *  ======== sleep(uint16_t) ========
 *  Place device into LPM3.  Source of TimerA0 is ACLK.  The ISR is found in the 
 *  library, in CTS_HAL.c
 */
void sleep(uint16_t time)
{
    TA0CCR0 = time;
    TA0CTL = MC_1+TACLR+TASSEL_1; 
    TA0CCTL0 &= ~(CAP+CCIFG); 
    TA0CCTL0 |= CCIE; 
    __bis_SR_register(LPM3_bits+GIE);
    __no_operation();
    __disable_interrupt();
    TA0CTL &= ~(MC_1);
    TA0CCTL0 &= ~(CCIE);
}

/*  Initialize all unused interrupt vectors */
#pragma vector=RTC_VECTOR,PORT2_VECTOR,                                        \
  USCI_B1_VECTOR,USCI_A1_VECTOR,PORT1_VECTOR,TIMER1_A1_VECTOR,DMA_VECTOR,      \
  TIMER0_A1_VECTOR,TIMER1_A0_VECTOR,TIMER2_A0_VECTOR,TIMER2_A1_VECTOR,         \
  USCI_B0_VECTOR,USCI_A0_VECTOR,WDT_VECTOR,TIMER0_B1_VECTOR,TIMER0_B0_VECTOR,  \
  ADC12_VECTOR,COMP_B_VECTOR,UNMI_VECTOR,SYSNMI_VECTOR,USB_UBM_VECTOR
__interrupt void ISR_trap(void)
{
    /* The following will cause a software BOR */
 	PMMCTL0 = PMMPW | PMMSWBOR;
}


