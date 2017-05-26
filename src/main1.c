#include<msp430g2553.h>
#include<legacymsp430.h>
/*Exemplo de uso timer A*/
#define LED BIT0
int x=0;
int main(void){

	WDTCTL = WDTPW + WDTHOLD;       // Stop watchdog timer
	BCSCTL1 = CALBC1_1MHZ;					//
	DCOCTL = CALDCO_1MHZ;						//
	P1DIR = LED;
	P1OUT = BIT0;
	TA0CCR0 = 1000 -1;							//contador de 16 bits
	TA0CTL = TASSEL_2 + ID_0 + MC_1 + TAIE;//modo smclk + dividido por 1 + mod de contagem up + habilita interrupção
	_BIS_SR(GIE + LPM0_bits);
	return 0;
}
/*legacymsp430.h//lib necessária
template: interrupt(x) void __attribute__((interrupt (x)))
Vectors:
	TIMER0_A1_VECTOR 			// Timer A vector
	TIMER0_A0_VECTOR			//
	TIMER1_A1_VECTOR			//	
	TIMER1_A0_VECTOR			//
	TA0IV									//
	PORT1_VECTOR 		 			//
	PORT2_VECTOR					//
	ADC10_VECTOR					//
	USCIAB0TX_VECTOR			// USCI A0/B0 Transmit
	USCIAB0RX_VECTOR			// USCI A0/B0 Receive
	COMPARATORA_VECTOR		//
	NMI_VECTOR						//
	RESET_VECTOR					//

*/
interrupt(TIMER0_A1_VECTOR) TA0_ISR1(void){
	x++;	
	if(x == 500){
	P1OUT^=LED;
	x=0;
	}
  TA0CTL &= ~TAIFG;
}

