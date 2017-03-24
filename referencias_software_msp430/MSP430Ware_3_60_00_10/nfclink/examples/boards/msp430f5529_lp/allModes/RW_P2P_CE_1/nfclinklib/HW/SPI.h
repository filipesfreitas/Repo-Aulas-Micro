/** @file   SPI.h
 *  @brief  Header file with functions for SPI Master 
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


#ifndef __SPI_H
#define __SPI_H

#include "hardware.h"
#include <stdint.h>
//
// Macro definitions
//
/*! SPI Bit Rate divider MSB - 2 Mbit for 25MHz Clock */
#define SPIBAUD0  6
/*! SPI Bit Rate divider MSB - 2 Mbit for 25MHz Clock */
#define SPIBAUD1  0


// SPI pins in MSP430
/*! SPI PSEL register (Port3 for MSP430F5529 USCI_B0) */
#define SPI_PSEL                P3SEL
/*! SPI DIR register */
#define SPI_DIR                 P3DIR
/*! SPI OUT register */
#define SPI_OUT                 P3OUT
/*! SPI IN register */
#define SPI_IN                  P3IN
/*! SPI MOSI pin (P3.0) */
#define SPI_MOSI_PIN            BIT0
/*! SPI MISO pin (P3.1) */
#define SPI_MISO_PIN            BIT1
/*! SPI CLK pin (P3.3) */
#define SPI_CLK_PIN             BIT2

/*!SPI SS PSEL register */
#define SPI_SS_PSEL             P4SEL
/*!SPI SS DIR register */
#define SPI_SS_DIR              P4DIR
/*!SPI SS OUT register */
#define SPI_SS_OUT              P4OUT
/*!SPI SS IN register */
#define SPI_SS_IN               P4IN
/*! SPI SS pin (P2.6) */
#define SPI_SS_PIN              BIT2
/*! Sets SPI SS pin as output */
#define SLAVESELECT_OUTPUT()    {SPI_SS_DIR |= SPI_SS_PIN;}
/*! Sets SPI SS pin high */
#define SLAVESELECT_HIGH()      {SPI_SS_OUT |= SPI_SS_PIN;}
/*! Sets SPI SS pin low */
#define SLAVESELECT_LOW()       {SPI_SS_OUT &= ~SPI_SS_PIN;}

//USCI Register for SPI communication with TRF - uses USCI_B0
/*! USCI CTL0 register */
#define  UCSPICTL0              UCB0CTL0
/*! USCI CTL1 register */
#define  UCSPICTL1              UCB0CTL1
/*! USCI RXBUF register */
#define  UCSPIRXBUF             UCB0RXBUF
/*! USCI TXBUF register */
#define  UCSPITXBUF             UCB0TXBUF
/*! USCI IFG register */
#define  UCSPIIFG               UCB0IFG
/*! USCI STAT register */
#define  UCSPISTAT              UCB0STAT

#define SPIMODE					0x01

// Hardware GPIO definition
/*! Enable pin for TRF7970: P4.1 */
#define TRF_ENABLEBIT           BIT1
/*! Sets Enable pin as output */
#define TRF_ENABLESET()         {P4DIR |= TRF_ENABLEBIT;}
/*! Enables the TRF7970 */
#define TRF_ENABLE()            {P4OUT |= TRF_ENABLEBIT;}
/*! Disables the TRF7970 */
#define TRF_DISABLE()           {P4OUT &= ~TRF_ENABLEBIT;}


#define IRQ_PIN					BIT2
#define IRQ_PIN_SET()			{P2DIR &= ~IRQ_PIN;}
#define IRQ_PORT				P2IN
#define IRQ_INT_ON()			{P2IE |= IRQ_PIN;}		// IRQ on P2.2
#define IRQ_INT_OFF()			{P2IE &= ~IRQ_PIN;}		// IRQ on P2.2
#define IRQ_EDGE_SET()			{P2IES &= ~IRQ_PIN;}		// rising edge interrupt
#define IRQ_CLR()				{P2IFG &= ~IRQ_PIN;}
#define IRQ_REQ_REG				P2IFG

#define IRQ_IS_SET()            (IRQ_PORT & IRQ_PIN)

//
// Function prototypes
//
class RFSPI{
private:

public:
	static byte transfer(uint8_t data_out);
	static void send(uint8_t mode_addr, uint8_t *pbuf, uint8_t length,bool read_flag);
	static void waitBus(void);

	static void init(void);
	static void write(uint8_t a, uint8_t *b);
	static void read(uint8_t a, uint8_t *b);
	static void rawWrite(uint8_t *pbuf, uint8_t length);
	static void readCont(uint8_t a, byte *b, uint8_t l);
	static void writeCont(uint8_t a, uint8_t *b, uint8_t l);
	static void writePacket(uint8_t* pfbuf, uint8_t crc_bit, uint8_t total_len, uint8_t payload_len, bool header_enable, uint8_t broken_bits);

};


#endif //__SPI_H
