#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;

int n;
int a[N];
bool st[N];//状态数组，记录此数是否被选

void dfs(int x)//x为当前枚举到了哪个位置
{
    if(x > n)
    {
        for(int i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!st[i])//此数没有被选过
        {
            //更新标志（选数）
            st[i] = true;
            //存数
            a[x] = i;
            //向下搜索
            dfs(x + 1);
            //恢复现场
            st[i] = false;
            a[x] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1);

    return 0;
}