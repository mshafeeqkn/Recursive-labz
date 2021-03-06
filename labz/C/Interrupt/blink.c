#include<msp430.h>

#define LED BIT0
#define TOGGLE (P1OUT^=LED)

__attribute__((interrupt(TIMERA1_VECTOR)))
timer_isr(void)
{
P1OUT ^= LED;
TACTL &= ~TAIFG;
}

main()
{
P1DIR = LED;
P1OUT = LED;

TACTL |= TASSEL_2 | MC_2 | ID_3 | TAIE;
__enable_interrupt();

while(1);
}
