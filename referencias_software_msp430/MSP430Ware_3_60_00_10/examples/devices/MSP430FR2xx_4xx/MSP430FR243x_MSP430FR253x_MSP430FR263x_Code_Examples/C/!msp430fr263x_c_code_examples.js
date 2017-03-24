var jsonInfo = [
	{
		"MCU"    : "MSP430",
		"Device" : "MSP430FR263x",
		"Filter" : "MSP430FR263\\d"
	}
];

var jsonObjC = [
	{"SourcePreview" : "msp430fr243x_1.c",                         "Description" : "Toggle P1.0 using software"},
	{"SourcePreview" : "msp430fr243x_adc10_01.c",                  "Description" : "ADC, Sample A1, AVcc Ref, Set LED if A1 > 0.5*AVcc"},
	{"SourcePreview" : "msp430fr243x_adc10_02.c",                  "Description" : "ADC, Sample A1, internal 1.5V Ref, Set P1.0 if A1 > 0.5V"},
	{"SourcePreview" : "msp430fr243x_adc10_05.c",                  "Description" : "ADC, Lo_Batt, Set P1.0 if AVcc < 2.50V"},
	{"SourcePreview" : "msp430fr243x_adc10_10.c",                  "Description" : "ADC, Sample A2/A1/A0, internal 1.5V Ref."},
	{"SourcePreview" : "msp430fr243x_adc10_11.c",                  "Description" : "ADC, Sample A1, internal 1.5V Ref, TA0.1 Trig, Set P1.0 if A1>0.5V"},
	{"SourcePreview" : "msp430fr243x_adc10_16.c",                  "Description" : "ADC, Sample A12 Temp and Convert to oC and oF"},
	{"SourcePreview" : "msp430fr243x_adc10_21.c",                  "Description" : "ADC, Window Comparator, 1.5V ref, Timer trigger, DCO"},
	{"SourcePreview" : "msp430fr243x_CRC.c",                       "Description" : "CRC16, Compare CRC output with software-based algorithm"},
	{"SourcePreview" : "msp430fr243x_CS_01.c",                     "Description" : "Configure MCLK for 8MHz sourced from DCO."},
	{"SourcePreview" : "msp430fr243x_CS_02.c",                     "Description" : "Configure MCLK for 8MHz and XT1 sourcing ACLK and FLLREF"},
	{"SourcePreview" : "msp430fr243x_CS_03.c",                     "Description" : "Configure MCLK for 16MHz operation, and REFO sourcing FLLREF and ACLK"},
	{"SourcePreview" : "msp430fr243x_CS_04.c",                     "Description" : "Output 32768Hz crystal on XT1 and observe failsafe"},
	{"SourcePreview" : "msp430fr243x_CS_05.c",                     "Description" : "Configure MCLK for 16MHz operation, and XT1 sourcing FLLREF and ACLK"},
	{"SourcePreview" : "msp430fr243x_euscia0_spi_09.c",            "Description" : "eUSCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430fr243x_euscia0_spi_10.c",            "Description" : "eUSCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430fr243x_euscia0_spi_11.c",            "Description" : "eUSCI_A0, SPI 4-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430fr243x_euscia0_spi_12.c",            "Description" : "eUSCI_A0, SPI 4-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430fr243x_euscia0_uart_01.c",           "Description" : "eUSCI_A0 UART echo at 9600 baud using BRCLK = 8MHz"},
	{"SourcePreview" : "msp430fr243x_euscia0_uart_03.c",           "Description" : "USCI_A0 External Loopback test @ 115200 baud"},
	{"SourcePreview" : "msp430fr243x_euscib0_i2c_10.c",            "Description" : "eUSCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "msp430fr243x_euscib0_i2c_11.c",            "Description" : "eUSCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "msp430fr243x_euscib0_i2c_15.c",            "Description" : "eUSCI_B0 I2C Master TX bytes to Multiple Slaves"},
	{"SourcePreview" : "msp430fr243x_euscib0_i2c_16.c",            "Description" : "eUSCI_B0 I2C 4 Hardware I2C slaves"},
	{"SourcePreview" : "msp430fr243x_framwrite.c",                 "Description" : "Long word writes to FRAM"},
	{"SourcePreview" : "msp430fr243x_framwrite_persistent.c",      "Description" : "FRAM write, use #pragma PERSISTENT to initialize variable in FRAM"},
	{"SourcePreview" : "msp430fr243x_LPM3_01.c",                   "Description" : "Enters LPM3 with ACLK = XT1CLK = 32768Hz."},
	{"SourcePreview" : "msp430fr243x_LPM3_02.c",                   "Description" : "Configure MCLK and SMCLK up and down to adapt LPM3."},
	{"SourcePreview" : "msp430fr243x_lpm3_5_01.c",                 "Description" : "LPM3.5, device enter LPM3.5 and toggles P1.0 with RTC interrupt handling every 1s"},
	{"SourcePreview" : "msp430fr243x_lpm4_5_01.c",                 "Description" : "LPM4.5, Device enters LPM4.5 waiting for a port interrupt on P1.2"},
	{"SourcePreview" : "msp430fr243x_lpm4_5_02.c",                 "Description" : "LPM4.5, Device enters LPM4.5 waiting for a port interrupt on P1.2 with SVS disabled"},
	{"SourcePreview" : "msp430fr243x_P1_01.c",                     "Description" : "Software Poll P1.3, Set P1.0 if P1.3 = 1"},
	{"SourcePreview" : "msp430fr243x_P1_03.c",                     "Description" : "Software Port Interrupt Service on P1.3 from LPM3"},
	{"SourcePreview" : "msp430fr243x_RTC_01.c",                    "Description" : "RTC, toggle P1.0 every 1s"},
	{"SourcePreview" : "msp430fr243x_RTC_02.c",                    "Description" : "RTC, device enter LPM3.5 and toggle P1.0 in RTC interrupt handling every 1s"},
	{"SourcePreview" : "msp430fr243x_ta0_01.c",                    "Description" : "Timer0_A3, Toggle P1.0, CCR0 Count Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430fr243x_ta0_02.c",                    "Description" : "Timer0_A3, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430fr243x_ta0_04.c",                    "Description" : "Timer0_A3, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430fr243x_ta0_16.c",                    "Description" : "Timer0_A3, PWM TA0.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430fr243x_ta0_17.c",                    "Description" : "Timer0_A3, PWM TA0.1-2, Up Mode, 32KHz ACLK"},
	{"SourcePreview" : "msp430fr243x_ta0_20.c",                    "Description" : "Timer0_A3, PWM TA0.1-2, Up/Down Mode, 32kHz ACLK"},
	{"SourcePreview" : "msp430fr243x_ta0_22.c",                    "Description" : "Timer_A, Ultra-Low Pwr Pulse Accumulator"},
	{"SourcePreview" : "msp430fr243x_ta0_capture.c",               "Description" : "Timer0_A3 Capture of ACLK"},
	{"SourcePreview" : "msp430fr243x_ta1_05.c",                    "Description" : "Timer1_A3, Toggle P1.0, CCR0 Cont Mode ISR, 32KHz ACLK"},
	{"SourcePreview" : "msp430fr243x_ta1_06.c",                    "Description" : "Timer1_A3, Toggle P1.0, CCR0 UP Mode ISR, 32KHz ACLK"},
	{"SourcePreview" : "msp430fr243x_ta1_16.c",                    "Description" : "Timer1_A3, PWM TA1.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430fr243x_ta1_17.c",                    "Description" : "Timer1_A3, PWM TA1.1-2, Up Mode, 32KHz ACLK"},
	{"SourcePreview" : "msp430fr243x_WDT_01.c",                    "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430fr243x_WDT_02.c",                    "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430fr243x_WDT_04.c",                    "Description" : "WDT,  Failsafe Clock, WDT mode, DCO SMCLK"},
	{"SourcePreview" : "msp430fr243x_WDT_05.c",                    "Description" : "WDT,  Reset on Invalid Address fetch, Toggle P1.0"},
	{"SourcePreview" : "msp430fr243x_WDT_06.c",                    "Description" : "WDT,  Failsafe Clock, WDT mode, 32kHz ACLK"}
];

