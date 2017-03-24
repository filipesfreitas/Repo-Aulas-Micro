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
// rom_captivate.h - Macros to facilitate calling functions in the ROM.
//
// Copyright (c) 2014 Texas Instruments Incorporated.  All rights reserved.
// TI Information - Selective Disclosure
//
//! \version 1.04.00.00
//! Released on Mon, Aug 15, 2016  5:06:13 PM
//
//*****************************************************************************
//

#ifndef __ROM_CAPTIVATE_H__
#define __ROM_CAPTIVATE_H__

#if (defined(__TI_COMPILER_VERSION__) && !defined(__LARGE_CODE_MODEL__)) || \
    (defined(__IAR_SYSTEMS_ICC__) && (__CODE_MODEL__==__CODE_MODEL_SMALL__))

//*****************************************************************************
//
// Pointers to the CAPTIVATE API tables.
//
//*****************************************************************************
#define ROM_CAPTIVATE_APITABLE  ((uint16_t *)0x4000)
#define ROM_CAPTIVATE_VERSIONL  (ROM_CAPTIVATE_APITABLE[0])
#define ROM_CAPTIVATE_VERSIONH  (ROM_CAPTIVATE_APITABLE[1])
#define ROM_CAPTIVATETABLE      ((uint16_t *)(ROM_CAPTIVATE_APITABLE[2]))

#define ROM_CAPTIVATE_getVersion    ((uint32_t)ROM_CAPTIVATE_VERSIONH<<16|ROM_CAPTIVATE_VERSIONL)

//*****************************************************************************
//
// Macros for calling CAPTIVATE ROM functions in the CAPTIVATE API.
//
//*****************************************************************************
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_selectTimerSource                                            \
        ((void (*)(uint8_t))ROM_CAPTIVATETABLE[0])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_computeArcTanApprox                                          \
        ((uint16_t (*)(int32_t i32XComp,                                      \
                       int32_t i32YComp))ROM_CAPTIVATETABLE[1])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearChannelOffState                                         \
        ((void (*)(uint8_t,                                                   \
                  uint8_t))ROM_CAPTIVATETABLE[2])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearTimer                                                   \
        ((void (*)(void))ROM_CAPTIVATETABLE[3])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_getChecksum                                                  \
        ((uint16_t (*)(const uint8_t *pBuffer,                                \
                       const uint16_t ui16Length))ROM_CAPTIVATETABLE[4])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_verifyChecksum                                               \
        ((bool (*)(const uint8_t *pBuffer,                                    \
                   const uint16_t ui16Length,                                 \
                   const uint16_t ui16Checksum))ROM_CAPTIVATETABLE[5])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_updateTouch                                                  \
        ((bool (*)(tSensor *pSensor,                                          \
                   tElement *pElement))ROM_CAPTIVATETABLE[6])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_getCyclePacket                                               \
        ((uint16_t (*)(tSensor **sensorArray,                                 \
                       uint8_t ui8SensorID,                                   \
                       uint8_t ui8Cycle,                                      \
                       uint8_t *pBuffer))ROM_CAPTIVATETABLE[7])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearCAPLPMCFG                                               \
        ((void (*)(void))ROM_CAPTIVATETABLE[8])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearChannelOnState                                          \
        ((void (*)(uint8_t,                                                   \
                  uint8_t))ROM_CAPTIVATETABLE[9])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_pollResetStatus                                              \
        ((bool (*)(void))ROM_CAPTIVATETABLE[10])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_pollCIPF                                                     \
        ((bool (*)(void))ROM_CAPTIVATETABLE[11])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_computeWheelWrap                                             \
        ((uint16_t (*)(int16_t i16Position,                                   \
                       uint16_t ui16MaxPosition))ROM_CAPTIVATETABLE[12])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_powerOn                                                      \
        ((void (*)(void))ROM_CAPTIVATETABLE[13])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_startTimer                                                   \
        ((void (*)(void))ROM_CAPTIVATETABLE[14])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_accessSensorParameter                                        \
        ((tTLParameterAccessResult (*)( tSensor **sensorArray,                \
                                       tParameterPacket *packet))ROM_CAPTIVATETABLE[16])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearCAPSTART                                                \
        ((void (*)(void))ROM_CAPTIVATETABLE[17])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_processSlider                                                \
        ((void (*)(tSensor *pSlider))ROM_CAPTIVATETABLE[18])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_stopTimer                                                    \
        ((void (*)(void))ROM_CAPTIVATETABLE[19])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_setChannelOnState                                            \
        ((void (*)(uint8_t,                                                   \
                  uint8_t))ROM_CAPTIVATETABLE[20])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_initByteQueue                                                \
        ((bool (*)(tByteQueue *pQueue,                                        \
                   uint8_t *pBufferArray,                                     \
                   uint16_t ui16BufferArraySize))ROM_CAPTIVATETABLE[21])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_reseedFilterAll                                              \
        ((void (*)(tSensor *pSensor,                                          \
                   tFilterOption whatToFilter))ROM_CAPTIVATETABLE[22])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_writeOffsetTap                                               \
        ((void (*)(uint8_t,                                                   \
                   uint16_t))ROM_CAPTIVATETABLE[23])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_setChannelOffState                                           \
        ((void (*)(uint8_t,                                                   \
                  uint8_t))ROM_CAPTIVATETABLE[24])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_readOffsetTap                                                \
        ((uint16_t (*)(uint8_t))ROM_CAPTIVATETABLE[28])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_enableISR                                                    \
        ((void (*)(uint16_t))ROM_CAPTIVATETABLE[29])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_disableSensorSyncEvent                                       \
        ((void (*)(void))ROM_CAPTIVATETABLE[30])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_readConversion                                               \
        ((uint16_t (*)(uint8_t))ROM_CAPTIVATETABLE[31])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearCCounter                                                \
        ((void (*)(void))ROM_CAPTIVATETABLE[32])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_updateProx                                                   \
        ((bool (*)(tSensor *pSensor,                                          \
                   tElement *pElement))ROM_CAPTIVATETABLE[33])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_isByteQueueEmpty                                             \
        ((bool (*)(tByteQueue *pQueue))ROM_CAPTIVATETABLE[34])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_readTimerCompRegister                                        \
        ((uint16_t (*)(void))ROM_CAPTIVATETABLE[35])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_applySensorFreq                                              \
        ((void (*)(uint8_t,                                                   \
                   tSensor *))ROM_CAPTIVATETABLE[36])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_saveCycleResults                                             \
        ((void (*)(tSensor*,                                                  \
                  tCycle*))ROM_CAPTIVATETABLE[37])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_togglePingPongBuffer                                         \
        ((bool (*)(tPingPongBuffer *buffer))ROM_CAPTIVATETABLE[38])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_powerOff                                                     \
        ((void (*)(void))ROM_CAPTIVATETABLE[39])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearChannelEnable                                           \
        ((void (*)(uint8_t,                                                   \
                  uint8_t))ROM_CAPTIVATETABLE[40])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_reset                                                        \
        ((void (*)(void))ROM_CAPTIVATETABLE[41])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_setChannelEnable                                             \
        ((void (*)(uint8_t,                                                   \
                  uint8_t))ROM_CAPTIVATETABLE[42])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_updateFilterCount                                            \
        ((void (*)(tSensor *pSensor,                                          \
                   tElement *pElement))ROM_CAPTIVATETABLE[43])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_writeCoarseGain                                              \
        ((void (*)(uint8_t,                                                   \
                   uint8_t))ROM_CAPTIVATETABLE[44])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_computeSliderVectors                                         \
        ((uint16_t (*)(tSensor *pSlider))ROM_CAPTIVATETABLE[46])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_readFineGain                                                 \
        ((uint8_t (*)(uint8_t))ROM_CAPTIVATETABLE[47])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_applySensorParams                                            \
        ((void (*)(tSensor *))ROM_CAPTIVATETABLE[48])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_stuffSyncBytes                                               \
        ((uint16_t (*)(uint8_t *pBuffer,                                      \
                       uint16_t ui16Length))ROM_CAPTIVATETABLE[49])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_engageFSM                                                    \
        ((void (*)(void))ROM_CAPTIVATETABLE[50])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_enableRefCap                                                 \
        ((void (*)(tElement* pElement,                                        \
                   uint8_t capSize))ROM_CAPTIVATETABLE[51])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_stopCCounter                                                 \
        ((void (*)(void))ROM_CAPTIVATETABLE[52])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_processReceivedData                                          \
        ((bool (*)(tByteQueue *pReceiveQueue,                                 \
                   tParameterPacket *packet,                                  \
                   tTLProtocolProcessingVariables *pVariables))ROM_CAPTIVATETABLE[53])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_enableSensorIO                                               \
        ((void (*)(tSensor *))ROM_CAPTIVATETABLE[54])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_computeIIRFilterFast                                         \
        ((IQ16_t (*)(IQ16_t *raw,                                             \
                     IQ16_t *filtered,                                        \
                     uint8_t ui8Beta))ROM_CAPTIVATETABLE[55])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearCycleIO                                                 \
        ((void (*)(tSensor *,                                                 \
                  tCycle *))ROM_CAPTIVATETABLE[56])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_disableSensorIO                                              \
        ((void (*)(tSensor *))ROM_CAPTIVATETABLE[57])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearSensorProxTouch                                         \
        ((void (*)(tSensor *pSensor))ROM_CAPTIVATETABLE[58])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_selectCCounterInterval                                       \
        ((void (*)(uint8_t))ROM_CAPTIVATETABLE[59])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_setCycleIO                                                   \
        ((void (*)(tSensor *,                                                 \
                  tCycle *))ROM_CAPTIVATETABLE[60])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_initPingPongBuffer                                           \
        ((bool (*)(tPingPongBuffer *buffer,                                   \
                   uint8_t *pBuffer1,                                         \
                   uint8_t *pBuffer2))ROM_CAPTIVATETABLE[61])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_pushOntoByteQueue                                            \
        ((int8_t (*)(tByteQueue *pQueue,                                      \
                     uint8_t ui8DataToAdd))ROM_CAPTIVATETABLE[62])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_writeTimerCompRegister                                       \
        ((void (*)(uint16_t compRegister))ROM_CAPTIVATETABLE[63])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_readTimerRegister                                            \
        ((uint16_t (*)(void))ROM_CAPTIVATETABLE[64])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_initSensorIO                                                 \
        ((void (*)(tSensor *))ROM_CAPTIVATETABLE[65])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_writeFineGain                                                \
        ((void (*)(uint8_t,                                                   \
                   uint8_t))ROM_CAPTIVATETABLE[67])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_startCCounter                                                \
        ((void (*)(void))ROM_CAPTIVATETABLE[70])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_applyCycleFSM                                                \
        ((void (*)(tCycle *))ROM_CAPTIVATETABLE[71])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_updateFilterCounts                                           \
        ((void (*)(tCycle *pCycle,                                            \
                   uint8_t ui8Beta))ROM_CAPTIVATETABLE[72])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_setCAPSTART                                                  \
        ((void (*)(void))ROM_CAPTIVATETABLE[73])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_reseedFilter                                                 \
        ((void (*)(IQ16_t *pFilter,                                           \
                   uint16_t reseedValue))ROM_CAPTIVATETABLE[74])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_saveCycleRawResults                                          \
        ((void (*)(uint8_t,                                                   \
                  tSensor*,                                                   \
                  tCycle*))ROM_CAPTIVATETABLE[75])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_updateFSMTouch                                               \
        ((void (*)(tSensor *pSensor,                                          \
                   tElement *pElement))ROM_CAPTIVATETABLE[76])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_setCAPLPMCFG                                                 \
        ((void (*)(void))ROM_CAPTIVATETABLE[77])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_getByteQueueSize                                             \
        ((uint16_t (*)(tByteQueue *pQueue))ROM_CAPTIVATETABLE[78])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_setChannelActive                                             \
        ((void (*)(uint8_t,                                                   \
                  uint8_t))ROM_CAPTIVATETABLE[79])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_pullFromByteQueue                                            \
        ((int8_t (*)(tByteQueue *pQueue,                                      \
                     uint8_t *pDestination))ROM_CAPTIVATETABLE[80])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_updateFSMProx                                                \
        ((void (*)(tSensor *pSensor,                                          \
                   tElement *pElement))ROM_CAPTIVATETABLE[81])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_disableTimerTrigMeasurement                                  \
        ((void (*)(void))ROM_CAPTIVATETABLE[83])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_selectTimerSourceDivider                                     \
        ((void (*)(uint8_t))ROM_CAPTIVATETABLE[84])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_processButtons                                               \
        ((void (*)(tSensor *))ROM_CAPTIVATETABLE[85])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_disableRefCap                                                \
        ((void (*)(void))ROM_CAPTIVATETABLE[86])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_releaseStabilization                                         \
        ((void (*)(void))ROM_CAPTIVATETABLE[87])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_enableTimerTrigMeasurement                                   \
        ((void (*)(void))ROM_CAPTIVATETABLE[88])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_enableSensorSyncEvent                                        \
        ((void (*)(void))ROM_CAPTIVATETABLE[89])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_bypassFSM                                                    \
        ((void (*)(void))ROM_CAPTIVATETABLE[90])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_updateLTA                                                    \
        ((void (*)(tSensor *pSensor,                                          \
                   tElement *pElement))ROM_CAPTIVATETABLE[91])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_readCoarseGain                                               \
        ((uint8_t (*)(uint8_t))ROM_CAPTIVATETABLE[92])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_registerCallback                                             \
        ((void (*)(tSensor *pSensor,                                          \
                   void (* user_callback)(tSensor*)))ROM_CAPTIVATETABLE[93])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_applyCycleComp                                               \
        ((void (*)(uint8_t,                                                   \
                  tCycle *))ROM_CAPTIVATETABLE[94])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_updateSensorProxTouch                                        \
        ((void (*)(tSensor *pSensor))ROM_CAPTIVATETABLE[95])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_clearChannelActive                                           \
        ((void (*)(uint8_t,                                                   \
                  uint8_t))ROM_CAPTIVATETABLE[96])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_getSensorPacket                                              \
        ((uint16_t (*)(tSensor **sensorArray,                                 \
                       uint8_t ui8SensorID,                                   \
                       uint8_t *pBuffer))ROM_CAPTIVATETABLE[97])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_disableISR                                                   \
        ((void (*)(uint16_t))ROM_CAPTIVATETABLE[98])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_isByteQueueFull                                              \
        ((bool (*)(tByteQueue *pQueue))ROM_CAPTIVATETABLE[99])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_forceSensorIO                                                \
        ((void (*)(tSenseTechnology,                                          \
                  tSensor *))ROM_CAPTIVATETABLE[100])
#endif
#if defined(TARGET_IS_MSP430FR2633)
#define ROM_CAPT_computeIIRFilter                                             \
        ((IQ16_t (*)(IQ16_t *raw,                                             \
                     IQ16_t *filtered,                                        \
                     uint8_t ui8Beta))ROM_CAPTIVATETABLE[101])
#endif

#else
#error "Large code model is not supported"
#endif

#endif // __ROM_CAPTIVATE_H__
