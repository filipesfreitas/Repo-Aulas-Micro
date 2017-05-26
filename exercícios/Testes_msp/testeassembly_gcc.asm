	mov.w #00h,R7
	mov.w 
INIT:	
LOOP:	
	
	cmp #99,R7
	jge EXIT

	add.w R7,(R9)	
	add.w R7,(R9)
	inc.w R7
	
	jmp LOOP
	
EXIT:
