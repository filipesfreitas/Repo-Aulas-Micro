var jsonInfo = [
	{
		"MCU"    : "MSP430",
		"Device" : "MSP430FR572x",
		"Filter" : "MSP430FR572\\d"
	}
];

var jsonObjC = [
	{"SourcePreview" : "MSP430FR57xx_01.c",                                "Description" : "LED Toggle code example"},
	{"SourcePreview" : "MSP430FR57xx_active_02.c",                         "Description" : "Stay in active mode with MCLK = 8MHz (uses while loop)"},
	{"SourcePreview" : "MSP430FR57xx_adc10_01.c",                          "Description" : "ADC10, Sample A1, AVcc Ref, Set P1.0 if A1 > 0.5*AVcc"},
	{"SourcePreview" : "MSP430FR57xx_adc10_02.c",                          "Description" : "ADC10, Sample A1, 1.5V Shared Ref, Set P1.0 if A1 > 0.5V"},
	{"SourcePreview" : "MSP430FR57xx_adc10_05.c",                          "Description" : "ADC10, Sample A11, Lo_Batt, Clear P1.0 if AVcc < 2.3V"},
	{"SourcePreview" : "MSP430FR57xx_adc10_06.c",                          "Description" : "ADC10, Internal Reference toggle"},
	{"SourcePreview" : "MSP430FR57xx_adc10_07.c",                          "Description" : "ADC10, DMA Sample A1 64x, AVcc, Repeat Single, DCO"},
	{"SourcePreview" : "MSP430FR57xx_adc10_10.c",                          "Description" : "ADC10, DMA Sample A2-0, 8-bit Res, Single Sequence, DCO"},
	{"SourcePreview" : "MSP430FR57xx_adc10_11.c",                          "Description" : "ADC10, Sample A1, 1.5V Ref, TA0.1 Trig, Set P1.0 if A1>0.5V"},
	{"SourcePreview" : "MSP430FR57xx_adc10_15.c",                          "Description" : "ADC10, DMA Sample A11 32x to FRAM, Int Ref, DCO"},
	{"SourcePreview" : "MSP430FR57xx_adc10_16.c",                          "Description" : "ADC10, Sample A10 Temp and Convert to oC and oF"},
	{"SourcePreview" : "MSP430FR57xx_adc10_21.c",                          "Description" : "ADC10, Window Comparator, 2.5V ref, Timer trigger, DCO"},
	{"SourcePreview" : "MSP430FR57xx_compD_01.c",                          "Description" : "COMPD output Toggle in LPM4; Vcompare is compared against the internal 2.0V reference"},
	{"SourcePreview" : "MSP430FR57xx_compD_02.c",                          "Description" : "COMPD output toggle in LPM4; Vcompare is compared against the internal reference 2.5V"},
	{"SourcePreview" : "MSP430FR57xx_compD_03.c",                          "Description" : "COMPD interrupt capability; "},
	{"SourcePreview" : "MSP430FR57xx_compD_04.c",                          "Description" : "COMPD Toggle from LPM4; Ultra low power mode; "},
	{"SourcePreview" : "MSP430FR57xx_compD_05.c",                          "Description" : "COMPD Hysteresis, CBOUT Toggle in LPM4; High speed mode"},
	{"SourcePreview" : "MSP430FR57xx_CS_01.c",                             "Description" : "Configure MCLK for 8MHz operation"},
	{"SourcePreview" : "MSP430FR57xx_CS_02.c",                             "Description" : "Configure MCLK for 24MHz operation"},
	{"SourcePreview" : "MSP430FR57xx_CS_03.c",                             "Description" : "Output 32768Hz crystal on XT1 and observe failsafe "},
	{"SourcePreview" : "MSP430FR57xx_dma_01.c",                            "Description" : "DMA0, Repeated Block to-from RAM, Software Trigger"},
	{"SourcePreview" : "MSP430FR57xx_FRAMWrite.c",                         "Description" : "FRAM In-System Programming w/ Long-Word write "},
	{"SourcePreview" : "MSP430FR57xx_JTAG_01.c",                           "Description" : "Secure device using a JTAG password"},
	{"SourcePreview" : "MSP430FR57xx_LPM3_01.c",                           "Description" : "Enters LPM3 with ACLK = LFXT1"},
	{"SourcePreview" : "MSP430FR57xx_LPM3_02.c",                           "Description" : "Enters LPM3 with ACLK = VLO "},
	{"SourcePreview" : "MSP430FR57xx_LPM4.c",                              "Description" : "Enters LPM4"},
	{"SourcePreview" : "MSP430FR57xx_MPU_02.c",                            "Description" : "MPU write protection violation - PUC"},
	{"SourcePreview" : "MSP430FR57xx_P1_01.c",                             "Description" : "Software Poll P1.4, Set P1.0 if P1.4 = 1"},
	{"SourcePreview" : "MSP430FR57xx_P1_03.c",                             "Description" : "Software Port Interrupt Service on P1.4 from LPM4"},
	{"SourcePreview" : "MSP430FR57xx_ta0_01.c",                            "Description" : "Timer0_A3, Toggle P1.0, CCR0 Cont Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430FR57xx_ta0_02.c",                            "Description" : "Timer0_A3, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430FR57xx_ta0_04.c",                            "Description" : "Timer0_A3, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430FR57xx_ta0_16.c",                            "Description" : "Timer0_A3, PWM TA0.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "MSP430FR57xx_ta0_17.c",                            "Description" : "Timer0_A3, PWM TA0.1-2, Up Mode, 32KHz ACLK"},
	{"SourcePreview" : "MSP430FR57xx_ta1_05.c",                            "Description" : "Timer1_A3, Toggle P1.0, CCR0 Cont Mode ISR, 32KHz ACLK "},
	{"SourcePreview" : "MSP430FR57xx_ta1_06.c",                            "Description" : "Timer1_A3, Toggle P1.0, CCR0 UP Mode ISR, 32KHz ACLK "},
	{"SourcePreview" : "MSP430FR57xx_ta1_16.c",                            "Description" : "Timer1_A3, PWM TA1.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "MSP430FR57xx_ta1_17.c",                            "Description" : "Timer1_A3, PWM TA1.1-2, Up Mode, 32KHz ACLK"},
	{"SourcePreview" : "MSP430FR57xx_tb0_01.c",                            "Description" : "TimerB, Toggle P1.0, CCR0 Cont Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430FR57xx_tb0_02.c",                            "Description" : "TimerB, Toggle P1.0, CCR0 UP Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430FR57xx_tb0_03.c",                            "Description" : "TimerB, Toggle P1.0, Overflow ISR, DCO SMCLK "},
	{"SourcePreview" : "MSP430FR57xx_tb0_04.c",                            "Description" : "TimerB, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430FR57xx_tb0_06.c",                            "Description" : "TimerB, Toggle P1.0, CCR0 UP Mode ISR, 32KHz ACLK "},
	{"SourcePreview" : "MSP430FR57xx_tb0_16.c",                            "Description" : "TimerB, PWM TB0.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "MSP430FR57xx_tb0_17.c",                            "Description" : "TimerB, PWM TB0.1-2, Up Mode, 32KHz ACLK"},
	{"SourcePreview" : "MSP430FR57xx_uscia0_spi_09.c",                     "Description" : "USCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "MSP430FR57xx_uscia0_spi_10.c",                     "Description" : "USCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "MSP430FR57xx_uscia0_uart_03.c",                    "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430FR57xx_uscia0_uart_04.c",                    "Description" : "USCI_A0, 9600 UART external loopback"},
	{"SourcePreview" : "MSP430FR57xx_uscib0_i2c_04.c",                     "Description" : "USCI_B0 I2C Master RX single bytes to MSP430 Slave"},
	{"SourcePreview" : "MSP430FR57xx_uscib0_i2c_05.c",                     "Description" : "USCI_B0 I2C Slave TX single bytes from MSP430 Master"},
	{"SourcePreview" : "MSP430FR57xx_uscib0_i2c_06.c",                     "Description" : "USCI_B0 I2C Master TX single bytes to MSP430 Slave"},
	{"SourcePreview" : "MSP430FR57xx_uscib0_i2c_07.c",                     "Description" : "USCI_B0 I2C Slave RX single bytes from MSP430 Master"},
	{"SourcePreview" : "MSP430FR57xx_uscib0_i2c_10.c",                     "Description" : "USCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "MSP430FR57xx_uscib0_i2c_11.c",                     "Description" : "USCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "MSP430FR57xx_uscib0_i2c_12.c",                     "Description" : "USCI_B0 I2C Slave TX multiple bytes to MSP430 Master using Early Transmit (preload feature)"},
	{"SourcePreview" : "MSP430FR57xx_uscib0_i2c_Master_MultiSlave.c",      "Description" : "USCI_B0 Master TX to 4 unique slave addresses"},
	{"SourcePreview" : "MSP430FR57xx_uscib0_i2c_MultiSlave.c",             "Description" : "USCI_B0 configured as 4 unique slave receviers."},
	{"SourcePreview" : "MSP430FR57xx_WDT_01.c",                            "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430FR57xx_WDT_02.c",                            "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430FR57xx_WDT_04.c",                            "Description" : "WDT+ Failsafe Clock, WDT mode, DCO SMCLK"},
	{"SourcePreview" : "MSP430FR57xx_WDT_05.c",                            "Description" : "Reset on Invalid Address fetch, Toggle P1.0"}
];
