//*****************************************************************************
//
// rom_map.h - Macros to facilitate calling functions in the ROM when they are
//             available and in flash otherwise.
//
// Copyright (c) 2014 Texas Instruments Incorporated.  All rights reserved.
// TI Information - Selective Disclosure
//
//
//*****************************************************************************

#ifndef __ROM_MAP_DRIVERLIB_H__
#define __ROM_MAP_DRIVERLIB_H__

//*****************************************************************************
//
// Macros for the EUSCIASPI API.
//
//*****************************************************************************
#ifdef ROM_EUSCI_A_SPI_disableInterrupt
#define MAP_EUSCI_A_SPI_disableInterrupt                                      \
        ROM_EUSCI_A_SPI_disableInterrupt
#else
#define MAP_EUSCI_A_SPI_disableInterrupt                                      \
        EUSCI_A_SPI_disableInterrupt
#endif
#ifdef ROM_EUSCI_A_SPI_disable
#define MAP_EUSCI_A_SPI_disable                                               \
        ROM_EUSCI_A_SPI_disable
#else
#define MAP_EUSCI_A_SPI_disable                                               \
        EUSCI_A_SPI_disable
#endif
#ifdef ROM_EUSCI_A_SPI_isBusy
#define MAP_EUSCI_A_SPI_isBusy                                                \
        ROM_EUSCI_A_SPI_isBusy
#else
#define MAP_EUSCI_A_SPI_isBusy                                                \
        EUSCI_A_SPI_isBusy
#endif
#ifdef ROM_EUSCI_A_SPI_getReceiveBufferAddress
#define MAP_EUSCI_A_SPI_getReceiveBufferAddress                               \
        ROM_EUSCI_A_SPI_getReceiveBufferAddress
#else
#define MAP_EUSCI_A_SPI_getReceiveBufferAddress                               \
        EUSCI_A_SPI_getReceiveBufferAddress
#endif
#ifdef ROM_EUSCI_A_SPI_enableInterrupt
#define MAP_EUSCI_A_SPI_enableInterrupt                                       \
        ROM_EUSCI_A_SPI_enableInterrupt
#else
#define MAP_EUSCI_A_SPI_enableInterrupt                                       \
        EUSCI_A_SPI_enableInterrupt
#endif
#ifdef ROM_EUSCI_A_SPI_transmitData
#define MAP_EUSCI_A_SPI_transmitData                                          \
        ROM_EUSCI_A_SPI_transmitData
#else
#define MAP_EUSCI_A_SPI_transmitData                                          \
        EUSCI_A_SPI_transmitData
#endif
#ifdef ROM_EUSCI_A_SPI_changeMasterClock
#define MAP_EUSCI_A_SPI_changeMasterClock                                     \
        ROM_EUSCI_A_SPI_changeMasterClock
#else
#define MAP_EUSCI_A_SPI_changeMasterClock                                     \
        EUSCI_A_SPI_changeMasterClock
#endif
#ifdef ROM_EUSCI_A_SPI_initMaster
#define MAP_EUSCI_A_SPI_initMaster                                            \
        ROM_EUSCI_A_SPI_initMaster
#else
#define MAP_EUSCI_A_SPI_initMaster                                            \
        EUSCI_A_SPI_initMaster
#endif
#ifdef ROM_EUSCI_A_SPI_changeClockPhasePolarity
#define MAP_EUSCI_A_SPI_changeClockPhasePolarity                              \
        ROM_EUSCI_A_SPI_changeClockPhasePolarity
#else
#define MAP_EUSCI_A_SPI_changeClockPhasePolarity                              \
        EUSCI_A_SPI_changeClockPhasePolarity
#endif
#ifdef ROM_EUSCI_A_SPI_getInterruptStatus
#define MAP_EUSCI_A_SPI_getInterruptStatus                                    \
        ROM_EUSCI_A_SPI_getInterruptStatus
#else
#define MAP_EUSCI_A_SPI_getInterruptStatus                                    \
        EUSCI_A_SPI_getInterruptStatus
#endif
#ifdef ROM_EUSCI_A_SPI_select4PinFunctionality
#define MAP_EUSCI_A_SPI_select4PinFunctionality                               \
        ROM_EUSCI_A_SPI_select4PinFunctionality
#else
#define MAP_EUSCI_A_SPI_select4PinFunctionality                               \
        EUSCI_A_SPI_select4PinFunctionality
#endif
#ifdef ROM_EUSCI_A_SPI_initSlave
#define MAP_EUSCI_A_SPI_initSlave                                             \
        ROM_EUSCI_A_SPI_initSlave
#else
#define MAP_EUSCI_A_SPI_initSlave                                             \
        EUSCI_A_SPI_initSlave
#endif
#ifdef ROM_EUSCI_A_SPI_enable
#define MAP_EUSCI_A_SPI_enable                                                \
        ROM_EUSCI_A_SPI_enable
#else
#define MAP_EUSCI_A_SPI_enable                                                \
        EUSCI_A_SPI_enable
#endif
#ifdef ROM_EUSCI_A_SPI_getTransmitBufferAddress
#define MAP_EUSCI_A_SPI_getTransmitBufferAddress                              \
        ROM_EUSCI_A_SPI_getTransmitBufferAddress
#else
#define MAP_EUSCI_A_SPI_getTransmitBufferAddress                              \
        EUSCI_A_SPI_getTransmitBufferAddress
#endif
#ifdef ROM_EUSCI_A_SPI_clearInterrupt
#define MAP_EUSCI_A_SPI_clearInterrupt                                        \
        ROM_EUSCI_A_SPI_clearInterrupt
#else
#define MAP_EUSCI_A_SPI_clearInterrupt                                        \
        EUSCI_A_SPI_clearInterrupt
#endif
#ifdef ROM_EUSCI_A_SPI_receiveData
#define MAP_EUSCI_A_SPI_receiveData                                           \
        ROM_EUSCI_A_SPI_receiveData
#else
#define MAP_EUSCI_A_SPI_receiveData                                           \
        EUSCI_A_SPI_receiveData
#endif

//*****************************************************************************
//
// Macros for the EUSCIAUART API.
//
//*****************************************************************************
#ifdef ROM_EUSCI_A_UART_setDormant
#define MAP_EUSCI_A_UART_setDormant                                           \
        ROM_EUSCI_A_UART_setDormant
#else
#define MAP_EUSCI_A_UART_setDormant                                           \
        EUSCI_A_UART_setDormant
#endif
#ifdef ROM_EUSCI_A_UART_getTransmitBufferAddress
#define MAP_EUSCI_A_UART_getTransmitBufferAddress                             \
        ROM_EUSCI_A_UART_getTransmitBufferAddress
#else
#define MAP_EUSCI_A_UART_getTransmitBufferAddress                             \
        EUSCI_A_UART_getTransmitBufferAddress
#endif
#ifdef ROM_EUSCI_A_UART_disableInterrupt
#define MAP_EUSCI_A_UART_disableInterrupt                                     \
        ROM_EUSCI_A_UART_disableInterrupt
#else
#define MAP_EUSCI_A_UART_disableInterrupt                                     \
        EUSCI_A_UART_disableInterrupt
#endif
#ifdef ROM_EUSCI_A_UART_enable
#define MAP_EUSCI_A_UART_enable                                               \
        ROM_EUSCI_A_UART_enable
#else
#define MAP_EUSCI_A_UART_enable                                               \
        EUSCI_A_UART_enable
#endif
#ifdef ROM_EUSCI_A_UART_transmitData
#define MAP_EUSCI_A_UART_transmitData                                         \
        ROM_EUSCI_A_UART_transmitData
#else
#define MAP_EUSCI_A_UART_transmitData                                         \
        EUSCI_A_UART_transmitData
#endif
#ifdef ROM_EUSCI_A_UART_transmitBreak
#define MAP_EUSCI_A_UART_transmitBreak                                        \
        ROM_EUSCI_A_UART_transmitBreak
#else
#define MAP_EUSCI_A_UART_transmitBreak                                        \
        EUSCI_A_UART_transmitBreak
#endif
#ifdef ROM_EUSCI_A_UART_resetDormant
#define MAP_EUSCI_A_UART_resetDormant                                         \
        ROM_EUSCI_A_UART_resetDormant
#else
#define MAP_EUSCI_A_UART_resetDormant                                         \
        EUSCI_A_UART_resetDormant
#endif
#ifdef ROM_EUSCI_A_UART_init
#define MAP_EUSCI_A_UART_init                                                 \
        ROM_EUSCI_A_UART_init
#else
#define MAP_EUSCI_A_UART_init                                                 \
        EUSCI_A_UART_init
#endif
#ifdef ROM_EUSCI_A_UART_clearInterrupt
#define MAP_EUSCI_A_UART_clearInterrupt                                       \
        ROM_EUSCI_A_UART_clearInterrupt
#else
#define MAP_EUSCI_A_UART_clearInterrupt                                       \
        EUSCI_A_UART_clearInterrupt
#endif
#ifdef ROM_EUSCI_A_UART_transmitAddress
#define MAP_EUSCI_A_UART_transmitAddress                                      \
        ROM_EUSCI_A_UART_transmitAddress
#else
#define MAP_EUSCI_A_UART_transmitAddress                                      \
        EUSCI_A_UART_transmitAddress
#endif
#ifdef ROM_EUSCI_A_UART_receiveData
#define MAP_EUSCI_A_UART_receiveData                                          \
        ROM_EUSCI_A_UART_receiveData
#else
#define MAP_EUSCI_A_UART_receiveData                                          \
        EUSCI_A_UART_receiveData
#endif
#ifdef ROM_EUSCI_A_UART_enableInterrupt
#define MAP_EUSCI_A_UART_enableInterrupt                                      \
        ROM_EUSCI_A_UART_enableInterrupt
#else
#define MAP_EUSCI_A_UART_enableInterrupt                                      \
        EUSCI_A_UART_enableInterrupt
#endif
#ifdef ROM_EUSCI_A_UART_queryStatusFlags
#define MAP_EUSCI_A_UART_queryStatusFlags                                     \
        ROM_EUSCI_A_UART_queryStatusFlags
#else
#define MAP_EUSCI_A_UART_queryStatusFlags                                     \
        EUSCI_A_UART_queryStatusFlags
#endif
#ifdef ROM_EUSCI_A_UART_getReceiveBufferAddress
#define MAP_EUSCI_A_UART_getReceiveBufferAddress                              \
        ROM_EUSCI_A_UART_getReceiveBufferAddress
#else
#define MAP_EUSCI_A_UART_getReceiveBufferAddress                              \
        EUSCI_A_UART_getReceiveBufferAddress
#endif
#ifdef ROM_EUSCI_A_UART_getInterruptStatus
#define MAP_EUSCI_A_UART_getInterruptStatus                                   \
        ROM_EUSCI_A_UART_getInterruptStatus
#else
#define MAP_EUSCI_A_UART_getInterruptStatus                                   \
        EUSCI_A_UART_getInterruptStatus
#endif
#ifdef ROM_EUSCI_A_UART_selectDeglitchTime
#define MAP_EUSCI_A_UART_selectDeglitchTime                                   \
        ROM_EUSCI_A_UART_selectDeglitchTime
#else
#define MAP_EUSCI_A_UART_selectDeglitchTime                                   \
        EUSCI_A_UART_selectDeglitchTime
#endif
#ifdef ROM_EUSCI_A_UART_disable
#define MAP_EUSCI_A_UART_disable                                              \
        ROM_EUSCI_A_UART_disable
#else
#define MAP_EUSCI_A_UART_disable                                              \
        EUSCI_A_UART_disable
#endif

//*****************************************************************************
//
// Macros for the EUSCIBI2C API.
//
//*****************************************************************************
#ifdef ROM_EUSCI_B_I2C_initSlave
#define MAP_EUSCI_B_I2C_initSlave                                             \
        ROM_EUSCI_B_I2C_initSlave
#else
#define MAP_EUSCI_B_I2C_initSlave                                             \
        EUSCI_B_I2C_initSlave
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendMultiByteStop
#define MAP_EUSCI_B_I2C_masterSendMultiByteStop                               \
        ROM_EUSCI_B_I2C_masterSendMultiByteStop
#else
#define MAP_EUSCI_B_I2C_masterSendMultiByteStop                               \
        EUSCI_B_I2C_masterSendMultiByteStop
#endif
#ifdef ROM_EUSCI_B_I2C_isBusBusy
#define MAP_EUSCI_B_I2C_isBusBusy                                             \
        ROM_EUSCI_B_I2C_isBusBusy
#else
#define MAP_EUSCI_B_I2C_isBusBusy                                             \
        EUSCI_B_I2C_isBusBusy
#endif
#ifdef ROM_EUSCI_B_I2C_masterReceiveMultiByteNext
#define MAP_EUSCI_B_I2C_masterReceiveMultiByteNext                            \
        ROM_EUSCI_B_I2C_masterReceiveMultiByteNext
#else
#define MAP_EUSCI_B_I2C_masterReceiveMultiByteNext                            \
        EUSCI_B_I2C_masterReceiveMultiByteNext
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendMultiByteStartWithTimeout
#define MAP_EUSCI_B_I2C_masterSendMultiByteStartWithTimeout                   \
        ROM_EUSCI_B_I2C_masterSendMultiByteStartWithTimeout
#else
#define MAP_EUSCI_B_I2C_masterSendMultiByteStartWithTimeout                   \
        EUSCI_B_I2C_masterSendMultiByteStartWithTimeout
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendStart
#define MAP_EUSCI_B_I2C_masterSendStart                                       \
        ROM_EUSCI_B_I2C_masterSendStart
#else
#define MAP_EUSCI_B_I2C_masterSendStart                                       \
        EUSCI_B_I2C_masterSendStart
#endif
#ifdef ROM_EUSCI_B_I2C_disableInterrupt
#define MAP_EUSCI_B_I2C_disableInterrupt                                      \
        ROM_EUSCI_B_I2C_disableInterrupt
#else
#define MAP_EUSCI_B_I2C_disableInterrupt                                      \
        EUSCI_B_I2C_disableInterrupt
#endif
#ifdef ROM_EUSCI_B_I2C_initMaster
#define MAP_EUSCI_B_I2C_initMaster                                            \
        ROM_EUSCI_B_I2C_initMaster
#else
#define MAP_EUSCI_B_I2C_initMaster                                            \
        EUSCI_B_I2C_initMaster
#endif
#ifdef ROM_EUSCI_B_I2C_clearInterrupt
#define MAP_EUSCI_B_I2C_clearInterrupt                                        \
        ROM_EUSCI_B_I2C_clearInterrupt
#else
#define MAP_EUSCI_B_I2C_clearInterrupt                                        \
        EUSCI_B_I2C_clearInterrupt
#endif
#ifdef ROM_EUSCI_B_I2C_getTransmitBufferAddress
#define MAP_EUSCI_B_I2C_getTransmitBufferAddress                              \
        ROM_EUSCI_B_I2C_getTransmitBufferAddress
#else
#define MAP_EUSCI_B_I2C_getTransmitBufferAddress                              \
        EUSCI_B_I2C_getTransmitBufferAddress
#endif
#ifdef ROM_EUSCI_B_I2C_masterReceiveMultiByteFinishWithTimeout
#define MAP_EUSCI_B_I2C_masterReceiveMultiByteFinishWithTimeout               \
        ROM_EUSCI_B_I2C_masterReceiveMultiByteFinishWithTimeout
#else
#define MAP_EUSCI_B_I2C_masterReceiveMultiByteFinishWithTimeout               \
        EUSCI_B_I2C_masterReceiveMultiByteFinishWithTimeout
#endif
#ifdef ROM_EUSCI_B_I2C_masterReceiveSingleByte
#define MAP_EUSCI_B_I2C_masterReceiveSingleByte                               \
        ROM_EUSCI_B_I2C_masterReceiveSingleByte
#else
#define MAP_EUSCI_B_I2C_masterReceiveSingleByte                               \
        EUSCI_B_I2C_masterReceiveSingleByte
#endif
#ifdef ROM_EUSCI_B_I2C_setSlaveAddress
#define MAP_EUSCI_B_I2C_setSlaveAddress                                       \
        ROM_EUSCI_B_I2C_setSlaveAddress
#else
#define MAP_EUSCI_B_I2C_setSlaveAddress                                       \
        EUSCI_B_I2C_setSlaveAddress
#endif
#ifdef ROM_EUSCI_B_I2C_slaveGetData
#define MAP_EUSCI_B_I2C_slaveGetData                                          \
        ROM_EUSCI_B_I2C_slaveGetData
#else
#define MAP_EUSCI_B_I2C_slaveGetData                                          \
        EUSCI_B_I2C_slaveGetData
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendSingleByte
#define MAP_EUSCI_B_I2C_masterSendSingleByte                                  \
        ROM_EUSCI_B_I2C_masterSendSingleByte
#else
#define MAP_EUSCI_B_I2C_masterSendSingleByte                                  \
        EUSCI_B_I2C_masterSendSingleByte
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendMultiByteFinish
#define MAP_EUSCI_B_I2C_masterSendMultiByteFinish                             \
        ROM_EUSCI_B_I2C_masterSendMultiByteFinish
#else
#define MAP_EUSCI_B_I2C_masterSendMultiByteFinish                             \
        EUSCI_B_I2C_masterSendMultiByteFinish
#endif
#ifdef ROM_EUSCI_B_I2C_setMode
#define MAP_EUSCI_B_I2C_setMode                                               \
        ROM_EUSCI_B_I2C_setMode
#else
#define MAP_EUSCI_B_I2C_setMode                                               \
        EUSCI_B_I2C_setMode
#endif
#ifdef ROM_EUSCI_B_I2C_enable
#define MAP_EUSCI_B_I2C_enable                                                \
        ROM_EUSCI_B_I2C_enable
#else
#define MAP_EUSCI_B_I2C_enable                                                \
        EUSCI_B_I2C_enable
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendMultiByteNext
#define MAP_EUSCI_B_I2C_masterSendMultiByteNext                               \
        ROM_EUSCI_B_I2C_masterSendMultiByteNext
#else
#define MAP_EUSCI_B_I2C_masterSendMultiByteNext                               \
        EUSCI_B_I2C_masterSendMultiByteNext
#endif
#ifdef ROM_EUSCI_B_I2C_getMode
#define MAP_EUSCI_B_I2C_getMode                                               \
        ROM_EUSCI_B_I2C_getMode
#else
#define MAP_EUSCI_B_I2C_getMode                                               \
        EUSCI_B_I2C_getMode
#endif
#ifdef ROM_EUSCI_B_I2C_masterReceiveSingle
#define MAP_EUSCI_B_I2C_masterReceiveSingle                                   \
        ROM_EUSCI_B_I2C_masterReceiveSingle
#else
#define MAP_EUSCI_B_I2C_masterReceiveSingle                                   \
        EUSCI_B_I2C_masterReceiveSingle
#endif
#ifdef ROM_EUSCI_B_I2C_disable
#define MAP_EUSCI_B_I2C_disable                                               \
        ROM_EUSCI_B_I2C_disable
#else
#define MAP_EUSCI_B_I2C_disable                                               \
        EUSCI_B_I2C_disable
#endif
#ifdef ROM_EUSCI_B_I2C_enableInterrupt
#define MAP_EUSCI_B_I2C_enableInterrupt                                       \
        ROM_EUSCI_B_I2C_enableInterrupt
#else
#define MAP_EUSCI_B_I2C_enableInterrupt                                       \
        EUSCI_B_I2C_enableInterrupt
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendMultiByteNextWithTimeout
#define MAP_EUSCI_B_I2C_masterSendMultiByteNextWithTimeout                    \
        ROM_EUSCI_B_I2C_masterSendMultiByteNextWithTimeout
#else
#define MAP_EUSCI_B_I2C_masterSendMultiByteNextWithTimeout                    \
        EUSCI_B_I2C_masterSendMultiByteNextWithTimeout
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendSingleByteWithTimeout
#define MAP_EUSCI_B_I2C_masterSendSingleByteWithTimeout                       \
        ROM_EUSCI_B_I2C_masterSendSingleByteWithTimeout
#else
#define MAP_EUSCI_B_I2C_masterSendSingleByteWithTimeout                       \
        EUSCI_B_I2C_masterSendSingleByteWithTimeout
#endif
#ifdef ROM_EUSCI_B_I2C_slavePutData
#define MAP_EUSCI_B_I2C_slavePutData                                          \
        ROM_EUSCI_B_I2C_slavePutData
#else
#define MAP_EUSCI_B_I2C_slavePutData                                          \
        EUSCI_B_I2C_slavePutData
#endif
#ifdef ROM_EUSCI_B_I2C_masterReceiveStart
#define MAP_EUSCI_B_I2C_masterReceiveStart                                    \
        ROM_EUSCI_B_I2C_masterReceiveStart
#else
#define MAP_EUSCI_B_I2C_masterReceiveStart                                    \
        EUSCI_B_I2C_masterReceiveStart
#endif
#ifdef ROM_EUSCI_B_I2C_getReceiveBufferAddress
#define MAP_EUSCI_B_I2C_getReceiveBufferAddress                               \
        ROM_EUSCI_B_I2C_getReceiveBufferAddress
#else
#define MAP_EUSCI_B_I2C_getReceiveBufferAddress                               \
        EUSCI_B_I2C_getReceiveBufferAddress
#endif
#ifdef ROM_EUSCI_B_I2C_disableMultiMasterMode
#define MAP_EUSCI_B_I2C_disableMultiMasterMode                                \
        ROM_EUSCI_B_I2C_disableMultiMasterMode
#else
#define MAP_EUSCI_B_I2C_disableMultiMasterMode                                \
        EUSCI_B_I2C_disableMultiMasterMode
#endif
#ifdef ROM_EUSCI_B_I2C_masterReceiveMultiByteFinish
#define MAP_EUSCI_B_I2C_masterReceiveMultiByteFinish                          \
        ROM_EUSCI_B_I2C_masterReceiveMultiByteFinish
#else
#define MAP_EUSCI_B_I2C_masterReceiveMultiByteFinish                          \
        EUSCI_B_I2C_masterReceiveMultiByteFinish
#endif
#ifdef ROM_EUSCI_B_I2C_masterIsStartSent
#define MAP_EUSCI_B_I2C_masterIsStartSent                                     \
        ROM_EUSCI_B_I2C_masterIsStartSent
#else
#define MAP_EUSCI_B_I2C_masterIsStartSent                                     \
        EUSCI_B_I2C_masterIsStartSent
#endif
#ifdef ROM_EUSCI_B_I2C_enableMultiMasterMode
#define MAP_EUSCI_B_I2C_enableMultiMasterMode                                 \
        ROM_EUSCI_B_I2C_enableMultiMasterMode
#else
#define MAP_EUSCI_B_I2C_enableMultiMasterMode                                 \
        EUSCI_B_I2C_enableMultiMasterMode
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendMultiByteStart
#define MAP_EUSCI_B_I2C_masterSendMultiByteStart                              \
        ROM_EUSCI_B_I2C_masterSendMultiByteStart
#else
#define MAP_EUSCI_B_I2C_masterSendMultiByteStart                              \
        EUSCI_B_I2C_masterSendMultiByteStart
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendMultiByteStopWithTimeout
#define MAP_EUSCI_B_I2C_masterSendMultiByteStopWithTimeout                    \
        ROM_EUSCI_B_I2C_masterSendMultiByteStopWithTimeout
#else
#define MAP_EUSCI_B_I2C_masterSendMultiByteStopWithTimeout                    \
        EUSCI_B_I2C_masterSendMultiByteStopWithTimeout
#endif
#ifdef ROM_EUSCI_B_I2C_masterSendMultiByteFinishWithTimeout
#define MAP_EUSCI_B_I2C_masterSendMultiByteFinishWithTimeout                  \
        ROM_EUSCI_B_I2C_masterSendMultiByteFinishWithTimeout
#else
#define MAP_EUSCI_B_I2C_masterSendMultiByteFinishWithTimeout                  \
        EUSCI_B_I2C_masterSendMultiByteFinishWithTimeout
#endif
#ifdef ROM_EUSCI_B_I2C_masterIsStopSent
#define MAP_EUSCI_B_I2C_masterIsStopSent                                      \
        ROM_EUSCI_B_I2C_masterIsStopSent
#else
#define MAP_EUSCI_B_I2C_masterIsStopSent                                      \
        EUSCI_B_I2C_masterIsStopSent
#endif
#ifdef ROM_EUSCI_B_I2C_masterReceiveMultiByteStop
#define MAP_EUSCI_B_I2C_masterReceiveMultiByteStop                            \
        ROM_EUSCI_B_I2C_masterReceiveMultiByteStop
#else
#define MAP_EUSCI_B_I2C_masterReceiveMultiByteStop                            \
        EUSCI_B_I2C_masterReceiveMultiByteStop
#endif
#ifdef ROM_EUSCI_B_I2C_getInterruptStatus
#define MAP_EUSCI_B_I2C_getInterruptStatus                                    \
        ROM_EUSCI_B_I2C_getInterruptStatus
#else
#define MAP_EUSCI_B_I2C_getInterruptStatus                                    \
        EUSCI_B_I2C_getInterruptStatus
#endif

//*****************************************************************************
//
// Macros for the EUSCIBSPI API.
//
//*****************************************************************************
#ifdef ROM_EUSCI_B_SPI_enableInterrupt
#define MAP_EUSCI_B_SPI_enableInterrupt                                       \
        ROM_EUSCI_B_SPI_enableInterrupt
#else
#define MAP_EUSCI_B_SPI_enableInterrupt                                       \
        EUSCI_B_SPI_enableInterrupt
#endif
#ifdef ROM_EUSCI_B_SPI_disable
#define MAP_EUSCI_B_SPI_disable                                               \
        ROM_EUSCI_B_SPI_disable
#else
#define MAP_EUSCI_B_SPI_disable                                               \
        EUSCI_B_SPI_disable
#endif
#ifdef ROM_EUSCI_B_SPI_clearInterrupt
#define MAP_EUSCI_B_SPI_clearInterrupt                                        \
        ROM_EUSCI_B_SPI_clearInterrupt
#else
#define MAP_EUSCI_B_SPI_clearInterrupt                                        \
        EUSCI_B_SPI_clearInterrupt
#endif
#ifdef ROM_EUSCI_B_SPI_isBusy
#define MAP_EUSCI_B_SPI_isBusy                                                \
        ROM_EUSCI_B_SPI_isBusy
#else
#define MAP_EUSCI_B_SPI_isBusy                                                \
        EUSCI_B_SPI_isBusy
#endif
#ifdef ROM_EUSCI_B_SPI_getReceiveBufferAddress
#define MAP_EUSCI_B_SPI_getReceiveBufferAddress                               \
        ROM_EUSCI_B_SPI_getReceiveBufferAddress
#else
#define MAP_EUSCI_B_SPI_getReceiveBufferAddress                               \
        EUSCI_B_SPI_getReceiveBufferAddress
#endif
#ifdef ROM_EUSCI_B_SPI_changeMasterClock
#define MAP_EUSCI_B_SPI_changeMasterClock                                     \
        ROM_EUSCI_B_SPI_changeMasterClock
#else
#define MAP_EUSCI_B_SPI_changeMasterClock                                     \
        EUSCI_B_SPI_changeMasterClock
#endif
#ifdef ROM_EUSCI_B_SPI_transmitData
#define MAP_EUSCI_B_SPI_transmitData                                          \
        ROM_EUSCI_B_SPI_transmitData
#else
#define MAP_EUSCI_B_SPI_transmitData                                          \
        EUSCI_B_SPI_transmitData
#endif
#ifdef ROM_EUSCI_B_SPI_select4PinFunctionality
#define MAP_EUSCI_B_SPI_select4PinFunctionality                               \
        ROM_EUSCI_B_SPI_select4PinFunctionality
#else
#define MAP_EUSCI_B_SPI_select4PinFunctionality                               \
        EUSCI_B_SPI_select4PinFunctionality
#endif
#ifdef ROM_EUSCI_B_SPI_initSlave
#define MAP_EUSCI_B_SPI_initSlave                                             \
        ROM_EUSCI_B_SPI_initSlave
#else
#define MAP_EUSCI_B_SPI_initSlave                                             \
        EUSCI_B_SPI_initSlave
#endif
#ifdef ROM_EUSCI_B_SPI_disableInterrupt
#define MAP_EUSCI_B_SPI_disableInterrupt                                      \
        ROM_EUSCI_B_SPI_disableInterrupt
#else
#define MAP_EUSCI_B_SPI_disableInterrupt                                      \
        EUSCI_B_SPI_disableInterrupt
#endif
#ifdef ROM_EUSCI_B_SPI_getTransmitBufferAddress
#define MAP_EUSCI_B_SPI_getTransmitBufferAddress                              \
        ROM_EUSCI_B_SPI_getTransmitBufferAddress
#else
#define MAP_EUSCI_B_SPI_getTransmitBufferAddress                              \
        EUSCI_B_SPI_getTransmitBufferAddress
#endif
#ifdef ROM_EUSCI_B_SPI_changeClockPhasePolarity
#define MAP_EUSCI_B_SPI_changeClockPhasePolarity                              \
        ROM_EUSCI_B_SPI_changeClockPhasePolarity
#else
#define MAP_EUSCI_B_SPI_changeClockPhasePolarity                              \
        EUSCI_B_SPI_changeClockPhasePolarity
#endif
#ifdef ROM_EUSCI_B_SPI_receiveData
#define MAP_EUSCI_B_SPI_receiveData                                           \
        ROM_EUSCI_B_SPI_receiveData
#else
#define MAP_EUSCI_B_SPI_receiveData                                           \
        EUSCI_B_SPI_receiveData
#endif
#ifdef ROM_EUSCI_B_SPI_getInterruptStatus
#define MAP_EUSCI_B_SPI_getInterruptStatus                                    \
        ROM_EUSCI_B_SPI_getInterruptStatus
#else
#define MAP_EUSCI_B_SPI_getInterruptStatus                                    \
        EUSCI_B_SPI_getInterruptStatus
#endif
#ifdef ROM_EUSCI_B_SPI_initMaster
#define MAP_EUSCI_B_SPI_initMaster                                            \
        ROM_EUSCI_B_SPI_initMaster
#else
#define MAP_EUSCI_B_SPI_initMaster                                            \
        EUSCI_B_SPI_initMaster
#endif
#ifdef ROM_EUSCI_B_SPI_enable
#define MAP_EUSCI_B_SPI_enable                                                \
        ROM_EUSCI_B_SPI_enable
#else
#define MAP_EUSCI_B_SPI_enable                                                \
        EUSCI_B_SPI_enable
#endif

#endif // __ROM_MAP_DRIVERLIB_H__
