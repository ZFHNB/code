#include <stdio.h>

#define SHOWLIST(...) printf(# __VA_ARGS__)//#�������Ĳ�����Ϊ�ַ�������"1233, hello"

int main()
{
	SHOWLIST(1233, hello);
	
	return 0;
}
