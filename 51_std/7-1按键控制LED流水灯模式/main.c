#include <STC89C5xRC.H>

void Timer0_Init()
{
	//配置TMOD
	//TMOD=0x01;
	//与或式赋值法（掩码）
	TMOD=TMOD&0xF0;//把TMOD低四位清零，高四位保持不变（防止影响计时器T1的TMOD）
	TMOD=TMOD|0x01;//把TMOD的最低位置为1，其余位保持不变
	
	//配置TCON
	TF0=0;//T0溢出中断标志
	TR0=1;
	/*配置计数器
	11.0592MHz晶振，1s机械周期数：11059200/12 = 921600
	计数器最高计数：65535
	10ms机械周期数：9216
	65535-9216*/
	TH0=56319/256;//取出高八位
	TL0=56319%256;//取出低八位
	//配置中断，执行完此处代码后跳转至中断函数
	ET0=1;
	EA=1;
	PT0=0;
}

void main()
{
	Timer0_Init();
	while(1)
	{
		
	}
}

unsigned int T0Count;
void Timer0_Routine() interrupt 1//中断函数
{
	//重新赋初值，因为在第一次计数到65535后会将计数器清零
	TH0=56319/256;//取出高八位
	TL0=56319%256;//取出低八位
	T0Count++;
	if(T0Count >= 100)
	{
		T0Count=0;
		P20=~P20;
		P21=~P20;
	}
}