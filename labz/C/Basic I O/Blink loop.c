#include<msp430.h>
main()
{
int i,a;
P1DIR = 0x01;
P1OUT = 0x01;
while(1)
	{
	for(i=0;i<0x5000;i++)
		{
		int a=10;
		}
	P1OUT=P1OUT^0x01;
	}
}
