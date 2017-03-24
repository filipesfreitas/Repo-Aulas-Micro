var jsonInfo = [
	{
		"MCU"    : "MSP430",
		"Device" : "MSP430F51x2",
		"Filter" : "MSP430F51\\d2"
	}
];

var jsonObjC = [
	{"SourcePreview" : "MSP430F51x2.c",                     "Description" : "Toggle P1.0, default DCO"},
	{"SourcePreview" : "MSP430F51x2_adc10_01.c",            "Description" : "ADC10, Sample A1, AVcc Ref, Set P1.0 if A1 > 0.5*AVcc "},
	{"SourcePreview" : "MSP430F51x2_adc10_02.c",            "Description" : "ADC10, Sample A1, 1.5V Shared Ref, Set P1.0 if A1 > 0.2V "},
	{"SourcePreview" : "MSP430F51x2_adc10_03.c",            "Description" : "ADC10, Sample A10 Temp, TA0 trigger, Set P1.0 if Temp ++ ~2C "},
	{"SourcePreview" : "MSP430F51x2_adc10_04.c",            "Description" : "ADC10, Sample A1, Signed, Set P1.0 if A1 > 0.5*AVcc"},
	{"SourcePreview" : "MSP430F51x2_adc10_05.c",            "Description" : "ADC10, Sample A11, Lo_Batt, Clear P1.0 if AVcc < 2.3V"},
	{"SourcePreview" : "MSP430F51x2_adc10_06.c",            "Description" : "ADC10, Internal Reference toggle "},
	{"SourcePreview" : "MSP430F51x2_adc10_07.c",            "Description" : "ADC10, DMA Sample A0 64x, AVcc, Repeat Single, DCO "},
	{"SourcePreview" : "MSP430F51x2_adc10_10.c",            "Description" : "ADC10, DMA Sample A2-0, 8-bit Res, Single Sequence, DCO "},
	{"SourcePreview" : "MSP430F51x2_adc10_11.c",            "Description" : "ADC10, Sample A0, 1.5V Shared Ref, ta0 Trig, Set P1.0 if > 0.5V "},
	{"SourcePreview" : "MSP430F51x2_adc10_12.c",            "Description" : "ADC10, Sample A7, 1.5V Shared Ref, ta0 Trig, Ultra-Low Pwr "},
	{"SourcePreview" : "MSP430F51x2_adc10_13.c",            "Description" : "ADC10, DMA Sample A1 32x, AVcc, TA0 Trig, DCO "},
	{"SourcePreview" : "MSP430F51x2_adc10_14.c",            "Description" : "ADC10, DMA Sample A1-0 32x, AVcc, Repeat Seq, DCO "},
	{"SourcePreview" : "MSP430F51x2_adc10_15.c",            "Description" : "ADC10, DMA Sample A10 32x to Flash, Int Ref, DCO "},
	{"SourcePreview" : "MSP430F51x2_adc10_21.c",            "Description" : "ADC10, Window Comparator, 2.5V Timer trigger, DCO"},
	{"SourcePreview" : "MSP430F51x2_compB_01.c",            "Description" : "COMPB output Toggle in LPM4; "},
	{"SourcePreview" : "MSP430F51x2_compB_02.c",            "Description" : "COMPB output Toggle from LPM4; input channel CB1; "},
	{"SourcePreview" : "MSP430F51x2_compB_03.c",            "Description" : "COMPB interrupt capability; "},
	{"SourcePreview" : "MSP430F51x2_compB_04.c",            "Description" : "COMPB Toggle from LPM4; Ultra low power mode; "},
	{"SourcePreview" : "MSP430F51x2_dma_01.c",              "Description" : "DMA0, Repeated Block to-from RAM, Software Trigger"},
	{"SourcePreview" : "MSP430F51x2_dma_02.c",              "Description" : "DMA0, Repeated Block UCA0UART 9600, TACCR2, ACLK"},
	{"SourcePreview" : "MSP430F51x2_flashwrite_01.c",       "Description" : "Single-Byte Flash In-System Programming, Copy SegC to SegD"},
	{"SourcePreview" : "MSP430F51x2_flashwrite_02.c",       "Description" : "Flash In-System Programming w/ Long-Word write at 0x1800"},
	{"SourcePreview" : "MSP430F51x2_flashwrite_03.c",       "Description" : "Bank Erase from a Block while Executing Code from Another Block"},
	{"SourcePreview" : "MSP430F51x2_LPM3_01.c",             "Description" : "Enters LPM3 with ACLK = LFXT1, REF0 disabled, VUSB LDO and SLDO disabled, SVS disabled"},
	{"SourcePreview" : "MSP430F51x2_LPM3_02.c",             "Description" : "Enters LPM3 (ACLK = VLO)"},
	{"SourcePreview" : "MSP430F51x2_LPM4.c",                "Description" : "Enters LPM4"},
	{"SourcePreview" : "MSP430F51x2_P1_01.c",               "Description" : "Software Poll P1.4, Set P1.0 if P1.4 = 1"},
	{"SourcePreview" : "MSP430F51x2_PA_05.c",               "Description" : "Write a Word to Port A (Port1+Port2)"},
	{"SourcePreview" : "MSP430F51x2_PortMap_01.c",          "Description" : "Port Mapping Port4; Single runtime configuration"},
	{"SourcePreview" : "MSP430F51x2_PortMap_02.c",          "Description" : "Port Mapping single function to multiple pins; Single runtime configuration."},
	{"SourcePreview" : "MSP430F51x2_PortMap_03.c",          "Description" : "Port Map single function to multiple pins; Multiple runtime configurations"},
	{"SourcePreview" : "MSP430F51x2_ta0_02.c",              "Description" : "Timer0_A3, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430F51x2_ta0_04.c",              "Description" : "Timer0_A3, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430F51x2_ta0_16.c",              "Description" : "Timer0_A3, PWM TA0.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "MSP430F51x2_ta0_17.c",              "Description" : "Timer0_A3, PWM TA0.1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "MSP430F51x2_td0_01.c",              "Description" : "Timer0_D3, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430F51x2_td0_03.c",              "Description" : "Timer0_D3, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430F51x2_td0_08.c",              "Description" : "Timer0_D3, Toggle P1.0;P2.3-5, Cont. Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430F51x2_td0_14.c",              "Description" : "Timer0_D3, Toggle TD0.0, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "MSP430F51x2_td0_19.c",              "Description" : "Timer0_D3, PWM TD0.0-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "MSP430F51x2_td0_20a.c",             "Description" : "Timer0_D3, Hi-Res Calibrated mode, PWM TD0.0-2, DCO SMCLK"},
	{"SourcePreview" : "MSP430F51x2_td0_20b.c",             "Description" : "Timer0_D3, Hi-Res Free Running mode, PWM TD0.0-2, TDCLK = 64Mhz"},
	{"SourcePreview" : "MSP430F51x2_td0_20c.c",             "Description" : "Timer0_D3, Hi-Res Free Running mode, PWM TD0.0-2, TDCLK = 128Mhz"},
	{"SourcePreview" : "MSP430F51x2_td0_20d.c",             "Description" : "Timer0_D3, Hi-Res Free Running mode, PWM TD0.0-2, TDCLK = 200Mhz"},
	{"SourcePreview" : "MSP430F51x2_td0_21.c",              "Description" : "Timer0_D3, Hi-Res Free Running mode, PWM TD0.0-2, TDCLK = 256Mhz"},
	{"SourcePreview" : "MSP430F51x2_td0_22.c",              "Description" : "Timer0_D3, Hi-Res Calibrated mode, max TimerD clock "},
	{"SourcePreview" : "MSP430F51x2_td0_23.c",              "Description" : "Timer0_D3, Combining two CCRx register to control one PWM channel"},
	{"SourcePreview" : "MSP430F51x2_td0_24.c",              "Description" : "Timer0_D3, Single Input Capture mode, Normal Timer Mode"},
	{"SourcePreview" : "MSP430F51x2_td0_25.c",              "Description" : "Timer0_D3, Dual Input Capture mode, Normal timer mode, Period Measurement"},
	{"SourcePreview" : "MSP430F51x2_td0_26.c",              "Description" : "Timer0_D3, Dual Input Capture mode, Normal timer mode, DutyCycle Measurement"},
	{"SourcePreview" : "MSP430F51x2_tec_01.c",              "Description" : "TimerD0/1-TEC, External Clear, Rising edge trigger"},
	{"SourcePreview" : "MSP430F51x2_tec_02.c",              "Description" : "TimerD0/1-TEC, External Clear, Level trigger"},
	{"SourcePreview" : "MSP430F51x2_tec_03.c",              "Description" : "TimerD0/1-TEC, External Fault, Rising edge and Level trigger "},
	{"SourcePreview" : "MSP430F51x2_tec_04.c",              "Description" : "TimerD0/1-TEC, External Fault, TECIV"},
	{"SourcePreview" : "MSP430F51x2_tec_05.c",              "Description" : "TimerD0/1-TEC, Synchronizing timers, Normal timer mode"},
	{"SourcePreview" : "MSP430F51x2_tec_06.c",              "Description" : "TimerD0/1-TEC, Synchronizing timers, Hi-res timer mode "},
	{"SourcePreview" : "MSP430F51x2_tec_07.c",              "Description" : "TimerD0/1-TEC, Synchronizing timers, Master Capture/Slave Compare"},
	{"SourcePreview" : "MSP430F51x2_UCS_01.c",              "Description" : "Software Toggle P1.0 at Default DCO "},
	{"SourcePreview" : "MSP430F51x2_UCS_02.c",              "Description" : "Software Toggle P1.0 with 8MHz DCO"},
	{"SourcePreview" : "MSP430F51x2_UCS_03.c",              "Description" : "Software Toggle P1.0 with 12MHz DCO"},
	{"SourcePreview" : "MSP430F51x2_UCS_04.c",              "Description" : "FLL+, Runs Internal DCO at 2.45MHz, 32kHz XT1"},
	{"SourcePreview" : "MSP430F51x2_UCS_05.c",              "Description" : "VLO sources ACLK"},
	{"SourcePreview" : "MSP430F51x2_UCS_06.c",              "Description" : "XT1 sources ACLK"},
	{"SourcePreview" : "MSP430F51x2_UCS_10.c",              "Description" : "Software Toggle P1.1 with 25MHz DCO"},
	{"SourcePreview" : "MSP430F51x2_uscia0_spi_09.c",       "Description" : "USCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "MSP430F51x2_uscia0_spi_10.c",       "Description" : "USCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "MSP430F51x2_uscia0_uart_01.c",      "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430F51x2_uscia0_uart_03.c",      "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430F51x2_uscib0_i2c_04.c",       "Description" : "USCI_B0 I2C Master RX single bytes from MSP430 Master"},
	{"SourcePreview" : "MSP430F51x2_uscib0_i2c_05.c",       "Description" : "USCI_B0 I2C Slave TX single bytes to MSP430 Slave"},
	{"SourcePreview" : "MSP430F51x2_uscib0_i2c_06.c",       "Description" : "USCI_B0 I2C Master TX single bytes to MSP430 Slave"},
	{"SourcePreview" : "MSP430F51x2_uscib0_i2c_07.c",       "Description" : "USCI_B0 I2C Slave RX single bytes from MSP430 Master"},
	{"SourcePreview" : "MSP430F51x2_uscib0_i2c_08.c",       "Description" : "USCI_B0 I2C Master TX multiple bytes to MSP430 Slave"},
	{"SourcePreview" : "MSP430F51x2_uscib0_i2c_09.c",       "Description" : "USCI_B0 I2C Slave RX multiple bytes from MSP430 Master"},
	{"SourcePreview" : "MSP430F51x2_uscib0_i2c_10.c",       "Description" : "USCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "MSP430F51x2_uscib0_i2c_11.c",       "Description" : "USCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "MSP430F51x2_WDT_01.c",              "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430F51x2_WDT_02.c",              "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430F51x2_WDT_04.c",              "Description" : "WDT+ Failsafe Clock, WDT mode, DCO SMCLK"},
	{"SourcePreview" : "MSP430F51x2_WDT_05.c",              "Description" : "Reset on Invalid Address fetch, Toggle P1.0"},
	{"SourcePreview" : "MSP430F51x2_WDT_06.c",              "Description" : "WDT+ Failsafe Clock, 32kHz ACLK"}
];

