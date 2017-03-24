/* --COPYRIGHT--,BSD
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// rom_captivate_map.h - Macros to facilitate calling functions in the ROM
// when they are available and in flash otherwise.
//
// Copyright (c) 2013 Texas Instruments Incorporated.  All rights reserved.
// TI Information - Selective Disclosure
//
//! \version 1.04.00.00
//! Released on Mon, Aug 15, 2016  5:06:13 PM
//
//*****************************************************************************

#ifndef __ROM_CAPTIVATE_MAP_H__
#define __ROM_CAPTIVATE_MAP_H__

//*****************************************************************************
//
// Macros for the CAPTIVATE API.
//
//*****************************************************************************
#ifdef ROM_CAPT_selectTimerSource
#define MAP_CAPT_selectTimerSource                                            \
        ROM_CAPT_selectTimerSource
#else
#define MAP_CAPT_selectTimerSource                                            \
        CAPT_selectTimerSource
#endif
#ifdef ROM_CAPT_computeArcTanApprox
#define MAP_CAPT_computeArcTanApprox                                          \
        ROM_CAPT_computeArcTanApprox
#else
#define MAP_CAPT_computeArcTanApprox                                          \
        CAPT_computeArcTanApprox
#endif
#ifdef ROM_CAPT_clearChannelOffState
#define MAP_CAPT_clearChannelOffState                                         \
        ROM_CAPT_clearChannelOffState
#else
#define MAP_CAPT_clearChannelOffState                                         \
        CAPT_clearChannelOffState
#endif
#ifdef ROM_CAPT_clearTimer
#define MAP_CAPT_clearTimer                                                   \
        ROM_CAPT_clearTimer
#else
#define MAP_CAPT_clearTimer                                                   \
        CAPT_clearTimer
#endif
#ifdef ROM_CAPT_getChecksum
#define MAP_CAPT_getChecksum                                                  \
        ROM_CAPT_getChecksum
#else
#define MAP_CAPT_getChecksum                                                  \
        CAPT_getChecksum
#endif
#ifdef ROM_CAPT_verifyChecksum
#define MAP_CAPT_verifyChecksum                                               \
        ROM_CAPT_verifyChecksum
#else
#define MAP_CAPT_verifyChecksum                                               \
        CAPT_verifyChecksum
#endif
#ifdef ROM_CAPT_updateTouch
#define MAP_CAPT_updateTouch                                                  \
        ROM_CAPT_updateTouch
#else
#define MAP_CAPT_updateTouch                                                  \
        CAPT_updateTouch
#endif
#ifdef ROM_CAPT_getCyclePacket
#define MAP_CAPT_getCyclePacket                                               \
        ROM_CAPT_getCyclePacket
#else
#define MAP_CAPT_getCyclePacket                                               \
        CAPT_getCyclePacket
#endif
#ifdef ROM_CAPT_clearCAPLPMCFG
#define MAP_CAPT_clearCAPLPMCFG                                               \
        ROM_CAPT_clearCAPLPMCFG
#else
#define MAP_CAPT_clearCAPLPMCFG                                               \
        CAPT_clearCAPLPMCFG
#endif
#ifdef ROM_CAPT_clearChannelOnState
#define MAP_CAPT_clearChannelOnState                                          \
        ROM_CAPT_clearChannelOnState
#else
#define MAP_CAPT_clearChannelOnState                                          \
        CAPT_clearChannelOnState
#endif
#ifdef ROM_CAPT_pollResetStatus
#define MAP_CAPT_pollResetStatus                                              \
        ROM_CAPT_pollResetStatus
#else
#define MAP_CAPT_pollResetStatus                                              \
        CAPT_pollResetStatus
#endif
#ifdef ROM_CAPT_pollCIPF
#define MAP_CAPT_pollCIPF                                                     \
        ROM_CAPT_pollCIPF
#else
#define MAP_CAPT_pollCIPF                                                     \
        CAPT_pollCIPF
#endif
#ifdef ROM_CAPT_computeWheelWrap
#define MAP_CAPT_computeWheelWrap                                             \
        ROM_CAPT_computeWheelWrap
#else
#define MAP_CAPT_computeWheelWrap                                             \
        CAPT_computeWheelWrap
#endif
#ifdef ROM_CAPT_powerOn
#define MAP_CAPT_powerOn                                                      \
        ROM_CAPT_powerOn
#else
#define MAP_CAPT_powerOn                                                      \
        CAPT_powerOn
#endif
#ifdef ROM_CAPT_startTimer
#define MAP_CAPT_startTimer                                                   \
        ROM_CAPT_startTimer
#else
#define MAP_CAPT_startTimer                                                   \
        CAPT_startTimer
#endif
#ifdef ROM_CAPT_accessSensorParameter
#define MAP_CAPT_accessSensorParameter                                        \
        ROM_CAPT_accessSensorParameter
#else
#define MAP_CAPT_accessSensorParameter                                        \
        CAPT_accessSensorParameter
#endif
#ifdef ROM_CAPT_clearCAPSTART
#define MAP_CAPT_clearCAPSTART                                                \
        ROM_CAPT_clearCAPSTART
#else
#define MAP_CAPT_clearCAPSTART                                                \
        CAPT_clearCAPSTART
#endif
#ifdef ROM_CAPT_processSlider
#define MAP_CAPT_processSlider                                                \
        ROM_CAPT_processSlider
#else
#define MAP_CAPT_processSlider                                                \
        CAPT_processSlider
#endif
#ifdef ROM_CAPT_stopTimer
#define MAP_CAPT_stopTimer                                                    \
        ROM_CAPT_stopTimer
#else
#define MAP_CAPT_stopTimer                                                    \
        CAPT_stopTimer
#endif
#ifdef ROM_CAPT_setChannelOnState
#define MAP_CAPT_setChannelOnState                                            \
        ROM_CAPT_setChannelOnState
#else
#define MAP_CAPT_setChannelOnState                                            \
        CAPT_setChannelOnState
#endif
#ifdef ROM_CAPT_initByteQueue
#define MAP_CAPT_initByteQueue                                                \
        ROM_CAPT_initByteQueue
#else
#define MAP_CAPT_initByteQueue                                                \
        CAPT_initByteQueue
#endif
#ifdef ROM_CAPT_reseedFilterAll
#define MAP_CAPT_reseedFilterAll                                              \
        ROM_CAPT_reseedFilterAll
#else
#define MAP_CAPT_reseedFilterAll                                              \
        CAPT_reseedFilterAll
#endif
#ifdef ROM_CAPT_writeOffsetTap
#define MAP_CAPT_writeOffsetTap                                               \
        ROM_CAPT_writeOffsetTap
#else
#define MAP_CAPT_writeOffsetTap                                               \
        CAPT_writeOffsetTap
#endif
#ifdef ROM_CAPT_setChannelOffState
#define MAP_CAPT_setChannelOffState                                           \
        ROM_CAPT_setChannelOffState
#else
#define MAP_CAPT_setChannelOffState                                           \
        CAPT_setChannelOffState
#endif
#ifdef ROM_CAPT_readOffsetTap
#define MAP_CAPT_readOffsetTap                                                \
        ROM_CAPT_readOffsetTap
#else
#define MAP_CAPT_readOffsetTap                                                \
        CAPT_readOffsetTap
#endif
#ifdef ROM_CAPT_enableISR
#define MAP_CAPT_enableISR                                                    \
        ROM_CAPT_enableISR
#else
#define MAP_CAPT_enableISR                                                    \
        CAPT_enableISR
#endif
#ifdef ROM_CAPT_disableSensorSyncEvent
#define MAP_CAPT_disableSensorSyncEvent                                       \
        ROM_CAPT_disableSensorSyncEvent
#else
#define MAP_CAPT_disableSensorSyncEvent                                       \
        CAPT_disableSensorSyncEvent
#endif
#ifdef ROM_CAPT_readConversion
#define MAP_CAPT_readConversion                                               \
        ROM_CAPT_readConversion
#else
#define MAP_CAPT_readConversion                                               \
        CAPT_readConversion
#endif
#ifdef ROM_CAPT_clearCCounter
#define MAP_CAPT_clearCCounter                                                \
        ROM_CAPT_clearCCounter
#else
#define MAP_CAPT_clearCCounter                                                \
        CAPT_clearCCounter
#endif
#ifdef ROM_CAPT_updateProx
#define MAP_CAPT_updateProx                                                   \
        ROM_CAPT_updateProx
#else
#define MAP_CAPT_updateProx                                                   \
        CAPT_updateProx
#endif
#ifdef ROM_CAPT_isByteQueueEmpty
#define MAP_CAPT_isByteQueueEmpty                                             \
        ROM_CAPT_isByteQueueEmpty
#else
#define MAP_CAPT_isByteQueueEmpty                                             \
        CAPT_isByteQueueEmpty
#endif
#ifdef ROM_CAPT_readTimerCompRegister
#define MAP_CAPT_readTimerCompRegister                                        \
        ROM_CAPT_readTimerCompRegister
#else
#define MAP_CAPT_readTimerCompRegister                                        \
        CAPT_readTimerCompRegister
#endif
#ifdef ROM_CAPT_applySensorFreq
#define MAP_CAPT_applySensorFreq                                              \
        ROM_CAPT_applySensorFreq
#else
#define MAP_CAPT_applySensorFreq                                              \
        CAPT_applySensorFreq
#endif
#ifdef ROM_CAPT_saveCycleResults
#define MAP_CAPT_saveCycleResults                                             \
        ROM_CAPT_saveCycleResults
#else
#define MAP_CAPT_saveCycleResults                                             \
        CAPT_saveCycleResults
#endif
#ifdef ROM_CAPT_togglePingPongBuffer
#define MAP_CAPT_togglePingPongBuffer                                         \
        ROM_CAPT_togglePingPongBuffer
#else
#define MAP_CAPT_togglePingPongBuffer                                         \
        CAPT_togglePingPongBuffer
#endif
#ifdef ROM_CAPT_powerOff
#define MAP_CAPT_powerOff                                                     \
        ROM_CAPT_powerOff
#else
#define MAP_CAPT_powerOff                                                     \
        CAPT_powerOff
#endif
#ifdef ROM_CAPT_clearChannelEnable
#define MAP_CAPT_clearChannelEnable                                           \
        ROM_CAPT_clearChannelEnable
#else
#define MAP_CAPT_clearChannelEnable                                           \
        CAPT_clearChannelEnable
#endif
#ifdef ROM_CAPT_reset
#define MAP_CAPT_reset                                                        \
        ROM_CAPT_reset
#else
#define MAP_CAPT_reset                                                        \
        CAPT_reset
#endif
#ifdef ROM_CAPT_setChannelEnable
#define MAP_CAPT_setChannelEnable                                             \
        ROM_CAPT_setChannelEnable
#else
#define MAP_CAPT_setChannelEnable                                             \
        CAPT_setChannelEnable
#endif
#ifdef ROM_CAPT_updateFilterCount
#define MAP_CAPT_updateFilterCount                                            \
        ROM_CAPT_updateFilterCount
#else
#define MAP_CAPT_updateFilterCount                                            \
        CAPT_updateFilterCount
#endif
#ifdef ROM_CAPT_writeCoarseGain
#define MAP_CAPT_writeCoarseGain                                              \
        ROM_CAPT_writeCoarseGain
#else
#define MAP_CAPT_writeCoarseGain                                              \
        CAPT_writeCoarseGain
#endif
#ifdef ROM_CAPT_computeSliderVectors
#define MAP_CAPT_computeSliderVectors                                         \
        ROM_CAPT_computeSliderVectors
#else
#define MAP_CAPT_computeSliderVectors                                         \
        CAPT_computeSliderVectors
#endif
#ifdef ROM_CAPT_readFineGain
#define MAP_CAPT_readFineGain                                                 \
        ROM_CAPT_readFineGain
#else
#define MAP_CAPT_readFineGain                                                 \
        CAPT_readFineGain
#endif
#ifdef ROM_CAPT_applySensorParams
#define MAP_CAPT_applySensorParams                                            \
        ROM_CAPT_applySensorParams
#else
#define MAP_CAPT_applySensorParams                                            \
        CAPT_applySensorParams
#endif
#ifdef ROM_CAPT_stuffSyncBytes
#define MAP_CAPT_stuffSyncBytes                                               \
        ROM_CAPT_stuffSyncBytes
#else
#define MAP_CAPT_stuffSyncBytes                                               \
        CAPT_stuffSyncBytes
#endif
#ifdef ROM_CAPT_engageFSM
#define MAP_CAPT_engageFSM                                                    \
        ROM_CAPT_engageFSM
#else
#define MAP_CAPT_engageFSM                                                    \
        CAPT_engageFSM
#endif
#ifdef ROM_CAPT_enableRefCap
#define MAP_CAPT_enableRefCap                                                 \
        ROM_CAPT_enableRefCap
#else
#define MAP_CAPT_enableRefCap                                                 \
        CAPT_enableRefCap
#endif
#ifdef ROM_CAPT_stopCCounter
#define MAP_CAPT_stopCCounter                                                 \
        ROM_CAPT_stopCCounter
#else
#define MAP_CAPT_stopCCounter                                                 \
        CAPT_stopCCounter
#endif
#ifdef ROM_CAPT_processReceivedData
#define MAP_CAPT_processReceivedData                                          \
        ROM_CAPT_processReceivedData
#else
#define MAP_CAPT_processReceivedData                                          \
        CAPT_processReceivedData
#endif
#ifdef ROM_CAPT_enableSensorIO
#define MAP_CAPT_enableSensorIO                                               \
        ROM_CAPT_enableSensorIO
#else
#define MAP_CAPT_enableSensorIO                                               \
        CAPT_enableSensorIO
#endif
#ifdef ROM_CAPT_computeIIRFilterFast
#define MAP_CAPT_computeIIRFilterFast                                         \
        ROM_CAPT_computeIIRFilterFast
#else
#define MAP_CAPT_computeIIRFilterFast                                         \
        CAPT_computeIIRFilterFast
#endif
#ifdef ROM_CAPT_clearCycleIO
#define MAP_CAPT_clearCycleIO                                                 \
        ROM_CAPT_clearCycleIO
#else
#define MAP_CAPT_clearCycleIO                                                 \
        CAPT_clearCycleIO
#endif
#ifdef ROM_CAPT_disableSensorIO
#define MAP_CAPT_disableSensorIO                                              \
        ROM_CAPT_disableSensorIO
#else
#define MAP_CAPT_disableSensorIO                                              \
        CAPT_disableSensorIO
#endif
#ifdef ROM_CAPT_clearSensorProxTouch
#define MAP_CAPT_clearSensorProxTouch                                         \
        ROM_CAPT_clearSensorProxTouch
#else
#define MAP_CAPT_clearSensorProxTouch                                         \
        CAPT_clearSensorProxTouch
#endif
#ifdef ROM_CAPT_selectCCounterInterval
#define MAP_CAPT_selectCCounterInterval                                       \
        ROM_CAPT_selectCCounterInterval
#else
#define MAP_CAPT_selectCCounterInterval                                       \
        CAPT_selectCCounterInterval
#endif
#ifdef ROM_CAPT_setCycleIO
#define MAP_CAPT_setCycleIO                                                   \
        ROM_CAPT_setCycleIO
#else
#define MAP_CAPT_setCycleIO                                                   \
        CAPT_setCycleIO
#endif
#ifdef ROM_CAPT_initPingPongBuffer
#define MAP_CAPT_initPingPongBuffer                                           \
        ROM_CAPT_initPingPongBuffer
#else
#define MAP_CAPT_initPingPongBuffer                                           \
        CAPT_initPingPongBuffer
#endif
#ifdef ROM_CAPT_pushOntoByteQueue
#define MAP_CAPT_pushOntoByteQueue                                            \
        ROM_CAPT_pushOntoByteQueue
#else
#define MAP_CAPT_pushOntoByteQueue                                            \
        CAPT_pushOntoByteQueue
#endif
#ifdef ROM_CAPT_writeTimerCompRegister
#define MAP_CAPT_writeTimerCompRegister                                       \
        ROM_CAPT_writeTimerCompRegister
#else
#define MAP_CAPT_writeTimerCompRegister                                       \
        CAPT_writeTimerCompRegister
#endif
#ifdef ROM_CAPT_readTimerRegister
#define MAP_CAPT_readTimerRegister                                            \
        ROM_CAPT_readTimerRegister
#else
#define MAP_CAPT_readTimerRegister                                            \
        CAPT_readTimerRegister
#endif
#ifdef ROM_CAPT_initSensorIO
#define MAP_CAPT_initSensorIO                                                 \
        ROM_CAPT_initSensorIO
#else
#define MAP_CAPT_initSensorIO                                                 \
        CAPT_initSensorIO
#endif
#ifdef ROM_CAPT_writeFineGain
#define MAP_CAPT_writeFineGain                                                \
        ROM_CAPT_writeFineGain
#else
#define MAP_CAPT_writeFineGain                                                \
        CAPT_writeFineGain
#endif
#ifdef ROM_CAPT_startCCounter
#define MAP_CAPT_startCCounter                                                \
        ROM_CAPT_startCCounter
#else
#define MAP_CAPT_startCCounter                                                \
        CAPT_startCCounter
#endif
#ifdef ROM_CAPT_applyCycleFSM
#define MAP_CAPT_applyCycleFSM                                                \
        ROM_CAPT_applyCycleFSM
#else
#define MAP_CAPT_applyCycleFSM                                                \
        CAPT_applyCycleFSM
#endif
#ifdef ROM_CAPT_updateFilterCounts
#define MAP_CAPT_updateFilterCounts                                           \
        ROM_CAPT_updateFilterCounts
#else
#define MAP_CAPT_updateFilterCounts                                           \
        CAPT_updateFilterCounts
#endif
#ifdef ROM_CAPT_setCAPSTART
#define MAP_CAPT_setCAPSTART                                                  \
        ROM_CAPT_setCAPSTART
#else
#define MAP_CAPT_setCAPSTART                                                  \
        CAPT_setCAPSTART
#endif
#ifdef ROM_CAPT_reseedFilter
#define MAP_CAPT_reseedFilter                                                 \
        ROM_CAPT_reseedFilter
#else
#define MAP_CAPT_reseedFilter                                                 \
        CAPT_reseedFilter
#endif
#ifdef ROM_CAPT_saveCycleRawResults
#define MAP_CAPT_saveCycleRawResults                                          \
        ROM_CAPT_saveCycleRawResults
#else
#define MAP_CAPT_saveCycleRawResults                                          \
        CAPT_saveCycleRawResults
#endif
#ifdef ROM_CAPT_updateFSMTouch
#define MAP_CAPT_updateFSMTouch                                               \
        ROM_CAPT_updateFSMTouch
#else
#define MAP_CAPT_updateFSMTouch                                               \
        CAPT_updateFSMTouch
#endif
#ifdef ROM_CAPT_setCAPLPMCFG
#define MAP_CAPT_setCAPLPMCFG                                                 \
        ROM_CAPT_setCAPLPMCFG
#else
#define MAP_CAPT_setCAPLPMCFG                                                 \
        CAPT_setCAPLPMCFG
#endif
#ifdef ROM_CAPT_getByteQueueSize
#define MAP_CAPT_getByteQueueSize                                             \
        ROM_CAPT_getByteQueueSize
#else
#define MAP_CAPT_getByteQueueSize                                             \
        CAPT_getByteQueueSize
#endif
#ifdef ROM_CAPT_setChannelActive
#define MAP_CAPT_setChannelActive                                             \
        ROM_CAPT_setChannelActive
#else
#define MAP_CAPT_setChannelActive                                             \
        CAPT_setChannelActive
#endif
#ifdef ROM_CAPT_pullFromByteQueue
#define MAP_CAPT_pullFromByteQueue                                            \
        ROM_CAPT_pullFromByteQueue
#else
#define MAP_CAPT_pullFromByteQueue                                            \
        CAPT_pullFromByteQueue
#endif
#ifdef ROM_CAPT_updateFSMProx
#define MAP_CAPT_updateFSMProx                                                \
        ROM_CAPT_updateFSMProx
#else
#define MAP_CAPT_updateFSMProx                                                \
        CAPT_updateFSMProx
#endif
#ifdef ROM_CAPT_disableTimerTrigMeasurement
#define MAP_CAPT_disableTimerTrigMeasurement                                  \
        ROM_CAPT_disableTimerTrigMeasurement
#else
#define MAP_CAPT_disableTimerTrigMeasurement                                  \
        CAPT_disableTimerTrigMeasurement
#endif
#ifdef ROM_CAPT_selectTimerSourceDivider
#define MAP_CAPT_selectTimerSourceDivider                                     \
        ROM_CAPT_selectTimerSourceDivider
#else
#define MAP_CAPT_selectTimerSourceDivider                                     \
        CAPT_selectTimerSourceDivider
#endif
#ifdef ROM_CAPT_processButtons
#define MAP_CAPT_processButtons                                               \
        ROM_CAPT_processButtons
#else
#define MAP_CAPT_processButtons                                               \
        CAPT_processButtons
#endif
#ifdef ROM_CAPT_disableRefCap
#define MAP_CAPT_disableRefCap                                                \
        ROM_CAPT_disableRefCap
#else
#define MAP_CAPT_disableRefCap                                                \
        CAPT_disableRefCap
#endif
#ifdef ROM_CAPT_releaseStabilization
#define MAP_CAPT_releaseStabilization                                         \
        ROM_CAPT_releaseStabilization
#else
#define MAP_CAPT_releaseStabilization                                         \
        CAPT_releaseStabilization
#endif
#ifdef ROM_CAPT_enableTimerTrigMeasurement
#define MAP_CAPT_enableTimerTrigMeasurement                                   \
        ROM_CAPT_enableTimerTrigMeasurement
#else
#define MAP_CAPT_enableTimerTrigMeasurement                                   \
        CAPT_enableTimerTrigMeasurement
#endif
#ifdef ROM_CAPT_enableSensorSyncEvent
#define MAP_CAPT_enableSensorSyncEvent                                        \
        ROM_CAPT_enableSensorSyncEvent
#else
#define MAP_CAPT_enableSensorSyncEvent                                        \
        CAPT_enableSensorSyncEvent
#endif
#ifdef ROM_CAPT_bypassFSM
#define MAP_CAPT_bypassFSM                                                    \
        ROM_CAPT_bypassFSM
#else
#define MAP_CAPT_bypassFSM                                                    \
        CAPT_bypassFSM
#endif
#ifdef ROM_CAPT_updateLTA
#define MAP_CAPT_updateLTA                                                    \
        ROM_CAPT_updateLTA
#else
#define MAP_CAPT_updateLTA                                                    \
        CAPT_updateLTA
#endif
#ifdef ROM_CAPT_readCoarseGain
#define MAP_CAPT_readCoarseGain                                               \
        ROM_CAPT_readCoarseGain
#else
#define MAP_CAPT_readCoarseGain                                               \
        CAPT_readCoarseGain
#endif
#ifdef ROM_CAPT_registerCallback
#define MAP_CAPT_registerCallback                                             \
        ROM_CAPT_registerCallback
#else
#define MAP_CAPT_registerCallback                                             \
        CAPT_registerCallback
#endif
#ifdef ROM_CAPT_applyCycleComp
#define MAP_CAPT_applyCycleComp                                               \
        ROM_CAPT_applyCycleComp
#else
#define MAP_CAPT_applyCycleComp                                               \
        CAPT_applyCycleComp
#endif
#ifdef ROM_CAPT_updateSensorProxTouch
#define MAP_CAPT_updateSensorProxTouch                                        \
        ROM_CAPT_updateSensorProxTouch
#else
#define MAP_CAPT_updateSensorProxTouch                                        \
        CAPT_updateSensorProxTouch
#endif
#ifdef ROM_CAPT_clearChannelActive
#define MAP_CAPT_clearChannelActive                                           \
        ROM_CAPT_clearChannelActive
#else
#define MAP_CAPT_clearChannelActive                                           \
        CAPT_clearChannelActive
#endif
#ifdef ROM_CAPT_getSensorPacket
#define MAP_CAPT_getSensorPacket                                              \
        ROM_CAPT_getSensorPacket
#else
#define MAP_CAPT_getSensorPacket                                              \
        CAPT_getSensorPacket
#endif
#ifdef ROM_CAPT_disableISR
#define MAP_CAPT_disableISR                                                   \
        ROM_CAPT_disableISR
#else
#define MAP_CAPT_disableISR                                                   \
        CAPT_disableISR
#endif
#ifdef ROM_CAPT_isByteQueueFull
#define MAP_CAPT_isByteQueueFull                                              \
        ROM_CAPT_isByteQueueFull
#else
#define MAP_CAPT_isByteQueueFull                                              \
        CAPT_isByteQueueFull
#endif
#ifdef ROM_CAPT_forceSensorIO
#define MAP_CAPT_forceSensorIO                                                \
        ROM_CAPT_forceSensorIO
#else
#define MAP_CAPT_forceSensorIO                                                \
        CAPT_forceSensorIO
#endif
#ifdef ROM_CAPT_computeIIRFilter
#define MAP_CAPT_computeIIRFilter                                             \
        ROM_CAPT_computeIIRFilter
#else
#define MAP_CAPT_computeIIRFilter                                             \
        CAPT_computeIIRFilter
#endif

#endif // __ROM_CAPTIVATE_MAP_H__
