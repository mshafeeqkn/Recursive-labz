#include<msp430.h>
main()
{
int a,i;
P1DIR=0x41;//0b01000001
P1OUT=0x01;//0b00000001
while(1)
	{
	for(i=0;i<10000;i++)
		{
		a=1;
		}
	P1OUT^=0x41;
	}
}
