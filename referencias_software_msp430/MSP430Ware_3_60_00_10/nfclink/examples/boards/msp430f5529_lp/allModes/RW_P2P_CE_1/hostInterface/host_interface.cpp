#include "host_interface.h"
#include "buffer.h"
#include "hardware.h"
#include "API.h"
#include "MSP430_hardware.h"


extern "C" {

#include "USB_config/descriptors.h"

#include "USB_API/USB_Common/device.h"
#include "USB_API/USB_Common/types.h"               //Basic Type declarations
#include "USB_API/USB_Common/usb.h"                 //USB-specific functions

#include "USB_API/USB_CDC_API/UsbCdc.h"
#include "usbConstructs.h"

#define MAX_DATA_LENGTH	261

//Global flags set by events
volatile BYTE bCDCDataReceived_event = FALSE;   //Indicates data has been received without an open rcv operation
}



byte * readp;
byte * writep;
indextype readlen, readsize, writelen, writesize;

static Buffer<indextype, RS232_BUFFSIZE> recbuf;
static Buffer<indextype, RS232_BUFFSIZE> sendbuf;

void Host_Interface::Init(void) {
	//Init USB
    USB_init();

    //Enable various USB event handling routines
    USB_setEnabledEvents(
        kUSB_VbusOnEvent + kUSB_VbusOffEvent + kUSB_receiveCompletedEvent
        + kUSB_dataReceivedEvent + kUSB_sendCompletedEvent + kUSB_UsbSuspendEvent + kUSB_UsbResumeEvent +
        kUSB_UsbResetEvent);

    //See if we're already attached physically to USB, and if so, connect to it
    //Normally applications don't invoke the event handlers, but this is an exception.
    if (USB_connectionInfo() & kUSB_vbusPresent){
        USB_handleVbusOnEvent();
    }

    __no_operation();
	__enable_interrupt();                           //Enable interrupts globally

//	while( USB_connectionState() != ST_ENUM_ACTIVE) //wait until MCU has been enumerated
//	{
//		__no_operation();
//	}

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

	//send the chars from buf
	cdcSendDataWaitTilDone(buf,len,CDC0_INTFNUM,0);

	GPIO::setSerialTX(false);
	return 0;
}

unsigned short Host_Interface::Received() {
	return recbuf.used();
}

void Host_Interface::run() {
}

BYTE USBCDC_handleDataReceived (BYTE intfNum)
{
    //TO DO: You can place your code here

	word rcvd_len = 0;

	GPIO::setSerialRX(true);

	// Flush the buffer to ensure we have enough memory available
	rcvd_len = cdcReceiveDataInBuffer (recbuf.getBufferPtr(), recbuf.free(), CDC0_INTFNUM);

	recbuf.updateBufferValues(rcvd_len);

	bCDCDataReceived_event = TRUE;

	GPIO::setSerialRX(false);

    return (TRUE);                              //return FALSE to go asleep after interrupt (in the case the CPU slept before
                                                //interrupt)
}

#pragma vector= USCI_A1_VECTOR
__interrupt void USCI_A1_ISR (void)
{
	while(1);
}
