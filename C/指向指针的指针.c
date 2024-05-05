#include <stdio.h>

int main(){
	
	int n = 1;
	int *p = &n;
	int **pp = &p;
	
	printf("n: %d\n",n);
	printf("*p: %d\n",*p);
	printf("**pp: %d\n",**pp);
	
	printf("\n*****************\n");
	
	printf("&n: %p\n",&n);
	printf("p: %p\n",p);
	printf("*pp: %p\n",*pp);
	
	printf("\n*****************\n");
	
	printf("&p: %p\n",&p);
	printf("pp: %p\n",pp);

	return 0;
}
