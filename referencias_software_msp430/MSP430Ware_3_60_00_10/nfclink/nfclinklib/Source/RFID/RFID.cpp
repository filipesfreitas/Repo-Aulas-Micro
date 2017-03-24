/*******************************************************************************
 * @file    RFID.cpp
 * @brief
 * @version V0.0.2
 * @date    05/28/2014
 *
 * THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". KRONEGGER
 * GMBH MAKES NO OTHER WARRANTY OF ANY KIND, WHETHER EXPRESS, IMPLIED OR,
 * STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. KRONEGGER GMBH
 * RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
 * REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
 * THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
 *
 * KRONEGGER GMBH SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL
 * DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR ANY
 * DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR PROFITS,
 * DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE DAMAGES,
 * LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION WITH THIS
 * AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
 * PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
 * WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
 *
 * (C)Copyright Kronegger GmbH 2012 All rights reserved
 ******************************************************************************/

//#define _MSP430F5438
#define _MSP430F5529

#include "RFID.h"
#include "hardware.h"
#include "SPI.h"
#include "API.h"
#include "tool.h"
#include "DebugPrint.h"
#include "buffer.h"
#include "msp430.h"
#include "NCI_API.h"
#include "MSP430_hardware.h"
#include "TRF7970A.h"

#define MAXGUARDTIME 5
#define HAL_LF_T3T_MAX          (byte)0x01

static byte selectedFrameType = 0xFF;
static byte selectedBaudrate = BAUDRATE_106;

static const indextype BuffSize = 256;
static Buffer<indextype, BuffSize> mailbox;

bool RFID::isRxMultiple = false;
bool RFID::isNFCActive = false;

byte RFID::current_frame_type = NO_TAG_MODE;
byte RFID::current_frame_param = 0;
byte RFID::bitFrame = 0;
byte RFID::stmReceiveMode = RCV_IDLE;

bool g_bNfcTargetEnable = false;

struct RFID::_AAC {
	byte sens_res[2];byte sel_res;byte prot_sel[2];byte Padding[8];byte sys_code[2];byte pupi[4];byte afi;byte crc_aid[2];byte number_apli;byte proto_info[4];byte lfT3tFlags[2];byte lfProtocolType;byte lfAdvFeat;byte lfConBitrF;
} RFID::AACconfig;

Array<10> RFID::nfcid1; //ISO/IEC 18092 11.2.1.26 NFCID1 contents and cascade levels
Array<8> RFID::nfcid2; //ISO/IEC 18092 11.2.2.4 NFCID2 contents

static word _PICCTimeout = 200; // TODO: Check if this is being used

#define NFC_FIFO_SIZE 		255

uint8_t g_ui8FifoBuffer[NFC_FIFO_SIZE];

t_sTRF797x_Bitrate g_sTargetSupportedBitrates;
t_sTRF797x_TargetMode g_sTargetSupportedTechnologies;
tTRF797x_Status g_sTrf7970Status;

volatile uint8_t g_ui8IrqFlag;

uint8_t g_ui8TargetId[10];
uint8_t g_ui8IdLength;
bool g_bNfcDepSupport;
bool g_bIsoDepSuport;

extern "C" void RF_WriteMailBox(unsigned char *data, unsigned char len) {
	mailbox.Write(data, len);
}

extern "C" uint8_t RF_getBitframe(void) {
	return RFID::bitFrame;
}

extern "C" void RF_anticollisionProcess(uint8_t * pui8SendBuf,
		uint8_t ui8Length) {
	RFID::anticollisionProcess(pui8SendBuf, ui8Length);
}

/**
 *<b>Call Interface</b>
 *<p>
 * Todo: add description
 *</p>
 *@param opcode contains the Command code
 *@param sendbuf contains the reveived data from host.
 *@param sendlen contains the length of revieved data from host
 *@param recbuf contains the sending data to the host.
 *@param reclen contains the length of sending data to the host
 *@return
 */word RFID::Call(word opcode, byte *sendbuf, word sendlen, byte *recbuf,
		word &reclen) {

	switch (opcode) {
	case RFID_INIT:
		Init(sendbuf, sendlen, recbuf, reclen);
		return OK;
	case RFID_VERSION:
		return version(sendbuf, sendlen, recbuf, reclen);
	case RFID_FRAMETYPE: {
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		word ret = 0;
		ret = FrameType(sendbuf[0], sendbuf[1]);
		if (ret != OK) {
			reclen = 0;
			return ret;
		}
		/*if(reclen >= 1) {
		 reclen = 1;
		 recbuf[0]=param;
		 }*/
		return OK;
	}
	case RFID_TRANSCEIVE: {

		if ((sendlen == 0) && (reclen == 0)) {
			return GENERAL_ERROR;
		}

		if ((sendlen == 0) && (reclen != 0)) {
			return RFID::readMailbox(recbuf, reclen);
		} else {

			//			if (sendlen != 6) {
			//			DebugPrint::Write("\nsendbuf[%02x]: ", sendlen);
			//			DebugPrint::Hex(sendbuf, sendlen);
			//			}
			word ret = RFID::transceive(0, sendbuf, sendlen, recbuf, reclen);
			//DebugPrint::Write("\nBitCollsionPos: %02x \nrecbuf: ", BitCollision());
			//DebugPrint::Write("recbuf[%02x]: ", reclen);
			//DebugPrint::Hex(recbuf, reclen);

			if (ret == RF_FRAMING_ERROR)
				P6OUT = 0x00;

			return ret;

		}

	}
	case RFID_AUTHENTICATE:
		return UNKNOWN_COMMAND;

	case RFID_CONTROL:
		if (sendlen < 1) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		return RFID::control(sendbuf, sendlen, recbuf, reclen);
	case RFID_DISCOVERY:
		return modeDetection(recbuf, reclen);
	case RFID_RESET:
		return UNKNOWN_COMMAND;
	default:
		//printf("RFID: unknown command %x\n",opcode);
		reclen = 0;
		return UNKNOWN_COMMAND;
	}
}

/**
 *<b>Call</b>
 *<p>
 * Wrapper for RFID::Call
 *</p>
 *@param opcode contains the opcode to execute
 *@param s1 contains sendbuf[0].
 *@param s2 contains sendbuf[1]. If s2 is a word (higher byte is not 0x00) then s2 is sent as sendbuf[1] and sendbuf[2]
 *@return any errorcode from RFID::Call. If the call was OK and returned exactly one byte via recbuf, this byte is returned as lower byte.
 */word RFID::Call(word opcode, byte s1, word s2) {
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
 *<b>Call</b>
 *<p>
 * Wrapper for RFID::Call
 *</p>
 *@param opcode contains the opcode to execute
 *@param s1 contains the only parameter sent via sendbuf. sendlen will be 1.
 *@return any errorcode from RFID::Call. If the call was OK and returned exactly one byte via recbuf, this byte is returned as lower byte.
 */word RFID::Call(word opcode, byte s1) {
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

//Sets a parameter to the given value
// type			parameter
// value		value for the parameter
void RFID::Timing(byte type, word value) {
	switch (type) {
	case PCD_GUARD_TIME:
		//_PCDGuardTime = value;
		break;
	case PICC_TIMEOUT:
		_PICCTimeout = value;
		break;
	case TRANSMISSIONTIMEOUT:
		//_TransmissionTimeout = value;
		break;
	case RECEIVE_TIMEOUT:
		//_ReceiveTimeout = value;
		break;
	}
}

int RFID::run() {
	if ((g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE)) {
		TRF797x_irqHandler(0);
	}
	return OK;
}

void RFID::callbackInit(bool (*callback)()) {
	RFID::callbackFunction = callback;
}

/**
 *<b>Setup Frame</b>
 *@param isNFC_TargetMode is a flag which is only true when initialized as Target (active and passive)
 *@param isNFCActive is a flag which is only be used to for set registers for higher baudrates
 *@param isNFC_Passive_Target was used at the transceive switch methode. Isn't used anymore, left here for tests
 */
void RFID::SetupFrame(byte mode) {
	// TODO modify with new target/initiator setup functions
	isRxMultiple = false;
	isNFCActive = false; //Only set by NFC_INITIATOR_ACTIVE to set the baudrate register
	bitFrame = 0x00;
	stmReceiveMode = RCV_IDLE;
	t_sTRF797x_InitiatorMode eInitiatorMode;
	t_sTRF797x_Bitrate eBitrate;
	volatile t_sTRF797x_TargetMode eSupportedTargetModes;

	eInitiatorMode.ui8byte = 0x00;
	eBitrate.ui16word = 0x0000;
	eSupportedTargetModes.ui8byte = 0x00;

	switch (mode) {
	case ISO14443A_BYTEFRAME:
		eInitiatorMode.bits.bPassiveTypeA = 1;
		eBitrate.bits.b106kpbs = 1;
		selectedFrameType = ISO14443A_BYTEFRAME;
		selectedBaudrate = BAUDRATE_106;
		TRF797x_initiatorModeSetup(eInitiatorMode, eBitrate);
		break;
	case ISO14443B_BYTEFRAME:
		eInitiatorMode.bits.bPassiveTypeB = 1;
		eBitrate.bits.b106kpbs = 1;
		selectedFrameType = ISO14443B_BYTEFRAME;
		selectedBaudrate = BAUDRATE_106;
		TRF797x_initiatorModeSetup(eInitiatorMode, eBitrate);
		break;
	case ISO15693_BYTEFRAME:
		eInitiatorMode.bits.bPassive15693 = 1;
		eBitrate.bits.b26_48_kbps_1_out_4 = 1;
		selectedFrameType = ISO15693_BYTEFRAME;
		selectedBaudrate = BAUDRATE_26_48;
		TRF797x_initiatorModeSetup(eInitiatorMode, eBitrate);
		break;
	case FELICA_BYTEFRAME:
		eInitiatorMode.bits.bPassiveTypeF = 1;
		eBitrate.bits.b212kpbs = 1;
		selectedFrameType = FELICA_BYTEFRAME;
		selectedBaudrate = BAUDRATE_212;
		TRF797x_initiatorModeSetup(eInitiatorMode, eBitrate);
		break;
	case NFC_INITIATOR_ACTIVE:
		// TODO: Check if this parameter is called. Should not be called
		break;
	case NFC_TARGET_PASSIVE:
		// TODO: Check if this parameter is called. Should not be called
		break;
	case NFC_TARGET_ACTIVE:
		// TODO: Check if this parameter is called. Should not be called
		break;
	case LISTEN_A_PASSIVE:
		// Clear Supported Technologies & Bitrates
		g_sTargetSupportedTechnologies.ui8byte = 0x00;
		g_sTargetSupportedBitrates.ui16word = 0x0000;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeA = 1;
		g_sTargetSupportedBitrates.bits.b106kpbs = 1;
//		selectedFrameType = LISTEN_A_PASSIVE;
//		selectedBaudrate = BAUDRATE_106;
		if (g_sTrf7970Status.eCurrentMode != TRF_TARGET_MODE) {
			TRF797x_setTargetSelect(false);
			TRF797x_targetModeSetup(g_sTargetSupportedTechnologies,
					g_sTargetSupportedBitrates);
		}
		mailbox.flush();
		break;
	case LISTEN_B_PASSIVE:
		// Clear Supported Technologies & Bitrates
		g_sTargetSupportedTechnologies.ui8byte = 0x00;
		g_sTargetSupportedBitrates.ui16word = 0x0000;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeB = 1;
		g_sTargetSupportedBitrates.bits.b106kpbs = 1;
//		selectedFrameType = LISTEN_B_PASSIVE;
//		selectedBaudrate = BAUDRATE_106;
		if (g_sTrf7970Status.eCurrentMode != TRF_TARGET_MODE) {
			TRF797x_setTargetSelect(false);
			TRF797x_targetModeSetup(g_sTargetSupportedTechnologies,
					g_sTargetSupportedBitrates);
		}
		mailbox.flush();
		break;
	case LISTEN_AB_PASSIVE:
		// Clear Supported Technologies & Bitrates
		g_sTargetSupportedTechnologies.ui8byte = 0x00;
		g_sTargetSupportedBitrates.ui16word = 0x0000;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeA = 1;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeB = 1;
		g_sTargetSupportedBitrates.bits.b106kpbs = 1;
//		selectedFrameType = LISTEN_AB_PASSIVE;
		if (g_sTrf7970Status.eCurrentMode != TRF_TARGET_MODE) {
			TRF797x_setTargetSelect(false);
			TRF797x_targetModeSetup(g_sTargetSupportedTechnologies,
					g_sTargetSupportedBitrates);
		}
		mailbox.flush();
		break;
	case LISTEN_F_PASSIVE:
		// Clear Supported Technologies & Bitrates
		g_sTargetSupportedTechnologies.ui8byte = 0x00;
		g_sTargetSupportedBitrates.ui16word = 0x0000;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeF = 1;
		g_sTargetSupportedBitrates.bits.b212kpbs = 1;
		g_sTargetSupportedBitrates.bits.b424kpbs = 1;
//		selectedFrameType = LISTEN_F_PASSIVE;
		if (g_sTrf7970Status.eCurrentMode != TRF_TARGET_MODE) {
			TRF797x_setTargetSelect(false);
			TRF797x_targetModeSetup(g_sTargetSupportedTechnologies,
					g_sTargetSupportedBitrates);
		}
		mailbox.flush();
		break;
	case LISTEN_AF_PASSIVE:
		// Clear Supported Technologies & Bitrates
		g_sTargetSupportedTechnologies.ui8byte = 0x00;
		g_sTargetSupportedBitrates.ui16word = 0x0000;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeA = 1;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeF = 1;
		g_sTargetSupportedBitrates.bits.b106kpbs = 1;
		g_sTargetSupportedBitrates.bits.b212kpbs = 1;
		g_sTargetSupportedBitrates.bits.b424kpbs = 1;
//		selectedFrameType = LISTEN_AF_PASSIVE;

		if (g_sTrf7970Status.eCurrentMode != TRF_TARGET_MODE) {
			TRF797x_setTargetSelect(false);
			TRF797x_targetModeSetup(g_sTargetSupportedTechnologies,
					g_sTargetSupportedBitrates);
		}
		mailbox.flush();
		break;
	case LISTEN_BF_PASSIVE:
		// Clear Supported Technologies & Bitrates
		g_sTargetSupportedTechnologies.ui8byte = 0x00;
		g_sTargetSupportedBitrates.ui16word = 0x0000;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeB = 1;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeF = 1;
		g_sTargetSupportedBitrates.bits.b106kpbs = 1;
		g_sTargetSupportedBitrates.bits.b212kpbs = 1;
		g_sTargetSupportedBitrates.bits.b424kpbs = 1;
//		selectedFrameType = LISTEN_BF_PASSIVE;
		if (g_sTrf7970Status.eCurrentMode != TRF_TARGET_MODE) {
			TRF797x_setTargetSelect(false);
			TRF797x_targetModeSetup(g_sTargetSupportedTechnologies,
					g_sTargetSupportedBitrates);
		}
		mailbox.flush();
		break;
	case LISTEN_ABF_PASSIVE:
		// Clear Supported Technologies & Bitrates
		g_sTargetSupportedTechnologies.ui8byte = 0x00;
		g_sTargetSupportedBitrates.ui16word = 0x0000;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeA = 1;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeB = 1;
		g_sTargetSupportedTechnologies.bits.bPassiveTypeF = 1;
		g_sTargetSupportedBitrates.bits.b106kpbs = 1;
		g_sTargetSupportedBitrates.bits.b212kpbs = 1;
		g_sTargetSupportedBitrates.bits.b424kpbs = 1;
//		selectedFrameType = LISTEN_ABF_PASSIVE;
		if (g_sTrf7970Status.eCurrentMode != TRF_TARGET_MODE) {
			TRF797x_setTargetSelect(false);
			TRF797x_targetModeSetup(g_sTargetSupportedTechnologies,
					g_sTargetSupportedBitrates);
		}
		mailbox.flush();
		break;
	case NO_TAG_MODE:
		TRF797x_idleMode();
		break;
	default:
		//DebugPrint::Write("\nUnknown Frametype");
		break;
	}

	return;
}

/**
 *<b>callback</b>
 *<p>
 * call function in NCI.cpp for protocol handling
 *</p>
 *@return returns TRUE or FALSE for aborting
 */
bool RFID::callback() {
	static Timer tCallback;

	if (tCallback.iselapsed()) {
		if (callbackFunction()) {
			return true;
		}
		tCallback.Start(100);
	}
	return false;
}

bool (*RFID::callbackFunction)() = &RFID::functionDummy;

void RFID::anticollisionProcess(byte *sendbuf, byte length) {
	byte ui8ResBuffer[40];
	byte ui8BufIdx = 0;
	byte ui8Command;

	ui8Command = sendbuf[0];

	TRF797x_setTargetSelect(false);

	switch (ui8Command) {
	//
	// Type A Commands
	//

	//
	// Received a REQA / SENS_REQ or WUPA
	//
	case 0x26:
	case 0x52:

		if(g_sTargetSupportedTechnologies.bits.bPassiveTypeA == 1)
		{
			// Register 01h. ISO Control Register
			//
			// 106 kbps Tag Emulator 14443A mode
			//

			// BIT15:12 RFU
			// BIT11:8 Proprietary - 0x03
			// BIT7:6  NFCID Length - 00 - Single, 01 - Double, 11 - Triple
			// BIT5 RFU
			// BIT4:0 Bit frame anti-collision - Bit 1

			// Note: Otherwise we receive a 0x30 0x0C 0x01 from the reader
			ui8ResBuffer[ui8BufIdx++] = AACconfig.sens_res[0];
			ui8ResBuffer[ui8BufIdx++] = 0x00;
			TRF797x_writeFIFO(ui8ResBuffer, CRC_BIT_DISABLE, ui8BufIdx, 0);

			// Register 01h. ISO Control Register - Receive @ 106 kbps without CRC.
			TRF797x_writeSingle(0xA4, TRF79X0_ISO_CONTROL_REG);
		}

		break;

		//
		// Received a anticollision command # 1
		//
	case 0x93:

		if(g_sTargetSupportedTechnologies.bits.bPassiveTypeA == 1)
		{
			//
			// Cascade level 1
			//
			if (sendbuf[1] == 0x20) {
				//
				// Clear Buffer[5]
				//
				ui8ResBuffer[4] = 0x00;
				for (ui8BufIdx = 0; ui8BufIdx < 4; ui8BufIdx++) {
					ui8ResBuffer[ui8BufIdx] = nfcid1.data[ui8BufIdx];
					ui8ResBuffer[4] ^= nfcid1.data[ui8BufIdx];
				}
				TRF797x_writeFIFO(ui8ResBuffer, CRC_BIT_DISABLE, 5, 0);
			}
			//
			// PCD Selected the TRF7970 based on the UID
			//
			else if (sendbuf[1] == 0x70) {

				// BIT5 - UID Complete, PICC Compliant with ISO / IEC 14443-4
				ui8ResBuffer[ui8BufIdx++] = AACconfig.sel_res; // SAK
				//NFCSend(&buffer[0]); //Send complete UID (93 20) / SAK ( 93 70 + UID)
				TRF797x_writeFIFO(ui8ResBuffer, CRC_BIT_ENABLE, ui8BufIdx, 0);

				//
				// 106 kbps Tag Emulator 14443A mode
				//
				// Register 01h. ISO Control Register
				TRF797x_writeSingle(0x24, TRF79X0_ISO_CONTROL_REG);

				// Disable Anti-collision Frames for 14443A.
				TRF797x_writeSingle(0x02, TRF79X0_SPECIAL_FUNC_1_REG);

				selectedFrameType = ISO14443A_BYTEFRAME;
				selectedBaudrate = BAUDRATE_106;

				TRF797x_setTargetSelect(true);
			}
		}

		break;

	case 0x05:

		if(g_sTargetSupportedTechnologies.bits.bPassiveTypeB == 1)
		{
			// ATQB Packet
			ui8ResBuffer[ui8BufIdx++] = 0x50; // ATQB Start Byte
			// NFCID 3:0
			ui8ResBuffer[ui8BufIdx++] = AACconfig.pupi[0];
			ui8ResBuffer[ui8BufIdx++] = AACconfig.pupi[1];
			ui8ResBuffer[ui8BufIdx++] = AACconfig.pupi[2];
			ui8ResBuffer[ui8BufIdx++] = AACconfig.pupi[3];

			// Application Data Bytes
			ui8ResBuffer[ui8BufIdx++] = AACconfig.afi; // AFI - Public Telephony, GSM ... ( See ISO14443-3 Table 12 AFI Coding)
			ui8ResBuffer[ui8BufIdx++] = AACconfig.crc_aid[0]; // CRC_B
			ui8ResBuffer[ui8BufIdx++] = AACconfig.crc_aid[1]; // CRC_B
			// TODO TI
			ui8ResBuffer[ui8BufIdx++] = 0x01; // # of applications (1)
			//		ui8ResBuffer[ui8BufIdx++] = TargetAC_number_apli; // # of applications (1)

			// Protocol Info Bytes
			ui8ResBuffer[ui8BufIdx++] = 0x00; // Date Rate Capability ( Only Support 106 kbps)
			// Max Frame/Protocol type (128 bytes / PICC compliant to -4)
			ui8ResBuffer[ui8BufIdx++] = 0x81;
			// (FWI/ADC/FO) ( FWT = 77.3mSec, ADC = coded according to AFI, CID supported)
			ui8ResBuffer[ui8BufIdx++] = 0xD5;

			TRF797x_writeFIFO(ui8ResBuffer, CRC_BIT_ENABLE, ui8BufIdx, 0);

			selectedFrameType = ISO14443B_BYTEFRAME;
			selectedBaudrate = BAUDRATE_106;

			// Testing new driver
			TRF797x_setTargetSelect(true);
		}

		break;
		//
		// Receive ATTRIB Req
		//
	case 0x1D:

		if(g_sTargetSupportedTechnologies.bits.bPassiveTypeB == 1)
		{
			if (sendbuf[1] == AACconfig.pupi[0] && sendbuf[2] == AACconfig.pupi[1]
					&& sendbuf[3] == AACconfig.pupi[2]
					&& sendbuf[4] == AACconfig.pupi[3]) {
				// ATTRIB Response
				ui8ResBuffer[ui8BufIdx++] = 0x00; // Length
				TRF797x_writeFIFO(ui8ResBuffer, CRC_BIT_ENABLE, ui8BufIdx, 0);

				selectedFrameType = ISO14443B_BYTEFRAME;
				selectedBaudrate = BAUDRATE_106;

				// Testing new driver
				TRF797x_setTargetSelect(true);
			}
		}

		break;
		//
		// Receive SENF_F REQ
		//
	case 0x06:

		if(g_sTargetSupportedTechnologies.bits.bPassiveTypeF == 1)
		{
			if (sendbuf[1] == 0x00 && sendbuf[2] == 0xFF && sendbuf[3] == 0xFF
					&& (sendbuf[4] == 0x01 || sendbuf[4] == 0x00))
			{
				if (sendbuf[4] == 0x01) {
					ui8ResBuffer[ui8BufIdx++] = 0x14; 	//SensF_Res Length
				} else {
					ui8ResBuffer[ui8BufIdx++] = 0x12; 	//SensF_Res Length
				}
				ui8ResBuffer[ui8BufIdx++] = 0x01;	//SensF_RES_CMD
				ui8ResBuffer[ui8BufIdx++] = nfcid2.data[0];	//nfcid2.data		//NFC-DEP Prot.(P2P-Target)=01;TagType3 Platform=02
				ui8ResBuffer[ui8BufIdx++] = nfcid2.data[1];
				ui8ResBuffer[ui8BufIdx++] = nfcid2.data[2];
				ui8ResBuffer[ui8BufIdx++] = nfcid2.data[3];
				ui8ResBuffer[ui8BufIdx++] = nfcid2.data[4];
				ui8ResBuffer[ui8BufIdx++] = nfcid2.data[5];
				ui8ResBuffer[ui8BufIdx++] = nfcid2.data[6];
				ui8ResBuffer[ui8BufIdx++] = nfcid2.data[7];
				ui8ResBuffer[ui8BufIdx++] = 0xC0;
				ui8ResBuffer[ui8BufIdx++] = 0xC1;
				ui8ResBuffer[ui8BufIdx++] = 0xC2;	//PAD1
				ui8ResBuffer[ui8BufIdx++] = 0xC3;
				ui8ResBuffer[ui8BufIdx++] = 0xC4;
				ui8ResBuffer[ui8BufIdx++] = 0xC5;	//MRTI_Check
				ui8ResBuffer[ui8BufIdx++] = 0xC6;	//MRTI_Update
				ui8ResBuffer[ui8BufIdx++] = 0xC7;	//PAD2
				if (sendbuf[4] == 0x01) {
					ui8ResBuffer[ui8BufIdx++] = 0xFF;	//[RD]
					ui8ResBuffer[ui8BufIdx++] = 0xFF;
				}

				// Delay for slot 0
				waitus(2250);

				TRF797x_writeFIFO(ui8ResBuffer, CRC_BIT_ENABLE, ui8BufIdx, 0);

				TRF797x_setTargetSelect(true);

				selectedFrameType = FELICA_BYTEFRAME;
			}
		}

		break;
		//
		// Receive HALT A/B
		//
	case 0x50:
		// Reset FIFO with an extra dummy clock

		if (selectedFrameType == ISO14443A_BYTEFRAME) {

			ui8ResBuffer[ui8BufIdx++] = 0x06; //response to HLTA
		}
		if (selectedFrameType == ISO14443B_BYTEFRAME) {

			ui8ResBuffer[ui8BufIdx++] = 0x00; // response to HLTB
		}
		TRF797x_writeFIFO(ui8ResBuffer, CRC_BIT_ENABLE, ui8BufIdx, 0);
		break;
		//
		// Receive Deselect
		//
	case 0xC2:

		if(g_sTargetSupportedTechnologies.bits.bPassiveTypeA == 1
			|| g_sTargetSupportedTechnologies.bits.bPassiveTypeB == 1)
		{
			ui8ResBuffer[ui8BufIdx++] = 0xC2; // response to deselect
			TRF797x_writeFIFO(ui8ResBuffer, CRC_BIT_ENABLE, ui8BufIdx, 0);

			TRF797x_setTargetSelect(false);
		}

		break;
	default:
		TRF797x_resetMode();
		break;
	}

}

bool RFID::functionDummy() {
	return false;
}

unsigned char RFID::BitCollision() {
	return 0xFF;
}

unsigned short RFID::Init(unsigned char* sendbuf, unsigned short sendlen,
		unsigned char* recbuf, unsigned short & reclen) {

	TRF797x_setup();

	//default initialization for the AAC()
	/* NFCForum TS Digital Protocol 1.0 */

	AACconfig.sens_res[0] = 0x04; //4.6.3 SENS_RES Response, Byte1
	AACconfig.sens_res[1] = 0x04; //Byte2
	AACconfig.sel_res = 0x40; //4.8.2 SEL_RES Response
	AACconfig.Padding[0] = 0xFF; //PAD0 = see NFC FORUM TS Digital Protocol 1.0; Padding is set with dummy values for testing Typ3 communication
	AACconfig.Padding[1] = 0xFF; //PAD0
	AACconfig.Padding[2] = 0xFF; //PAD1
	AACconfig.Padding[3] = 0xFF; //PAD1
	AACconfig.Padding[4] = 0xFF; //PAD1
	AACconfig.Padding[5] = 0xFF; //MRTIcheck
	AACconfig.Padding[6] = 0xFF; //MRTIupadate
	AACconfig.Padding[7] = 0xFF; //PAD2
	AACconfig.sys_code[0] = 0xFF; //HCI default 0x12
	AACconfig.sys_code[1] = 0xFF; //HCI default 0xFC
	AACconfig.afi = 0x00;

//	setSensRes(AACconfig.sens_res, 2);
//	setSelRes(AACconfig.sel_res);
//	setPadding(AACconfig.Padding, 8);
//	setSysCode(AACconfig.sys_code, 2);
//	setAFI(AACconfig.afi);

	nfcid1.data[0] = 0x08;
	nfcid1.data[1] = 0x12;
	nfcid1.data[2] = 0x34;
	nfcid1.data[3] = 0x56;
	nfcid1.len = 4;
//	setNfcid1(nfcid1.data, nfcid1.len);

	for (int i = 0; i < 6; i++) {
		nfcid1.data[i + 4] = 0x00;
	}

	nfcid2.data[0] = 0x02; // protocol Byte1
	nfcid2.data[1] = 0xFE; // protocol Byte2
	nfcid2.data[2] = 0x12;
	nfcid2.data[3] = 0x34;
	nfcid2.data[4] = 0x56;
	nfcid2.data[5] = 0x78;
	nfcid2.data[6] = 0x90;
	nfcid2.data[7] = 0xAB;
	nfcid2.len = 8;

//	setNfcid2(nfcid2.data, nfcid2.len);

	AACconfig.pupi[0] = 0x01;
	AACconfig.pupi[1] = 0x02;
	AACconfig.pupi[2] = 0x03;
	AACconfig.pupi[3] = 0x04;

//	setPupi_(AACconfig.pupi, 4);

	AACconfig.crc_aid[0] = 0x00;
	AACconfig.crc_aid[1] = 0x00;
	AACconfig.number_apli = 0x00;

//	setCRCAid(AACconfig.crc_aid, 2);
//	setNumberApli(AACconfig.number_apli);

	AACconfig.proto_info[0] = 0x00;
	AACconfig.proto_info[1] = 0x00;
	AACconfig.proto_info[2] = 0x45; //protocol info byte NCI default 0x45 (FWI 0x04) (ADC FO 0x05)
	AACconfig.proto_info[3] = 0x00;

//	setProtoInfo(AACconfig.proto_info, 4);

	return OK;
}

/**
 *<b>Version</b>
 *<p>
 Returns the actual version of the RFID layer.
 *</p>
 *@param sendbuf NULL
 *@param sendlen has to be 0 to be valid.
 *@param recbuf contains the version string which will be returned to host.
 *@param reclen contains the length of the valid data in recbuf.
 *@return <b>Zero</b> for OK. Else a ErrorCode according to API.h will be returned.
 */word RFID::version(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	if (sendlen != 0) {
		reclen = 0;
		return WRONG_LENGTH;
	}
	if (reclen > RFID_VERSION_LENGTH)
		reclen = RFID_VERSION_LENGTH;
	if (reclen < RFID_VERSION_LENGTH) {
		reclen = 0;
		return DATA_OVERFLOW;
	}
	memcpy(recbuf, (byte *) RFID_VERSION_STR, RFID_VERSION_LENGTH);
	return OK;
}

/**
 *<b>Set some necessary timeouts</b>
 *<p>
 Set either PCD_GUARD_TIME, PICC_TIMEOUT, TRANSMISSIONTIMEOUT or RECEIVE_TIMEOUT. Depends on the parameter
 which is send with.
 *</p>
 *@see Hardware Abstraction Layer Version 1.16, 4.4 RFID_CONTROL
 *@param sendbuf contains the opcode which timeout should be set and the value
 *@param sendlen has to be 2 or 3 to be valid!
 *@return <b>ZERO</b> if no error occured. Else a error code according to API.h will be returned.
 */word RFID::setTimeouts(byte *sendbuf, word sendlen) {
	if (sendlen == 2) {
		Timing(sendbuf[0], sendbuf[1]); //type, value
		return OK;
	} else if (sendlen == 3) {
		Timing(sendbuf[0], (word) (sendbuf[2]) + (word) (sendbuf[1] << 8)); //type, value
		return OK;
	} else {
		return WRONG_LENGTH;
	}
}

/**
 *<b>RFID Control</b>
 *<p>
 * Todo: add description
 *</p>
 *@param sendbuf
 *@param sendlen
 *@param recbuf
 *@param reclen
 *@return
 */
unsigned short RFID::transceive(unsigned char cmd, unsigned char* sendbuf,
		unsigned short sendlen, unsigned char* recbuf,
		unsigned short & reclen) {

	static Timer txTimer;
	static Timer tCallback;
	static Timer timeout;
	tTRF797x_IRQFlag sIrqStatusFlag;
	unsigned short ret_value = 0;
	unsigned char broken_frame_bits = 0;
	// Flag used to switch the RX setting to receive without CRC, once the
	//command to write has been sent, and a response has been received - the
	// flag will be used to switch the setting back to receive with CRC
	bool mifare_ultra_light_flag = false;
	bool iso15693_flag = false;

	if (g_sTrf7970Status.bProtocolError == true) {
		g_sTrf7970Status.bProtocolError = false;
		return RF_FRAMING_ERROR;
	}

	// Check if the packet is a broken Frame
	if (bitFrame < 8) {
		broken_frame_bits = bitFrame;
	}

  	if((g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeA == 1) &&
  			sendlen == 0x06 && sendbuf[0] == 0xA2)
  	{
  		mifare_ultra_light_flag = true;
  		// Register 01h. Chip Status Control
  		TRF797x_writeSingle(0x88, TRF79X0_ISO_CONTROL_REG);

  		TRF797x_writeSingle(0x04, TRF79X0_SPECIAL_FUNC_1_REG);
  	}
  	else
  	{
  		mifare_ultra_light_flag = false;
  	}

	if ((g_sTrf7970Status.sInitiatorMode.bits.bPassive15693 == 1)
			&& (sendbuf[0] & BIT6)) {
		iso15693_flag = true;
	}

	byte ret = TRF797x_writeFIFO(sendbuf,
			(tTRF797x_CRC) (
					bitFrame ?
							TRF79X0_TRANSMIT_NO_CRC_CMD | 0x80 :
							TRF79X0_TRANSMIT_CRC_CMD | 0x80), sendlen,
			broken_frame_bits);
	if (reclen == 0) {
		if (ret == OK)
			ret_value = OK;
		else
			ret_value = RF_FRAMING_ERROR;
	} else {
		if (iso15693_flag == true) {
			waitms(15);
			TRF797x_directCommand(TRF79X0_TRANSMIT_NEXT_SLOT_CMD);
		}

		sIrqStatusFlag = TRF797x_irqHandler(_PICCTimeout);

		if (sIrqStatusFlag == IRQ_STATUS_RX_COMPLETE) {
			// Read the mailbox
			reclen = mailbox.used();
			mailbox.Read(recbuf, reclen);
			ret_value = OK;
		} else if (sIrqStatusFlag == IRQ_STATUS_PROTOCOL_ERROR) {
			reclen = 0;
			ret_value = RF_FRAMING_ERROR;
		} else {
			reclen = 0;
			ret_value = NO_ANSWER_FROM_TAG;
		}

  		if(mifare_ultra_light_flag == true)
  		{
  			TRF797x_writeSingle(0x00, TRF79X0_SPECIAL_FUNC_1_REG);
  			// Register 01h. Chip Status Control
  			TRF797x_writeSingle(0x08, TRF79X0_ISO_CONTROL_REG);
  		}
  	}

	return ret_value;
}

void RFID::HFField(char state) {

	if (state == 0) {
		TRF797x_setField(EXT_FIELD_OFF);
	} else {
		TRF797x_setField(EXT_FIELD_ON);
	}
}

void RFID::FieldReset(word msec) {
	HFField(0);
	waitms(msec);
	HFField(1);
}

word RFID::FrameType(byte option, byte param) {
	//FlushFIFO();
	//mailbox.flush();

	//if(current_frame_type == option && current_frame_param == param)    //for timing-optimisation. ToDo: start AAC() always if frame_type remains unchanged (NFC)
	//  return OK;                                                        //ToDo: NO_TAG_MODE has same value as LISTEN_ABF_PASSIVE

	current_frame_type = option;
	current_frame_param = param;

	switch (option) {
	case ISO14443A_BITFRAME:
		SetupFrame(ISO14443A_BYTEFRAME);
		Setup14443A_Bitframe(param);
		break;

	case ISO14443A_BYTEFRAME:
		SetupFrame(ISO14443A_BYTEFRAME);
		Setup14443A_Byteframe();
		break;

	case ISO14443B_BYTEFRAME:
		SetupFrame(ISO14443B_BYTEFRAME);
		break;

	case NFC_TARGET_PASSIVE:
		SetupFrame(param);
		break;

	case FELICA_BYTEFRAME:
		SetupFrame(FELICA_BYTEFRAME);
		break;
	case ISO15693_BYTEFRAME:
		SetupFrame(ISO15693_BYTEFRAME);
		break;
	case NO_TAG_MODE:
		SetupFrame(NO_TAG_MODE);
		break;

		//   case GTML_BYTEFRAME:
		//       SetupFrame(GTML_BYTEFRAME);
		//       break;
		//
		//   case NFC_INITIATOR_ACTIVE:
		//       SetupFrame(NFC_INITIATOR_ACTIVE);
		//       break;
		//
		//   case NFC_TARGET_ACTIVE:
		//       SetupFrame(NFC_TARGET_ACTIVE);
		//       break;
		//
		//	case LISTEN_A_PASSIVE:
		//		SetupFrame(LISTEN_A_PASSIVE);
		//		break;
		//	case LISTEN_B_PASSIVE:
		//		SetupFrame(LISTEN_B_PASSIVE);
		//		break;
		//	case LISTEN_F_PASSIVE:
		//		SetupFrame(LISTEN_F_PASSIVE);
		//		break;

	default:
		//DebugPrint::Write("\nunknown FrameType %04x in RFID\n", option);
		return WRONG_PARAMETER;
	}

	TRF797x_displayMode();

	return OK;
}

/**
 *<b>Setup 14443A-Bitframe</b>
 *<p>
 * Bitframe is used for REQA and Anticollision. THis function sets up the TRF7970A to receive broken byte packets.
 *</p>
 *@param bitcount contains the total number of bits to send in a bitframe
 */
void RFID::Setup14443A_Bitframe(byte bitcount) {

	bitFrame = bitcount;
	TRF797x_writeSingle(0x88, TRF79X0_ISO_CONTROL_REG);
}

void RFID::Setup14443A_Byteframe() {

	bitFrame = 0x00;
}

/**
 *<b>RFID Control</b>
 *<p>
 * Todo: add description
 *</p>
 *@param sendbuf
 *@param sendlen
 *@param recbuf
 *@param reclen
 *@return
 */

unsigned short RFID::baudrate_air(unsigned char baudrate) {

	word ret;
	t_sTRF797x_Bitrate eBaudRate;

	switch (baudrate) {
	case BAUDRATE_106:
		eBaudRate.bits.b106kpbs = 1;
		break;
	case BAUDRATE_212:
		eBaudRate.bits.b212kpbs = 1;
		// Change selectedFrameType when increasing the bitrate for P2P mode
		if (g_sTrf7970Status.bNfcModeEnabled == true)
			selectedFrameType = FELICA_BYTEFRAME;
		break;
	case BAUDRATE_424:
		eBaudRate.bits.b424kpbs = 1;
		// Change selectedFrameType when increasing the bitrate for P2P mode
		if (g_sTrf7970Status.bNfcModeEnabled == true)
			selectedFrameType = FELICA_BYTEFRAME;
		break;
	case BAUDRATE_848:
		eBaudRate.bits.b848kpbs = 1;
		break;
	}

	selectedBaudrate = baudrate;

	if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {
		TRF797x_incrementTargetBaudRate(eBaudRate);
		ret = OK;
	} else if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE) {
		TRF797x_incrementInitiatorBaudRate(eBaudRate);
		ret = OK;
	} else {
		ret = GENERAL_ERROR;
	}

	return ret;

}

/**
 *<b>Read Mailbox</b>
 *<p>
 * Before checking the mailbox run once rfid::run when using NFC-TargetMode resp. transceive when using Initiator-mode. If data is
 * available it will be written into recbuf.
 *</p>
 *@see API.h
 *@param recbuf will contains the received data from target
 *@param reclen will contain the length of the valid data in recbuf
 *@param recbuf contains the answer from target if received.
 *@param reclen contains the length of valid data in recbuf
 *@return OK on success
 *        MORE_DATA\RF_FRAMING_ERR_MORE_DATA if isRxMultiple is true and more frames are available
 *        RF_FRAMING_ERROR on CRC, Parity error, etc.
 */word RFID::readMailbox(byte *recbuf, word &reclen) {
	word len;

	if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {

		if (g_sTrf7970Status.bProtocolError) {
			reclen = 0;
			g_sTrf7970Status.bProtocolError = false;
			return RF_FRAMING_ERROR;
		}
		if (g_sTrf7970Status.bRfFieldOn == false) {
			reclen = 0;
			g_sTrf7970Status.bRfFieldOn = true;
			g_sTrf7970Status.bProtocolError = false;
			return RF_FRAMING_ERROR;
		}

		len = mailbox.used(); //get how many bytes are in the mailbox buffer
		if (len == 0) {
			reclen = 0;
			return NO_ANSWER_FROM_TAG;
		}
		if (len > reclen) { //more data in buffer than expected. Reclen too short!
			mailbox.flush();
			reclen = 0;
			return DATA_OVERFLOW;
		}

		//len-=2;
		reclen = 0;
		reclen = mailbox.Read(recbuf, len);
		mailbox.flush();
		return OK;
	} else
		return GENERAL_ERROR;

}

word RFID::control(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	word ui16Command;

	ui16Command = sendbuf[0];

	switch (ui16Command)
	{
	case PCD_GUARD_TIME:
	case PICC_TIMEOUT:
	case TRANSMISSIONTIMEOUT:
	case RECEIVE_TIMEOUT:
	{
		reclen = 0;
		return setTimeouts(sendbuf, sendlen);
	}
	case REG_READ:
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		if (reclen != 1) {
			reclen = 0;
			return DATA_OVERFLOW;
		}
		TRF797x_readSingle(recbuf, sendbuf[1]);
		reclen = 1;
		return OK;
	}
	case REG_WRITE:
	{
		if (sendlen != 3) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		TRF797x_writeSingle(sendbuf[2], sendbuf[1]); //value, adr
		reclen = 0;
		return OK;
	}
	case FIELD_RESET:
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		FieldReset(sendbuf[1]); //msec
		reclen = 0;
		return OK;
	}
	case RCRESET:
	{
		if (sendlen != 1) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		//CHECK(HW::Call(HW_RC_RESET));
		reclen = 0;
		return OK;
	}
	case HF_FIELD:
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		if (sendbuf[1] & 0xFE) {
			reclen = 0;
			return WRONG_PARAMETER;
		} //must be 0x00 or 0x01
		HFField(sendbuf[1]); //state
		reclen = 0;
		return OK;
	}
	case MODINDEX:
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		//ModIndex_value = sendbuf[1];
		//RFID::Write(ModGsPReg, ModIndex_value);
		reclen = 0;
		return OK;
	}
	case MF_AUTHBIT_CLEAN: //clean the bit which turns the crypto-unit on
	{
		if (sendlen != 1) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		//ClearBits(Status2Reg, 0x08); //Write(Status2Reg,0x00);
		reclen = 0;
		return OK;
	}
	case POSSIBLE_BAUDRATE_AIR:
	{
		if (sendlen != 1) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		if (reclen < 1) {
			reclen = 0;
			return DATA_OVERFLOW;
		}
		recbuf[0] = BAUDRATE_848;
		reclen = 1;
		return OK;
	}
	case BAUDRATE_AIR: //change the airinterface speed
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		reclen = 0;
		return baudrate_air(sendbuf[1]);
		//return 0;
	}
	case CHECK_RF: //check the external RFFieldl
	{
		if (sendlen != 1) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		if (reclen < 1) {
			reclen = 0;
			return DATA_OVERFLOW;
		}
		recbuf[0] = g_sTrf7970Status.bRfFieldOn;
		reclen = 1;
		return OK;
	}
	case SET_RECEIVING: //put the PN512 into receive mode ->nfc mode
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		if (sendbuf[1] == 0x00) {
			//RFID::Write(CommandReg, PCD_IDLE);
		} //put the pn512 in the idle mode
		if (sendbuf[1] == 0x01) {
			//RFID::Write(CommandReg, PCD_RECEIVE);
		} //put the pn512 in the receive mode
		reclen = 0;
		return OK;
	}
	case TARGET_AC_TEST:
	{
		if (sendlen != 1 && sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		TRF797x_setTargetSelect(false);
//		NFCTarget_init_light();
		reclen = 0;
		return OK;
	}
	case POWER_SAVE:
	{
		if (sendlen != 1 && sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		//RFID::HFField(0);
		//RFID::Write(CommandReg, 0x30);
		reclen = 0;
		return OK;
	}
	case RX_GAIN:
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		//RFID::Write(RFCfgReg, (sendbuf[1] & 0x7f));
		//rcf_sensitivity = (sendbuf[1] & 0x7f);
		reclen = 0;
		return OK;
	}
	case CRC_ENABLE:
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		if (sendbuf[1] & 0xFE) {
			reclen = 0;
			return WRONG_PARAMETER;
		}
		//byte ret = RFID::Read(RxModeReg);
		if (sendbuf[1]) {
			bitFrame = false;
		} else {
			bitFrame = true;
		}
		reclen = 0;
		return OK;
	}
	case THRESHOLD:
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		//Treshold = sendbuf[1];
		//RFID::Write(RxTresholdReg, sendbuf[1]);
		reclen = 0;
		return OK;
	}
	case BITCOLLISION:
	{
		if (sendlen != 1) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		if (reclen < 1) {
			reclen = 0;
			return DATA_OVERFLOW;
		}
		recbuf[0] = BitCollision();
		reclen = 1;
		return OK;
	}
	case GET_RANDOM_ID:
	{
		if (reclen < 10) {
			reclen = 0;
			return DATA_OVERFLOW;
		}
		uint8_t len = 0;
		//FlushFIFO();
		//RFID::Write(CommandReg, PCD_GenRandomID); //genarate a random ID
		//waitus(500);
		//SetBits(ControlReg, 0x20); //copy random ID into FIFO
		//while (Read(FIFOLevelReg) && (reclen > len)) {
		//	recbuf[len++] = Read(FIFODataReg);
		//}
		while (len < reclen) {
			recbuf[len] = len;
			len++;
		}

		reclen = len;
		return OK;
	}
	case AAC_CONFIGURATION:
	{
		return aacConfiguration(sendbuf, sendlen, recbuf, reclen);
	}
	case CHECK_PON:
	{
		//return checkPON(recbuf, reclen);
		return 0;
	}
	case TARGET_ACTIVATED:
	{
		return checkTargetActivated(recbuf, reclen);
	}
	case RX_MULTIPLE:
	{
		if (sendlen != 2) {
			reclen = 0;
			return WRONG_LENGTH;
		}
		if (sendbuf[1] == 0x01) {
			//SetBits(RxModeReg, 0x04);
			isRxMultiple = true;
		} else if (sendbuf[1] == 0x00) {
			//ClearBits(RxModeReg, 0x04);
			isRxMultiple = false;
		} else {
			reclen = 0;
			return WRONG_PARAMETER;
		}
		if (reclen >= 1) {
			//recbuf[0] = (isRxMultiple ? 0x01 : 0x00);
			reclen = 1;
		}
		return OK;
	}
	case BAUDRATE_AIR_V:
	{
		word ret = OK;
		t_sTRF797x_Bitrate eBaudRate;

		if(sendbuf[1] == TX)
		{
			switch(sendbuf[2])
			{
			case BAUDRATE_1_66:
				eBaudRate.bits.b6_62_kbps_1_out_4 = 1;
				break;
			case BAUDRATE_26_48:
				eBaudRate.bits.b26_48_kbps_1_out_4 = 1;
				break;
			default:
				ret = GENERAL_ERROR;
				break;
			}

			if(ret == OK)
			{
				TRF797x_incrementInitiatorBaudRate(eBaudRate);
			}

			return ret;
		}
		else if(sendbuf[1] == RX)
		{
			switch(sendbuf[2])
			{
			case BAUDRATE_6_62:
				eBaudRate.bits.b6_62_kbps_1_out_4 = 1;
				break;
			case BAUDRATE_26_48:
				eBaudRate.bits.b26_48_kbps_1_out_4 = 1;
				break;
			default:
				ret = GENERAL_ERROR;
				break;
			}

			if(ret == OK)
			{
				TRF797x_incrementInitiatorBaudRate(eBaudRate);
			}

			return ret;
		}
		else
		{
			return GENERAL_ERROR;
		}
//	case AAC_DE_INIT:
//		// TOODO
//		break;
	}
	default:
		reclen = 0;
		return UNKNOWN_COMMAND;
	}
}

unsigned short RFID::modeDetection(byte* recbuf, word & reclen) {

	recbuf[0] = selectedFrameType;
	recbuf[1] = selectedBaudrate;
	reclen = 2;
	return OK;
}

/**
 *<b>Check Target Activated</b>
 *<p>
 Will return '1' if the Select command or if the Polling command was answered.
 *</p>
 *@param recbuf contains the indicating byte. 0x01 -> got selected, 0x00-> not
 *@param reclen has to be at minimum 1 and will return 1 byte.
 *@return <b>ZERO</b> if no error occured. Else a error code according to API.h will be returned.
 */
unsigned short RFID::checkTargetActivated(unsigned char* recbuf,
		unsigned short & reclen) {

	if (reclen < 1) {
		reclen = 0;
		return DATA_OVERFLOW;
	}

	if (g_sTrf7970Status.bTargetSelected == true) {
		recbuf[0] = 0x01;
		//DebugPrint::Write("\nTargetActivated");
	} else {
		recbuf[0] = 0x00;
		//DebugPrint::Write("\nnoTargetActivated");
	}

	reclen = 1;
	return OK;

}

/**
 * <b>AAC configuration</b>
 * <p>
 * This method dispatches the incomming data to several functions to configure the AAC().
 * </p>
 * @param sendbuf contains the from host received data. sendbuf[0]=sub-opcode 'AAC_CONFIGURATION' + sendbuf[1]=sub-sub-opcode 'SENS_RES' (for example) + sendbuf[i] = data
 * @param sendlen contains the length of received data
 * @param recbuf contains the data returned to host. At SENS_RES for example: 0x44, 0x00
 * @param reclen contains the length of data returned to host. At SENS_RES it will be 2.
 * @return <b>ZERO</b> if no error occured. Else a error code according to API.h will be returned.
 */word RFID::aacConfiguration(byte *sendbuf, word sendlen, byte *recbuf,
		word &reclen) {
	/* sendbuf+2/sendlen-2 to cut off the opcodes */
	switch (sendbuf[1]) {
	case SENS_RES: //r/w
		return sgSensRes(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case NFCID1: //r/w
		return sgNfcid1(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case SEL_RES: //r/w
		return sgSelRes(sendbuf + 2, sendlen - 2, recbuf, reclen);

		//	case NFCID2: //r/w
		//		return sgNfcid2(sendbuf + 2, sendlen - 2, recbuf, reclen);
		//
		//	case SYS_CODE: //r/w
		//		return sgSysCode(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case AAC_PADDING: //r/w    // Felica PMM
		return sgPadding(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case PUPI_REG: //-/w
		return setPupi(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case AAC_ATQB: //r/w
		return sgAtqb(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case AAC_AFI: //r/w
		return sgAfi(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case LF_T3T_MAX: //-/w
		return getLfT3tMax(sendlen - 2, recbuf, reclen);

	case LF_T3T_FLAGS: //r/w
		return sgLfT3tFlags(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case LF_T3T_IDENTIFIERS_1:
	case LF_T3T_IDENTIFIERS_2:
	case LF_T3T_IDENTIFIERS_3:
	case LF_T3T_IDENTIFIERS_4:
	case LF_T3T_IDENTIFIERS_5:
	case LF_T3T_IDENTIFIERS_6:
	case LF_T3T_IDENTIFIERS_7:
	case LF_T3T_IDENTIFIERS_8:
	case LF_T3T_IDENTIFIERS_9:

	case LF_T3T_IDENTIFIERS_10:
	case LF_T3T_IDENTIFIERS_11:
	case LF_T3T_IDENTIFIERS_12:
	case LF_T3T_IDENTIFIERS_13:
	case LF_T3T_IDENTIFIERS_14:
	case LF_T3T_IDENTIFIERS_15:
	case LF_T3T_IDENTIFIERS_16:
		return sgLfT3tIdentifier(sendbuf + 1, sendlen - 1, recbuf, reclen);

	case LF_PROTOCOL_TYPE:
		return sgLfProtocolType(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case LF_ADV_FEAT:
		return sgLfAdvFeat(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case LF_CON_BITR_F:
		return sgLfConBitrF(sendbuf + 2, sendlen - 2, recbuf, reclen);

	case LN_NFC_DEP:
		return sgLnNfcDep(sendbuf + 2, sendlen - 2, recbuf, reclen);

	default:
		reclen = 0;
		return UNKNOWN_COMMAND;
	}
}

/**
 * <b> Set Get LN_NFC_DEP </b>
 * <p>
 * Todo: add description
 * </p>
 * @see Hardware Abstraction Layer 1.34 4.4.18.4 LN_NFC_DEP
 * @param sendbuf
 * @param sendlen
 * @param recbuf
 * @param reclen
 * @return
 */word RFID::sgLnNfcDep(byte *sendbuf, word sendlen, byte *recbuf,
		word &reclen) {
	/* not implemented yet, is supposed to be like an T3T Identifier for the DH */
	if (sendlen == 10) {
		memcpy(nfcid2.data, sendbuf + 2, 8);
		nfcid2.len = 8;

//		setNfcid2(sendbuf + 2, 8);

		memcpy(AACconfig.sys_code, sendbuf, 2);
		reclen = 0;
		return OK;
	} else if (sendlen == 0 && reclen >= 10) {
		memcpy(recbuf, AACconfig.sys_code, 2);
		memcpy(recbuf + 2, nfcid2.data, 8);
	} else
		return DATA_OVERFLOW;

	return OK;

	//   reclen = 0;
	//   return OK;
}

/**
 * <b>Set Get LF_CON_BITR_F </b>
 * <p>
 * Todo: add description
 * </p>
 * @see Hardware Abstraction Layer Specification 1.34 4.4.18.13 LF_CON_BITR_F
 * @see NFCForum-TS-NCI-1.0 Table 35
 * @param sendbuf
 * @param sendlen
 * @param recbuf
 * @param reclen
 * @return
 */word RFID::sgLfConBitrF(byte *sendbuf, word sendlen, byte *recbuf,
		word &reclen) {
	if (sendlen == 1) {
		AACconfig.lfConBitrF = sendbuf[0];
		reclen = 0;
	} else if (sendlen == 0) {
		if (reclen == 0)
			return DATA_OVERFLOW;
		recbuf[0] = AACconfig.lfConBitrF;
		reclen = 1;
	} else {
		return WRONG_LENGTH;
	}
	return OK;
}

/**
 * <b> Set Get LF_ADV_FEAT </b>
 * <p>
 * Todo: add description
 * </p>
 * @see NFCForum-TS-NCI-1.0 Table 35
 * @param sendbuf
 * @param sendlen
 * @param recbuf
 * @param reclen
 * @return
 */word RFID::sgLfAdvFeat(byte *sendbuf, word sendlen, byte *recbuf,
		word &reclen) {
	if (sendlen == 1) {
		AACconfig.lfAdvFeat = sendbuf[0];
		reclen = 0;
	} else if (sendlen == 0) {
		if (reclen == 0)
			return DATA_OVERFLOW;
		recbuf[0] = AACconfig.lfAdvFeat;
		reclen = 1;
	} else {
		return WRONG_LENGTH;
	}
	return OK;
}

/**
 * <b> Set Get LF_PROTOCOL_TYPE </b>
 * <p>
 * Todo: add description
 * </p>
 * @param sendbuf
 * @param sendlen
 * @param recbuf
 * @param reclen
 * @return
 */word RFID::sgLfProtocolType(byte *sendbuf, word sendlen, byte *recbuf,
		word &reclen) {
	if (sendlen == 1) {
		AACconfig.lfProtocolType = sendbuf[0];
		if (AACconfig.lfProtocolType & 0x02) {
			// TODO Ensure that when P2P mode is enabled this bit is set
			g_sTrf7970Status.bNfcModeEnabled = 1;
			g_bNfcTargetEnable = true;
		} else {
			g_sTrf7970Status.bNfcModeEnabled = 0;
			g_bNfcTargetEnable = false;
		}
		reclen = 0;
		return OK;
	} else if (sendlen == 0) {
		if (reclen < 1)
			return DATA_OVERFLOW;
		recbuf[0] = AACconfig.lfProtocolType;
		reclen = 1;
		return OK;
	}
	return WRONG_LENGTH;
}

/**
 * <b> Set Get LF_T3T_IDENTIFIERS 1-16 </b>
 * <p>
 * Todo: add description
 * </p>
 * @param sendbuf
 * @param sendlen
 * @param recbuf
 * @param reclen
 * @return
 */word RFID::sgLfT3tIdentifier(byte *sendbuf, word sendlen, byte *recbuf,
		word &reclen) {
	//sendbuf[0] is the Identifiers ID (1-16)
	if (sendlen == 11) {
		memcpy(AACconfig.sys_code, sendbuf + 1, 2);
		memcpy(nfcid2.data, sendbuf + 3, 8);
//		setNfcid2(sendbuf + 3, 8);
		return OK;
	} else if (sendlen == 1) {
		if (reclen < 10)
			return DATA_OVERFLOW;
		memcpy(recbuf, AACconfig.sys_code, 2);
		memcpy(recbuf + 2, nfcid2.data, 8);
		return OK;
	} else {
		return WRONG_LENGTH;
	}
	//   return GENERAL_ERROR;
}

/**
 * <b> Set Get LF_T3T_FLAGS </b>
 * <p>
 * Todo: add description
 * </p>
 * @param sendbuf
 * @param sendlen
 * @param recbuf
 * @param sendlen
 * @return
 */word RFID::sgLfT3tFlags(byte *sendbuf, word sendlen, byte *recbuf,
		word &reclen) {
	if (sendlen == 2) {
		AACconfig.lfT3tFlags[0] = sendbuf[0];
		AACconfig.lfT3tFlags[1] = sendbuf[1];
		reclen = 0;
	} else if ((sendlen == 0) && (reclen >= 2)) {
		recbuf[0] = AACconfig.lfT3tFlags[0];
		recbuf[1] = AACconfig.lfT3tFlags[1];
		reclen = 2;
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
	return OK;
}

/**
 * <b> Get LF_T3T_MAX </b>
 * <p>
 * Returns the value of LF_T3T_MAX. Specified at NFCForum-TS-NCI-1.0 6.1.8 Listen F Parameters
 * Table 35.
 * This register is read only and one byte data will be returned. Valid return values are 00h-0Fh.
 * </p>
 * @param sendlen contains the sendlen. SHALL be zero.
 * @param recbuf contains the returned data.
 * @param reclen is the maximum available recbuf size and will be changed to the returned length of data.
 * @return <b>OK</b> if no error occured. Else a error code according to 1.10 Error codes will be returned.
 */word RFID::getLfT3tMax(word sendlen, byte *recbuf, word &reclen) {
	if (sendlen != 0)
		return WRONG_LENGTH;

	if (reclen == 0)
		return DATA_OVERFLOW;

	recbuf[0] = HAL_LF_T3T_MAX;
	reclen = 1;
	return OK;
}

/**
 *<b>Set/Get AFI</b>
 *<p>
 Todo: add description
 *</p>
 *@see ISO/IEC 14443-3 7.9 ATQB Response
 *@param sendbuf
 *@param sendlen
 *@param recbuf
 *@param reclen
 *@return
 */word RFID::sgAfi(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	if (sendlen == 1) {
		AACconfig.afi = sendbuf[0];
//		setAFI(sendbuf[0]);
		reclen = 0;
		return OK;
	} else if (sendlen == 0) {
		if (reclen < 1) {
			reclen = 0;
			return DATA_OVERFLOW;
		}
		reclen = 1;
		recbuf[0] = AACconfig.afi;
		return OK;
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
}

/**
 * <b>Set/Get PUPI</b>
 * <p>
 * Write and read PUPI register. With sendlen of 4 it is possible to write the pupi register. With
 * sendlen of 0 you can read the pupi register. At a read access the reclen has to be at minimum 4.
 * </p>
 * @see ISO/IEC 14443-3 7.9 ATQB Response
 * @param sendbuf contains the data which will be written in pupi register
 * @param sendlen contains the length of sendbuffer. Has to be 0 or 4.
 * @param recbuf contains the data of pupi req.
 * @param reclen contains the length of recbuffer
 * @return <b>ZERO</b> if no error occured. Else a error code according to API.h will be returned.
 */word RFID::setPupi(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	if (sendlen == 4) {
		memcpy(AACconfig.pupi, sendbuf, 4);
//		setPupi_(sendbuf, 4);
		reclen = 0;
		return OK;
	} else if (sendlen == 0) {
		if (reclen < 4) {
			reclen = 0;
			return DATA_OVERFLOW;
		}
		memcpy(recbuf, AACconfig.pupi, 4);
		reclen = 4;
		return OK;
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
}

/**
 * <b>Set/Get ATQB</b>
 * <p>
 * Write and read the ATQB register. A write command has to be 6 or 7 byte long. Depends if extended
 * ATQB or normal is used. The parameters are written in the order:
 * - CRC-AID: 2 byte. Default: '00 00'
 * - NUMBER_APLI: 1 byte. Default: '00'
 * - PROTO_INFO: 3-4 byte. Default: '00 00 E4'
 * With a sendlen of 0 and a reclen greater or equal 7 you can read the current settings of ATQB.
 * </p>
 * @see Kronegger HAL Specification 1.23 4.4.18.10 AAC_ATQB
 * @see ISO/IEC 14443-3 7.9 ATQB Response
 * @param sendbuf
 * @param sendlen
 * @param recbuf
 * @param reclen
 * @return
 */word RFID::sgAtqb(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	if (sendlen == 6 || sendlen == 7) {
		memcpy(AACconfig.crc_aid, sendbuf, 2);
		AACconfig.number_apli = sendbuf[2];
		memcpy(AACconfig.proto_info, sendbuf + 3, sendlen - 3);
//		setCRCAid(sendbuf, 2);
//		setNumberApli(sendbuf[2]);
//		setProtoInfo(sendbuf + 3, sendlen - 3);
		reclen = 0;
		return OK;
	} else if (sendlen == 0) {
		if (reclen < 7) {
			reclen = 0;
			return DATA_OVERFLOW;
		}
		reclen = 7;
		memcpy(recbuf, AACconfig.crc_aid, 2);
		recbuf[2] = AACconfig.number_apli;
		memcpy(recbuf + 3, AACconfig.proto_info, 4);
		return OK;
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
}

/**
 *<b>Set/Get SYS_CODE</b>
 *<p>
 Todo: add description
 *</p>
 *@param sendbuf
 *@param sendlen
 *@param recbuf
 *@param reclen
 *@return
 */word RFID::sgSysCode(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	if (sendlen == 2) { //write
		memcpy(AACconfig.sys_code, sendbuf, 2);
//		setSysCode(sendbuf, 2);
		reclen = 0;
		return OK;
	} else if (sendlen == 0) { //read
		if (reclen >= 2) {
			memcpy(recbuf, AACconfig.sys_code, 2);
			reclen = 2;
			return OK;
		} else {
			reclen = 0;
			return DATA_OVERFLOW;
		}
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
}

/**
 * <b>Set/Get NFCID2</b>
 * <p>
 * Write and read the NFCID2. The NFCID2 is used for passive communication with 212 and 424kbaud.
 * The NFCID2 can be written in two different ways. With a sendlen of 06h the first two bytes of
 * the NFCID2 are fixed to 02h FEh and the six bytes are attached.
 * With a sendlen of 08h also the first two bytes are written.
 * To read the NFCID2 the sendlen has to be 00h and the reclen at minimum 08h.
 * </p>
 * @see ISO/IEC 18092 11.2.2.4 NFCID2 contents
 * @param sendbuf contains the NFCID2 with or without prefix.
 * @param sendlen contains the length of sendbuf. Allowed length: 0, 6 and 8.
 * @param recbuf contains the current setting of the NFCID2
 * @param reclen contains the length of recbuf. At minimum 8.
 * @return <b>ZERO</b> if no error occured. Else a error code according to API.h will be returned.
 */word RFID::sgNfcid2(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	if (sendlen == 6) { //write
		nfcid2.data[0] = 0x02;
		nfcid2.data[1] = 0xFE;
		memcpy(nfcid2.data + 2, sendbuf, sendlen);
		nfcid2.len = 8;
//		setNfcid2(nfcid2.data, 8);
		reclen = 0;
		return OK;
	} else if (sendlen == 8) {
		memcpy(nfcid2.data, sendbuf, sendlen);
		nfcid2.len = 8;
//		setNfcid2(nfcid2.data, 8);
		reclen = 0;
		return OK;
	} else if (sendlen == 0) { //read
		if (reclen >= 8) {
			memcpy(recbuf, nfcid2.data, nfcid2.len);
			reclen = nfcid2.len;
			return OK;
		} else {
			reclen = 0;
			return DATA_OVERFLOW;
		}
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
}

/**
 *<b>Set/Get SEL_RES/SAK</b>
 *<p>
 Todo: add description
 *</p>
 *@param sendbuf
 *@param sendlen
 *@param recbuf
 *@param reclen
 *@return
 */word RFID::sgSelRes(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	if (sendlen == 1) { //write
		AACconfig.sel_res = sendbuf[0];
//		setSelRes(sendbuf[0]);
		reclen = 0;
		return OK;
	} else if (sendlen == 0) { //read
		if (reclen >= 1) {
			recbuf[0] = AACconfig.sel_res;
			reclen = 1;
			return OK;
		} else {
			reclen = 0;
			return DATA_OVERFLOW;
		}
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
}

/**
 * <b>Set/Get NFCID1</b>
 * <p>
 * With this opcode the NFCID1 for Listen Modes can be configured. It is possible to write 3 or 4 bytes
 * NFCID. If you write only 3 bytes the first one of the four byte NFCID is fixed to 0x08 which indicates
 * a random generated UID. If you write 4 bytes, the first byte is overwritten aswell.
 * If the sendlen is zero you can read the current NFCID. For this reclen as to be at minimum 4.
 * </p>
 * @see NFCForum-TS-DigitalProtocol Requirements 17: NFCID1 Length
 * @param sendbuf contains the NFCID1 which will be written. Three or four bytes.
 * @param sendlen contains the length of sendbuffer. Has to be 0, 3 or 4.
 * @param recbuf contains the current NFCID1 settings.
 * @param reclen contains the length of recbuffer and has to be at minimum 4.
 * @return <b>ZERO</b> if no error occured. Else a error code according to API.h will be returned.
 */word RFID::sgNfcid1(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	if (sendlen == 3) {
		nfcid1.data[0] = 0x08;
		memcpy(nfcid1.data + 1, sendbuf, sendlen);
		nfcid1.len = 4;
//		setNfcid1(nfcid1.data, 4);
		//		DebugPrint::Write("\nsetID:");
		//		DebugPrint::Hex(nfcid1.data, 4);
		reclen = 0;
		return OK;
	} else if (sendlen == 4) {
		memcpy(nfcid1.data, sendbuf, sendlen);
		nfcid1.len = 4;
//		setNfcid1(nfcid1.data, 4);
		reclen = 0;
		return OK;
	} else if (sendlen == 0) {
		if (reclen >= nfcid1.len) {
			memcpy(recbuf, nfcid1.data, nfcid1.len);
			reclen = nfcid1.len;
			return OK;
		} else {
			reclen = 0;
			return DATA_OVERFLOW;
		} //reclen to short
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
}

/**
 *<b>Set/Get SENS_RES</b>
 *<p>
 Todo: add description
 *</p>
 *@param sendbuf
 *@param sendlen
 *@param recbuf
 *@param reclen
 *@return
 */word RFID::sgSensRes(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) {
	if (sendlen == 2) { //write
		memcpy(AACconfig.sens_res, sendbuf, 2);
//		setSensRes(sendbuf, 2);
		reclen = 0;
		return OK;
	} else if (sendlen == 0) { //read
		if (reclen >= 2) {
			recbuf[0] = AACconfig.sens_res[0];
			recbuf[1] = AACconfig.sens_res[1];
			reclen = 2;
			return OK;
		} else {
			reclen = 0;
			return DATA_OVERFLOW;
		} //reclen to short
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
}
/**
 *<b>Set/Get Padding</b>
 *<p>
 Todo: add description
 *</p>
 *@see ISO/IEC 14443-3 7.9 ATQB Response
 *@param sendbuf
 *@param sendlen
 *@param recbuf
 *@param reclen
 *@return
 */word RFID::sgPadding(byte *sendbuf, word sendlen, byte *recbuf, word &reclen) //PMM
		{
	if (sendlen == 8) {
		memcpy(AACconfig.Padding, sendbuf, 8);
//		setPadding(sendbuf, 8);
		reclen = 0;
		return OK;
	} else if (sendlen == 0) {
		if (reclen < 8) {
			reclen = 0;
			return DATA_OVERFLOW;
		}
		reclen = 8;
		memcpy(recbuf, AACconfig.Padding, 8);
		return OK;
	} else {
		reclen = 0;
		return WRONG_LENGTH;
	}
}

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------

//*****************************************************************************
//
// This function initializes the TRF97x0 Enable, Slave Select, and SPI module.
//
//*****************************************************************************
void TRF797x_setup(void) {
	RFSPI::init();

	waitms(5);

	// Initialize Radio GPIOs
	TRF_DISABLE()
	;
	TRF_ENABLESET()
	;
	TRF_ENABLE()
	;

	//
	// Enable an interrupt Low to High transition for the IRQ pin on the TRF7970A
	//
	IRQ_PIN_SET()
	;
	IRQ_INT_ON()
	;
	IRQ_EDGE_SET()
	;
	IRQ_CLR()
	;

	TRF797x_idleMode();
}

//===============================================================
// NAME: void Trf796xDirectCommand (uint8_t *pui8Value)
//
// BRIEF: Is used to transmit a Direct Command to TRF796x.
//
// INPUTS:
//    Parameters:
//        uint8_t        *pui8Value        Direct Command
//
// OUTPUTS:
//
// PROCESS:    [1] transmit Direct Command
//
// CHANGE:
// DATE          WHO    DETAIL
// 24Nov2010    RP    Original Code
//===============================================================

void TRF797x_directCommand(uint8_t ui8Command) {
	uint8_t ui8TxBuff[2];

	if (SPIMODE) // SPI mode given by jumper setting
	{
		if (ui8Command == TRF79X0_RESET_FIFO_CMD) {
			//
			// Reset FIFO CMD + Dummy byte
			//
			ui8TxBuff[0] = TRF79X0_RESET_FIFO_CMD | BIT7;
			ui8TxBuff[1] = 0x00;
			RFSPI::rawWrite(ui8TxBuff, 2);
		} else {
			ui8TxBuff[0] = ui8Command | BIT7;
			RFSPI::rawWrite(ui8TxBuff, 1);
		}
	}

}

//===============================================================
// NAME: void TRF797xRawWrite (uint8_t *pui8Value, uint8_t length)
//
// BRIEF: Is used to write direct to the TRF797x.
//
// INPUTS:
//	Parameters:
//		uint8_t		*pui8Value		raw data
//		uint8_t		length		number of data bytes
//
// OUTPUTS:
//
// PROCESS:	[1] send raw data to TRF797x
//
// CHANGE:
// DATE  		WHO	DETAIL
// 24Nov2010	RP	Original Code
//===============================================================
void TRF797x_rawWrite(uint8_t *pui8Payload, uint8_t ui8Length) {
	if (SPIMODE) // SPI mode given by jumper setting
	{
		RFSPI::rawWrite(pui8Payload, ui8Length);
	} else // parallel mode
	{
//		ParallelRawWrite(pui8Value, length);
	}
}

//===============================================================
// NAME: void TRF797xReadSingle (uint8_t *pui8Value, uint8_t number)
//
// BRIEF: Is used to read specified TRF797x registers.
//
// INPUTS:
//	Parameters:
//		uint8_t		*pui8Value		addresses of the registers
//		uint8_t		number		number of the registers
//
// OUTPUTS:
//
// PROCESS:	[1] read registers
//			[2] write contents to *pui8Value
//
// CHANGE:
// DATE  		WHO	DETAIL
// 24Nov2010	RP	Original Code
//===============================================================

void TRF797x_readSingle(uint8_t *pui8Value, uint8_t ui8Register) {
	if (SPIMODE) // SPI mode given by jumper setting
	{
		RFSPI::read(ui8Register, pui8Value);
	} else // parallel mode
	{
//		ParallelReadSingle(pui8Value, number);
	}
}

//===============================================================
// NAME: void TRF797xReadCont (uint8_t *pui8Value, uint8_t length)
//
// BRIEF: Is used to read a specified number of TRF797x registers
// from a specified address upwards.
//
// INPUTS:
//	Parameters:
//		uint8_t		*pui8Value		address of first register
//		uint8_t		length		number of registers
//
// OUTPUTS:
//
// PROCESS:	[1] read registers
//			[2] write contents to *pui8Value
//
// CHANGE:
// DATE  		WHO	DETAIL
// 24Nov2010	RP	Original Code
//===============================================================

void TRF797x_readCont(uint8_t *pui8Value, uint8_t ui8Register,
		uint8_t ui8Length) {
	if (SPIMODE) // SPI mode given by jumper setting
	{
		RFSPI::readCont(ui8Register, pui8Value, ui8Length);
	} else // parallel mode
	{
//		ParallelReadCont(pui8Value, length);
	}
}

//===============================================================
// NAME: void TRF797xWriteSingle (uint8_t ui8Value, uint8_t ui8Length)
//
// BRIEF: Is used to write to specified reader chip registers.
//
// INPUTS:
//	uint8_t	*pui8Value	addresses of the registers followed by the
//					contents to write
//	uint8_t	length	number of registers * 2
//
// OUTPUTS:
//
// PROCESS:	[1] write to the registers
//
// CHANGE:
// DATE  		WHO	DETAIL
// 24Nov2010	RP	Original Code
//===============================================================

void TRF797x_writeSingle(uint8_t ui8Value, uint8_t ui8Register) {
	if (SPIMODE) // SPI mode given by jumper setting
	{
		RFSPI::write(ui8Register, &ui8Value);
	} else // parallel mode
	{
//		ParallelWriteSingle(pui8Value, length);
	}
}

//===============================================================
// NAME: void SpiWriteCont (uint8_t *pui8Value, uint8_t ui8Length)
//
// BRIEF: Is used to write to a specific number of reader chip
// registers from a specific address upwards.
//
// INPUTS:
//	uint8_t	*pui8Value	address of first register followed by the
//					contents to write
//	uint8_t	length	number of registers + 1
//
// OUTPUTS:
//
// PROCESS:	[1] write to the registers
//
// CHANGE:
// DATE  		WHO	DETAIL
//===============================================================

void TRF797x_writeCont(uint8_t *pui8Value, uint8_t ui8Register,
		uint8_t ui8Length) {
	if (SPIMODE) // SPI mode given by jumper setting
	{
		RFSPI::writeCont(ui8Register, pui8Value, ui8Length);
	} else // parallel mode
	{
//		ParallelWriteCont(pui8Value, length);
	}
}

void TRF797x_resetFIFO(void) {
	TRF797x_directCommand(TRF79X0_RESET_FIFO_CMD);
}

void TRF797x_displayMode(void) {
	if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE) {
		GPIO::setRWMode(true);
		GPIO::setP2PTargetMode(false);
		GPIO::setCEMode(false);
	} else if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {
		// Check if NFC mode is enabled
		if (g_bNfcTargetEnable == true)
//		if(g_sTrf7970Status.bNfcModeEnabled == 1)
				{
			GPIO::setRWMode(false);
			GPIO::setP2PTargetMode(true);
			GPIO::setCEMode(false);
		}
		// If is not NFC mode then it means is in Card Emulation
		else {
			GPIO::setRWMode(false);
			GPIO::setP2PTargetMode(false);
			GPIO::setCEMode(true);
		}
	} else {
		GPIO::setRWMode(false);
		GPIO::setP2PTargetMode(false);
		GPIO::setCEMode(false);
	}
}

/*
 * Reset TRF79x0 in current mode. (Needed for Target Mode to start polling for
 * supported modes and frequencies.)
 */
uint8_t TRF797x_resetMode(void) {
	if (g_sTrf7970Status.eCurrentMode == TRF_IDLE_MODE) {
		TRF797x_idleMode();
	} else if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE) {
		TRF797x_initiatorModeSetup(g_sTrf7970Status.sInitiatorMode,
				g_sTrf7970Status.sInitiatorPayloadFrequency);
	} else if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {
		TRF797x_targetModeSetup(g_sTargetSupportedTechnologies,
				g_sTargetSupportedBitrates);
	} else
		return STATUS_FAIL_T;

	return OK;
}

uint8_t * TRF797x_getNfcBuffer(void) {
	return g_ui8FifoBuffer;
}

tTRF797x_Status TRF797x_getStatus(void) {
	return g_sTrf7970Status;
}

void TRF797x_setAutoSdd(uint8_t * pui8TargetId, uint8_t ui8IdLength,
		bool bNfcDep, bool bIsoDep) {
	uint8_t ui8Temp;

	// UID Length Must be 4,7,or 10
	if (ui8IdLength == 0x04 || ui8IdLength == 0x07 || ui8IdLength == 0x0A) {
		// Check if is different than current DEP support
		if (g_bNfcDepSupport != bNfcDep || g_bIsoDepSuport != bIsoDep
				|| g_ui8IdLength != ui8IdLength) {
			g_ui8IdLength = ui8IdLength;
			// Copy the UID
			for (ui8Temp = 0; ui8Temp < ui8IdLength; ui8Temp++) {
				g_ui8TargetId[ui8Temp] = pui8TargetId[ui8Temp];
			}
			g_bNfcDepSupport = bNfcDep;
			g_bIsoDepSuport = bIsoDep;

			TRF797x_initAutoSdd();
		}
	}
}

void TRF797x_initAutoSdd(void) {
	if (g_ui8IdLength > 0) {
		if (g_bIsoDepSuport == true)
			// Indicate Layer 4 Compliance
			TRF797x_writeSingle(0x01, TRF79X0_ISO14443B_OPTIONS_REG);
		if (g_bNfcDepSupport == true)
			// Not supported

			if (g_ui8IdLength == 0x04) {
				// Auto SDD - Single UID
				TRF797x_writeSingle(0x27, TRF79X0_NFC_TARGET_LEVEL_REG);
				TRF797x_writeCont(g_ui8TargetId, TRF79X0_NFC_ID_REG, 0x04);
			} else if (g_ui8IdLength == 0x07) {
				// Auto SDD - Double UID
				TRF797x_writeSingle(0x67, TRF79X0_NFC_TARGET_LEVEL_REG);
				TRF797x_writeCont(g_ui8TargetId, TRF79X0_NFC_ID_REG, 0x07);
			} else if (g_ui8IdLength == 0x0A) {
				// Auto SDD - Tripple UID
				TRF797x_writeSingle(0xA7, TRF79X0_NFC_TARGET_LEVEL_REG);
				TRF797x_writeCont(g_ui8TargetId, TRF79X0_NFC_ID_REG, 0x0A);
			}
	}
}

void TRF797x_disableAutoSdd(void) {
	g_bIsoDepSuport = false;
	g_bIsoDepSuport = false;
	g_ui8IdLength = 0;
}

void TRF797x_setTargetSelect(bool bTargetStatus) {

	if (bTargetStatus == true) {
		P4DIR |= BIT6;
		P4OUT |= BIT6;
	} else {
		P4DIR |= BIT6;
		P4OUT &= ~BIT6;
	}

	g_sTrf7970Status.bTargetSelected = bTargetStatus;
}

void TRF797x_setNfcMode(bool bNfcMode) {
	g_sTrf7970Status.bNfcModeEnabled = bNfcMode;
}

/*
 * Writes payload to the FIFO register.
 */
uint8_t TRF797x_writeFIFO(uint8_t *pui8Payload, tTRF797x_CRC eCRCBit,
		uint8_t ui8Length, uint8_t ui8BrokenBits) {
	uint8_t ui8Status = STATUS_SUCCESS_T;
	tTRF797x_IRQFlag sIrqStatusFlag = IRQ_STATUS_IDLE;
	uint8_t ui8RemainingBytes = 0;
	uint8_t ui8FiFoStatusLength = 0;
	uint8_t ui8PayloadLength = 0;
	uint8_t ui8TimeOutCounter = 0;
	uint8_t ui8IrqBuffer[2];

	// Ensure the IRQ line is low before sending out a packet
//	TRF797x_irqHandler(0);
	if (IRQ_IS_SET())
	{
		TRF797x_readSingle(ui8IrqBuffer, TRF79X0_IRQ_STATUS_REG);
	}

	if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {
		// Enable the field for active communication
		if (g_sTrf7970Status.sTargetMode.bits.bActiveTypeA == 1
				|| g_sTrf7970Status.sTargetMode.bits.bActiveTypeF == 1) {
			waitus(200);
		}
	} else if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE) {
		// Enable the field for active communication
		if (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA == 1
				|| g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF == 1) {
			TRF797x_switchInitiatorBaudRate(
					g_sTrf7970Status.sInitiatorPayloadFrequency, true);
			waitus(200);
		}
	}

	if (ui8Status != STATUS_FAIL_T) {
		// Check if the Total Packet Length is greater than 127, if so we have to fragment
		// the packet with the first fragment including 127 bytes.
		if (ui8Length > 127) {
			ui8PayloadLength = 127;
		} else {
			ui8PayloadLength = ui8Length;
		}

		// Calculate remaining bytes to be sent.
		ui8RemainingBytes = ui8Length - ui8PayloadLength;

		// Send 1st Fragment of the packet.
		RFSPI::writePacket(pui8Payload, (uint8_t) eCRCBit, ui8Length,
				ui8PayloadLength, true, ui8BrokenBits);

		// Wait until TX is complete
		while (sIrqStatusFlag != IRQ_STATUS_TX_COMPLETE) {
			if (RFID::callback()) {
				return STATUS_FAIL_T;
			}

			// Workaround for Type A commands - check the IRQ within 7 mS to refill FIFO
			if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE
					&& (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeA == 1)
					&& ui8Length > 127) {
				sIrqStatusFlag = TRF797x_irqHandler(7);
				ui8TimeOutCounter = ui8TimeOutCounter + 7;
			}
			// Workaround for Type F commands - check the IRQ within 1 mS to refill FIFO
			else if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE
					&& (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF == 1
							|| g_sTrf7970Status.sTargetMode.bits.bActiveTypeF
									== 1) && ui8Length > 127) {
				sIrqStatusFlag = TRF797x_irqHandler(5);
				ui8TimeOutCounter = ui8TimeOutCounter + 5;
			} else {
				sIrqStatusFlag = TRF797x_irqHandler(1);
				ui8TimeOutCounter++;
			}

			// Check if there was a Protocol_Error or if 40 mSec ( 128 bytes @ 26kb worst case scenario)
			if (sIrqStatusFlag == IRQ_STATUS_PROTOCOL_ERROR
					|| sIrqStatusFlag == IRQ_STATUS_NO_RESPONSE
					|| ui8TimeOutCounter > 40) {
				ui8Status = STATUS_FAIL_T;
				break;
			} else if (sIrqStatusFlag == IRQ_STATUS_TX_COMPLETE) {
				ui8Status = OK;
			} else if ((sIrqStatusFlag == IRQ_STATUS_FIFO_HIGH_OR_LOW
					|| sIrqStatusFlag == IRQ_STATUS_TIME_OUT)
					&& ui8RemainingBytes > 0) {
				ui8TimeOutCounter = 0;
				// Modify the pointer to point to the next address of data for payload larger than 127 bytes
				pui8Payload = pui8Payload + ui8PayloadLength;

				// Check how many bytes are inside the FIFO.
				TRF797x_readSingle(&ui8FiFoStatusLength,
						TRF79X0_FIFO_STATUS_REG);

				// Check if there are more remaining bytes than available spots on the TRF7970
				if (ui8RemainingBytes > (127 - ui8FiFoStatusLength)) {
					// If there are more bytes than available then payload length is the (127 - ui8FiFoStatusLength)
					ui8PayloadLength = (127 - ui8FiFoStatusLength);
				} else {
					ui8PayloadLength = ui8RemainingBytes;
				}

				// Update Remaining Bytes.
				ui8RemainingBytes = ui8RemainingBytes - ui8PayloadLength;

				RFSPI::writePacket(pui8Payload, (uint8_t) eCRCBit, ui8Length,
						ui8PayloadLength, false, 0x00);
			}
		}

		// Target Active Communication Handling.
		if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE
				&& g_sTrf7970Status.sTargetMode.ui8byte != 0x00) {
			// Disable the field for active communication
			if (g_sTrf7970Status.sTargetMode.bits.bActiveTypeA == 1) {
				// Handle the RF Field turned on while exiting the send cmd.
				TRF797x_irqHandler(0);

				waitus(1);

				// Setup for passive target mode.
				TRF797x_writeSingle(0x21, TRF79X0_ISO_CONTROL_REG);
			} else if (g_sTrf7970Status.sTargetMode.bits.bActiveTypeF == 1) {
				// Handle the RF Field turned on while exiting the send cmd.
				TRF797x_irqHandler(0);

				waitus(1);

				// Setup for passive target mode.
				TRF797x_writeSingle(0x21, TRF79X0_ISO_CONTROL_REG);
			}

		}
		// Initiator Active Communication Handling.
		else if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE) {
			// Enable the field for active communication
			if (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA == 1) {
				// Handle the RF Field turned on while exiting the send cmd.
				TRF797x_irqHandler(0);

				waitus(1);

				// Setup for passive target mode.
				TRF797x_writeSingle(0x21, TRF79X0_ISO_CONTROL_REG);
			} else if (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF == 1) {
				// Handle the RF Field turned on while exiting the send cmd.
				TRF797x_irqHandler(0);

				waitus(100);

				// Setup for passive target mode.
				TRF797x_writeSingle(0x21, TRF79X0_ISO_CONTROL_REG);
			}
		}
	}

	return ui8Status;
}

/*
 * IRQ Handler.
 */
tTRF797x_IRQFlag TRF797x_irqHandler(uint16_t ui16TimeOut) {
	tTRF797x_IRQFlag eIrqStatusFlag = IRQ_STATUS_IDLE;

	uint8_t ui8IrqBuffer[2];
	uint8_t ui8TargetProtocol[2];
	uint8_t ui8FifoStatusLength;
	uint8_t ui8FifoIndex = 0;
//	uint8_t ui8PacketLength = 0;

	bool bRfidModeEnabled = false;
	bool bNfcModeEnabled = false;

	static Timer txTimer;

	uint16_t ui16ElapsedTimeMs = 0;
	uint16_t ui16TimeDelayValue = 0;

	if (IRQ_IS_SET())
		g_ui8IrqFlag = 1;
	else {
		g_ui8IrqFlag = 0;
		if (ui16TimeOut == 0)
			return eIrqStatusFlag;
	}

	//
	// Check if the IRQ flag has been set
	//
	while (IRQ_IS_SET() == 0x00 && ui16ElapsedTimeMs != ui16TimeOut) {
		if (txTimer.iselapsed()) {
			if (RFID::callbackFunction()) {
				__no_operation();
				break;
			}
			ui16ElapsedTimeMs += ui16TimeDelayValue;
			if ((ui16TimeOut - ui16ElapsedTimeMs) > 100) {
				ui16TimeDelayValue = 100;
			} else if (ui16TimeOut != ui16ElapsedTimeMs)
				ui16TimeDelayValue = ui16TimeOut - ui16ElapsedTimeMs;
			txTimer.Start(ui16TimeDelayValue);
		}
	}

	//
	// Disable Timer
	//
	txTimer.Stop();

	// Check for RFID Mode
	if ((g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE
			&& (g_sTrf7970Status.sInitiatorMode.bits.bPassive15693 == 1
					|| g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeA == 1
					|| g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeB == 1
					|| g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeF == 1))) {
		bRfidModeEnabled = true;
	} else if (g_sTrf7970Status.eCurrentMode != TRF_IDLE_MODE) {
		bNfcModeEnabled = true;
	}

	if (g_ui8IrqFlag == 0x00 && ui16TimeOut > 0) {
		eIrqStatusFlag = IRQ_STATUS_TIME_OUT;
	} else {

		g_ui8IrqFlag = 0;

		if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {
			//
			// Read Target Protocol
			//
			TRF797x_readCont(ui8TargetProtocol, TRF79X0_NFC_TARGET_PROTOCOL_REG,
					2);
		}

		//
		// Read IRQ Register
		//
		TRF797x_readSingle(ui8IrqBuffer, TRF79X0_IRQ_STATUS_REG);

		// RF Field for Target Modes
		if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {
			if ((ui8TargetProtocol[0] & 0x80) == 0x80) {
				g_sTrf7970Status.bRfFieldOn = true;
			} else if (g_sTrf7970Status.bRfFieldOn) {
				g_sTrf7970Status.bRfFieldOn = false;
			}
		} else if (g_sTrf7970Status.eCurrentMode != TRF_TARGET_MODE) {
			g_sTrf7970Status.bRfFieldOn = false;
		}

		//
		// FIFO_IRQ_Handler
		//
		if (ui8IrqBuffer[0] & IRQ_STATUS_FIFO_HIGH_OR_LOW) {
			if (ui8IrqBuffer[0] & IRQ_STATUS_RX_COMPLETE) {
				g_sTrf7970Status.ui8FifoBytesReceived = 0;
				//
				// Read the FIFO status and FIFO into g_nfc_buffer
				//
				TRF797x_readSingle(&ui8FifoStatusLength,
						TRF79X0_FIFO_STATUS_REG);

				ui8FifoIndex = 0;

				while ((g_sTrf7970Status.ui8FifoBytesReceived
						+ ui8FifoStatusLength) <= NFC_FIFO_SIZE
						&& eIrqStatusFlag == IRQ_STATUS_IDLE) {

					// Update the received bytes
					g_sTrf7970Status.ui8FifoBytesReceived +=
							ui8FifoStatusLength;

//					// Check if the packet has been received completely.
//					if(ui8PacketLength == g_sTrf7970Status.ui8FifoBytesReceived &&
//						g_sTrf7970Status.bNfcModeEnabled == true)
//					{
//						// Handle Active communication TADT Required Delay
//						if(g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE &&
//							 (g_sTrf7970Status.sTargetMode.bits.bActiveTypeF == 1 ||
//							  g_sTrf7970Status.sTargetMode.bits.bActiveTypeA == 1))
//						{
//							while(TRF797x_checkField(EXTERNAL_RSSI) != 0x00);
//							TRF797x_switchTargetBaudRate(g_sTrf7970Status.sTargetPayloadFrequency,true);
//							TRF797x_setField(EXT_FIELD_ON);
//						}
//						else if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE &&
//								 (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF == 1 ||
//								  g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA == 1))
//						{
//							while(TRF797x_checkField(EXTERNAL_RSSI) != 0x00);
//							TRF797x_switchInitiatorBaudRate(g_sTrf7970Status.sInitiatorPayloadFrequency,true);
//							TRF797x_setField(EXT_FIELD_ON);
//						}
//						TRF797x_readCont(&g_ui8FifoBuffer[ui8FifoIndex],TRF79X0_FIFO_REG, ui8FifoStatusLength);
//						eIrqStatusFlag = IRQ_STATUS_RX_COMPLETE;
//						break;
//					}

					if (ui8FifoStatusLength > 0) {
						//
						// Read the FIFO Data
						//
						TRF797x_readCont(&g_ui8FifoBuffer[ui8FifoIndex],
								TRF79X0_FIFO_REG, ui8FifoStatusLength);

						// Update fifo_index
						ui8FifoIndex = ui8FifoIndex + ui8FifoStatusLength;
					}

					//
					// Re-Read the FIFO status to check if we are still in the process of receiving
					//
					TRF797x_readSingle(&ui8FifoStatusLength,
							TRF79X0_FIFO_STATUS_REG);

					// If there are no more bytes inside the FIFO
					if ((ui8FifoStatusLength & 0x7F) == 0x00) {
						eIrqStatusFlag = IRQ_STATUS_RX_COMPLETE;
						break;
					} else {
						//
						// Initialize a 1 mS timeout
						//
						if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE
								&& (g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeA
										== 1
										|| g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA
												== 1)) {
//							// If the IRQ is set, do not read out the data yet (workaround for Passive Type A)
//							if (IRQ_IS_SET())
//							{
//								TRF797x_readCont(ui8IrqBuffer, TRF79X0_IRQ_STATUS_REG, 2);
//							}
							g_ui8IrqFlag = 0;
							ui16TimeOut = 7;
						} else if (g_sTrf7970Status.eCurrentMode
								== TRF_TARGET_MODE
								&& (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeA
										== 1
										|| g_sTrf7970Status.sTargetMode.bits.bActiveTypeA
												== 1)) {
							ui16TimeOut = 7;
						} else {

							ui16TimeOut = 7;
						}

						if (!IRQ_IS_SET())
							g_ui8IrqFlag = 0;

						// Clear ui16TimeDelayValue
						ui16TimeDelayValue = 0;
						ui16ElapsedTimeMs = 0;

						while (g_ui8IrqFlag == 0x00
								&& ui16ElapsedTimeMs != ui16TimeOut) {
							if (txTimer.iselapsed()) {
								if (RFID::callbackFunction()) {
									__no_operation();
									break;
								}
								ui16ElapsedTimeMs += ui16TimeDelayValue;
								if ((ui16TimeOut - ui16ElapsedTimeMs) > 100) {
									ui16TimeDelayValue = 100;
								} else if (ui16TimeOut != ui16ElapsedTimeMs)
									ui16TimeDelayValue = ui16TimeOut
											- ui16ElapsedTimeMs;
								txTimer.Start(ui16TimeDelayValue);
							}
						}

						//
						// Disable Timer
						//
						txTimer.Stop();
					}

//					// Check for packet length for P2P
//					if( (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE &&
//							(g_sTrf7970Status.sTargetMode.ui8byte == 0x00 ||
//							 g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF == 1 ||
//							 g_sTrf7970Status.sTargetMode.bits.bActiveTypeF == 1 ||
//							 g_sTrf7970Status.sTargetMode.bits.bPassiveTypeA == 1 ||
//							 g_sTrf7970Status.sTargetMode.bits.bActiveTypeA == 1))
//							 && g_sTrf7970Status.bNfcModeEnabled == true)
//					{
//						if( (ui8TargetProtocol[0] == 0xC0 ||
//								((ui8TargetProtocol[0] & 0x09) == 0x09))
//								&& g_ui8FifoBuffer[0] == 0xF0)
//						{
//							ui8PacketLength = g_ui8FifoBuffer[1]+1;
//						}
//						else if(((ui8TargetProtocol[0] & 0x12) == 0x12) ||
//								((ui8TargetProtocol[0] & 0x13) == 0x13))
//						{
//							ui8PacketLength = g_ui8FifoBuffer[0];
//						}
//					}
//					else if ((g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE &&
//								(g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeF == 1 ||
//								 g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF == 1))
//							 && g_sTrf7970Status.bNfcModeEnabled == true)
//					{
//						ui8PacketLength = g_ui8FifoBuffer[0];
//					}
//					else if(g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE &&
//							(g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeA == 1 ||
//									g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA == 1)
//							&& g_sTrf7970Status.bNfcModeEnabled == true)
//					{
//						if(g_ui8FifoBuffer[0] == 0xF0)
//						{
//							ui8PacketLength = g_ui8FifoBuffer[1]+1;
//						}
//					}

					TRF797x_readCont(ui8IrqBuffer, TRF79X0_IRQ_STATUS_REG, 2);

					//
					// Read the FIFO status and FIFO into g_nfc_buffer
					//
					TRF797x_readSingle(&ui8FifoStatusLength,
							TRF79X0_FIFO_STATUS_REG);

					// Mask off bit 7.
					ui8FifoStatusLength &= 0x7F;
				}

				if (eIrqStatusFlag != IRQ_STATUS_RX_COMPLETE) {
					eIrqStatusFlag = IRQ_STATUS_PROTOCOL_ERROR;
				} else if (IRQ_IS_SET()) {
					TRF797x_readCont(ui8IrqBuffer, TRF79X0_IRQ_STATUS_REG, 2);
				}

				if (eIrqStatusFlag == IRQ_STATUS_RX_COMPLETE) {
					if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE
							|| ((g_sTrf7970Status.eCurrentMode
									== TRF_TARGET_MODE)
									&& (g_sTrf7970Status.bTargetSelected == true)))
						RF_WriteMailBox(g_ui8FifoBuffer,
								g_sTrf7970Status.ui8FifoBytesReceived);
				}

			} else if (ui8IrqBuffer[0] & IRQ_STATUS_TX_COMPLETE) {
				//
				// Read the FIFO status and FIFO into g_nfc_buffer
				//
				TRF797x_readSingle(&ui8FifoStatusLength,
						TRF79X0_FIFO_STATUS_REG);

				if (ui8FifoStatusLength == 0x00) {
					eIrqStatusFlag = IRQ_STATUS_TX_COMPLETE;
				} else {
					eIrqStatusFlag = IRQ_STATUS_FIFO_HIGH_OR_LOW;
				}

			}
			// RX Complete
		} else if (ui8IrqBuffer[0] & IRQ_STATUS_RX_COMPLETE) {

			if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {
				g_sTrf7970Status.bRfFieldOn = true;
				if (g_sTrf7970Status.bTargetSelected == true) {
					//
					// Register 0Fh. RSSI Register
					//
					TRF797x_readSingle(&g_sTrf7970Status.ui8InternalRssi,
							TRF79X0_RSSI_LEVEL_REG);
				}
			}
			// Initiator Mode
			else {
				//
				// Register 0Fh. RSSI Register
				//
				TRF797x_readSingle(&g_sTrf7970Status.ui8InternalRssi,
						TRF79X0_RSSI_LEVEL_REG);
			}

			//
			// Read the FIFO status and FIFO into g_nfc_buffer
			//
			TRF797x_readSingle(&ui8FifoStatusLength, TRF79X0_FIFO_STATUS_REG);

			// Handle Active communication TADT Required Delay
			if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE
					&& (g_sTrf7970Status.sTargetMode.bits.bActiveTypeF == 1
							|| g_sTrf7970Status.sTargetMode.bits.bActiveTypeA
									== 1 ||
							// Check if first polling command is greater than 20 bytes
							(g_sTrf7970Status.sTargetMode.ui8byte == 0x00
									&& ui8FifoStatusLength > 20
									&& (g_sTargetSupportedTechnologies.bits.bActiveTypeA
											== 1
											|| g_sTargetSupportedTechnologies.bits.bActiveTypeF
													== 1)))) {
				// Wait until RF Field is disabled.
				while (TRF797x_checkField(EXTERNAL_RSSI) != 0x00)
					;
				if (g_sTrf7970Status.sTargetMode.ui8byte == 0x00) {
					// Change the ISO Control Register to RFID Mode to ensure RF Field will be enabled.
					TRF797x_writeSingle(0x08, TRF79X0_ISO_CONTROL_REG);
				} else {
					TRF797x_switchTargetBaudRate(
							g_sTrf7970Status.sTargetPayloadFrequency, true);
				}
				TRF797x_setField(EXT_FIELD_ON);
			} else if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE
					&& (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF == 1
							|| g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA
									== 1)) {
				while (TRF797x_checkField(EXTERNAL_RSSI) != 0x00)
					;
				TRF797x_switchInitiatorBaudRate(
						g_sTrf7970Status.sInitiatorPayloadFrequency, true);
				TRF797x_setField(EXT_FIELD_ON);
			}

			// Check if the selected_mode corresponds to the command read in the command
			if ((g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE
					&& (g_sTrf7970Status.sTargetMode.ui8byte == 0x00
							|| (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF
									== 1
									&& ui8TargetProtocol[0]
											& TRF79X0_NFC_TARGET_PROTOCOL_FELICA)
							|| (g_sTrf7970Status.sTargetMode.bits.bActiveTypeF
									== 1
									&& ui8TargetProtocol[0]
											& TRF79X0_NFC_TARGET_PROTOCOL_FELICA)
							|| (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeA
									== 1)
							|| (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeB
									== 1
									&& ui8TargetProtocol[0]
											& TRF79X0_NFC_TARGET_PROTOCOL_ISO14443B)
							|| (g_sTrf7970Status.sTargetMode.bits.bActiveTypeA
									== 1)))
					|| g_sTrf7970Status.sInitiatorMode.bits.bPassive15693 == 1
					|| g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeA == 1
					|| g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA == 1
					|| g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeB == 1
					|| g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeF == 1
					|| g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF == 1)

					{
				// Read the data
				if (ui8FifoStatusLength > 0
						&& ((ui8FifoStatusLength & TRF79X0_FIFO_OVERFLOW)
								!= TRF79X0_FIFO_OVERFLOW)) {
					//
					// Read the FIFO Data
					//
					TRF797x_readCont(g_ui8FifoBuffer, TRF79X0_FIFO_REG,
							ui8FifoStatusLength);

					g_sTrf7970Status.ui8FifoBytesReceived = ui8FifoStatusLength;
				} else {
					TRF797x_resetMode();
					return IRQ_STATUS_IDLE;
				}

				// Target Mode Listening for multiple protocols
				if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {
					// Target Has not been activated
					if (g_sTrf7970Status.sTargetPayloadFrequency.ui16word
							== 0x0000) {
						switch (ui8TargetProtocol[0]
								& TRF79X0_NFC_TARGET_PROTOCOL_KBPS_MASK) {
						case TRF79X0_NFC_TARGET_PROTOCOL_106KBPS:
							g_sTrf7970Status.sTargetPayloadFrequency.bits.b106kpbs =
									1;
							break;
						case TRF79X0_NFC_TARGET_PROTOCOL_212KBPS:
							g_sTrf7970Status.sTargetPayloadFrequency.bits.b212kpbs =
									1;
							break;
						case TRF79X0_NFC_TARGET_PROTOCOL_424KBPS:
							g_sTrf7970Status.sTargetPayloadFrequency.bits.b424kpbs =
									1;
							break;
						default:
							// Handle Type A Case
							// Check for  SENS_REQ or  ATR_REQ
							if (ui8FifoStatusLength == 1
									|| (ui8FifoStatusLength
											== (g_ui8FifoBuffer[1] + 1))) {
								g_sTrf7970Status.sTargetPayloadFrequency.bits.b106kpbs =
										1;
							}

							break;
						}

						if (TRF797x_targetInitialize() != OK) {
							eIrqStatusFlag = IRQ_STATUS_IDLE;
							TRF797x_resetMode();
						} else {
							if (g_sTrf7970Status.bTargetSelected == false) {
								eIrqStatusFlag = IRQ_STATUS_IDLE;
								RF_anticollisionProcess(g_ui8FifoBuffer,
										g_sTrf7970Status.ui8FifoBytesReceived);
							} else {
								eIrqStatusFlag = IRQ_STATUS_RX_COMPLETE;
							}
						}
					} else {
						switch (ui8TargetProtocol[0]
								& TRF79X0_NFC_TARGET_PROTOCOL_KBPS_MASK) {
						case TRF79X0_NFC_TARGET_PROTOCOL_106KBPS:
							if (g_sTrf7970Status.sTargetPayloadFrequency.bits.b106kpbs
									!= 1)
								eIrqStatusFlag = IRQ_STATUS_PROTOCOL_ERROR;
							break;
						case TRF79X0_NFC_TARGET_PROTOCOL_212KBPS:
							if (g_sTrf7970Status.sTargetPayloadFrequency.bits.b212kpbs
									!= 1)
								eIrqStatusFlag = IRQ_STATUS_PROTOCOL_ERROR;
							break;
						case TRF79X0_NFC_TARGET_PROTOCOL_424KBPS:
							if (g_sTrf7970Status.sTargetPayloadFrequency.bits.b424kpbs
									!= 1)
								eIrqStatusFlag = IRQ_STATUS_PROTOCOL_ERROR;
							break;
						default:
							// Handle Type A Case
							if (ui8TargetProtocol[0] == 0xC0) {
								if (g_sTrf7970Status.sTargetPayloadFrequency.bits.b106kpbs
										!= 1)
									eIrqStatusFlag = IRQ_STATUS_PROTOCOL_ERROR;
							}

							break;
						}

						if (eIrqStatusFlag != IRQ_STATUS_PROTOCOL_ERROR) {
							if (g_sTrf7970Status.bTargetSelected == false) {
								RF_anticollisionProcess(g_ui8FifoBuffer,
										g_sTrf7970Status.ui8FifoBytesReceived);
							} else {
								eIrqStatusFlag = IRQ_STATUS_RX_COMPLETE;
							}
						}
					}

				}
				// Initiator Mode
				else {
					eIrqStatusFlag = IRQ_STATUS_RX_COMPLETE;
				}

				if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE
						|| ((g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE)
								&& (g_sTrf7970Status.bTargetSelected == true))) {
					// TODO Remove if statement to activate Card Emulation Type B
					if (eIrqStatusFlag == IRQ_STATUS_RX_COMPLETE) {
						RF_WriteMailBox(g_ui8FifoBuffer,
								g_sTrf7970Status.ui8FifoBytesReceived);
					}

				} else if (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeB == 1
						&& g_ui8FifoBuffer[0] == 0xC2) {
					RF_anticollisionProcess(g_ui8FifoBuffer,
							g_sTrf7970Status.ui8FifoBytesReceived);
				}

			} else {
				if (ui8FifoStatusLength == 0) {
					eIrqStatusFlag = IRQ_STATUS_PROTOCOL_ERROR;
					TRF797x_resetMode();
				}
			}

		} else if (ui8IrqBuffer[0] & IRQ_STATUS_TX_COMPLETE) {

			if (ui8IrqBuffer[0] == IRQ_STATUS_TX_COMPLETE) {
				g_sTrf7970Status.bTxComplete = true;
				// Reset FIFO CMD + Dummy byte
				TRF797x_resetFIFO();

				eIrqStatusFlag = IRQ_STATUS_TX_COMPLETE;
			} else {
				// Read the FIFO status
				TRF797x_readSingle(&ui8FifoStatusLength,
						TRF79X0_FIFO_STATUS_REG);

				if (ui8FifoStatusLength == 0)
					eIrqStatusFlag = IRQ_STATUS_TX_COMPLETE;
			}
		}
		// Handle NFC remaining cases
		else if (bNfcModeEnabled) {
			if ((ui8IrqBuffer[0] & IRQ_STATUS_NFC_COLLISION_ERROR)
					|| (ui8IrqBuffer[0] & IRQ_STATUS_NFC_PROTOCOL_ERROR)) {
				if (g_sTrf7970Status.bTargetSelected)
					g_sTrf7970Status.bProtocolError = true;
				TRF797x_resetMode();
				eIrqStatusFlag = IRQ_STATUS_PROTOCOL_ERROR;
			} else if (ui8IrqBuffer[0] & IRQ_STATUS_NFC_RF_FIELD_CHANGE) {
				eIrqStatusFlag = IRQ_STATUS_RF_FIELD_CHANGE;
				if ((ui8TargetProtocol[0] & 0x80) != 0x80) {
					TRF797x_resetMode();
					eIrqStatusFlag = IRQ_STATUS_PROTOCOL_ERROR;
				}

				// Check RF Field when Active Initiator is enabled
				if (g_sTrf7970Status.eCurrentMode == TRF_INITIATOR_MODE
						&& (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF
								== 1
								|| g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA
										== 1)) {
					TRF797x_readCont(ui8TargetProtocol,
							TRF79X0_NFC_TARGET_PROTOCOL_REG, 2);
				}

				if ((((ui8TargetProtocol[0] & 0x40) != 0x40)
						&& (ui8TargetProtocol[0] != 0x00))
						|| (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE
								&& g_sTrf7970Status.sTargetPayloadFrequency.ui16word
										== 0x0000
								&& (ui8TargetProtocol[0] == 0x00))) {
					// In the case we get this in the middle of a transfer
					TRF797x_resetMode();
				}
			} else if (ui8IrqBuffer[0] & IRQ_STATUS_NFC_SDD_COMPLETE) {
				g_sTrf7970Status.sTargetMode.bits.bPassiveTypeA = 1;
				g_sTrf7970Status.sTargetPayloadFrequency.bits.b106kpbs = 1;
				eIrqStatusFlag = IRQ_STATUS_SDD_COMPLETE;
				TRF797x_resetFIFO();
				// Disable Anti-collision Frames for 14443A.
				TRF797x_writeSingle(0x02, TRF79X0_SPECIAL_FUNC_1_REG);
			}
			// Handle RFID remaining cases
		} else if (bRfidModeEnabled) {
			if (ui8IrqBuffer[0] & IRQ_STATUS_RFID_COLLISION_ERROR
					|| ui8IrqBuffer[0] & IRQ_STATUS_RFID_FRAMING_OR_EOF_ERROR
					|| ui8IrqBuffer[0] & IRQ_STATUS_RFID_PARITY_ERROR
					|| ui8IrqBuffer[0] & IRQ_STATUS_RFID_CRC_ERROR) {
				TRF797x_resetMode();
				eIrqStatusFlag = IRQ_STATUS_PROTOCOL_ERROR;
			} else if (ui8IrqBuffer[0] == IRQ_STATUS_RFID_NO_RESPONSE_INT) {
				eIrqStatusFlag = IRQ_STATUS_NO_RESPONSE;
			}
		}
	}

	// RF Field for Target Modes
	if (g_sTrf7970Status.bRfFieldOn == true) {
		GPIO::setExtField(true);
	} else {
		GPIO::setExtField(false);
	}

	// Reset Global Flags
	g_ui8IrqFlag = 0x00;

	return eIrqStatusFlag;
}

/*
 * Switch Target BaudRate.
 */
uint8_t TRF797x_switchTargetBaudRate(t_sTRF797x_Bitrate sTargetFrequency,
		bool bModifyRegister) {
	uint8_t ui8IsoControlReg;
	uint8_t ui8RetValue = STATUS_SUCCESS_T;

	//
	// Register 01h. ISO Control Reg
	//
	if (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeA == 1) {
		if (sTargetFrequency.bits.b106kpbs == 1) {
			ui8IsoControlReg = 0x24;
		} else if (sTargetFrequency.bits.b212kpbs == 1) {
			// Clear Target Mode
			g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
			// Set Active Type F
			g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF = 1;
			ui8IsoControlReg = 0x22;
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;
		} else if (sTargetFrequency.bits.b424kpbs == 1) {
			// Clear Target Mode
			g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
			// Set Active Type F
			g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF = 1;
			ui8IsoControlReg = 0x23;
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;
		} else
			ui8RetValue = STATUS_FAIL_T;
	} else if (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeB == 1) {
		if (sTargetFrequency.bits.b106kpbs == 1) {
			// Clear Target Mode
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;

			ui8IsoControlReg = 0x25;
		} else
			ui8RetValue = STATUS_FAIL_T;
	} else if (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF == 1) {
		if (sTargetFrequency.bits.b212kpbs == 1) {
			g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
			g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF = 1;
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;
			ui8IsoControlReg = 0x22;
		} else if (sTargetFrequency.bits.b424kpbs == 1) {
			g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
			g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF = 1;
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;
			ui8IsoControlReg = 0x23;
		} else
			ui8RetValue = STATUS_FAIL_T;
	} else if (g_sTrf7970Status.sTargetMode.bits.bActiveTypeA == 1) {
		if (sTargetFrequency.bits.b106kpbs == 1) {
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;
			ui8IsoControlReg = 0x08;
		} else if (sTargetFrequency.bits.b212kpbs == 1) {
			// Clear Target Mode
			g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
			// Set Active Type F
			g_sTrf7970Status.sTargetMode.bits.bActiveTypeF = 1;
			ui8IsoControlReg = 0x32;
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;
		} else if (sTargetFrequency.bits.b424kpbs == 1) {
			// Clear Target Mode
			g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
			// Set Active Type F
			g_sTrf7970Status.sTargetMode.bits.bActiveTypeF = 1;
			ui8IsoControlReg = 0x33;
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;
		} else
			ui8RetValue = STATUS_FAIL_T;
	} else if (g_sTrf7970Status.sTargetMode.bits.bActiveTypeF == 1) {
		if (sTargetFrequency.bits.b212kpbs == 1) {
			// Clear Target Mode
			g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
			// Set Active Type F
			g_sTrf7970Status.sTargetMode.bits.bActiveTypeF = 1;
			ui8IsoControlReg = 0x32;
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;
		} else if (sTargetFrequency.bits.b424kpbs == 1) {
			// Clear Target Mode
			g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
			// Set Active Type F
			g_sTrf7970Status.sTargetMode.bits.bActiveTypeF = 1;
			ui8IsoControlReg = 0x33;
			g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;
		} else
			ui8RetValue = STATUS_FAIL_T;
	} else {
		ui8RetValue = STATUS_FAIL_T;
	}

	if (ui8RetValue == OK) {
		g_sTrf7970Status.sTargetPayloadFrequency = sTargetFrequency;

		if (bModifyRegister == true) {
			TRF797x_writeSingle(ui8IsoControlReg, TRF79X0_ISO_CONTROL_REG);
		}
	}

	return ui8RetValue;
}

uint8_t TRF797x_incrementTargetBaudRate(t_sTRF797x_Bitrate sTargetFrequency) {
	uint8_t ui8RetValue = OK;

	if (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeA == 1) {
		ui8RetValue = TRF797x_switchTargetBaudRate(sTargetFrequency, true);
	} else if (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeB == 1) {
		ui8RetValue = TRF797x_switchTargetBaudRate(sTargetFrequency, true);
	} else if (g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF == 1) {
		ui8RetValue = TRF797x_switchTargetBaudRate(sTargetFrequency, true);
	} else if (g_sTrf7970Status.sTargetMode.bits.bActiveTypeA == 1) {
		ui8RetValue = TRF797x_switchTargetBaudRate(sTargetFrequency, false);
	} else if (g_sTrf7970Status.sTargetMode.bits.bActiveTypeF == 1) {
		ui8RetValue = TRF797x_switchTargetBaudRate(sTargetFrequency, false);
	} else {
		ui8RetValue = STATUS_FAIL_T;
	}

	return ui8RetValue;
}

/*
 * Switch Initiator BaudRate.
 */
uint8_t TRF797x_switchInitiatorBaudRate(t_sTRF797x_Bitrate sInitiatorFrequency,
		bool bModifyRegister) {
	uint8_t ui8IsoControlReg;
	uint8_t ui8RetValue = STATUS_SUCCESS_T;
	g_sTrf7970Status.sInitiatorPayloadFrequency = sInitiatorFrequency;

	//
	// Register 01h. ISO Control Reg
	//
	if (g_sTrf7970Status.sInitiatorMode.bits.bPassive15693 == 1) {
		if (sInitiatorFrequency.bits.b6_62_kbps_1_out_4 == 1) {
			ui8IsoControlReg = 0x00;
		} else if (sInitiatorFrequency.bits.b6_62_kbps_1_out_256 == 1) {
			ui8IsoControlReg = 0x01;
		} else if (sInitiatorFrequency.bits.b26_48_kbps_1_out_4 == 1) {
			ui8IsoControlReg = 0x02;
		} else if (sInitiatorFrequency.bits.b26_48_kbps_1_out_256 == 1) {
			ui8IsoControlReg = 0x03;
		} else if (sInitiatorFrequency.bits.b6_67_kbps_1_out_4 == 1) {
			ui8IsoControlReg = 0x04;
		} else if (sInitiatorFrequency.bits.b6_67_kbps_1_out_256 == 1) {
			ui8IsoControlReg = 0x05;
		} else if (sInitiatorFrequency.bits.b26_69_kbps_1_out_4 == 1) {
			ui8IsoControlReg = 0x06;
		} else if (sInitiatorFrequency.bits.b26_69_kbps_1_out_256 == 1) {
			ui8IsoControlReg = 0x07;
		} else
			ui8RetValue = STATUS_FAIL_T;
	} else if (g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeA == 1) {
		if (sInitiatorFrequency.bits.b106kpbs == 1) {
			if (RF_getBitframe() == 0) {
				ui8IsoControlReg = 0x08;
			} else {
				ui8IsoControlReg = 0x88;
			}

		} else if (sInitiatorFrequency.bits.b212kpbs == 1) {

			if (g_sTrf7970Status.bNfcModeEnabled == false) {
				ui8IsoControlReg = 0x09;
			} else {
				// Clear Initiator Mode
				g_sTrf7970Status.sInitiatorMode.ui8byte = 0x00;
				// Set Passive Type F
				g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeF = 1;
				ui8IsoControlReg = 0x32;
			}
		} else if (sInitiatorFrequency.bits.b424kpbs == 1) {
			if (g_sTrf7970Status.bNfcModeEnabled == false) {
				ui8IsoControlReg = 0x0A;
			} else {
				// Clear Initiator Mode
				g_sTrf7970Status.sInitiatorMode.ui8byte = 0x00;
				// Set Passive Type F
				g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeF = 1;
				ui8IsoControlReg = 0x33;
			}
		} else if (sInitiatorFrequency.bits.b848kpbs == 1) {
			ui8IsoControlReg = 0x0B;
		}
	} else if (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA == 1) {
		if (sInitiatorFrequency.bits.b106kpbs == 1) {
			ui8IsoControlReg = 0x08;
		} else if (sInitiatorFrequency.bits.b212kpbs == 1) {

			if (g_sTrf7970Status.bNfcModeEnabled == false) {
				ui8IsoControlReg = 0x09;
			} else {
				// Clear Initiator Mode
				g_sTrf7970Status.sInitiatorMode.ui8byte = 0x00;
				// Set Passive Type F
				g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF = 1;
				ui8IsoControlReg = 0x32;
			}
		} else if (sInitiatorFrequency.bits.b424kpbs == 1) {
			if (g_sTrf7970Status.bNfcModeEnabled == false) {
				ui8IsoControlReg = 0x0A;
			} else {
				// Clear Initiator Mode
				g_sTrf7970Status.sInitiatorMode.ui8byte = 0x00;
				// Set Passive Type F
				g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF = 1;
				ui8IsoControlReg = 0x33;
			}
		}
	}

	else if (g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeB == 1) {
		if (sInitiatorFrequency.bits.b106kpbs == 1) {
			ui8IsoControlReg = 0x0C;
		} else if (sInitiatorFrequency.bits.b212kpbs == 1) {
			ui8IsoControlReg = 0x0D;
		} else if (sInitiatorFrequency.bits.b424kpbs == 1) {
			ui8IsoControlReg = 0x0E;
		} else if (sInitiatorFrequency.bits.b848kpbs == 1) {
			ui8IsoControlReg = 0x0F;
		}
	} else if (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF == 1
			|| g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeF == 1) {
		if (sInitiatorFrequency.bits.b212kpbs == 1) {
			ui8IsoControlReg = 0x32;
			// In the MicroPross it looked as if the TRF was generating an extra when 0x1A was set.
//			ui8IsoControlReg = 0x1A;
		} else if (sInitiatorFrequency.bits.b424kpbs == 1) {
			ui8IsoControlReg = 0x33;
		}
	} else {
		ui8RetValue = STATUS_FAIL_T;
	}

	if (ui8RetValue == OK && bModifyRegister == true) {
		TRF797x_writeSingle(ui8IsoControlReg, TRF79X0_ISO_CONTROL_REG);
	}

	return ui8RetValue;
}

uint8_t TRF797x_incrementInitiatorBaudRate(
		t_sTRF797x_Bitrate sInitiatorFrequency) {
	uint8_t ui8RetValue = OK;
	//
	// Register 01h. ISO Control Reg
	//
	if (g_sTrf7970Status.sInitiatorMode.bits.bPassive15693 == 1) {
		ui8RetValue = TRF797x_switchInitiatorBaudRate(sInitiatorFrequency,
				true);
	} else if (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeA == 1) {
		ui8RetValue = TRF797x_switchInitiatorBaudRate(sInitiatorFrequency,
				true);
	} else if (g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeA == 1) {
		ui8RetValue = TRF797x_switchInitiatorBaudRate(sInitiatorFrequency,
				true);
	} else if (g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeB == 1) {
		ui8RetValue = TRF797x_switchInitiatorBaudRate(sInitiatorFrequency,
				true);
	} else if (g_sTrf7970Status.sInitiatorMode.bits.bActiveTypeF == 1) {
		ui8RetValue = TRF797x_switchInitiatorBaudRate(sInitiatorFrequency,
				true);
	} else if (g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeF == 1) {
		ui8RetValue = TRF797x_switchInitiatorBaudRate(sInitiatorFrequency,
				true);
	} else {
		ui8RetValue = STATUS_FAIL_T;
	}

	return ui8RetValue;
}

/*
 * Get Collision Position if there was a collision.
 */
uint16_t TRF797x_getCollisionStatus(void) {
	uint16_t ui16CollisionStatus = 0x00;
	uint8_t ui8CollisionStatus = 0x00;

	TRF797x_readSingle(&ui8CollisionStatus, TRF79X0_COLLISION_POSITION_REG);

	ui16CollisionStatus = ui8CollisionStatus;

	TRF797x_readSingle(&ui8CollisionStatus, TRF79X0_IRQ_MASK_REG);

	// Mask Bit 7 and 6 ( Col 9 & Col 8)
	ui8CollisionStatus = ui8CollisionStatus & 0xC0;

	ui16CollisionStatus = (ui16CollisionStatus
			| ((uint16_t) ui8CollisionStatus << 8));

	return ui16CollisionStatus;
}

/*
 * Enable/Disable RF Field.
 */
uint8_t TRF797x_setField(tExtField eRfField) {
	if (eRfField == EXT_FIELD_ON) {
		//
		// Register 00h. Chip Status Control
		//
		TRF797x_writeSingle(
				TRF79X0_STATUS_CTRL_RF_ON | TRF79X0_CHIP_STATUS_CTRL_BYTE,
				TRF79X0_CHIP_STATUS_CTRL_REG);

		if(g_sTrf7970Status.sInitiatorMode.bits.bPassiveTypeB == 1)
		{
			// Add 15 ms to GTB
			waitms(15);
		}
	} else if (eRfField == EXT_FIELD_OFF) {
		//
		// Register 00h. Chip Status Control
		//
		TRF797x_writeSingle(
				(~TRF79X0_STATUS_CTRL_RF_ON) & TRF79X0_CHIP_STATUS_CTRL_BYTE,
				TRF79X0_CHIP_STATUS_CTRL_REG);
	} else
		return STATUS_FAIL_T;

	return OK;
}

/*
 * Checks the external field RSSI.
 */
uint8_t TRF797x_checkField(tRssiStatus eField) {
	uint8_t ui8RssiLevel;

	if (eField == INTERNAL_RSSI) {
		//
		// Transmitter On
		//
		TRF797x_setField(EXT_FIELD_ON);

		//
		// Register 00h. Chip Status Control
		//
		TRF797x_writeSingle(
				(TRF79X0_STATUS_CTRL_RF_ON | TRF79X0_STATUS_CTRL_RECEIVER_ON
						| TRF79X0_CHIP_STATUS_CTRL_BYTE),
				TRF79X0_CHIP_STATUS_CTRL_REG);

		//
		// Register 01h. ISO Control Reg
		//
		TRF797x_writeSingle(0x00, TRF79X0_ISO_CONTROL_REG);

		//
		// Test Internal RF Field
		//
		TRF797x_directCommand(TRF79X0_TEST_INTERNAL_RF_CMD);
	} else if (eField == EXTERNAL_RSSI) {
		//
		// Transmitter Off
		//
		TRF797x_setField(EXT_FIELD_OFF);

		//
		// Register 00h. Chip Status Control
		//
		TRF797x_writeSingle(
				(TRF79X0_STATUS_CTRL_RECEIVER_ON
						| TRF79X0_CHIP_STATUS_CTRL_BYTE),
				TRF79X0_CHIP_STATUS_CTRL_REG);

		//
		// Test External RF Field
		//
		TRF797x_directCommand(TRF79X0_TEST_EXTERNAL_RF_CMD);
	}

	waitus(50);

	//
	// Register 0Fh. RSSI Register
	//
	TRF797x_readSingle(&ui8RssiLevel, TRF79X0_RSSI_LEVEL_REG);

	return (ui8RssiLevel & 0x3F);
}

word TRF797x_checkExternalField(void) {
	uint8_t rx_buffer;
	word ret_val = OK;

	//
	// Soft Init Command
	//
	TRF797x_directCommand(TRF79X0_SOFT_INIT_CMD);

	//
	// Idle Command
	//
	TRF797x_directCommand(TRF79X0_IDLE_CMD);

	// Register 00h. Chip Status Control
	// RF output active, +5 V operation
	TRF797x_writeSingle(0x03, TRF79X0_CHIP_STATUS_CTRL_REG);

	// Check if there an external RF Field
	TRF797x_directCommand(TRF79X0_TEST_EXTERNAL_RF_CMD);

	// Delay 50 uS to latch the RSSI value to the RSSI register
	waitus(50);

	TRF797x_readSingle(&rx_buffer, TRF79X0_RSSI_LEVEL_REG);

	// If the External RF Field is 0x00, we continue else we return fail
	if ((rx_buffer & 0x3F) != 0x00) {
		// Register 00h. Chip Status Control
		// RF output de-activated, +5 V operation
		TRF797x_writeSingle(0x01, TRF79X0_CHIP_STATUS_CTRL_REG);
		ret_val = HF_FIELD_ERROR;
	} else {

		//
		// Register 09h. Modulator Control
		//
		// SYS_CLK (in this case 13.56 MHz) out optional, based on system req.
		TRF797x_writeSingle(0x00, TRF79X0_MODULATOR_CONTROL_REG);

		//
		// Register 0Bh. Regulator Control
		//
		TRF797x_writeSingle(0x01, TRF79X0_REGULATOR_CONTROL_REG);

		//
		// Register 14h. FIFO IRQ Level
		//
		// RX High = 96 bytes , TX Low = 32 bytes
		TRF797x_writeSingle(0x0F, TRF79X0_FIFO_IRQ_LEVEL);
	}

	return ret_val;
}

/*
 * Initialize Idle Mode.
 */
uint8_t TRF797x_idleMode(void) {
	uint8_t ui8RxBuffer[2];
	uint8_t ui8RetryCounter = 0;

	// Reset Status Values
	g_sTrf7970Status.ui8FifoBytesReceived = 0x00;
	g_sTrf7970Status.bTxComplete = false;
	g_sTrf7970Status.bTargetSelected = false;
	g_sTrf7970Status.bRfFieldOn = false;
	g_sTrf7970Status.eCurrentMode = TRF_IDLE_MODE;
	g_sTrf7970Status.sTargetPayloadFrequency.ui16word = 0x0000;
	g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
	g_sTrf7970Status.sInitiatorPayloadFrequency.ui16word = 0x0000;
	g_sTrf7970Status.sInitiatorMode.ui8byte = 0x00;
	g_sTrf7970Status.eIrqFlags = IRQ_STATUS_IDLE;
	g_sTrf7970Status.ui8InternalRssi = 0;
	g_sTrf7970Status.bNfcModeEnabled = false;
	g_sTrf7970Status.bProtocolError = false;

	GPIO::setExtField(g_sTrf7970Status.bRfFieldOn);

	// Reset Auto-SDD parameters
	g_ui8IdLength = 0x00;
	g_bNfcDepSupport = false;
	g_bIsoDepSuport = false;

	do {
		//
		// Soft Init Command
		//
		TRF797x_directCommand(TRF79X0_SOFT_INIT_CMD);

		//
		// Idle Command
		//
		TRF797x_directCommand(TRF79X0_IDLE_CMD);

		waitms(1);

		//
		// Register 09h. Modulator Control
		//
		TRF797x_readSingle(ui8RxBuffer, TRF79X0_MODULATOR_CONTROL_REG);

	} while (ui8RxBuffer[0] != 0x91 && ui8RetryCounter++ < 5);

	if (ui8RetryCounter == 0x05) {
		return STATUS_FAIL_T;
	}

	//
	// Register 00h. Chip Status Control
	//
	TRF797x_writeSingle(0x21, TRF79X0_CHIP_STATUS_CTRL_REG);

	//
	// Register 09h. Modulator Control
	//
	// SYS_CLK (in this case 13.56 MHz) out optional, based on system req.
	TRF797x_writeSingle(0x00, TRF79X0_MODULATOR_CONTROL_REG);

	//
	// Register 0Bh. Regulator Control
	//
	TRF797x_writeSingle(0x87, TRF79X0_REGULATOR_CONTROL_REG);

	//
	// Reset FIFO CMD + Dummy byte
	//
	TRF797x_resetFIFO();

	//
	// Register 00h. Chip Status Control
	//
	// +5 V operation
	TRF797x_writeSingle(0x00 | TRF79X0_CHIP_STATUS_CTRL_BYTE,
			TRF79X0_CHIP_STATUS_CTRL_REG);

	//
	// Register 0Dh. Interrupt Mask Register
	//
	TRF797x_writeSingle(0x3E, TRF79X0_IRQ_MASK_REG);

	//
	// Register 14h. FIFO IRQ Level
	//
	// RX High = 96 bytes , TX Low = 32 bytes
	TRF797x_writeSingle(0x0F, TRF79X0_FIFO_IRQ_LEVEL);

	TRF797x_readSingle(ui8RxBuffer, TRF79X0_IRQ_STATUS_REG);

	return OK;
}

/*
 * Initialize TRF7970A after the receipt of a SENS_REQ (Type A), SENSB_REQ (Type B), SENSF_REQ (Type F),
 * ATR_REQ @ 106 (Active Type A), ATR_REQ @ 212/424 (Active Type F). This function must be execute only when
 * the first command is received from the polling device.
 */
uint8_t TRF797x_targetInitialize(void) {
	uint8_t ui8Status = OK;
	t_sTRF797x_Bitrate sTargetBitrate;

	// Initialize Target Bitrate
	sTargetBitrate.ui16word = 0x0000;

	// Check if one the supported bitrates corresponds to the current bitrate.
	if ((g_sTargetSupportedBitrates.ui16word
			& g_sTrf7970Status.sTargetPayloadFrequency.ui16word) == 0) {
		ui8Status = STATUS_FAIL_T;
	} else if (g_sTrf7970Status.sTargetPayloadFrequency.bits.b106kpbs == 1) {
		// Check for SENS_REQ (Type A)
		if (g_sTrf7970Status.ui8FifoBytesReceived == 1
				&& (g_ui8FifoBuffer[0] == 0x26 || g_ui8FifoBuffer[0] == 0x52)) {
			if (g_sTargetSupportedTechnologies.bits.bPassiveTypeA == 1) {
				g_sTrf7970Status.sTargetMode.bits.bPassiveTypeA = 1;
			} else
				ui8Status = STATUS_FAIL_T;
		}
		// Check for SENSB_REQ (Type B) or
		else if ((g_sTrf7970Status.ui8FifoBytesReceived == 0x03
				&& g_ui8FifoBuffer[0] == 0x05)
				|| (g_sTrf7970Status.ui8FifoBytesReceived == 0x09
						&& g_ui8FifoBuffer[0] == 0x1D)
				|| (g_sTrf7970Status.ui8FifoBytesReceived == 0x01
						&& g_ui8FifoBuffer[0] == 0xC2)) {
			if (g_sTargetSupportedTechnologies.bits.bPassiveTypeB == 1) {
				g_sTrf7970Status.sTargetMode.bits.bPassiveTypeB = 1;

				sTargetBitrate.bits.b106kpbs = 1;
				TRF797x_switchTargetBaudRate(sTargetBitrate, true);

				// Register 09h. Modulator Control Register - ASK (10 %)
				TRF797x_writeSingle(TRF79X0_MOD_CTRL_MOD_ASK_10,
						TRF79X0_MODULATOR_CONTROL_REG);

//				TRF797x_writeSingle(0x03, TRF79X0_NFC_LOW_DETECTION_LEVEL);
			} else
				ui8Status = STATUS_FAIL_T;
		}
		// Check for ATR_REQ (Active Type A)
		else if (g_sTrf7970Status.ui8FifoBytesReceived
				== (g_ui8FifoBuffer[1] + 1)) {
			if (g_sTargetSupportedTechnologies.bits.bActiveTypeA == 1) {
				g_sTrf7970Status.sTargetMode.bits.bActiveTypeA = 1;
				TRF797x_switchTargetBaudRate(
						g_sTrf7970Status.sTargetPayloadFrequency, true);
			} else
				ui8Status = STATUS_FAIL_T;
		} else
			ui8Status = STATUS_FAIL_T;
	} else if (g_sTrf7970Status.sTargetPayloadFrequency.bits.b212kpbs == 1) {
		// Check for SENSF_REQ (Type F)
		if (g_sTrf7970Status.ui8FifoBytesReceived == 0x06
				&& g_ui8FifoBuffer[0] == 0x06) {
			if (g_sTargetSupportedTechnologies.bits.bPassiveTypeF == 1) {
				g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF = 1;

				sTargetBitrate.bits.b212kpbs = 1;
				TRF797x_switchTargetBaudRate(sTargetBitrate, true);

				// Register 09h. Modulator Control Register - ASK (10 %)
				TRF797x_writeSingle(TRF79X0_MOD_CTRL_MOD_ASK_10,
						TRF79X0_MODULATOR_CONTROL_REG);
			} else
				ui8Status = STATUS_FAIL_T;
		}
		// Check for ATR_REQ (Active Type F)
		else if (g_sTrf7970Status.ui8FifoBytesReceived == g_ui8FifoBuffer[0]) {
			if (g_sTargetSupportedTechnologies.bits.bActiveTypeF == 1) {
				g_sTrf7970Status.sTargetMode.bits.bActiveTypeF = 1;
				TRF797x_switchTargetBaudRate(
						g_sTrf7970Status.sTargetPayloadFrequency, true);

				// Register 09h. Modulator Control Register - ASK (10 %)
				TRF797x_writeSingle(TRF79X0_MOD_CTRL_MOD_ASK_10,
						TRF79X0_MODULATOR_CONTROL_REG);
			} else
				ui8Status = STATUS_FAIL_T;
		} else
			ui8Status = STATUS_FAIL_T;
	} else if (g_sTrf7970Status.sTargetPayloadFrequency.bits.b424kpbs == 1) {
		// Check for SENSF_REQ (Type F)
		if (g_sTrf7970Status.ui8FifoBytesReceived == 0x06
				&& g_ui8FifoBuffer[0] == 0x06) {
			if (g_sTargetSupportedTechnologies.bits.bPassiveTypeF == 1) {
				g_sTrf7970Status.sTargetMode.bits.bPassiveTypeF = 1;

				sTargetBitrate.bits.b424kpbs = 1;
				TRF797x_switchTargetBaudRate(sTargetBitrate, true);

				// Register 09h. Modulator Control Register - ASK (10 %)
				TRF797x_writeSingle(TRF79X0_MOD_CTRL_MOD_ASK_10,
						TRF79X0_MODULATOR_CONTROL_REG);
			} else
				ui8Status = STATUS_FAIL_T;
		}
		// Check for ATR_REQ (Active Type F)
		else if (g_sTrf7970Status.ui8FifoBytesReceived == g_ui8FifoBuffer[0]) {
			if (g_sTargetSupportedTechnologies.bits.bActiveTypeF == 1) {
				g_sTrf7970Status.sTargetMode.bits.bActiveTypeF = 1;
				TRF797x_switchTargetBaudRate(
						g_sTrf7970Status.sTargetPayloadFrequency, true);
			} else
				ui8Status = STATUS_FAIL_T;
		} else
			ui8Status = STATUS_FAIL_T;
	} else {
		ui8Status = STATUS_FAIL_T;
	}

	return ui8Status;
}

/*
 * Setup Target Mode and supported frequencies.
 */
uint8_t TRF797x_targetModeSetup(t_sTRF797x_TargetMode sSupportedModes,
		t_sTRF797x_Bitrate sTargetSupportedFrequency) {
	uint8_t ui8RxBuffer[2];

	// Reset Status Values
	g_sTrf7970Status.ui8FifoBytesReceived = 0x00;
	g_sTrf7970Status.bTxComplete = false;
//	g_sTrf7970Status.bTargetSelected = false;
	g_sTrf7970Status.bRfFieldOn = false;
	g_sTrf7970Status.eCurrentMode = TRF_TARGET_MODE;
	g_sTrf7970Status.sTargetPayloadFrequency.ui16word = 0x0000;
	g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
	g_sTrf7970Status.sInitiatorPayloadFrequency.ui16word = 0x0000;
	g_sTrf7970Status.sInitiatorMode.ui8byte = 0x00;
	g_sTrf7970Status.eIrqFlags = IRQ_STATUS_IDLE;
	g_sTrf7970Status.ui8InternalRssi = 0;
	g_sTrf7970Status.bNfcModeEnabled = false;
	g_sTrf7970Status.bProtocolError = false;

	g_sTargetSupportedTechnologies = sSupportedModes;
	g_sTargetSupportedBitrates = sTargetSupportedFrequency;

	//
	// Soft Init. Command
	//
	TRF797x_directCommand(TRF79X0_SOFT_INIT_CMD);

	//
	// Idle Command
	//
	TRF797x_directCommand(TRF79X0_IDLE_CMD);

	//
	// Register 09h. Modulator Control Register - OOK (100 %) (This helps reduce the time to activate Type A)
	//
	TRF797x_writeSingle(TRF79X0_MOD_CTRL_MOD_OOK_100,
			TRF79X0_MODULATOR_CONTROL_REG);

	//
	// Register 00h. Chip Status Control
	//
	// RF output active
	TRF797x_writeSingle(
			TRF79X0_STATUS_CTRL_RF_ON | TRF79X0_CHIP_STATUS_CTRL_BYTE,
			TRF79X0_CHIP_STATUS_CTRL_REG);

	//
	// Register 01h. ISO Control Register
	//
	// Handle all incoming Technologies (A/B/F) and frequencies (106/212/424)
	TRF797x_writeSingle(0x21, TRF79X0_ISO_CONTROL_REG);

	//
	// Register 0Ah. RX Special Settings
	//
	TRF797x_writeSingle(0xF0, TRF79X0_RX_SPECIAL_SETTINGS_REG);

	//
	// Register 0Bh. Regulator Control
	//
	TRF797x_writeSingle(0x01, TRF79X0_REGULATOR_CONTROL_REG);

	//
	// Register 14h. FIFO IRQ Level
	//
	// RX High = 96 bytes , TX Low = 32 bytes
	TRF797x_writeSingle(0x0F, TRF79X0_FIFO_IRQ_LEVEL);

	//
	// Register 16h. NFC Low Detection Level
	//
	TRF797x_writeSingle(0x03, TRF79X0_NFC_LOW_DETECTION_LEVEL);

	//
	// Register 18h. NFC Target level
	//
	TRF797x_writeSingle(0x07, TRF79X0_NFC_TARGET_LEVEL_REG);

	//
	// Read IRQ Register
	//
	TRF797x_readCont(ui8RxBuffer, TRF79X0_IRQ_STATUS_REG, 2);

	//
	// Read Target NFC Protocol Register
	//
	TRF797x_readSingle(ui8RxBuffer, TRF79X0_NFC_TARGET_PROTOCOL_REG);

	if (ui8RxBuffer[0] & 0x80) {
		g_sTrf7970Status.bRfFieldOn = true;
	}
	GPIO::setExtField(g_sTrf7970Status.bRfFieldOn);

	// Setup AutoSdd Register
	TRF797x_initAutoSdd();

	//
	// Enable Decoder Command
	//
	TRF797x_directCommand(TRF79X0_RUN_DECODERS_CMD);

	return OK;
}

/*
 * Setup Initiator Mode and Initiator frequency.
 */
uint8_t TRF797x_initiatorModeSetup(t_sTRF797x_InitiatorMode sInitiatorMode,
		t_sTRF797x_Bitrate sFrequency) {

	// Reset Status Values
	g_sTrf7970Status.ui8FifoBytesReceived = 0x00;
	g_sTrf7970Status.bTxComplete = false;
	g_sTrf7970Status.bTargetSelected = false;
	g_sTrf7970Status.bRfFieldOn = false;
	g_sTrf7970Status.eCurrentMode = TRF_INITIATOR_MODE;
	g_sTrf7970Status.sTargetPayloadFrequency.ui16word = 0x0000;
	g_sTrf7970Status.sTargetMode.ui8byte = 0x00;
	g_sTrf7970Status.sInitiatorPayloadFrequency = sFrequency;
	g_sTrf7970Status.sInitiatorMode = sInitiatorMode;
	g_sTrf7970Status.eIrqFlags = IRQ_STATUS_IDLE;
	g_sTrf7970Status.ui8InternalRssi = 0;
	g_sTrf7970Status.bNfcModeEnabled = false;
	g_sTrf7970Status.bProtocolError = false;

	TRF797x_switchInitiatorBaudRate(sFrequency, true);

	return OK;
}

#pragma vector = PORT2_VECTOR
__interrupt void TRF797x_IRQ_ISR(void) // interrupt handler
		{
	IRQ_REQ_REG &= ~IRQ_PIN;

	if (g_sTrf7970Status.eCurrentMode == TRF_TARGET_MODE) {
		if (g_sTrf7970Status.bTargetSelected == true) {
			g_ui8IrqFlag = 0x01;
			return;
		} else {
			TRF797x_irqHandler(0);
		}
//		if (TRF797x_irqHandler(0) == IRQ_STATUS_RX_COMPLETE) {
//			RF_anticollisionProcess(g_ui8FifoBuffer, g_sTrf7970Status.ui8FifoBytesReceived);
//		}
	} else {
		g_ui8IrqFlag = 0x01;
	}
}
