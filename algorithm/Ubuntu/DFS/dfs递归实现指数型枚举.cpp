#include <bits/stdc++.h>
using namespace std;

#define N 20

int n;
int st[N];//记录每个数的状态，0表示未考虑，1表示选，2表示未选

void dfs(int x) //x表示当前枚举到了哪个位置
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
    //选
    st[x] = 1;
    dfs(x+1);
    st[x] = 0;//恢复现场
    
    //不选
    st[x] = 2;
    dfs(x+1);
    st[x] = 1;//恢复现场
}

int main()
{
    scanf("%d", &n);
    dfs(1);
    
    return 0;
}
