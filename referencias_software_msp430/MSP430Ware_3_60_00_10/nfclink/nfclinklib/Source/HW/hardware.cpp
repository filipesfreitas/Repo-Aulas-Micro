/*
 * hardware.cpp
 *
 *  Created on: 18.09.2012
 *      Author: A
 */

#include "hardware.h"
#include "API.h"
#include "MSP430_hardware.h"
#include "tool.h"
#include "host_interface.h"
#include "SPI.h"
#include "RFID.h"
#include "DebugPrint.h"
#include "msp430.h"

static bool _isReset;

void HW::Init() {

	word reclen = 0;
	HWConfig::Init();
	GPIO::Init();
	Host_Interface::Init();
	HWTimer::Init();
	RFID::Call(RFID_INIT, 0, 0, 0, reclen);


	_isReset = false;
	return;
}

void HW::Idle() {

}

void HW::run() {
	if (_isReset)
		HW::reset();
}

//Todo: refactoring - use a separate opcode/subopcode for RS232::Received(). Otherwise this method returns the number of bytes even if recbuf=NULL and reclen=0
word SerialInterface(byte *sendbuf, word sendlen, byte *recbuf, word reclen) {
	if ((sendlen == 0) && (reclen > 0)) {
		return Host_Interface::Read(recbuf, reclen);
	}
	if ((sendlen > 0) && (reclen == 0)) {
		Host_Interface::Write(sendbuf, sendlen);
	}
	if ((sendlen == 0) && (reclen == 0)) {
		return Host_Interface::Received();
	}
	return 0;
}

/**
 * <b> Hardware Call Interface </b>
 * <p>
 * Todo: add description
 * </p>
 * @param opcode contains the Command code
 * @param sendbuf contains the reveived data from host.
 * @param sendlen contains the length of revieved data from host
 * @param recbuf contains the sending data to the host.
 * @param reclen contains the length of sending data to the host
 * @return returns the length of the received data
 */
word HW::Call(word opcode, byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	switch (opcode) {

	case HW_VERSION:
		return hwVersion(sendlen, recbuf, reclen);
	case HW_RESET:
			if (sendlen != 0) {
				reclen = 0;
				return WRONG_LENGTH;
			}
			_isReset = true;
			reclen = 0;
			return OK; //will probably not be transmitted
	case HW_DH_INTERFACE:
	case HW_UART:
		reclen = SerialInterface(sendbuf, sendlen, recbuf, reclen);
		return OK;
	case HW_DEBUG_READ:
		reclen = DebugPrint::Read(recbuf, 253);
		//reclen=DebugPrint::Read(recbuf,reclen);
		return OK;
	 case HW_SET_BOOT_FLAG:
//TODO	insert your code for bootloader activation
	        return OK;

	default:
		//DebugPrint::Write("\nUNKNOWN opcode: %04x in HW::CALL", opcode);
		reclen = 0;
		return UNKNOWN_COMMAND;
	}
}

/**
 * <b>Call</b>
 * <p>
 * Wrapper for HW::Call
 * </p>
 * @param opcode contains the Command code
 * @return returns the reclen of the called method (needed for HW_UART) else returns the status code
 */
word HW::Call(word opcode) {
	word rlen = 1;
	byte r[1] = { 0 };
	word ret = 0;
	ret = Call(opcode, NULL, (word) 0, r, rlen);

	//if(rlen > 256) { return ret; }
	//else { return rlen; }

	//if no error occured and one byte is received, return this byte as lower byte
	if (ret == OK && rlen == 1) {
		return r[0] & 0x00FF;
	} else {
		return ret;
	}
}

/**
 * <b>Call</b>
 * <p>
 * Wrapper for HW::Call
 * </p>
 * @param opcode contains the opcode to execute
 * @param s1 contains the only parameter sent via sendbuf. sendlen will be 1.
 * @return any errorcode from HW::Call. If the call was OK and returned exactly one byte via recbuf, this byte is returned as lower byte.
 */
 word HW::Call(word opcode, byte s1) {
	word rlen = 1;
	byte r[1] = { 0 };
	word ret = Call(opcode, &s1, 1, r, rlen);

	//if no error occured and one byte is received, return this byte as lower byte
	if (ret == OK && rlen == 1) {
		return r[0] & 0x00FF;
	} else {
		return ret;
	}
}

/**
 * <b>Call</b>
 * <p>
 * Wrapper for HW::Call
 * </p>
 * @param opcode contains the opcode to execute
 * @param s1 contains sendbuf[0].
 * @param s2 contains sendbuf[1]. If s2 is a word (higher byte is not 0x00) then s2 is sent as sendbuf[1] and sendbuf[2]
 * @return any errorcode from HW::Call. If the call was OK and returned exactly one byte via recbuf, this byte is returned as lower byte.
 */
 word HW::Call(word opcode, byte s1, word s2) {
	byte r[1] = { 0 };
	word rlen = 1;
	word ret;

	if (s2 & 0xFF00) {
		byte b[] = { s1, (s2 >> 8), (s2 & 0x00FF) };
		ret = Call(opcode, b, 3, r, rlen);
	} else {
		byte b[] = { s1, (byte) s2 };
		ret = Call(opcode, b, 2, r, rlen);
	}

	//if no error occured and one byte is received, return this byte as lower byte
	if (ret == OK && rlen == 1) {
		return r[0] & 0x00FF;
	} else {
		return ret;
	}
}

/**
 * <b>HW Version</b>
 * <p>
 * Todo: add description
 * </p>
 * @param sendlen
 * @param recbuf
 * @param reclen
 * @return
 */word HW::hwVersion(word sendlen, byte *recbuf, word &reclen) {
	if (sendlen != 0) {
		reclen = 0;
		return WRONG_LENGTH;
	}
	if (reclen > HW_VERSION_LENGTH)
		reclen = HW_VERSION_LENGTH;
	if (reclen < HW_VERSION_LENGTH) {
		reclen = 0;
		return DATA_OVERFLOW;
	}
	memcpy(recbuf, (byte *) HW_VERSION_STR, HW_VERSION_LENGTH);
	return OK;
}

/**
 * <b> Reset </b>
 * <p>
 * This method performs a µC reset. Before the reset will be performed it waits till the the UART
 * has finished sending. At maximum 15ms will be waited, after this time the reset will be performed
 * even if the UART is still sending.
 * </p>
 */
void HW::reset() {
	_isReset = false;
	//HWConfig::MCU_Reset();
	return;
}
