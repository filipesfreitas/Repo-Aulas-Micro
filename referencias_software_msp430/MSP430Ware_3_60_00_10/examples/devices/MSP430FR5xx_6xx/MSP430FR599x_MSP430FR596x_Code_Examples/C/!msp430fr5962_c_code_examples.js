var jsonInfo = [
	{
		"MCU"    : "MSP430",
		"Device" : "MSP430FR5962",
		"Filter" : "MSP430FR5962"
	}
];

var jsonObjC = [
	{"SourcePreview" : "msp430fr599x_1.c",                                  "Description" : "Blink LED"},
	{"SourcePreview" : "msp430fr599x_active_01.c",                          "Description" : "Active mode test"},
	{"SourcePreview" : "msp430fr599x_active_02.c",                          "Description" : "Active Mode Test with 100% CHR"},
	{"SourcePreview" : "msp430fr599x_adc12_01.c",                           "Description" : "ADC12, Sample A1, Avcc Ref, Set P1.0 if A1 > 0.5*AVcc"},
	{"SourcePreview" : "msp430fr599x_adc12_02.c",                           "Description" : "ADC12, Using the Internal Reference"},
	{"SourcePreview" : "msp430fr599x_adc12_03.c",                           "Description" : "ADC12, Sample A2-A3 Differential,Set P1.0 if i/p> 1V"},
	{"SourcePreview" : "msp430fr599x_adc12_05.c",                           "Description" : "ADC12, Using an External Reference"},
	{"SourcePreview" : "msp430fr599x_adc12_10.c",                           "Description" : "ADC12, Sample A10 Temp and Convert to oC and oF"},
	{"SourcePreview" : "msp430fr599x_adc12_11.c",                           "Description" : "ADC12, Sample A1, T0A1 Trig, Ultra-Low Pwr"},
	{"SourcePreview" : "msp430fr599x_adc12_21.c",                           "Description" : "ADC12, Window Comparator, 2.5V ref"},
	{"SourcePreview" : "msp430fr599x_adc12_22.c",                           "Description" : "ADC12, Window Comparator, 2.5V ref, 2's Complement"},
	{"SourcePreview" : "msp430fr599x_compe_01.c",                           "Description" : "COMPE output Toggle in LPM4; input channel CE1"},
	{"SourcePreview" : "msp430fr599x_compe_02.c",                           "Description" : "COMPE output Toggle in LPM4; input channel CE12"},
	{"SourcePreview" : "msp430fr599x_compe_04.c",                           "Description" : "COMPE output Toggle in LPM4, Vcompare is compared against the Vcc*1/2"},
	{"SourcePreview" : "msp430fr599x_compe_05.c",                           "Description" : "COMPE Hysteresis, COUT Toggle in LPM4; High speed mode"},
	{"SourcePreview" : "msp430fr599x_crc16.c",                              "Description" : "Calculate CRC16 and compare"},
	{"SourcePreview" : "msp430fr599x_crc32.c",                              "Description" : "Calculate CRC32 and compare"},
	{"SourcePreview" : "msp430fr599x_cs_01.c",                              "Description" : "Configure MCLK for 8MHz operation"},
	{"SourcePreview" : "msp430fr599x_cs_02.c",                              "Description" : "Configure MCLK for 16MHz operation"},
	{"SourcePreview" : "msp430fr599x_cs_03.c",                              "Description" : "Output 32768Hz crystal on XT1 and observe failsafe"},
	{"SourcePreview" : "msp430fr599x_cs_04.c",                              "Description" : "ACLK = XT1 = 32768Hz, SMCLK= XT2 = 8MHz, MCLK = DCO"},
	{"SourcePreview" : "msp430fr599x_cs_05.c",                              "Description" : "Using LFXT in bypass mode, failsafe operation shown"},
	{"SourcePreview" : "msp430fr599x_dma_01.c",                             "Description" : "DMA0, Repeated Block to-from RAM, Software Trigger"},
	{"SourcePreview" : "msp430fr599x_euscia0_spi_09.c",                     "Description" : "eUSCI_A0, SPI 3-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430fr599x_euscia0_spi_10.c",                     "Description" : "eUSCI_A0, SPI 3-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430fr599x_euscia0_spi_11.c",                     "Description" : "eUSCI_A0, SPI 4-Wire Master Incremented Data"},
	{"SourcePreview" : "msp430fr599x_euscia0_spi_12.c",                     "Description" : "eUSCI_A0, SPI 4-Wire Slave Data Echo"},
	{"SourcePreview" : "msp430fr599x_euscia0_uart_01.c",                    "Description" : "eUSCI_A0 UART echo at 9600 baud using BRCLK = 8MHz"},
	{"SourcePreview" : "msp430fr599x_euscia0_uart_02.c",                    "Description" : "eUSCI_A0 UART echo at 9600 baud using BRCLK = 32768Hz"},
	{"SourcePreview" : "msp430fr599x_euscia0_uart_03.c",                    "Description" : "eUSCI_A0 External Loopback test @ 115200 baud"},
	{"SourcePreview" : "msp430fr599x_euscia0_uart_04.c",                    "Description" : "eUSCI_A0 External Loopback test @ 9600 baud using BRCLK = 32768Hz"},
	{"SourcePreview" : "msp430fr599x_euscib0_i2c_10.c",                     "Description" : "eUSCI_B0 I2C Master RX multiple bytes from MSP430 Slave"},
	{"SourcePreview" : "msp430fr599x_euscib0_i2c_11.c",                     "Description" : "eUSCI_B0 I2C Slave TX multiple bytes to MSP430 Master"},
	{"SourcePreview" : "msp430fr599x_euscib0_i2c_master_multislave.c",      "Description" : "eUSCI_B0 I2C Master TX bytes to Multiple Slaves"},
	{"SourcePreview" : "msp430fr599x_euscib0_i2c_multislave.c",             "Description" : "eUSCI_B0 I2C 4 Hardware I2C slaves"},
	{"SourcePreview" : "msp430fr599x_framwrite.c",                          "Description" : "Long word writes to FRAM"},
	{"SourcePreview" : "msp430fr599x_frctl_a_01.c",                         "Description" : "Entire FRAM Write Protection Enabled"},
	{"SourcePreview" : "msp430fr599x_lpm0.c",                               "Description" : "Enters LPM0 with ACLK = LFXT, MCLK = 1MHz"},
	{"SourcePreview" : "msp430fr599x_lpm3_02.c",                            "Description" : "Enters LPM3 with ACLK = VLO"},
	{"SourcePreview" : "msp430fr599x_lpm3_03.c",                            "Description" : "Enters LPM3 with ACLK = LFXT1"},
	{"SourcePreview" : "msp430fr599x_lpm4-5_01.c",                          "Description" : "Enters LPM4.5 and wakes-up via P1.3 interrupt with SVS enabled"},
	{"SourcePreview" : "msp430fr599x_lpm4-5_02.c",                          "Description" : "Enters LPM4.5 and wakes-up via P1.3 interrupt with SVS disabled"},
	{"SourcePreview" : "msp430fr599x_lpm4.c",                               "Description" : "Enters LPM4 with SVS enabled"},
	{"SourcePreview" : "msp430fr599x_mpu_01.c",                             "Description" : "MPU write protection violation - interrupt"},
	{"SourcePreview" : "msp430fr599x_mpu_02.c",                             "Description" : "MPU Write protection violation - PUC"},
	{"SourcePreview" : "msp430fr599x_of_lfxt1_nmi.c",                       "Description" : "LFXT Oscillator Fault Detection"},
	{"SourcePreview" : "msp430fr599x_p1_01.c",                              "Description" : "Software Poll P1.3, Set P1.0 if P1.3 = 1"},
	{"SourcePreview" : "msp430fr599x_p1_03.c",                              "Description" : "Port Interrupt Service on P1.3 from LPM4"},
	{"SourcePreview" : "msp430fr599x_rtc_01.c",                             "Description" : "RTC in counter mode toggles P1.0 every 1s"},
	{"SourcePreview" : "msp430fr599x_rtc_02.c",                             "Description" : "RTC in real time clock mode in LPM3"},
	{"SourcePreview" : "msp430fr599x_ta0_01.c",                             "Description" : "Timer0_A3, Toggle P1.0, CCR0 Cont Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_ta0_02.c",                             "Description" : "Timer0_A3, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_ta0_04.c",                             "Description" : "Timer0_A3, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430fr599x_ta0_16.c",                             "Description" : "Timer0_A3, PWM TA0.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_ta0_17.c",                             "Description" : "Timer0_A3, PWM TA0.1-2, Up Mode, 32KHz ACLK"},
	{"SourcePreview" : "msp430fr599x_ta0_capture.c",                        "Description" : "Timer0_A3 Capture of VLO Period using DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_ta1_05.c",                             "Description" : "Timer1_A3, Toggle P1.0, CCR0 Cont Mode ISR, 32KHz ACLK"},
	{"SourcePreview" : "msp430fr599x_ta1_06.c",                             "Description" : "Timer1_A3, Toggle P1.0, CCR0 UP Mode ISR, 32KHz ACLK"},
	{"SourcePreview" : "msp430fr599x_ta1_16.c",                             "Description" : "Timer1_A3, PWM TA1.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_ta1_17.c",                             "Description" : "Timer1_A3, PWM TA1.1-2, Up Mode, 32KHz ACLK"},
	{"SourcePreview" : "msp430fr599x_tb0_01.c",                             "Description" : "TimerB, Toggle P1.0, CCR0 Cont Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_tb0_02.c",                             "Description" : "TimerB, Toggle P1.0, CCR0 UP Mode ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_tb0_03.c",                             "Description" : "TimerB, Toggle P1.0, Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_tb0_04.c",                             "Description" : "TimerB, Toggle P1.0, Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430fr599x_tb0_06.c",                             "Description" : "TimerB, Toggle P1.0, CCR0 UP Mode ISR, 32KHz ACLK"},
	{"SourcePreview" : "msp430fr599x_tb0_16.c",                             "Description" : "TimerB, PWM TB0.1-2, Up Mode, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_tinyram_01.c",                         "Description" : "Store global variable in Tiny RAM and toggle LED"},
	{"SourcePreview" : "msp430fr599x_wdt_01.c",                             "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_wdt_02.c",                             "Description" : "WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK"},
	{"SourcePreview" : "msp430fr599x_wdt_04.c",                             "Description" : "WDT, Failsafe Clock, WDT mode, DCO SMCLK"},
	{"SourcePreview" : "msp430fr599x_wdt_05.c",                             "Description" : "Reset on Invalid Address fetch, Toggle P1.0"}
];
