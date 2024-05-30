#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 210;

int n, a, b;
int ele[N];//存Ki
bool st[N];//存每层楼被走过的状态
int res = 1e9;

//当前在x楼, 摁了cnt次按钮
void dfs(int x, int cnt)
{
    if(cnt >= res) return ;
    if(x < 0 || x > n) return;

    if(x == b)
    {
        res = min (res, cnt);
        return;
    }
    //上
    if(x + ele[x] <= n && !st[x + ele[x]])//边界判断 + 判断目标楼层有没有被走过
    {
        st[x + ele[x]] = true;
        dfs(x + ele[x], cnt + 1);
        st[x + ele[x]] = false;//回溯时恢复现场
    }
    //下
    if(x - ele[x] > 0 && !st[x - ele[x]])
    {   st[x - ele[x]] = true;
        dfs(x - ele[x], cnt + 1);
        st[x - ele[x]] = false;
    }
}

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &ele[i]);
    }
    dfs(a, 0);
    if(res == 1e9)
    {
        printf("-1\n");
        return 0;
    } 
    printf("%d", res);

    return 0;
}