#ifndef __NCI_CONFIGURATION_H
#define __NCI_CONFIGURATION_H

#include "hardware.h"

/******************************************* 
* Manufacturer Configuration
* NFCForum-TS-NCI-1.0 2012-11-06
*******************************************/
//table 6/7
#define KEEP_CONFIG                     0x00
#define RESET_CONFIG                    0x01
#define REASON_CODE                     0x00
#define NCI_VERSION                     0x10
//table 9
#define NFCC_FEAT1                      0x01
#define NFCC_FEAT2                      0x0E
#define NFCC_FEAT3                      0x02
#define NFCC_FEAT4                      0x00
#define NR_OF_SUPPORTED_RF_INTERFACES   0x04
  //NFCEE Direct RF Interface
  //Frame RF Interface
  //ISO-DEP RF Interface
  //NFC-DEP RF Interface
#define MAX_LOGIC_CONN                  0x02    //used for buffer allocation, be carefull by changing it.
//#define MAX_ROUT_TABLE_SIZE1            0x00
//#define MAX_ROUT_TABLE_SIZE2            0x00
#define MAX_CTRL_PACKET_PAYL_SIZE       0xFF
#define MAX_SIZE_LARGE_PARAMS1          0x40    //used for buffer allocation, be carefull by changing it.
#define MAX_SIZE_LARGE_PARAMS2          0x00
//table 13
#define MAX_DATA_PACKET_PAYL_SIZE       0xFF

/******************************************* 
* NCI include/exclude Configuration
*******************************************/
//#define NO_LISTENMODE
//#define NO_RF_MANAGEMENT_HANDLER
//#define NO_RF_COMMUNICATION_HANDLER
//#define NO_PROPERIETARY_HANDLER
#define NO_POWERMANAGEMENT
#define NO_PRESENCE_CHECK
#define ENABLE_KRONEGGER_PACKET_HANDLER


/******************************************* 
* NFCEE Configuration 
*******************************************/
#define MAX_SUPPORTED_NFCEES            0x03    //How many real NFCEE's are supported (SE, ESE, ...)
#define HCI_ACCESS_NFCEE                0x01    //Symblos the HCI-Access NFCEE in the NFCC
#define MAX_SUPPORTED_PROTOCOLS         0x03

#define NFCEE_1                         0x00    //LLC/NfceeInterface index for SWP1
#define NFCEE_2                         0x01    //LLC/NfceeInterface index for SWP2
#define NFCEE_3                         0x02    //LLC/NfceeInterface index for SWP3
#define NFCEE_4_HCI_ACCESS              0x03    //NfceeInterface index for HCI-Access NFCEE

#define ESE_INTERFACE_IDX               (0x02)  //The physical, and logical, interface of the ESE. n-1
#define MAX_NFCEE_INTERFACES            (MAX_SUPPORTED_NFCEES - 1)  //n-1, used for array indexes and such stuff

#define NFCEE_PROTOCOL_HCI              0x00
#define NFCEE_PROTOCOL_DCLB             0x01
#define NFCEE_PROTOCOL_SPE              0x02

#define HCI_ACCESS_INTERFACE            0xE9    //Only to distinguish from the Real interfaces

/******************************************* 
* Buffer size Definitions. Be careful with them!
*******************************************/
#define MAX_APP_DATA_LEN        15  //for Type-A; @see NFCForum-TS-DigitalProtocol-1.0 [Requirements 130: Length Byte TL of the ATS]
#define MAX_HIGHER_LAYER_LEN    50  //for Type-B



#endif //__NCI_CONFIGURATION_H
