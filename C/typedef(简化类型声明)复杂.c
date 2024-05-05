#include <stdio.h>

typedef int *(*PTR_TO_FUN)(int);

int * funA(int num) {
	printf("%d\t", num);
	return &num;
}

int * funB(int num) {
	printf("%d\t", num);
	return &num;
}

int * funC(int num) {
	printf("%d\t", num);
	return &num;
}

int main() {
	PTR_TO_FUN array[3] = {funA, funB, funC};

	int i;
	for (i = 0; i < 3; i++) {
		printf("addr of num: %p\n", (*array[i])(i));
	}

	return 0;
}
