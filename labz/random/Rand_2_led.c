#include<msp430.h>
#include<stdint.h>

#define R_LED BIT0
#define G_LED BIT6

#define R_TOGGLE (P1OUT^=R_LED)

main()
{
int16_t lfsr1 = 0xACE1u,lfsr2 = 0xBDF2u;
				//Always 16 bit independent of m/c
int8_t bit1,bit2;		//Always 8 bit independent of m/c

P1DIR |= R_LED | G_LED;
P1OUT = 0x00;

TACTL |= TASSEL_2 | MC_2 | ID_3;//Timer SMCLK,Cont,/8

while(1)
	{
	bit2 = ((lfsr2>>13)^(lfsr2>>11)^(lfsr2>>7)^(lfsr2>>9))&(0x01);
	lfsr2= (bit2 | lfsr2<<1);

	if(lfsr2&0x01==0x01)
		P1OUT |= 0x40;
	else
		P1OUT &= ~(0x40);

	bit1 = ((lfsr1>>15)^(lfsr1>>12)^(lfsr1>>5)^(lfsr1>>9))&(0x01);
	lfsr1= (bit1 | lfsr2<<1);

	if(lfsr1&0x01==0x01)
		P1OUT |= 0x01;
	else
		P1OUT &= ~(0x01);

	while(!(TACTL&TAIFG));
	TACTL &= ~TAIFG;
	}
}
