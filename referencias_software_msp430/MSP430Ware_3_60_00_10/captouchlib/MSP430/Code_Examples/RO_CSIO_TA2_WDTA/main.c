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
 *  RO_CSIO_TA2_WDTA implementation example with 6 buttons and 6 leds.
 *
 *  Schematic Description:
 *
 *                         MSP430FR5969
 *                      +---------------+
 *                      |               |
 *          LED0--------|P4.2       P1.2|--------LED3
 *          LED1--------|P2.4       P3.0|--------LED4
 *          LED2--------|P2.2       P1.7|--------LED5
 *                      |               |
 *            C0--------|P3.4       P1.5|--------C3
 *            C1--------|P3.5       P1.4|--------C4
 *            C2--------|P3.6       P1.3|--------C5
 *
 *
 *  The WDTA interval represents the gate time.  The number of
 *  counts within the TA2R that have accumulated during the gate time
 *  represents the capacitance of the element.
 *  The gate time for each element defined in sensor keyPad is about 64us. The 
 *  the time it takes to measure all six elements is approximately 384us.
 *  The scan rate for the sensor keyPad is approximately 31ms plus the 384us it 
 *  takes to measure all six elements wihtin the sensor.
 *  1/(31ms + 384us) ~ 32Hz
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

struct Element * activeKey;
//const struct Element* keyAddress[6] =
//{
//	&key0,  // C0
//	&key1,
//	&key2,
//	&key3,
//	&key4,
//	&key5
//};
const uint8_t * ledPort[6] =
{
	(uint8_t *)&P4OUT,
	(uint8_t *)&P2OUT,
	(uint8_t *)&P2OUT,
	(uint8_t *)&P1OUT,
	(uint8_t *)&P3OUT,
	(uint8_t *)&P1OUT
};
const uint8_t ledBit[6] =
{
	BIT2,
	BIT4,
	BIT2,
	BIT2,
	BIT0,
	BIT7
};

/*
 *  ======== main() ========
 */
uint16_t main(void)
{ 
	volatile uint8_t i;
    WDTCTL = WDTPW + WDTHOLD;             /* Stop watchdog timer */
    /* Initialize IO */
    P1DIR = 0xFF;
    P2DIR = 0xFF;
    P3DIR = 0xFF;
    P4DIR = 0xFF;
    PJDIR = 0xFF;
    P1OUT = 0;
    P2OUT = 0;
    P3OUT = 0;
    P4OUT = 0;
    PJOUT = 0;
    /* XT1 Setup taken from msp430fr59xx_CS_03.c code example. */
    PJSEL0 |= BIT4 + BIT5;

    CSCTL0 = CSKEY;
    CSCTL1 = DCOFSEL_0;                    /* Set DCO= 1MHz */
    CSCTL2 = SELA__LFXTCLK + SELS__DCOCLK + SELM__DCOCLK;
    CSCTL3 = DIVA_1 + DIVS_0 + DIVM_0;     /* ACLK/2, SMCLK/1, MCLK/1 */
    CSCTL4 |= LFXTDRIVE_0;
    CSCTL4 &= ~LFXTOFF;

    do
    {
        CSCTL5 &= ~LFXTOFFG;
                                                // Clear XT1 fault flag
        SFRIFG1 &= ~OFIFG;
    }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag

    // establish baseline
    TI_CAPT_Init_Baseline(&keyPad);
    TI_CAPT_Update_Baseline(&keyPad,5);

    while (1)
    {
        activeKey = (struct Element *)TI_CAPT_Buttons(&keyPad);
        for(i=0;i<6;i++)
        {
            //if(activeKey == keyAddress[i])
            if(activeKey == keyPad.arrayPtr[i])
            {
                *(uint8_t *)ledPort[i] |= ledBit[i];
            }
        }
        /* 31ms delay, ISR is found in the library, in CTS_HAL.c */
        SFRIE1 |= WDTIE;           /* Enable the WDTA interrupt */
        WDTCTL = WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL_1+WDTIS_6; /* ACLK/512 */
        __bis_SR_register(LPM3_bits+GIE);
        __no_operation();
        WDTCTL = WDTPW + WDTHOLD;  /* Halt watchdog timer */
        SFRIE1 &= ~WDTIE;          /* Disable the WDTA interrupt */
        __disable_interrupt();
        /* Turn off all LEDs before next measurement */
        for(i=0;i<6;i++)
        {
            *(uint8_t *)ledPort[i] &= ~ledBit[i];
        }
    }
} // End Main

#pragma vector=RTC_VECTOR,PORT2_VECTOR,ADC12_VECTOR,USCI_A1_VECTOR,           \
  PORT1_VECTOR,TIMER1_A1_VECTOR,DMA_VECTOR,TIMER0_A1_VECTOR,TIMER0_A0_VECTOR, \
  USCI_B0_VECTOR,USCI_A0_VECTOR,TIMER0_B1_VECTOR,TIMER0_B0_VECTOR,            \
  UNMI_VECTOR,SYSNMI_VECTOR,AES256_VECTOR,PORT3_VECTOR,TIMER3_A1_VECTOR,      \
  PORT4_VECTOR, TIMER1_A0_VECTOR, TIMER2_A0_VECTOR, TIMER3_A0_VECTOR,         \
  TIMER2_A1_VECTOR /* ,COMP_E_VECTOR */
__interrupt void ISR_trap(void)
{
    /* The following will cause a software BOR */
 	PMMCTL0 = PMMPW | PMMSWBOR;
}


