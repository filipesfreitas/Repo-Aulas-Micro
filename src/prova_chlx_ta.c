#include<msp430g2553.h>
#include<legacymsp430.h>

#define chlx1 BIT0
#define chlx2 BIT1
#define chlx3 BIT2
#define key1  BIT3
#define key2	BIT4
#define key3  BIT5

void Charlie_LED_on(volatile char pin_pos,volatile char pin_neg){
	P1DIR &= ~(chlx1 + chlx2 + chlx3);//leitura digital
	P1OUT |= pin_pos;
	P1OUT &= ~pin_neg;
	P1DIR |= (pin_pos + pin_neg);
}
int main(void){

	WDTCTL = WDTPW + WDTCNTCL;       // watchdog timer
	//P1DIR &= ~(key1 + key2 + key3 );

	if((key1) & P1IN){
		if((key2) & P1IN){
			if((key3) & P1IN){	
				
			}
			else{
				Charlie_LED_on(chlx3,chlx1);
			}

		}
		else{
			if((key3) & P1IN){	
				Charlie_LED_on(chlx1,chlx3);
			}
			else{
				Charlie_LED_on(chlx3,chlx2);
			}
		}
	}
	else{
		if((key2) & P1IN){
			if((key3) & P1IN){	
				Charlie_LED_on(chlx2,chlx3);
			}
			else{
				Charlie_LED_on(chlx2,chlx1);
			}

		}
		else{
			if((key3) & P1IN){	
				Charlie_LED_on(chlx1,chlx2);
			}
			else{
				
			}
			}

	}

}
