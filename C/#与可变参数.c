#include <stdio.h>

#define SHOWLIST(...) printf(# __VA_ARGS__)//#将传来的参数变为字符串，即"1233, hello"

int main()
{
	SHOWLIST(1233, hello);
	
	return 0;
}
