#include <stdio.h>

int main() {
	int a = 520, b = 1314;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
	printf("����ǰ��a = %d, b = %d", a, b);
	printf("������a = %d, b = %d", a, b);
	
	return 0;
}
