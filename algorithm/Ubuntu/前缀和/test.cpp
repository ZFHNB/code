#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100001;

int n;
int a[N], s[N];

int main()
{
    for(int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    return 0;
}