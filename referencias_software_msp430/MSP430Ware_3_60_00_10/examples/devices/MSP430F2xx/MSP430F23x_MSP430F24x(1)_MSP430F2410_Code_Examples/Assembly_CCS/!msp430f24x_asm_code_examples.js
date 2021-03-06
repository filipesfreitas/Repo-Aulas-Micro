var jsonObjASM = [
	{"SourcePreview" : "msp430x24x_1.asm",                             "Description" : "Software Toggle P1.0"},
	{"SourcePreview" : "msp430x24x_1_vlo.asm",                         "Description" : "Software Toggle P1.0, MCLK = VLO/8"},
	{"SourcePreview" : "msp430x24x_adc12_01.asm",                      "Description" : "ADC12, Sample A0, Set P1.0 if A0 > 0.5*AVcc"},
	{"SourcePreview" : "msp430x24x_adc12_02.asm",                      "Description" : "ADC12, Using the Internal Reference"},
	{"SourcePreview" : "msp430x24x_adc12_03.asm",                      "Description" : "ADC12, Sample A10 Temp, Set P1.0 if Temp ++ ~2C"},
	{"SourcePreview" : "msp430x24x_adc12_04.asm",                      "Description" : "ADC12, Extend Sampling Period with SHT Bits"},
	{"SourcePreview" : "msp430x24x_adc12_05.asm",                      "Description" : "ADC12, Using an External Reference"},
	{"SourcePreview" : "msp430x24x_adc12_06.asm",                      "Description" : "ADC12, Repeated Sequence of Conversions"},
	{"SourcePreview" : "msp430x24x_adc12_07.asm",                      "Description" : "ADC12, Repeated Single Channel Conversions"},
	{"SourcePreview" : "msp430x24x_adc12_08.asm",                      "Description" : "ADC12, Using 10 External Channels for Conversion"},
	{"SourcePreview" : "msp430x24x_adc12_09.asm",                      "Description" : "ADC12, Sequence of Conversions (non-repeated)"},
	{"SourcePreview" : "msp430x24x_adc12_10.asm",                      "Description" : "ADC12, Sample A10 Temp and Convert to oC and oF"},
	{"SourcePreview" : "msp430x24x_clks.asm",                          "Description" : "Basic Clock, Output Buffered SMCLK, ACLK, and MCLK"},
	{"SourcePreview" : "msp430x24x_compA_01.asm",                      "Description" : "Comparator A, Poll input CA0, result in P1.0"},
	{"SourcePreview" : "msp430x24x_compA_02.asm",                      "Description" : "Comparator A, Poll input CA0, CA exchange, result in P1.0"},
	{"SourcePreview" : "msp430x24x_compA_04.asm",                      "Description" : "Comparator A, Poll input CA0, result in P1.0"},
	{"SourcePreview" : "msp430x24x_compA_05.asm",                      "Description" : "Comparator A, Poll input CA0, interrupt triggered"},
	{"SourcePreview" : "msp430x24x_dco_flashcal.asm",                  "Description" : "DCO Calibration Constants Programmer"},
	{"SourcePreview" : "msp430x24x_flashwrite_01.asm",                 "Description" : "Flash In-System Programming, Copy SegC to SegD"},
	{"SourcePreview" : "msp430x24x_flashwrite_02.asm",                 "Description" : "Flash In-System Programming w/ EEI, Copy SegC to SegD"},
	{"SourcePreview" : "msp430x24x_flashwrite_03.asm",                 "Description" : "Flash In-System Programming w/ EEI, Copy SegD to B&C"},
	{"SourcePreview" : "msp430x24x_fll_01.asm",                        "Description" : "Basic Clock, Implement Auto RSEL SW FLL"},
	{"SourcePreview" : "msp430x24x_fll_02.asm",                        "Description" : "Basic Clock, Implement Cont. SW FLL with Auto RSEL"},
	{"SourcePreview" : "msp430x24x_hfxt2.asm",                         "Description" : "Basic Clock, MCLK Configured to Operate from XT2 HF XTAL"},
	{"SourcePreview" : "msp430x24x_hfxt2_nmi.asm",                     "Description" : "Basic Clock, MCLK Sourced from HF XTAL XT2, NMI"},
	{"SourcePreview" : "msp430x24x_lpm3.asm",                          "Description" : "Basic Clock, LPM3 Using WDT ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_lpm3_vlo.asm",                      "Description" : "Basic Clock, LPM3 Using WDT ISR, VLO ACLK"},
	{"SourcePreview" : "msp430x24x_MPY_01.asm",                        "Description" : "16x16 Unsigned Multiply"},
	{"SourcePreview" : "msp430x24x_MPY_02.asm",                        "Description" : "8x8 Unsigned Multiply"},
	{"SourcePreview" : "msp430x24x_MPY_03.asm",                        "Description" : "16x16 Signed Multiply"},
	{"SourcePreview" : "msp430x24x_MPY_04.asm",                        "Description" : "8x8 Signed Multiply"},
	{"SourcePreview" : "msp430x24x_MPY_05.asm",                        "Description" : "16x16 Unsigned Multiply Accumulate"},
	{"SourcePreview" : "msp430x24x_MPY_06.asm",                        "Description" : "8x8 Unsigned Multiply Accumulate"},
	{"SourcePreview" : "msp430x24x_MPY_07.asm",                        "Description" : "16x16 Signed Multiply Accumulate"},
	{"SourcePreview" : "msp430x24x_MPY_08.asm",                        "Description" : "8x8 Signed Multiply Accumulate"},
	{"SourcePreview" : "msp430x24x_nmi.asm",                           "Description" : "Configure RST/NMI as NMI"},
	{"SourcePreview" : "msp430x24x_OF_LFXT1_nmi.asm",                  "Description" : "LFXT1 Oscillator Fault Detection"},
	{"SourcePreview" : "msp430x24x_OF_XT2.asm",                        "Description" : "XT2 Oscillator Fault Detection"},
	{"SourcePreview" : "msp430x24x_P1_01.asm",                         "Description" : "Software Poll P1.3, Set P1.0 if P1.3 = 1"},
	{"SourcePreview" : "msp430x24x_P1_02.asm",                         "Description" : "Software Port Interrupt Service on P1.3 from LPM4"},
	{"SourcePreview" : "msp430x24x_P1_05.asm",                         "Description" : "Write a byte to Port 1"},
	{"SourcePreview" : "msp430x24x_rosc.asm",                          "Description" : "DCOCLK Biased with External Resistor Rosc"},
	{"SourcePreview" : "msp430x24x_svs_01.asm",                        "Description" : "SVS, POR @ 2.5V Vcc"},
	{"SourcePreview" : "msp430x24x_ta_01.asm",                         "Description" : "Timer_A, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_ta_02.asm",                         "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_ta_03.asm",                         "Description" : "Timer_A, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_ta_04.asm",                         "Description" : "Timer_A, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_ta_05.asm",                         "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_ta_11.asm",                         "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_ta_13.asm",                         "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_ta_17.asm",                         "Description" : "Timer_A, PWM TA1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_ta_19.asm",                         "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_ta_20.asm",                         "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_ta_24.asm",                         "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, 32kHz INCLK"},
	{"SourcePreview" : "msp430x24x_tb_01.asm",                         "Description" : "Timer_B, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_tb_02.asm",                         "Description" : "Timer_B, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_tb_03.asm",                         "Description" : "Timer_B, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_tb_04.asm",                         "Description" : "Timer_B, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_tb_05.asm",                         "Description" : "Timer_B, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_tb_06.asm",                         "Description" : "Timer_B, PWM TB1-6, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_tb_07.asm",                         "Description" : "Timer_B, PWM TB1-6, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_tb_09.asm",                         "Description" : "Timer_B, PWM TB1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_tb_10.asm",                         "Description" : "Timer_B, PWM TB1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_uscia0_irda_01.asm",                "Description" : "USCI_A0 IrDA External Loopback Test, 8MHz SMCLK"},
	{"SourcePreview" : "msp430x24x_uscia0_irda_02.asm",                "Description" : "USCI_A0 IrDA Monitor, 8MHz SMCLK"},
	{"SourcePreview" : "msp430x24x_uscia0_irda_03.asm",                "Description" : "USCI_A0 IrDA Physical Layer Comm, 8MHz SMCLK"},
	{"SourcePreview" : "msp430x24x_uscia0_spi_01.asm",                 "Description" : "USCI_A0, SPI Interface to HC164 Shift Register"},
	{"SourcePreview" : "msp430x24x_uscia0_spi_02.asm",                 "Description" : "USCI_A0, SPI Interface to HC165 Shift Register"},
	{"SourcePreview" : "msp430x24x_uscia0_spi_03.asm",                 "Description" : "USCI_A0, SPI Interface to HC165/164 Shift Registers"},
	{"SourcePreview" : "msp430x24x_uscia0_spi_09.asm",                 "Description" : "USCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430x24x_uscia0_spi_10.asm",                 "Description" : "USCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430x24x_uscia0_uart_01_115k.asm",           "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_uscia0_uart_01_115k_lpm4.asm",      "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK, LPM4"},
	{"SourcePreview" : "msp430x24x_uscia0_uart_01_19200.asm",          "Description" : "USCI_A0, 19200 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_uscia0_uart_01_9600.asm",           "Description" : "USCI_A0, 9600 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_uscia0_uart_04_9600.asm",           "Description" : "USCI_A0, 9600 UART, SMCLK, LPM0, Echo with over-sampling"},
	{"SourcePreview" : "msp430x24x_uscia0_uart_05_9600.asm",           "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_uscia0_uart_06_9600.asm",           "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 String, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_uscia0_uart_07_9600.asm",           "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 RX/TX, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_uscia0_uart_08_9600.asm",           "Description" : "USCI_A0, UART 9600 Full-Duplex Transceiver, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_uscia1_irda_01.asm",                "Description" : "USCI_A1 IrDA External Loopback Test, 8MHz SMCLK"},
	{"SourcePreview" : "msp430x24x_uscia1_spi_09.asm",                 "Description" : "USCI_A1, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430x24x_uscia1_spi_10.asm",                 "Description" : "USCI_A1, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430x24x_uscia1_uart_05_9600.asm",           "Description" : "USCI_A1, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_01.asm",                 "Description" : "USCI_B0 I2C Master to TMP100, Set P1.0 if Temp > 28C"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_02.asm",                 "Description" : "USCI_B0 I2C Master Interface to PCF8574, Read/Write"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_04.asm",                 "Description" : "USCI_B0 I2C Master RX single bytes from MSP430 Slave"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_05.asm",                 "Description" : "USCI_B0 I2C Slave TX single bytes to MSP430 Master"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_06.asm",                 "Description" : "USCI_B0 I2C Master TX single bytes to MSP430 Slave"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_07.asm",                 "Description" : "USCI_B0 I2C Slave RX single bytes from MSP430 Master"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_08.asm",                 "Description" : "USCI_B0 I2C Master TX multiple bytes to MSP430 Slave"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_09.asm",                 "Description" : "USCI_B0 I2C Slave RX multiple bytes from MSP430 Master"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_10.asm",                 "Description" : "USCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "msp430x24x_uscib0_i2c_11.asm",                 "Description" : "USCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "msp430x24x_uscib0_spi_01.asm",                 "Description" : "USCI_B0, SPI Interface to TLC549 8-Bit ADC"},
	{"SourcePreview" : "msp430x24x_uscib0_spi_02.asm",                 "Description" : "USCI_B0, SPI Interface to TLV1549 10-Bit ADC"},
	{"SourcePreview" : "msp430x24x_uscib0_spi_09.asm",                 "Description" : "USCI_B0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430x24x_uscib0_spi_10.asm",                 "Description" : "USCI_B0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430x24x_uscib1_i2c_06.asm",                 "Description" : "USCI_B1 I2C Master TX single bytes to MSP430 Slave"},
	{"SourcePreview" : "msp430x24x_uscib1_i2c_07.asm",                 "Description" : "USCI_B1 I2C Slave RX single bytes from MSP430 Master"},
	{"SourcePreview" : "msp430x24x_uscib1_spi_09.asm",                 "Description" : "USCI_B1, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430x24x_uscib1_spi_10.asm",                 "Description" : "USCI_B1, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430x24x_wdt_01.asm",                        "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_wdt_02.asm",                        "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x24x_wdt_04.asm",                        "Description" : "WDT+ Failsafe Clock, WDT mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x24x_wdt_05.asm",                        "Description" : "Reset on Invalid Address fetch, Toggle P1.0"},
	{"SourcePreview" : "msp430x24x_wdt_06.asm",                        "Description" : "WDT+ Failsafe Clock, 32kHz ACLK"}
];

