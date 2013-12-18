#include <msp430.h>
#include <stdint.h>


#define LED_ON (P1OUT = BIT0)
#define LED_OFF (P1OUT = 0)
#define MX 1000

int on_time = 0;

void delay(int16_t n)
{
while(n--);
}

void one_cycle()
{
LED_ON;
delay(on_time);
LED_OFF;
delay(MX-on_time);
}

main()
{
int step = 20;
int dir = +1;
P1DIR = BIT0;
on_time = 0;
while(1) 
	{
	while(on_time!=MX)
		{
		one_cycle();
		on_time += step * dir;
		}
	LED_ON;
	delay(65000);
	while(on_time!=0)
		{
		one_cycle();
		on_time -= step * dir;
		}
	delay(65000);
	}
}
