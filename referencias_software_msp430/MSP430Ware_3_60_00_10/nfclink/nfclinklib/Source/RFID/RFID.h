/*******************************************************************************
* @file    RFID.h
* @brief
* @version V0.0.1
* @date    01/12/2012
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


#ifndef RFID_H
#define RFID_H

#include "hardware.h"
#include "buffer.h"
#include <stdint.h>
#define RFID_VERSION_STR  "RFID_v2.0"
#define RFID_VERSION_LENGTH 9


class RFID {
public:
	static byte bitFrame;

	//SystemCall
	static word Call(word opcode, byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
	static word Call(word opcode, byte s1, word s2);
	static word Call(word opcode, byte s1);

	static void Timing(byte type, word value);
    static int run();
    static bool isProtocolError;
//    static bool isTXfinish;
//
//    static bool isTargetActivated;
//    static bool isRFFieldOn;
    static void callbackInit(bool (*callback)());
	static void SetupFrame(byte mode);
	static bool callback();
    static bool (*callbackFunction)();

    static void anticollisionProcess(byte *sendbuf, byte length);

private:
//


    static bool functionDummy();

	static bool isNFCActive;
    static bool isTargetSelected;
//     static void setHigherBaudrate();

//     static bool LongFrameFlag;
	static bool isRxMultiple;
//     //static bool isNFC_Passive_Target;
	static byte current_frame_type;
	static byte current_frame_param;
//     static byte baud;
//
	static byte BitCollision();
//
	static word Init(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
	static word version(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
	static word setTimeouts(byte *sendbuf, word sendlen);
	static word transceive(byte cmd, byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
	static void calcFifoLen(byte sendlen, byte bitFrameCount, byte &highByte, byte &lowByte);
	static void HFField(char state);
	static void FieldReset(word msec);

	static word FrameType(byte option, byte param);
	static void Setup14443A_Bitframe(byte sendlen);
	static void Setup14443A_Byteframe();
//     static void Setup14443B_Byteframe();
     static word baudrate_air(byte baudrate);
//     static bool WaitModemState(byte state, word timeout);
//     static void SetupNFC_Byteframe();
//     static void SetupFELICA_Byteframe();
//     static void ClearBits(byte adr, byte mask);
//     static void SetBits(byte adr, byte mask);

//     static byte AACC();
    static word readMailbox(byte *recbuf, word &reclen);
	static word control(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word modeDetection(byte *recbuf, word &reclen);
//     static word checkPON(byte *recbuf, word &reclen);
     static word checkTargetActivated(byte *recbuf, word &reclen);
//
//    //This functions are in the file RFID_TestCases.cpp and used to test and debug parts of the RFID Layer and other functions
//    static void SpiStressTest(byte *sendbuf, word sendlen, byte *recbuf, word reclen); //function found in Sample Folder!
//    static void RegisterReadOut(byte *sendbuf, word sendlen, byte *recbuf, word reclen); //Reads all necessary Register from PN512
//
//     static bool firstRun;
//
     //AAC configuration and sub methods
     static word aacConfiguration(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgLnNfcDep(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgLfConBitrF(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgLfAdvFeat(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgLfProtocolType(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgLfT3tIdentifier(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgLfT3tFlags(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word getLfT3tMax(word sendlen, byte *recbuf, word &reclen);
     static word sgAfi(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word setPupi(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgAtqb(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgSysCode(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgNfcid2(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgSelRes(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgNfcid1(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgSensRes(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgPadding(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);

     // Not implemented
     static word sgProtSel(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
     static word sgNfcid3(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);


     struct _AAC;
     static _AAC AACconfig;

     static Array<10> nfcid1;
     static Array<8>  nfcid2;

     static byte stmReceiveMode;

#define	RCV_IDLE			0
#define	RCV_SDD_COMPLETE	1
#define	RCV_TX_FINISH_IRQ	2
#define	RCV_RX_IRQ			3
#define	RCV_STOP			4
#define	RCV_RECEIVING		5



};

//
// TRF797x0 Modes Settings
//

typedef enum
{
   TRF_IDLE_MODE = 0,
   TRF_INITIATOR_MODE,
   TRF_TARGET_MODE
} tTRF797x_Mode;

typedef union
{
    struct {
    	uint8_t bPassive15693  	: 1;
    	uint8_t bPassiveTypeA  	: 1;
    	uint8_t bPassiveTypeB  	: 1;
    	uint8_t bPassiveTypeF  	: 1;
    	uint8_t bActiveTypeA  	: 1;
    	uint8_t bActiveTypeF  	: 1;
        /*! Reserved bits         */
    	uint8_t reserved   		: 2;
    }bits;
    /*! Whole status byte access */
    uint8_t     ui8byte;
}t_sTRF797x_InitiatorMode;

typedef union
{
    struct {
    	uint8_t bPassiveTypeA  	: 1;
    	uint8_t bPassiveTypeB  	: 1;
    	uint8_t bPassiveTypeF  	: 1;
    	uint8_t bActiveTypeA  	: 1;
    	uint8_t bActiveTypeF  	: 1;

        /*! Reserved bits         */
    	uint8_t reserved   : 5;
    }bits;
    /*! Whole status byte access */
    uint8_t     ui8byte;
}t_sTRF797x_TargetMode;

typedef union
{
    struct {
    	// Target and Initiator Bitrates
    	// ISO1443A / ISO1443B
    	uint16_t b106kpbs  				: 1;
    	// ISO1443A / ISO1443B / FeliCa
        uint16_t b212kpbs 				: 1;
        // ISO1443A / ISO1443B / FeliCa
        uint16_t b424kpbs 				: 1;
        // Initiator Bitrates Only
        // ISO1443A / ISO1443B
        uint16_t b848kpbs 				: 1;
        // 15693 Bit-Rates
        uint16_t b6_62_kbps_1_out_4 	: 1;
        uint16_t b6_62_kbps_1_out_256 	: 1;
        uint16_t b26_48_kbps_1_out_4 	: 1;
        uint16_t b26_48_kbps_1_out_256 	: 1;
        uint16_t b6_67_kbps_1_out_4 	: 1;
        uint16_t b6_67_kbps_1_out_256 	: 1;
        uint16_t b26_69_kbps_1_out_4 	: 1;
        uint16_t b26_69_kbps_1_out_256 	: 1;
        /*! Reserved bits         */
        uint16_t reserved     			: 4;
    }bits;
    /*! Whole status word access */
    uint16_t     ui16word;
}t_sTRF797x_Bitrate;

//
// CRC Settings for TRF797x_
//
typedef enum
{
	CRC_BIT_DISABLE = 0,						// TX CRC Disabled
	CRC_BIT_ENABLE								// TX CRC Enabled
} tTRF797x_CRC;

//
// External Field Settings for TRF797x_
//
typedef enum
{
	EXT_FIELD_OFF = 0,						// External Field Off
	EXT_FIELD_ON							// External Field On
} tExtField;

//
// RSSI Settings for testing internal/external RF strengths.
//
typedef enum
{
	INTERNAL_RSSI = 0,						// Internal RSSI
	EXTERNAL_RSSI							// External RSSI
} tRssiStatus;

//
// IRQ Flag definitions.
//
typedef enum
{
    IRQ_STATUS_IDLE = 0x00,
    IRQ_STATUS_COLLISION_ERROR = 0x01,
    IRQ_STATUS_COLLISION_AVOID_FINISHED = 0x02,
    IRQ_STATUS_RF_FIELD_CHANGE = 0x04,
    IRQ_STATUS_SDD_COMPLETE = 0x08,
    IRQ_STATUS_PROTOCOL_ERROR = 0x10,
    IRQ_STATUS_FIFO_HIGH_OR_LOW  = 0x20,
    IRQ_STATUS_RX_COMPLETE = 0x40,
    IRQ_STATUS_TX_COMPLETE = 0x80,
    IRQ_STATUS_NO_RESPONSE = 0xFE,
    IRQ_STATUS_TIME_OUT = 0xFF
} tTRF797x_IRQFlag;

//
// IRQ NFC Flag definitions.
//
typedef enum {
	IRQ_STATUS_NFC_COLLISION_ERROR = 0x01,
	IRQ_STATUS_NFC_COLLISION_AVOID_FINISHED = 0x02,
	IRQ_STATUS_NFC_RF_FIELD_CHANGE = 0x04,
	IRQ_STATUS_NFC_SDD_COMPLETE = 0x08,
	IRQ_STATUS_NFC_PROTOCOL_ERROR = 0x10
}tTRF797x_NFCFlag;

//
// IRQ RFID Flag definitions.
//
typedef enum {
	IRQ_STATUS_RFID_NO_RESPONSE_INT = 0x01,
	IRQ_STATUS_RFID_COLLISION_ERROR = 0x02,
	IRQ_STATUS_RFID_FRAMING_OR_EOF_ERROR = 0x04,
	IRQ_STATUS_RFID_PARITY_ERROR = 0x08,
	IRQ_STATUS_RFID_CRC_ERROR = 0x10
}tTRF797x_RFIDFlag;

//
// TRF7970A Status Register
//
typedef struct
{
	uint8_t ui8FifoBytesReceived;		// Bytes Received
	bool bTxComplete;					// Transmission Complete
	bool bTargetSelected;				// Target Selected
	bool bRfFieldOn;					// RF Field Status
	bool bProtocolError;				// Protocol Error
	bool bNfcModeEnabled;				// Use to differentiate between Reader/NFC Modes
	tTRF797x_Mode eCurrentMode;			// Target / Initiator / Idle
	// Target Bitrate
	t_sTRF797x_Bitrate sTargetPayloadFrequency;
	// Passive / Active Types A / B (not active) / F
	t_sTRF797x_TargetMode sTargetMode;
	// Initiator Bitrate
	t_sTRF797x_Bitrate sInitiatorPayloadFrequency;
	// Passive / Active Types A / B (not active) / F / 15693 (not active)
	t_sTRF797x_InitiatorMode sInitiatorMode;
	// IRQ Status
	tTRF797x_IRQFlag eIrqFlags;
	// Internal RSSI
	uint8_t ui8InternalRssi;
}tTRF797x_Status;

typedef enum
{
	STATUS_SUCCESS_T = 0,
	STATUS_FAIL_T

}status_;

extern volatile uint8_t g_ui8IrqFlag;

void TRF797x_setup(void);
void TRF797x_directCommand(uint8_t ui8Command);
void TRF797x_rawWrite(uint8_t *pui8Payload, uint8_t ui8Length);
void TRF797x_readSingle(byte *pui8Payload, uint8_t ui8Register);
void TRF797x_readCont(byte *pui8Payload, uint8_t ui8Register, uint8_t ui8Length);
void TRF797x_writeSingle(byte ui8Value, uint8_t ui8Register);
void TRF797x_writeCont(byte *pui8Payload, uint8_t ui8Register, uint8_t ui8Length);

void TRF797x_resetFIFO(void);

void TRF797x_setP2PTargetFlag(bool bTargetFlag);
void TRF797x_setP2PInitiatorFlag(bool bInitiatorFlag);

void TRF797x_displayMode(void);

// New APIs

uint8_t TRF797x_resetMode(void);
uint8_t * TRF797x_getNfcBuffer(void);
tTRF797x_Status TRF797x_getStatus(void);
void TRF797x_setAutoSdd(uint8_t * pui8TargetId, uint8_t ui8IdLength, bool bNfcDep, bool bIsoDep);
void TRF797x_initAutoSdd(void);
void TRF797x_disableAutoSdd(void);

void TRF797x_setTargetSelect(bool bTargetStatus);
void TRF797x_setNfcMode(bool bNfcMode);

uint8_t TRF797x_writeFIFO(
	uint8_t *pui8Payload,
    tTRF797x_CRC eCRCBit,
	uint8_t ui8Length,
	uint8_t ui8BrokenBits
	);
tTRF797x_IRQFlag TRF797x_irqHandler(uint16_t ui16TimeOut);
uint8_t TRF797x_switchTargetBaudRate(
	t_sTRF797x_Bitrate sTargetFrequency,
	bool bModifyRegister
	);
uint8_t TRF797x_incrementTargetBaudRate(
	t_sTRF797x_Bitrate sTargetFrequency
	);
uint8_t TRF797x_switchInitiatorBaudRate(
	t_sTRF797x_Bitrate sInitiatorFrequency,
	bool bModifyRegister
	);
uint8_t TRF797x_incrementInitiatorBaudRate(
	t_sTRF797x_Bitrate sInitiatorFrequency
	);
// TODO check if needed?
uint16_t TRF797x_getCollisionStatus(void);
uint8_t TRF797x_setField(tExtField eRfField);
uint8_t TRF797x_checkField(tRssiStatus eField);
word TRF797x_checkExternalField(void);
uint8_t TRF797x_idleMode(void);
uint8_t TRF797x_targetInitialize(void);
uint8_t TRF797x_targetModeSetup(
	t_sTRF797x_TargetMode sSupportedModes,
	t_sTRF797x_Bitrate sTargetSupportedFrequency);
uint8_t TRF797x_initiatorModeSetup(
	t_sTRF797x_InitiatorMode sInitiatorMode,
	t_sTRF797x_Bitrate sFrequency);

#endif //RFID_h
