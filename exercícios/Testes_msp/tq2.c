#include <msp430g2553.h>	
#include<intrinsic.h>
	

void main(void){	

WDTCTL = WDTPW | WDTHOLD;	
	
asm("mov.w #10,R15");
}	

