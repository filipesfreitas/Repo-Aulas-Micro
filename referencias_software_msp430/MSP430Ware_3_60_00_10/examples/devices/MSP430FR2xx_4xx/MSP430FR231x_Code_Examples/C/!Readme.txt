File Name                                Description
----------------------------------------------------------------------------------------
msp430fr231x_1.c                         Toggle P1.0 using software
msp430fr231x_adc10_01.c                  ADC, Sample A1, AVcc Ref, Set LED if A1 > 0.5*AVcc
msp430fr231x_adc10_02.c                  ADC, Sample A1, internal 1.5V Ref, Set P1.0 if A1 > 0.5V
msp430fr231x_adc10_05.c                  ADC, Lo_Batt, Set P1.0 if AVcc < 2.50V
msp430fr231x_adc10_10.c                  ADC, Sample A2/A1/A0, internal 1.5V Ref.
msp430fr231x_adc10_11.c                  ADC, Sample A1, internal 1.5V Ref, tb0.1 Trig, Set P1.0 if A1>0.5V
msp430fr231x_adc10_16.c                  ADC, Sample A12 Temp and Convert to oC and oF
msp430fr231x_adc10_21.c                  ADC, Window Comparator, 1.5V ref, Timer trigger, DCO
msp430fr231x_CRC.c                       CRC16, Compare CRC output with software-based algorithm
msp430fr231x_CS_01.c                     Configure MCLK for 8MHz sourced from DCO.
msp430fr231x_CS_02.c                     Configure MCLK for 8MHz and XT1 sourcing ACLK and FLLREF
msp430fr231x_CS_03.c                     Configure MCLK for 16MHz operation, and REFO sourcing FLLREF and ACLK
msp430fr231x_CS_04.c                     Output 32768Hz crystal on XT1 and observe failsafe
msp430fr231x_CS_05.c                     Configure MCLK for 16MHz operation, and XT1 sourcing FLLREF and ACLK
msp430fr231x_CS_06.c                     Configure MCLK for 4MHz and XT1HF sourcing MCLK
msp430fr231x_CS_07.c                     Configure MCLK for 1MHz and use DCO software trim to lock FLL
msp430fr231x_eCOMP_01.c                  eCOMP output Toggle in LPM3; Vcompare is compared against internal reference
msp430fr231x_eCOMP_02.c                  eCOMP output Toggle in LPM3, Vcompare is compared against the Vcc*1/2
msp430fr231x_eCOMP_03.c                  eCOMP output Toggle, wake up from LPM3, Vcompare is compared against 1V
msp430fr231x_eCOMP_04.c                  eCOMP Hysteresis, COUT Toggle in LPM4; Low speed and low power mode
msp430fr231x_eCOMP_05.c                  eCOMP output connected toTimer_B capture, Detect pulse width
msp430fr231x_eCOMP_06.c                  eCOMP to compare two channel input voltage
msp430fr231x_euscia0_spi_09.c            eUSCI_A0, SPI 3-Wire Master Incremented Data
msp430fr231x_euscia0_spi_10.c            eUSCI_A0, SPI 3-Wire Slave Data Echo
msp430fr231x_euscia0_spi_11.c            eUSCI_A0, SPI 4-Wire Master Incremented Data
msp430fr231x_euscia0_spi_12.c            eUSCI_A0, SPI 4-Wire Slave Data Echo
msp430fr231x_euscia0_uart_01.c           eUSCI_A0 UART echo at 9600 baud using BRCLK = 8MHz
msp430fr231x_euscia0_uart_03.c           eUSCI_A0 External Loopback test @ 115200 baud
msp430fr231x_euscia0_uart_05.c           eUSCI_A0 UART echo at 4800 baud using ACLK=32.768KHz
msp430fr231x_euscib0_i2c_10.c            eUSCI_B0 I2C Master RX multiple bytes from MSP430 Slave
msp430fr231x_euscib0_i2c_11.c            eUSCI_B0 I2C Slave TX multiple bytes to MSP430 Master
msp430fr231x_euscib0_i2c_15.c            eUSCI_B0 I2C Master TX bytes to Multiple Slaves
msp430fr231x_euscib0_i2c_16.c            eUSCI_B0 I2C 4 Hardware I2C slaves
msp430fr231x_framwrite.c                 Long word writes to FRAM
msp430fr231x_framwrite_persistent.c      FRAM write, use #pragma PERSISTENT to initialize variable in FRAM
msp430fr231x_LPM3_01.c                   Enters LPM3 with ACLK = XT1CLK = 32768Hz.
msp430fr231x_LPM3_02.c                   Configure MCLK and SMCLK up and down to adapt LPM3.
msp430fr231x_lpm3_5_01.c                 LPM3.5, device enter LPM3.5 and toggles P1.0 with RTC interrupt handling every 1s
msp430fr231x_lpm4_5_01.c                 LPM4.5, Device enters LPM4.5 waiting for a port interrupt on P1.2
msp430fr231x_lpm4_5_02.c                 LPM4.5, Device enters LPM4.5 waiting for a port interrupt on P1.2 with SVS disabled
msp430fr231x_P1_01.c                     Software Poll P1.3, Set P1.0 if P1.3 = 1
msp430fr231x_P1_03.c                     Software Port Interrupt Service on P1.3 from LPM3
msp430fr231x_pinosc_01.c                 Capacitive Touch, Pin Oscillator Method, 1 button
msp430fr231x_pinosc_02.c                 Capacitive Touch, Pin Oscillator Method, 4-buttons
msp430fr231x_RTC_01.c                    RTC, toggle P1.0 every 1s
msp430fr231x_RTC_02.c                    RTC, device enter LPM3.5 and toggle P1.0 in RTC interrupt handling every 1s
msp430fr231x_RTC_03.c                    RTC, using ACLK as clock source, toggle P1.0 every 1s
msp430fr231x_SAC_L1_01.c                 SAC0, General-Purpose Mode
msp430fr231x_SAC_L1_02.c                 SAC0, Unity-Gain Buffer Mode
msp430fr231x_SAC_L1_03.c                 TRI0+SAC0, Two-Stage amplifier, Use ADC to sample SAC0 ouput
msp430fr231x_tb0_01.c                    Timer0_B3, Toggle P1.0, CCR0 Count Mode ISR, DCO SMCLK
msp430fr231x_tb0_02.c                    Timer0_B3, Toggle P1.0, CCR0 Up Mode ISR, DCO SMCLK
msp430fr231x_tb0_04.c                    Timer0_B3, Toggle P1.0, Overflow ISR, 32kHz ACLK
msp430fr231x_tb0_16.c                    Timer0_B3, PWM tb0.1-2, Up Mode, DCO SMCLK
msp430fr231x_tb0_17.c                    Timer0_B3, PWM tb0.1-2, Up Mode, 32KHz ACLK
msp430fr231x_tb0_20.c                    Timer0_B3, PWM tb0.1-2, Up/Down Mode, 32kHz ACLK
msp430fr231x_tb0_22.c                    Timer0_B3, Ultra-Low Pwr Pulse Accumulator
msp430fr231x_tb0_capture.c               Timer0_B3 Capture of ACLK
msp430fr231x_tb0_highimpedance.c         Timer0_B3, Output high-impedance state
msp430fr231x_tb0_shadow_register.c       Timer0_B3, Showcase double-buffered TBxCCRn feature
msp430fr231x_tb1_05.c                    Timer1_B3, Toggle P1.0, CCR0 Cont Mode ISR, 32KHz ACLK
msp430fr231x_tb1_06.c                    Timer1_B3, Toggle P1.0, CCR0 UP Mode ISR, 32KHz ACLK
msp430fr231x_tb1_16.c                    Timer1_B3, PWM tb1.1-2, Up Mode, DCO SMCLK
msp430fr231x_tb1_17.c                    Timer1_B3, PWM tb1.1-2, Up Mode, 32KHz ACLK
msp430fr231x_TRI_01.c                    TRI0, General-Purpose Mode
msp430fr231x_TRI_02.c                    TRI0+ADC10, Use ADC to sample TRI output
msp430fr231x_WDT_01.c                    WDT, Toggle P1.0, Interval Overflow ISR, DCO SMCLK
msp430fr231x_WDT_02.c                    WDT, Toggle P1.0, Interval Overflow ISR, 32kHz ACLK
msp430fr231x_WDT_04.c                    WDT,  Failsafe Clock, WDT mode, DCO SMCLK
msp430fr231x_WDT_05.c                    WDT,  Reset on Invalid Address fetch, Toggle P1.0
msp430fr231x_WDT_06.c                    WDT,  Failsafe Clock, WDT mode, 32kHz ACLK
msp430fr231x_WDT_07.c                    WDT, WDT mode, use VLO as clock source

