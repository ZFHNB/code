#include <REGX52.H>
#include <INTRINS.H>

#define DELAYTIMES 100

void Delayxms(int xms)	//@11.0592MHz
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


void main()
{
	/*while(1)
	{
		P2 = 0xfe;//1111 1110
		Delayxms(DELAYTIMES);
		P2 = 0xfd;//1111 1101
		Delayxms(DELAYTIMES);
		P2 = 0xfb;//1111 1011
		Delayxms(DELAYTIMES);
		P2 = 0xf7;//1111 0111
		Delayxms(DELAYTIMES);
		P2 = 0xef;//1110 1111
		Delayxms(DELAYTIMES);
		P2 = 0xdf;//1101 1111
		Delayxms(DELAYTIMES);
		P2 = 0xbf;//1011 1111
		Delayxms(DELAYTIMES);
		P2 = 0x7f;//0111 1111
		Delayxms(DELAYTIMES);
	}
	*/
	int i;
	while(1)
		for(i=0;i<8;i++)
	{
		P2 = ~(0x01<<i);//'~'È¡·´²Ù×÷·û
		Delayxms(DELAYTIMES);
	}
}