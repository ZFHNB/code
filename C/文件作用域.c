#include <stdio.h>

void func(void);

int main()
{
	extern int count;//�˴���ʾ��ȫ�ֱ���count������������һ���ڴ�count��������֮ǰ
	
	func();
	count++;
	printf("In main, count = %d\n", count);
	
	return 0;
}

int count;//�Ӵ˴�����count����Ҫ�ڴ����ǰ����count����Ҫʹ��extern

void func (void)
{
	count ++;
	printf("In func, count = %d\n", count);
}
