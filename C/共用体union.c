#include <stdio.h>
#include <string.h>

typedef union Test
{
	int i;
	double pi;
	char str[8];
}Test;

int main()
{
	Test test;
	
	test.i = 520;
	test.pi = 3.14;
	strcpy(test.str, "Guolujie");
	
	printf("addr of test.i: %p\n", &test.i);
	printf("addr of test.pi: %p\n", &test.pi);
	printf("addr of test.str: %p\n", &test.str);
	
	printf("test.i: %d\n",test.i);
	printf("test.pi: %2f\n",test.pi);
	printf("test.str: %s\n",test.str);
	
	return 0;
}
