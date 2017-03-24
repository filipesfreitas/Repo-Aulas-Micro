/** @file   SPI.c
 *  @brief  Polling based SPI driver
 *  @author LR
 *  @date   Feb 2011
 *  @note   History:
 *          Date        Author      Comment
 *          02/2011     LR          File created and added to GIT
 *  Built with IAR Embedded Workbench Version: 5.20
 *
 */
/* --COPYRIGHT--,BSD
 * Copyright (c) 2011, Texas Instruments Incorporated
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

//
// Include files
//
#include "SPI.h"  

extern "C" {
#include <msp430.h>

}
//
// Public functions
//
/******************************************************************************
 * @brief   Initializes the SPI module
 * 
 * @return  none
 *****************************************************************************/
void RFSPI::init() {

	SLAVESELECT_OUTPUT(); // P3.0 - Slave Select
	SLAVESELECT_HIGH(); // Slave Select - inactive ( high)

	UCB0CTL1 |= UCSWRST; // Disable USCI first

	UCB0CTL0 |= UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit SPI master, Clock Pol/Phase = 0

	UCB0CTL1 |= UCSSEL_2; // SMCLK

	UCB0BR0 = SPIBAUD0;
	UCB0BR1 = SPIBAUD1;
	// P3.1,3.2,3.3 UCB0SIMO,UCB0SOMI,UCBOCLK option select
	SPI_PSEL |= (SPI_MOSI_PIN + SPI_MISO_PIN + SPI_CLK_PIN);

	UCB0CTL1 &= ~UCSWRST; // **Initialize USCI state machine**

}

/******************************************************************************
 * @brief   Waits for the bus to be idle
 * 
 * @return  none
 *****************************************************************************/
void RFSPI::waitBus() {
	while (UCSPISTAT & UCBUSY)
		// Ensure USCI is not busy
		;
}

/******************************************************************************
 * @brief   Transfers data to the SPI slave (TX and RX in same transfer)
 *  
 * @param data_out Data being sent
 * 
 * @return  uint8_t with received data
 * @note This function polls for bus activity. CS is not handled here
 *****************************************************************************/
byte RFSPI::transfer(uint8_t data_out) {
	while (!(UCSPIIFG & UCTXIFG))
		// USCI_B0 TX buffer ready?
		;
	UCSPITXBUF = data_out; // Previous data to TX, RX

	waitBus();
	byte reg = UCSPIRXBUF;

	return reg;
}

void RFSPI::send(uint8_t mode_addr, uint8_t *pbuf, uint8_t length, bool read_flag) {
	byte *txbuf, *rxbuf;

	rxbuf = txbuf = pbuf; // Initialize pointer

	SLAVESELECT_LOW(); //Start SPI Mode

	(void) transfer(mode_addr);
	waitBus();

	while (length > 0) {
		if(read_flag)
			*rxbuf++  = transfer(0x00);
		else
			(void)  transfer(*txbuf++);
		length--;
	}
	waitBus();
	SLAVESELECT_HIGH(); //Stop SPI Mode
}

void RFSPI::write(uint8_t a,uint8_t* b) {
	send((a & 0x1F), b, 1,false);
}

void RFSPI::read(uint8_t a, uint8_t* b) {
	send(((a & 0x1F) | BIT6), b, 1,true);
}
void RFSPI::rawWrite(uint8_t *pbuf, uint8_t length) {

		SLAVESELECT_LOW(); //Start SPI Mode

		while (length > 0) {
			transfer(*pbuf++);
			length--;
		}
		waitBus();
		SLAVESELECT_HIGH(); //Stop SPI Mode
}
void RFSPI::writeCont(uint8_t a, uint8_t *b, byte l){

	send(((a&0x1F)|(BIT5)), b, l,false);
}
void RFSPI::readCont(uint8_t a, uint8_t *b, uint8_t l){

	send(((a&0x1F)|(BIT5|BIT6)), b, l,true);
}
void RFSPI::writePacket(uint8_t* pfbuf, uint8_t crc_bit, uint8_t total_len, uint8_t payload_len, bool header_enable, uint8_t broken_bits){
	volatile int i;

	SLAVESELECT_LOW(); //Start SPI Mode

	if(header_enable)
	{
		byte len_low_nibble = (total_len & 0x0F) << 4;
		byte len_high_nibble = (total_len & 0xF0) >> 4;
		transfer(0x8F);		// Reset FIFO
		transfer(0x90 | (crc_bit & 0x01));		// Reset FIFO
		transfer(0x3D);		// Continuous write to Length Register)
		if(broken_bits == 0x00)
		{
			transfer(len_high_nibble);		// High Length Nibble
			transfer(len_low_nibble);		// Low Length Nibble
		}
		else
		{
			// Broken bit
			transfer(0x00);
			transfer((broken_bits << 0x01) | 0x01);
		}

	}
	else
	{
		transfer(0x3F);			// Continuous Write to FIFO
//		if(payload_len == 0x01)
//			transfer(0x1F);			// Single Write to FIFO
//		else
//			transfer(0x3F);			// Continuous Write to FIFO
	}

	while(payload_len > 0)
	{
		transfer(*pfbuf++);
		payload_len--;
	}

	SLAVESELECT_HIGH(); //Stop SPI Mode

}


