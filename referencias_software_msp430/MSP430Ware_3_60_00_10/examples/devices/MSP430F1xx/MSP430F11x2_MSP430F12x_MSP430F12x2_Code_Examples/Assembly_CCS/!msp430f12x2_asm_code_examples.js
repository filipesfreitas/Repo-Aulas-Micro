var jsonObjASM = [
	{"SourcePreview" : "fet120_1.asm",                 "Description" : "Software Toggle P1.0"},
	{"SourcePreview" : "fet120_5timers.asm",           "Description" : "5 Interrupt Timers & 2 Clock Outputs, 32kHz ACLK"},
	{"SourcePreview" : "fet120_adc10_01.asm",          "Description" : "ADC10, Sample A0, AVcc Ref, Set P1.0 if A0 > 0.5*AVcc"},
	{"SourcePreview" : "fet120_adc10_02.asm",          "Description" : "ADC10, Sample A0, 1.5V Ref, Set P1.0 if A0 > 0.2V"},
	{"SourcePreview" : "fet120_adc10_03.asm",          "Description" : "ADC10, Sample A10 Temp, Set P1.0 if Temp ++ ~2C"},
	{"SourcePreview" : "fet120_adc10_04.asm",          "Description" : "ADC10, Sample A0, Signed, Set P1.0 if A0 > 0.5*AVcc"},
	{"SourcePreview" : "fet120_adc10_05.asm",          "Description" : "ADC10, Sample A11, Lo_Batt, Set P1.0 if AVcc < 2.3V"},
	{"SourcePreview" : "fet120_adc10_06.asm",          "Description" : "ADC10, Output Internal Vref on P2.4 & ADCCLK on P1.0"},
	{"SourcePreview" : "fet120_adc10_07.asm",          "Description" : "ADC10, DTC Sample A0 64x, AVcc, Repeat Single, DCO"},
	{"SourcePreview" : "fet120_adc10_08.asm",          "Description" : "ADC10, DTC Sample A0 64x, 1.5V, Repeat Single, DCO"},
	{"SourcePreview" : "fet120_adc10_09.asm",          "Description" : "ADC10, DTC Sample A10 64x, 1.5V, Repeat Single, DCO"},
	{"SourcePreview" : "fet120_adc10_10.asm",          "Description" : "ADC10, DTC Sample A2-0, AVcc, Single Sequence, DCO"},
	{"SourcePreview" : "fet120_adc10_11.asm",          "Description" : "ADC10, Sample A0, 1.5V, TA1 Trig, Set P1.0 if > 0.5V"},
	{"SourcePreview" : "fet120_adc10_12.asm",          "Description" : "ADC10, Sample A7, 1.5V, TA1 Trig, Ultra-Low Pwr"},
	{"SourcePreview" : "fet120_adc10_13.asm",          "Description" : "ADC10, DTC Sample A1 32x, AVcc, TA0 Trig, DCO"},
	{"SourcePreview" : "fet120_adc10_14.asm",          "Description" : "ADC10, DTC Sample A1-0 32x, AVcc, Repeat Seq, DCO"},
	{"SourcePreview" : "fet120_adc10_15.asm",          "Description" : "ADC10, DTC Sample A10 32x to Flash, Int Ref, DCO"},
	{"SourcePreview" : "fet120_adc10_16.asm",          "Description" : "ADC10, DTC Sample A0 -> TA1, AVcc, DCO"},
	{"SourcePreview" : "fet120_adc10_17.asm",          "Description" : "ADC10, DTC Sample A0 -> TA1, AVcc, HF XTAL"},
	{"SourcePreview" : "fet120_adc10_18.asm",          "Description" : "ADC10, DTC Sample A1/0 -> TA1/2, 2.5V, HF XTAL"},
	{"SourcePreview" : "fet120_adc10_19.asm",          "Description" : "ADC10, DTC Sample A0 64x, AVcc, HF XTAL"},
	{"SourcePreview" : "fet120_adc10_20.asm",          "Description" : "ADC10, DTC Sample A0 2-Blk Cont. Mode, AVcc, HF XTAL"},
	{"SourcePreview" : "fet120_adc10_temp.asm",        "Description" : "ADC10, Sample A10 Temp and Convert to oC and oF"},
	{"SourcePreview" : "fet120_clks.asm",              "Description" : "Basic Clock, Output Buffered SMCLK, ACLK and MCLK/10"},
	{"SourcePreview" : "fet120_flash_write.asm",       "Description" : "Flash In-System Programming, Copy SegA to SegB"},
	{"SourcePreview" : "fet120_fll_01.asm",            "Description" : "Basic Clock, Implement Auto RSEL SW FLL"},
	{"SourcePreview" : "fet120_fll_02.asm",            "Description" : "Basic Clock, Implement Cont. SW FLL with Auto RSEL"},
	{"SourcePreview" : "fet120_hfxtal.asm",            "Description" : "Basic Clock, LFXTI/MCLK Sourced from HF XTAL"},
	{"SourcePreview" : "fet120_hfxtal_nmi.asm",        "Description" : "Basic Clock, LFXT1/MCLK Sourced from HF XTAL, NMI"},
	{"SourcePreview" : "fet120_lpm3.asm",              "Description" : "Basic Clock, LPM3 Using WDT ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet120_nmi.asm",               "Description" : "Basic Clock, Configure RST/NMI as NMI"},
	{"SourcePreview" : "fet120_rosc.asm",              "Description" : "DCOCLK Biased with External Resistor Rosc"},
	{"SourcePreview" : "fet120_spi0_0549.asm",         "Description" : "USART0, SPI Interface to TLC549 8-Bit ADC"},
	{"SourcePreview" : "fet120_spi0_1549.asm",         "Description" : "USART0, SPI Interface to TLV1549 10-Bit ADC"},
	{"SourcePreview" : "fet120_spi0_16x.asm",          "Description" : "USART0, SPI Interface to HC165/164 Shift Registers"},
	{"SourcePreview" : "fet120_spi0_7822.asm",         "Description" : "USART0, SPI Interface to ADS7822 ADC"},
	{"SourcePreview" : "fet120_spi0_mstr.asm",         "Description" : "USART0, SPI 3-Wire Master"},
	{"SourcePreview" : "fet120_spi0_slav.asm",         "Description" : "USART0, SPI 3-Wire Slave"},
	{"SourcePreview" : "fet120_ta_01.asm",             "Description" : "Timer_A, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet120_ta_02.asm",             "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet120_ta_03.asm",             "Description" : "Timer_A, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "fet120_ta_04.asm",             "Description" : "Timer_A, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet120_ta_05.asm",             "Description" : "Timer_A, Toggle P1.0, CCR0 Up Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet120_ta_06.asm",             "Description" : "Timer_A, Toggle P1.0, CCR1 Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet120_ta_07.asm",             "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "fet120_ta_08.asm",             "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet120_ta_09.asm",             "Description" : "Timer_A, Toggle P1.0-3, Cont. Mode ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet120_ta_10.asm",             "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "fet120_ta_11.asm",             "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet120_ta_12.asm",             "Description" : "Timer_A, Toggle P1.1/TA0, Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet120_ta_13.asm",             "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "fet120_ta_14.asm",             "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet120_ta_15.asm",             "Description" : "Timer_A, Toggle P1.1/TA0, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet120_ta_16.asm",             "Description" : "Timer_A, PWM TA1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "fet120_ta_17.asm",             "Description" : "Timer_A, PWM TA1-2, Up Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet120_ta_18.asm",             "Description" : "Timer_A, PWM TA1-2, Up Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet120_ta_19.asm",             "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, DCO SMCLK"},
	{"SourcePreview" : "fet120_ta_20.asm",             "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "fet120_ta_21.asm",             "Description" : "Timer_A, PWM TA1-2, Up/Down Mode, HF XTAL ACLK"},
	{"SourcePreview" : "fet120_ta_22.asm",             "Description" : "Timer_A, Ultra-Low Pwr Pulse Accumulator"},
	{"SourcePreview" : "fet120_uart01_0115k.asm",      "Description" : "USART0, UART 115200 Echo ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet120_uart01_02400.asm",      "Description" : "USART0, Ultra-Low Pwr UART 2400 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet120_uart01_09600.asm",      "Description" : "USART0, UART 9600 Echo ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet120_uart01_19200.asm",      "Description" : "USART0, UART 19200 Echo ISR, HF XTAL ACLK"},
	{"SourcePreview" : "fet120_uart02_09600.asm",      "Description" : "USART0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet120_uart02_19200.asm",      "Description" : "USART0, Ultra-Low Pwr UART 19200 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet120_uart03_09600.asm",      "Description" : "USART0, UART 9600 Echo ISR, 32kHz ACLK + DCO"},
	{"SourcePreview" : "fet120_uart03_19200.asm",      "Description" : "USART0, UART 19200 Echo ISR, 32kHz ACLK + DCO"},
	{"SourcePreview" : "fet120_uart04_09600.asm",      "Description" : "USART0, UART 9600 Echo ISR, No XTAL, Rosc DCO Only"},
	{"SourcePreview" : "fet120_uart04_19200.asm",      "Description" : "USART0, UART 19200 Echo ISR, No XTAL, Rosc DCO Only"},
	{"SourcePreview" : "fet120_uart05_09600.asm",      "Description" : "USART0, Ultra-Low Pwr UART 9600 Echo ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet120_uart06_09600.asm",      "Description" : "USART0, Ultra-Low Pwr UART 9600 String, 32kHz ACLK"},
	{"SourcePreview" : "fet120_wdt_01.asm",            "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "fet120_wdt_02.asm",            "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "fet120_wdt_03.asm",            "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, HF XTAL ACLK"}
];

