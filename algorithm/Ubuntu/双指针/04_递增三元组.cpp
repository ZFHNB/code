#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;

int n;
int a[N], b[N], c[N];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    
    long long res = 0;
    for(int i = 1, pa = 1, pc = 1; i <= n; i++)
    {
        while(pa <= n && a[pa] < b[i])
        {
            pa++;
        }
        while(pc <= n && c[pc] <= b[i])
        {
            pc++;
        }
        res += (long long)(pa - 1) * (n - pc + 1);
    }
    
    printf("%lld\n", res);
    return 0;
}