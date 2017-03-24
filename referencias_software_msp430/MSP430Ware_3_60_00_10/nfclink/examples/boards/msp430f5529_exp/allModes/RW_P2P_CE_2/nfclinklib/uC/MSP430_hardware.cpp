/*
 * MSP430F5x2x_hardware.cpp
 *
 *  Created on: 18.09.2012
 *      Author: A
 */


#include "MSP430_hardware.h"
#include "hardware.h"
#include "msp430.h"

extern "C" {
#include "inc/hw_memmap.h"
#include "wdt_a.h"
#include "timer_a.h"
#include "sfr.h"
#include "ucs.h"
#include "pmm.h"
}

byte HWTimer::lastmsb=0;
HWTimer::tstruct HWTimer::timervalue;

static void Init_FLL(unsigned int fsystem, unsigned int ratio) {
	unsigned int d, dco_div_bits;
	unsigned int mode = 0;

	// Save actual state of FLL loop control, then disable it. This is needed to
	// prevent the FLL from acting as we are making fundamental modifications to
	// the clock setup.
	unsigned int srRegisterState = __get_SR_register() & SCG0;
	__bic_SR_register(SCG0); d
	= ratio;
	dco_div_bits = FLLD__2;        // Have at least a divider of 2

	if (fsystem > 16000) {
		d >>= 1;
		mode = 1;
	} else {
		fsystem <<= 1;               // fsystem = fsystem * 2
	}

	while (d > 512) {
		dco_div_bits = dco_div_bits + FLLD0;  // Set next higher div level
		d >>= 1;
	}

	UCSCTL0 = 0x0000;              // Set DCO to lowest Tap

	UCSCTL2 &= ~(0x03FF);          // Reset FN bits
	UCSCTL2 = dco_div_bits | (d - 1);

	if (fsystem <= 630)            //           fsystem < 0.63MHz
		UCSCTL1 = DCORSEL_0;
	else if (fsystem < 1250)      // 0.63MHz < fsystem < 1.25MHz
		UCSCTL1 = DCORSEL_1;
	else if (fsystem < 2500)      // 1.25MHz < fsystem <  2.5MHz
		UCSCTL1 = DCORSEL_2;
	else if (fsystem < 5000)      // 2.5MHz  < fsystem <    5MHz
		UCSCTL1 = DCORSEL_3;
	else if (fsystem < 10000)     // 5MHz    < fsystem <   10MHz
		UCSCTL1 = DCORSEL_4;
	else if (fsystem < 20000)     // 10MHz   < fsystem <   20MHz
		UCSCTL1 = DCORSEL_5;
	else if (fsystem < 40000)     // 20MHz   < fsystem <   40MHz
		UCSCTL1 = DCORSEL_6;
	else
		UCSCTL1 = DCORSEL_7;

	while (SFRIFG1 & OFIFG) {                          // Check OFIFG fault flag
		UCSCTL7 &= ~(DCOFFG + XT1LFOFFG + XT1HFOFFG + XT2OFFG); // Clear OSC flaut Flags
		SFRIFG1 &= ~OFIFG;                             // Clear OFIFG fault flag
	}

	if (mode == 1) {                              		  // fsystem > 16000
		SELECT_MCLK_SMCLK(SELM__DCOCLK + SELS__DCOCLK);
		// Select DCOCLK
	} else {
		SELECT_MCLK_SMCLK(SELM__DCOCLKDIV + SELS__DCOCLKDIV);
		// Select DCODIVCLK
	}

	__bis_SR_register(srRegisterState);	                // Restore previous SCG0
}


static void Init_FLL_Settle(unsigned int fsystem, unsigned int ratio) {
	volatile unsigned int x = ratio * 32;

	Init_FLL(fsystem, ratio);

	while (x--) {
		__delay_cycles(30);
	}
}

/*******************************************************************************
 * \brief   Increase Vcore by one level
 *
 * \param level     Level to which Vcore needs to be increased
 * \return status   Success/failure
 ******************************************************************************/
static unsigned int SetVCoreUp(unsigned int level) {
	unsigned int PMMRIE_backup, SVSMHCTL_backup, SVSMLCTL_backup;

	// The code flow for increasing the Vcore has been altered to work around
	// the erratum FLASH37.
	// Please refer to the Errata sheet to know if a specific device is affected
	// DO NOT ALTER THIS FUNCTION

	// Open PMM registers for write access
	PMMCTL0_H = 0xA5;

	// Disable dedicated Interrupts
	// Backup all registers
	PMMRIE_backup = PMMRIE;
	PMMRIE &= ~(SVMHVLRPE | SVSHPE | SVMLVLRPE | SVSLPE | SVMHVLRIE | SVMHIE
			| SVSMHDLYIE | SVMLVLRIE | SVMLIE | SVSMLDLYIE);
	SVSMHCTL_backup = SVSMHCTL;
	SVSMLCTL_backup = SVSMLCTL;

	// Clear flags
	PMMIFG = 0;

	// Set SVM highside to new level and check if a VCore increase is possible
	SVSMHCTL = SVMHE | SVSHE | (SVSMHRRL0 * level);

	// Wait until SVM highside is settled
	while ((PMMIFG & SVSMHDLYIFG) == 0)
		;

	// Clear flag
	PMMIFG &= ~SVSMHDLYIFG;

	// Check if a VCore increase is possible
	if ((PMMIFG & SVMHIFG) == SVMHIFG) { // -> Vcc is too low for a Vcore increase
		// recover the previous settings
		PMMIFG &= ~SVSMHDLYIFG;
		SVSMHCTL = SVSMHCTL_backup;

		// Wait until SVM highside is settled
		while ((PMMIFG & SVSMHDLYIFG) == 0)
			;

		// Clear all Flags
		PMMIFG &= ~(SVMHVLRIFG | SVMHIFG | SVSMHDLYIFG | SVMLVLRIFG | SVMLIFG
				| SVSMLDLYIFG);

		PMMRIE = PMMRIE_backup;         // Restore PMM interrupt enable register
		PMMCTL0_H = 0x00;                 // Lock PMM registers for write access
		return PMM_STATUS_ERROR;                // return: voltage not set
	}

	// Set also SVS highside to new level
	// Vcc is high enough for a Vcore increase
	SVSMHCTL |= (SVSHRVL0 * level);

	// Wait until SVM highside is settled
	while ((PMMIFG & SVSMHDLYIFG) == 0)
		;

	// Clear flag
	PMMIFG &= ~SVSMHDLYIFG;

	// Set VCore to new level
	PMMCTL0_L = PMMCOREV0 * level;

	// Set SVM, SVS low side to new level
	SVSMLCTL = SVMLE | (SVSMLRRL0 * level) | SVSLE | (SVSLRVL0 * level);

	// Wait until SVM, SVS low side is settled
	while ((PMMIFG & SVSMLDLYIFG) == 0)
		;

	// Clear flag
	PMMIFG &= ~SVSMLDLYIFG;
	// SVS, SVM core and high side are now set to protect for the new core level

	// Restore Low side settings
	// Clear all other bits _except_ level settings
	SVSMLCTL &= (SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 + SVSMLRRL1 + SVSMLRRL2);

	// Clear level settings in the backup register,keep all other bits
	SVSMLCTL_backup &=
			~(SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 + SVSMLRRL1 + SVSMLRRL2);

	// Restore low-side SVS monitor settings
	SVSMLCTL |= SVSMLCTL_backup;

	// Restore High side settings
	// Clear all other bits except level settings
	SVSMHCTL &= (SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 + SVSMHRRL1 + SVSMHRRL2);

	// Clear level settings in the backup register,keep all other bits
	SVSMHCTL_backup &=
			~(SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 + SVSMHRRL1 + SVSMHRRL2);

	// Restore backup
	SVSMHCTL |= SVSMHCTL_backup;

	// Wait until high side, low side settled
	while (((PMMIFG & SVSMLDLYIFG) == 0) && ((PMMIFG & SVSMHDLYIFG) == 0))
		;

	// Clear all Flags
	PMMIFG &= ~(SVMHVLRIFG | SVMHIFG | SVSMHDLYIFG | SVMLVLRIFG | SVMLIFG
			| SVSMLDLYIFG);

	PMMRIE = PMMRIE_backup;             // Restore PMM interrupt enable register
	PMMCTL0_H = 0x00;                     // Lock PMM registers for write access

	return PMM_STATUS_OK;
}

/*******************************************************************************
 * \brief  Decrease Vcore by one level
 *
 * \param  level    Level to which Vcore needs to be decreased
 * \return status   Success/failure
 ******************************************************************************/
static unsigned int SetVCoreDown(unsigned int level) {
	unsigned int PMMRIE_backup, SVSMHCTL_backup, SVSMLCTL_backup;

	// The code flow for decreasing the Vcore has been altered to work around
	// the erratum FLASH37.
	// Please refer to the Errata sheet to know if a specific device is affected
	// DO NOT ALTER THIS FUNCTION

	// Open PMM registers for write access
	PMMCTL0_H = 0xA5;

	// Disable dedicated Interrupts
	// Backup all registers
	PMMRIE_backup = PMMRIE;
	PMMRIE &= ~(SVMHVLRPE | SVSHPE | SVMLVLRPE | SVSLPE | SVMHVLRIE | SVMHIE
			| SVSMHDLYIE | SVMLVLRIE | SVMLIE | SVSMLDLYIE);
	SVSMHCTL_backup = SVSMHCTL;
	SVSMLCTL_backup = SVSMLCTL;

	// Clear flags
	PMMIFG &= ~(SVMHIFG | SVSMHDLYIFG | SVMLIFG | SVSMLDLYIFG);

	// Set SVM, SVS high & low side to new settings in normal mode
	SVSMHCTL = SVMHE | (SVSMHRRL0 * level) | SVSHE | (SVSHRVL0 * level);
	SVSMLCTL = SVMLE | (SVSMLRRL0 * level) | SVSLE | (SVSLRVL0 * level);

	// Wait until SVM high side and SVM low side is settled
	while ((PMMIFG & SVSMHDLYIFG) == 0 || (PMMIFG & SVSMLDLYIFG) == 0)
		;

	// Clear flags
	PMMIFG &= ~(SVSMHDLYIFG + SVSMLDLYIFG);
	// SVS, SVM core and high side are now set to protect for the new core level

	// Set VCore to new level
	PMMCTL0_L = PMMCOREV0 * level;

	// Restore Low side settings
	// Clear all other bits _except_ level settings
	SVSMLCTL &= (SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 + SVSMLRRL1 + SVSMLRRL2);

	// Clear level settings in the backup register,keep all other bits
	SVSMLCTL_backup &=
			~(SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 + SVSMLRRL1 + SVSMLRRL2);

	// Restore low-side SVS monitor settings
	SVSMLCTL |= SVSMLCTL_backup;

	// Restore High side settings
	// Clear all other bits except level settings
	SVSMHCTL &= (SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 + SVSMHRRL1 + SVSMHRRL2);

	// Clear level settings in the backup register, keep all other bits
	SVSMHCTL_backup &=
			~(SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 + SVSMHRRL1 + SVSMHRRL2);

	// Restore backup
	SVSMHCTL |= SVSMHCTL_backup;

	// Wait until high side, low side settled
	while (((PMMIFG & SVSMLDLYIFG) == 0) && ((PMMIFG & SVSMHDLYIFG) == 0))
		;

	// Clear all Flags
	PMMIFG &= ~(SVMHVLRIFG | SVMHIFG | SVSMHDLYIFG | SVMLVLRIFG | SVMLIFG
			| SVSMLDLYIFG);

	PMMRIE = PMMRIE_backup;             // Restore PMM interrupt enable register
	PMMCTL0_H = 0x00;                     // Lock PMM registers for write access
	return PMM_STATUS_OK;		                // Return: OK
}
static unsigned int SetVCore(unsigned int level) {
	unsigned int actlevel;
	unsigned int status = 0;

	level &= PMMCOREV_3;                       // Set Mask for Max. level
	actlevel = (PMMCTL0 & PMMCOREV_3);         // Get actual VCore
											   // step by step increase or decrease
	while (((level != actlevel) && (status == 0)) || (level < actlevel)) {
		if (level > actlevel) {
			status = SetVCoreUp(++actlevel);
		} else {
			status = SetVCoreDown(--actlevel);
		}
	}

	return status;
}
static void LFXT_Start(unsigned int xtdrive) {
	// If the drive setting is not already set to maximum
	// Set it to max for LFXT startup
	if ((UCSCTL6 & XT1DRIVE_3) != XT1DRIVE_3) {
		UCSCTL6_L |= XT1DRIVE1_L + XT1DRIVE0_L; // Highest drive setting for XT1startup
	}

	while (SFRIFG1 & OFIFG) {   // Check OFIFG fault flag
		UCSCTL7 &= ~(DCOFFG + XT1LFOFFG + XT1HFOFFG + XT2OFFG); // Clear OSC flaut Flags fault flags
		SFRIFG1 &= ~OFIFG;        // Clear OFIFG fault flag
	}

	UCSCTL6 = (UCSCTL6 & ~(XT1DRIVE_3)) | (xtdrive); // set requested Drive mode
}

void HWConfig::Init()
{
	WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);

	// Setup XT1 and XT2
	XT1_XT2_PORT_SEL |= XT1_ENABLE + XT2_ENABLE;

	// Set Vcore to accomodate for max. allowed system speed
	SetVCore(3);

	// Use 32.768kHz XTAL as reference
	LFXT_Start(XT1DRIVE_0);
	Init_FLL_Settle(25000, 762);
}

void HWConfig::MCU_Reset()
{
	//RESET CPU, Software BrownOutReset
	PMMCTL0 = PMMPW + PMMSWBOR;
}

void HWTimer::Init() {

	//Start timer in continuous mode sourced by ACLK
	TIMER_A_configureContinuousMode(__MSP430_BASEADDRESS_T0B7__,
			TIMER_A_CLOCKSOURCE_ACLK, TIMER_A_CLOCKSOURCE_DIVIDER_1,
			TIMER_A_TAIE_INTERRUPT_DISABLE, TIMER_A_DO_CLEAR);

	TIMER_A_startCounter(__MSP430_BASEADDRESS_T0B7__, TIMER_A_CONTINUOUS_MODE);

}

dword HWTimer::ticks32() // 32 bit timer
{
	timervalue.f[0] = TB0R; //TIM2->CNT; //lower word of timer

	unsigned char x = timervalue.f[0] >> 15; //get most significatnt byte
	if (x != lastmsb) //has most significant bit changed ?
			{
		lastmsb = x;
		if (x == 0)
			timervalue.f[1]++; //timer overflow ? -> increment high word
	}
	return timervalue.d;
}

void GPIO::Init(){
	// Disable All the LEDs
	setExtField(false);
	setAnyMode(false);
	setRWMode(false);
	setP2PTargetMode(false);
	setCEMode(false);
	setSerialTX(false);
	setSerialRX(false);

	// Set LEDs as output
	LED_ANY_MODE_PDIR |= LED_ANY_MODE_BIT;
	LED_EXT_FIELD_PDIR |= LED_EXT_FIELD_BIT;
	LED_RW_MODE_PDIR |= LED_RW_MODE_BIT;
	LED_P2P_MODE_PDIR |= LED_P2P_MODE_BIT;
	LED_CE_MODE_PDIR |= LED_CE_MODE_BIT;

	PIN_SERIAL_TX_PDIR |= PIN_SERIAL_TX_BIT;
	PIN_SERIAL_RX_PDIR |= PIN_SERIAL_RX_BIT;
	PIN_EXT_FIELD_PDIR |= PIN_EXT_FIELD_BIT;

}
void GPIO::setExtField(bool ext_field)
{
	if(ext_field)
	{
		LED_EXT_FIELD_POUT |= LED_EXT_FIELD_BIT;
		PIN_EXT_FIELD_POUT |= PIN_EXT_FIELD_BIT;
	}
	else
	{
		LED_EXT_FIELD_POUT &= ~LED_EXT_FIELD_BIT;
		PIN_EXT_FIELD_POUT &= ~PIN_EXT_FIELD_BIT;
	}
}
void GPIO::setAnyMode(bool any_mode)
{
	if(any_mode)
		LED_ANY_MODE_POUT |= LED_ANY_MODE_BIT;
	else
		LED_ANY_MODE_POUT &= ~LED_ANY_MODE_BIT;
}
void GPIO::setRWMode(bool rw_mode)
{
	if(rw_mode)
		LED_RW_MODE_POUT |= LED_RW_MODE_BIT;
	else
		LED_RW_MODE_POUT &= ~LED_RW_MODE_BIT;
}
void GPIO::setP2PTargetMode(bool p2p_mode)
{
	if(p2p_mode)
		LED_P2P_MODE_POUT |= LED_P2P_MODE_BIT;
	else
		LED_P2P_MODE_POUT &= ~LED_P2P_MODE_BIT;
}
void GPIO::setCEMode(bool ce_mode)
{
	if(ce_mode)
		LED_CE_MODE_POUT |= LED_CE_MODE_BIT;
	else
		LED_CE_MODE_POUT &= ~LED_CE_MODE_BIT;
}
void GPIO::setSerialTX(bool serial_tx)
{
	if(serial_tx)
		PIN_SERIAL_TX_POUT |= PIN_SERIAL_TX_BIT;
	else
		PIN_SERIAL_TX_POUT &= ~PIN_SERIAL_TX_BIT;
}
void GPIO::setSerialRX(bool serial_rx)
{
	if(serial_rx)
		PIN_SERIAL_RX_POUT |= PIN_SERIAL_RX_BIT;
	else
		PIN_SERIAL_RX_POUT &= ~PIN_SERIAL_RX_BIT;
}



#pragma vector= ADC12_VECTOR
__interrupt void ADC12_ISR (void)
{
	while(1);
}

#pragma vector= COMP_B_VECTOR
__interrupt void COMP_B_ISR (void)
{
	while(1);
}

#pragma vector= DMA_VECTOR
__interrupt void DMA_ISR (void)
{
	while(1);
}

#pragma vector= PORT1_VECTOR
__interrupt void PORT1_ISR (void)
{
	while(1);
}

//#pragma vector= PORT2_VECTOR
//__interrupt void PORT2_ISR (void)
//{
//	while(1);
//}

#pragma vector= RTC_VECTOR
__interrupt void RTC_ISR (void)
{
	while(1);
}

#pragma vector= SYSNMI_VECTOR
__interrupt void SYSNMI_ISR (void)
{
	while(1);
}

#pragma vector= TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR (void)
{
	while(1);
}

#pragma vector= TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR (void)
{
	while(1);
}

#pragma vector= TIMER0_B0_VECTOR
__interrupt void TIMER0_B0_ISR (void)
{
	while(1);
}

#pragma vector= TIMER0_B1_VECTOR
__interrupt void TIMER0_B1_ISR (void)
{
	while(1);
}

#pragma vector= TIMER1_A0_VECTOR
__interrupt void TIMER1_A0_ISR (void)
{
	while(1);
}

#pragma vector= TIMER1_A1_VECTOR
__interrupt void TIMER1_A1_ISR (void)
{
	while(1);
}

#pragma vector= TIMER2_A0_VECTOR
__interrupt void TIMER2_A0_ISR (void)
{
	while(1);
}

#pragma vector= TIMER2_A1_VECTOR
__interrupt void TIMER2_A1_ISR (void)
{
	while(1);
}

#pragma vector= UNMI_VECTOR
__interrupt void UNMI_ISR (void)
{
	while(1);
}

//#pragma vector= USB_UBM_VECTOR
//__interrupt void USB_UBM_ISR (void)
//{
//	while(1);
//}

#pragma vector= USCI_A0_VECTOR
__interrupt void USCI_A0_ISR (void)
{
	while(1);
}

//#pragma vector= USCI_A1_VECTOR
//__interrupt void USCI_A1_ISR (void)
//{
//	while(1);
//}

#pragma vector= USCI_B0_VECTOR
__interrupt void USCI_B0_ISR (void)
{
	while(1);
}

#pragma vector= USCI_B1_VECTOR
__interrupt void USCI_B1_ISR (void)
{
	while(1);
}

#pragma vector= WDT_VECTOR
__interrupt void WTD_ISR (void)
{
	while(1);
}

