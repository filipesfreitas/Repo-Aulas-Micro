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
 *  RO_PINOSC_TA0_TA1 implementation using 6 buttons/LEDS or a 1 button/LED.
 *
 *          Schematic Description:
 *
 *                         MSP430F2553
 *                      +---------------+
 *                      |               |
 *          LED0--------|P1.0       P2.6|--------LED5
 *          LED1--------|P1.4       P2.7|--------LED4
 *          LED2--------|P1.5       P1.6|--------LED3
 *                      |               |
 *          key0--------|P2.0       P2.5|--------key5
 *          key1--------|P2.1       P2.4|--------key4
 *    eProx/key2--------|P2.2       P2.3|--------key3
 *
 *  The TIMERA_1 interval represents the gate time.  The number of counts within
 *  the TA0R that have accumulated during the gate time represents the 
 *  capacitance of the element. The code is divided into two different
 *  applications; keypad and proximity sensor.  The structure./.h files support
 *  both.
 *  The gate time for the element defined in sensor proximity is about 11ms.
 *  The scan rate for the sensor proximity is approximately 20ms plus the 11ms 
 *  it takes to measure the sensor.
 *  1/(20ms + 11ms) ~ 32Hz
 *  The gate time for each element defined in sensor keypad is about 1ms. The 
 *  the time it takes to measure all six elements is 6ms.
 *  The scan rate for the sensor keypad is approximately 25ms plus the 6ms it 
 *  takes to measure all six elements wihtin the sensor.
 *  1/(25ms + 6ms) ~ 32Hz
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

//#define PROXIMITY_APP
#define KEYPAD_APP

#ifdef KEYPAD_APP
struct Element * activeKey;
const struct Element* keyAddress[6] =
{
	&key0,
	&key1,
	&key2,
	&key3,
	&key4,
	&key5
};
const uint8_t * portOut[6] =
{
	(uint8_t *)&P1OUT,
	(uint8_t *)&P1OUT,
	(uint8_t *)&P1OUT,
	(uint8_t *)&P1OUT,
	(uint8_t *)&P2OUT,
	(uint8_t *)&P2OUT
};
const uint8_t bitOut[6] =
{
	BIT0,
	BIT4,
	BIT5,
	BIT6,
	BIT7,
	BIT6
};
#endif
void sleep(uint16_t);
/*
 *  ======== main() ========
 */
uint16_t main(void) {
	
	volatile uint8_t i;

    WDTCTL = WDTPW + WDTHOLD;  /* Stop WDT */
    BCSCTL1 = CALBC1_1MHZ;     /* Set DCO to 1, 8, 12 or 16MHz */
    DCOCTL = CALDCO_1MHZ;
    BCSCTL3 |= LFXT1S_2;       /* LFXT1 = VLO */

    P1DIR |= 0xFF;
    P2DIR |= 0xFF;
    P1OUT = 0;
    P2OUT = 0;
    P2SEL = 0;
    P1SEL = 0;

#ifdef PROXIMITY_APP
    TI_CAPT_Init_Baseline(&proximity);
    TI_CAPT_Update_Baseline(&proximity,5);
#endif

#ifdef KEYPAD_APP
    TI_CAPT_Init_Baseline(&keypad);
    TI_CAPT_Update_Baseline(&keypad,5);
#endif

    while(1)
    {
#ifdef PROXIMITY_APP
    	if(TI_CAPT_Button(&proximity))
    	{
    		P1OUT |= BIT0;
    	}
        /* Delay 20ms, 20ms*12Khz = 240 */
        sleep(240);
        P1OUT &= ~BIT0;
#endif
#ifdef KEYPAD_APP
        activeKey = (struct Element *)TI_CAPT_Buttons(&keypad);
        for(i=0;i<6;i++)
        {
        	if(activeKey == keyAddress[i])
        	{
        		*(uint8_t *)portOut[i] |= bitOut[i];
        	}
        }
        /* Delay 25ms, 25ms*12Khz = 300 */
        sleep(300);
        P1OUT &= ~(BIT0+BIT4+BIT5+BIT6);
        P2OUT &= ~(BIT6+BIT7);
#endif
    } /* End While */
}  /* End Main */

/*
 *  ======== sleep(uint16_t) ========
 *  Place device into LPM3.  Source of TimerA1 is ACLK which is sourced from the 
 *  VLO (~12Khz).  The ISR is found in the library, in CTS_HAL.c
 */
void sleep(uint16_t time)
{
    TA1CCR0 = time;
    TA1CTL = MC_1+TACLR+TASSEL_1; 
    TA1CCTL0 &= ~(CAP+CCIFG); 
    TA1CCTL0 |= CCIE; 
    __bis_SR_register(LPM3_bits+GIE);
    __no_operation();
    __disable_interrupt();
    TA1CTL &= ~(MC_1);
    TA1CCTL0 &= ~(CCIE);
}

#pragma vector= PORT2_VECTOR,PORT1_VECTOR,WDT_VECTOR,ADC10_VECTOR,NMI_VECTOR,  \
                USCIAB0TX_VECTOR,USCIAB0RX_VECTOR, TIMER0_A1_VECTOR,           \
                COMPARATORA_VECTOR, TIMER1_A1_VECTOR, TIMER0_A0_VECTOR
__interrupt void ISR_trap(void)
{
  /* the following will cause an access violation and result in a PUC reset */
  WDTCTL = 0;
}


