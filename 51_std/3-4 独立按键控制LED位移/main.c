#include <STC89C5xRC.H>
#include <INTRINS.H>

#define DTime 20

void Delay(unsigned int xms)	//@11.0592MHz
{
	while(xms--){
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

unsigned char LEDNum;//操作数需移动的位数

void main()
{
	while(1)
	{
		if(P30 == 0)
		{
			Delay(DTime);
			while(P30 == 0);
			Delay(DTime);
			
			LEDNum++;
			if(LEDNum>=8)
				LEDNum = 0;
			P2 = ~(0x01<<LEDNum);
		}
		
		if(P31 == 0)
		{
			Delay(DTime);
			while(P31 == 0);
			Delay(DTime);
			
			if(LEDNum==0)
				LEDNum = 7;
			else
				LEDNum--;
			P2 = ~(0x01<<LEDNum);
		}
	}
}