#include<msp430.h>

#define LED BIT6

main()
{
P1DIR = 0x40;
ADC10CTL0 |= SREF_0/*Reference 1.5v*/ | ADC10SHT_2/*S-A-H 16xClock*/ | ADC10ON/*ADC Power ON*/ | REFON;
ADC10CTL1 |= INCH_0 /*Channel 0*/| SHS_0 /*Select ADC10SC for start*/| ADC10SSEL_0 /*Dedicated clock*/|ADC10DIV_0/*Clock division*/| CONSEQ_0/*Single channel single conversion mode*/;
ADC10AE0 = BIT0/*Adc P1.0 enabled*/;
ADC10CTL0 |= ENC;//ADC enabled

while(1)
	{
	ADC10CTL0 |= ADC10SC/*Start conversion*/;

	while(ADC10CTL1&ADC10BUSY);

	if(ADC10MEM>100)
		P1OUT |= LED;
	else
		P1OUT &= ~LED;
	}
 
}


