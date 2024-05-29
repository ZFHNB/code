#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 20

int n;
vector<int> st(N);//1Ñ¡£¬2²»Ñ¡

void dfs(int x)
{
	if(x>n)
	{
		for(int i = 0; i<=n; i++)
		{
			if(st[i] == 1)
			{
				printf("%d",i);
			}
		}
		printf("\n");
		return ;
	}
	
	st[x] = 2;
	dfs(x+1);	
	st[x] = 1;
	dfs(x+1);
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	
	return 0;
}
