#include <stdio.h>
#define SQUARE(x) ((x) * (x))
int main(void){
	int i = 1;
	while (i <= 100){
		printf("%d 的平方是 %d \n", i, SQUARE(i));
		i++;
	}
	return 0;
}

