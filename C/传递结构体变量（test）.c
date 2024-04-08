#include <stdio.h>

int main()
{
	struct Test
	{
		int x;
		int y;
	}t1,t2;
	
	t1.x = 3;
	t1.y = 4;
	
	t2 = t1;
	
	printf("t2.x = %d, t2.y = %d",t2.x, t2.y);
	
	return 0;
}
