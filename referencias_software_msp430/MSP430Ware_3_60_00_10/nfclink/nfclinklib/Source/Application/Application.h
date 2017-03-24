/*
 * Application.h
 *
 *  Created on: 20.09.2012
 *      Author: A
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_


/*******************************************************************************
* Company specific Stack version
*******************************************************************************/
#define MANUF_ID                        0x07

/* Company specific defines */
#define NCI_TEXAS_INSTRUMENTS           0x08

#define MANUF_SPEC_INF1                 NCI_TEXAS_INSTRUMENTS    //Company Specific
#define MANUF_SPEC_INF2                 0x01    //Major Release Version (Alpha, Beta, Release...)
#define MANUF_SPEC_INF3                 0x00    //Minor update Version
#define MANUF_SPEC_INF4                 0x3C    //Minor update Version (Incremented on every update)
/*******************************************************************************/

#define FW_VERSION        "TA 1.04.11"
#define FW_VERSION_LENGTH   10

#define FW_INTERMEDIATE_VERSION         "TA 1.04.10 - VI 00"
#define FW_INTERMEDIATE_VERSION_LENGTH  (unsigned char)18
/*******************************************************************************/

//#define NCI_CARD_EMULATION_ONLY			//TagActivity
//#define NCI_READER_WRITER_ONLY				//ListenModeHandler, Configurations, ...
//#define NCI_PEER_TO_PEER_ONLY				//
/*******************************************************************************/

#define BINARY_V2   //use new protocol with appended reclen for HW Tests

#define NO_TAGABSTRACTION
#define NO_MIFARE_CMD

#define NO_ICODE_UID
#define NO_SRT
#define NO_EXTENDED_COMMANDS_CLASS
#define NO_EXTENDED_COMMANDS
#define NO_SAM
#define NO_KEYHANDLER
#define NO_SAM
#define HCI_NCI
#define _NCI
//#define NO_TAG_ACTIVITY

//#define NO_ISO14443A
//#define NO_ICODE
//#define NO_FELICA
//#define NO_ISO14443B


#define NO_SRT
#define NO_ICODE_UID
#define NO_ICODE_UID
//#define NO_NFC

//#define NO_CARDEMULATION

#define NO_TAGDETECTION
#define NO_OKLED
//#define BINARYCOMMAND_LAYER

//#define CARD_EMU

//#define _DEBUG_PRINT_ON
//#define NCI_DEBUG_OUTPUT




#define CHECK(func) func
#define RETURN_CHECK(func) return func

class Application
{
public:
     static void init();
     static void run();
};


#endif /* APPLICATION_H_ */
