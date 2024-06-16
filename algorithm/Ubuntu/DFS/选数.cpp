#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 30

int n,k;
int arr[N];
int t[N];
int res = 0;//存储结果

//检查是否为素数
bool is_prim(int sum)
{
	if(sum < 2)
		return false;
	for(int i = 2; i <= sum / i; i++)
	{
		if(sum % i == 0)
			return false;
	}
	return true;
}

//x表示到了哪个位置，start表示从几开始枚举
void dfs(int x, int start)
{
	
	if(x > k)
	{
		int sum = 0;
		for(int i = 1; i<=k; i++)
		{
			sum += arr[i];
		}
		if(is_prim(sum))
		{
			res ++;
		}
		return ;
	}
	
	for(int i = start; i<=n; i++)
	{
		arr[x] = t[i];
		dfs(x+1, i+1);//继续向下搜索
		arr[x] = 0;//恢复现场
	}
}

int main()
{
	scanf("%d %d", &n,&k);
	for(int i = 1; i<=n; i++)
	{
		scanf("%d",&t[i]);
	}
	dfs(1,1);
	
	printf("%d\n",res);
	
	return 0;
}
