#include <STC89C5xRC.H>
#include <INTRINS.H>

#define XMS 500

void Delay(unsigned int xms)	//@11.0592MHz
{
	while(xms--)
	{
		unsigned char data i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	}
}


void main(void)
{
	while(1)
	{
		if(P31 == 0)
		{
			Delay(20);//消除摁下时的按键抖动
			while(P31 == 0);//此时按钮处于触发状态
			Delay(20);//消除松手时的按键抖动
			
			P20 = ~P20;
		}
	}
}
