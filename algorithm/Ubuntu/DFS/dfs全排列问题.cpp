#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10;

int n;
bool st[N];//true表示被选过，false表示未被选过
int arr[N];//存储排列的数组（123,132等）

//x表示当前枚举到了哪个位置
void dfs(int x)
{
	
	if(x > n)//结束条件
	{
		for(int i = 1; i<=n; i++)
		{
			printf("%d", arr[i]);
		}
		printf("\n");
		return ;
	}
	
	for(int i = 1; i<=n; i++)
	{
		if(!st[i])
		{
			st[i] = true;
			arr[x] = i;
			dfs(x+1);
			st[i] = false;
			arr[x] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	
	return 0;
}
