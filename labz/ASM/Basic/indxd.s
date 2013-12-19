	org 0xf800

start: 
	mov.w #0xabcd, &0x0202 	;Normal methode,Store in 0x0202
	mov.w #0x0200, R5	
	mov.w #0xabcd, 6(R5)	;Indexed adrsing,store in 0x0206
	
loop:
	jmp loop
	org 0xfffe
	dw start
