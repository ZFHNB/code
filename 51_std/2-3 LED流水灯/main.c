#include <REGX52.H>
#include <INTRINS.H>

void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

int main(void)
{
	while(1)
	{
		P2 = 0xfe;//1111 1110
		Delay500ms();
		P2 = 0xfd;//1111 1101
		Delay500ms();
		P2 = 0xfb;//1111 1011
		Delay500ms();
		P2 = 0xf7;//1111 0111
		Delay500ms();
	}
	//可用位移运算符（<<）+取反操作符(~)实现
}
