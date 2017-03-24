#include "application.h"
#include "hardware.h"
#include "MSP430_hardware.h"

int blink() {
crBegin
	LED_TEST_BLINK_POUT ^= LED_TEST_BLINK_BIT;
	crWaitms(500);
crFinish
}

int main(void) {
	Application::init();
	LED_TEST_BLINK_PDIR |= LED_TEST_BLINK_BIT;

	while(1)
	{
		Application::run();
		blink();
	}
}
