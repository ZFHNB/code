#include <stdio.h>
#include <stdlib.h>

int main() {

	int *ptr1 = NULL;
	int *ptr2 = NULL;

	ptr1 = (int *)malloc(sizeof(int));
	ptr2 = (int *)malloc(sizeof(int));

	printf("stack: %p -> %p\n", &ptr1, &ptr2);//栈：高 -> 低，更环保（地址差更小）
	printf("heap: %p -> %p", ptr1, ptr2);//堆：低 -> 高
	return 0;
}
