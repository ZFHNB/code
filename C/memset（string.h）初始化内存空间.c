#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main() {

	int *ptr = NULL;
	int i;

	ptr = (int *)malloc(N * sizeof(int));
	if (ptr == NULL) {
		exit(1);
	}

	memset(ptr, 0, N * sizeof(int));
	for(i = 0; i<N; i++){
		printf("%2d",ptr[i]);
	}
	
	free(ptr);

	return 0;
}
