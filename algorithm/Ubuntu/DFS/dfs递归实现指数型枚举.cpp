#include <bits/stdc++.h>
using namespace std;

#define N 20

int n;
int st[N];//��¼ÿ������״̬��0��ʾδ���ǣ�1��ʾѡ��2��ʾδѡ

void dfs(int x) //x��ʾ��ǰö�ٵ����ĸ�λ��
{
    if(x > n)
    {
        for(int i = 1; i<=n; i++)
        {
            if(st[i] == 1)
            {
                printf("%d ",i);
            }
        }
        printf("\n");
        return;
    }
    //ѡ
    st[x] = 1;
    dfs(x+1);
    st[x] = 0;//�ָ��ֳ�
    
    //��ѡ
    st[x] = 2;
    dfs(x+1);
    st[x] = 1;//�ָ��ֳ�
}

int main()
{
    scanf("%d", &n);
    dfs(1);
    
    return 0;
}
