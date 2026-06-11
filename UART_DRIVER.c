#include<lpc21xx.h>
void uart0_init(unsigned int baud)
{
    int pclk, result = 0;
    int a[] = {15, 60, 30, 0};
    pclk = a[VPBDIV] * 1000000;
    result = pclk / (16 * baud);
    PINSEL0 |= 0x5;  //P0.0 & 0.1
    U0LCR = 0x83;
    U0DLL = (result & 0xff);
    U0DLM = (result >> 8) & 0xff;
    U0LCR = 0x03;
}
// Transmit 1 byte of Data
#define THRE ((U0LSR >> 5) & 1)
void uart0_tx(unsigned char data)
{
    U0THR = data;
    while (THRE == 0);
}
// Receive 1 byte of Data
#define RDR (U0LSR & 1)
unsigned char uart0_rx()
{
    while (RDR == 0);
    return U0RBR;
}
// Uart0_tx_string() function
void uart0_tx_string(char *ptr)
{
    while (*ptr != 0)
    {
        uart0_tx(*ptr);
        ptr++;
    }
}

void uart0_integer(int num)
{
    int a[10], i;
    if (num == 0)
    {
        uart0_tx('0');
    }
    if (num < 0)
    {
        num = -num;
        uart0_tx('-');
    }
    while (num > 0)
    {
        a[i] = num % 10 + 48;
        num = num / 10;
        i++;
    }
    for (i = i - 1; i >= 0; i--)
    {
        uart0_tx(a[i]);
    }
}




