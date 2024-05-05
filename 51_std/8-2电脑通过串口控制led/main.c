#include <STC89C5xRC.H>
#include "Delay.h"
#include "UART.h"

void main()
{
	UART_Init();
	while(1)
	{
		
	}
}

//中断函数：
void UART_Routine() interrupt 4	//interrupt后的数字决定此函数的中断类型
{
	if(RI==1)//若为1，则为接收中断
	{
		P2 = ~SBUF;
		UART_SendByte(SBUF);
		RI = 0;//RI与TI一样，需要软件中置为0
	}
}