/*
 * MSP430F5x2x_hardware.h
 *
 *  Created on: 18.09.2012
 *      Author: A
 */

#ifndef MSP430_HARDWARE_H_
#define MSP430_HARDWARE_H_
#include "hardware.h"
#include "msp430.h"

#define UCS_MCLK_DESIRED_FREQUENCY_IN_KHZ   12000
#define UCS_MCLK_FLLREF_RATIO   366
/*use own definition*/
//#define XT1HFOFFG   0

#define PMM_STATUS_OK     0
#define PMM_STATUS_ERROR  1
#define st(x)      do { x } while (__LINE__ == -1)

#define XT1_XT2_PORT_DIR            P5DIR
#define XT1_XT2_PORT_OUT            P5OUT
#define XT1_XT2_PORT_SEL            P5SEL
#define XT1_ENABLE                  (BIT4 + BIT5)
#define XT2_ENABLE                  (BIT2 + BIT3)

/*******************************************************************************
 * Macros
 ******************************************************************************/

/* Select source for FLLREF  e.g. SELECT_FLLREF(SELREF__XT1CLK) */
#define SELECT_FLLREF(source) st(UCSCTL3 = (UCSCTL3 & ~(SELREF_7)) | (source);)
/* Select source for ACLK    e.g. SELECT_ACLK(SELA__XT1CLK) */
#define SELECT_ACLK(source)   st(UCSCTL4 = (UCSCTL4 & ~(SELA_7))   | (source);)
/* Select source for MCLK    e.g. SELECT_MCLK(SELM__XT2CLK) */
#define SELECT_MCLK(source)   st(UCSCTL4 = (UCSCTL4 & ~(SELM_7))   | (source);)
/* Select source for SMCLK   e.g. SELECT_SMCLK(SELS__XT2CLK) */
#define SELECT_SMCLK(source)  st(UCSCTL4 = (UCSCTL4 & ~(SELS_7))   | (source);)
/* Select source for MCLK and SMCLK e.g. SELECT_MCLK_SMCLK(SELM__DCOCLK + SELS__DCOCLK) */
#define SELECT_MCLK_SMCLK(sources) st(UCSCTL4 = (UCSCTL4 & ~(SELM_7 + SELS_7)) | (sources);)

/* set ACLK/x */
#define ACLK_DIV(x)         st(UCSCTL5 = (UCSCTL5 & ~(DIVA_7)) | (DIVA__##x);)
/* set MCLK/x */
#define MCLK_DIV(x)         st(UCSCTL5 = (UCSCTL5 & ~(DIVM_7)) | (DIVM__##x);)
/* set SMCLK/x */
#define SMCLK_DIV(x)        st(UCSCTL5 = (UCSCTL5 & ~(DIVS_7)) | (DIVS__##x);)
/* Select divider for FLLREF  e.g. SELECT_FLLREFDIV(2) */
#define SELECT_FLLREFDIV(x) st(UCSCTL3 = (UCSCTL3 & ~(FLLREFDIV_7))|(FLLREFDIV__##x);)

class HWConfig {

public:
	static void Init();
	static void MCU_Reset();
};

class HWTimer {
private:
	static unsigned char lastmsb; //keeps track of timer overflow
	typedef union {
		dword d;word f[2];
		//byte b[4]; // low byte first
	} tstruct;
	static tstruct timervalue;
public:
	static const long TICKS_PER_MSEC = (33L); //Timer cycles per millisecond
	static void Init();
	static dword ticks32();
};


//#define LED_ANY_MODE_PDIR		P1DIR
//#define LED_ANY_MODE_BIT		BIT0
//#define LED_ANY_MODE_POUT		P1OUT

#define LED_EXT_FIELD_PDIR		P4DIR
#define LED_EXT_FIELD_BIT		BIT7
#define LED_EXT_FIELD_POUT		P4OUT

#define LED_RW_MODE_PDIR		P8DIR
#define LED_RW_MODE_BIT			BIT1
#define LED_RW_MODE_POUT		P8OUT

#define LED_P2P_MODE_PDIR		P2DIR
#define LED_P2P_MODE_BIT		BIT3
#define LED_P2P_MODE_POUT		P2OUT

#define LED_CE_MODE_PDIR		P2DIR
#define LED_CE_MODE_BIT			BIT6
#define LED_CE_MODE_POUT		P2OUT

#define LED_TEST_BLINK_PDIR		P1DIR
#define LED_TEST_BLINK_BIT		BIT0
#define LED_TEST_BLINK_POUT		P1OUT

#define PIN_SERIAL_TX_PDIR		P2DIR
#define PIN_SERIAL_TX_BIT		BIT1
#define PIN_SERIAL_TX_POUT		P2OUT

#define PIN_SERIAL_RX_PDIR		P2DIR
#define PIN_SERIAL_RX_BIT		BIT7
#define PIN_SERIAL_RX_POUT		P2OUT

#define PIN_EXT_FIELD_PDIR		P4DIR
#define PIN_EXT_FIELD_BIT		BIT7
#define PIN_EXT_FIELD_POUT		P4OUT

class GPIO{
public:
	static void Init();
	static void setExtField(bool ext_field);
	static void setAnyMode(bool any_mode);
	static void setRWMode(bool rw_mode);
	static void setP2PTargetMode(bool p2p_mode);
	static void setCEMode(bool ce_mode);

	static void setSerialTX(bool serial_tx);
	static void setSerialRX(bool serial_rx);
};


#endif
