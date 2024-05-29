#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 10

int n;
int arr[N];
int st[N];//false为未选，true为已选

void dfs(int x)
{
	
	if(x > n)
	{
		for(int i = 1; i <= n; i++)
		{
			printf("%d", arr[i]);
		}
		printf("\n"); 
	}
	
	for(int i = 1; i<=n; i++)
	{
		if(!st[i])
		{
			st[i] = true;
			arr[x] = i;
			dfs(x+1);
			st[i] = false;
		}
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	
	return 0;
}
