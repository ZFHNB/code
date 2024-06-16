#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 21;

int n, r;
int ans[N];

void dfs(int x, int start)//x当前枚举到哪个数，start从哪个数开始枚举
{
    if(x > r)
    {
        for(int i = 1; i <= r; i++)
        {
            printf("%3d", ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i = start; i <= n; i++)
    {
        ans[x] = i;
        dfs(x + 1, i + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &r);
    dfs(1, 1);//x当前枚举到哪个数，start从哪个数开始枚举
    
    return 0;
}