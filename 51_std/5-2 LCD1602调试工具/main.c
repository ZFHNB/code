#include <STC89C5xRC.H>
#include "LCD1602.h"
#include "Delay.h"

int Result = 60000;

void main()
{
	LCD_Init();
//	LCD_ShowChar(1,1,'A');//(行,列,字符);
//	LCD_ShowString(1,3,"Hello");//(行,列,字符串);
//	LCD_ShowNum(1,9,65535,5);//(行,列,数字,显示几位(位数小于数字位数时,高位去掉,大于高位补0))
//	LCD_ShowSignedNum(1,15,-6,1);
//	LCD_ShowHexNum(2,1,0xa8,2);
//	LCD_ShowBinNum(2,4,0xaa,8);
	while(1)
	{
		Result--;
		LCD_ShowNum(1,1,Result,5);
		Delay(1);
	}
}
		
