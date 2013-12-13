#include<msp430.h>
main()
{
int a;
P1DIR = 0x01;//0000 0001
while(1)
	{
	if((P1IN&0x08)==0x08)
		{
		P1OUT=0x00;
		}
	else
		{
		P1OUT=0x01;
		}
	}
}
