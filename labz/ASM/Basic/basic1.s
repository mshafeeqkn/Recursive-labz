	org 0xf800
start:
	mov.w #0x5a80, &0x0120
	
	mov.w #1,R5
	mov.w #2,R4
	add R4,R5
	add R4,R5

loop:
	jmp loop
	
	org 0xfffe
	dw start
