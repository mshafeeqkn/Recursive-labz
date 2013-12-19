#include<msp430.h>

#define LED_G BIT6
#define LED_R BIT0

main()
{
P1DIR = 0x41;
ADC10CTL0 |= SREF_0/*Reference 3.6v*/ | ADC10SHT_2/*S-A-H 16xClock*/ | ADC10ON/*ADC Power ON*/ | REFON;
ADC10CTL1 |= INCH_4 /*Channel 0*/| SHS_0 /*Select ADC10SC for start*/| ADC10SSEL_0 /*Dedicated clock*/|ADC10DIV_0/*Clock division*/| CONSEQ_0/*Single channel single conversion mode*/;
ADC10AE0 = BIT4/*Adc P1.0 enabled*/;
ADC10CTL0 |= ENC;//ADC enabled

while(1)
	{
	ADC10CTL0 |= ADC10SC/*Start conversion*/;

	while(ADC10CTL1&ADC10BUSY);
	
	if(ADC10MEM>=0 && ADC10MEM<256)
		P1OUT = LED_G;
	else if(ADC10MEM>=256 && ADC10MEM<512)
		P1OUT = LED_R;
	else if(ADC10MEM>=512 && ADC10MEM<768)
		P1OUT = LED_R | LED_G;
	else
		P1OUT = 0x00;
	}
 
}


