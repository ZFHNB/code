#include <stdio.h>

typedef int (*PTR_TO_FUN)(void);

int fun(void)
{
	return 520;	
}

int main()
{
	PTR_TO_FUN ptr_to_fun = &fun;
	
	printf("%d",(*ptr_to_fun)());
	
	return 0;
}
