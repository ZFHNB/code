#include <stdio.h>

int main()
{
	typedef struct
	{
		unsigned int a:1;//��":����"�ķ�ʽ����λ�򣬿ɷ�������ָ��bit�Ŀռ䣬��λ��Ŀ�Ȳ��ܳ������������������͵ĳ���
		unsigned int b:1;
		unsigned int c:2;
	}Test;
	
	Test t;
	t.a = 0;
	t.b = 1;
	t.c = 0b11;//������2ռ2λ
	
	printf("a = %d, b = %d, c = %d\n",t.a, t.b, t.c);
	printf("size of Test = %d", sizeof(Test));
	
	return 0;
}
