#include<lpc21xx.h>
void delay_s(unsigned int seconds)
{
T0PR=15000000-1;
T0PC=0;
T0TC=0;
T0TCR=1;
while(T0TC<seconds);
T0TCR=0;
}


