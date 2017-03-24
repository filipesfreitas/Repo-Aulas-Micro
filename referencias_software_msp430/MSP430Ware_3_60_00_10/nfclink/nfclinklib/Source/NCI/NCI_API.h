#ifndef NCI_API_H
#define NCI_API_H
 /*******************************************************************************
 * @file    NCI_API.h
 * @brief
 * @author
 * @version V0.0.6
 * @date    15/02/2014
 * @details
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

#include "NCIConfiguration.h"

/*
* Packet Format
* ref. NFCForum -TS-NCI-1. 0_Candidate-1 201 2-03-07 chapter 3.4
*/
#define DATA_PACKET                             0x0000
#define CP_COMMAND_MSG                          0x0001
#define CP_RESPONSE_MSG                         0x0002
#define CP_NOTIFICATION_MSG                     0x0003
#define KR_FRAME                                0x0005 //custom-made Kronegger frame
#define MASK_OID                                0x3F
#define GID_MASK                                0x0F
#define CONN_ID_MASK                            0x0F
#define PBF_MASK                                0x10
#define PBF_COMPLETE_MESSAGE                    0x00
#define PBF_MESSAGE_SEGMENT                     0x01

/**
* Common Packet Header - Message Type (MT)
* @see NFCForum-TS-NCI-1.0 [3.4.1 Common Packet Header]
*/
#define MT_DATA_PACKET                      (byte)0x00
#define MT_CP_CMD_MESSAGE                   (byte)0x20
#define MT_CP_RSP_MESSAGE                   (byte)0x40
#define MT_CP_NTF_MESSAGE                   (byte)0x60
//RFU                                      0x80 - 0xE0

/*
* Packet Format
* ref. NFCForum -TS-NCI-1. 0_Candidate-1 201 2-03-07 chapter 4.4.4
*/
#define INITIAL_CREDITS                         0x01 // due to buffer/maxframelen ratio 255/255

/*
* Destination Types
* ref. NFCForum-TS-NCI-1.0 2012-11-06 Table 12
*/
//RFU                                           0x00
#define NFCC_LOOPBACK                           0x01
#define REMOTE_NFC_ENDPOINT                     0x02
#define NFCEE                                   0x03
//RFU                                           0x04-0xC0
//Proprietary                                   0xC1-0xFE
//RFU                                           0xFF

/*
*TLV Coding for Listen Mode Routing
*ref. NFCForum -TS-NCI-1. 0_Candidate-1 201 2-03-07 Table 45
*/
#define TECHN_ROUTING_ENTRY                     0x00
#define PRTCL_ROUTING_ENTRY                     0x01
#define AID_ROUTING_ENTRY                       0x02
#define NFCID2_ROUTING_ENTRY                    0x03
//RFU                                           0x03-0x9F
//Proprietary                                   0xA0-0xFF

/*
*Value Field for Power State
*ref. NFCForum -TS-NCI-1. 0_Candidate-1 201 2-03-07 Table 49
*/
#define BATT_OFF_MASK                           0x04
#define OFF_MASK                                0x02
#define ON_MASK                                 0x01


/*
* Deactivation Types
* @see NFCForum-TS-NCI-1.0 Table 63: Deactivation Types
*/
#define IDLE_MODE                               0x00
#define SLEEP_MODE                              0x01
#define SLEEP_AF_MODE                           0x02
#define DISCOVERY                               0x03
//RFU                                           0x04–0xFF

/*
* Deactivation Reasons
* @see NFCForum-TS-NCI-1.0 Table 64: Deactivation Reasons
*/
#define DH_REQUEST                              0x00
#define ENDPOINT_REQUEST                        0x01
#define RF_LINK_LOSS                            0x02
#define NFC_B_BAD_AFI                           0x04

/*
*TLV Coding for RF Communication Parameter ID
*ref. NFCForum -TS-NCI-1. 0_Candidate-1 201 2-03-07 Table 71
*/
#define RF_TECHN_MODE                           0x00
#define TRANSM_BIT_RATE                         0x01
#define REC_BIT_RATE                            0x02
#define NFCB_DATA_EXCH_CONF                     0x03
//RFU                                           0x04-0x7F
//Proprietary                                   0x80-0xFF

/*
*NFC-B Data Exchange Configuration Parameter
*ref. NFCForum -TS-NCI-1. 0_Candidate-1 201 2-03-07 Table 72
*/
#define MIN_TR0_MASK                            0xC0
#define MIN_TR1_MASK                            0x30
#define SUPR_EOS_MASK                           0x08
#define SUPR_SOS_MASK                           0x04
#define MIN_TR2_MASK                            0x03

/*
*Status Codes
*ref. NFCForum -TS-NCI-1. 0_Candidate-1 201 2-03-07 Table 92
*/

// Generic Status Codes
#define STATUS_OK                               0x00
#define STATUS_REJECTED                         0x01
#define STATUS_RF_FRAME_CORRUPTED               0x02
#define STATUS_FAILED                           0x03
#define STATUS_NOT_INITIALIZED                  0x04
#define STATUS_SYNTAX_ERROR                     0x05
#define STATUS_SEMANTIC_ERROR                   0x06
#define STATUS_UNKNOWN_GID                      0x07
#define STATUS_UNKNOWN_OID                      0x08
#define STATUS_INVALID_PARAM                    0x09
#define STATUS_MESSAGE_SIZE_EXCEEDED            0x0A
//RFU                                           0x0B-0x9F

//RF Discovery Specific Status Codes
#define DISCOVERY_ALREADY_STARTED               0xA0
#define DISCOVERY_TARGET_ACTIVATION_FAILED      0xA1
#define DISCOVERY_TEAR_DOWN                     0xA2
//RFU                                           0xA3-0xAF

//RF Interface Specific Status Codes
#define RF_TRANSMISSION_ERROR                   0xB0
#define RF_PROTOCOL_ERROR                       0xB1
#define RF_TIMEOUT_ERROR                        0xB2
//RFU                                           0xB3-0xBF

//NFCEE Interface Specific Status Codes
#define NFCEE_INTERFACE_ACTIVATION_FAILED       0xC0
#define NFCEE_TRANSMISSION_ERROR                0xC1
#define NFCEE_PROTOCOL_ERROR                    0xC2
#define NFCEE_TIMEOUT_ERROR                     0xC3
//RFU                                           0xC4-0xDF

//Proprietary Status Codes
//For proprietary use                           0xE0-0xFF

/*
* RF Technologies
* @see NFCForum-TS-NCI-1.0 [Table 95: RF Technologes]
*/
#define NFC_RF_TECHNOLOGY_A                     (byte)0x00
#define NFC_RF_TECHNOLOGY_B                     (byte)0x01
#define NFC_RF_TECHNOLOGY_F                     (byte)0x02
#define NFC_RF_TECHNOLOGY_15693                 (byte)0x03
//RFU                                           0x04-0x7F
//For proprietary use                           0x80-0xFE
//RFU                                           0xFF

/*
*RF Technology and Mode
*@see NFCForum-TS-NCI-1.0 [Table 96: RF Technology and Mode]
*/
#define NFC_A_PASSIVE_POLL_MODE                 0x00
#define NFC_B_PASSIVE_POLL_MODE                 0x01
#define NFC_F_PASSIVE_POLL_MODE                 0x02
#define NFC_A_ACTIVE_POLL_MODE                  0x03
//RFU						                    0x04
#define NFC_F_ACTIVE_POLL_MODE                  0x05
#define NFC_15693_PASSIVE_POLL_MODE             0x06
//RFU					                        0x07 - 0x6F
//Reserved for Proprietary Technologies in Poll Mode	0x70 - 0x7F
#define NFC_A_KOVIO_BARCODE_POLL_MODE           0x70
//Reserved for Proprietary Technologies in Poll Mode    0x70 - 0x7F
#define NFC_A_PASSIVE_LISTEN_MODE               0x80
#define NFC_B_PASSIVE_LISTEN_MODE               0x81
#define NFC_F_PASSIVE_LISTEN_MODE               (byte)0x82
#define NFC_A_ACTIVE_LISTEN_MODE                0x83
//RFU                                           0x84
#define NFC_F_ACTIVE_LISTEN_MODE                0x85
#define NFC_15693_PASSIVE_LISTEN_MODE           0x86
//RFU                                           0x87–0xEF
//Reserved for Proprietary Technologies in Listen Mode	0xF0–0xFF

/*
* Bit Rates
* @see NFCForum-TS-NCI-1.0 Table 97: Bit Rates
*/
#define NFC_BIT_RATE_106                        0x00
#define NFC_BIT_RATE_212                        0x01
#define NFC_BIT_RATE_424                        0x02
#define NFC_BIT_RATE_848                        0x03
#define NFC_BIT_RATE_1695                       0x04
#define NFC_BIT_RATE_3390                       0x05
#define NFC_BIT_RATE_6780                       0x06
//RFU                                           0x07–0x7F
//For proprietary use                           0x80-0xFE
#define NFC_BIT_RATE_15693_LOW                  0x80
#define NFC_BIT_RATE_15693_HIGH                 0x81
//RFU                                           0xFF

/*
*RF Protocols
*@see NFCForum-TS-NCI-1.0 [Table 98: RF Protocols]
*/
#define PROTOCOL_UNDETERMINED                   0x00
#define PROTOCOL_T1T                            0x01
#define PROTOCOL_T2T                            0x02
#define PROTOCOL_T3T                            0x03
#define PROTOCOL_ISO_DEP                        0x04
#define PROTOCOL_NFC_DEP                        0x05
//RFU                                           0x06–0x7F
//For proprietary use                           0x80-0xFE
#define PROTOCOL_MIFARE_CLASSIC           (byte)0x80
#define PROTOCOL_KOVIO_BARCODE            (byte)0x81
#define PROTOCOL_15693                    (byte)0x86  //ref. NCI_15693 Page 5
//RFU                                           0xFF

/*
*RF Interfaces
*@see NFCForum-TS-NCI-1.0 [Table 99: RF Interfaces]
*/
#define NFCEE_DIRECT_RF_INTERFACE               0x00
#define FRAME_RF_INTERFACE                      0x01
#define ISO_DEP_RF_INTERFACE                    0x02
#define NFC_DEP_RF_INTERFACE                    0x03
//RFU                                           0x04–0x7F
//For proprietary use                           0x80-0xFE
#define KOVIO_BARCODE_INTERFACE                 0x80
//RFU                                           0xFF

/*
*NFCEE Protocols / Interfaces
*@see NFCForum-TS-NCI-1.0 Table 100
*/
#define NCI_APDU                                0x00
#define NCI_HCI_ACCESS                          0x01
#define NCI_TYPE_3_TAG_COMMAND_SET              0x02
#define NCI_TRANSPARENT                         0x03
//RFU                                           0x04–0x7F
//For proprietary use                           0x80-0xFE
//RFU                                           0xFF

/**************************************************************************************************
*   Configuration Parameter Tags
*   @see NFCForum-TS-NCI-1.0 [Table 101: Configuration Parameter Tags]
***************************************************************************************************/

//Common Discovery Parameters
#define TOTAL_DURATION                          0x00
#define CON_DEVICES_LIMIT                       0x01
//RFU                                           0x02-0x07

//Poll Mode – NFC-A Discovery Parameters
#define PA_BAIL_OUT                             0x08
//RFU                                           0x09-0x0F

//Poll Mode – NFC-B Discovery Parameters
#define PB_AFI                                  0x10
#define PB_BAIL_OUT                             0x11
#define PB_ATTRIB_PARAM1                        0x12
#define PB_SENSB_REQ_PARAM                      0x13

//RFU                                           0x14-0x17

//Poll Mode – NFC-F Discovery Parameters
#define PF_BIT_RATE                             0x18
#define PF_RC_CODE                              0x19
//RFU                                           0x1A-0x1F

//Poll Mode – ISO-DEP Discovery Parameters
#define PB_H_INFO                               0x20
#define PI_BIT_RATE                             0x21
#define PA_ADV_FEAT                             0x22
//RFU                                           0x22-0x27

//Poll Mode – NFC-DEP Discovery Parameters
#define PN_NFC_DEP_SPEED                        0x28
#define PN_ATR_REQ_GEN_BYTES                    0x29
#define PN_ATR_REQ_CONFIG                       0x2A
//RFU                                           0x2B-0x2F

//Listen Mode – NFC-A Discovery Parameters
#define LA_BIT_FRAME_SDD                        0x30
#define LA_PLATFORM_CONFIG                      0x31
#define LA_SEL_INFO                             0x32
#define LA_NFCID1                               0x33
//RFU                                           0x34-0x37

//Listen Mode – NFC-B Discovery Parameters
#define LB_SENSB_INFO                           0x38
#define LB_NFCID0                               0x39
#define LB_APPLICATION_DATA                     0x3A
#define LB_SFGI                                 0x3B
#define LB_ADC_FO                               0x3C
//RFU                                           0x3D–0x3F

//Listen Mode – NFC-F Discovery Parameters
#define LF_T3T_IDENTIFIERS                      0x40
#define LF_T3T_IDENTIFIERS_1                    0x40
#define LF_T3T_IDENTIFIERS_2                    0x41
#define LF_T3T_IDENTIFIERS_3                    0x42
#define LF_T3T_IDENTIFIERS_4                    0x43
#define LF_T3T_IDENTIFIERS_5                    0x44
#define LF_T3T_IDENTIFIERS_6                    0x45
#define LF_T3T_IDENTIFIERS_7                    0x46
#define LF_T3T_IDENTIFIERS_8                    0x47
#define LF_T3T_IDENTIFIERS_9                    0x48
#define LF_T3T_IDENTIFIERS_10                   0x49
#define LF_T3T_IDENTIFIERS_11                   0x4A
#define LF_T3T_IDENTIFIERS_12                   0x4B
#define LF_T3T_IDENTIFIERS_13                   0x4C
#define LF_T3T_IDENTIFIERS_14                   0x4D
#define LF_T3T_IDENTIFIERS_15                   0x4E
#define LF_T3T_IDENTIFIERS_16                   0x4F
#define LF_PROTOCOL_TYPE                        0x50
#define LF_T3T_PMM                              0x51
#define LF_T3T_MAX                              0x52
#define LF_T3T_FLAGS                            0x53
#define LF_CON_BITR_F                           0x54
#define LF_ADV_FEAT                             0x55
//RFU                                           0x56-0x57
//Listen Mode – ISO-DEP Discovery Parameters
#define LI_FWI                                  0x58
#define LA_HIST_BY                              0x59
#define LB_H_INFO_RESP                          0x5A
#define LI_BIT_RATE                             0x5B
//RFU                                           0x5C-0x5F

//Listen Mode – NFC-DEP Discovery Parameters
#define LN_WT                                   0x60
#define LN_ATR_RES_GEN_BYTES                    0x61
#define LN_ATR_RES_CONFIG                       0x62
//RFU                                           0x63-0x7F

//Other Parameters
#define RF_FIELD_INFO                           0x80
#define RF_NFCEE_ACTION                         0x81
#define NFCDEP_OP                               0x82
//RFU                                           0x83-0x9F
//Reserved for Proprietary Use                  0xA0-0xFE
#define BOOTLOADER_FLAG                         0xA0
#define HOST_IF_BAUDRATE                        0xA1
#define EEPROM_SETTING                          0xA2
#define LN_NFC_DEP                              0xA3    //AAC Setting
#define CID_CONFIG_CMD                          0xA4
#define SET_PICC_TIMEOUT                        0xA5
#define RNAK_COUNT                              0xA6    //DTA-Extension
#define RACK_COUNT                              0xA7    //DTA-Extension
#define DESELECT_COUNT                          0xA8    //DTA-Extension
#define HW_POWER_SAVE                           0xA9
#define TRANSCEIVE_RF_DISABLE                   0xAA    //DTA-Extension
#define RECEIVE_RF_DISABLE                      0xAB    //DTA-Extension
#define RETRY_NACK_COUNT                        0xAC    //DTA-Extension
#define RETRY_ATN_COUNT                         0xAD    //DTA-Extension
#define DSL_COUNT                               0xAE    //DTA-Extension
#define RLS_COUNT                               0xAF    //DTA-Extension
#define RATS_PARAM                              0xB0
#define GATHER_ERROR_INFO_LLC                   0xB1    //Kronegger Proprietary
#define FN_LISTEN_T1                            0xB2    //FeliCa Networks
#define FN_LISTEN_T2                            0xB3    //FeliCa Networks
#define RETRANSMISSION_TIME                     0xB4
#define GATHER_ERROR_INFO_NCI_STM               0xB5    //Kronegger Proprietary
#define FN_T3T_FWT                              0xB6    //FeliCa Networks
#define PA_T1T_CONFIG                           0xB7    //Kroneger Proprietary

//Poll Mode - NFC-V Discovery Parameters
#define PV_BITRATE                              0xD0    //Kronegger Proprietary
#define PV_FLAGS                                0xD1    //Kronegger Proprietary
#define PV_AFI                                  0xD2    //Kronegger Proprietary



/*
* Proprietary Configuration Parameter Tags
*/
#define EEPROM_CONFIG                           0x00

//Reserved for Extension                        0xFF

/*
* GID and OID Definitions
* ref. NFCForum -TS-NCI-1. 0_Candidate-1 201 2-03-07 Table 100
*/
#define GID_NCI_CORE                            0x00
#define GID_RF_MANAGEMENT                       0x01
#define GID_NFCEE_MANAGEMENT                    0x02
#define GID_PROPRIETARY                         0x0F

//NCI Core
#define OID_CORE_RESET                          0x00
#define OID_CORE_INIT                           0x01
#define OID_CORE_SET_CONFIG                     0x02
#define OID_CORE_GET_CONFIG                     0x03
#define OID_CORE_CONN_CREATE                    0x04
#define OID_CORE_CONN_CLOSE                     0x05
#define OID_CORE_CONN_CREDITS                   0x06
#define OID_CORE_GENERIC_ERROR                  0x07
#define OID_CORE_INTERFACE_ERROR                0x08
#define OID_CORE_KRONEGGER_NTF                  0x3F
//RFU						0x09-0x0F
#define OID_CORE_SET_PARAM                      0x0E
#define OID_CORE_GET_PARAM                      0x0F

//RF Management
#define OID_RF_DISCOVER_MAP                     0x00
#define OID_RF_SET_LISTEN_MODE_ROUTING	        0x01
#define OID_RF_GET_LISTEN_MODE_ROUTING	        0x02
#define OID_RF_DISCOVER                         0x03
#define OID_RF_DISCOVER_SELECT                  0x04
#define OID_RF_INTF_ACTIVATED                   0x05
#define OID_RF_DEACTIVATE                       0x06
#define OID_RF_FIELD_INFO                       0x07
#define OID_RF_T3T_POLLING                      0x08
#define OID_RF_NFCEE_ACTION                     0x09
#define OID_RF_NFCEE_DISCOVERY_REQ              0x0A
#define OID_RF_PARAMETER_UPDATE                 0x0B
//RFU						0x0C-0x0F

//NFCEE Management
#define OID_NFCEE_DISCOVER                      0x00
#define OID_NFCEE_MODE_SET                      0x01
//RFU						0x02-0x0F

//Proprietary Management
#define OID_PROP_DH_WAKEUP                      0x00
#define OID_PRESENCE_CHECK                      0x01
#define OID_PRESENCE_CHECK_DEACTIVATE           0x02
#define OID_RF_FIELD_ON                         0x03
#define OID_RF_FIELD_OFF                        0x04
#define OID_RF_SET_POLLING_MODE_ROUTING_CMD     0x05
#define OID_RF_GET_POLLING_MODE_ROUTING_CMD     0x06
#define OID_CUSTOM_INTERFACE                    0x07
//RFU                                   0x05 -  0xFE

//For Firmware Updating added by fifty @ 2013/10/24
#define OID_FWUP_DATA                           0x10
#define OID_ETCPARAM_DATA                       0x11


/*
* RF States
*/
#define RFST_IDLE                               0x01
#define RFST_DISCOVERY                          0x02
#define RFST_POLL_ACTIVE                        0x03
#define RFST_W4_HOST_SELECT                     0x04
#define RFST_W4_ALL_DISCOVERIES                 0x05
#define RFST_LISTEN_ACTIVE                      0x06
#define RFST_LISTEN_SLEEP                       0x07
/**Just for error counter index**/
#define RFSTERROR_WRONG_STATE                   0x00

/*
*State Commands
*Self defined Opcodes
*/
#define RF_DISCOVER_CMD                         0x01
#define RF_DEACTIVATE_CMD                       0x02
#define RF_DEACTIVATE_CMD_IDLE                  0x03
#define RF_DEACTIVATE_CMD_DISCOVERY             0x04
#define RF_DEACTIVATE_CMD_SLEEP                 0x05
#define RF_DEACTIVATE_CMD_SLEEP_AF              0x06
#define RF_DEACTIVATE_NTF_IDLE                  0x07
#define RF_DEACTIVATE_NTF_DISCOVERY             0x08
#define RF_DEACTIVATE_NTF_SLEEP                 0x09
#define RF_DEACTIVATE_NTF_SLEEP_AF              0x0A
#define RF_DEACTIVATE_NTF_DISCOVERY_LINK_LOSS   0x0B
#define RF_DEACTIVATE_NTF_DISCOVERY_EP_REQ      0x0C
#define RF_DEACTIVATE_NTF_DISCOVERY_NFC_B_BAD   0x0D
#define RF_DEACTIVATE_NTF_SLEEP_EP_REQ	        0x0E
#define RF_DEACTIVATE_NTF_SLEEP_AF_EP_REQ       0x0F
#define RF_INTF_ACTIVATED_NTF_POLL              0x10
#define RF_INTF_ACTIVATED_NTF_LISTEN            0x11
#define RF_DISCOVER_NTF_TYPE_2                  0x12
#define RF_DISCOVER_NTF_TYPE_0_1                0x13
#define RF_DISCOVER_SELECT_CMD                  0x14
#define RF_NFCEE_ACTION_NTF                     0x15
#define CORE_INTF_ERROR_NTF                     0x16
#define CORE_GENERIC_ERROR_NTF                  0x17
#define NFCEE_DISCOVER_REQ_NTF                  0x18 //maybe this definition is not needed, cause not needed in state machine?
#define CORE_RESET                              0x19
#define RF_FIELD_INFO_NTF                       0x1A
#define RF_DISCOVER_NTF_TYPE                    0x1B

/**
* NFCEE Action Notification Triggers
* @see NFCForum-TS-NCI-1.0 [7.5 RF NFCEE Action]
*/
#define NFCEE_TRIGGER_SELECT_COMMAND        (byte)0x00  //This trigger shall be sent by the NFCC when the NFCC is capable of determining the AID of the accessed application.
#define NFCEE_TRIGGER_PRTCL_ROUTING         (byte)0x01  //This trigger shall be sent when a routing decision is made based on the RF Protocol.
#define NFCEE_TRIGGER_TECH_ROUTING          (byte)0x02  //This trigger shall be sent when a routing decision is made based on the RF Technology.
//RFU                                       0x03 - 0x0F
#define NFCEE_TRIGGER_APP_INIT              (byte)0x10  //This trigger shall be sent when the NFCEE provides the information to the NFCC.
//RFU                                       0x11 - 0xFF

/**
* Power States
* @see NFCForum-TS-NCI-1.0 [Table 50: Value Field for Power State]
*/
#define NCI_SWITCHED_ON                     (byte)0x01
#define NCI_SWITCHED_OFF                    (byte)0x02
#define NCI_BATTERY_OFF                     (byte)0x04

/**
* Core Reset Configuration Status
* @see NFCForum-TS-NCI-1.0 [4.1 Reset of NFCC]
*/
#define CR_RESET_STATUS_CONFIG_KEPT         (byte)0x00
#define CR_RESET_STATUS_CONFIG_RESET        (byte)0x01
//RFU                                       0x02 - 0xFF

/**
* Core Reset Notification Reason Codes
* @see NFCForum-TS-NCI-1.0 [4.1 Reset of NFCC]
*/
#define CR_RESET_REASON_UNSPECIFIED         (byte)0x00
//RFU                                       0x01 - 0x9F
#define CR_RESET_REASON_WATCHDOG            (byte)0xA0

/**
*Error codes (used for check status in dispatcher.h)
*
*/
enum
{
  WRONG_RF_STATE  = 0xFFEF, //If a execution error is thrown
  WRONG_STATE_CMD = 0xFFEE //If the current state can´t handle the command
};


#define TAG_STATUS_OK                           0x0000  //If a command that was sent to the TAG returned no error

#define UID4                                    0x04    //Lenght of a 4 Byte UID
#define UID7                                    0x07    //Lenght of a 7 Byte UID
#define UID10                                   0x0A    //Lenght of a 10 Byte UID
#define TAG_STATUS_LEN                          0x02
#define MAX_EXPECTED_RECLEN                     0x14

//#define TAG_SELECT                            0x0202  //commited out cause of double definition and it is not used at the moment.
#define MAX_PAYLOAD_SIZE                        0xFF
#define HEADER_SIZE                             0x03
#define MAX_ROUT_TABLE_SIZE                     (82)    //

#define SAK_TYPE_MASK                           0x60    //To get the right bits of the SAK for type recognition
#define SAK_FRAME_RF_INTERFACE                  0x00    //SAK Bitmask for Frame Interfaces
#define SAK_ISO_DEP_RF_INTERFACE                0x20    //SAK Bitmask for ISO- DEP
#define SAK_NFC_DEP_INTERFACE                   0x40    //SAK Bitmask for NFC-DEP
#define SAK_ISO_NFC_DEP_INTERFACE               0x60    //SAK Bitmask for NFC-DEP and ISO-DEP.

#define RX_BITRATE_MASK                         0x70    //Bitrate form PICC to PCD
#define TX_BITRATE_MASK                         0x07    //Bitrate from PCD to PICC

#define BITRATE_106                             0x00
#define BITRATE_212                             0x01
#define BITRATE_424                             0x02
#define BITRATE_848                             0x04

#define BITRATE_SENSF_MASK                      0x0F

#define MAX_DEACTIVATION_COUNT                  0x05    //Maximal times deactivation is performed before

/*
*INTERN USED COMMANDS
*/
#define MAPPED_PROTOCOL_POLL                    0x00
#define MAPPED_PROTOCOL_LISTEN                  0x01

#define SET_TECH_BASED_ROUTING                  (word)0x0001

#define SET_UID_RANDOM_FLAGS                    (word)0x007F

#define DISCOVER_SELECT                         0x7575

#endif //NCI_API_H

