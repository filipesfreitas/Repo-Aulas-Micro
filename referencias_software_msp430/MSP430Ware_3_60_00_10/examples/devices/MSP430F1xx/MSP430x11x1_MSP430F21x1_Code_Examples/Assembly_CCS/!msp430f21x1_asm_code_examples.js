var jsonObjASM = [
	{"SourcePreview" : "msp430x11x1_1.asm",                      "Description" : "Software Toggle P1.0"},
	{"SourcePreview" : "msp430x11x1_164.asm",                    "Description" : "Software SPI Interface to HC164 Shift Register"},
	{"SourcePreview" : "msp430x11x1_165.asm",                    "Description" : "Software Interface to HC165 Shift Register"},
	{"SourcePreview" : "msp430x11x1_1820.asm",                   "Description" : "Software 1-Wire Interface DS1820, Set P1.0 if > 30C"},
	{"SourcePreview" : "msp430x11x1_549.asm",                    "Description" : "Software SPI Interface TLC549, Set P1.0 if > 0.5*Vcc"},
	{"SourcePreview" : "msp430x11x1_5616.asm",                   "Description" : "Software SPI Interface to TLV5616 12-Bit DAC"},
	{"SourcePreview" : "msp430x11x1_5timers.asm",                "Description" : "5 Interrupt Timers & 2 Clock Outputs, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_7822.asm",                   "Description" : "Software Interface to Read ADS7822"},
	{"SourcePreview" : "msp430x11x1_831.asm",                    "Description" : "Software SPI Interface to TLV0831"},
	{"SourcePreview" : "msp430x11x1_8574.asm",                   "Description" : "Software I2C Master Interface to PCF8574, Read/Write"},
	{"SourcePreview" : "msp430x11x1_ca_01.asm",                  "Description" : "Comp_A, Output Reference Voltages on P2.3"},
	{"SourcePreview" : "msp430x11x1_ca_02.asm",                  "Description" : "Comp_A, Detect Threshold, Set P1.0 if P2.3 > 0.25*Vcc"},
	{"SourcePreview" : "msp430x11x1_ca_03.asm",                  "Description" : "Comp_A, Simple 2.2V Low Battery Detect"},
	{"SourcePreview" : "msp430x11x1_ca_04.asm",                  "Description" : "Comp_A, Slope ADC to Detect Temp Lvl, Set P1.0 > 25C"},
	{"SourcePreview" : "msp430x11x1_ca_05.asm",                  "Description" : "Comp_A, Thermometer 59-99 F"},
	{"SourcePreview" : "msp430x11x1_ca_06.asm",                  "Description" : "Comp_A, Thermometer 0-50 C"},
	{"SourcePreview" : "msp430x11x1_ca_07.asm",                  "Description" : "Comp_A, Resistance Meter"},
	{"SourcePreview" : "msp430x11x1_clks.asm",                   "Description" : "Basic Clock, Output Buffered SMCLK, ACLK and MCLK/10"},
	{"SourcePreview" : "msp430x11x1_flashwrite_01.asm",          "Description" : "Flash In-System Programming, Copy SegA to SegB"},
	{"SourcePreview" : "msp430x11x1_fll_01.asm",                 "Description" : "Basic Clock, Implement Auto RSEL SW FLL"},
	{"SourcePreview" : "msp430x11x1_fll_02.asm",                 "Description" : "Basic Clock, Implement Cont. SW FLL with Auto RSEL"},
	{"SourcePreview" : "msp430x11x1_hfxtal.asm",                 "Description" : "Basic Clock, MCLK Sourced from HF XTAL"},
	{"SourcePreview" : "msp430x11x1_hfxtal_nmi.asm",             "Description" : "Basic Clock, MCLK Configured with HF XTAL & Osc Fault"},
	{"SourcePreview" : "msp430x11x1_lpm3.asm",                   "Description" : "Basic Clock, LPM3 Using WDT ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_nmi.asm",                    "Description" : "Basic Clock, Configure RST/NMI as NMI"},
	{"SourcePreview" : "msp430x11x1_P2_int.asm",                 "Description" : "Software Port Interrupt on P2.0 from LPM4"},
	{"SourcePreview" : "msp430x11x1_P2_poll.asm",                "Description" : "Software Poll P2.0, Set P1.0 if P2.0 = 1"},
	{"SourcePreview" : "msp430x11x1_r2r.asm",                    "Description" : "Software Output 6-Bit R2R DAC"},
	{"SourcePreview" : "msp430x11x1_selftest.asm",               "Description" : "Use JTAG for Downloadable Test Code"},
	{"SourcePreview" : "msp430x11x1_ta_01.asm",                  "Description" : "Timer_A, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_02.asm",                  "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_03.asm",                  "Description" : "Timer_A, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_04.asm",                  "Description" : "Timer_A, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_05.asm",                  "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_06.asm",                  "Description" : "Timer_A, Toggle P1.0, CCR1 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_07.asm",                  "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_08.asm",                  "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_09.asm",                  "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, HF XTAL ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_10.asm",                  "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_11.asm",                  "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_12.asm",                  "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_13.asm",                  "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_14.asm",                  "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_15.asm",                  "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_16.asm",                  "Description" : "Timer_A, PWM TA1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_17.asm",                  "Description" : "Timer_A, PWM TA1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_18.asm",                  "Description" : "Timer_A, PWM TA1-2 Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_19.asm",                  "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_20.asm",                  "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_21.asm",                  "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_22.asm",                  "Description" : "Timer_A, Output 40kHz Square Wave, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_ta_23.asm",                  "Description" : "Timer_A, Ultra-Low Pwr 1200Hz Detect, ACLK +/- 5%"},
	{"SourcePreview" : "msp430x11x1_ta_24.asm",                  "Description" : "Timer_A, Ultra-Low Pwr 1800Hz Detect, SMCLK +/- 1%"},
	{"SourcePreview" : "msp430x11x1_ta_uart115k.asm",            "Description" : "Timer_A, UART 115200 Echo, HF XTAL ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_uart19200_01.asm",        "Description" : "Timer_A, UART 19200 Echo, HF XTAL ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_uart19200_02.asm",        "Description" : "Timer_A, Ultra-Low Pwr UART 19200 Echo, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_uart19200_03.asm",        "Description" : "Timer_A, UART 19200 Echo, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_uart2400.asm",            "Description" : "Timer_A, Ultra-Low Pwr UART 2400 Echo, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_uart9600_01.asm",         "Description" : "Timer_A, UART 9600 Echo, HF XTAL ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_uart9600_02.asm",         "Description" : "Timer_A, Ultra-Low Pwr UART 9600 Echo, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_uart9600_03.asm",         "Description" : "Timer_A, UART 9600 Echo, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_uart9600_05.asm",         "Description" : "Timer_A, Ultra-Low Pwr UART 9600 String, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_ta_uart9600_06.asm",         "Description" : "Timer_A, Ultra-Low Pwr UART 9600 Echo, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_tmp100.asm",                 "Description" : "Software I2C Master Interface to TMP100"},
	{"SourcePreview" : "msp430x11x1_tvrc5_tx.asm",               "Description" : "Encode RC5 IR Remote Control, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_wdt_01.asm",                 "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x11x1_wdt_02.asm",                 "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x11x1_wdt_03.asm",                 "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, HF XTAL ACLK"},
	{"SourcePreview" : "msp430x21x1_2.asm",                      "Description" : "Reset on Invalid Address fetch, Toggle P1.0"},
	{"SourcePreview" : "msp430x21x1_ca_08.asm",                  "Description" : "Comp_A, Millivolt Meter"},
	{"SourcePreview" : "msp430x21x1_ca_CASHORT.asm",             "Description" : "Comp_A, Simple 2.2V Low Battery Detect using CASHORT"},
	{"SourcePreview" : "msp430x21x1_flashwrite_03.asm",          "Description" : "Flash In-System Programming, Copy SegC to SegD"},
	{"SourcePreview" : "msp430x21x1_fll_03.asm",                 "Description" : "Basic Clock, Implement Auto RSEL SW FLL"},
	{"SourcePreview" : "msp430x21x1_hfxtal.asm",                 "Description" : "Basic Clock, MCLK Sourced from HF XTAL"},
	{"SourcePreview" : "msp430x21x1_HF_ExtACLK.asm",             "Description" : "Basic Clock, MCLK Sourced from HF Digital source"},
	{"SourcePreview" : "msp430x21x1_LF_OFIFG_extclk.asm",        "Description" : "OFIFG ISR for LF Failsafe Operation on Ext Clk"},
	{"SourcePreview" : "msp430x21x1_LF_OFIFG_XTAL.asm",          "Description" : "OFIFG ISR for LF Failsafe Operation"},
	{"SourcePreview" : "msp430x21x1_Pull-up.asm",                "Description" : "21x1 Pull-up resistors demo"},
	{"SourcePreview" : "msp430x21x1_ta_uart115k_12MHz.asm",      "Description" : "Timer_A, UART 115200 Echo, 12MHz DCO SMCLK"},
	{"SourcePreview" : "msp430x21x1_ta_uart115k_16MHz.asm",      "Description" : "Timer_A, UART 115200 Echo, 16MHz DCO SMCLK"},
	{"SourcePreview" : "msp430x21x1_ta_uart115k_8MHz.asm",       "Description" : "Timer_A, UART 115200 Echo, 8MHz DCO SMCLK"},
	{"SourcePreview" : "msp430x21x1_ta_uart9600_1MHz.asm",       "Description" : "Timer_A, Ultra-Low Pwr UART 9600 Echo,1MHz DCO SMCLK"},
	{"SourcePreview" : "msp430x21x1_wdt_04.asm",                 "Description" : "WDT+ Failsafe Clock, DCO SMCLK"}
];

