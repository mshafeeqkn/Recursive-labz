#include<msp430.h>
#include<stdint.h>

#define R_LED BIT0
#define G_LED BIT6

#define R_TOGGLE (P1OUT^=R_LED)

main()
{
int16_t lfsr = 0xACE1u;		//Always 16 bit independent of m/c
int8_t bit;			//Always 8 bit independent of m/c

P1DIR |= R_LED | G_LED;
P1OUT = 0x00;

TACTL |= TASSEL_2 | MC_2 | ID_3;//Timer SMCLK,Cont,/8

while(1)
	{
	bit = ((lfsr>>15)^(lfsr>>11)^(lfsr>>8)^(lfsr>>4))&(0x01);
	lfsr= (bit | lfsr<<1);
	P1OUT = lfsr&0x01;
	while(!(TACTL&TAIFG));
	TACTL &= ~TAIFG;
	}
}
