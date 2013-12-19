	org 0xf800
start:
	mov.b #9, R5
	rra.w R5
loop:
	jmp loop
	org 0xfffe
	dw start
