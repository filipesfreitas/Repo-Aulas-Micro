/*******************************************************************************
 *
 *  UserExperience.c - Main Application
 *
 *  Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

#include <stdint.h>
#include "msp430.h"
#include "HAL_PMM.h"
#include "HAL_UCS.h"
#include "HAL_Board.h"
#include "HAL_Buttons.h"
#include "HAL_LIS3DH.h"
#include "HAL_Dogs102x6.h"
#include "HAL_Menu.h"
#include "HAL_Wheel.h"
#include "LaunchpadDef.h"
#include "Clock.h"
#include "LPM.h"
#include "MassStorage.h"
#include "Mouse.h"
#include "PMM.h"
#include "Settings.h"
#include "PowerTest.h"
#include "DemoApps.h"
#include "SdCard.h"
#include "ff.h"
#include "MenuGames.h"

uint16_t timeoutCounter;

// This image has been created by ImageDog using 'ti_bug.jpg'
static const uint8_t tiBug[] =
{
    0x42,    // Image width in pixels
    0x08,    // Image height in rows (1 row = 8 pixels)
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x08, 0x00, 0x00, 0x0f, 0xcf, 0xcf, 0xcf, 0xcf,
    0xcf, 0xc8, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xc0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0xc0, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x70, 0x7c, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x01, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x00, 0x01, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0,
    0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x80, 0x00, 0x0e, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfc, 0x80, 0x00, 0x0e, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0, 0xc0, 0x80,
    0x80, 0x80, 0xc0, 0xc0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0f, 0xff, 0xff, 0xff, 0xfe, 0xfe,
    0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfe, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0xf0, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char *const mainMenu[] = {
    "=MSP-EXP430F5529=",
    "1. Clock ",
    "2. Games ",
    "3. Power Tests ",
    "4. Demo Apps ",
    "5. SD Card Access",
    "6. Settings "
};

void main(void)
{
    uint8_t contrast = *((unsigned char *)contrastSetpointAddress);
    uint8_t brightness = *((unsigned char *)brightnessSetpointAddress);

    // Initialize accelerometer offset from flash
    LIS3DH_setAccel_offset(*((unsigned char *)accelXcalibrationAddress),
                            *((unsigned char *)accelYcalibrationAddress),
                            *((unsigned char *)accelZcalibrationAddress));

    // Stop WDT
    WDTCTL = WDTPW + WDTHOLD;

    // Basic GPIO initialization
    Board_init();

    // Set Vcore to accomodate for max. allowed system speed
    SetVCore(3);

    // Use 32.768kHz XTAL as reference
    LFXT_Start(XT1DRIVE_0);

    // Set system clock to max (25MHz)
    Init_FLL_Settle(25000, 762);

    SFRIFG1 = 0;
    SFRIE1 |= OFIE;

    // Globally enable interrupts
    __enable_interrupt();

    // Setup SD Card
    // MSUpdate
    FRESULT rc;
    rc = GetDirectory("");

    // Setup real time clock
    SetupRTC();

    // Set up LCD
    Dogs102x6_init();
    Dogs102x6_backlightInit();

    // Contrast not programed in Flash Yet
    if (contrast == 0xFF)
        // Set Default Contrast
        contrast = 11;

    // Brightness not programed in Flash Yet
    if (brightness == 0xFF)
        // Set Default Brightness
        brightness = 11;

    Dogs102x6_setBacklight(brightness);
    Dogs102x6_setContrast(contrast);
    Dogs102x6_clearScreen();

    // Set up wheel
    Wheel_init();
    Buttons_init(BUTTON_ALL);
    Buttons_interruptEnable(BUTTON_ALL);
    buttonsPressed = 0;

    // Display TI logo
    Dogs102x6_imageDraw(tiBug, 0, 16);

    // Wait for button press
    while (!buttonsPressed)
    {
        for (timeoutCounter = 0; timeoutCounter < 0xFFFF; timeoutCounter++)
        {
            if (buttonsPressed)
                break;
            __delay_cycles(1000);
        }

        //Timeout break
        break;
    }
    buttonsPressed = 0;
    Dogs102x6_clearScreen();

    // Main loop
    while (1)
    {
        Dogs102x6_stringDraw(7, 0, "*S1=Enter S2=Esc*", DOGS102x6_DRAW_NORMAL);
        switch (Menu_active((char **)mainMenu, 6))
        {
            case 1: ClockMenu(); break;
            case 2: MenuGames(); break;
            case 3: PowerMenu(); break;
            case 4: DemoApp();   break;
            case 5: SDCard();    break;
            case 6: Settings();  break;
            default: break;
        }
    }
}
