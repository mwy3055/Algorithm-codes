#include <bits/stdc++.h>

using coord = std::pair<int, int>;

int n, src[][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};
char map[10][11];
bool ans;

void search(int, int);
void solve();

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool iswin()
{
    int rock = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '2')
                rock++;
        }
    }
    return rock == 1;
}

void search(int i, int j)
{
    for (int k = 0; k < 8; k++)
    {
        if (ans)
            break;
        int ny = i + src[k][0], nx = j + src[k][1];
        int dy = i + 2 * src[k][0], dx = j + 2 * src[k][1];
        if (isin(ny, nx) && isin(dy, dx) &&
            map[ny][nx] == '2' && map[dy][dx] == '0')
        {
            map[i][j] = '0';
            map[ny][nx] = '0';
            map[dy][dx] = '2';
            solve();
            map[ny][nx] = '2';
            map[dy][dx] = '0';
            map[i][j] = '2';
        }
    }
}

void solve()
{
    if (iswin())
    {
        ans = true;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '2')
            {
                search(i, j);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    solve();
    std::cout << (ans ? "Possible" : "Impossible") << '\n';
}