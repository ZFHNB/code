#include <STC89C5xRC.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password;
unsigned int Key = 1234;
unsigned char Count = 0;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Enter Password:");
	
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum)
		{	
			if(KeyNum <= 10)
			{
				if(Count<4)
				{
					Password *= 10;			 //密码左移一位
					Password += KeyNum%10;//获取一位密码
				}
				Count++;
			}
			if(KeyNum == 11)//退格
			{
				Password /= 10;	
				Count--;
			}
			if(KeyNum == 12)//确认
			{
				if(Password == Key)
				{
					LCD_ShowString(2,7,"TRUE");
					Password = 0;
					Count = 0;
				}
				else
				{
					LCD_ShowString(2,7,"ERROR");
					Password = 0;
					Count = 0;
				}
			}
			if(KeyNum == 16)//清除
			{
				Password = 0;
				Count = 0;
			}
			LCD_ShowNum(2,1,Password,4);
		}	
	}
}