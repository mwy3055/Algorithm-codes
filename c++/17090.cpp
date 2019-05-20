#include <iostream>
using namespace std;

int n, m;
char maze[500][501], escape[500][500];
/*
    escape 배열의 값
    0: 아직 탐색하지 않음
    1: 탈출 가능
    2: 탈출 불가능
    3: 탐색중(경로에 포함되는 점)
*/

bool isin(int &y, int &x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
void getnext(int &y, int &x, char &now)
{
    switch (now)
    {
    case 'U':
        y -= 1;
        break;
    case 'D':
        y += 1;
        break;
    case 'L':
        x -= 1;
        break;
    case 'R':
        x += 1;
        break;
    }
}
char dfs(int &y, int &x)
{
    char &cur = escape[y][x];
    cur = 3;

    int sy = y, sx = x;
    getnext(sy, sx, maze[y][x]);

    if (!isin(sy, sx) || escape[sy][sx] == 1)
        return cur = 1;
    if (escape[sy][sx] == 2 || escape[sy][sx] == 3)
        return cur = 2;

    return cur = dfs(sy, sx);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (escape[i][j] == 0)
                dfs(i, j);
            if (escape[i][j] == 1)
                ans++;
        }
    }
    cout << ans;
}