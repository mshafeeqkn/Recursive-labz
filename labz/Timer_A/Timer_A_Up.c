#include<msp430.h>

#define GREEN_LED BIT6

#define G_TOGGLE (P1OUT^=BIT6)

main()
{
P1DIR = 0x41;
P1OUT = 0x40;

TACTL |= TACTL | TASSEL_2 | ID_3 | MC_1;
TACCR0 = 0x2000;
while(1)
	{
	while(!(TACTL&TAIFG));
	TACTL &= ~TAIFG;
	G_TOGGLE;
	}
}
