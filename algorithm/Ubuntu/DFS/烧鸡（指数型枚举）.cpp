#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 20
int n;
int arr[N];//存每次递归的临时方案
int res = 0;//存方案数
int mem[59055][N];//存所有方案

//x表示枚举到了哪一位，sum表示当前已选调料的总质量
void dfs(int x,int sum)
{
	if(sum > n) //剪枝
		return ;
	
	if(x > 10)
	{
		if(sum == n)
		{
			res++;
			for(int i = 1; i <= 10; i++)
			{
				mem[res][i] = arr[i];
			}
		}
		return;
	}
	
	for(int i = 1; i<=3; i++)
	{
		arr[x] = i;
		dfs(x+1, sum + i);
		arr[x] = 0;
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1,0);
	printf("%d\n",res);
	
	for(int i = 1; i<res; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			printf("%d ",mem[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
