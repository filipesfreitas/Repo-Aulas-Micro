var jsonInfo = [
	{
		"MCU"    : "MSP430",
		"Device" : "MSP430F565x",
		"Filter" : "MSP430F565\\d"
	}
];

var jsonObjC = [
	{"SourcePreview" : "msp430f665x_1.c",                   "Description" : "Software Toggle P1.0"},
	{"SourcePreview" : "msp430f665x_adc_01.c",              "Description" : "ADC12, Sample A0, Set P1.0 if A0 > 0.5*AVcc"},
	{"SourcePreview" : "msp430f665x_adc_02.c",              "Description" : "ADC12, Using the Internal Reference"},
	{"SourcePreview" : "msp430f665x_adc_05.c",              "Description" : "ADC12, Using an External Reference"},
	{"SourcePreview" : "msp430f665x_adc_06.c",              "Description" : "ADC12, Repeated Sequence of Conversions"},
	{"SourcePreview" : "msp430f665x_adc_07.c",              "Description" : "ADC12, Repeated Single Channel Conversions"},
	{"SourcePreview" : "msp430f665x_adc_08.c",              "Description" : "ADC12, Using A8 and A9 Ext Channels for Conversion"},
	{"SourcePreview" : "msp430f665x_adc_09.c",              "Description" : "ADC12, Sequence of Conversions (non-repeated)"},
	{"SourcePreview" : "msp430f665x_adc_10.c",              "Description" : "ADC12, Sample A10 Temp and Convert to oC and oF"},
	{"SourcePreview" : "msp430f665x_compB_01.c",            "Description" : "COMPB output Toggle in LPM4; Vcompare is compared against the internal 2.0V reference"},
	{"SourcePreview" : "msp430f665x_compB_02.c",            "Description" : "COMPB Toggle from LPM4; input channel CB1; Vcompare is compared against the internal reference 2.0V"},
	{"SourcePreview" : "msp430f665x_compB_03.c",            "Description" : "COMPB interrupt capability; Vcompare is compared against internal 1.5V reference"},
	{"SourcePreview" : "msp430f665x_compB_04.c",            "Description" : "COMPB Toggle from LPM4; CompB in ultra low power mode Vcompare is compared against the Vcc*1/2"},
	{"SourcePreview" : "msp430f665x_compB_05.c",            "Description" : "COMPB Hysteresis, CBOUT Toggle in LPM4; High speed mode"},
	{"SourcePreview" : "msp430f665x_crc16_01.c",            "Description" : "CRC16, Compare CRC output with software-based algorithm"},
	{"SourcePreview" : "msp430f665x_crc16_02.c",            "Description" : "CRC16, fed by DMA, compare w/ software algorithm"},
	{"SourcePreview" : "msp430f665x_dac12_1.c",             "Description" : "DAC12_0, Output 1.5V on DAC0"},
	{"SourcePreview" : "msp430f665x_dac12_2.c",             "Description" : "DAC12_1, Output 0.75V on DAC1"},
	{"SourcePreview" : "msp430f665x_dac12_3.c",             "Description" : "DAC12_0, Output Voltage Ramp on DAC0"},
	{"SourcePreview" : "msp430f665x_dma_01.c",              "Description" : "DMA0, Repeated Block to-from RAM, Software Trigger"},
	{"SourcePreview" : "msp430f665x_dma_02.c",              "Description" : "DMA0, Repeated Block UCA1UART 9600, TACCR2, ACLK"},
	{"SourcePreview" : "msp430f665x_flashwrite_01.c",       "Description" : "Single-Byte Flash In-System Programming, Copy SegC to SegD"},
	{"SourcePreview" : "msp430f665x_flashwrite_02.c",       "Description" : "Flash In-System Programming w/ Long-Word write at 0x1800"},
	{"SourcePreview" : "msp430f665x_lpm0_01.c",             "Description" : "Enters LPM0 with ACLK = LFXT1, REF0 disabled, VUSB LDO and SLDO disabled, SVS disabled"},
	{"SourcePreview" : "msp430f665x_LPM35_RTC.c",           "Description" : "RTC_B, LPM3.5, & alarm"},
	{"SourcePreview" : "msp430f665x_lpm3_01.c",             "Description" : "Enters LPM3 with ACLK = LFXT1, REF0 disabled, VUSB LDO and SLDO disabled, SVS disabled"},
	{"SourcePreview" : "msp430f665x_lpm3_02.c",             "Description" : "Enters LPM3 with ACLK =REFO; LFXT1 disabled, VUSB LDO and SLDO disabled"},
	{"SourcePreview" : "msp430f665x_lpm3_03.c",             "Description" : "Enters LPM3 with ACLK =VLO; REFO, LFXT1 disabled, VUSB LDO and SLDO disabled"},
	{"SourcePreview" : "msp430f665x_lpm4.c",                "Description" : "Enters LPM4"},
	{"SourcePreview" : "msp430f665x_LPM45_BAKMEM.c",        "Description" : "Enters LPM4.5, tests backup memory"},
	{"SourcePreview" : "msp430f665x_mid_01.c",              "Description" : "Enabling MID protection for the entire main memory "},
	{"SourcePreview" : "msp430f665x_mid_02.c",              "Description" : "Enabling MID protection for one MID block"},
	{"SourcePreview" : "msp430f665x_mid_03.c",              "Description" : "Error injection when MID protection is enabled"},
	{"SourcePreview" : "msp430f665x_PortMap_01.c",          "Description" : "Port Mapping Port2; Single runtime configuration"},
	{"SourcePreview" : "msp430f665x_PortMap_02.c",          "Description" : "Port Mapping single function to multiple pins; Single runtime configuration."},
	{"SourcePreview" : "msp430f665x_PortMap_03.c",          "Description" : "Port Map single function to multiple pins; Multiple runtime configurations"},
	{"SourcePreview" : "msp430f665x_RTC_01.c",              "Description" : "RTC_B in real time clock mode"},
	{"SourcePreview" : "msp430f665x_ta0_02.c",              "Description" : "Timer0_A5, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta0_04.c",              "Description" : "Timer0_A5, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta0_16.c",              "Description" : "Timer0_A5, PWM TA1.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta0_17.c",              "Description" : "Timer0_A5, PWM TA1.1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta1_01.c",              "Description" : "Timer1_A3, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta1_02.c",              "Description" : "Timer1_A3, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta1_03.c",              "Description" : "Timer1_A3, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta1_04.c",              "Description" : "Timer1_A3, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta1_05.c",              "Description" : "Timer1_A3, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta1_11.c",              "Description" : "Timer1_A3, Toggle P3.1/TA1.0, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta1_13.c",              "Description" : "Timer1_A3, Toggle P1.7/TA1.0, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta1_14.c",              "Description" : "Timer1_A3, Toggle P3.1/TA1.0, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta1_16.c",              "Description" : "Timer1_A3, PWM TA1.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta1_17.c",              "Description" : "Timer1_A3, PWM TA1.1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta1_19.c",              "Description" : "Timer1_A3, PWM TA1.1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta1_20.c",              "Description" : "Timer1_A3, PWM TA1.1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta2_01.c",              "Description" : "Timer2_A3, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta2_03.c",              "Description" : "Timer2_A3, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ta2_08.c",              "Description" : "Timer2_A3, Toggle P1.0;P2.3-5, Cont. Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta2_14.c",              "Description" : "Timer2_A3, Toggle P3.5/TA2.0, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_ta2_19.c",              "Description" : "Timer2_A3, PWM TA2.1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_tb_01.c",               "Description" : "Timer_B, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_tb_02.c",               "Description" : "Timer_B, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_tb_03.c",               "Description" : "Timer_B, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_tb_04.c",               "Description" : "Timer_B, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_tb_05.c",               "Description" : "Timer_B, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_tb_10.c",               "Description" : "Timer_B, PWM TB1-6, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_ucs_03.c",              "Description" : "Software Toggle P1.1 with 12MHz DCO"},
	{"SourcePreview" : "msp430f665x_ucs_04.c",              "Description" : "FLL+, Runs Internal DCO at 2.45MHz"},
	{"SourcePreview" : "msp430f665x_ucs_05.c",              "Description" : "VLO sources ACLK"},
	{"SourcePreview" : "msp430f665x_ucs_06.c",              "Description" : "XT1 sources ACLK"},
	{"SourcePreview" : "msp430f665x_ucs_07.c",              "Description" : "FLL+, Output 32kHz Xtal + HF Xtal + Internal DCO"},
	{"SourcePreview" : "msp430f665x_ucs_08.c",              "Description" : "XT2 sources SMCLK"},
	{"SourcePreview" : "msp430f665x_uscia0_spi_09.c",       "Description" : "eUSCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430f665x_uscia0_spi_10.c",       "Description" : "eUSCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430f665x_uscia0_uart_03.c",      "Description" : "eUSCI_A0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_uscia0_uart_04.c",      "Description" : "eUSCI_A0, 9600 UART, SMCLK, LPM0, Echo with over-sampling"},
	{"SourcePreview" : "msp430f665x_uscib0_i2c_06.c",       "Description" : "eUSCI_B0 I2C Slave RX single bytes from MSP430 Master"},
	{"SourcePreview" : "msp430f665x_uscib0_i2c_07.c",       "Description" : "eUSCI_B0 I2C Master TX single bytes to MSP430 Slave"},
	{"SourcePreview" : "msp430f665x_uscib0_i2c_08.c",       "Description" : "eUSCI_B0 I2C Master TX multiple bytes to MSP430 Slave"},
	{"SourcePreview" : "msp430f665x_uscib0_i2c_09.c",       "Description" : "eUSCI_B0 I2C Slave RX multiple bytes from MSP430 Master"},
	{"SourcePreview" : "msp430f665x_uscib0_i2c_10.c",       "Description" : "eUSCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "msp430f665x_uscib0_i2c_11.c",       "Description" : "eUSCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "msp430f665x_wdt_01.c",              "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_wdt_02.c",              "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430f665x_wdt_04.c",              "Description" : "WDT+ Failsafe Clock, WDT mode, DCO SMCLK"},
	{"SourcePreview" : "msp430f665x_wdt_05.c",              "Description" : "Reset on Invalid Address fetch, Toggle P1.0"},
	{"SourcePreview" : "msp430f665x_wdt_06.c",              "Description" : "WDT+ Failsafe Clock, 32kHz ACLK"}
];

