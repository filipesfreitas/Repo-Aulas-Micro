#ifndef API_INTERN_H
#define API_INTERN_H

#define BOOTLOADER_FLAG_LOCATION    (byte)0xE0
#define BOOTLOADER_FLAG_LOCATION_PSION (byte)0xA0
#define CARD_EMULATION			0x35

#define CARD_EMULATION_A 		0x31
#define CARD_EMULATION_B		0x32
#define CARD_EMULATION_AB		0x33
#define CARD_EMULATION_F 	 	0x34
#define CARD_EMULATION_AF  		0x35
#define CARD_EMULATION_BF		0x36
#define CARD_EMULATION_ABF		0x00


/**
*<b>MIFARE specific defines<b>
*@see AN10856 NXP Semiconductors
*/
//commands
#define CMD_REQA    	        (unsigned char)0x26
#define CMD_WUPA    	        (unsigned char)0x52
#define CMD_HALT    	        (unsigned char)0x50
#define CMD_READ    	        (unsigned char)0x30
#define CMD_WRITE   	        (unsigned char)0xA2
#define CMD_COMPATIBILITY_WRITE (unsigned char)0xA0
#define CMD_RATS   	            (unsigned char)0xE0
#define CMD_PPS	    	        (unsigned char)0xD0
#define CMD_HOST    	        (unsigned char)0x19

//ACK/NAK
#define NAK_ACC    	            (unsigned char)0x00
#define NAK_CRC   	            (unsigned char)0x01
#define NAK_TRA                 (unsigned char)0x04
#define NAK_PAR                 (unsigned char)0x05
#define ACK_ACK                 (unsigned char)0x0A

/**
*FELICA specific defines
*
*/
#define CMD_POLL	    (unsigned char)0x00
#define CMD_POLL_RES	(unsigned char)0x01
#define CMD_CHECK   	(unsigned char)0x06
#define CMD_CHECK_RES	(unsigned char)0x07
#define CMD_UPDATE	    (unsigned char)0x08
#define CMD_UPDATE_RES	(unsigned char)0x09
#define CMD_REQ_SYS	    (unsigned char)0x0c
#define CMD_REQ_SYS_RES	(unsigned char)0x0d

/**
* ISO/IEC 7816 specific defines
*/

/**
* ISO/IEC 14443-B specific defines
*/
#define CMD_ATTRIB      (unsigned char)0x1D



/**
*<b>NDEF parser opcodes and defines</b>
*/
#define NDEF_RECORD     (unsigned short)0x0801
#define NDEF_MESSAGE    (unsigned short)0x0802

enum
{
    //LLC Error Codes
    ERR_NO_READERREPLAY         = 0xFFEF,
    ERR_ERROR_CODE		        = 0xFFEE, //not used
    ERR_WRONG_DATA              = 0xFFED,
    ERR_NO_TARGET               = 0xFFEC,
    ERR_CONNECTION_FAILED       = 0xFFEB,
    ERR_I_PDU_REJECTED          = 0xFFEA, //not used
    ERR_EMPTY_SYMM_PDU          = 0xFFE9,
    ERR_SELECT_NO_TAG           = 0xFFE8, //not used
    ERR_SELECT_INVALID_DATALEN  = 0xFFE7, //not used
    ERR_SELECT_INVALID_TAGTYPE  = 0xFFE6, //not used
    ERR_ATR_NO_TAG              = 0xFFE5,
    ERR_ATR_INVALID_DATALEN     = 0xFFE4,
    ERR_ATR_INVALID_DATA        = 0xFFE3,
    ERR_CONNECT_NO_TAG          = 0xFFE2,
    ERR_CONNECT_INVALID_DATALEN = 0xFFE1,
    ERR_CONNECT_INVALID_DATA    = 0xFFE0,
    ERR_SENDFRAME_NO_TAG        = 0xFFDF,
    ERR_CALL_INVALID_OPCODE     = 0xFFDE,
    ERR_LLC_CALL_OPCODE         = 0xFFDD,
    ERR_LLC_CALL_BUFFER_FULL    = 0xFFDC,
    ERR_LLC_CALL_BUFFER_EMPTY   = 0xFFDB,
    ERR_SW_BUG                  = 0xFFDC,
    CONNECTION_ALREADY_ESTABLISHED  = 0xFFDA, //not used
    CONNECTION_ESTABLISHED      = 0xFFD9,
    CONNECTION_NOT_ESTABLISHED  = 0xFFD8,
    CONNECTION_CLOSED           = 0xFFD7, //not used
    CONNECTION_NOT_CLOSED       = 0xFFD6, //not used
    CONNECTION_ERROR_UNKNOWN    = 0xFFD5, //not used
    CONNECTION_ERROR_NO_TAG     = 0xFFD4,  //not used
    
    EMPTY_SYMM_RECEIVED         = 0x0010
};

enum
{
  //NDEF parser ERROR codes
  ERR_WRONG_ID_LENGTH           = 0xFFAF,
  ERR_WRONG_TYPE                = 0xFFAE,
  ERR_TLV_LENGTH                = 0xFFAD
};

#endif //API_INTERN_H
