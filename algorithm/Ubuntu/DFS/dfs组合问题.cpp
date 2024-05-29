#include <bits/stdc++.h>
using namespace std;

const int N = 21;

int n,r;
int arr[N];

void dfs(int x, int start)
{
	
	if(x > r)
	{
		for(int i = 1; i <= r; i++)
		{
			printf("%3d",arr[i]);
		}
		printf("\n");
		return ;
	}
	
	for(int i = start; i <= n; i++)
	{
		arr[x] = i;
		dfs(x+1, start+1);
		arr[x] = 0;
	}
}

int main()
{
	scanf("%d %d", &n, &r);
	dfs(1,1);
}
