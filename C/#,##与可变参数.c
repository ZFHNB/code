#include <stdio.h>

#define PRINT(format, ...) printf(#format, ## __VA_ARGS__)//#将传来的参数变为字符串，##连接参数

int main()
{
	PRINT(num = %d\n, 520);
	PRINT(Hellow World!\n);	
	return 0;
}
