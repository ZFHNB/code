#include <stdio.h>

int main() {

	char a = 0, b = 0;
	int *p = (int *)&b;

	*p = 258;

	printf("a = %d, b = %d", a, b);

	return 0;
}
