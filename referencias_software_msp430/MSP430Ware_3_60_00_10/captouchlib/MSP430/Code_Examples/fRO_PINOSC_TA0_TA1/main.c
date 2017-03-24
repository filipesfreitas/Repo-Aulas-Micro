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
 *  fRO_PINOSC_TA0_TA1 implementation using a single proximity element and LED.
 *
 *          Schematic Description:
 *
 *                         MSP430F2553
 *                      +---------------+
 *                      |               |
 *          LED0--------|P1.0           |
 *                      |               |
 *          eProx-------|P2.2           |
 *
 *  The TIMERA_0 interval represents the gate time.  The number of counts within
 *  the TA1R that have accumulated during the gate time represents the 
 *  capacitance of the element.
 *  The gate time for the element defined in sensor proximity is about 10ms.
 *  The scan rate for the sensor proximity is approximately 21ms plus the 10ms 
 *  it takes to measure the sensor.
 *  1/(21ms + 10ms) ~ 32Hz
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

// uint16_t deltaCnt;
void sleep(uint16_t);
/*
 *  ======== main() ========
 */
uint16_t main(void) {
	
	volatile uint8_t i;

    WDTCTL = WDTPW + WDTHOLD;  /* Stop WDT */
    BCSCTL1 = CALBC1_12MHZ;    /* Set DCO to 1, 8, 12 or 16MHz */
    DCOCTL = CALDCO_12MHZ;
    BCSCTL3 |= LFXT1S_2;       /* LFXT1 = VLO */

    P1DIR |= 0xFF;
    P2DIR |= 0xFF;
    P1OUT = 0;
    P2OUT = 0;
    P2SEL = 0;
    P1SEL = 0;

    TI_CAPT_Update_Tracking_Rate(TRADOI_FAST+TRIDOI_SLOW); /* Default Setting */
    //TI_CAPT_Update_Tracking_Rate(TRADOI_MED+TRIDOI_SLOW);
    //TI_CAPT_Update_Tracking_Rate(TRADOI_SLOW+TRIDOI_SLOW);
    //TI_CAPT_Update_Tracking_Rate(TRADOI_VSLOW+TRIDOI_SLOW);

    TI_CAPT_Init_Baseline(&proximity);
    TI_CAPT_Update_Baseline(&proximity,5);

    while(1)
    {
        //TI_CAPT_Custom(&proximity,&deltaCnt);
    	if(TI_CAPT_Button(&proximity))
    	{
    		P1OUT |= BIT0;
    	}
        /* Delay 21ms, 21ms*12Khz = 252 */
        sleep(252);
        P1OUT &= ~BIT0;
    }  /* End While */
} /* End Main */
/*
 *  ======== sleep(uint16_t) ========
 *  Place device into LPM3.  Source of TimerA0 is ACLK which is sourced from the 
 *  VLO (~12Khz).  The ISR is found in the library, in CTS_HAL.c
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
#pragma vector= PORT2_VECTOR,PORT1_VECTOR,WDT_VECTOR,ADC10_VECTOR,NMI_VECTOR,  \
                USCIAB0TX_VECTOR,USCIAB0RX_VECTOR, TIMER0_A1_VECTOR,           \
                COMPARATORA_VECTOR, TIMER1_A1_VECTOR, TIMER1_A0_VECTOR
__interrupt void ISR_trap(void)
{
  /* the following will cause an access violation and result in a PUC reset */
  WDTCTL = 0;
}


