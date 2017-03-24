var jsonInfo = [
	{
		"MCU"    : "MSP430",
		"Device" : "MSP430G2x44",
		"Filter" : "MSP430G2\\d44"
	}
];

var jsonObjC = [
	{"SourcePreview" : "msp430g2x44_1.c",                            "Description" : "Software Toggle P1.0"},
	{"SourcePreview" : "msp430g2x44_1_vlo.c",                        "Description" : "Software Toggle P1.0, MCLK = VLO/8"},
	{"SourcePreview" : "msp430g2x44_adc10_01.c",                     "Description" : "ADC10, Sample A0, AVcc Ref, Set P1.0 if A0 > 0.5*AVcc"},
	{"SourcePreview" : "msp430g2x44_adc10_02.c",                     "Description" : "ADC10, Sample A0, 1.5V Ref, Set P1.0 if A0 > 0.2V"},
	{"SourcePreview" : "msp430g2x44_adc10_03.c",                     "Description" : "ADC10, Sample A10 Temp, Set P1.0 if Temp ++ ~2C"},
	{"SourcePreview" : "msp430g2x44_adc10_04.c",                     "Description" : "ADC10, Sample A0, Signed, Set P1.0 if A0 > 0.5*AVcc"},
	{"SourcePreview" : "msp430g2x44_adc10_05.c",                     "Description" : "ADC10, Sample A11, Lo_Batt, Set P1.0 if AVcc < 2.3V"},
	{"SourcePreview" : "msp430g2x44_adc10_06.c",                     "Description" : "ADC10, Output Internal Vref on P2.4 & ADCCLK on P1.0"},
	{"SourcePreview" : "msp430g2x44_adc10_07.c",                     "Description" : "ADC10, DTC Sample A0 64x, AVcc, Repeat Single, DCO"},
	{"SourcePreview" : "msp430g2x44_adc10_08.c",                     "Description" : "ADC10, DTC Sample A0 64x, 1.5V, Repeat Single, DCO"},
	{"SourcePreview" : "msp430g2x44_adc10_09.c",                     "Description" : "ADC10, DTC Sample A10 64x, 1.5V, Repeat Single, DCO"},
	{"SourcePreview" : "msp430g2x44_adc10_10.c",                     "Description" : "ADC10, DTC Sample A2-0, AVcc, Single Sequence, DCO"},
	{"SourcePreview" : "msp430g2x44_adc10_11.c",                     "Description" : "ADC10, Sample A0, 1.5V, TA1 Trig, Set P1.0 if > 0.5V"},
	{"SourcePreview" : "msp430g2x44_adc10_12.c",                     "Description" : "ADC10, Sample A7, 1.5V, TA1 Trig, Ultra-Low Pwr"},
	{"SourcePreview" : "msp430g2x44_adc10_13.c",                     "Description" : "ADC10, DTC Sample A1 32x, AVcc, TA0 Trig, DCO"},
	{"SourcePreview" : "msp430g2x44_adc10_14.c",                     "Description" : "ADC10, DTC Sample A1-0 32x, AVcc, Repeat Seq, DCO"},
	{"SourcePreview" : "msp430g2x44_adc10_15.c",                     "Description" : "ADC10, DTC Sample A10 32x to Flash, Int Ref, DCO"},
	{"SourcePreview" : "msp430g2x44_adc10_16.c",                     "Description" : "ADC10, DTC Sample A0 -> TA1, AVcc, DCO"},
	{"SourcePreview" : "msp430g2x44_adc10_17.c",                     "Description" : "ADC10, DTC Sample A0 -> TA1, AVcc, HF XTAL"},
	{"SourcePreview" : "msp430g2x44_adc10_18.c",                     "Description" : "ADC10, DTC Sample A1/0 -> TA1/2, 2.5V, HF XTAL"},
	{"SourcePreview" : "msp430g2x44_adc10_19.c",                     "Description" : "ADC10, DTC Sample A0 64x, AVcc, HF XTAL"},
	{"SourcePreview" : "msp430g2x44_adc10_20.c",                     "Description" : "ADC10, DTC Sample A0 2-Blk Cont. Mode, AVcc, HF XTAL"},
	{"SourcePreview" : "msp430g2x44_adc10_temp.c",                   "Description" : "ADC10, Sample A10 Temp and Convert to oC and oF"},
	{"SourcePreview" : "msp430g2x44_clks.c",                         "Description" : "Basic Clock, Output Buffered SMCLK, ACLK and MCLK/10"},
	{"SourcePreview" : "msp430g2x44_dco_flashcal.c",                 "Description" : "DCO Calibration Constants Programmer"},
	{"SourcePreview" : "msp430g2x44_flashwrite_01.c",                "Description" : "Flash In-System Programming, Copy SegC to SegD"},
	{"SourcePreview" : "msp430g2x44_flashwrite_03.c",                "Description" : "Flash In-System Programming w/ EEI, Copy SegC to SegD"},
	{"SourcePreview" : "msp430g2x44_flashwrite_04.c",                "Description" : "Flash In-System Programming w/ EEI, Copy SegD to A/B/C"},
	{"SourcePreview" : "msp430g2x44_fll_01.c",                       "Description" : "Basic Clock, Implement Auto RSEL SW FLL"},
	{"SourcePreview" : "msp430g2x44_fll_02.c",                       "Description" : "Basic Clock, Implement Cont. SW FLL with Auto RSEL"},
	{"SourcePreview" : "msp430g2x44_hfxtal.c",                       "Description" : "Basic Clock, MCLK Sourced from HF XTAL"},
	{"SourcePreview" : "msp430g2x44_hfxtal_nmi.c",                   "Description" : "Basic Clock, LFXT1/MCLK Sourced from HF XTAL, NMI"},
	{"SourcePreview" : "msp430g2x44_lpm3.c",                         "Description" : "Basic Clock, LPM3 Using WDT ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_lpm3_vlo.c",                     "Description" : "Basic Clock, LPM3 Using WDT ISR, VLO ACLK"},
	{"SourcePreview" : "msp430g2x44_nmi.c",                          "Description" : "Configure RST/NMI as NMI"},
	{"SourcePreview" : "msp430g2x44_p1_01.c",                        "Description" : "Software Poll P1.2, Set P1.0 if P1.2 = 1"},
	{"SourcePreview" : "msp430g2x44_p1_02.c",                        "Description" : "Software Port Interrupt Service on P1.2 from LPM4"},
	{"SourcePreview" : "msp430g2x44_p1_03.c",                        "Description" : "Poll P1.2 With Software with Internal Pull-up"},
	{"SourcePreview" : "msp430g2x44_p1_04.c",                        "Description" : "P1.2 Interrupt from LPM4 with Internal Pull-up"},
	{"SourcePreview" : "msp430g2x44_rosc.c",                         "Description" : "DCOCLK Biased with External Resistor Rosc"},
	{"SourcePreview" : "msp430g2x44_ta_01.c",                        "Description" : "Timer_A, Toggle P1.0, TACCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_ta_02.c",                        "Description" : "Timer_A, Toggle P1.0, TACCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_ta_03.c",                        "Description" : "Timer_A, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_ta_04.c",                        "Description" : "Timer_A, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_05.c",                        "Description" : "Timer_A, Toggle P1.0, TACCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_06.c",                        "Description" : "Timer_A, Toggle P1.0, TACCR1 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_ta_07.c",                        "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_ta_08.c",                        "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_09.c",                        "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, HF XTAL ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_10.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_ta_11.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_12.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_13.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_ta_14.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_15.c",                        "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_16.c",                        "Description" : "Timer_A, PWM TA1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_ta_17.c",                        "Description" : "Timer_A, PWM TA1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_18.c",                        "Description" : "Timer_A, PWM TA1-2, Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_19.c",                        "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_ta_20.c",                        "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_21.c",                        "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430g2x44_ta_22.c",                        "Description" : "Timer_A, Ultra-Low Pwr Pulse Accumulator"},
	{"SourcePreview" : "msp430g2x44_tb_01.c",                        "Description" : "Timer_B, Toggle P1.0, TBCCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_tb_02.c",                        "Description" : "Timer_B, Toggle P1.0, TBCCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_tb_03.c",                        "Description" : "Timer_B, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_tb_04.c",                        "Description" : "Timer_B, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_tb_05.c",                        "Description" : "Timer_B, Toggle P1.0, TBCCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_tb_06.c",                        "Description" : "Timer_B, Toggle P1.0, TBCCR1 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_tb_07.c",                        "Description" : "Timer_B, Toggle P4.0-2, Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_tb_08.c",                        "Description" : "Timer_B, Toggle P4.0-2, Cont. Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_tb_09.c",                        "Description" : "Timer_B, Toggle P4.0-2, Cont. Mode ISR, HF XTAL ACLK"},
	{"SourcePreview" : "msp430g2x44_tb_10.c",                        "Description" : "Timer_B, PWM TB1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_tb_11.c",                        "Description" : "Timer_B, PWM TB1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_tb_12.c",                        "Description" : "Timer_B, PWM TB1-2, Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430g2x44_tb_13.c",                        "Description" : "Timer_B, PWM TB1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_tb_14.c",                        "Description" : "Timer_B, PWM TB1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_tb_15.c",                        "Description" : "Timer_B, PWM TB1-2, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_irda_01.c",               "Description" : "USCI_A0 IrDA External Loopback Test, 8MHz SMCLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_irda_02.c",               "Description" : "USCI_A0 IrDA Monitor, 8MHz SMCLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_irda_03.c",               "Description" : "USCI_A0 IrDA Physical Layer Comm, 8MHz SMCLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_spi_01.c",                "Description" : "USCI_A0, SPI Interface to HC164 Shift Register"},
	{"SourcePreview" : "msp430g2x44_uscia0_spi_02.c",                "Description" : "USCI_A0, SPI Interface to HC165 Shift Register"},
	{"SourcePreview" : "msp430g2x44_uscia0_spi_03.c",                "Description" : "USCI_A0, SPI Interface to HC165/164 Shift Registers"},
	{"SourcePreview" : "msp430g2x44_uscia0_spi_09.c",                "Description" : "USCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430g2x44_uscia0_spi_10.c",                "Description" : "USCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430g2x44_uscia0_uart_01_115k.c",          "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_uart_01_115k_lpm.c",      "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK, LPM4"},
	{"SourcePreview" : "msp430g2x44_uscia0_uart_01_19200.c",         "Description" : "USCI_A0, 19200 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_uart_01_19200_2.c",       "Description" : "USCI_A0, UART 19200 Echo ISR, HF XTAL SMCLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_uart_01_9600.c",          "Description" : "USCI_A0, 9600 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_uart_05_9600.c",          "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_uart_06_9600.c",          "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 String, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_uart_07_9600.c",          "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 RX/TX, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_uscia0_uart_08_9600.c",          "Description" : "USCI_A0, UART 9600 Full-Duplex Transceiver, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_01.c",                "Description" : "USCI_B0 I2C Master to TMP100, Set P5.1 if Temp > 28C"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_02.c",                "Description" : "USCI_B0 I2C Master Interface to PCF8574, Read/Write"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_03.c",                "Description" : "USCI_B0 I2C Master Interface to DAC8571, Write"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_04.c",                "Description" : "USCI_B0 I2C Master RX single bytes from MSP430 Slave"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_05.c",                "Description" : "USCI_B0 I2C Slave TX single bytes to MSP430 Master"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_06.c",                "Description" : "USCI_B0 I2C Master TX single bytes to MSP430 Slave"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_07.c",                "Description" : "USCI_B0 I2C Slave RX single bytes from MSP430 Master"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_08.c",                "Description" : "USCI_B0 I2C Master TX multiple bytes to MSP430 Slave"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_09.c",                "Description" : "USCI_B0 I2C Slave RX multiple bytes from MSP430 Master"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_10.c",                "Description" : "USCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "msp430g2x44_uscib0_i2c_11.c",                "Description" : "USCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "msp430g2x44_uscib0_spi_01.c",                "Description" : "USCI_B0, SPI Interface to TLC549 8-Bit ADC"},
	{"SourcePreview" : "msp430g2x44_uscib0_spi_02.c",                "Description" : "USCI_B0, SPI Interface to TLV1549 10-Bit ADC"},
	{"SourcePreview" : "msp430g2x44_wdt_01.c",                       "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_wdt_02.c",                       "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430g2x44_wdt_04.c",                       "Description" : "WDT+ Failsafe Clock, DCO SMCLK"},
	{"SourcePreview" : "msp430g2x44_wdt_05.c",                       "Description" : "Reset on Invalid Address fetch, Toggle P1.0"},
	{"SourcePreview" : "msp430g2x44_wdt_06.c",                       "Description" : "WDT+ Failsafe Clock, 32kHz ACLK"}
];

