#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30;

int n, k;
int arr[N];
int q[N];
int ans = 0;

bool is_prim(int sum)
{
    if(sum < 2) return false;
    for(int i = 2; i < sum / i; i++)
    {
        if(sum % i == 0) return false;
    }
    return true;
}

void dfs(int x, int start)
{
    if(x > k)
    {
        int sum = 0;
        for(int i = 1; i <= k; i++)
        {
            sum += q[i];
        }
        if(is_prim(sum))
        {
            ans ++;
        }
        return;
    }
    for(int i = start; i <= n; i++)
    {
        q[x] = arr[i];
        dfs(x + 1, i + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    dfs(1, 1);
    printf("%d", ans);

    return 0;
}