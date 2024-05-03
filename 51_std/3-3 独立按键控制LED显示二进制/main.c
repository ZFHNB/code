#include <STC89C5xRC.H>
#include <INTRINS.H>

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


void main()
{
	unsigned char LEDNum = 0;//char -> 8bit
	while(1){
		if(P31 == 0)
		{
			Delay(20);
			while(P31 == 0);
			Delay(20);
			
			P2 = ~(++LEDNum);
		}
	}
	
//	int i = 0;
//	while(1){
//		if(P31 == 0)
//		{
//			Delay(20);
//			while(P31 == 0);
//			Delay(20);
//			
//			P2 = ~(++i);
//		}
//	}
	
	//若要实现从右到左：
//	0111 1111 -> 0x7F
//	1011 1111 -> 0xBF
//	0011 1111 -> 0x3F
//	1101 1111 -> 0xDF
	
}
