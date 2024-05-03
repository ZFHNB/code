#include <STC89C5xRC.H>

/**
  * @brief 定时器0初始化，1ms@11.0592MHz
  * @param  无
  * @retval 无
  */
void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x00;				//设置定时初始值
	TH0 = 0xDC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	
	//配置中断，执行完此处代码后跳转至中断函数
	ET0=1;//允许中断
	EA=1;//允许总中断
	PT0=0;//中断优先级（0为低优先级）
}

//定时器中断函数模板
//void Timer0_Routine() interrupt 1//中断函数
//{
//	static unsigned int T0Count;
////重新赋初值，因为在第一次计数到65535后会将计数器清零
////	TH0=56319/256;//取出高八位
////	TL0=56319%256;//取出低八位
//	TL0 = 0x00;				//设置定时初始值
//	TH0 = 0xDC;				//设置定时初始值
//	T0Count++;
//	if(T0Count >= 100)
//	{
//		T0Count=0;
//		P20=~P20;
//		P21=~P20;
//	}
//}