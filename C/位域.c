#include <stdio.h>

int main()
{
	typedef struct
	{
		unsigned int a:1;//以":数字"的方式定义位域，可分配数字指定bit的空间，且位域的宽度不能超过其依附的数据类型的长度
		unsigned int b:1;
		unsigned int c:2;
	}Test;
	
	Test t;
	t.a = 0;
	t.b = 1;
	t.c = 0b11;//二进制2占2位
	
	printf("a = %d, b = %d, c = %d\n",t.a, t.b, t.c);
	printf("size of Test = %d", sizeof(Test));
	
	return 0;
}
