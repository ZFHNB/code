#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 10010

int n,m;
int arr[N];//��¼����
int mars[N];//��¼�����˵ĳ�ʼ����
bool st[N];//״̬����
int res;//��ǰ������ö���˼�������
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
			//�ָ��ֳ���
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
