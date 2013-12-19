#include<msp430.h>

main()
	{
	int i=2;
	P1DIR = 0x01;
	P1OUT = 0x01;
	while(1)
		{
		while((P1IN>>3)&1);
		while(!(P1IN>>3)&1);
		i--;
		if(!i)
			{
			P1OUT^=0x01;
			i=2;
			}
		}
	}
