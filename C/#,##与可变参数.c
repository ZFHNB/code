#include <stdio.h>

#define PRINT(format, ...) printf(#format, ## __VA_ARGS__)//#�������Ĳ�����Ϊ�ַ�����##���Ӳ���

int main()
{
	PRINT(num = %d\n, 520);
	PRINT(Hellow World!\n);	
	return 0;
}
