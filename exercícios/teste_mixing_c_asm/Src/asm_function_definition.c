#include<msp430g2553.h>
#include"asm_teste.h"
#include<stdio.h>

void prototipo(){
/*Zear registradores de propósito geral*/
__asm__("mov.w #0,R15;";
		"mov.w #0,R14;";
		"mov.w #0,R13;";
		"mov.w #0,R12;";
		"mov.w #0,R11;";
		"mov.w #0,R10;";
		"mov.w #0,R9;";
		"mov.w #0,R8;";
		"mov.w #0,R7;";
		"mov.w #0,R6;");
}
