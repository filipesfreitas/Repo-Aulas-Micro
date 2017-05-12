;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
													; Generate START;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

MOV.B #000h,&USISRL 				; MSB = 0
BIS.B #USIGE+USIOE,&USICTL0 ; Latch/SDA output enabled
BIC.B #USIGE,&USICTL0				; Latch disabled

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
													; Generate STOP;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	BIS.B #USIOE,&USICTL0 			; SDA=output
	MOV.B #000h,&USISRL 				; MSB = 0
	MOV.B	#001h,&USICNT					; USICNT = 1 for one clock

TEST_USIIFG	

	BIT.B	#USIIFG,&USICTL1			; Test USIIFG
	JZ		test_USIIFG						;
	MOV.B	#0FFh,&USISRL					;	USISRL = 1 to drive SDA high
	BIS.B	#USIGE,&USICTL0				; Transparent latch enabled
	BIC.B	#USIGE+USIOE,&USICTL	; Latch/SDA output disabled
