var jsonInfo = [
	{
		"MCU"    : "MSP430",
		"Device" : "MSP430FG47x",
		"Filter" : "MSP430FG47\\d"
	}
];

var jsonObjC = [
	{"SourcePreview" : "msp430F(G)47x_1.c",                         "Description" : "Toggle P4.6 in software"},
	{"SourcePreview" : "msp430F(G)47x_bt_01.c",                     "Description" : "Basic Timer, Toggle P4.6 Inside ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_bt_02.c",                     "Description" : "Basic Timer, Toggle P4.6 Inside ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430F(G)47x_clks_03.c",                   "Description" : "FLL+, Output 32kHz XTAL + HF XTAL + Internal DCO"},
	{"SourcePreview" : "msp430F(G)47x_compA_01.c",                  "Description" : "Comparator_A, Poll input CA0, result in P4.6"},
	{"SourcePreview" : "msp430F(G)47x_compA_02.c",                  "Description" : "Comparator_A, Poll input CA0, CA exchange, result in P4.6"},
	{"SourcePreview" : "msp430F(G)47x_compA_04.c",                  "Description" : "Comparator_A, Poll input CA0, result in P4.6"},
	{"SourcePreview" : "msp430F(G)47x_compA_05.c",                  "Description" : "Comparator_A, Poll input CA0, interrupt triggered"},
	{"SourcePreview" : "msp430F(G)47x_dac0_1.c",                    "Description" : "DAC12_0, Output 1V on DAC0"},
	{"SourcePreview" : "msp430F(G)47x_dac0_2.c",                    "Description" : "DAC12_0, Output 2V on DAC1"},
	{"SourcePreview" : "msp430F(G)47x_dac0_3.c",                    "Description" : "DAC12_0, Output Voltage Ramp on DAC0"},
	{"SourcePreview" : "msp430F(G)47x_dac0_5.c",                    "Description" : "DAC12_0, Output Voltage Ramp on DAC0"},
	{"SourcePreview" : "msp430F(G)47x_flashwrite_01.c",             "Description" : "Flash In-System Programming, Copy SegC to SegD"},
	{"SourcePreview" : "msp430F(G)47x_flashwrite_03.c",             "Description" : "Flash In-System Programming w/ EEI, Copy SegC to SegD"},
	{"SourcePreview" : "msp430F(G)47x_flashwrite_04.c",             "Description" : "Flash In-System Programming w/ EEI, Copy SegD to A/B/C"},
	{"SourcePreview" : "msp430F(G)47x_fll_01.c",                    "Description" : "FLL+, Runs Internal DCO at 2.5MHz"},
	{"SourcePreview" : "msp430F(G)47x_fll_02.c",                    "Description" : "FLL+, Runs Internal DCO at 8MHz"},
	{"SourcePreview" : "msp430F(G)47x_LFxtal_nmi.c",                "Description" : "LFXT1 Oscillator Fault Detection"},
	{"SourcePreview" : "msp430F(G)47x_lpm3.c",                      "Description" : "FLL+, LPM3 Using Basic Timer ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430F(G)47x_oa_02.c",                     "Description" : "OA0,Comparator in General-Purpose Mode"},
	{"SourcePreview" : "msp430F(G)47x_oa_03.c",                     "Description" : "OA0,General-Purpose Mode"},
	{"SourcePreview" : "msp430F(G)47x_oa_06.c",                     "Description" : "OA0,Unity-Gain Buffer Mode"},
	{"SourcePreview" : "msp430F(G)47x_oa_11.c",                     "Description" : "OA1,Unity-Gain Buffer Mode"},
	{"SourcePreview" : "msp430F(G)47x_sd16a_03.c",                  "Description" : "SD16_A, Continuous Conversion on a Single Channel"},
	{"SourcePreview" : "msp430F(G)47x_sd16a_04.c",                  "Description" : "SD16_A, Single Conversion on Single Channel Polling IFG"},
	{"SourcePreview" : "msp430F(G)47x_sd16a_05.c",                  "Description" : "SD16_A, Single Conversion on a Single Channel Using ISR"},
	{"SourcePreview" : "msp430F(G)47x_sd16a_07.c",                  "Description" : "SD16, Single Conversion on a Single Channel Using ISR"},
	{"SourcePreview" : "msp430F(G)47x_sd16a_08.c",                  "Description" : "SD16_A, Single Conversion on a Channel using buffered input"},
	{"SourcePreview" : "msp430F(G)47x_sd16a_09.c",                  "Description" : "SD16_A, Single Conversion on a Single Channel Using ISR"},
	{"SourcePreview" : "msp430F(G)47x_sd16a_10.c",                  "Description" : "SD16_A, Single Conversion on a Single Channel Using ISR 1024 Extended Oversampling Rate"},
	{"SourcePreview" : "msp430F(G)47x_sd16a_11.c",                  "Description" : "SD16_A, Single Conversion on a Single Channel Using ISR ACLK input to SD16_A"},
	{"SourcePreview" : "msp430F(G)47x_sd16a_12.c",                  "Description" : "SD16_A, Single Conversion on a Single Channel Using ISR SMCLK input is divided by 32"},
	{"SourcePreview" : "msp430F(G)47x_svs_01.c",                    "Description" : "SVS, POR @ 2.5V Vcc"},
	{"SourcePreview" : "msp430F(G)47x_svs_03.c",                    "Description" : "SVM, Toggle port 4.6 on Vcc < 2.8V"},
	{"SourcePreview" : "msp430F(G)47x_ta_01.c",                     "Description" : "Timer_A, Toggle P4.6, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_ta_02.c",                     "Description" : "Timer_A, Toggle P4.6, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_ta_03.c",                     "Description" : "Timer_A, Toggle P4.6, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_ta_04.c",                     "Description" : "Timer_A, Toggle P4.6, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430F(G)47x_ta_05.c",                     "Description" : "Timer_A, Toggle P4.6, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430F(G)47x_ta_16.c",                     "Description" : "Timer_A, Timer_A, PWM TA1-2 Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_ta_17.c",                     "Description" : "Timer_A, PWM TA1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430F(G)47x_tb_01.c",                     "Description" : "Timer_B, Toggle P4.6, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_tb_02.c",                     "Description" : "Timer_B, Toggle P4.6, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_tb_03.c",                     "Description" : "Timer_B, Toggle P4.6, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_tb_04.c",                     "Description" : "Timer_B, Toggle P4.6, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430F(G)47x_tb_05.c",                     "Description" : "Timer_B, Toggle P4.6, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430F(G)47x_tb_10.c",                     "Description" : "Timer_B, PWM TB1 -2 Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_tb_11.c",                     "Description" : "Timer_B, PWM TB1-2 Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430F(G)47x_uscia0_duplex_9600.c",        "Description" : "USCI_A0, UART 9600 Full-Duplex Transceiver, 32K ACLK"},
	{"SourcePreview" : "msp430F(G)47x_uscia0_irda_01.c",            "Description" : "USCI_A0 IrDA External Loopback Test, 4MHz SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_uscia0_spi_09.c",             "Description" : "USCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430F(G)47x_uscia0_spi_10.c",             "Description" : "USCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430F(G)47x_uscia0_uart_115k.c",          "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_uscia0_uart_115k_lpm.c",      "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK, LPM3"},
	{"SourcePreview" : "msp430F(G)47x_uscia0_uart_9600.c",          "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430F(G)47x_uscib0_i2c_02.c",             "Description" : "USCI_B0 I2C Master Interface to PCF8574, Read/Write"},
	{"SourcePreview" : "msp430F(G)47x_uscib0_i2c_08.c",             "Description" : "USCI_B0 I2C Master TX multiple bytes to MSP430 Slave"},
	{"SourcePreview" : "msp430F(G)47x_uscib0_i2c_09.c",             "Description" : "USCI_B0 I2C Slave RX multiple bytes from MSP430 Master"},
	{"SourcePreview" : "msp430F(G)47x_uscib0_i2c_10.c",             "Description" : "USCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "msp430F(G)47x_uscib0_i2c_11.c",             "Description" : "USCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "msp430F(G)47x_wdt_01.c",                    "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430F(G)47x_wdt_02.c",                    "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"}
];

