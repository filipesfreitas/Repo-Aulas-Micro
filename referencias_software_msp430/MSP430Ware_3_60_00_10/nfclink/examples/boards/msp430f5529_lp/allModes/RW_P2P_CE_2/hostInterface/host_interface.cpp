#include "host_interface.h"
#include "buffer.h"
#include "hardware.h"
#include "API.h"
#include "MSP430_hardware.h"


extern "C" {

#include "msp430.h"
#include "inc/hw_memmap.h"
#include "usci_a_uart.h"
#include "wdt_a.h"
#include "gpio.h"
#include "ucs.h"

}

byte * readp;
byte * writep;
indextype readlen, readsize, writelen, writesize;

static Buffer<indextype, RS232_BUFFSIZE> recbuf;
static Buffer<indextype, RS232_BUFFSIZE> sendbuf;

void Host_Interface::Init(void) {
	//P4.4,5 = USCI_A0 TXD/RXD
	GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN4 + GPIO_PIN5);

	if (STATUS_FAIL
			== USCI_A_UART_initAdvance(__MSP430_BASEADDRESS_USCI_A1__, USCI_A_UART_CLOCKSOURCE_SMCLK,
					13, 9, 0,
					USCI_A_UART_NO_PARITY, USCI_A_UART_LSB_FIRST, USCI_A_UART_ONE_STOP_BIT,
					USCI_A_UART_MODE, USCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION)) {
		return;
	}


	//Enable UART module for operation
	USCI_A_UART_enable(__MSP430_BASEADDRESS_USCI_A1__);

	//Enable Receive Interrupt
	USCI_A_UART_enableInterrupt(__MSP430_BASEADDRESS_USCI_A1__,
			USCI_A_UART_RECEIVE_INTERRUPT);

	//interrupts enabled
	__bis_SR_register(GIE);
}

unsigned short Host_Interface::Read(unsigned char* buf, unsigned short len) {
	indextype x = 0;

	if(Received())
		x = recbuf.Read(buf, len);

	if (x) {
		return x;
	} else
		return 0;
}

unsigned short Host_Interface::Write(unsigned char* buf, unsigned short len) {

	GPIO::setSerialTX(true);

	while(len--)
	{
		USCI_A_UART_transmitData(__MSP430_BASEADDRESS_USCI_A1__, *buf++);
	    //USCI TX buffer ready?
	    while (!USCI_A_UART_getInterruptStatus(__MSP430_BASEADDRESS_USCI_A1__, UCTXIFG)) ;
	}

	GPIO::setSerialTX(false);

	return 0;
}

unsigned short Host_Interface::Received() {
	return recbuf.used();
}

void Host_Interface::run() {
}

//******************************************************************************
//
//This is the USCI_A1 interrupt vector service routine.
//
//******************************************************************************
static byte x = 0;
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void) {
	int state = __even_in_range(UCA1IV, 4);
	switch (state) {
	// Vector 0 - no interrupt
	case 0:
		break;
	//Vector 2 - RXIFG
	case 2:
		//Receive the data
		x = USCI_A_UART_receiveData(__MSP430_BASEADDRESS_USCI_A1__);
		recbuf.Write(&x, 1); //store received byte in recbuf
		break;
	// Vector 4 - TXIFG
	case 4: {
		USCI_A_UART_clearInterruptFlag(__MSP430_BASEADDRESS_USCI_A1__,UCA1IFG);
		if (!(sendbuf.empty())) //any data in writebuffer to be sent ?
		{
			byte x;
			if (sendbuf.Read(&x, 1)) //fetch byte from buffer
					{
				USCI_A_UART_transmitData(__MSP430_BASEADDRESS_USCI_A1__, x);
			}
		} else //no more data to send
		{
			USCI_A_UART_disableInterrupt(__MSP430_BASEADDRESS_USCI_A1__,
					USCI_A_UART_TRANSMIT_INTERRUPT); //Disable the transmit interrupt, otherwize TXE would cause another interrupt (because the transmit data register is still empty)
		}
		break;
	}
	default:
		break;
	}
}

#pragma vector= USB_UBM_VECTOR
__interrupt void USB_UBM_ISR (void)
{
	while(1);
}
