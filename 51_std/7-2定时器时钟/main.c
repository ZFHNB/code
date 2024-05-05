#include <STC89C5xRC.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Sec=00,Min=19,Hour=15;

void main()
{
	LCD_Init();
	Timer0_Init();
	
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :");
	
	while(1)
	{
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);
	}
}

//定时器中断函数
void Timer0_Routine() interrupt 1//中断函数
{
	static unsigned int T0Count;
//重新赋初值，因为在第一次计数到65535后会将计数器清零
	TL0 = 0x00;				//设置定时初始值
	TH0 = 0xDC;				//设置定时初始值
	T0Count++;
	if(T0Count >= 100)
	{
		T0Count=0;
		Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Min++;
			if(Min>=60)
				{
					Min=0;
					Hour++;
					if(Hour>=24)
					{
						Hour=0;
					}
				}
		}	
	}
}