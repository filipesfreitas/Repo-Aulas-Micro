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
//******************************************************************************
// IIR filter using a cascaded DF2 biquad.
//
//! \example filter_ex5_biquad_cascade_df2_ext_q15.c
//! This example demonstrates how to use the msp_biquad_df2_ext_q15 API to 
//! filter 16-bit input data using the extended Direct Form II (df2) biquad 
//! function that includes DC bias and min/max states and a cascade of filter 
//! stages.
//!
// Brent Peterson, Jeremy Friesenhahn
// Texas Instruments Inc.
// April 2016
//******************************************************************************
#include "msp430.h"

#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#include "DSPLib.h"

/* Include header generated from DSPLib GUI here (optional). */
//#include "myCoeffs_ex5.h"

/* Input signal parameters */
#define FS                  8192
#define SIGNAL_LENGTH       256
#define SIGNAL_FREQUENCY1   200
#define SIGNAL_AMPLITUDE1   0.6
#define SIGNAL_FREQUENCY2   2100
#define SIGNAL_AMPLITUDE2   0.15

/* Constants */
#define PI                  3.1415926536

/* Define example coefficients if no DSPLib GUI header is provided. */
#ifndef FILTER_COEFFS_EX5
/* Second-order sections for 16th order low pass filter (Fs=8192, Fc=1800) */
DSPLIB_DATA(FILTER_COEFFS_EX5,4)
msp_biquad_df2_ext_q15_coeffs FILTER_COEFFS_EX5[8] = {
    {
        .b0     = _Q15(+0.299438),
        .b1By2  = _Q15(+0.582237/2),
        .b2     = _Q15(+0.299438),
        .a0     = _Q15(+1.000000),
        .a1By2  = _Q15(-0.215187/2),
        .a2     = _Q15(-0.019276),
        .bias   = _Q15(+0.000000)
    },
    {
        .b0     = _Q15(+0.331762),
        .b1By2  = _Q15(+0.517588/2),
        .b2     = _Q15(+0.331762),
        .a0     = _Q15(+1.000000),
        .a1By2  = _Q15(-0.145445/2),
        .a2     = _Q15(-0.070846),
        .bias   = _Q15(+0.000000)
    },
    {
        .b0     = _Q15(+0.391490),
        .b1By2  = _Q15(+0.398133/2),
        .b2     = _Q15(+0.391490),
        .a0     = _Q15(+1.000000),
        .a1By2  = _Q15(-0.021883/2),
        .a2     = _Q15(-0.164643),
        .bias   = _Q15(+0.000000)
    },
    {
        .b0     = _Q15(+0.469527),
        .b1By2  = _Q15(+0.242057/2),
        .b2     = _Q15(+0.469527),
        .a0     = _Q15(+1.000000),
        .a1By2  = _Q15(+0.131385/2),
        .a2     = _Q15(-0.286925),
        .bias   = _Q15(+0.000000)
    },
    {
        .b0     = _Q15(+0.553995),
        .b1By2  = _Q15(+0.073122/2),
        .b2     = _Q15(+0.553995),
        .a0     = _Q15(+1.000000),
        .a1By2  = _Q15(+0.291215/2),
        .a2     = _Q15(-0.425539),
        .bias   = _Q15(+0.000000)
    },
    {
        .b0     = _Q15(+0.632033),
        .b1By2  = _Q15(-0.082953/2),
        .b2     = _Q15(+0.632033),
        .a0     = _Q15(+1.000000),
        .a1By2  = _Q15(+0.440602/2),
        .a2     = _Q15(-0.573626),
        .bias   = _Q15(+0.000000)
    },
    {
        .b0     = _Q15(+0.691760),
        .b1By2  = _Q15(-0.202408/2),
        .b2     = _Q15(+0.691760),
        .a0     = _Q15(+1.000000),
        .a1By2  = _Q15(+0.569203/2),
        .a2     = _Q15(-0.730815),
        .bias   = _Q15(+0.000000)
    },
    {
        .b0     = _Q15(+0.724084),
        .b1By2  = _Q15(-0.267057/2),
        .b2     = _Q15(+0.724084),
        .a0     = _Q15(+1.000000),
        .a1By2  = _Q15(+0.671286/2),
        .a2     = _Q15(-0.903577),
        .bias   = _Q15(+0.000000)
    }
};
#endif

/* Filter parameters */
#define FILTER_LENGTH   (SIGNAL_LENGTH)
#define FILTER_STAGES   (sizeof(FILTER_COEFFS_EX5)/sizeof(msp_biquad_df2_ext_q15_coeffs))

/* Filter input signal */
DSPLIB_DATA(input,4)
_q15 input[SIGNAL_LENGTH];

/* Temporary data array for processing */
DSPLIB_DATA(temp,4)
_q15 temp[SIGNAL_LENGTH];

/* Filter result */
DSPLIB_DATA(result,4)
_q15 result[SIGNAL_LENGTH];

/* State buffer */
DSPLIB_DATA(states,4)
msp_biquad_df2_ext_q15_states states[FILTER_STAGES] = {0};

/* Benchmark cycle counts */
volatile uint32_t cycleCount = 0;

/* Function prototypes */
extern void initSignal(void);

void main(void)
{
    msp_status status;
    msp_biquad_cascade_df2_ext_q15_params df2Params;
    
    /* Disable WDT. */
    WDTCTL = WDTPW + WDTHOLD;

    /* Initialize input signal */
    initSignal();
    
    /* Initialize the parameter structure. */
    df2Params.length = FILTER_LENGTH;
    df2Params.stages = FILTER_STAGES;
    df2Params.coeffs = FILTER_COEFFS_EX5;
    df2Params.states = states;
    
    /* Invoke the msp_biquad_cascade_df2_ext_q15 function. */
    msp_benchmarkStart(MSP_BENCHMARK_BASE, 8);
    status = msp_biquad_cascade_df2_ext_q15(&df2Params, input, result);
    cycleCount = msp_benchmarkStop(MSP_BENCHMARK_BASE);
    msp_checkStatus(status);
    
    /* End of program. */
    __no_operation();
}

void initSignal(void)
{
    msp_status status;
    msp_add_q15_params addParams;
    msp_sinusoid_q15_params sinParams;

    /* Generate Q15 input signal 1 */
    sinParams.length = SIGNAL_LENGTH;
    sinParams.amplitude = _Q15(SIGNAL_AMPLITUDE1);
    sinParams.cosOmega = _Q15(cosf(2*PI*SIGNAL_FREQUENCY1/FS));
    sinParams.sinOmega = _Q15(sinf(2*PI*SIGNAL_FREQUENCY1/FS));
    status = msp_sinusoid_q15(&sinParams, input);
    msp_checkStatus(status);

    /* Generate Q15 input signal 2 to temporary array */
    sinParams.length = SIGNAL_LENGTH;
    sinParams.amplitude = _Q15(SIGNAL_AMPLITUDE2);
    sinParams.cosOmega = _Q15(cosf(2*PI*SIGNAL_FREQUENCY2/FS));
    sinParams.sinOmega = _Q15(sinf(2*PI*SIGNAL_FREQUENCY2/FS));
    status = msp_sinusoid_q15(&sinParams, temp);
    msp_checkStatus(status);

    /* Add input signals */
    addParams.length = SIGNAL_LENGTH;
    status = msp_add_q15(&addParams, input, temp, input);
    msp_checkStatus(status);
}
