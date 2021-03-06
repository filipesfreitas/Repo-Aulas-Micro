var jsonObjASM = [
	{"SourcePreview" : "msp430x54x_adc12_01.asm",                "Description" : "ADC12, Sample A0, Set P1.0 if A0 > 0.5*AVcc"},
	{"SourcePreview" : "msp430x54x_adc12_02.asm",                "Description" : "ADC12, Using the Internal Reference"},
	{"SourcePreview" : "msp430x54x_adc12_05.asm",                "Description" : "ADC12, Using an External Reference"},
	{"SourcePreview" : "msp430x54x_adc12_06.asm",                "Description" : "ADC12, Repeated Sequence of Conversions"},
	{"SourcePreview" : "msp430x54x_adc12_07.asm",                "Description" : "ADC12, Repeated Single Channel Conversions"},
	{"SourcePreview" : "msp430x54x_adc12_08.asm",                "Description" : "ADC12, Using A8 and A9 Ext Channels for Conversion"},
	{"SourcePreview" : "msp430x54x_adc12_09.asm",                "Description" : "ADC12, Sequence of Conversions (non-repeated)"},
	{"SourcePreview" : "msp430x54x_adc12_10.asm",                "Description" : "ADC12, Sample A10 Temp and Convert to oC and oF"},
	{"SourcePreview" : "msp430x54x_dma_01.asm",                  "Description" : "DMA0, Repeated Block to-from RAM, Software Trigger"},
	{"SourcePreview" : "msp430x54x_dma_02.asm",                  "Description" : "DMA0, Single Transfer in Block Mode UART1 9600, ACLK"},
	{"SourcePreview" : "msp430x54x_dma_03.asm",                  "Description" : "SPI TX & RX using DMA0 & DMA1 Single Transfer in Fixed Address Mode"},
	{"SourcePreview" : "msp430x54x_dma_04.asm",                  "Description" : "DMA0, Single transfer using ADC12 triggered by TimerB"},
	{"SourcePreview" : "msp430x54x_fet_1.asm",                   "Description" : "Blink the LED in a while loop "},
	{"SourcePreview" : "msp430x54x_flashwrite_01.asm",           "Description" : "Single-Byte Flash In-System Programming, Copy SegC to SegD"},
	{"SourcePreview" : "msp430x54x_flashwrite_02.asm",           "Description" : "Flash In-System Programming w/ Long-Word write at 0x1800"},
	{"SourcePreview" : "msp430x54x_LPM3_1.asm",                  "Description" : "Block Write and Memory Erase @ 0x10000 Executed from RAM"},
	{"SourcePreview" : "msp430x54x_LPM3_2.asm",                  "Description" : "Enters LPM3 (ACLK = LFXT1)"},
	{"SourcePreview" : "msp430x54x_MPY_1.asm",                   "Description" : "Enters LPM3 (ACLK = VLO)"},
	{"SourcePreview" : "msp430x54x_MPY_10.asm",                  "Description" : "16x16 Unsigned Multiply"},
	{"SourcePreview" : "msp430x54x_MPY_11.asm",                  "Description" : "32x32 Signed Multiply"},
	{"SourcePreview" : "msp430x54x_MPY_12.asm",                  "Description" : "32x32 Signed Multiply Accumalate"},
	{"SourcePreview" : "msp430x54x_MPY_13.asm",                  "Description" : "32x32 Unsigned Multiply Accumalate"},
	{"SourcePreview" : "msp430x54x_MPY_14.asm",                  "Description" : "Saturation mode overflow test"},
	{"SourcePreview" : "msp430x54x_MPY_15.asm",                  "Description" : "Saturation mode underflow test"},
	{"SourcePreview" : "msp430x54x_MPY_2.asm",                   "Description" : "Fractional mode, Q15 multiplication"},
	{"SourcePreview" : "msp430x54x_MPY_3.asm",                   "Description" : "8x8 Unsigned Multiply"},
	{"SourcePreview" : "msp430x54x_MPY_4.asm",                   "Description" : "16x16 Signed Multiply"},
	{"SourcePreview" : "msp430x54x_MPY_5.asm",                   "Description" : "8x8 Signed Multiply"},
	{"SourcePreview" : "msp430x54x_MPY_6.asm",                   "Description" : "16x16 Unsigned Multiply Accumulate"},
	{"SourcePreview" : "msp430x54x_MPY_7.asm",                   "Description" : "8x8 Unsigned Multiply Accumulate"},
	{"SourcePreview" : "msp430x54x_MPY_8.asm",                   "Description" : "16x16 Signed Multiply Accumulate"},
	{"SourcePreview" : "msp430x54x_MPY_9.asm",                   "Description" : "8x8 Signed Multiply Accumulate"},
	{"SourcePreview" : "msp430x54x_OF_LFXT1_nmi.asm",            "Description" : "32x32 Unsigned Multiply"},
	{"SourcePreview" : "msp430x54x_P1_01.asm",                   "Description" : "LFXT1 Oscillator Fault Detection"},
	{"SourcePreview" : "msp430x54x_P1_02.asm",                   "Description" : "Software Poll P1.4, Set P1.0 if P1.4 = 1"},
	{"SourcePreview" : "msp430x54x_P1_05.asm",                   "Description" : "Software Port Interrupt Service on P1.4 from LPM4 with Internal Pull-up Resistance Enabled"},
	{"SourcePreview" : "msp430x54x_PA_05.asm",                   "Description" : "Write a byte to Port 1"},
	{"SourcePreview" : "msp430x54x_RTC_01.asm",                  "Description" : "Write a Word to Port A (Port1+Port2)"},
	{"SourcePreview" : "msp430x54x_ta3_01.asm",                  "Description" : "RTC in Counter Mode toggles P1.0 every 1s"},
	{"SourcePreview" : "msp430x54x_ta3_02.asm",                  "Description" : "Timer_A3, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_ta3_03.asm",                  "Description" : "Timer_A3, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_ta3_04.asm",                  "Description" : "Timer_A3, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_ta3_05.asm",                  "Description" : "Timer_A3, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x54x_ta3_08.asm",                  "Description" : "Timer_A3, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x54x_ta3_11.asm",                  "Description" : "Timer_A3, Toggle P1.0;P2.1-3, Cont. Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x54x_ta3_13.asm",                  "Description" : "Timer_A3, Toggle P2.1/TA1.0, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x54x_ta3_14.asm",                  "Description" : "Timer_A3, Toggle P2.1/TA1.0, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_ta3_16.asm",                  "Description" : "Timer_A3, Toggle P2.1/TA1.0, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x54x_ta3_17.asm",                  "Description" : "Timer_A3, PWM TA1.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_ta3_19.asm",                  "Description" : "Timer_A3, PWM TA1.1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x54x_ta3_20.asm",                  "Description" : "Timer_A3, PWM TA1.1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_tb_01.asm",                   "Description" : "Timer_A3, PWM TA1.1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430x54x_tb_02.asm",                   "Description" : "Timer_B, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_tb_03.asm",                   "Description" : "Timer_B, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_tb_04.asm",                   "Description" : "Timer_B, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_tb_05.asm",                   "Description" : "Timer_B, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x54x_tb_10.asm",                   "Description" : "Timer_B, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430x54x_UCS_1.asm",                   "Description" : "Timer_B, PWM TB1-6, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430x54x_UCS_2.asm",                   "Description" : "Software Toggle P1.0 at Default DCO"},
	{"SourcePreview" : "msp430x54x_UCS_3.asm",                   "Description" : "Software Toggle P1.0 with 8MHz DCO"},
	{"SourcePreview" : "msp430x54x_UCS_4.asm",                   "Description" : "Software Toggle P1.0 with 12MHz DCO"},
	{"SourcePreview" : "msp430x54x_UCS_5.asm",                   "Description" : "FLL+, Runs Internal DCO at 2.45MHz with LFXT1 as Ref"},
	{"SourcePreview" : "msp430x54x_UCS_6.asm",                   "Description" : "VLO sources ACLK"},
	{"SourcePreview" : "msp430x54x_UCS_7.asm",                   "Description" : "XT1 sources ACLK "},
	{"SourcePreview" : "msp430x54x_UCS_8.asm",                   "Description" : "FLL+, Output 32kHz Xtal + HF Xtal + Internal DCO"},
	{"SourcePreview" : "msp430x54x_UCS_9.asm",                   "Description" : "XT2 sources MCLK & SMCLK"},
	{"SourcePreview" : "msp430x54x_uscia0_duplex_9600.asm",      "Description" : "LFXT1 HF Xtal + Internal DCO"},
	{"SourcePreview" : "MSP430x54x_uscia0_spi_09.asm",           "Description" : "USCI_A0, UART 9600 Full-Duplex Transceiver, 32K ACLK"},
	{"SourcePreview" : "MSP430x54x_uscia0_spi_10.asm",           "Description" : "USCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "MSP430x54x_uscia0_uart_01.asm",          "Description" : "USCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "MSP430x54x_uscia0_uart_02.asm",          "Description" : "USCI_A0, 115200 UART Echo ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430x54x_uscia0_uart_03.asm",          "Description" : "USCI_A0, Ultra-Low Pwr UART 2400 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430x54x_uscia0_uart_04.asm",          "Description" : "USCI_A0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430x54x_uscib0_i2c_04.asm",           "Description" : "USCI_A0, 9600 UART, SMCLK, LPM0, Echo with over-sampling"},
	{"SourcePreview" : "MSP430x54x_uscib0_i2c_05.asm",           "Description" : "USCI_B0 I2C Master RX single bytes from MSP430 Master"},
	{"SourcePreview" : "MSP430x54x_uscib0_i2c_06.asm",           "Description" : "USCI_B0 I2C Slave TX single bytes to MSP430 Slave"},
	{"SourcePreview" : "MSP430x54x_uscib0_i2c_07.asm",           "Description" : "USCI_B0 I2C Master TX single bytes to MSP430 Slave"},
	{"SourcePreview" : "MSP430x54x_uscib0_i2c_08.asm",           "Description" : "USCI_B0 I2C Slave RX single bytes from MSP430 Master"},
	{"SourcePreview" : "MSP430x54x_uscib0_i2c_09.asm",           "Description" : "USCI_B0 I2C Master TX multiple bytes to MSP430 Slave"},
	{"SourcePreview" : "MSP430x54x_uscib0_i2c_10.asm",           "Description" : "USCI_B0 I2C Slave RX multiple bytes from MSP430 Master"},
	{"SourcePreview" : "MSP430x54x_uscib0_i2c_11.asm",           "Description" : "USCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "MSP430x54x_wdt_01.asm",                  "Description" : "USCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "MSP430x54x_wdt_02.asm",                  "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "MSP430x54x_wdt_04.asm",                  "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "MSP430x54x_wdt_05.asm",                  "Description" : "WDT+ Failsafe Clock, WDT mode, DCO SMCLK"}
];

