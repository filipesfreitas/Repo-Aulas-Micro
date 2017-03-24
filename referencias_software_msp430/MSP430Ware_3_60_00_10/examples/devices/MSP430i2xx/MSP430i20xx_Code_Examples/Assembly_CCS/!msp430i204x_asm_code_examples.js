var jsonObjASM = [
	{"SourcePreview" : "msp430i20xx_01",                   "Description" : "Blink an LED"},
	{"SourcePreview" : "msp430i20xx_cs_01",                "Description" : "Basic Clock, Output Buffered SMCLK and MCLK/10"},
	{"SourcePreview" : "msp430i20xx_cs_02",                "Description" : "Basic Clock, MCLK = DCO/2, SMCLK = DCO/4, Internal Resistor"},
	{"SourcePreview" : "msp430i20xx_cs_03",                "Description" : "Basic Clock, MCLK = DCO/2, SMCLK = DCO/4, External Resistor"},
	{"SourcePreview" : "msp430i20xx_euscia0_spi_09",       "Description" : "eUSCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430i20xx_euscia0_spi_10",       "Description" : "eUSCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430i20xx_euscia0_spi_11",       "Description" : "eUSCI_A0, SPI 4-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430i20xx_euscia0_spi_12",       "Description" : "eUSCI_A0, SPI 4-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430i20xx_euscia0_uart_01",      "Description" : "eUSCI, 9600 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430i20xx_euscia0_uart_03",      "Description" : "eUSCI, 115200 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430i20xx_euscib0_i2c_10",       "Description" : "eUSCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "msp430i20xx_euscib0_i2c_11",       "Description" : "eUSCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "msp430i20xx_euscib0_i2c_12",       "Description" : "eUSCI_B0 I2C Master TX bytes to Multiple Slaves"},
	{"SourcePreview" : "msp430i20xx_euscib0_i2c_13",       "Description" : "eUSCI_B0 I2C 4 Hardware I2C slaves"},
	{"SourcePreview" : "msp430i20xx_euscib0_spi_09",       "Description" : "eUSCI_B0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430i20xx_euscib0_spi_10",       "Description" : "eUSCI_B0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430i20xx_euscib0_spi_11",       "Description" : "eUSCI_B0, SPI 4-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430i20xx_euscib0_spi_12",       "Description" : "eUSCI_B0, SPI 4-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430i20xx_flashwrite_01",        "Description" : "Flash In-System Programming, Information Segment"},
	{"SourcePreview" : "msp430i20xx_lpm0",                 "Description" : "Enters LPM0 with ACLK = 32kHz, MCLK = 1MHz"},
	{"SourcePreview" : "msp430i20xx_lpm3",                 "Description" : "Enters LPM3 with ACLK = 32kHz, MCLK = 1MHz"},
	{"SourcePreview" : "msp430i20xx_lpm4",                 "Description" : "Enters LPM4"},
	{"SourcePreview" : "msp430i20xx_lpm4-5",               "Description" : "Entering and waking up from LPM4.5 via P2.1 interrupt"},
	{"SourcePreview" : "msp430i20xx_P1_01",                "Description" : "Software Poll P1.0, Set P1.4 if P1.0 = 1"},
	{"SourcePreview" : "msp430i20xx_P1_02",                "Description" : "Port Interrupt Service on P1.0 from LPM4"},
	{"SourcePreview" : "msp430i20xx_pmm_01",               "Description" : "PMM Module, Compare VMONIN to Internal 1.16V, Poll IFG"},
	{"SourcePreview" : "msp430i20xx_pmm_02",               "Description" : "PMM Module, Compare VMONIN to Internal 1.16V, VMON ISR"},
	{"SourcePreview" : "msp430i20xx_pmm_03",               "Description" : "PMM Module, Compare DVCC to 2.85V, VMON ISR"},
	{"SourcePreview" : "msp430i20xx_sd24_01",              "Description" : "SD24, Continuous Conversion on a Group of 3 Channels"},
	{"SourcePreview" : "msp430i20xx_sd24_02",              "Description" : "SD24, Single Conversion on a Group of 3 Channels"},
	{"SourcePreview" : "msp430i20xx_sd24_03",              "Description" : "SD24, Continuous Conversion on a Single Channel"},
	{"SourcePreview" : "msp430i20xx_sd24_04",              "Description" : "SD24, Single Conversion on Single Channel Polling IFG"},
	{"SourcePreview" : "msp430i20xx_sd24_05",              "Description" : "SD24, Single Conversion on a Single Channel Using ISR"},
	{"SourcePreview" : "msp430i20xx_ta0_01",               "Description" : "Timer_A0, Toggle P1.4, CCR0 Cont. Mode ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta0_02",               "Description" : "Timer_A0, Toggle P1.4, CCR0 Up Mode ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta0_03",               "Description" : "Timer_A0, Toggle P1.4, Overflow ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta0_04",               "Description" : "Timer_A0, Toggle P1.4, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430i20xx_ta0_06",               "Description" : "Timer_A0, Toggle P1.4, CCR1 Cont. Mode ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta0_07",               "Description" : "Timer_A0, Toggle P1.4-6, Cont. Mode ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta0_13",               "Description" : "Timer_A0, Toggle P1.4/TA0, Up/Down Mode, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta0_19",               "Description" : "Timer_A0, PWM, Up/Down Mode, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta1_01",               "Description" : "Timer_A1, Toggle P1.4, CCR0 Cont. Mode ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta1_02",               "Description" : "Timer_A1, Toggle P1.4, CCR0 Up Mode ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta1_03",               "Description" : "Timer_A1, Toggle P1.4, Overflow ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta1_04",               "Description" : "Timer_A1, Toggle P1.4, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430i20xx_ta1_06",               "Description" : "Timer_A1, Toggle P1.4, CCR1 Cont. Mode ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta1_07",               "Description" : "Timer_A1, Toggle P1.4-6, Cont. Mode ISR, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta1_13",               "Description" : "Timer_A1, Toggle P1.4/TA0, Up/Down Mode, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_ta1_19",               "Description" : "Timer_A1, PWM, Up/Down Mode, DCO SMCLK/8"},
	{"SourcePreview" : "msp430i20xx_wdt_01",               "Description" : "WDT, Toggle P1.4, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430i20xx_wdt_04",               "Description" : "WDT Failsafe Clock, DCO SMCLK"},
	{"SourcePreview" : "msp430i20xx_wdt_05",               "Description" : "Reset on Invalid Address fetch, Toggle P1.4"}
];

