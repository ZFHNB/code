#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;

int n;
int st[N];//记录每个数的状态，1选 ，0不选

void dfs(int x)
{
    /*归*/
    if(x > n)
    {
        for(int i = 1; i <= n; i++)
        {
            if(st[i] == 1)//判断状态
            {
                printf("%d", i);
            }
        }
        printf("\n");
        return;
    }
    /*递*/
    //选
    st[x] = 1;
    dfs(x + 1);
    //不选
    st[x] = 0;
    dfs(x + 1);
}
int main()
{
    scanf("%d ", &n);
    dfs(1);

    return 0;
}