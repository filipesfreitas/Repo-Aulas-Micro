#include <msp430g2553.h>	


int main()
{
	P1DIR = 
	_BIS_SR(GIE);//+LPM4_bits);
	while(1)
	{
		
	}	
	return 0;
}

interrupt(PORT1_VECTOR) P1_interrupcao(void)
{
	P1OUT |= LED1;
}
