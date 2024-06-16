#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30;

int m, n;
char g[N][N];
int res = 0;
bool st[N][N];//记录瓷砖是否走过

/*方向数组 方向顺序：上右下左*/
//x 方向数组
int dx[] = {-1, 0, 1, 0};
//y 方向数组
int dy[] = {0, 1, 0, -1};

//当前访问到的坐标是(x, y)
void dfs(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
       int a = x + dx[i], b = y + dy[i];

       //边缘检测
       if(a < 0 || a >= n || b < 0 || b >= m) continue;
       if(g[a][b] != '.') continue;
       if(st[a][b]) continue;

       //走(a, b)
       st[a][b] = true;
       res++;
       dfs(a, b);
    }
}

int main()
{
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", g[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(g[i][j] == '@')
            {
                st[i][j] = true;
                dfs(i, j);
            }
        }
    }
    res++;
    printf("%d", res);
    return 0;
}