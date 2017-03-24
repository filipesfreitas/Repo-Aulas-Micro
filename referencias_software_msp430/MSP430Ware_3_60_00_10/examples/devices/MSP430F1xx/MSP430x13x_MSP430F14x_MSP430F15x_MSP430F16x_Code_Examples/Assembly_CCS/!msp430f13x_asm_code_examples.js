var jsonObjASM = [
	{"SourcePreview" : "fet140_1.asm",                   "Description" : "Software Toggle P1.0"},
	{"SourcePreview" : "fet140_adc12_01.asm",            "Description" : "ADC12, Sample A0, Set P1.0 if A0 > 0.5*AVcc"},
	{"SourcePreview" : "fet140_adc12_02.asm",            "Description" : "ADC12, Using the Internal Reference"},
	{"SourcePreview" : "fet140_adc12_03.asm",            "Description" : "ADC12, Sample A10 Temp, Set P1.0 if Temp ++ ~2C"},
	{"SourcePreview" : "fet140_adc12_04.asm",            "Description" : "ADC12, Extend Sampling Period with SHT Bits"},
	{"SourcePreview" : "fet140_adc12_05.asm",            "Description" : "ADC12, Using an External Reference"},
	{"SourcePreview" : "fet140_adc12_06.asm",            "Description" : "ADC12, Repeated Sequence of Conversions"},
	{"SourcePreview" : "fet140_adc12_07.asm",            "Description" : "ADC12, Repeated Single Channel Conversions"},
	{"SourcePreview" : "fet140_adc12_08.asm",            "Description" : "ADC12, Using 10 External Channels for Conversion"},
	{"SourcePreview" : "fet140_adc12_09.asm",            "Description" : "ADC12, Sequence of Conversions (non-repeated)"},
	{"SourcePreview" : "fet140_adc12_10.asm",            "Description" : "ADC12, Sample A10 Temp and Convert to oC and oF"},
	{"SourcePreview" : "fet140_clks.asm",                "Description" : "Basic Clock, Output Buffered SMCLK, ACLK and MCLK"},
	{"SourcePreview" : "fet140_dac12_01.asm",            "Description" : "DAC12_0, Output 1.0V on DAC0"},
	{"SourcePreview" : "fet140_dac12_02.asm",            "Description" : "DAC12_1, Output 2.0V on DAC1"},
	{"SourcePreview" : "fet140_dac12_03.asm",            "Description" : "DAC12_0, Output Voltage Ramp on DAC0"},
	{"SourcePreview" : "fet140_dma_01.asm",              "Description" : "DMA0, Repeated Burst to-from RAM, Software Trigger"},
	{"SourcePreview" : "fet140_dma_02.asm",              "Description" : "DMA0, Repeated Block to P1OUT, TACCR2 Trigger"},
	{"SourcePreview" : "fet140_dma_03.asm",              "Description" : "DMA0, Repeated Block UART1 9600, TACCR2, ACLK"},
	{"SourcePreview" : "fet140_dma_04.asm",              "Description" : "DMA0, Block Mode UART1 9600, ACLK"},
	{"SourcePreview" : "fet140_dma_05.asm",              "Description" : "DMA0, Repeated Blk to DAC0, Sine Output, TACCR1, DCO"},
	{"SourcePreview" : "fet140_dma_06.asm",              "Description" : "DMA2, Rpt'd Blk to DAC1, 8-Bit Sine, TBCCR2, DCO"},
	{"SourcePreview" : "fet140_dma_07.asm",              "Description" : "DMA0/1, Rpt'd Blk to DAC12_0/1, Sin/Cos, TACCR1, XT2"},
	{"SourcePreview" : "fet140_dma_08.asm",              "Description" : "DMA0, Rpt'd Block, I2C Master Intf. to DAC8571, DCO"},
	{"SourcePreview" : "fet140_dma_09.asm",              "Description" : "DMA0, ADC12 A10 Block Xfer to RAM, TBCCR1, DCO"},
	{"SourcePreview" : "fet140_dma_10.asm",              "Description" : "DMA0, ADC12 A10 Block Xfer to Flash, TBCCR1, DCO"},
	{"SourcePreview" : "fet140_dma_11.asm",              "Description" : "DMA0/1, ADC12 A10 Block Xfer to MPY/RAM, TBCCR1, DCO"},
	{"SourcePreview" : "fet140_dma_12.asm",              "Description" : "DMA0/1, Block Mode UART1 9600 Auto RX/TX String, ACLK"},
	{"SourcePreview" : "fet140_dma_13.asm",              "Description" : "DMA0/1/2, USART0 UART 9600 Full-Duplex Transcvr, ACLK"},
	{"SourcePreview" : "fet140_dma_14.asm",              "Description" : "DMA0/1/2, USART0 SPI 3-Wire SPI Master P1.x Exchange"},
	{"SourcePreview" : "fet140_dma_15.asm",              "Description" : "DMA0/1/2, USART0 SPI 3-Wire SPI Slave P1.x Exchange"},
	{"SourcePreview" : "fet140_dma_16.asm",              "Description" : "DMA0/1/2, USART1 SPI 3-Wire Master P1.x Exchange"},
	{"SourcePreview" : "fet140_flashwrite_01.asm",       "Description" : "Flash In-System Programming, Copy SegA to SegB"},
	{"SourcePreview" : "fet140_flashwrite_02.asm",       "Description" : "Flash In-System Programming, BlockWrite"},
	{"SourcePreview" : "fet140_fll_01.asm",              "Description" : "Basic Clock, Implement Auto RSEL SW FLL"},
	{"SourcePreview" : "fet140_fll_02.asm",              "Description" : "Basic Clock, Implement Cont. SW FLL with Auto RSEL"},
	{"SourcePreview" : "fet140_hfxt2.asm",               "Description" : "Basic Clock, MCLK Sourced from HF XTAL XT2"},
	{"SourcePreview" : "fet140_hfxtal.asm",              "Description" : "Basic Clock, LFXT1/MCLK Sourced from HF XTAL"},
	{"SourcePreview" : "fet140_hfxtal_nmi.asm",          "Description" : "Basic Clock, MCLK Sourced from HF XTAL & Osc Fault"},
	{"SourcePreview" : "fet140_i2c_01.asm",              "Description" : "I2C, Master Intf. to TMP100, Set P1.0 if Temp > 28C"},
	{"SourcePreview" : "fet140_i2c_02.asm",              "Description" : "I2C, Master Interface to PCF8574, Read/Write"},
	{"SourcePreview" : "fet140_i2c_03.asm",              "Description" : "I2C, Master Interface to DAC8571, Repeat Mode"},
	{"SourcePreview" : "fet140_i2c_04.asm",              "Description" : "I2C, Master Reads from MSP430 Slave"},
	{"SourcePreview" : "fet140_i2c_05.asm",              "Description" : "I2C, Slave Transmits to MSP430 Master"},
	{"SourcePreview" : "fet140_i2c_06.asm",              "Description" : "I2C, Master Transmits to MSP430 Slave"},
	{"SourcePreview" : "fet140_i2c_07.asm",              "Description" : "I2C, Slave Reads from MSP430 Master"},
	{"SourcePreview" : "fet140_i2c_08.asm",              "Description" : "I2C, Master Writes Multiple Bytes to MSP430 Slave"},
	{"SourcePreview" : "fet140_i2c_09.asm",              "Description" : "I2C, Slave Writes to MSP430 Master, Repeat Mode"},
	{"SourcePreview" : "fet140_i2c_10.asm",              "Description" : "I2C, Master Reads from MSP430 Slave, Repeat Mode"},
	{"SourcePreview" : "fet140_i2c_11.asm",              "Description" : "I2C, Master Writes/Reads with Slave, Rptd Start"},
	{"SourcePreview" : "fet140_i2c_12.asm",              "Description" : "I2C, Slave Reads/Writes to MSP430 Master"},
	{"SourcePreview" : "fet140_lpm3.asm",                "Description" : "Basic Clock, LPM3 Using WDT ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_nmi.asm",                 "Description" : "Basic Clock, Configure RST/NMI as NMI"},
	{"SourcePreview" : "fet140_rosc.asm",                "Description" : "DCOCLK Biased with External Resistor Rosc"},
	{"SourcePreview" : "fet140_spi0_01.asm",             "Description" : "USART0, SPI Interface to HC164 Shift Register"},
	{"SourcePreview" : "fet140_spi0_02.asm",             "Description" : "USART0, SPI Interface to HC165 Shift Register"},
	{"SourcePreview" : "fet140_spi0_03.asm",             "Description" : "USART0, SPI Interface to HC165/164 Shift Registers"},
	{"SourcePreview" : "fet140_spi0_04.asm",             "Description" : "USART0, SPI Interface to TLV5616 DAC"},
	{"SourcePreview" : "fet140_spi0_05.asm",             "Description" : "USART0, SPI 3-Wire Master"},
	{"SourcePreview" : "fet140_spi0_06.asm",             "Description" : "USART0, SPI 3-Wire Slave"},
	{"SourcePreview" : "fet140_spi1_01.asm",             "Description" : "USART1, SPI Interface to TLC549 8-Bit ADC"},
	{"SourcePreview" : "fet140_spi1_02.asm",             "Description" : "USART1, SPI Interface to TLV1549 10-Bit ADC"},
	{"SourcePreview" : "fet140_spi1_03.asm",             "Description" : "USART1, SPI Interface to TLV5616 DAC"},
	{"SourcePreview" : "fet140_svs_01.asm",              "Description" : "SVS, POR @ 2.5V Vcc"},
	{"SourcePreview" : "fet140_ta_01.asm",               "Description" : "Timer_A, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_ta_02.asm",               "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_ta_03.asm",               "Description" : "Timer_A, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_ta_04.asm",               "Description" : "Timer_A, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_ta_05.asm",               "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_ta_06.asm",               "Description" : "Timer_A, Toggle P1.0, CCR1 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_ta_07.asm",               "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_ta_08.asm",               "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_ta_09.asm",               "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_ta_10.asm",               "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "fet140_ta_11.asm",               "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet140_ta_12.asm",               "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_ta_13.asm",               "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "fet140_ta_14.asm",               "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet140_ta_15.asm",               "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_ta_16.asm",               "Description" : "Timer_A, PWM TA1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "fet140_ta_17.asm",               "Description" : "Timer_A, PWM TA1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet140_ta_18.asm",               "Description" : "Timer_A, PWM TA1-2, Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_ta_19.asm",               "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "fet140_ta_20.asm",               "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet140_ta_21.asm",               "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_ta_22.asm",               "Description" : "Timer_A, PWM TA1-2, Up Mode, XT2 HF XTAL SMCLK"},
	{"SourcePreview" : "fet140_ta_23.asm",               "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, XT2 HF XTAL SMCLK"},
	{"SourcePreview" : "fet140_tb_01.asm",               "Description" : "Timer_B, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_tb_02.asm",               "Description" : "Timer_B, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_tb_03.asm",               "Description" : "Timer_B, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_tb_04.asm",               "Description" : "Timer_B, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_tb_05.asm",               "Description" : "Timer_B, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_tb_06.asm",               "Description" : "Timer_B, Toggle P1.0, CCR1 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_tb_07.asm",               "Description" : "Timer_B, Toggle P4.0-6, Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_tb_08.asm",               "Description" : "Timer_B, Toggle P4.0-6, Cont. Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet140_tb_09.asm",               "Description" : "Timer_B, Toggle P4.0-6, Cont. Mode ISR, XT2 SMCLK"},
	{"SourcePreview" : "fet140_tb_10.asm",               "Description" : "Timer_B, PWM TB1-6, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "fet140_tb_11.asm",               "Description" : "Timer_B, PWM TB1-6, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet140_tb_12.asm",               "Description" : "Timer_A, PWM TB1-2, Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_tb_13.asm",               "Description" : "Timer_B, PWM TB1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "fet140_tb_14.asm",               "Description" : "Timer_B, PWM TB1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet140_tb_15.asm",               "Description" : "Timer_B, PWM TB1-2, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_tb_16.asm",               "Description" : "Timer_B, PWM TB1-6, Up Mode, XT2 HF XTAL SMCLK"},
	{"SourcePreview" : "fet140_tb_17.asm",               "Description" : "Timer_B, PWM TB1-6, Up/Down Mode, XT2 HF XTAL SMCLK"},
	{"SourcePreview" : "fet140_uart01_0115k.asm",        "Description" : "USART0, UART 115200 Echo ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_uart01_0115k_2.asm",      "Description" : "USART0, UART 115200 Echo ISR, XT2 HF XTAL SMCLK"},
	{"SourcePreview" : "fet140_uart01_02400.asm",        "Description" : "USART0, Ultra-Low Pwr UART 2400 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_uart01_09600.asm",        "Description" : "USART0, UART 9600 Echo ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_uart01_19200.asm",        "Description" : "USART0, UART 19200 Echo ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_uart01_19200_2.asm",      "Description" : "USART0, UART 19200 Echo ISR, XT2 HF XTAL SMCLK"},
	{"SourcePreview" : "fet140_uart02_09600.asm",        "Description" : "USART0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_uart02_19200.asm",        "Description" : "USART0, Ultra-Low Pwr UART 19200 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_uart03_09600.asm",        "Description" : "USART0, UART 9600 Echo ISR, 32kHz ACLK + DCO"},
	{"SourcePreview" : "fet140_uart03_19200.asm",        "Description" : "USART0, UART 19200 Echo ISR, 32kHz ACLK + DCO"},
	{"SourcePreview" : "fet140_uart04_09600.asm",        "Description" : "USART0, UART 9600 Echo ISR, No XTAL, Rosc DCO Only"},
	{"SourcePreview" : "fet140_uart04_19200.asm",        "Description" : "USART0, UART 19200 Echo ISR, No XTAL, Rosc DCO Only"},
	{"SourcePreview" : "fet140_uart05_09600.asm",        "Description" : "USART0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_uart06_09600.asm",        "Description" : "USART0, Ultra-Low Pwr UART 9600 String, 32kHz ACLK"},
	{"SourcePreview" : "fet140_uart07_09600.asm",        "Description" : "USART0, Ultra-Low Pwr UART 9600 RX/TX, 32kHz ACLK"},
	{"SourcePreview" : "fet140_uart08_09600.asm",        "Description" : "USART0, UART 9600 Full-Duplex Transceiver, 32K ACLK"},
	{"SourcePreview" : "fet140_uart11_0115k.asm",        "Description" : "USART1, UART 115200 Echo ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_uart11_0115k_2.asm",      "Description" : "USART1, UART 115200 Echo ISR, XT2 HF XTAL SMCLK"},
	{"SourcePreview" : "fet140_uart11_02400.asm",        "Description" : "USART1, Ultra-Low Pwr UART 2400 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_uart11_09600.asm",        "Description" : "USART1, UART 9600 Echo ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_uart11_19200.asm",        "Description" : "USART1, UART 19200 Echo ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet140_uart11_19200_2.asm",      "Description" : "USART1, UART 19200 Echo ISR, XT2 HF XTAL SMCLK"},
	{"SourcePreview" : "fet140_uartxx_00123.asm",        "Description" : "USART0/1, UART 19200-115200 Router, XT2 HF XTAL SMCLK"},
	{"SourcePreview" : "fet140_wdt_01.asm",              "Description" : "WDT, Toggle P1.0, Interval overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "fet140_wdt_02.asm",              "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet140_wdt_03.asm",              "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, HF XTAL ACLK"}
];
