#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 10010

int n,m;
int arr[N];//记录方案
int mars[N];//记录火星人的初始排列
bool st[N];//状态数组
int res;//当前已向下枚举了几个数字
bool return0 = false;

void dfs(int x)
{
	if(return0)
	{
		return ;
	}
	
	if(x > n)
	{
		res++;
		if(res == m + 1)
		{
			return0 = true;
			for(int i = 1; i <= n; i++)
			{
				printf("%d", arr[i]);
			}
		}
		return ;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!res)
		{
			i = mars[x];
		}
		
		if(!st[i])
		{
			st[i] = true;
			arr[x] = i;
			dfs(x+1);
			//恢复现场：
			st[i] = false;
			arr[x] = 0;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &mars[i]);
	}
	
	dfs(1);
	
	return 0;	
}
