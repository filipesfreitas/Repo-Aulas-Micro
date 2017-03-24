/* --COPYRIGHT--,BSD
 * Copyright (c) 2016, Texas Instruments Incorporated
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
//*****************************************************************************
//! CAPT_CommConfig.h
//! This file configures the Captivate COMM stack.
//
//! \version 1.04.00.00
//! Released on Mon, Aug 15, 2016  5:06:13 PM
//
//*****************************************************************************
//*****************************************************************************
//! \addtogroup CAPT_Interface
//! \{
//*****************************************************************************

#ifndef CAPT_COMMCONFIG_H_
#define CAPT_COMMCONFIG_H_

//*****************************************************************************
//
// CAPT_INTERFACE may be defined as one of the following options:
//
//! def __CAPT_NO_INTERFACE__ disables the communications module.
//
//! def __CAPT_UART_INTERFACE__ sets the interface to UART.
//
//! def __CAPT_BULKI2C_INTERFACE__ sets the interface to I2C Bulk.
//
//! def __CAPT_REGISTERI2C_INTERFACE__ sets the interface to I2C Register.
//
//*****************************************************************************
#define __CAPT_NO_INTERFACE__                                               (0)
#define __CAPT_UART_INTERFACE__				                                (1)
#define __CAPT_BULKI2C_INTERFACE__			                                (2)
#define __CAPT_REGISTERI2C_INTERFACE__		                                (3)

//*****************************************************************************
//
// Include the user's configuration selection options  from the CAPT_UserConfig
// to integrate them into the library build.
//
//*****************************************************************************
#include "CAPT_UserConfig.h"

//*****************************************************************************
//
//! def CAPT_TRANSMIT_BUFFER_SIZE defines the size of the transmit buffer.
//! Note that 2x this size will be allocated, since ping-pong buffering is
//! used.  This should be at least 2x the size of the largest packet, to allow
//! for byte stuffing.
//
//*****************************************************************************
#define CAPT_TRANSMIT_BUFFER_SIZE			(48)

//*****************************************************************************
//
//! def CAPT_QUEUE_BUFFER_SIZE defines the size of the receive queue buffer.
//
//*****************************************************************************
#define CAPT_QUEUE_BUFFER_SIZE				(256)

//*****************************************************************************
//
//! def CAPT_REGISTER_I2C_BUFFER_SIZE defines the size of the I2C Rx buffer.
//
//*****************************************************************************
#define CAPT_I2C_RECEIVE_BUFFER_SIZE		(32)

//*****************************************************************************
//
//! def CAPT_I2C_REGISTER_RW_BUFFER_SIZE defines the size of the I2C
//! register mode working buffer.
//
//*****************************************************************************
#define CAPT_I2C_REGISTER_RW_BUFFER_SIZE	(32)

//*****************************************************************************
//
//! \def UART__ENABLE controls whether the UART driver is included.
//! \def I2CSLAVE__ENABLE controls whether the I2C slave driver is included.
//! \def FUNCTIONTIMER__ENABLE controls whether the I2C slave driver is
//! included.
//
//*****************************************************************************
#if (CAPT_INTERFACE==__CAPT_UART_INTERFACE__)
#define UART__ENABLE			(true)
#define I2CSLAVE__ENABLE		(false)
#define FUNCTIONTIMER__ENABLE	(false)
#elif (CAPT_INTERFACE==__CAPT_BULKI2C_INTERFACE__)
#define UART__ENABLE			(false)
#define I2CSLAVE__ENABLE		(true)
#define FUNCTIONTIMER__ENABLE	(true)
#elif (CAPT_INTERFACE==__CAPT_REGISTERI2C_INTERFACE__)
#define UART__ENABLE			(false)
#define I2CSLAVE__ENABLE		(true)
#define FUNCTIONTIMER__ENABLE	(true)
#endif

#endif /* CAPT_COMMCONFIG_H_ */

//*****************************************************************************
//! Close the doxygen group
//! @}
//*****************************************************************************
