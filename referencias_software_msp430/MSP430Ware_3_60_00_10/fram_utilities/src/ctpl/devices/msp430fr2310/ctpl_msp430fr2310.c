/* --COPYRIGHT--,FRAM-Utilities
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * This source code is part of FRAM Utilities for MSP430 FRAM Microcontrollers.
 * Visit http://www.ti.com/tool/msp-fram-utilities for software information and
 * download.
 * --/COPYRIGHT--*/
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include <msp430.h>

#include <peripherals/ctpl_peripherals.h>

#ifndef __MSP430FR2310__
#error This file is only to be used with msp430fr2310, please replace this and the linker files with the correct device files.
#endif

/*
 * Comment out a line below if you would not like to save the peripheral. The
 * remainder of the file should not be modified.
 */
#define CTPL_SAVE_PORTA
#define CTPL_SAVE_PORTJ
#define CTPL_SAVE_CS
#define CTPL_SAVE_SYS
#define CTPL_SAVE_RTC
//#define CTPL_SAVE_CRC16
//#define CTPL_SAVE_TB0
//#define CTPL_SAVE_TB1
//#define CTPL_SAVE_EUSCIA0
//#define CTPL_SAVE_EUSCIB0
//#define CTPL_SAVE_ECOMP
//#define CTPL_SAVE_ADC
//#define CTPL_SAVE_SAC
//#define CTPL_SAVE_TRI
#define CTPL_SAVE_WDT_A

/*****************************************************/
/*                                                   */
/* !!! DO NOT MODIFY ANYTHING BELOW THIS COMMENT !!! */
/*                                                   */
/*****************************************************/

#ifdef CTPL_SAVE_PORTA

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_PORTA_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_PORTA_storage[CTPL_PORT_INT_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_PORTA = {
    __MSP430_BASEADDRESS_PORTA_R__,
    ctpl_PORTA_storage,
    ctpl_PORT_INT_save,
    ctpl_PORT_INT_restore,
    ctpl_PORT_INT_epilogue
};
#endif

#ifdef CTPL_SAVE_PORTJ

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_PORTJ_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_PORTJ_storage[CTPL_PORT_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_PORTJ = {
    __MSP430_BASEADDRESS_PORTJ_R__,
    ctpl_PORTJ_storage,
    ctpl_PORT_save,
    ctpl_PORT_restore,
    ctpl_PORT_epilogue
};
#endif

#ifdef CTPL_SAVE_CS

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_CS_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_CS_storage[CTPL_CS_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_CS = {
    __MSP430_BASEADDRESS_CS__,
    ctpl_CS_storage,
    ctpl_CS_save,
    ctpl_CS_restore,
    ctpl_CS_epilogue
};
#endif

#ifdef CTPL_SAVE_SYS

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_SYS_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_SYS_storage[CTPL_SYS_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_SYS = {
    __MSP430_BASEADDRESS_SYS__,
    ctpl_SYS_storage,
    ctpl_SYS_save,
    ctpl_SYS_restore,
    ctpl_SYS_epilogue
};
#endif

#ifdef CTPL_SAVE_RTC

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_RTC_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_RTC_storage[CTPL_RTC_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_RTC = {
    __MSP430_BASEADDRESS_RTC__,
    ctpl_RTC_storage,
    ctpl_RTC_save,
    ctpl_RTC_restore,
    ctpl_RTC_epilogue
};
#endif

#ifdef CTPL_SAVE_CRC16

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_CRC16_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_CRC16_storage[CTPL_CRC16_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_CRC16 = {
    __MSP430_BASEADDRESS_CRC__,
    ctpl_CRC16_storage,
    ctpl_CRC16_save,
    ctpl_CRC16_restore,
    ctpl_CRC16_epilogue
};
#endif

#ifdef CTPL_SAVE_TB0

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_TB0_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_TB0_storage[CTPL_TIMER_3_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_TB0 = {
    __MSP430_BASEADDRESS_T0B3__,
    ctpl_TB0_storage,
    ctpl_TIMER_3_save,
    ctpl_TIMER_3_restore,
    ctpl_TIMER_3_epilogue
};
#endif

#ifdef CTPL_SAVE_TB1

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_TB1_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_TB1_storage[CTPL_TIMER_3_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_TB1 = {
    __MSP430_BASEADDRESS_T1B3__,
    ctpl_TB1_storage,
    ctpl_TIMER_3_save,
    ctpl_TIMER_3_restore,
    ctpl_TIMER_3_epilogue
};
#endif

#ifdef CTPL_SAVE_EUSCIA0

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_EUSCIA0_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_EUSCIA0_storage[CTPL_EUSCI_A_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_EUSCIA0 = {
    __MSP430_BASEADDRESS_EUSCI_A0__,
    ctpl_EUSCIA0_storage,
    ctpl_EUSCI_A_save,
    ctpl_EUSCI_A_restore,
    ctpl_EUSCI_A_epilogue
};
#endif

#ifdef CTPL_SAVE_EUSCIB0

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_EUSCIB0_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_EUSCIB0_storage[CTPL_EUSCI_B_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_EUSCIB0 = {
    __MSP430_BASEADDRESS_EUSCI_B0__,
    ctpl_EUSCIB0_storage,
    ctpl_EUSCI_B_save,
    ctpl_EUSCI_B_restore,
    ctpl_EUSCI_B_epilogue
};
#endif

#ifdef CTPL_SAVE_ECOMP

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_ECOMP_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_ECOMP_storage[CTPL_ECOMP_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_ECOMP = {
    __MSP430_BASEADDRESS_ECOMP0__,
    ctpl_ECOMP_storage,
    ctpl_ECOMP_save,
    ctpl_ECOMP_restore,
    ctpl_ECOMP_epilogue
};
#endif

#ifdef CTPL_SAVE_ADC

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_ADC_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_ADC_storage[CTPL_ADC_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_ADC = {
    __MSP430_BASEADDRESS_ADC__,
    ctpl_ADC_storage,
    ctpl_ADC_save,
    ctpl_ADC_restore,
    ctpl_ADC_epilogue
};
#endif

#ifdef CTPL_SAVE_SAC

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_SAC_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_SAC_storage[CTPL_SAC_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_SAC = {
    __MSP430_BASEADDRESS_SAC0__,
    ctpl_SAC_storage,
    ctpl_SAC_save,
    ctpl_SAC_restore,
    ctpl_SAC_epilogue
};
#endif

#ifdef CTPL_SAVE_TRI

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_TRI_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_TRI_storage[CTPL_TRI_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_TRI = {
    __MSP430_BASEADDRESS_TRI0__,
    ctpl_TRI_storage,
    ctpl_TRI_save,
    ctpl_TRI_restore,
    ctpl_TRI_epilogue
};
#endif

#ifdef CTPL_SAVE_WDT_A

#if defined(__TI_COMPILER_VERSION__)
#pragma PERSISTENT(ctpl_WDT_A_storage)
#elif defined(__IAR_SYSTEMS_ICC__)
__persistent
#endif
uint16_t ctpl_WDT_A_storage[CTPL_WDT_A_STORAGE_LENGTH] = {0};

const ctpl_peripheral ctpl_WDT_A = {
    __MSP430_BASEADDRESS_WDT_A__,
    ctpl_WDT_A_storage,
    ctpl_WDT_A_save,
    ctpl_WDT_A_restore,
    ctpl_WDT_A_epilogue
};
#endif

const ctpl_peripheral * const ctpl_peripherals[] = {
#ifdef CTPL_SAVE_PORTA
    &ctpl_PORTA,
#endif
#ifdef CTPL_SAVE_PORTJ
    &ctpl_PORTJ,
#endif
#ifdef CTPL_SAVE_CS
    &ctpl_CS,
#endif
#ifdef CTPL_SAVE_SYS
    &ctpl_SYS,
#endif
#ifdef CTPL_SAVE_RTC
    &ctpl_RTC,
#endif
#ifdef CTPL_SAVE_CRC16
    &ctpl_CRC16,
#endif
#ifdef CTPL_SAVE_TB0
    &ctpl_TB0,
#endif
#ifdef CTPL_SAVE_TB1
    &ctpl_TB1,
#endif
#ifdef CTPL_SAVE_EUSCIA0
    &ctpl_EUSCIA0,
#endif
#ifdef CTPL_SAVE_EUSCIB0
    &ctpl_EUSCIB0,
#endif
#ifdef CTPL_SAVE_ECOMP
    &ctpl_ECOMP,
#endif
#ifdef CTPL_SAVE_ADC
    &ctpl_ADC,
#endif
#ifdef CTPL_SAVE_SAC
    &ctpl_SAC,
#endif
#ifdef CTPL_SAVE_TRI
    &ctpl_TRI,
#endif
#ifdef CTPL_SAVE_WDT_A
    &ctpl_WDT_A,
#endif
};

const uint16_t ctpl_peripheralsLen = (sizeof(ctpl_peripherals)/sizeof(ctpl_peripherals[0]));
