
	org 0xf800

start:
	mov.w #0x5a80, &0x120
	mov.b #1, &0x22
	mov.b #0, &0x21

LOOP1:
	mov.w #65000, R4

decr1:
	dec R4
	jnz decr1
LOOP2:
        mov.w #65000, R4

decr2:
        dec R4
        jnz decr2
	
	xor.b #01, &0x21
	jmp LOOP1

	org 0xfffe
	dw start
