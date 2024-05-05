#include <stdio.h>

typedef int (*PTR_TO_ARRAY)[3];

int main()
{
	int array[3] = {1, 2, 3};
	PTR_TO_ARRAY ptr_to_array = &array;
	
	int i;
	for(i=0;i<3;i++)
	{
		printf("%d\n", (*ptr_to_array)[i]);
	}
	
	return 0;
}
