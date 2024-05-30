#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;

int n;
int arr[N];
int s[N], b[N];//存酸苦
bool st[N];//存状态
int res = 1e9;
bool has_ingredient;

void dfs(int x)
{
    if(x > n)
    {
        int pro = 1;
        int sum = 0;
        for(int  i = 1; i <= n; i++)
        {
            if(st[i] == 1)
            {
                has_ingredient = 1;
                pro *= s[i];
                sum += b[i];
            }
        }
        if(has_ingredient)
            res = min(res, abs(pro - sum));
        has_ingredient = 0;
        return;
    }
    st[x] = 1;
    dfs(x + 1);
    st[x] = 0;
    dfs(x + 1);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &s[i], &b[i]);
    }
    dfs(1);
    printf("%d\n", res);

    return 0;
}