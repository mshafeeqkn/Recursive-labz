#include<msp430.h>

#define LED BIT0
#define TOGGLE (P1OUT^=LED)

main()
{
int i=5;

P1DIR = 0xFF;
P1OUT = 0x00;

TACTL |= TACTL | TASSEL_2 | MC_2 | ID_3;
while(1)
	{
	while(!(TACTL&TAIFG));
	TACTL &= ~TAIFG;
	TOGGLE;
	}
}