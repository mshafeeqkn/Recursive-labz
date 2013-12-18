#include<msp430.h>
#include<stdint.h>

#define a BIT0
#define b BIT1
#define c BIT2
#define d BIT3
#define e BIT4
#define f BIT5
#define g BIT6

void n1()
{P1OUT = b | c;}
void n2()
{P1OUT = a | b | g | e | d;}
void n3()
{P1OUT = a | b | g | c | d;}
void n4()
{P1OUT = f | g | b | c;}
void n5()
{P1OUT = a | f | g | c | d;}
void n6()
{P1OUT = a | f | g | c | d | e;}
void n7()
{P1OUT = a | f | b | c ;}
void n8()
{P1OUT = a | f | g | c | d | b | e;}
void n9()
{P1OUT = a | f | g | c | d | b;}
void n0()
{P1OUT = a | f | c | d | b | e;}
void delay(int16_t i)
{
while(--i)
	{
	++i;
	--i;	
	}
}

main()
{
P1DIR = 0xFF;
while(1)
	{
	n1();
	delay(65000);
	n2();
	delay(65000);
	n3();
	delay(65000);
	n4();
	delay(65000);
	n5();
	delay(65000);
	n6();
	delay(65000);
	n7();
	delay(65000);
	n8();
	delay(65000);
	n9();
	delay(65000);
	n0();
	delay(65000);
	}
}
