#include <stdio.h>

int main() {
	int a = 520, b = 1314;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
	printf("交换前：a = %d, b = %d", a, b);
	printf("交换后：a = %d, b = %d", a, b);
	
	return 0;
}
