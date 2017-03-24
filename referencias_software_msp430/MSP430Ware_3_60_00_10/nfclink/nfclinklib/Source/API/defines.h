#ifndef _DEFINES_H_
#define _DEFINES_H_

/**
* ISO/IEC 14443-3 and 14443-4 related defines
* Also NFCForum-TS-DigitalProtocol
*/
#define TYPEA_SAK_LEN                   0x01
#define TYPEA_ATQA_LEN                  0x02

#define TYPEA_SLP_REQ_BYTE_1            0x50 /* ISO 6.3.3 HLTA Command, lenght 2byte 50h 00h */
#define TYPEA_SLP_REQ_BYTE_2            0x00
#define TYPEA_SLP_REQ_LENGTH            0x02 /* Length of HTLA command SHALL be 2 */

#define TYPEB_SLP_REQ_BYTE_1            0x50 /* Digital 5.8.1 SLPB_REQ Command */
#define TYPEB_SLP_REQ_LENGTH            0x05
#define TYPEB_SLP_RES                   0x00 /* Digital 5.8.2 SLPB_RES Response */

#define ISO_PPS_MIN_LENGTH              0x02 /* The PPS Req is at minimum 2 bytes long (PPS + PPS0) */
#define ISO_PPS_MAX_LENGTH              0x03 /* The PPS Req is at maximum 3 bytes long (PPS + PPS0 + PPS1) */
#define PPS0_RFU_MASK                   0xEF /* b2-4 and b6-8 shall be set to 0, b1 shall be set to 1. All other values are RFU! */
#define PPS0_RFU_MASK_VALUE             0x01 /* PPS0 SHALL be set to 000X 0001, all other values are RFU! */
#define PPS1_AVAILABLE_MASK             0x10 /* b5 indicates if PPS1 is transmitted if set to 1 */
#define PPS1_RFU_MASK                   0xF0 /* Higher nibble of PPS1 shall be set to 0, all other values are RFU! */
#define PPS1_RFU_MASK_VALUE             0x00 /* PPS1 SHALL be 0000 XXXX, all other values are RFU! */

//NFC-Forum-TS-DigitalProtocol-1.0 Table 116 defines GT_F as 20ms. 
#define GT_F                        (byte)20 //ms
#define PCD_GT_F                    (byte)1 //ms   Exact value of TR0F,Poll,min = (int)((106*64+16)/13.56/1000) = 0,5 ms
#define MAX_SENSF_RES_LEN           (byte)20    //@see NFCForum-TS-DigitalProtocol-1.0 [6.6.2 SENSF_RES Response]

/**
* NFC-DEP and ISO-DEP Protocol Timing values
*/
#define WT_MAX_TARGET               (byte)0x0A  //@see NFCForum-TS-DigitalProtocol 1.0 [14.6.3 ATR_RES Response TO Format; Appendix A.10]
#define FDT_F_LISTEN_MIN            (word)425   //@see NFCForum-TS-DigitalProtocol-1.0 [6.7.1 Frame Delay Time Poll->Listen]
#define FDT_A_POLL_MIN              (word)500   //@see NFCForum-TS-DigitalProtocol-1.0 [A.1 NFC-A Technology]
#define ATR_REQ_MIN_WT              (word)1250  //@see NFCForum-TS-DigitalProtocol-1.0 [Requirements 212: Response Waiting Time] 14.11.1.3 ((+ reserve of 12ms!))
#define T_RETRANSMISSION_MAX        (word)1238  //@see NFCForum-TS-DigitalProtocol-1.0 [Requirements 212:
#define ISO_DEP_FWT_DEACTIVATION    (byte)0x06  //@see NFCForum-TS-DigitalProtocol 1.0 [A.9 ISO-DEP Protocol]
#define FWT_MAXIMUM                 (word)4960  //@see NFCForum-TS-DigitalProtocol 1.0 [11.7.1 FWT] (maximum is 4949ms but some margin has been added!)
#define WAITING_TIME_MAX            FWT_MAXIMUM //@see NFCForum-TS-DigitalProtocol 1.0 [14.11 Timing Requirements] (Same calculation as FWT + reserve added of 11ms!)


/**
* Mifare Classic SAK and ATQA values to distinguish which Classic it is
* @see AN10833 MIFARE Type Identification Procedure Rev. 3.2 - 29 August 2011
*/
#define NXP_MIFARE_MINI_SAK             (byte)0x09
#define NXP_MIFARE_CLASSIC_1K_SAK       (byte)0x08
#define NXP_MIFARE_CLASSIC_4k_SAK       (byte)0x18

#define NXP_MIFARE_CLASSIC_ATQA_B1      (byte)0x00
#define NXP_MIFARE_MINI_ATQA_B2         (byte)0x04
#define NXP_MIFARE_CLASSIC_1K_ATQA_B2   (byte)0x04
#define NXP_MIFARE_CLASSIC_4K_ATQA_B2   (byte)0x02


#endif //_DEFINES_H_
