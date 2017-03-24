#ifndef READER_API_H_
#define READER_API_H_
/*******************************************************************************
* @file     API.h
* @brief    Containing all opcodes for the API interface
* @author   Florian Puffer
* @version  V0.0.4
* @date     01/02/2014
* @details  This class provides the opcode for the API. Also containing error
* codes and several necessary defines.
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

//#include "API_intern.h"
#include "defines.h"
//#include "NCI_API.h"

//#include "hardware.h"
//API.h
// opcodes for API Interface

// Bit coding of opcodes
// The opcode is defined as word value (16Bit)
// The higher byte defines the sevice (RFID, SAM, TAG, HW)
// The lower byte defines the methode (SelectTag (TAG), Read(TAG), SPI(HW), SAM_Init(SAM))

// #define EEPROM_PAGE_NUMBER          (256U)
// #define EEPROM_PAGE_SIZE_BYTE       (128U)
// #define EEPROM_PAGE_SIZE_DWORD      (EEPROM_PAGE_SIZE_BYTE / 4U)
// #define EEPROM_START_ADDR           (0x10000000U)
// #define EEPROM_FILE1_ID             (1U)
// #define EEPROM_FILE2_ID             (2U)
// #define EEPROM_FILE3_ID             (3U)
// #define EEPROM_FILE4_ID             (4U)
// #define EEPROM_FILE5_ID             (5U)
// #define EEPROM_FILE1_PAGE_NUMBER    (4U)
// #define EEPROM_FILE2_PAGE_NUMBER    (12U)
// #define EEPROM_FILE3_PAGE_NUMBER    (5U)
// #define EEPROM_FILE4_PAGE_NUMBER    (0U)
// #define EEPROM_FILE5_PAGE_NUMBER    (EEPROM_PAGE_NUMBER)
// #define EEPROM_FILE1_START_ADDR     (0x10000D80U)
// #define EEPROM_FILE2_START_ADDR     (0x10000F80U)
// #define EEPROM_FILE3_START_ADDR     (0x10001580U)
// #define EEPROM_FILE4_START_ADDR     (0x10000000U)
// #define EEPROM_FILE5_START_ADDR     (0x10000000U)
// #define EEPROM_FILE1_SIZE           (EEPROM_PAGE_SIZE_BYTE * EEPROM_FILE1_PAGE_NUMBER)
// #define EEPROM_FILE2_SIZE           (EEPROM_PAGE_SIZE_BYTE * EEPROM_FILE2_PAGE_NUMBER)
// #define EEPROM_FILE3_SIZE           (EEPROM_PAGE_SIZE_BYTE * EEPROM_FILE3_PAGE_NUMBER)
// #define EEPROM_FILE4_SIZE           (EEPROM_PAGE_SIZE_BYTE * EEPROM_FILE4_PAGE_NUMBER)
// #define EEPROM_FILE5_SIZE           (EEPROM_PAGE_SIZE_BYTE * EEPROM_FILE5_PAGE_NUMBER)

#define INTERFACE_BUFFER_SIZE       (264UL)

#define HOST_INTERFACE HW_DH_INTERFACE

#define RS232_BUFFSIZE 261 //5 byte header/tail + 256 data bytes

/** Defines the maximum Buffersize and is also used for reclen. DO NOT CHANGE */
#define MAX_BUFFER_SIZE 260 //Defines the buffer size of the receiving buffer,
#define MAX_RECLEN      254 //Max Payload size of data which can be received at FW layer

/********************************************************
** Opcodes of Service Types                            **
********************************************************/
#define API_HW                          0x0000  //hardware layer service
#define API_RFID                        0x0100  //RFID layer services
#define API_API                         0x0200
#define API_SAM                         0x0400
#define API_NFC                         0x0800  //NFC LCC layer specified by NFC forum
#define API_Mask                        0x0F00
#define API_HCI                         0x1000

/********************************************************
** Hardware Service Types                              **
********************************************************/
#define HW_VERSION                      (API_HW|0x01) /* The version number of the hardware abstraction. */
#define HW_ID                           (API_HW|0x02) /* The ID number of the µC. */

#define HW_STATUS                       (API_HW|0x03) /* Returns the HAL internal state (Booting, normal, off, etc) */
  #define OSCILLATOR_STATUS             0x01
  #define SWP1_PWR_STATUS               0x02
  #define BATT_PWR_STATUS               0x03
  #define WKP_PIN_STATUS                0x04
  #define WKP_SOURCE                    0x05
    #define WKP_SRC_DH                          0x00
    #define WKP_SRC_RF                          0x01
    #define WKP_SRC_SOFTWARE                    0x02
    #define WKP_SRC_WATCHDOG                    0x03
    #define WKP_SRC_PON                         0x10
  #define SLP_WKP_SOURCE                0x06
  #define SE3_SELECTION                 0x08
  #define LMRT_CHANGE                   0x09
    #define VALID_ROUTE_CHANGE                  0x01
    #define SET_ROUTES_NEUTRAL                  0x02
  #define PWR_STATES                    0x0A

/* µC internal */
#define HW_TICKS32                      (API_HW|0x04) /* Gets the timer value. */
#define HW_WATCHDOG                     (API_HW|0x05) /* Gets and sets the watchdog timer. */
#define HW_CLEAR_WTD                    (API_HW|0x06) /* Clear the watchdog. */
#define HW_RESET                        (API_HW|0x07) /* Reset the Contactless Frontend. */
#define HW_SET_BOOT_FLAG                (API_HW|0x08) /* Sets Bootflag to start the bootloader after reset. */
#define HW_CRC32                        (API_HW|0x09)
#define HW_EEPROM_READ                  (API_HW|0x0A)
#define HW_EEPROM_WRITE                 (API_HW|0x0B)

/* peripherie */
#define HW_USER_PORT                    (API_HW|0x0C)
#define HW_IO_SET                       (API_HW|0x0D)
#define HW_IO_DIRECTION                 (API_HW|0x0E)
#define HW_IO_GET                       (API_HW|0x0F)
#define HW_BUZZER                       (API_HW|0x10)
#define HW_STATUS_LED                   (API_HW|0x11)

/* SerialInterface for SAM */
#define HW_UART                         (API_HW|0x14)
#define HW_SAM1                         (API_HW|0x15)
#define HW_SAM2                         (API_HW|0x16)
#define HW_SAM3                         (API_HW|0x17)
#define HW_SAM4                         (API_HW|0x18)
#define HW_SAM                          (API_HW|0x19)

/* interface for RF reader chip	*/
#define HW_RC                           (API_HW|0x1B)
#define HW_RC_RESET                     (API_HW|0x1C)

/* debuging interface */
#define HW_DEBUG_READ                   (API_HW|0x20)
#define HW_DEBUG_WRITE                  (API_HW|0x21)

/* I2C interface */
#define HW_I2C_READ                     (API_HW|0x25)
#define HW_I2C_WRITE                    (API_HW|0x26)

/* SPI interface */
#define HW_SPI_WRITE                    (API_HW|0x27)
#define HW_SPI_READ                     (API_HW|0x28)
#define HW_SPI_CS                       (API_HW|0x29)
#define HW_SPI_INIT                     (API_HW|0x2A)

/* serial number */
#define HW_GET_SERIAL_NUMBER            (API_HW|0x2B)
#define HW_SET_SERIAL_NUMBER            (API_HW|0x2C)

/* ADC antenna voltage */
#define HW_ANTENNA_VOLTAGE              (API_HW|0x2E)

/* storage */
#define HW_FILE                         (API_HW|0x2F)

/* power managment */
#define HW_POWER_MANAGMENT              (API_HW|0x30)
#define HW_STOP                         (API_HW|0x31)
#define HW_SLEEP                        (API_HW|0x32)
#define HW_WAKEUP                       (API_HW|0x3B)

/* SWP interace */
#define HW_SWP1                         (API_HW|0x31)
#define HWB_SWP1                        (0x31)
#define HW_SWP2                         (API_HW|0x32)
#define HWB_SWP2                        (0x32)
#define HW_SWP3                         (API_HW|0x34)
#define HWB_SWP3                        (0x34)

/* SPI Host Interface */
#define HW_SPI                          (API_HW|0x41)

/* I2C Host Interface */
#define HW_I2C                          (API_HW|0x51)

/* General HW_Control Register to set and change the settings of the interfaces. */
#define HW_CONTROL                      (API_HW|0x61)

#define HW_DH_WKP_GPIO                  0x20 //HW Control to set and clear the IO for DH wakeup notification
  #define SET_DH_WKP                    0x01
  #define CLEAR_DH_WKP                  0x00

/* SPE Host Interface */
#define HW_SPE                          (API_HW|0x71)

/* DCLB Interface */
#define HW_DCLB                         (API_HW|0x3A)
#define DCLB_DCSEL                      (0x01)
#define DCLB_RFTECHSEL                  (0x02)
#define DCLB_TXACT                      (0x03)
#define DCLB_ISR                        (0x04)

/* SPI Extended Interface */
#define SPI_EXT                         (API_HW|0x3B)
#define SPI_EXT_ACTIVATE                (0x05)
#define SPI_EXT_STATUS                  (0x06)
#define SPI_EXT_CONN_ID                 (0x07)
#define SPI_PROT_ACTIVE                 (byte)0x3B

/* HW_POWERSAVE */
#define HW_POWERSAVE                    (API_HW|0x80)
#define STANDBY                         0x00
#define DEEP_SLP                        0x01

/* HW_CONTROL -> HW_CLOCK */
#define HW_CLOCK                        0x01
#define POWER_LOW                       0x01
#define POWER_MIDDLE                    0x02
#define POWER_HIGH                      0x03
#define POWER_TURBO                     0x04
#define POWER_STATUS                    0x08

/**/
#define HW_HOST_INTERFACE               (API_HW|0x81)
#define HW_CHANGE                       (API_HW|0x82)
#define HW_DH_INTERFACE                 (API_HW|0x83)


/* For test purpose, the implementation can be changed  */
#define HW_TEST                         (API_HW|0xFE)

/*******************************************************
** Hardware sub-opcodes                               **
**                                                    **
** project-specific HW-Calls:                         **
** The range (API_HW|0xC0) to (API_HW|0xFF) is        **
** reserved for project-specific  HW-Calls. These are **
** defined in a separate file.                        **
********************************************************/

/* Actions */
#define INIT			                0x00
#define START			                0x01
#define STOP			                0x02
#define SET_PIN			                0x03
#define CLEAR_PIN		                0x04

/* Filehandler */
#define HW_FILE_1                       0x01
#define HW_FILE_2                       0x02
#define HW_FILE_3                       0x03
#define HW_FILE_4                       0x04
#define HW_FILE_5                       0x05

#define GET_FILE_ID                     0x00
#define GET_FILE_INFO                   0x01
#define WRITE_FILE                      0x02
#define READ_FILE                       0x03
#define ERASE_FILE                      0x04
#define ERASE_PAGE                      0x05

/* HW_CONTROL */
#define HWC_CLOCK                       0x01
#define HWC_SPI                         0x41
#define HWC_I2C                         0x51
//#define HWC_DLCB                      0x38
//#define HWC_SAM                       0x19
#define HWC_UART                        0x14



/**
* Power Managemement
*/
#define RF_DETECTION_WAKEUP             (word)0x0001
#define PWRM_LOAD_NCI_CONFIG            (word)0x0002

enum SPI {
  SPI_CLOCK           = 0x01,
  SPI_PRESCALER       = 0x02,
  SPI_FRAMETYPE       = 0x03,
  SPI_BAUDRATE        = 0x04,
  SPI_DATASIZE        = 0x05,
  SPI_PHASE           = 0x06,
  SPI_POLARITY        = 0x07,
  SPI_MASTERSLAVE     = 0x08,
  SPI_ENABLE          = 0x09,
  //SPI_DMA           = 0x0A, RFU
  SPI_STATUS          = 0x0B,
  //SPI_INT_ENABLE    = 0x0C, RFU
  SPI_SE3_CLOCK       = 0x0D,
  SPI_SE3_PRESCALER   = 0x0E,
  //SPI_TX_LENGTH     = 0x0F, RFU
  //SPI_RX_LENGTH     = 0x10, RFU
  SPI_EDC_ENABLE      = 0x11,
  //SPI_EDC_OFFSET    = 0x12, RFU
  SPI_EDC_DATA        = 0x13
  //SPI_INT_ENABLE2   = 0x14, RFU
};

enum I2C {
  I2C_CLOCK           = 0x01,
  I2C_ENABLE          = 0x02,
  I2C_MASTERSLAVE     = 0x03,
  I2C_BAUDRATE        = 0x04,
  I2C_MASTER_10B_ADDR = 0x05,
  I2C_SLAVE_10B_ADDR  = 0x06,
  I2C_RESTART         = 0x07,
  I2C_TARGET_ADDR     = 0x08,
  I2C_SLAVE_ADDR      = 0x09,
  I2C_STOP_BIT        = 0x0A,
  I2C_RX_FIFO_TRESH   = 0x0B,
  I2C_TX_FIFO_TRESH   = 0x0C,
  //I2C_DMA_ENABLE      = 0x0D,
  //I2C_DMA_TX_LVL      = 0x0E,
  //I2C_DMA_RX_LVL      = 0x0F,
  I2C_GENERAL_CALL    = 0x10,
  I2C_HS_MASTER_ADDR  = 0x11,
  I2C_SS_SCL_HCNT     = 0x12,
  I2C_SS_SCL_LCNT     = 0x13,
  I2C_FS_SCL_HCNT     = 0x14,
  I2C_FS_SCL_LCNT     = 0x15,
  I2C_HS_SCL_HCNT     = 0x16,
  I2C_HS_SCL_LCNT     = 0x17,
  //I2C_INT_ENABLE      = 0x18,
  I2C_STATUS          = 0x19,
  I2C_TX_FIFO_LVL     = 0x1A,
  I2C_RX_FIFO_LVL     = 0x1B,
  I2C_SDA_HOLD        = 0x1C,
  I2C_SDA_SETUP       = 0x1D,
  I2C_ABORT_SOURCE    = 0x1E,
  I2C_NACK_ENABLE     = 0x1F,
  I2C_ENABLE_STATUS   = 0x20,
  I2C_SPIKE_SS_FS     = 0x21,
  I2C_SPIKE_HS        = 0x22
};

enum SWP {
  SWP_CLOCK           = 0x01,
  SWP_RESET           = 0x02,
  SWP_BAUDRATE        = 0x03,
  SWP_RX_STATUS       = 0x04,
  SWP_TX_STATUS       = 0x05,
  SWP_ACTIVATE        = 0x06,
  SWP_SYNC_ID         = 0x07,
  SWP_CLT_ACTIVATE    = 0x08,
  SWP_SUBSEQUENT_DEACTIVE = 0x10,
};

enum UART {
  UART_CLOCK          = 0x01,
  UART_PRESCALER      = 0x02,
  UART_BAUDRATE       = 0x03,
  UART_DATA           = 0x04,
  //UART_FIFO_ENABLE    = 0x05,
  UART_STOP_BIT       = 0x06,
  UART_PARITY_ENABLE  = 0x07,
  UART_PARITY         = 0x08,
  UART_CTS_ENABLE     = 0x09,
  UART_RTS_ENABLE     = 0x0A,
  UART_RX_ENABLE      = 0x0B,
  UART_TX_ENABLE      = 0x0C,
  UART_GUART_ENABLE   = 0x0D,
  //UART_FIFO_LVL       = 0x0E,
  //UART_DMA            = 0x0F,
  UART_DATA_STATUS    = 0x10,
  UART_RX_STATUS      = 0x11,
  UART_FLAG_STATUS    = 0x12,
  UART_STICK_PARITY   = 0x13
  //UART_TX_BREAK       = 0x14,
  //UART_REQ_TO_SEND    = 0x15,
  //UART_DATA_TO_RECEIVE = 0x16,
  //UART_INT_ENABLE     = 0x17,
};


//---------------------------------------------------------------------------------------
//					     RFID
//---------------------------------------------------------------------------------------

//ProtocolTypes
#define NO_TAG_MODE                     0xFF
#define ISO14443A_BYTEFRAME             0x00
#define ISO14443A_BITFRAME              0x01
#define ISO14443B_BYTEFRAME             0x02
//#define ISO14443B_Bitframe            0x03  //doesn't exist
#define FELICA_BYTEFRAME                0x04
#define KOVIO_BARCODE_BYTEFRAME         0x05
#define GTML_BYTEFRAME                  0x06
#define GTML_BITFRAME                   0x07
#define NFC_TARGET_PASSIVE              0x08
#define NFC_INITIATOR_ACTIVE            0x09

#define ISO15693_BYTEFRAME              0x0B
#define ICODEUID_MODE                   0x0C
#define ICODE1_STANDARDMODE             0x0D
#define ICODE1_FASTMODE                 0x0E
#define ISO14443A_MODE                  0x0F
#define NFC_TARGET_ACTIVE               0x10
#define TOPAZ_FRAMETYPE					0x11

#define NFC_TARGET_ACTIVE               0x10
  #define LISTEN_A_ACTIVE                 0x70
  #define LISTEN_F_ACTIVE                 0xB0

#define NFC_TARGET_PASSIVE              0x08
  #define LISTEN_A_PASSIVE                0x31
  #define LISTEN_B_PASSIVE                0x32
  #define LISTEN_AB_PASSIVE               0x33
  #define LISTEN_F_PASSIVE                0x34
  #define LISTEN_AF_PASSIVE               0x35
  #define LISTEN_BF_PASSIVE               0x36
  #define LISTEN_ABF_PASSIVE			  0x37

//RFID Service Types
//Frame Level Services
#define RFID_INIT                       (API_RFID|0x00)
#define RFID_VERSION                    (API_RFID|0x01)
#define RFID_TRANSCEIVE                 (API_RFID|0x02)
#define RFID_FRAMETYPE                  (API_RFID|0x03)
#define RFID_CONTROL                    (API_RFID|0x04)
#define RFID_SERIAL                     (API_RFID|0x05)
#define RFID_AUTHENTICATE               (API_RFID|0x06)
#define RFID_GET_FIFO                   (API_RFID|0x07)
#define RFID_SEND                       (API_RFID|0x08)
#define RFID_SETUPFRAME                 (API_RFID|0x09)
#define RFID_WRITE_KEY                  (API_RFID|0x0A)
#define RFID_TEST                       (API_RFID|0x0B)
#define RFID_DISCOVERY                  (API_RFID|0x0C)
#define RFID_RESET                      (API_RFID|0x0D)
//#define RFID_TYPEV_ACTIONS            (API_RFID|0x0E) obsolete
#define RFID_STATUS                     (API_RFID|0x0F)
#define RFID_READ_MAILBOX               (API_RFID|0x10)

//RFID_Controle_Services
#define PCD_GUARD_TIME                  0x00    //deprecated, replaced with RF_FRAME_DELAY_TIME
#define RF_FRAME_DELAY_TIME             0x00
#define PICC_TIMEOUT                    0x01
#define TRANSMISSIONTIMEOUT             0x02
#define RECEIVE_TIMEOUT                 0x03
//Control
#define _ISRECEIVING                    0x0F
#define REG_READ                        0x10
#define REG_WRITE                       0x11
#define FIELD_RESET                     0x12
#define RCRESET                         0x13
#define HF_FIELD                        0x14
#define MODINDEX                        0x15
#define MF_AUTHBIT_CLEAN                0x16
#define BAUDRATE_AIR                    0x17
#define CHECK_RF                        0x18
#define SET_RECEIVING                   0x19
#define TARGET_AC_TEST                  0x1A
#define POWER_SAVE                      0x1B
#define RX_GAIN                         0x1C
#define CRC_ENABLE                      0x1D
#define POSSIBLE_BAUDRATE_AIR           0x1E
#define THRESHOLD                       0x1F
#define BITCOLLISION                    0x20
#define PARITY_ENABLE                   0x21
#define BAUDRATE_AIR_V                  0x40
#define RX_MULTIPLE                     0x41
#define CHECK_PON                       0x3A
#define TARGET_ACTIVATED                0x3B
#define AAC_DE_INIT                     0x3C
#define RXEN                            0x43


#define RXCRC                           0x21
#define TXCRC                           0x22
#define PARGEN                          0x23
#define EVENPAR                         0x24
#define CRYPTOD                         0x25
#define BITFRAMING                      0x26
#define NO_RX_SOF                       0x27
#define NO_RX_EGT                       0x28
#define NO_RX_EOF                       0x29
#define NO_TX_SOF                       0x2A
#define NO_TX_EOF                       0x2B
#define EOF_WIDTH                       0x2C
#define CHAR_SPACING                    0x2D
#define SOF_WIDTH                       0x2E
#define GET_RANDOM_ID                   0x2F

#define SEND_EOF                        0x01

/********************************************************
** RFID_STATUS                                         **
********************************************************/
#define STRONG_RF_FIELD                 (0x01)
#define RF_CARRIER_OFF                  (0x02)
#define CARD_DET                        (0x42)
#define GET_C_I_INFO_REC_STATE          (0x43)
#define GET_NFCEE_ACTION_TRIGGER        (0x44)

/********************************************************
** AAC_CONFIGURATION                                   **
********************************************************/
#define AAC_CONFIGURATION               0x30
#define SENS_RES                        0x31
#define NFCID1                          0x32
#define SEL_RES                         0x33
//#define PROT_SEL                        0x34 //was POL_RES before
//#define NFCID2                          0x35
//#define SYS_CODE                        0x36
#define NFCID3                          0x37
#define PUPI_REG                        0x3C
#define AAC_ATQB                        0x3D
#define AAC_AFI                         0x3E
#define AAC_PADDING                     0x3F


//RFID Test services
#define PN512_SPI                       0x30
#define PN512_REGISTER                  0x31


/**
*KeyHnadler opcodes (operationc codes of the Keyhandler module)
*
*/
#define WRITE_KEY                       0x00
#define READ_KEY                        0x01
#define INIT_KEY                        0x02
#define DELETE_KEY                      0x03
#define DELETE_KEY_TABLE                0x04
#define LOAD_KEY                        0x05
#define UNLOCK_DELETE_KEY_TABLE         0x06

/**
*I2C service Calls
*
*/
//#define I2C_Clock                     (API_API|0x01)
//#define I2C_EEPROM                    (API_API|0x01)

/**
*other API Service Types
*
*For internal usage only.
*/
#define T_14443A                        0x02
#define T_TOPAZ                         0x03
#define T_14443B                        0x50
#define T_15693                         0x01
#define T_FELICA                        0x60
#define T_ICODEUID                      0x03
#define T_ICODEEPC                      0x04
#define T_SRT                           0x05
#define T_NFCIP1_INITIATOR              0x07
#define T_NFC_TARGET                    0x08
#define T_NFCIP1_AATARGET               0x09


/**
*Tag Abstraction Enable codes
*
*This enable codes are used at the TagAbstraction Layer to enable specific TagTypes.
*@see NFC&LLC User Guide Code Snippets: Tag Enable
*/
#define ENABLE_14443A                   0x01
#define ENABLE_14443B                   0x02
#define ENABLE_15693                    0x04
#define ENABLE_FELICA                   0x08
#define ENABLE_ICODEUID                 0x10
#define ENABLE_ICODEEPC                 0x20
#define ENABLE_SRT                      0x40
#define ENABLE_NFC_INITIATOR            0x80
#define ENABLE_GTML                     0x80



/**
*Generic Tag Service Calls
*
*
*/
#define TAG_ABSTRACTION_VERSION         (API_API|0x00)
#define TAG_INIT                        (API_API|0x01)
#define TAG_SELECT                      (API_API|0x02)
#define TAG_HALT                        (API_API|0x03)
#define TAG_FINISH                      (API_API|0x04)
#define TAG_TYPE                        (API_API|0x05)
#define TAG_HIGHSPEED_Select            (API_API|0x06)
#define TAG_APDU                        (API_API|0x0B)
#define TAG_MULTITAGLIST                (API_API|0x0C)
#define TAG_MULTITAGSELECT              (API_API|0x0D)
#define TAG_ATQX                        (API_API|0x0E)  //deprecated - use TAG_CONTROL
#define TAG_SAK                         (API_API|0x0F)  //deprecated - use TAG_CONTROL
#define TAG_UID                         (API_API|0x10)  //deprecated - use TAG_CONTROL
#define TAG_SENSF_RESP                  (API_API|0x11)
#define TAG_APP_DATA                    (API_API|0x77)  //deprecated - use TAG_CONTROL
#define TAG_FWI_SFGT                    (API_API|0x78)
#define TAG_CLR_REQUEST_FLAG            (API_API|0x79)
#define TAG_CLR_RATS_FLAG               (API_API|0x79)
#define TAG_DATARATE_MAX                (API_API|0x7A)
#define TAG_AFI                         (API_API|0x7B)
#define TAG_HIGHER_LAYER_RESPONSE       (API_API|0x7C)
//#define TAG_HIGHER_LAYER_DATA         (API_API|0x7D)
#define TAG_PMM                         (API_API|0x7E)
#define TAG_SYSTEM_CODE                 (API_API|0x7F)
#define TAG_INVENTORY                   (API_API|0x89)

//sub opcodes for TAG_UID
#define CLEAR_UID                       0x10

//NFC tag
#define TAG_MODE                        (API_API|0x80)
#define TAG_ATR_REQ                     (API_API|0x81)
#define TAG_ATR_RES                     (API_API|0x82)
#define TAG_BRS                         (API_API|0x83)
#define TAG_DID                         (API_API|0x84)
#define TAG_STATUS                      (API_API|0x85)
#define TAG_NFCID3I                     (API_API|0x86)
#define TAG_NFCID3T                     (API_API|0x87)
#define TAG_PARAM                       (API_API|0x88)
#define TAG_DEP_REQ                     (API_API|0x8A)
#define TAG_DEP_RES                     (API_API|0x8B)
#define TAG_InitATR                     (API_API|0x8C)
#define TAG_RATS                        (API_API|0x8D)
#define TAG_CARDEMU                     (API_API|0x8E)
#define ATR_REQ                         (API_API|0x8F)
#define ATR_RES                         (API_API|0x90)
#define TAG_DESELECT                    (API_API|0x93)
#define TAG_WUP_REQ                     (API_API|0x94)
#define TAG_PSL_REQ                     (API_API|0x95)
#define TAG_RLS_REQ                     (API_API|0x96)
#define TAG_ATR_RES_GI                  (API_API|0x97)
#define TAG_ATR_REQ_GI                  (API_API|0x98)
#define RESET_PFB                       (API_API|0x99)
#define SET_DEFAULT_REGISTER_VALUES     (API_API|0x9A)

//new tag-abstraction according to NFC-Forum-TS-Activity-1.0
//opcodes for different Activities
#define TAG_POLL                        (API_API|0xA0)
#define TAG_TECHNOLOGY_DETECTION        (API_API|0xA1)
#define TAG_COLLISION_RESOLUTION        (API_API|0xA2)
#define TAG_DEVICE_ACTIVATION           (API_API|0xA3)
#define TAG_DATA_EXCHANGE               (API_API|0xA4)
#define TAG_DEVICE_DEACTIVATION         (API_API|0xA5)

//TAG_Control is used to read and write config parameters as well as to read greedy collection, UID...
#define TAG_CONTROL                     (API_API|0xA6)

// opcode for nci p2p
#define TAG_SET_NFCID2                  (API_API|0xA7)

//Defines for int_tech_sel parameter
#define INT_TECH_SEL_A                  0x00
#define INT_TECH_SEL_B                  0x01
#define INT_TECH_SEL_F                  0x02
#define INT_TECH_SEL_V                  0x03

//Defines for int_protocol parameter
#define INT_PROTOCOL_NFC_DEP            0x00
#define INT_PROTOCOL_ISO_DEP            0x01
#define INT_PROTOCOL_TYPE1              0x02
#define INT_PROTOCOL_TYPE2              0x03
#define INT_PROTOCOL_TYPE3              0x04
#define INT_PROTOCOL_15693              0x05

#define CONTROL_CONF                    0x0000  //used for configuration parameters
#define CONTROL_GRE                     0x0100  //used for greedy collection
#define CONTROL_P                       0x0200  //used for other proprietary parameters
#define CONTROL_EMU                     0x0400  //used for card emulation
#define CONTROL_NCI                     0x0800  //used for configuration defined in NFCForum-TS-NCI-1.0-candidate-1
#define CONTROL_DTA                     0x1000  //used for parameters in document DTA_NCI_Extensions Version1.0

//Random defines used in NCI but not related to NCI commands (will not be conflict with any values
//defined in NCI standards
#define NFCEE_QUICK_ENABLE                 0x0001   //used to enable all NFCEE's
#define NFCEE_QUICK_ACTIVATE               0x0002   //used to activate all NFCEE's
#define NFCEE_DEACTIVATE_ALL               0x0003   //deactivation of all NFCEE's. Used before reset.
#define ACTIVATE_ESE                       0x0004   //to activate the Embedded Secure Element
#define DEACTIVATE_ESE                     0x0005   //to deactivate the Embedded Secure Element
#define ACTIVATE_ESE_BLOCKING              0x0006   //If a CoreConnCreateCmd has been received you have to wait with the rsp till the activation is done to see if it has been successfull or not
#define NFCEEMNGT_CHECK_MIFARE_CLASSIC     0x0007   //Check if the NFCEE connected to the passed nfceeInterface instance is Mifare Classic compliant.
#define NFCEEMNGT_DEACTIVATE_ESE_BLOCKING  0x0008   //
#define NFCEEMNGT_EVT_FIELD_ON             0x0011
#define NFCEEMNGT_EVT_FIELD_OFF            0x0014
#define NFCEEMNGT_SET_SESSION_ID           0x0021   //
#define NFCEEMNGT_SET_SYNC_ID              0x0022   //
#define NFCEEMNGT_LOAD_RF_PARAMS           0x0023   //
#define NFCEEMNGT_SET_ISO_COMPLIANCE       0x0024   //Will be set from the HCI Gate if a NFCEE is ISO/IEC 14443-4 compliant.

//Defines for ListenModeFelica::Call
#define LMF_DH_WKP_CMD                  (word)0x0001 //@see ListenModeFelica::wakeupFromDH() description
#define LMF_DH_WKP_CMD_RECEIVED         (word)0x0002 //Shall be called from the Proprietary Handler if the Wakeup from Dh is received correctly.


//Sub-opcodes for CONTROL_NCI (as defined in NFCForum-TS-NCI-1.0-candidate-1 page 138ff)
#define NCI_TOTAL_DURATION              (CONTROL_NCI|0x00)
#define NCI_DEVICES_LIMIT               (CONTROL_NCI|0x01)
#define NCI_PA_BAIL_OUT                 (CONTROL_NCI|0x08)
#define NCI_PB_AFI                      (CONTROL_NCI|0x10)
#define NCI_PB_BAIL_OUT                 (CONTROL_NCI|0x11)
#define NCI_PB_ATTRIB_PARAM1            (CONTROL_NCI|0x12)
#define NCI_PB_SENSB_REQ_PARAM          (CONTROL_NCI|0x13)
#define NCI_PF_BIT_RATE                 (CONTROL_NCI|0x18)
#define NCI_PF_PF_RC_CODE               (CONTROL_NCI|0x19)
#define NCI_PB_H_INFO                   (CONTROL_NCI|0x20)
#define NCI_PI_BIT_RATE                 (CONTROL_NCI|0x21)
#define NCI_PN_NFC_DEP_SPEED            (CONTROL_NCI|0x28)
#define NCI_PN_ATR_REQ_GEN_BYTES        (CONTROL_NCI|0x29)
#define NCI_PN_ATR_REQ_CONFIG           (CONTROL_NCI|0x2A)
#define NCI_BOOTLADER_FLAG              (CONTROL_NCI|0xA0)
#define NCI_RF_FIELD_INFO               (CONTROL_NCI|0x80)
#define NCI_RF_NFCEE_ACTION             (CONTROL_NCI|0x81)
#define NCI_NFCDEP_OP                   (CONTROL_NCI|0x82)
#define NCI_LF_PROTOCOL_TYPE            (CONTROL_NCI|0x50)
#define NCI_LF_T3T_FLAGS                (CONTROL_NCI|0x53)
#define NCI_LI_FWI                      (CONTROL_NCI|0x58)
#define NCI_LN_WT                       (CONTROL_NCI|0x60)
#define NCI_LN_ATR_RES_GEN_BYTES        (CONTROL_NCI|0x61)
#define NCI_LN_ATR_RES_CONFIG           (CONTROL_NCI|0x62)


//Sub-opcodes for CONTROL_CONF. For internal use (specified in NFCForum-TS-Activity-1.0)
//Don't name them CON_... --> Conflicts with NCI-API
#define CONF_POLL                       (CONTROL_CONF|0xA0)
#define CONF_ANTICOLL                   (CONTROL_CONF|0xA1)
#define CONF_ADV_FEAT                   (CONTROL_CONF|0xA2)
#define CONF_RATS                       (CONTROL_CONF|0xA3)
#define CONF_ATTRIB_PARAM               (CONTROL_CONF|0xA4)
#define CONF_BITR                       (CONTROL_CONF|0xA5)
#define CONF_GB                         (CONTROL_CONF|0xA6)
#define CONF_BITR_NFC_DEP               (CONTROL_CONF|0xA7)
#define CONF_ATR                        (CONTROL_CONF|0xA8)
#define CONF_RC_BYTE                    (CONTROL_CONF|0xA9)
#define CONF_ACTIVATED_BITR             (CONTROL_CONF|0xAA) /** To get the Bitrate with which the Tag has been activated. */
#define CONF_FN_T3T_FWT                 (CONTROL_CONF|0xAB) /** FeliCa Networks */
#define CONF_V_BIT_RATE                 (CONTROL_CONF|0xAC)
#define CONF_V_FLAGS                    (CONTROL_CONF|0xAD)
#define CONF_V_AFI                      (CONTROL_CONF|0xAE)


//defines for sendbuf[0] CONF_POLL
#define CONF_POLL_A                     0x01
#define CONF_POLL_B                     0x02
#define CONF_POLL_F                     0x04
#define CONF_POLL_V                     0x08
#define CONF_POLL_ACTIVE_A              0x10
#define CONF_POLL_ACTIVE_F              0x40
#define CONF_POLL_K                     0x80

//Sub-opcodes for CONTROL_GRE
#define GRE_POLL_A                      (CONTROL_GRE|0x00)
#define GRE_POLL_B                      (CONTROL_GRE|0x01)
#define GRE_POLL_F                      (CONTROL_GRE|0x02)
#define GRE_SEL_RES                     (CONTROL_GRE|0x03)
#define GRE_SENSB_RES                   (CONTROL_GRE|0x04)
#define GRE_SENSF_RES                   (CONTROL_GRE|0x05)
#define GRE_ATR                         (CONTROL_GRE|0x06)
#define GRE_ATS                         (CONTROL_GRE|0x07)
#define GRE_ATTRIB                      (CONTROL_GRE|0x08)
#define GRE_CLEAR                       (CONTROL_GRE|0x09)
#define GRE_BITRATE_A                   (CONTROL_GRE|0xA0)
#define GRE_BITRATE_B                   (CONTROL_GRE|0xB0)
#define GRE_BITRATE_NFC_DEP             (CONTROL_GRE|0xC0)
#define GRE_POLL_V                      (CONTROL_GRE|0xD0)
#define GRE_ATTRIV                      (CONTROL_GRE|0xE0)
#define GRE_KOVIO_BARCODE               (CONTROL_GRE|0xF0)

//Sub-opcodes for CONTROL_P
//#define P_ATQA                              (CONTROL_P|0x00)
//#define P_ATQB                              (CONTROL_P|0x01)
//#define P_UIDA                              (CONTROL_P|0x02)
//#define P_UIDB                              (CONTROL_P|0x03)
//#define P_SAK                               (CONTROL_P|0x04)
//#define P_APP_DATA                          (CONTROL_P|0x05)
#define P_FOUND                         (CONTROL_P|0x06)
#define P_LAST_NFCIDX_TECH              (CONTROL_P|0x07)
#define P_INT_COLL_PEND                 (CONTROL_P|0x08)
#define P_GET_NFCIDX                    (CONTROL_P|0x09)
#define P_HS_MULTISELECT                (CONTROL_P|0x0A)

//Sub-opcodes for CONTROL_DTA
//Used as Sub-opcodes for call functions,
//Different coding, than received 4Bytes Value defined in DTA_NCI_Extensions!!!
//Don't use them for comparison with received Data!
#define DTA_RF_OFF_ALL_REQ                  (CONTROL_DTA|0x01)
#define DTA_RF_OFF_SENS_REQ                 (CONTROL_DTA|0x02)
#define DTA_RF_OFF_SENSB_RES                (CONTROL_DTA|0x03)
#define DTA_RF_OFF_SENSB_REQ                (CONTROL_DTA|0x04)
#define DTA_RF_OFF_ALLB_REQ                 (CONTROL_DTA|0x05)
#define DTA_RF_OFF_SENS_RES                 (CONTROL_DTA|0x06)
#define DTA_RF_OFF_SEL_RES                  (CONTROL_DTA|0x07)
#define DTA_RF_OFF_SLPB_RES                 (CONTROL_DTA|0x08)
#define DTA_RF_OFF_SDD_RES_CL1              (CONTROL_DTA|0x09)
#define DTA_RF_OFF_SDD_RES_CL2              (CONTROL_DTA|0x0A)
#define DTA_RF_OFF_SDD_RES_CL3              (CONTROL_DTA|0x0B)
#define DTA_RF_OFF_SDD_REQ_CL1              (CONTROL_DTA|0x0C)
#define DTA_RF_OFF_SDD_REQ_CL2              (CONTROL_DTA|0x0D)
#define DTA_RF_OFF_SDD_REQ_CL3              (CONTROL_DTA|0x0E)

//defines for recbuf[0] P_FOUND
#define P_FOUND_A                       0x01
#define P_FOUND_B                       0x02
#define P_FOUND_F                       0x04
#define P_FOUND_V                       0x08
#define P_FOUND_ACTIVE_A                0x10
#define P_FOUND_ACTIVE_F                0x20
#define P_FOUND_K                       0x40


//Sub-opcodes for CONTROL_EMU
#define EMU_1                           (CONTROL_EMU|0x00)

/*
*Configuration Parameter Tags
*ref. NFCForum -TS-NCI-1. 0_Candidate-1 201 2-03-07 Table 99
*/

//Common Discovery Parameters
#define TAG_TOTAL_DURATION              (API_API|0x00)
#define TAG_CON_DEVICES_LIMIT           (API_API|0x01)

//Poll Mode – NFC-A Discovery Parameters
#define TAG_PA_BAIL_OUT                 (API_API|0x08)

//Poll Mode – NFC-B Discovery Parameters
//#define TAG_PB_AFI                    (API_API|0x10)
#define TAG_PB_BAIL_OUT                 (API_API|0x11)
#define TAG_PB_ATTRIB_PARAM1            (API_API|0x12)

//Poll Mode – NFC-F Discovery Parameters
#define TAG_PF_BIT_RATE                 (API_API|0x18)

//Poll Mode – ISO-DEP Discovery Parameters
#define TAG_PB_H_INFO                   (API_API|0x20)
#define TAG_PI_BIT_RATE                 (API_API|0x21)

//Poll Mode – NFC-DEP Discovery Parameters
#define TAG_PN_NFC_DEP_SPEED            (API_API|0x28)
#define TAG_PN_ATR_REQ_GEN_BYTES        (API_API|0x29)
#define TAG_PN_ATR_REQ_CONFIG           (API_API|0x2A)

//Listen Mode – NFC-A Discovery Parameters
#define TAG_LA_BIT_FRAME_SDD            (API_API|0x30)
#define TAG_LA_PLATFORM_CONFIG          (API_API|0x31)
#define TAG_LA_SEL_INFO                 (API_API|0x32)
#define TAG_LA_NFCID1                   (API_API|0x33)

//Listen Mode – NFC-B Discovery Parameters
#define TAG_LB_SENSB_INFO               (API_API|0x38)
#define TAG_LB_NFCID0                   (API_API|0x39)
#define TAG_LB_APPLICATION_DATA         (API_API|0x3A)
#define TAG_LB_SFGI                     (API_API|0x3B)
#define TAG_LB_ADC_FO                   (API_API|0x3C)

//Listen Mode – NFC-F Discovery Parameters
#define LF_T3T_IDENTIFIERS              0x40
#define TAG_LF_T3T_IDENTIFIERS_1        0x40
#define TAG_LF_T3T_IDENTIFIERS_2        0x41
#define TAG_LF_T3T_IDENTIFIERS_3        0x42
#define TAG_LF_T3T_IDENTIFIERS_4        0x43
#define TAG_LF_T3T_IDENTIFIERS_5        0x44
#define TAG_LF_T3T_IDENTIFIERS_6        0x45
#define TAG_LF_T3T_IDENTIFIERS_7        0x46
#define TAG_LF_T3T_IDENTIFIERS_8        0x47
#define TAG_LF_T3T_IDENTIFIERS_9        0x48
#define TAG_LF_T3T_IDENTIFIERS_10       0x49
#define TAG_LF_T3T_IDENTIFIERS_11       0x4A
#define TAG_LF_T3T_IDENTIFIERS_12       0x4B
#define TAG_LF_T3T_IDENTIFIERS_13       0x4C
#define TAG_LF_T3T_IDENTIFIERS_14       0x4D
#define TAG_LF_T3T_IDENTIFIERS_15       0x4E
#define TAG_LF_T3T_IDENTIFIERS_16       0x4F
#define TAG_LF_PROTOCOL_TYPE            0x50
#define TAG_LF_T3T_PMM                  0x51
#define TAG_LF_T3T_MAX                  0x52
#define TAG_LF_T3T_FLAGS                0x53
#define TAG_LF_CON_BITR_F               0x54
#define TAG_LF_ADV_FEAT                 0x55
#define TAG_LN_NFC_DEP					0xA3

//Listen Mode – ISO-DEP Discovery Parameters
#define TAG_LI_FWI                      (API_API|0x58)
#define TAG_LA_HIST_BY                  (API_API|0x59)
#define TAG_LB_H_INFO_RESP              (API_API|0x5A)
#define TAG_LI_BIT_RATE                 (API_API|0x5B)

//Listen Mode – NFC-DEP Discovery Parameters
#define TAG_LN_WT                       (API_API|0x60)
#define TAG_LN_ATR_RES_GEN_BYTES        (API_API|0x61)
#define TAG_LN_ATR_RES_CONFIG           (API_API|0x62)

//Other Parameters
#define TAG_RF_FIELD_INFO               (API_API|0x80)
#define TAG_RF_NFCEE_ACTION             (API_API|0x81)
#define TAG_NFCDEP_OP                   (API_API|0x82)
#define L_BLOCK_NOTIFICATION            (API_API|0x83)



/**
*MIFARE Tag operations
*
*/
#define TAG_AUTHENTICATE                (API_API|0x11)
#define TAG_READ                        (API_API|0x12)
#define TAG_WRITE                       (API_API|0x13)
#define TAG_LOCKBLOCK                   (API_API|0x14)
#define TAG_VALUE_SET                   (API_API|0x15)
#define TAG_VALUE_GET                   (API_API|0x16)
#define TAG_VALUE_INC                   (API_API|0x17)
#define TAG_VALUE_DEC                   (API_API|0x18)
#define TAG_VALUE_COPY                  (API_API|0x19)
#define TAG_APDU_INIT                   (API_API|0x1A)
#define TAG_WRITE_KEY                   (API_API|0x1B)
#define TAG_READ_MULTIPLE_BLOCK         (API_API|0x1C)
#define TAG_WRITE_MULTIPLE_BLOCK        (API_API|0x1D)


/**
*NFC operations
*
*/
#define NFC_ROLL                        0x01
#define NFC_MODE                        0x02
#define NFC_ATR                         0x04
#define NFC_PARAM                       0x08

#define RX                              0x00
#define TX                              0x01

#define ON                              0x01
#define OFF                             0x00

#define DEF_INPUT                       0x00
#define DEF_OUTPUT                      0x01

#define BAUDRATE_106                    0x00
#define BAUDRATE_212                    0x02
#define BAUDRATE_424                    0x04
#define BAUDRATE_848                    0x08
#define BAUDRATE_1696                   0x10
#define BAUDRATE_3392                   0x20
#define BAUDRATE_6784                   0x40
#define BAUDRATE_ALL                    0x80

#define BAUDRATE_1_66                   0x00  //will only be used at transmitting part (TX)
#define BAUDRATE_6_62                   0x00  //will only be used at receiving part (RX)
#define BAUDRATE_26_48                  0x01  //will be used at RX and TX part


#define HOST_BAUD_9600                  0x00
#define HOST_BAUD_19200                 0x01
#define HOST_BAUD_38400                 0x02
#define HOST_BAUD_57600                 0x03
#define HOST_BAUD_115200                0x04
#define HOST_BAUD_230400                0x05
#define HOST_BAUD_460800                0x06
#define HOST_BAUD_921600                0x07

/**
*TagAbstraction opcode
*
*/
#define TAG_CHOOSE                      (API_API|0x1E)
#define TAG_ENABLE                      (API_API|0x1F)
#define TAG_MULTI_ENABLE                (API_API|0x44)
#define TAGABSTRACTION_CONTROLE         (API_API|0x21)
#define TAGABSTRACTION_CLEAN_SELECT_STATE   (API_API|0x22)


/**
*TagAbstraction extended opcodes
*
*/
#define TAG_APDU_LAYER4                 (API_API|0x33)
#define SET_RNAK_CNT                    (API_API|0x34)
#define SET_RACK_CNT                    (API_API|0x35)
#define ISO_DEP_PRESENCE_CHECK          (API_API|0x36)
#define SET_DESELECT_CNT                (API_API|0x37)
#define TAG_CID_SUPPORT                 (API_API|0x38)
#define SET_RETRY_NACK_CNT              (API_API|0x39)
#define SET_RETRY_ATN_CNT               (API_API|0x3A)
#define SET_DSL_CNT                     (API_API|0x3B)
#define SET_RLS_CNT                     (API_API|0x3C)

/**
*Typ F
*
*/
#define RC0                             (byte)0x00
#define RC1                             (byte)0x01
#define RC2                             (byte)0x02

/**
*14443-4 Datacommunication
*
*/
#define I_Block 			(byte)0x02      // 14443-4 I-Block received; see ISO/IEC 14443-4 clause 7.1
#define R_Block 			(byte)0x02	// 14443-4 R-Block received; see ISO/IEC 14443-4 clause 7.1
#define S_Block 			(byte)0x03	// 14443-4 S-Block received; see ISO/IEC 14443-4 clause 7.1
#define ACK                             (byte)0x01
#define _NAK				(byte)0x00
#define DESELECT			(byte)0x05
#define WTX 				(byte)0x09

/**
*CardEmulation
*
*/
#define KEEP_SETTINGS                   (byte)0xCE

#define LMH_TAG_MODE                    (byte)0x08
#define LMH_TAG_ANSWER_AB               (byte)0x09
#define LMH_TAG_ANSWER_F                (byte)0x0a
#define TAG_CID                         (byte)0x0b
#define TAG_CLT                         (byte)0x0c
#define TAG_FWISFGI                     (byte)0x0d
#define TAG_A_DS_DR                     (byte)0x0e
#define TAG_B_DS_DR                     (byte)0x0f
#define TAG_SPEED                       (byte)0x10
#define TAG_ATQB                        (byte)0x11
#define TAG_HIGHER_RESPONSE             (byte)0x12
#define TAG_RATS_RECEIVED               (byte)0x13
#define TAG_APPLICATION_DATA            (byte)0x14
#define TAG_SET_FWT                     (byte)0x15
#define TAG_SET_FSCI                    (byte)0x16
#define TAG_SET_SFGI                    (byte)0x17
#define LMH_TAG_RESET_MODES             (byte)0x18

#define CE_SUSPEND                      (byte)0x15
#define CE_RESUME                       (byte)0x16

#define IDLE_STATE                      (byte)0x00
#define FIELD_DETECTED                  (byte)0x01
#define SELECTED                        (byte)0x02
#define FIELD_OFF                       (byte)0x03
#define GUARD_STATE                     (byte)0x04

#define SET_ROUTING_DIRECTIONS          (byte)0x7E

/**
*HCI CardEmulation Defines
*
*/
#define CARD_EMULATION_ACTIVE           (byte)0x02
#define CARD_EMULATION_NOT_ACTIVE       (byte)0xFF

/**< Events for Card application Gates, defined in ETSI TS 102 622 V11.1.10 9.3.4.3 Events */
#define EVT_SEND_DATA                     (byte)0x10
#define EVT_FIELD_ON                      (byte)0x11
#define EVT_CARD_DEACTIVATED              (byte)0x12
#define EVT_CARD_ACTIVATED                (byte)0x13
#define EVT_FIELD_OFF                     (byte)0x14

/**
* Administration Gate Call Opcodes
*
*/
#define ADG_EVT_HOT_PLUG                (word)0x0001

/**
* NFCEE Management Defines
*/
#define NO_VALID_INTERFACE              (byte)0xFF


/********************************************************
** HCI Service Call Opcodes                            **
********************************************************/
#define HCI_CLT_GOTO_INIT                   (word)(API_HCI | 0x01)  /**< Defined in ETSI TS 102 613 V11.0.0 [Table 11.1 Contents of CLT_CMD] >*/
#define HCI_CLT_GOTO_HALT                   (word)(API_HCI | 0x02)  /**< Defined in ETSI TS 102 613 V11.0.0 [Table 11.1 Contents of CLT_CMD] >*/


/**
* Return and error codes (used for check status in dispatcher.h)
* Any error code must have the most significant bit 0x8000 set in order to distinguish error codes from status codes.
* Used by CHECK-macro defined in DebugPrint.h
*/
enum
{
  OK                       = 0x0000, //SUCCESS
  MORE_DATA                = 0x0001,  //If more frames are available.

  UNKNOWN_COMMAND          = 0xFFFE, //If the received command is unknown
  OUT_OF_RANGE             = 0xFFFC, //If you try to write a address/file which doesn't exist
  GENERAL_ERROR            = 0xFFFA, //If a ErrorOccured which really shouldn't! ;-)
  OPERATION_MODE_FAILURE   = 0xFFF9, //If for example the RF-Field is on but it shouldn't be.
  WRONG_LENGTH             = 0xFFF6, //If sendlen isn't what it's expected
  WRONG_PARAMETER          = 0xFFF5, //If you try to set a byte (or something else) to a not allowed state/value
  TIMEOUT_ERROR            = 0xFFF4, //For Host-Reader communication. If a Tag won't answer in a explizit time = NO_ANSWER_FROM_TAG
  COMMUNICATION_ERROR      = 0xFFF3, //If the Tag has answered but the data isn't right. (Like the header is false, missing,...)
  NO_ANSWER_FROM_TAG       = 0xFFF2, //If the target device (card, nfc device, ...) hasn't answered in the set time.
  DATA_OVERFLOW            = 0xFFF1, //If reclen is too short
  HF_FIELD_ERROR           = 0xFFF0, //If the HAL can't activated a HF-Field due existence of other RF-Field

  RF_FRAMING_ERROR         = 0xFFEF, //If the received frame is invalid (crc-, parity-, wrong SOF or EOF and so on)
  RF_FRAMING_ERR_MORE_DATA = 0xFFEE, //If RF_FRAMING_ERROR occured at current frame and more frames are available.
  INTERFACE_ERROR          = 0xFFED, //If a interface activation/deactivation was not successfull.
  RF_PROTOCOL_EXCEPTION    = 0xFFEC, //if a protocol error occures to inform higher ligher
  NOT_IMPLEMENTED          = 0xFEF8,
  INTERFACE_DISABLED       = 0xFEF9,
  ACTIVATED                = 0xFEFA,
  DEACTIVATED              = 0xFEFB,
  STILL_ACTIVATING         = 0xFEFC,
  STILL_DEACTIVATING       = 0xFEFD,
  STILL_SENDING            = 0xFEFE,
  STILL_RECEIVING          = 0xFEFF,

  IN_PROGRESS              = 0xFEFC,

  TRIGGER_BY_RF            = 0xFFD0,

  NO_DEACTIVATE            = 0xFFCF,
};

#define RETURN_ERROR                    0x8000  //bitmask to check if a status code contains any error


/**
*Codes for set the default register values in the tag classes
*
*/
#define EE                              0x01
#define RAM                             0x02
#define EE_RAM                          0x03

#define SAK_TYPE_MASK                   0x60    //To get the right bits of the SAK for type recognition
#define SAK_FRAME_RF_INTERFACE          0x00    //SAK Bitmask for Frame Interfaces
#define SAK_ISO_DEP_RF_INTERFACE        0x20    //SAK Bitmask for ISO- DEP
#define SAK_NFC_DEP_INTERFACE           0x40    //SAK Bitmask for NFC-DEP

#define RX_BITRATE_MASK                 0x70   //Bitrate form PICC to PCD
#define TX_BITRATE_MASK                 0x07  //Bitrate from PCD to PICC

#define BITRATE_106                     0x00
#define BITRATE_212                     0x01
#define BITRATE_424                     0x02
#define BITRATE_848                     0x04

#define BITRATE_SENSF_MASK              0x0F


#define MODE_ACTIVE                     0xFF  //has to be refactored. RFID-Discovery doesn't distinguish between active or passive


/**************************************************************
*           Error Gathering Defines
***************************************************************/
#define ERR_HCI_INFO          (byte)0x01
#define ERR_NCI_STM           (byte)0x02

/**************************************************************
*           Common Callback Defines
***************************************************************/
#define CALLBACK_FIELD_ON           (word)0x0001
#define CALLBACK_FIELD_OFF          (word)0x0002
#define CALLBACK_FRAME_RECEIVED     (word)0x0003
#define CALLBACK_SWP_1_FRAME        (word)0x0010
#define CALLBACK_SWP_2_FRAME        (word)0x0011
#define CALLBACK_SWP_3_FRAME        (word)0x0012

/**************************************************************
*           IAR User Keyword defines
***************************************************************/
#define DO_NOT_CHANGE_THE_LINE_BELOW
#define IMPORTANT_NOTE

/**************************************************************
*           Kovio Service Calls
***************************************************************/
#define KOVIO_PRESENCE_CHECK        (word)0x0001

#endif //READER_API_H_
