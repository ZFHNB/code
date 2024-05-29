#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10;

int n;
bool st[N];//true��ʾ��ѡ����false��ʾδ��ѡ��
int arr[N];//�洢���е����飨123,132�ȣ�

//x��ʾ��ǰö�ٵ����ĸ�λ��
void dfs(int x)
{
	
	if(x > n)//��������
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
