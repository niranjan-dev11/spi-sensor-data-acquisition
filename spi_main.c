#include<lpc21xx.h>
#include"header.h"
int main()
{
	 int temp=0;
	spi0_init();
	uart0_init(9600);
	uart0_tx_string("ADC read start\n");
	while(1)
		{
		temp=mcp3204_adc_read(1);
		uart0_integer(temp);
			delay_s(2);
		temp=mcp3204_adc_read(2);
		uart0_integer(temp);
	}
}

