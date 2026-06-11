/*spi0_driver.c*/
#include <LPC21xx.H>
void spi0_init(void)
 {
	PINSEL0|=0x1500;//P0.4->SCK0
									//P0.5->MISO0
									//P0.6->MOSI0
	IODIR0|=(7<<7);//P0.7(CS0)-> Out Dir
	IOSET0=(7<<7);//CS0=1*
	S0SPCR=0x20;//CPOL=CPHA=0, Master Mode, MSB First, SPI0 Intr off
	S0SPCCR=15;//spi freq is 1Mbps/1MHz
}

/*spi transfer function*/
#define SPIF ((S0SPSR>>7)&1)
unsigned char spi0(unsigned char data)
{
	S0SPDR=data;//data from M-->S
	while(SPIF==0);
	return S0SPDR;
}


