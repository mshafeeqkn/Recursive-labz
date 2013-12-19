#include<msp430.h>

#define RED_LED BIT0
#define GREEN_LED BIT6

#define G_TOGGLE (P1OUT^=BIT6)
#define R_TOGGLE (P1OUT^=BIT0)

main()
{
int i=3;

P1DIR = 0x41;
P1OUT = 0x41;

TACTL |= TACTL | TASSEL_2 | ID_3 | MC_2;

while(1)
	{
	while(!(TACTL&TAIFG));
	TACTL &= ~TAIFG;
	R_TOGGLE;
	i--;
	if(!i)
		{
		i=3;
		G_TOGGLE;
		}
	}
}
