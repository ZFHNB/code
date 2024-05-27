#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, m, X;
int a[N], b[N];

int main()
{
    scnaf("%d %d %d", &n, &m, &X);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    for(int i = 0, j = m; i <n; i++)
    {
        while(j > 0; a[i] + b[j] > X)
        {
            j--;
        }
        if(a[i] + b[j] == X)
        {
            printf("%d %d\n", i, j);
        }
    }

    return 0;
}